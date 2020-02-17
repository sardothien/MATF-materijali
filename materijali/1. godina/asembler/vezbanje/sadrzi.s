.intel_syntax noprefix
.text
.global sadrzi

# int sadrzi(int*, int, int)
# eax        rdi   esi  edx

sadrzi:
 enter 0,0
 
 petlja:
  cmp esi, 0
  jle izlaz
  
  dec esi
  cmp edx, [rdi+4*rsi]
  je sadrzi_c  
 jmp petlja
 
 izlaz:
  mov eax, -1
  jmp kraj
 
 sadrzi_c:
  mov eax, esi
 
 kraj:
  leave
  ret
