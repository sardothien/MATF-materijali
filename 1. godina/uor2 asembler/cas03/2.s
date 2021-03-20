.intel_syntax noprefix
.text

.global ojler

# unsigned ojler(unsigned x)
#  eax              edi 

ojler:
 enter 0,0

 xor r12d, r12d # suma = 0
 mov esi, 2 # brojac
 
 petlja:
  cmp esi, edi
  jae kraj
  
  push rdi
  push rsi
  
  call nzd
  
  pop rsi
  pop rdi
  
  cmp eax, 1
  jnz dalje
  
  add r12d, 1
  
  dalje: 
   inc esi  
 
 jmp petlja
  
 kraj:  
  mov eax, r12d
  leave
  ret
