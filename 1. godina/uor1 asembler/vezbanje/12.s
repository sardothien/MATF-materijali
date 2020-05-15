.intel_syntax noprefix
.text
.global clan_niza

# int clan_niza(int)
# eax           edi

clan_niza:
 enter 0,0
 
 xor eax, eax
 inc eax # a[0] == 1
  
 petlja:
  cmp edi, 0
  jle kraj
  
  shl eax, 2
  add eax, 3
  
  dec edi
 jmp petlja 
 
 kraj:
  leave 
  ret
