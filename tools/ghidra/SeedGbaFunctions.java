// Seed all statically discoverable main-ROM functions before auto-analysis.
// Arguments: path to the complete base ROM.
// @category SonicBattle

import java.math.BigInteger;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Set;
import java.util.TreeSet;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.lang.Register;

public class SeedGbaFunctions extends GhidraScript {
    private static final long ROM_BASE = 0x08000000L;
    private static final int CODE_END = 0x4B718;

    private static int u16(byte[] data, int offset) {
        return (data[offset] & 0xFF) | ((data[offset + 1] & 0xFF) << 8);
    }

    private static long u32(byte[] data, int offset) {
        return Integer.toUnsignedLong((data[offset] & 0xFF)
            | ((data[offset + 1] & 0xFF) << 8)
            | ((data[offset + 2] & 0xFF) << 16)
            | ((data[offset + 3] & 0xFF) << 24));
    }

    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) {
            throw new IllegalArgumentException("complete ROM path required");
        }
        byte[] rom = Files.readAllBytes(Path.of(args[0]));
        Set<Long> starts = new TreeSet<>();
        starts.add(ROM_BASE);
        starts.add(ROM_BASE + 0xC0);
        starts.add(ROM_BASE + 0x104);
        starts.add(ROM_BASE + 0x1D0);

        // Function pointers are Thumb addresses with bit zero set. Scan the
        // complete ROM because callback tables mostly live after .text.
        for (int offset = 0; offset + 4 <= rom.length; offset += 4) {
            long value = u32(rom, offset);
            if ((value & 1) != 0 && value >= ROM_BASE + 0x210 && value < ROM_BASE + CODE_END) {
                starts.add(value - 1);
            }
        }

        // Decode Thumb-1 BL pairs throughout the established executable range.
        for (int offset = 0x210; offset + 4 <= CODE_END; offset += 2) {
            int high = u16(rom, offset);
            int low = u16(rom, offset + 2);
            if ((high & 0xF800) == 0xF000 && (low & 0xF800) == 0xF800) {
                int displacement = ((high & 0x7FF) << 12) | ((low & 0x7FF) << 1);
                if ((displacement & 0x400000) != 0) {
                    displacement |= 0xFF800000;
                }
                long target = ROM_BASE + offset + 4L + displacement;
                if (target >= ROM_BASE + 0x210 && target < ROM_BASE + CODE_END && (target & 1) == 0) {
                    starts.add(target);
                }
            }
        }

        Register thumb = currentProgram.getRegister("TMode");
        if (thumb != null) {
            currentProgram.getProgramContext().setValue(
                thumb, toAddr(ROM_BASE + 0x210), toAddr(ROM_BASE + CODE_END - 1), BigInteger.ONE);
        }
        for (long value : starts) {
            Address address = toAddr(value);
            disassemble(address);
            if (getFunctionContaining(address) == null) {
                createFunction(address, String.format("FUN_%08x", value));
            }
        }
        println("Seeded " + starts.size() + " statically referenced function starts");
    }
}
