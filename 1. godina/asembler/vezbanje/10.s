.intel_syntax noprefix
.text
.global savrsen

# int savrsen(int);
# eax         edi

savrsen:
 enter 0,0
 
 xor esi, esi # suma = 0
 mov r8d, edi # r8d = n !za kraj!
 mov eax, edi # eax = n
 
 sar edi, 1 # n = n/2
 
 petlja:
  cmp edi, 0 # edi == 0
  je izlaz
  
  mov eax, r8d # eax = n
  cdq
  idiv edi # eax /= edi
    
  cmp edx, 0 # ostatak == 0
  jne dalje
  
  add esi, edi # suma += edi
  dec edi # edi--
  jmp petlja
  
  dalje:
   dec edi   
 jmp petlja
 
 izlaz:
  cmp r8d, esi # n == suma
  je jeste_savrsen
 
 mov eax, 0
 jmp kraj
 
 jeste_savrsen:
  mov eax, 1 
 
 kraj:
  leave
  ret
