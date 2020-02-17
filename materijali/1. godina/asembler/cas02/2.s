# Napisati funkciju int prestupna(unsigned) koja
# proverava da li je godina data argumentom prestupna
# (ako je deljiva sa 4; izuzetak tome su godine deljive
# sa 100; izuzetak tom izuzetku su godine deljive sa
# 400).

.intel_syntax noprefix
.text
.global prestupna

# unsigned prestupna(unsigned x);
# rax (eax)           rdi (edi)

prestupna:
 enter 0,0
 
 mov eax, edi
 # da li je deljiva sa 4?
 and eax, 3
 jne nije_prestupna
 # da li je deljiva sa 100?
 mov eax, edi
 cdqe
 cqo
 mov rsi, 100
 div rsi
 cmp rdx, 0
 jne jeste_prestupna
 # da li je deljiva sa 400?
 mov eax, edi
 cdqe
 cqo
 mov rsi, 400
 div rsi
 cmp rdx, 0
 jne nije_prestupna
 
 jeste_prestupna:
  mov eax, 1
  leave
  ret
 
 nije_prestupna:
  mov eax, 0
  leave
  ret
