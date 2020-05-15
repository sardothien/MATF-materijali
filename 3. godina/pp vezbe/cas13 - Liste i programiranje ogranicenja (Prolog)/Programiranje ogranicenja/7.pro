/* Napisati program koji pronalazi sve vrednosti promenljivih X, Y, Z i W za
   koje vazi da je X>=2∗W, 3+Y<=Z i X−11∗W+Y+11∗Z<=100 pri cemu promenljive
   pripadaju narednim domenima X={1,2,...,10}, Y={1,3,5,...51}, 
   Z={10,20,30,...,100} i W={1,8,15,22,...,1000}. */

pronadji(Vars) :- Vars = [X, Y, Z, W],
                  X :: 1..10,
                  Y :: 1..2..51,
                  Z :: 10..10..100,
                  W :: 1..7..1000,
                  X #>= 2*W,
                  3+Y #=< Z,
                  X - 11*W + Y + 11*Z #=< 100,
                  labeling(Vars).