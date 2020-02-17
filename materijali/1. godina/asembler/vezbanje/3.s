.intel_syntax noprefix
.text
.global min

# unsigned min(unsigned, unsigned, unsigned)
#  eax          edi       esi        edx

min:
 enter 0,0
 
 cmp edi, esi # a i b
 jb poredi_a_c # a < b
 
 # a > b
 cmp esi, edx # b, c
 jb min1 # b < c
 mov eax, edx # eax = c 
 jmp kraj
 
 poredi_a_c:
  cmp edi, edx # a i c
  jb min2 # a < c  
  mov eax, edx # eax = c
  jmp kraj
 
 min1: 
  mov eax, esi # eax = b
  jmp kraj
 min2:
  mov eax, edi # eax = a
 
 kraj:
  leave
  ret
