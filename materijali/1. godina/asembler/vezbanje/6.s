.intel_syntax noprefix
.text
.global zbir_apsolutnih

# int zbir_apsolutnih(int*, int)
# eax                 edi   esi

zbir_apsolutnih:
 enter 0,0 
 
 cmp esi, 0 # n == 0
 jle kraj
 
 xor eax, eax # eax = 0 
   
 petlja:  
  cmp esi, 0 # n == 0
  je kraj
  
  dec esi  # n--
  mov r8d, [edi+4*esi] # r8d = a[n-1]
  cmp r8d, 0 
  jl dalje # r8d < 0 ?
  
  add eax, r8d # eax += r8d
  jmp petlja
  
  dalje: # r8d < 0
   mov r9d, 0   # r9d = 0
   sub r9d, r8d # r9d = 0 - (-r8d)
   add eax, r9d # eax += r8d   
 jmp petlja
 
 kraj: 
  leave
  ret 
