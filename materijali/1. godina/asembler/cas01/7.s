# Napisati funkciju u asembleru koja racuna 
# kolicnik i ostatak dva broja. Napisati zatim
# program u C-u koji poziva datu funkciju.

.intel_syntax noprefix
.text
.global deljenje

# a je u rdi, b u rsi, c u rdx, d u rcx

deljenje:
 enter 0,0
 
 # Smestamo privremeno vrednosti
 mov r8, rdx
 
 mov rax, rdi
 cqo
 idiv rsi

 # Smestamo kolicnik na c
 mov [r8], rax
 mov rcx, rdx
 
leave
ret
