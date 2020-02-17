.intel_syntax noprefix
.text
.global napravi

# void napravi(int*, int*, int, int*)
#              rdi   rsi   edx  rcx
#               X     Y     n    Z

napravi:
 enter 0,0
 
 mov r8, 0 # brojac = 0
 
 petlja:
  cmp edx, 0 # n == 0
  jle kraj
  
  dec edx    # n--
  
  push rdi
  push rsi
  push rdx
  push rcx
  push r8
  
  mov r11d, 2              # r11d = 2
  mov r9d, [rdi + 4*r8]    # r9d = x[0]
  mov r10d, [rsi + 4*r8]   # r10d = y[0]
  add r9d, r10d            # x[0] + y[0]
  mov eax, r9d             # eax = x[0] + y[0]
  cdq
  idiv r11d                # (x[0] + y[0])/2
  cmp edx, 0
  je dalje
  
  mov edx, 1
  jmp poziv
  
  dalje:            # x[0] + y[0] je paran
   mov edx, 0
  
  poziv:
   mov edi, [rdi + 4*r8]
   mov esi, [rsi + 4*r8]
   
  call izracunaj
  
  pop r8
  pop rcx
  pop rdx 
  pop rsi
  pop rdi
  
  mov [rcx + 4*r8], eax
  inc r8d
 jmp petlja
 
 kraj:
  leave
  ret
