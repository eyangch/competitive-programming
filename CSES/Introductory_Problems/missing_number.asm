; CSES Missing Number Fastest Submission on 12/28/2020

section .bss
    buffer: resb 1300000
    outbuff: resb 64
    N: resb 8
    cntN: resb 8
    csum: resb 8

section .text

atoi:
    xor rax, rax
    xor rcx, rcx
    .pre:
        mov cl, [rdx]
        inc rdx
        cmp rcx, '0'
        jb .pre
        cmp rcx, '9'
        ja .pre
        dec rdx
    .compute:
        mov cl, [rdx]
        inc rdx
        cmp rcx, '0'
        jb .done
        cmp rcx, '9'
        ja .done
        sub rcx, '0'
        imul rax, 10
        add rax, rcx
        jmp .compute
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
    ; read input (CSES reads entire input not just one line !!!)
    mov rax, 0
    mov rdi, 0
    mov rsi, buffer
    mov rdx, 1300000
    syscall
    
    ; clear csum
    xor rax, rax
    mov [csum], rax
    
    ; get N
    mov rdx, buffer
    call atoi
    mov [N], rax
    mov [cntN], rax

    ; get sum of numbers given
    .sum:
        call atoi
        mov rbx, [csum]
        add rax, rbx
        mov [csum], rax
        mov rax, [cntN]
        dec rax
        mov [cntN], rax
        cmp rax, 1
        jg .sum
    
        ; get total sum of numbers
        mov rax, [N]
        mov rcx, [N]
        inc rcx
        imul rcx
        mov rcx, 2
        idiv rcx

        ; subtract to get answer
        mov rbx, [csum]
        sub rax, rbx
    
    .print:
        xor rbx, rbx
        call itoa

        mov rdx, rbx
        inc rdx
        
        ; print answer
        mov rax, 1
        mov rdi, 1
        mov rsi, outbuff
        syscall
        
        mov rax, 60
        mov rdi, 0
        syscall 
