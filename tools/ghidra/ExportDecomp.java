// Export decompiler output and direct call references for an address range.
// Arguments: start address, end address, output path.

import java.io.FileWriter;
import java.io.PrintWriter;

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.symbol.Reference;

public class ExportDecomp extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 3) {
            throw new IllegalArgumentException("start address, end address, and output path required");
        }

        Address start = toAddr(Long.decode(args[0]));
        Address end = toAddr(Long.decode(args[1]));
        DecompInterface decompiler = new DecompInterface();
        decompiler.openProgram(currentProgram);

        try (PrintWriter out = new PrintWriter(new FileWriter(args[2]))) {
            FunctionIterator functions =
                    currentProgram.getFunctionManager().getFunctions(start, true);
            while (functions.hasNext()) {
                Function function = functions.next();
                if (function.getEntryPoint().compareTo(end) >= 0) {
                    break;
                }

                out.printf("===== %s %s-%s =====%n", function.getName(),
                        function.getEntryPoint(), function.getBody().getMaxAddress());
                out.println("Direct calls:");
                InstructionIterator instructions =
                        currentProgram.getListing().getInstructions(function.getBody(), true);
                while (instructions.hasNext()) {
                    Instruction instruction = instructions.next();
                    for (Reference reference : instruction.getReferencesFrom()) {
                        if (reference.getReferenceType().isCall()) {
                            Function callee = currentProgram.getFunctionManager()
                                    .getFunctionAt(reference.getToAddress());
                            out.printf("  %s -> %s%n", reference.getFromAddress(),
                                    callee == null ? reference.getToAddress() : callee.getName());
                        }
                    }
                }

                DecompileResults result = decompiler.decompileFunction(function, 60, monitor);
                if (result.decompileCompleted()) {
                    out.println(result.getDecompiledFunction().getC());
                } else {
                    out.println("Decompiler failed: " + result.getErrorMessage());
                }
            }
        } finally {
            decompiler.dispose();
        }
    }
}
