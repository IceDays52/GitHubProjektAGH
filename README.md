Kalkulator diety i jadłospis
Opis
To prosty program w C, który pomaga obliczyć Twoje dzienne zapotrzebowanie kaloryczne w zależności od płci, wieku, wzrostu, wagi i poziomu aktywności. Dodatkowo pozwala określić cel (utrzymanie wagi, redukcja, masa, zdrowa dieta), a na koniec generuje przykładowy jadłospis na wybraną liczbę dni.

Program pokazuje też, czy Twój plan odchudzania lub przybierania jest realny i zdrowy – np. ostrzega, gdy deficyt kalorii jest zbyt duży.

Przykład działania
Poniżej przykładowy dialog z programem (input od użytkownika i odpowiedzi programu):

less
Kopiuj
Edytuj
Podaj płeć (M/K): M  
Podaj wiek: 28  
Podaj wzrost (cm): 180  
Podaj wagę (kg): 75  

Jaka diete preferujesz i chcesz wybrac?:  
1 - Utrzymanie  
2 - Spadek  
3 - Wzrost  
4 - Zdrowa dieta  
Wybór: 2  
Ile kg chcesz zmienić (ujemne dla utraty, dodatnie dla przyrostu  
-5  
W jakim okresie chcesz stracić/przytyć z waga (dni): 30  

Podaj poziom aktywności fizycznej:  
1 - Siedzący  
2 - Niski  
3 - Średni  
4 - Wysoki  
Wybór: 3  

    Twoja kaloryczność bez wysiłku: 1745.0 kcal  
    Twoja kaloryczność z uwzględnieniem wysiłku: 2704.8 kcal  
    Twoja kaloryczność po korekcie trybu życia: 2163.8 kcal  

      Ocena planu utraty masy  
Chcesz stracić 5.00 kg w 30 dni.  
To wymaga dziennej zmiany kalorii o: 1283 kcal.  
    Uwaga! Deficyt jest bardzo wysoki (>1000 kcal), co może być niezdrowe.  
    Rozważ wydłużenie czasu do co najmniej 39 dni.  
Zmienia się czas odchudzania z 30 na 39 dni (zdrowszy plan).  

    Twoja kaloryczność bez wysiłku: 1745.0 kcal  
    Twoja kaloryczność z uwzględnieniem wysiłku: 2704.8 kcal  
    Twoja kaloryczność po korekcie trybu życia: 2163.8 kcal  
Przewidywana utrata masy:  
  0.49 kg na tydzien  
  0.070 kg na dzien  

Zalecany jadłospis na 39 dni:

Dzień 1:  
  Śniadanie: Jajecznica z warzywami (kcal: 300, białko: 20.0g, tłuszcz: 22.0g, węgle: 5.0g)  
  Obiad: Pizza pepperoni (kcal: 950, białko: 35.0g, tłuszcz: 50.0g, węgle: 105.0g)  
  Kolacja: Sałatka z tuńczykiem (kcal: 320, białko: 25.0g, tłuszcz: 15.0g, węgle: 10.0g)  
  Całkowita kaloryczność na dzień 1: 1570 kcal

...
(Program losuje inne posiłki dla każdego dnia – jadłospis się zmienia).

Uwagi
Program ostrzega, jeśli deficyt/nadmiar kalorii jest zbyt duży.

Wszystkie posiłki mają podaną kaloryczność oraz wartości odżywcze (białko, tłuszcz, węglowodany).

Jadłospisy są tworzone z gotowej listy 24 posiłków (śniadania, obiady, kolacje).

Całość działa z poziomu terminala – nie wymaga dodatkowych plików ani bibliotek poza standardowymi.
