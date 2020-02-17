.intel_syntax noprefix
.text

.global prost

# unsigned prost(unsigned)
#   eax            edi

prost:
 enter 0, 0

 mov ecx, 2
 mov esi, edi
 shr esi, 1

 petlja:
  cmp ecx, esi
  ja jeste_prost

  mov eax, edi
  cdq
  div ecx

  cmp edx, 0
  je nije_prost

  inc ecx
 jmp petlja

 jeste_prost:
  mov eax, 1
  leave
  ret

 nije_prost:
  mov eax, 0
  leave
  ret
