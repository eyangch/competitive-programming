section .bss
    buffer: resb 64
    outbuff: resb 7000000
    N: resb 8
    echar: resb 8
    currpos: resb 8
    outlen: resb 8

section .data
nosoln db "NO SOLUTION" ,10
nslen equ $ - nosoln

section .text

atoi:
    push rbx
    push rcx
    push rdx
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
        pop rdx
        pop rcx
        pop rbx
        ret

itoa: ; rax = num, echar = end char
    push rax
    push rbx
    push rcx
    push rdx
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
        mov rax, [echar]
        mov [rdx], rax
        mov rcx, [outlen]
        add rcx, rbx
        inc rcx
        inc rdx
        mov [outlen], rcx
        mov [currpos], rdx
        pop rdx
        pop rcx
        pop rbx
        pop rax
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

    mov rbx, outbuff
    mov [currpos], rbx

    ; get N
    mov rdx, buffer
    call atoi
    mov [N], rax

    ; solve problem
    .solve:
        cmp rax, 2
        je .bad
        cmp rax, 3
        je .bad
        
        mov rcx, 2
        .l1:
            cmp rcx, rax
            jg .f1
            push rax
            mov rax, rcx
            mov rbx, 32
            mov [echar], rbx
            call itoa
            pop rax
            add rcx, 2
            jmp .l1
        .f1:
            mov rcx, 1
        .l2:
            cmp rcx, rax
            jg .f2
            push rax
            mov rax, rcx
            mov rbx, 10
            pop rdx
            add rcx, 2
            cmp rcx, rdx
            jg .aftersp
            mov rbx, 32
        .aftersp:
            push rdx
            mov [echar], rbx
            call itoa
            pop rax
            jmp .l2
         .f2:
            call print
            jmp .done

    .bad:
        mov rdx, nslen
        mov rax, 1
        mov rdi, 1
        mov rsi, nosoln
        syscall
    
    .done:
        mov rax, 60
        mov rdi, 0
        syscall 
