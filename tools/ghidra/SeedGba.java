// Ghidra pre-script: seed analysis of a raw GBA ROM at its ARM reset vector.
// @category SonicBattle

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;

public class SeedGba extends GhidraScript {
    @Override
    public void run() throws Exception {
        Address entry = toAddr(0x08000000L);
        disassemble(entry);
        if (getFunctionAt(entry) == null) {
            createFunction(entry, "EntryPoint");
        }
        currentProgram.getSymbolTable().addExternalEntryPoint(entry);
    }
}
