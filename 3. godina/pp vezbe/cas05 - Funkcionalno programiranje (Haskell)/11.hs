-- Napisati funkciju tipJednacine a b c koja vraca
-- tip kvadratne jednacine a*x^2 + b*x + c = 0
-- (degenerisana, jedno resenje, dva resenja, bez resenja).

tipJednacine a b c
    | a == 0 = "Degenerisana"
    | (b*b - 4*a*c) == 0 = "Jedno resenje"
    | (b*b - 4*a*c) > 0 = "Dva resenja"
    | otherwise = "Bez resenja"