#include <stdio.h>


float obliczTDEE(char plec, int wiek, float wzrost, float waga, int tryb_zycia) {
    float bmr;
    if (plec == 'M' || plec == 'm')
        bmr = 10 * waga + 6.25 * wzrost - 5 * wiek + 5;
    else
        bmr = 10 * waga + 6.25 * wzrost - 5 * wiek - 161;

    float mnoznik[] = { 1.2, 1.375, 1.55, 1.725 };
    return bmr * mnoznik[tryb_zycia];
}