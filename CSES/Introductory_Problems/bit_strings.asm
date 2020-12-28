; CSES Bit Strings Fastest Submission as of 12/28/2020

section .bss
    buffer: resb 64
    outbuff: resb 64
    N: resb 8
    a: resb 8
    echar: resb 8
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

itoa: ; rax = num, echar = end char
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
    
    mov rbx, 2
    mov [a], rbx

    mov rax, 1
    xor rcx, rcx

    ; get sum of numbers given
    .solve:
        cmp rcx, 20
        je .done
        mov rbx, 1
        shl rbx, cl
        mov rdx, [N]
        and rdx, rbx
        mov rbx, 1000000007
        cmp rdx, 0
        je .mulmod
        push rcx
        mov rcx, [a]
        imul rcx
        xor rdx, rdx
        idiv rbx
        mov rax, rdx
        pop rcx
        .mulmod:
            push rax
            mov rax, [a]
            imul rax
            xor rdx, rdx
            idiv rbx
            mov [a], rdx
            pop rax
            inc rcx
            jmp .solve
        
    
    .done:
        mov rbx, outbuff
        mov [currpos], rbx
        mov rbx, 10
        mov [echar], rbx
        call itoa
        call print
        mov rax, 60
        mov rdi, 0
        syscall 
