.intel_syntax noprefix
.text
.global izracunaj

# int izracunaj(int n, int a, int b)
# eax           edi    esi    edx

izracunaj:
 enter 0,0
 
 xor r9d, r9d # r9d = 0
 mov r12d, edx
 
 shl edi, 1 # n = 2*n
 sub r9d, edi # r9d = -2*n
 
 mov r10d, 31 # r10d = 31
 
 mov eax, esi # eax = a
 cdqe
 cqo
 imul r10d # eax = a*31
 
 sub eax, r12d # eax = a*31 - b
 mov r11d, 4
 sub eax, r11d # eax = a*31 - b - 4
 cdq
 imul r9d # eax = -2*n * a*31-b-4
 
leave
ret
