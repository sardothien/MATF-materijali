.intel_syntax noprefix
.text

.global savrsen_stepen

# 1. zadatak (sajt)
# int savrsen_stepen(unsigned n, unsigned *m, unsigned *k)
# eax                 edi          rsi          rdx

savrsen_stepen:
 enter 0,0

 mov r8d, 2 # m
 mov r10d, edi
 mov r11, rdx
 shr r10d, 1 # n/2
 
 petlja1:
  cmp r8d, r10d # m i n/2
  ja kraj
  
  mov r9d, 2 # k
  
  petlja2: # m^k
   mov ecx, 0 # brojac i
   mov eax, 1 # proizvod
   
   petlja3:
    cmp ecx, r9d # cmp i, k
    jae kraj_stepena

    mul r8d # proizvod * m
    inc ecx
    
   jmp petlja3
   
 # Drugi nacin
 
 # petlja:
 #  cmp r8d, r10d # m i n/2
 #  ja kraj
 #  mov r9d, 2 # k
 #  mov eax, r8d
 #  mul r8d
 # petlja2:
 #  cmp eax, edi
 #  je nadjeno
 #  ja nastavi
 #  inc r9d
 #  mul r8d
 # jmp petlja2
   
 kraj_stepena:
  cmp eax, edi # proizvod i n
  je nadjeno # jednako
  ja nastavi1 # m^k > n
  
  inc r9d
  jmp petlja2
  
 nastavi1:
  inc r8d
  jmp petlja1
 
 nadjeno:
  mov [rsi], r8d
  mov [r11], r9d
  mov eax, 1
  leave
  ret
 
 kraj:
  mov eax, 0
  leave
  ret
