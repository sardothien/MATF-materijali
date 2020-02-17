.intel_syntax noprefix
.text
.global izracunaj

# int izracunaj(int, int, int)
# eax           edi  esi  edx
#                x    y    k

izracunaj:
 enter 0,0
 
 mov r8d, 2
 
 mov eax, edx
 cdq
 imul r8d
 
 dec edi
 cdq
 imul edi
 
 dec esi
 cdq
 imul esi
 
leave
ret
