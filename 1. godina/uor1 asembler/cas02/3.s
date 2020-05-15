# Napisati funkciju unsigned suma(unsigned n) koja
# racuna sumu prvih n prirodnih brojeva, pocev od 1.

.intel_syntax noprefix
.text
.global suma

# unsigned suma(unsigned x)
# rax (eax)      rdi (edi)

suma:
 enter 0,0
 
 xor eax, eax
 
 petlja:
  cmp edi, 0
  je kraj
  
  add eax, edi
  dec edi
 jmp petlja
 
 kraj:
  leave
  ret
