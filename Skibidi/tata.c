#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <bmi.h>

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
    {"Pierœ z kurczaka z ry¿em i warzywami", 500, 35.0f, 15.0f, 50.0f},
    {"£osoœ z kasz¹ i broku³ami", 550, 40.0f, 25.0f, 35.0f},
    {"Gulasz warzywny z ciecierzyc¹", 480, 20.0f, 18.0f, 55.0f}
};

struct Posilek kolacje[] = {
    {"Kanapki z jajkiem i warzywami", 300, 15.0f, 12.0f, 30.0f},
    {"Sa³atka z tuñczykiem", 320, 25.0f, 15.0f, 10.0f},
    {"Zupa krem z dyni z grzankami", 280, 10.0f, 10.0f, 35.0f}
};

enum Aktywnosc { SIEDZACY = 1, NISKI, SREDNI, WYSOKI };

int main() {
    char gender;
    int wiek;
    float weight, height;

    printf("Podaj p³eæ (M/K): ");
    if (scanf(" %c", &gender) != 1) {
        printf("B³¹d podczas wczytywania p³ci.\n");
        return 1;
    }

    printf("Podaj wiek: ");
    if (scanf("%d", &wiek) != 1) {
        printf("B³¹d podczas wczytywania wieku.\n");
        return 1;
    }

    printf("Podaj wzrost (cm): ");
    if (scanf("%f", &height) != 1) {
        printf("B³¹d podczas wczytywania wzrostu.\n");
        return 1;
    }

    printf("Podaj wagê (kg): ");
    if (scanf("%f", &weight) != 1) {
        printf("B³¹d podczas wczytywania wagi.\n");
        return 1;
    }

    printf("\nDane u¿ytkownika:\n");
    printf("P³eæ: %c\n", gender);
    printf("Wiek: %d lat\n", wiek);
    printf("Wzrost: %.1f cm\n", height);
    printf("Waga: %.1f kg\n", weight);

    return 0;
}
