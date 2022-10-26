Zawartość

Katalog zawiera 3 programy, 2 biblioteki z funkcjmi
oraz pliki Readme i Makefile.

1. Program p7.c tworzy semafory i pamięć dzieloną.
Następnie uruchamia programy producenta i konsumenta.
Na koniec usuwa utworzone semafory i pamięć dzieloną.

2. Producent otwiera pamięć dzieloną i ją mapuje.
Otwiera on też semafory. Następnie w swojej sekcji
krytycznej zapisuje zawartość pliku in.txt do wspólnego 
bufora.

3. Konsument otwiera pamięć dzieloną i ją mapuje. 
Otwiera on też semafory. Następnie w swojej sekcji 
krytycznej zapisuje zawartość wspólnego bufora do 
pliku out.txt.

4. Biblioteka biblioteka.c zawiera fukcje do otwierania, tworzenia,
podnoszenia, opuszczania, uzyskiwania wartości, zamykania i niszczenia 
semafora.

5. Biblioteka biblioteka2.c zawiera funkcje do tworzenia, otwierania,
zamykania, mapowania, odmapowania, usuwania pamięci dzielonej.

Uruchamianie

Aby uruchomić program z biblioteką statyczną należy wpisać "make run1".

Aby uruchomić program z biblioteką dzieloną na 1. sposób należy wpisać "make run2".

Aby uruchomić program z biblioteką dzieloną na 2. sposób należy wpisać "make run3".

Porównywanie

komenda "make compare"

Czyszczenie

komenda "make clean"

