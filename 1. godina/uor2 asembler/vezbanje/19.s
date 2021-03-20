.intel_syntax noprefix
.text
.global broj_jedinica

# unsigned broj_jedinica(unsigned);
#  eax                    edi

broj_jedinica:
 enter 0,0
 
 xor r8d, r8d
 mov r9d, 2
 mov eax, edi
 
 petlja:
  cmp eax, 0
  je kraj
  
  cdq
  idiv r9d
  
  cmp edx, 1
  jne petlja
  
  inc r8d
 jmp petlja
 
 kraj:
  mov eax, r8d
  leave
  ret
