.intel_syntax noprefix
.text
.global suma_razlika

# int suma_razlika(int*, int)
# eax              edi   esi

suma_razlika:
 enter 0,0
 
 xor eax, eax # suma = 0
 xor r8d, r8d # brojac koji ce ici do n (esi)
 dec esi # n = n-1
 
 petlja:
  cmp r8d, esi
  jz kraj
  
  mov r9d, [edi+4*r8d] # r9d = a[0]
  inc r8d # r8d++
  mov r10d, [edi+4*r8d] # r10d = a[1]
  
  sub r10d, r9d # a[1] -= a[0]
    
  add eax, r10d # eax += r10d
 jmp petlja
 
 kraj:
  leave
  ret
