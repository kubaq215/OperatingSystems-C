Zawartość

Katalog zawiera 2 programy, bibliotekę z funkcjmi
oraz pliki Readme i Makefile.

1. Program p6.c tworzy semafor i wypisuje jego nazwę, 
wartość i adres. Potem tworzy plik numer.txt i wpisuje 
do niego liczbę 0. Następnie uruchamia w swoim procesie 
potomnym program procesy.c. Na koniec usuwa utworzony semafor.

2. Program procesy.c odpowiada za operacje w sekcji prywatnej
i krytycznej procesu. W sekcji krytycznej wartość z pliku "numer.txt"
jest zwiększana o 1.

3. Biblioteka biblioteka.c zawiera fukcje do otwierania, tworzenia,
podnoszenia, opuszczania, uzyskiwania wartości, zamykania i niszczenia 
semafora.

Uruchamianie

Za kompilację i uruchamianie programu odpowiedzialny jest plik Makefile.
Aby to zrobić należy wpisać komendę "make run".

Czyszczenie

Aby uporządkować katalog po skończonej pracy można użyć
komendy "make clean", która usunie nam wszystkie zbędne pliki.