.intel_syntax noprefix
.text

.global izdvoji_proste

# void izdvoji_proste(int*, int, int*)
# eax                 edi   esi  edx

# pokazivaci su velicine 4 bajta !
 
izdvoji_proste:
 enter 0,0
 
 mov r8d, 0 # brojac kroz prvi niz
 mov r9d, 0 # brojac kroz drugi niz
 
 petlja:
  cmp esi, 0
  je kraj
  
  dec esi
  
  push rdi
  push rsi
  push rdx
  push r8
  push r9
  
  mov r10d, [edi+4*r8d] 
  mov edi, r10d
  
  call prost # sa proslog casa
  
  pop r9
  pop r8
  pop rdx
  pop rsi
  pop rdi
  
  cmp eax, 0
  je dalje
  
  mov r10d, [edi+4*r8d]
  mov [edx+4*r9d], r10d
  inc r9d
  
  dalje:
   inc r8d
   
  jmp petlja 
 
 kraj: 
  mov eax, r9d
  leave
  ret
