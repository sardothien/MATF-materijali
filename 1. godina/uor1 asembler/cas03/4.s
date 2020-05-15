.intel_syntax noprefix
.text

.global kolicnik

# void kolicnik(unsigned, unsigned, unsigned*, unsigned*)
#                edi        esi       rdx        rcx

kolicnik:
 enter 0,0
 
 mov r12, rdx
 mov eax, edi
 cdq
 div esi
 
 mov [r12], eax # kolicnik
 mov [rcx], edx # ostatak
 
leave
ret
