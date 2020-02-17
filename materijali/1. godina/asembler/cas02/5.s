# Napisati funkciju unsigned broj_jedinica(unsigned)
# koja vraca broj jedinica u binarnom zapisu argumenta.

.intel_syntax noprefix
.text
.global broj_jedinica

# unsigned broj_jedinica(unsigned)
# rax (eax)              rdi (edi)

broj_jedinica:
 enter 0,0
 
 xor eax, eax
 
 petlja:
  cmp edi, 0
  je kraj
  
  mov r8d, edi
  and r8d, 1
  cmp r8d, 0
  je dalje
  
  add eax, 1
 
  dalje: 
   shr edi, 1
 jmp petlja
 
 kraj:
  leave
  ret
