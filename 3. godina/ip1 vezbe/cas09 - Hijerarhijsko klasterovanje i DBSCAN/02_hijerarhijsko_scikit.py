# Dat je skup dogs koji ima atribute:
#   - breed - rasa psa
#   - height - visina psa
#   - weight - tezina psa
# Primeniti hijerarhijsko sakupljajuce klasterovanje na skup 
# koriscenjem biblioteke scikit-learn programskog jezika Python. 
# Pri klasterovanju koristiti atribute visina i tezina psa. 
# Izvrsiti klasterovanje koriscenjem razlicitih veza pri odredjivanju
# bliskosti dva klastera i izdvojiti 3 klastera. Rezultat svakog 
# izvrsenog klasterovanja prikazati pomocu grafa. Rezultat svakog 
# izvrsenog klasterovanja prikazati pomocu grafika sa semom sa rasprsenim
# elementima. Svakom klasteru u rezultatu dodeliti jedinstvenu boju i 
# njegove instance oznaciti tom bojom. U naslovu grafika ispisati ime 
# koriscene veze i vrednost silueta koeficijenta. Uporediti dobijene modele.

import pandas as pd
from sklearn.metrics import silhouette_score
from sklearn import preprocessing
from sklearn.cluster import AgglomerativeClustering
import matplotlib.pyplot as plt
import subprocess

#funkcija za pravljenje slike sa prikazom hijerarhijskog klasterovanja pomocu grafa
def make_graph(children,  labels, image_name ):
   
    # Oznaka cvora koji je dobijen spajanjem dva klastera. Oznake tih cvorova su n, n+1, ...
    # gde je n broj instanci.
    instances = labels.count()

    # opis grafa u dot formatu
    with open('dt.dot', 'w') as f:
        f.write("""
        digraph G {

        node [shape=circle];
   
        """)

        # pravljenje cvorova sa oznakama instanci skupa
        for i in range(0, len(labels)):
            f.write(str(i) + '[label="'+ labels[i] + '" color=blue];\n')

        # pravljenje cvorova dobijenih spajanjem dva klastera
        for x in children:
            f.write(str(x[0].item()) + "->" + str(instances) + ";\n")
            f.write(str(x[1].item()) + "->" + str(instances) + ";\n")
            instances+=1

        f.write("}")
        f.close()

        # na osnovu opisa grafa u dot formatu pravi se slika u png formatu
        subprocess.call("dot -Tpng dt.dot -o " + image_name + ".png", shell=True)

# ucitavanje skupa
df = pd.read_csv("dogs.csv")
    
# prikaz imena kolona + 5 prvih instanci
print('Prvih 5 instanci', df.head(), sep='\n')
print('\n\n')
    
# izdvajanje broja instanci u skupu
num_instances = df.shape[0]

# Za klasterovanje ce se koristiti atributi visina i tezina psa,
# a rasa nece biti uzeta u obzir.
features = df.columns[1:3].tolist()
x_original = df[features]

# normalizacija atributa posto se koristi euklidsko rastojanje
x = pd.DataFrame(preprocessing.MinMaxScaler().fit_transform(x_original))
    
# dodela imena kolonama
x.columns = features

# Definisanje boja koje se koriste pri crtanju instanci klastera.
# Instance jednog klastera ce biti prikazane istom bojom.
colors = ['red', 'green', 'gold']

# pravljenje slike sa graficima
fig = plt.figure()

# oznaka celije na slici u kojoj se vrse naredna crtanja
plt_ind=1

# primena razlicitih veza pri odredjivanju bliskosti dva klastera
for link in ['complete', 'average', 'single']:

    # primena hijerarhijskog sakupljajuceg klasterovanja
    # i izdvajanje 3 klastera
    est = AgglomerativeClustering(n_clusters=3, linkage=link)
    est.fit(x)

    # prikaz rezultata klasterovanja pomocu grafa
    make_graph(est.children_,  df['breed'], 'clus_' + link )

    # Originalnom skupu se dodaje jos jedan atribut 'label', koji sadrzi
    # podatak kom klasteru pripada koja instanca.
    # Oznake klastera su u intervalu [0, n_clusters-1]
    df['label']= est.labels_

    # Podela slike na 2x2 celije i zadavanje
    # celije (plt_ind) u kojoj ce se izvrsiti naredna crtanja.
    fig.add_subplot(2, 2, plt_ind)

    # Svakom klasteru (oznake klastera su u intervalu [0, 2]) se dodeljuje jedinstvena
    # boja. Instance jednog klastera se crtaju pomocu seme sa rasprsenim elementima i
    # boje se bojom koja je dodeljena njihovom klasteru. Na x osi je visina psa iz originalnog
    # skupa, a na y osi tezina psa. Instance su predstavljene kao tacke.
    for j in range(0,3):

        # izdvajanje instanci klastera koji se obradjuje
        cluster= df.loc[lambda x: x['label'] == j, :]

        # crtanje instanci klastera pomocu seme sa rasprsenim elementima
        plt.scatter(cluster['height'], cluster['weight'], color=colors[j], s=30, marker='o', label="klaster %d"%j)

    # postavljanje legende i naslova (koji sadrzi primenjenu vezu pri klasterovanju i silueta koeficijent)
    # za svaku celiju
    plt.legend(loc='lower right')
    plt.title('Veza: %s, silueta koef: %.2f' % (link, silhouette_score(x, df['label'])))

    # Prelazak u narednu celiju u kojoj ce se prikazati
    # rezultat klasterovanja sa novim parametrima.
    plt_ind += 1

# prikaz slike bez poklapanja celija
plt.tight_layout()
plt.show()

# Koriscenjem 'complete' i 'average' veze pri klasterovanju dobijaju se isti klasteri.
# Klasterovanjem su psi podeljeni na grupe malog, srednjeg i velikog rasta.

# Primenom 'single' veze dobijeni su drugaciji klasteri. Psi malog i srednjeg rasta su
# u jednom klasteru, dok su psi velikog rasta podeljeni u dva klastera.