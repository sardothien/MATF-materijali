/* Napisati program koji pronalazi sve vrednosti promenljivih X, Y, Z za 
   koje vazi da je X>=Z i X∗2+Y∗X+Z<=34 pri cemu promenljive pripadaju 
   narednim domenima X={1,2,...,90}, Y={2,4,6,...60} i Z={1,10,20,...,100}. */

pronadji(Vars) :- Vars = [X, Y, Z],
                  X :: 1..90,
                  Y :: 2..2..60,
                  Z :: 1..10..100,
                  X #>= Z,
                  2*X + X*Y + Z #=< 34,
                  labeling(Vars).