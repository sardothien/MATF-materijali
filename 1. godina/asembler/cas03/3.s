.intel_syntax noprefix
.text

.global zameni

# void zameni(int *x, int *y)
#              rdi      rsi

zameni:
 enter 0, 0
 mov eax, [rdi] # bazno (indirektno) adresiranje
                # u rdi je adresa na kojoj se nalazi
                # ono sto zelimo da premestimo u rax
 mov ecx, [rsi]
 mov [rdi], ecx # smesta na adresu koja se nalazi
                # u rdi
 mov [rsi], eax
 
 # mora eax, ecx itd. jer int ima 4 bajta
       # eax... takodje ima 4 bajta 
 # ako stavimo mov [rdi], [rsi] nece znati koliko
       # bajtova da premesti
 
leave
ret 
