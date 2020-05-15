# Napisati funkciju u asembleru koja racuna 
# proizvod dva broja. Napisati zatim program u C-u
# koji poziva datu funkciju.

.intel_syntax noprefix
.text
.global proizvod

# a je u rdi, b u rsi

proizvod:
 enter 0,0
 
 mov rax, rdi 
 imul rsi
 
leave
ret
