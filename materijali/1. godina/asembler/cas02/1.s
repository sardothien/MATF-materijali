# Napisati funkciju int deljiv_4(int) koja vraca  1 ako
# je argument deljiv sa 4 a 0 ako nije.

.intel_syntax noprefix
.text
.global deljiv_4

# int deljiv_4(int x);
# rax         rdi (edi)

deljiv_4:
 enter 0,0
 
 xor eax, eax # dovodimo eax na 0
 and edi, 3
 jnz nije_deljiv
 
 mov eax, 1
 
 nije_deljiv: 
  leave
  ret
