section .bss
    buffer: resb 64
    outbuff: resb 3500
    N: resb 8
    tmp1: resb 8
    currpos: resb 8
    outlen: resb 8

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

itoa: ; rax = num, tmp1 = end char
    xor rbx, rbx
    .pre:
        xor rdx, rdx
        mov rcx, 10
        div rcx
        push rdx
        inc rbx
        test rax, rax
        jnz .pre

        mov rcx, rbx
        mov rdx, [currpos]
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
        mov rax, [tmp1]
        mov [rdx], rax
        mov rcx, [outlen]
        add rcx, rbx
        inc rcx
        inc rdx
        mov [outlen], rcx
        mov [currpos], rdx
        ret

print: ; print whatever is in buffer
    mov rdx, [outlen]
    mov rax, 1
    mov rdi, 1
    mov rsi, outbuff
    syscall

    ret

global _start
_start:
    ; read input (CSES reads entire input not just one line !!!)
    mov rax, 0
    mov rdi, 0
    mov rsi, buffer
    mov rdx, 64
    syscall
    
    ; get N
    mov rdx, buffer
    call atoi
    mov [N], rax
    mov rbx, 32
    mov [tmp1], rbx
    mov rbx, outbuff
    mov [currpos], rbx

    call itoa

    mov rax, [N]
    cmp rax, 1
    je .done

    ; get sum of numbers given
    .solve:
        mov rax, [N]
        xor rdx, rdx
        mov rbx, 2
        idiv rbx
        cmp rdx, 0
        je .cont

        mov rax, [N]
        mov rbx, 3
        imul rbx
        inc rax

        .cont:
            mov [N], rax
            cmp rax, 1
            je .last
            mov rbx, 32
            mov [tmp1], rbx
            call itoa
            jmp .solve

         .last:
            mov rbx, 10
            mov [tmp1], rbx
            call itoa
    
    .done:
        call print
        mov rax, 60
        mov rdi, 0
        syscall 
