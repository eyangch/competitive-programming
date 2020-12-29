section .bss
    buffer: resb 64
    outbuff: resb 524288
    N: resb 8
    echar: resb 8
    currpos: resb 8
    outlen: resb 8

section .data

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
    
    mov rcx, rax
    ; solve problem
    .solve:
        cmp rcx, 0
        je .done
        mov rbx, rax
        sub rbx, rcx
        inc rbx
        push rax
        push rcx
        mov rax, rbx
        imul rbx ; i*i
        dec rax ; i*i-1
        imul rbx ; i*(i*i-1)
        imul rbx ; i*i*(i*i-1)
        mov rcx, 2
        idiv rcx ; i*i*(i*i-1)/2
        push rax
        mov rax, 4 ; 4
        dec rbx
        imul rbx ; 4*(i-1)
        dec rbx
        imul rbx ; 4*(i-1)*(i-2)
        mov rbx, rax
        pop rax
        sub rax, rbx ; i*i*(i*i-1)/2 - 4*(i-1)*(i-2)
        mov rdx, 10
        mov [echar], rdx
        call itoa
        pop rcx
        pop rax
        dec rcx
        jmp .solve
    
    .done:
        call print
        mov rax, 60
        mov rdi, 0
        syscall 
