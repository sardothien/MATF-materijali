.intel_syntax noprefix
.text
.global suma_cifara

# unsigned suma_cifara(unsigned);
#  eax                    edi

suma_cifara:
 enter 0,0
 
 xor r8d, r8d
 mov r9d, 10
 mov eax, edi
 
 petlja:
  cmp eax, 0
  je kraj
  
  cdq
  idiv r9d
  
  add r8d, edx
 jmp petlja
 
 kraj:
  mov eax, r8d
  leave
  ret
