.intel_syntax noprefix 
.text
.global napravi_niz

# void napravi_niz(int*, int*, int, int*, int)
#                  rdi   rsi   edx  rcx   r8d
#                  niz1  niz2   n   niz3   m
napravi_niz:
 enter 0,0
 
 mov r9, 0    # i = 0
 mov r10, 0   # j = 0
 
 petlja:
  cmp r10d, r8d
  je kraj
  
  push rdi
  push rsi
  push rdx
  push rcx
  push r8
  push r9
  push r10
  push r11
  
  mov esi, edx
  mov edx, [rcx + 4*r10]
  call sadrzi
  
  pop r11
  pop r10
  pop r9 
  pop r8
  pop rcx
  pop rdx
  pop rsi
  pop rdi
  
  cmp eax, -1
  je dalje
  
  movsx rax, eax
  mov r12d, [rsi + 4*rax]
  mov [rcx + 4*r10], r12d
  inc r10d
 jmp petlja
 
 dalje:
  inc r10d
 jmp petlja
 
 kraj:
  leave
  ret
