;; ****************************************************************************************************
;; count the number of bits set using the popcnt instruction
;; ****************************************************************************************************
;; $ fasm asmpopcnt.asm && gcc asmpopcnt.o -o asmpopcnt
        
format ELF64
section '.text' executable
public main
extrn printf

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

section '.data' writeable
        msg db "popcntasm: %d", 0xA, 0
