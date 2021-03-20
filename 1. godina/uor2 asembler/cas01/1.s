# Napisati program koji ispisuje pozdravnu poruku
# na izlaz

.intel_syntax noprefix
.data

fmt: .asciz "Zdravo, svima!\n"

.text
.global main

main:
 enter 0,0
 
 lea rdi, fmt
 call printf
 
leave
ret
