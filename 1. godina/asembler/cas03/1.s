.intel_syntax noprefix
.text

.global nzd

# unsigned nzd (unsigned x, unsigned y)
#  eax            edi         esi

nzd:
 enter 0,0
 
 mov eax, edi # x
 mov edx, esi # y
  
 petlja:
  cmp edx, 0
  je kraj
  
  cdq
  div esi # ostatak je u edx
  
  mov eax, esi
  mov esi, edx
  
 jmp petlja 
  
 kraj:  
  leave
  ret
