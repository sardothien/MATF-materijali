.intel_syntax noprefix
.text
.global deljiv

# int deljiv(int, int)
# eax        edi  esi

deljiv:
 enter 0,0
 
 mov eax, edi
 cdqe
 cqo
 idiv esi
 
 cmp edx, 0
 jne nije_deljiv
 
 mov eax, 1
 jmp kraj
 
 nije_deljiv:
  mov eax, 0
 
 kraj:
  leave
  ret
