.intel_syntax noprefix
.text
.global najveci

# int najveci(int*, int)
# eax         rdi   esi

najveci:
 enter 0,0
 
 dec esi
 mov eax, [edi+4*esi]
  
 petlja:
  cmp esi, 0
  je kraj
  
  dec esi
  cmp eax, [edi+4*esi]
  jg petlja
  
  mov eax, [edi+4*esi]  
 
 jmp petlja
 
 kraj:
  leave
  ret
