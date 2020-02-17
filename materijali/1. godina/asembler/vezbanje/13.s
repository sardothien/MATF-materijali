.intel_syntax noprefix
.text
.global smesti

# void smesti(int*, int, int*, int*)
#             rdi   esi  rdx   rcx

smesti:
 enter 0,0
 
 mov r8, 0  # brojac za niz1
 mov r9, 0  # brojac za niz2
 
 petlja:
  cmp esi, 0
  jle kraj
  
  dec esi # n--
  
  mov r10d, [rdi+4*r8]   # r10d = a[0]
  test r10d, 1           # r10d == 1
  jne dalje
  
  push rdi
  push rsi
  push rdx
  push rcx
  push r8
  push r9
  
  mov edi, [rdi+4*r8]    # edi = a[0]
  call vrednost
  
  pop r9
  pop r8
  pop rcx
  pop rdx
  pop rsi
  pop rdi
  
  mov [rdx+4*r9], eax    # b[0] = eax
  inc r9d                # r9d++
  
  dalje:
   inc r8d # r8d++
  jmp petlja
 
 kraj:
  mov [rcx], r9d         # vrednost = r9d
  leave
  ret
