.intel_syntax noprefix
.text

.global suma

# int suma_niza(int*, int)
# eax           rdi   esi

suma:
 enter 0,0
 xor eax, eax
 
 petlja: 
  cmp esi, 0
  jle kraj
  
  dec esi
  add eax, [edi + 4*esi]
   
 jmp petlja
 
 kraj: 
  leave
  ret
