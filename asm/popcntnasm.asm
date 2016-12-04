;; ****************************************************************************************************
;; count the number of bits set using the popcnt instruction
;; ****************************************************************************************************
;; nasm -f elf64 popcntnasm.asm && gcc -o popcntnasm popcntnasm.o

section .text
global main
extern printf

main:
        push rbp
        mov rbp, rsp
	mov rdx, 0xf00ff00ff00ff00f
        popcnt rax, rdx
        mov rsi, rax
        mov rdi, msg
        call printf
        mov rsp, rbp
        pop rbp
        xor rax, rax
        ret

msg db "popcntasm: %d", 10, 0
