-- Napisati funkciju izDekadne x osn koja prebacuje broj x
-- iz dekadne osnove u osnovu osn i funkciju uDekadnu x osn
-- koja prebacuje broj x iz osnove osn u dekadnu osnovu.

uDekadnu x osn =
    if x == 0 then 0
    else uDekadnu (div x 10) osn * osn + (mod x 10)

izDekadne x osn = 
    if x == 0 then 0
    else izDekadne (div x osn) osn * 10 + (mod x osn)