# Napisati funkciju u asembleru koja sabira dva 
# cela broja. Napisati zatim program u C-u
# koji poziva datu funkciju.

.intel_syntax noprefix
.text
.global sabiranje

# x je u rdi, y je u rsi

sabiranje:
 enter 0,0
 
 mov eax, edi 
 add eax, esi

leave
ret
