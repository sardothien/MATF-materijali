.intel_syntax noprefix
.text
.global aritmetika

# int aritmetika(int, int, char)
# eax            edi  esi  edx

aritmetika:
 enter 0,0
 
 cmp edx, '+'
 je zbir
 cmp edx, '-'
 je razlika
 cmp edx, '*'
 je proizvod
 cmp edx, '/'
 je kolicnik
 cmp edx, '~'
 je suprotan_broj
 cmp edx, '&'
 je konjukcija
 cmp edx, '|'
 je disjunkcija
 cmp edx, '^'
 je negacija
 jmp nista

 zbir:
  mov eax, edi
  add eax, esi
  jmp kraj
 
 razlika:
  mov eax, edi
  sub eax, esi
  jmp kraj 
 
 proizvod:
  mov eax, edi
  cdq
  imul esi
  jmp kraj
 
 kolicnik:
  mov eax, edi
  cdq
  idiv esi
  jmp kraj
 
 suprotan_broj:
  mov r8d, 0
  sub r8d, edi
  mov eax, r8d
  jmp kraj
 
 konjukcija:
  and edi, esi
  mov eax, edi
  jmp kraj
 
 disjunkcija:
  or edi, esi
  mov eax, edi
  jmp kraj
 
 negacija:
  not edi
  mov eax, edi
 
 nista:
  mov eax, 0
 
 kraj: 
  leave
  ret
