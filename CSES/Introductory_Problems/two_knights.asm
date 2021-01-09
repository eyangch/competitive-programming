section .bss
    buffer: resb 5
    outbuff: resb 155000

section .data

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

itoa: ; rax = num, rdi = end char, rsi = buffer pos
    xor rbx, rbx
    .pre:
        xor rdx, rdx
        mov rcx, 10
        div rcx
        push rdx
        inc rbx
        cmp rax, 0
        jne .pre

        mov rcx, rbx
    .compute:
        pop rax
        add rax, '0'
        mov [rsi], rax
        inc rsi
        dec rcx
        cmp rcx, 0
        je .done
        jmp .compute
    .done:
        mov [rsi], rdi
        inc rsi
        ret

print: ; print whatever is in buffer
    mov rdx, rsi
    sub rdx, outbuff
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
    mov rdx, 5
    syscall

    mov rsi, outbuff
    xor rdi, rdi

    ; get N
    mov rdx, buffer
    call atoi
    
    mov r9, rax
    mov r10, rax
    ; solve problem
    .solve:
        cmp r9, 0
        je .done
        mov rax, r10
        sub rax, r9
        inc rax
        mov rbx, rax
        mul rbx ; i*i
        dec rax ; i*i-1
        mul rbx ; i*(i*i-1)
        mul rbx ; i*i*(i*i-1)
        shr rax, 1 ; i*i*(i*i-1)/2
        mov r11, rax
        dec rbx
        mov rax, rbx ; (i-1)
        dec rbx
        mul rbx ; (i-1)*(i-2)
        shl rax, 2 ; 4*(i-1)*(i-2)
        sub r11, rax ; i*i*(i*i-1)/2 - 4*(i-1)*(i-2)
        mov rax, r11
        mov rdi, 10
        call itoa
        dec r9
        jmp .solve
    
    .done:
        call print
        mov rax, 60
        mov rdi, 0
        syscall 
