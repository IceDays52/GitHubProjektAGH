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
enum TrybZycia { UTRZYMANIE = 1, SPADEK = 2, WZROST = 3, ZDROWA = 4 };
void PPM(char gender, float weight, float height, int wiek, enum Aktywnosc aktywnosc, float* kaloryka, enum TrybZycia tryb, float* pp_kaloryka) {
    float wsp_aktywnosci[] = { 0.0f, 1.2f, 1.375f, 1.55f, 1.725f };
    float ppm_podstawowe = 0.0f;
    float ppm_z_aktywnoscia = 0.0f;
    float ppm_koncowe = 0.0f;

    if (gender == 'M') {
        ppm_podstawowe = (10 * weight) + (6.25 * height) - (5 * wiek) + 5;
    }
    else if (gender == 'K') {
        ppm_podstawowe = (10 * weight) + (6.25 * height) - (5 * wiek) - 161;
    }
    else {
        printf("Nieprawid�owa p�e�.\n");
        *kaloryka = -1;
        *pp_kaloryka = -1;
        return;
    }
    ppm_z_aktywnoscia = ppm_podstawowe * wsp_aktywnosci[aktywnosc];
    ppm_koncowe = ppm_z_aktywnoscia;

    if (tryb == SPADEK) {
        ppm_koncowe *= 0.8f;
    }
    else if (tryb == WZROST) {
        ppm_koncowe *= 1.15f;
    }
    else if (tryb == ZDROWA) {
        ppm_koncowe *= 0.9f;
    }

    printf("    Twoja kaloryczno�� bez wysi�ku: %.1f kcal\n", ppm_podstawowe);
    printf("    Twoja kaloryczno�� z uwzgl�dnieniem wysi�ku: %.1f kcal\n", ppm_z_aktywnoscia);
    printf("    Twoja kaloryczno�� po korekcie trybu �ycia: %.1f kcal\n", ppm_koncowe);

    *kaloryka = ppm_koncowe;
    *pp_kaloryka = ppm_podstawowe;
}

void pokazUtrateMasy(float ppm_utrzymanie, float ppm_dieta) {
    float deficyt = ppm_utrzymanie - ppm_dieta;
    if (deficyt <= 0) {
        printf("Twoja dieta nie powoduje utraty masy.\n");
        return;
    }
    float utrata_kg_na_dzien = deficyt / 7700.0f;
    float utrata_kg_na_tydzien = utrata_kg_na_dzien * 7;

    printf("Przewidywana utrata masy:\n");
    printf("  %.2f kg na tydzien\n", utrata_kg_na_tydzien);
    printf("  %.3f kg na dzien\n", utrata_kg_na_dzien);
}
void ocenPlanUtraty(float kg_do_zmiany, float dni, float dzienne_zapotrzebowanie, int* minimalne_dni, int tryb) {
    const float kcal_na_kg = 7700.0f;
    float dzienny_deficyt = (kg_do_zmiany * kcal_na_kg) / dni;

    printf("\n      Ocena planu %s masy     \n", (tryb == SPADEK) ? "utraty" : "przyrostu");
    printf("Chcesz %s %.2f kg w %.0f dni.\n", (tryb == SPADEK) ? "straci�" : "przyty�", kg_do_zmiany, dni);
    printf("To wymaga dziennej zmiany kalorii o: %.0f kcal.\n", dzienny_deficyt);

    if (tryb == SPADEK) {
        if (dzienny_deficyt > 1000) {
            printf("    Uwaga! Deficyt jest bardzo wysoki (>1000 kcal), co mo�e by� niezdrowe.\n");
            *minimalne_dni = (int)((kg_do_zmiany * kcal_na_kg) / 1000) + 1;
            printf("    Rozwa� wyd�u�enie czasu do co najmniej %d dni.\n", *minimalne_dni);
        }
        else if (dzienny_deficyt < 200) {
            printf("    Deficyt jest bardzo niski (<200 kcal), utrata masy b�dzie bardzo wolna.\n");
            *minimalne_dni = (int)dni;
        }
        else {
            printf("    Plan jest realistyczny i bezpieczny.\n");
            *minimalne_dni = (int)dni;
        }

        if (dzienny_deficyt > dzienne_zapotrzebowanie * 0.3f) {
            printf("Uwaga: deficyt przekracza 30%% Twojego dziennego zapotrzebowania kalorycznego.\n");
        }
    }
    else if (tryb == WZROST) {
        if (dzienny_deficyt > 1000) {
            printf("    Uwaga! Nadmiar kalorii jest bardzo wysoki (>1000 kcal), co mo�e by� niezdrowe.\n");
            *minimalne_dni = (int)((kg_do_zmiany * kcal_na_kg) / 1000) + 1;
            printf("    Rozwa� wyd�u�enie czasu do co najmniej %d dni.\n", *minimalne_dni);
        }
        else if (dzienny_deficyt < 200) {
            printf("    Nadmiar kalorii jest bardzo niski (<200 kcal), przyrost masy b�dzie bardzo wolny.\n");
            *minimalne_dni = (int)dni;
        }
        else {
            printf("Plan jest realistyczny i bezpieczny.\n");
            *minimalne_dni = (int)dni;
        }

        if (dzienny_deficyt > dzienne_zapotrzebowanie * 0.3f) {
            printf("    Uwaga: nadmiar kalorii przekracza 30%% Twojego dziennego zapotrzebowania kalorycznego.\n");
        }
    }
    else {
        *minimalne_dni = (int)dni;
    }
}
int main() {
    setlocale(LC_CTYPE, "Polish");
    char gender;
    int wiek,wybor, tryb;
    float weight, height, lossw = 0, okres = 0, dzienne_zapotrzebowanie = 0, finalne_zapotrzebowanie = 0;
    int minimalne_dni = 0;

    printf("Podaj p�e� (M/K): ");
    if (scanf(" %c", &gender) != 1) {
        printf("B��d: Niepoprawna p�e�. Spr�buj ponownie.\n");
        return 0;
    }

    printf("Podaj wiek: ");
    if (scanf("%d", &wiek) != 1) {
        printf("B��d: Niepoprawny wiek. Spr�buj ponownie.\n");
        return 0;
    }

    printf("Podaj wzrost (cm): ");
    if (scanf("%f", &height) != 1) {
        printf("B��d: Niepoprawny wzrost. Spr�buj ponownie.\n");
        return 0;
    }

    printf("Podaj wag� (kg): ");
    if (scanf("%f", &weight) != 1) {
        printf("B��d: Niepoprawna waga. Spr�buj ponownie.\n");
        return 0;
    }

    printf("\nJaka diete preferujesz i chcesz wybrac?:\n");
    printf("1 - Utrzymanie\n2 - Spadek\n3 - Wzrost\n4 - Zdrowa dieta\n");
    printf("Wyb�r: ");
    if (scanf("%d", &tryb) != 1 || tryb < 1 || tryb > 4) {
        printf("B��d: Niepoprawny tryb �ycia. Spr�buj ponownie.\n");
        return 0;
    }
    if (tryb == 2 || tryb == 3) {
        printf("Ile kg chcesz zmieni� (ujemne dla utraty, dodatnie dla przyrostu\n");
        if (scanf("%f", &lossw) != 1) {
            printf("B��d: Niepoprawna ilo�� kilogram�w. Spr�buj ponownie.\n");
            return 0;
        }

        printf("W jakim okresie chcesz straci�/przyty� z waga (dni): ");
        if (scanf("%f", &okres) != 1) {
            printf("B��d: Niepoprawny okres. Spr�buj ponownie.\n");
            return 0;
        }
    }
    printf("\nPodaj poziom aktywno�ci fizycznej:\n");
    printf("1 - Siedz�cy\n2 - Niski\n3 - �redni\n4 - Wysoki\n");
    printf("Wyb�r: ");
    if (scanf("%d", &wybor) != 1 || wybor < 1 || wybor > 4) {
        printf("B��d: Niepoprawny poziom aktywno�ci. Spr�buj ponownie.\n");
        return 0;
    }
    PPM(gender, weight, height, wiek, (enum Aktywnosc)wybor, &dzienne_zapotrzebowanie, UTRZYMANIE, &finalne_zapotrzebowanie);
    if (tryb == 2 || tryb == 3) {
        ocenPlanUtraty(lossw, okres, dzienne_zapotrzebowanie, &minimalne_dni, tryb);
        if (minimalne_dni > (int)okres) {
            printf("Zmienia si� czas %s masy z %.0f na %d dni (zdrowszy plan).\n", (lossw < 0) ? "odchudzania" : "przybierania",okres, minimalne_dni);
     
            okres = (float)minimalne_dni;
        }
    }
    PPM(gender, weight, height, wiek, (enum Aktywnosc)wybor, &finalne_zapotrzebowanie, (enum TrybZycia)tryb, &dzienne_zapotrzebowanie);
    if (tryb == 2) {
        pokazUtrateMasy(dzienne_zapotrzebowanie, finalne_zapotrzebowanie);
    }

    generujJadlospis(okres);
    return 0;
}