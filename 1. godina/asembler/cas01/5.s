# Napisati funkciju u asembleru koja izracunava 
# izraz (4a-b+1)/2+c/4, za prosledjene a, b i c
# kao argumente. Napisati zatim program u C-u
# koji poziva datu funkciju.

.intel_syntax noprefix
.text
.global izraz

# a je u rdi, b u rsi, c u rdx

izraz:
 enter 0,0
 shl edi, 2
 mov eax, edi  
 sub eax, esi
 inc eax
 sar eax, 1
 sar edx, 2
 add eax, edx

leave
ret
