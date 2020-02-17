.intel_syntax noprefix
.text

.global najveci

# int najveci(int*, int)
# eax          rdi   esi

najveci:
 enter 0,0
 
 cmp esi, 0
 jle prazan
  
 dec esi
 mov eax, [edi + 4*esi]
 
 petlja: 
  cmp esi, 0
  je kraj
  
  dec esi
  cmp eax, [edi+4*esi]
  jge petlja
  
  mov eax, [edi+4*esi]
  
 jmp petlja
 
 prazan:
  mov eax, 0 
 kraj: 
  leave
  ret
