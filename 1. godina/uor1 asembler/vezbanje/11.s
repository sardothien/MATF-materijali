.intel_syntax noprefix
.text
.global faktorizacija

# void faktorizacija(int, int*, int*, int*)
#                    rdi  rsi   rdx   rcx

faktorizacija:
 enter 0,0
 
 mov r10, rdx # r10 = niz b
 mov r8, 0    # r8 = 0
 mov r11, 2   # r11 = 2
 xor r12, r12 # r12 = 0
 mov eax, edi # eax = n
 
 petlja:
  cmp eax, 0 # eax == 0
  jle kraj
  
  mov r9d, eax # r9d = eax
  cdq
  idiv r11d    # eax /= r11d
  cmp edx, 0   # ostatak == 0
  je uvecaj1   
  
  cmp r12d, 0  # r12d == 0
  je uvecaj
  
  jne ubaci_niz
  
  uvecaj1:
   inc r12d # r12d++
 jmp petlja
 
  ubaci_niz:
   mov eax, r9d            # eax = r9d
   mov [r10 + 4*r8], r12d  # b = r12d
   mov [rsi + 4*r8], r11d  # a = r11d
   inc r8d                 # r8d++
   inc r11d                # r11d++
   xor r12d, r12d          # r12d = 0
  jmp petlja
  
  uvecaj:
   cmp eax, 0 # eax == 0
   je kraj
   
   mov eax, r9d # eax = r9d
   inc r11d     # r11d++
 jmp petlja
  
 kraj:
  mov [rcx], r8d  # vrednost = r8d
  leave
  ret
