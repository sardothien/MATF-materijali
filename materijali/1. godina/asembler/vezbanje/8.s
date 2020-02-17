.intel_syntax noprefix
.text
.global najveci_3

# int najveci_3(int*, int)
# eax           edi   esi

najveci_3:
 enter 0,0
 
 xor r9d, r9d # r9d = 0
 mov r10, 3 # r10 = 3
  
 petlja:
  cmp esi, 0 
  jle kraj
  dec esi
  
  mov eax, [edi+4*esi] # eax = a[n-1]
  mov r8d, eax # r8d = eax
  cdqe 
  cqo
  idiv r10 # rax /= 3
    
  cmp edx, 0 # edx == 0
  jne petlja
  
  cmp r9d, r8d # r9d > r8d
  jg petlja
  
  mov r9d, r8d # r9d = r8d 
 jmp petlja
 
 kraj: 
  mov eax, r9d
  leave
  ret
