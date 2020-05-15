.intel_syntax noprefix
.text
.global vrednost

# unsigned vrednost(unsigned)
#   eax               edi

vrednost:
 enter 0,0
 
 xor r10d, r10d
 
 petlja:
  cmp edi, 0
  je kraj
  
  mov r8d, edi
  mov r9d, edi
  
  shl r8d, 1
  mov eax, r8d
  cdq 
  imul r9d
  inc r9d
  imul r9d
  
  add r10d, eax
 
  dec edi
 jmp petlja
 
 kraj:
  mov eax, r10d
  leave
  ret
