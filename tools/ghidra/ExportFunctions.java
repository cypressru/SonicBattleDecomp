// Ghidra post-script: export discovered function boundaries for local analysis.
// @category SonicBattle

import java.io.File;
import java.io.PrintWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

public class ExportFunctions extends GhidraScript {
    @Override
    public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length == 0) {
            throw new IllegalArgumentException("output CSV path required");
        }
        try (PrintWriter out = new PrintWriter(new File(args[0]))) {
            out.println("start,end,size,name,thunk");
            FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
            for (Function function : functions) {
                long start = function.getEntryPoint().getOffset();
                long end = function.getBody().getMaxAddress().getOffset() + 1;
                out.printf("0x%08X,0x%08X,%d,%s,%s%n", start, end,
                    function.getBody().getNumAddresses(), function.getName(), function.isThunk());
            }
        }
    }
}
