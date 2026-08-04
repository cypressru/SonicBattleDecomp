    .syntax unified
    .thumb
    .section .text
    .align 2

    .macro function name
    .global \name
    .type \name, %function
    .thumb_func
\name:
    .endm

    .macro endfunction name
    .size \name, . - \name
    .endm

    .ifdef L_ArcTan2
    function ArcTan2
    swi #10
    bx lr
    endfunction ArcTan2
    .endif

    .ifdef L_CpuFastSet
    function CpuFastSet
    swi #12
    bx lr
    endfunction CpuFastSet
    .endif

    .ifdef L_CpuSet
    function CpuSet
    swi #11
    bx lr
    endfunction CpuSet
    .endif

    .ifdef L_Div
    function Div
    swi #6
    bx lr
    endfunction Div
    .endif

    .ifdef L_DivArm
    function DivArm
    swi #7
    bx lr
    endfunction DivArm
    .endif

    .ifdef L_Mod
    function Mod
    swi #6
    adds r0, r1, #0
    bx lr
    endfunction Mod
    .endif

    .ifdef L_IntrWait
    function IntrWait
    movs r2, #0
    swi #4
    bx lr
    endfunction IntrWait
    .endif

    .ifdef L_LZ77UnCompWram
    function LZ77UnCompWram
    swi #17
    bx lr
    endfunction LZ77UnCompWram
    .endif

    .ifdef L_LZ77UnCompVram
    function LZ77UnCompVram
    swi #18
    bx lr
    endfunction LZ77UnCompVram
    .endif

    .ifdef L_MultiBoot
    function MultiBoot
    movs r1, #1
    swi #37
    bx lr
    endfunction MultiBoot
    .endif

    .ifdef L_RLUnCompWram
    function RLUnCompWram
    swi #15
    bx lr
    endfunction RLUnCompWram
    .endif

    .ifdef L_RegisterRamReset
    function RegisterRamReset
    swi #1
    bx lr
    endfunction RegisterRamReset
    .endif

    .ifdef L_Sqrt
    function Sqrt
    swi #8
    bx lr
    endfunction Sqrt
    .endif

    .ifdef L_VBlankIntrWait
    function VBlankIntrWait
    movs r2, #0
    swi #5
    bx lr
    endfunction VBlankIntrWait
    .endif

    .ifdef L_SoftResetExram
    function SoftResetExram
    ldr r3, =0x04000208
    movs r2, #0
    strb r2, [r3, #0]
    ldr r3, =0x03007FFA
    movs r2, #1
    strb r2, [r3, #0]
    subs r3, #0xFA
    mov sp, r3
    movs r2, #1
    bics r0, r2
    swi #1
    swi #0
    endfunction SoftResetExram
    .pool
    .endif

    .align 2, 0
