.intel_syntax noprefix
.text
.global s_niz

# int s_niz(int, int, int)
# eax       edi  esi  edx

s_niz:
 enter 0,0
 
 mov r8d, 32 # r8d = 32
 xor r9d, r9d # r9d = 0
 inc r9d
 inc r9d # r9d = 2
 mov r10d, edx
 
 petlja:
  cmp r9d, r10d # r9d == 4
  je kraj
   
  mov eax, esi # eax = Sn-1
  cdqe
  cqo
  imul r8d # eax *= 32
  sub eax, edi #  eax -= Sn-2
  
  mov edi, esi # Sn-2 = Sn-1
  mov esi, eax # Sn-1 = eax
    
  inc r9d
 jmp petlja
  
 kraj:
  leave
  ret
