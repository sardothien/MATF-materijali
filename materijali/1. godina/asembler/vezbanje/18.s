.intel_syntax noprefix
.text
.global hipotenuza

# int hipotenuza(int, int)
# eax            edi  esi

hipotenuza:
 enter 0,0
 
 mov eax, edi
 cdq 
 imul edi
 mov r8d, eax # r8d = x*x
 
 mov eax, esi
 cdq 
 imul esi # eax = y*y
 
 add eax, r8d # eax = x*x + y*y
 mov r8d, eax
 
 mov eax, 1
 mov r9d, 1 
  
 petlja:
  cmp eax, r8d # r8d = 2*2 + 3*3
  jg kraj
  
  mov eax, r9d
  inc eax
  cdq
  imul eax
  inc r9d  
 jmp petlja
 
kraj: 
 dec r9d
 mov eax, r9d
 leave
 ret
