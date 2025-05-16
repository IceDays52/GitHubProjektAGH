#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
struct Posilek {
    char nazwa_posilku[100];
    int kcal;
    float bialko;
    float tluszcz;
    float wegle;
};

struct Posilek sniadania[] = {
    {"Owsianka z owocami", 350, 10.5f, 8.2f, 55.0f},
    {"Jajecznica z warzywami", 300, 20.0f, 22.0f, 5.0f},
    {"Jogurt naturalny z musli", 320, 15.0f, 10.0f, 40.0f}
};

struct Posilek obiady[] = {
    {"Pier� z kurczaka z ry�em i warzywami", 500, 35.0f, 15.0f, 50.0f},
    {"�oso� z kasz� i broku�ami", 550, 40.0f, 25.0f, 35.0f},
    {"Gulasz warzywny z ciecierzyc�", 480, 20.0f, 18.0f, 55.0f}
};

struct Posilek kolacje[] = {
    {"Kanapki z jajkiem i warzywami", 300, 15.0f, 12.0f, 30.0f},
    {"Sa�atka z tu�czykiem", 320, 25.0f, 15.0f, 10.0f},
    {"Zupa krem z dyni z grzankami", 280, 10.0f, 10.0f, 35.0f}
};

void generujJadlospis(int czas) {
    srand(time(NULL));  

    printf("\nZalecany jad�ospis na %d dni:\n", czas);

    for (int i = 1; i <= czas; i++) {
        printf("\nDzie� %d:\n", i);

       
        int i_sniadanie = rand() % (sizeof(sniadania) / sizeof(sniadania[0]));
        int i_obiad = rand() % (sizeof(obiady) / sizeof(obiady[0]));
        int i_kolacja = rand() % (sizeof(kolacje) / sizeof(kolacje[0]));

       
        struct Posilek sn = sniadania[i_sniadanie];
        struct Posilek ob = obiady[i_obiad];
        struct Posilek ko = kolacje[i_kolacja];

        
        printf("  �niadanie: %s (kcal: %d, bia�ko: %.1fg, t�uszcz: %.1fg, w�gle: %.1fg)\n",
            sn.nazwa_posilku, sn.kcal, sn.bialko, sn.tluszcz, sn.wegle);

        printf("  Obiad: %s (kcal: %d, bia�ko: %.1fg, t�uszcz: %.1fg, w�gle: %.1fg)\n",
            ob.nazwa_posilku, ob.kcal, ob.bialko, ob.tluszcz, ob.wegle);

        printf("  Kolacja: %s (kcal: %d, bia�ko: %.1fg, t�uszcz: %.1fg, w�gle: %.1fg)\n",
            ko.nazwa_posilku, ko.kcal, ko.bialko, ko.tluszcz, ko.wegle);
    }
}
enum Aktywnosc { SIEDZACY = 1, NISKI = 2, SREDNI = 3, WYSOKI = 4 };
void PPM(char gender,float weight, float height, int wiek, enum Aktywnosc aktywnosc, float* kaloryka) {
    float kaloryka;
    float wsp_aktywnosci[] = { 0.0f, 1.2f, 1.375f, 1.55f, 1.725f };
    if (gender == 'M') {
        *kaloryka = (10 * weight) + (6.25 * height) - (5 * wiek) + 5;
    }
    if (gender = 'K') {
        *kaloryka = (10 * weight) + (6.25 * height) - (5 * wiek) - 161;
    }
    printf("    Twoja Kaloryka bez wysi�ku: %.1f kcal\n",*kaloryka);
    *kaloryka *= wsp_aktywnosci[aktywnosc];
    printf("    Twoja Kaloryka z wysi�ku: %.1f kcal\n", *kaloryka);

}


int main() {
    setlocale(LC_CTYPE, "Polish");
    char gender;
    int wiek, czas, wybor;
    float weight, height, lossw, okres, dzienne_zapotrzebowanie;


    printf("Podaj p�e� (M/K): ");
    if (scanf(" %c", &gender) != 1) {
        printf("B��d podczas wczytywania p�ci.\n");
        return 1;
    }

    printf("Podaj wiek: ");
    if (scanf("%d", &wiek) != 1) {
        printf("B��d podczas wczytywania wieku.\n");
        return 1;
    }

    printf("Podaj wzrost (cm): ");
    if (scanf("%f", &height) != 1) {
        printf("B��d podczas wczytywania wzrostu.\n");
        return 1;
    }

    printf("Podaj wag� (kg): ");
    if (scanf("%f", &weight) != 1) {
        printf("B��d podczas wczytywania wagi.\n");
        return 1;
    }
    printf("Ile chcesz straci� kg (kg): ");
    if (scanf("%f", &lossw) != 1) {
        printf("B��d podczas wczytywania wagi.\n");
        return 1;
    }
    printf("W jakim okresie chcesz straci� wag� (dni): ");
    if (scanf("%f", &okres) != 1) {
        printf("B��d podczas wczytywania wagi.\n");
        return 1;
    }
    printf("Na jaki okres chcesz diete (dni): ");
    if (scanf("%d", &czas) != 1) {
        printf("Dobrze podamy ci diete.\n");
        return 1;
    }
    printf("\nPodaj poziom aktywno�ci fizycznej:\n");
    printf("1 - Siedz�cy\n2 - Niski\n3 - �redni\n4 - Wysoki\n");
    printf("Wyb�r: ");
    if (scanf("%d", &wybor) != 1 || wybor < 1 || wybor > 4) {
        printf("B��d: nieprawid�owy poziom aktywno�ci.\n");
        return 1;
    }
    printf("\nDane u�ytkownika:\n");
    printf("P�e�: %c\n", gender);
    printf("Wiek: %d lat\n", wiek);
    printf("Wzrost: %.1f cm\n", height);
    printf("Waga: %.1f kg\n", weight);
    PPM(gender, weight, height, wiek, (enum Aktywnosc) wybor, &dzienne_zapotrzebowanie);
    generujJadlospis(czas);

    return 0;
}
