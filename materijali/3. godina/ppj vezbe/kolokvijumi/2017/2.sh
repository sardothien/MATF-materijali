egrep '[A-Z][a-z]+,\s*[0-9]+,\s*[1-9][0-9][0-9]+' igraci.csv |
sed -r 's/([A-Za-z ]+),\s*([A-Za-z]+),\s*[0-9]+,\s*[0-9]+,\s*([0-9]+)-([0-9]+)?,\s*(.*)/\1 (\2) [\3 - \4] : \5/' |
sed -r 's/,\s*/ -> /g'

# U egrep-u izdvajamo samo igrace koji imaju preko 100 odigranih utakmica
# U prvom sed-u: grupisemo sve podatke i ispisujemo ih u trazenom obliku
# U drugom sed-u: menjamo , sa -> kod timova
