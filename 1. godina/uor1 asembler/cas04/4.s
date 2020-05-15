.intel_syntax noprefix
.text

.global fibonaci

# void fibonaci(int, int*)
#               edi   esi

fibonaci:
 enter 0,0
 
 cmp edi, 0
 je kraj
 
 mov r8d, 1
 mov [esi], r8d
 
 dec edi
 cmp edi, 0
 je kraj
 
 mov ecx, 1
 mov [esi+4*ecx], r8d
 
 mov r9d, ecx
 dec r9d
 mov r10d, ecx
 inc ecx
  
 petlja: 
  dec edi
  cmp edi, 0
  je kraj
  
  mov r11d, [esi+4*r9d]
  add r11d, [esi+4*r10d]
  mov [esi+4*ecx], r11d
  
  inc r9d
  inc r10d
  inc ecx 
 jmp petlja
 
 kraj: 
  leave
  ret
