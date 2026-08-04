    .syntax unified
    .arm
    .section .text
    .align 2

    .global start_vector
    .type start_vector, %function
.Lstart_vector:
start_vector:
    mov r0, #0x12
    msr cpsr_fc, r0
    ldr sp, sp_irq
    mov r0, #0x1F
    msr cpsr_fc, r0
    ldr sp, sp_sys
    ldr r1, intr_vector
    adr r0, IntrMain
    str r0, [r1]
    ldr r1, agb_main
    mov lr, pc
    bx r1
    b .Lstart_vector
    .size start_vector, . - start_vector

sp_sys:
    .word 0x03007F00
sp_irq:
    .word 0x03007FA0
intr_vector:
    .word 0x03007FFC
agb_main:
    .word 0x08000779

    .global IntrMain
    .type IntrMain, %function
IntrMain:
    mov r3, #0x04000000
    add r3, r3, #0x200
    ldr r2, [r3]
    ldrh r1, [r3, #8]
    mrs r0, spsr
    stmfd sp!, {r0-r3, lr}
    mov r0, #1
    strh r0, [r3, #8]
    and r1, r2, r2, lsr #16
    mov r12, #0

    ands r0, r1, #0xC0
    bne intr_found
    add r12, r12, #4
    ands r0, r1, #1
    bne intr_found
    add r12, r12, #4
    ands r0, r1, #4
    bne intr_found
    add r12, r12, #4
    ands r0, r1, #0x20
    bne intr_found
    add r12, r12, #4
    ands r0, r1, #0x2000
    strbne r0, [r3, #-0x17C]
1:
    bne 1b

intr_found:
    strh r0, [r3, #2]
    mov r1, #0x20C0
    bic r2, r2, r0
    and r1, r1, r2
    strh r1, [r3]

    mrs r3, cpsr
    bic r3, r3, #0xDF
    orr r3, r3, #0x1F
    msr cpsr_fc, r3

    ldr r1, intr_table
    add r1, r1, r12
    ldr r0, [r1]
    stmfd sp!, {lr}
    adr lr, 2f
    bx r0
2:
    ldmfd sp!, {lr}

    mrs r3, cpsr
    bic r3, r3, #0xDF
    orr r3, r3, #0x92
    msr cpsr_fc, r3

    ldmfd sp!, {r0-r3, lr}
    strh r2, [r3]
    strh r1, [r3, #8]
    msr spsr_fc, r0
    bx lr
    .size IntrMain, . - IntrMain

intr_table:
    .word 0x03003150
