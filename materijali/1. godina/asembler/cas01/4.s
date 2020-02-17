# Napisati funkciju u asembleru koja racuna 
# bitovsku negaciju. Napisati zatim program u C-u
# koji poziva datu funkciju.

.intel_syntax noprefix
.text
.global bitska_negacija

# x je u rdi

bitska_negacija:
 enter 0,0
 
 mov rax, rdi 
 NOT rax

leave
ret
