# Napisati funkciju u asembleru koja racuna 
# maksimum dva broja. Napisati zatim program
# u C-u koji poziva datu funkciju.

.intel_syntax noprefix
.text
.global maksimum

# a je u rdi, b u rsi

maksimum:
 enter 0,0
 
 # smestamo b u rax, prosirujemo i smestamo u rcx  
 mov rax, rsi 
 cdqe
 mov rcx, rax
 
 # smestamo a u rax i prosirujemo
 mov rax, rdi
 cdqe
 
 # poredimo a i b
 cmp rax, rcx
 jge a_vece
 mov rax, rcx # b vece -> uspisujemo b u rax
 a_vece: # a vece -> gotovo jer je a vec u rax
 
leave
ret
