.intel_syntax noprefix
.text
.global faktorijel

# unsigned faktorijel(unsigned)
#  eax                 edi
# ostatak u edx, ceo deo u eax

faktorijel:
 enter 0,0
 
 xor eax, eax
 inc eax # f = 1
 cdqe
 
 petlja:
  cmp edi, 0
  je kraj
  
  cqo 
  mul edi
  dec edi
 jmp petlja
  
 kraj:
  leave
  ret
