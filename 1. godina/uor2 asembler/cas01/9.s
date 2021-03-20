.intel_syntax noprefix
.text
.global maksimum

# a je u edi, b u esi

maksimum:
 enter 0,0
 cmp edi, esi
 jg maxa
 
 mov eax, esi
 jmp kraj
 
 maxa:
  mov eax, edi
 
 kraj: 
  leave
  ret
