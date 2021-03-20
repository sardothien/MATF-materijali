.intel_syntax noprefix
.text
.global deljiv_16

# int deljiv_16(int)
# eax           edi

deljiv_16:
 enter 0,0 
 xor eax, eax
 and edi, 15
 jnz nije_deljiv
 
 mov eax, 1
 jmp kraj
 
 nije_deljiv:
  mov eax, 0
 
 kraj:
  leave
  ret
