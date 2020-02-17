.intel_syntax noprefix
.text

.global obrni

# void obrni(long*, int)
#            rdi   esi

obrni:
 enter 0,0
 
 cmp esi, 0
 jle kraj
 
 # delimo n sa 2
 mov ecx, esi # ecx je brojac
 shr ecx, 1
 
 mov r8, 0

 petlja:
  cmp ecx, 0
  je kraj
  
  dec ecx
  dec rsi
  
  mov r9, [edi+8*r8d]
  mov r10, [edi+8*esi]
  mov [edi+8*r8d], r10
  mov [edi+8*esi], r9
  
  inc r8d
 jmp petlja
 
 kraj: 
  leave
  ret
