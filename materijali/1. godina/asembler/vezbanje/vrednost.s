.intel_syntax noprefix
.text
.global vrednost

# int vrednost(int)
# eax          edi

vrednost:
 enter 0,0
 
 mov eax, edi
 cdq
 imul edi
 
 cmp eax, 24
 jl kraj
 
 mov eax, 24
 
 kraj:
  leave
  ret
