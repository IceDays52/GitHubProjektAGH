# Kalkulator diety i jadłospis

## Opis

Program w języku C, który pomaga obliczyć Twoje dzienne zapotrzebowanie kaloryczne na podstawie:

- płci, wieku, wzrostu i wagi
- poziomu aktywności fizycznej
- celu (utrzymanie, redukcja, masa, zdrowa dieta)

Dodatkowo ocenia, czy wybrany plan zmian wagi jest zdrowy – np. ostrzega, jeśli deficyt kaloryczny jest zbyt duży – oraz generuje przykładowy jadłospis na wybraną liczbę dni.

Program działa w terminalu i nie wymaga żadnych zewnętrznych bibliotek.

---

## Przykład działania

```text
Podaj płeć (M/K): M  
Podaj wiek: 28  
Podaj wzrost (cm): 180  
Podaj wagę (kg): 75  

Jaka dietę preferujesz i chcesz wybrać?:  
1 - Utrzymanie  
2 - Spadek  
3 - Wzrost  
4 - Zdrowa dieta  
Wybór: 2  
Ile kg chcesz zmienić (ujemne dla utraty, dodatnie dla przyrostu):  
-5  
W jakim okresie chcesz stracić/przytyć wagę (dni): 30  

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
  0.49 kg na tydzień  
  0.070 kg na dzień  

Zalecany jadłospis na 39 dni:

Dzień 1:  
  Śniadanie: Jajecznica z warzywami (kcal: 300, białko: 20.0g, tłuszcz: 22.0g, węgle: 5.0g)  
  Obiad: Pizza pepperoni (kcal: 950, białko: 35.0g, tłuszcz: 50.0g, węgle: 105.0g)  
  Kolacja: Sałatka z tuńczykiem (kcal: 320, białko: 25.0g, tłuszcz: 15.0g, węgle: 10.0g)  
  Całkowita kaloryczność na dzień 1: 1570 kcal

......
```
## Wymagania
Kompilator C
#### Autorzy
Arkadiusz Ciuła, 
Mateusz Turakiewicz
