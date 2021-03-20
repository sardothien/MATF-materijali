# Napisati funkciju u asembleru koja oduzima dva 
# cela broja. Napisati zatim program u C-u
# koji poziva datu funkciju.

.intel_syntax noprefix
.text
.global oduzimanje

# x je u rdi, y je u rsi

oduzimanje:
 enter 0,0
 
 mov eax, edi 
 sub eax, esi

leave
ret
