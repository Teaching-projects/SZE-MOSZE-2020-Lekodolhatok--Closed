# SZE-MOSZE-2020-Lekodolhatok

Ebben a konzolos játékban két játékos küzd meg egymással. Egy-egy menet során a felek felváltva támadnak, az győz, aki az adott menet végén életben marad. A játékosok tulajdonságait az indításkor megadott .json fájlból olvassa ki a program. 

Játék inditása:
`./a.out <Karakter1 json> <Karakter2 json>`

<b>1. Feladat</b>

Először az alapjátékot kellett elkészíteni.

<b>2. Feladat</b>

Elkészültek a Json-ok, melyek tartalmazzák a karakterek legfontosabb tulajdonságait (nevüket, életerejüket, támadóerejüket).

<b>3. Feladat</b>
<ul>
  <li>AttackSpeed</li>
  
  Van egy timer, ami ha osztható valamelyik karakter attackSpeed értékével, akkor az adott karakter támad először.
  
  <li>LevelUp</li>
  
  Ebben a feladatban egy olyan függvényt kellett létrehozni, mely lehetőséget biztosít a karaktereknek, hogy bizonyos tapasztalatpontok összegyűjtése során a játékban legyen lehetőségük szintet lépni, amivel különböző extrákhoz juthattak (nőtt a támadóerejük és az életerejük is).
  
  <li>JsonParser</li>
  
  Egy általános JasonParsert kellett készíteni, mely 3 különböző formában kaphat JSON bemenetet (fájlnévből, istream-ből és stringből).
  
</ul>

<b>4. Feladat</b>
<ul>
  <li>Documentation</li>
  
  Ki kellett egészíteni a dokumentációt a hiányzó kommentekkel.
  
  <li>Makefile</li>
  
  Egy olyan Makefilet kellet készíteni, mely a kisebb scripteket összefogja és egységesíti a GHA kódokat.
  
  <li>UnitTest</li>
  
  Az összes metódust tesztelni kellett, hogy a helyes értékeket ad-e vissza.
  
  <li>Refactor</li>
  
  A feladat az volt, hogy egy kapott main.cpp fájl alapján írjuk át a kódunkat. Módosítani kellet hozzá a Json osztályt, a Character osztályt és létre kellet hozzá hozni egy új, Hero nevű osztályt is, amely a módosított Character osztály (új néven Monster) leszármazottja. Több függvénnyel is ki kellett egészíteni a kódunkat, ezekkel sajnos nem végeztünk határidőre. Miután Closed titulust kapott a projektünk, azt hittük, hogy muszáj vizsgára mennünk és emiatt későn kezdtük el befejezni a kódot. Az összes módosítás után azonban a tesztek nem futottak le, mert a jsonparser nem tud tömböket kezelni. Ennek átírására már szintén nem maradt idő, ezért inkább a branchet nem merge-ltük, hogy olyan kódot adhassunk le a végén, ami működik.
</ul>



Github-pages link: https://teaching-projects.github.io/SZE-MOSZE-2020-Lekodolhatok--Closed/index.html
