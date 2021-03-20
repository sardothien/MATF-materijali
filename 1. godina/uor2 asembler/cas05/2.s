.intel_syntax noprefix
.text

.global izbaci_neparne

# unsigned izbaci_neprane(long *niz, unsigned duzina)
#  eax                     rdi         esi 

izbaci_neparne:
 enter 0,0
 
 xor r8, r8 # brojac i
 xor r9, r9 # brojac j
 
 petlja:
  cmp r8d, esi
  je kraj
  
  mov r10, [rdi+8*r8] # clan niz[i]
  test r10, 1 # paran/neparan
  jne neparan
  
  mov [rdi+8*r9], r10 # niz[j] = niz[i] 
  inc r9
  
  neparan:
   inc r8
   jmp petlja
 
 kraj:
  mov eax, r9d
  leave
  ret
