# Napisati program koji od RESTful servisa uzima citat dana pomocu
# GET zahteva na https://quotes.rest/qod i ispisuje citat na
# standardni izlaz.

import requests

url = 'https://quotes.rest/qod'
response = requests.get(url)

if response.ok:
    json = response.json()
    print(json)
    citat = json['contents']['quotes'][0]['quote']
    print(citat)
else:
    print("Neuspesno dovlacenje citata!")