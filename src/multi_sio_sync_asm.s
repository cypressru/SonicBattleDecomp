    .syntax unified
    .arm
    .section .text
    .align 2

    .global MultiSioRecvBufChange
    .type MultiSioRecvBufChange, %function
MultiSioRecvBufChange:
    stmfd sp!, {r8-r11}
    mov r12, #0x04000000
    ldr r11, =0x03003BF0
    add r10, r11, #0x28
    mov r9, #1
    mov r8, #0

    strb r8, [r12, #0x208]
    ldmia r10, {r0-r1}
    stmia r10!, {r1}
    stmia r10!, {r0}
    ldrb r0, [r11, #5]
    strb r8, [r11, #5]
    strb r9, [r12, #0x208]

    ldmfd sp!, {r8-r11}
    bx lr
    .size MultiSioRecvBufChange, . - MultiSioRecvBufChange
    .ltorg
