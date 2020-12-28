section .bss
    buffer: resb 2000000
    outbuff: resb 64
    N: resb 8
    cntN: resb 8
    csum: resb 8
    tmp1: resb 8
    tmp2: resb 8

section .text

atoi:
    xor rax, rax
    .top:
        movzx rcx, byte [rdx]
        inc rdx
        cmp rcx, '0'
        jb .done
        cmp rcx, '9'
        ja .done
        sub rcx, '0'
        imul rax, 10
        add rax, rcx
        jmp .top
    .done:
        ret

itoa:
    xor rdx, rdx
    mov rcx, 10
    div rcx
    push rdx
    inc rbx
    test rax, rax
    jnz itoa

    mov rcx, rbx
    mov rdx, outbuff
    .compute:
        pop rax
        add rax, '0'
        mov [rdx], rax
        inc rdx
        dec rcx
        cmp rcx, 0
        je .done
        jmp .compute
    .done:
        mov rax, 10
        mov [rdx], rax
        ret

global _start
_start:
    mov rax, 0
    mov rdi, 0
    mov rsi, buffer
    mov rdx, 2000000
    syscall
    
    xor rax, rax
    mov [csum], rax

    mov rdx, buffer
    call atoi
    mov [N], rax
    mov [cntN], rax
    
    mov rax, 0
    mov rdi, 0
    mov rsi, buffer
    mov rdx, 2000000
    syscall
    
    mov rdx, buffer ; CSES input is really weird and breaks assembly kinda
    call atoi

    .sum:
        call atoi
        cmp rax, 0
        je .sum
        mov rbx, [csum]
        add rax, rbx
        mov [csum], rax
        mov rax, [cntN]
        dec rax
        mov [cntN], rax
        cmp rax, 1
        jg .sum
    
    mov rax, [N]
    mov rcx, [N]
    inc rcx
    imul rcx
    mov rcx, 2
    idiv rcx

    mov rbx, [csum]
    sub rax, rbx
    xor rbx, rbx
    call itoa

    mov rdx, rbx
    inc rdx
    
    mov rax, 1
    mov rdi, 1
    mov rsi, outbuff
    syscall
    
    mov rax, 60
    mov rdi, 0
    syscall 
