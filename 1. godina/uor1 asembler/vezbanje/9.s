.intel_syntax noprefix
.text
.global izdvoji_deljive

# void izdvoji_deljive(int*, int, int*, int*)
#                      rdi   esi  rdx   rcx

izdvoji_deljive:
 enter 0,0
 
 mov r8, 0     # brojac za a 
 mov r9, 0     # brojac za b
 
 petlja:
  cmp esi, 0  # esi == 0
  jle kraj     
   
  dec esi     # esi--
  
  push rdi
  push rsi
  push rdx
  push rcx
  push r8
  push r9
  
  mov edi, [rdi + 4*r8]  # edi = a[0]
  mov esi, 7             # esi = 7
  call deljiv  
  
  pop r9
  pop r8
  pop rcx
  pop rdx
  pop rsi
  pop rdi 
  
  cmp eax, 0  # eax == 0
  je dalje
  
  mov r10d, [rdi + 4*r8]  # r10d = a[0]
  mov [rdx + 4*r9], r10d  # b[0] = r10d
  inc r9d                 # r9d++
  
  dalje:
   inc r8d                # r8d++
 jmp petlja
 
 kraj:
  mov [rcx], r9d          # vrednost = r9d
  leave
  ret
