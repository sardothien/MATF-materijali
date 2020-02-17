.intel_syntax noprefix
.text
.global najveca_cifra

# unsigned najveca_cifra(unsigned);
#  eax                    edi
# ostatak je u edx, a ceo deo u eax

najveca_cifra:
 enter 0,0
 
 mov rsi, 10
 mov eax, edi # eax = n
 cdqe
 cqo
 div rsi # eax = n/10
 mov r8d, edx # r8d = n%10
 
 petlja:
  cmp eax, 0 # eax == 0
  je kraj
  
  cqo 
  div rsi # eax = n/10
  cmp r8d, edx # n%10 > (n/10)%10
  jnb dalje
  
  mov r8d, edx    
 jmp petlja
 
 dalje:
  jmp petlja
 
 kraj: 
  mov eax, r8d
  leave
  ret
