# Napisati funkciju unsigned suma_cifara(unsigned) 
# koja racuna sumu dekadnih cifara argumenta.

.intel_syntax noprefix
.text
.global suma_cifara

# unsigned suma_cifara(unsigned);
#  rax (eax)           rdi (edi)
# ostatak je u rdx(edx), ceo deo je u rax(eax)

suma_cifara:
 enter 0, 0
 
 xor r8d, r8d
 mov rsi, 10
 mov eax, edi
 cdqe
 
 petlja:
  cmp eax, 0
  je kraj
  
  cqo
  div rsi
  add r8d, edx # ostatak+suma
 jmp petlja
  
 kraj:
  mov eax, r8d
  leave
  ret
