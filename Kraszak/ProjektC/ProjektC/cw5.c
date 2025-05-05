#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zadanie5(void) {
	int liczba, strzal, proby = 0;
	srand(time(NULL));
	liczba = rand() % 100 + 1;
	printf("Zgadywanka: liczbe od 1 do 100\n");

    printf("Podaj liczbe: ");
    scanf("%d", &strzal);

    while (strzal != liczba) {
        proby++;
        if (strzal > liczba) {
            printf("Za duza\n");
        }
        else {
            printf("Za malo\n");
        }
        printf("Podaj liczbe: ");
        scanf("%d", &strzal);
    }

    proby++; 
    printf("Zgadles Liczba prob: %d\n", proby);
}
unsigned int zadania6(unsigned int a) {
    while (a >= 10) {
        unsigned int suma = 0;
        while (a > 0) {
            suma += a % 10;
            a /= 10;
        }
        a = suma;
    }
    return a;
}
void numbersbin111(void) {
    unsigned char liczba = 1;
    printf("Liczby binarne\n");
    while (liczba != 0) {
        int bits[7]; 
        int count = 0; 
        for (int i = 7; i >= 0; i--) {
            if ((liczba >> i) & 1) {
                bits[count++] = 1; 
            }
        }
        for (int i = 0; i < count; i++) {
            printf("%d", bits[i]);
        }
        printf("\n");
        liczba = (liczba << 1) | 1;
        if (liczba == 255) {
            break;
        }
    }
}
void bubble_sort(int arr[], int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void generowanie(void) {
    srand(time(NULL)); 
    int arr[20];
    printf("Tablica przed:\n");
    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 61 - 30; 
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubble_sort(arr, 20);
    printf("Tablica po:\n");
    for (int i = 0; i < 20; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int nwd(int a, int b) {
    if (b == 0) {
        return a;  
    }
    else {
        return nwd(b, a % b);  
    }
}
void testnwd(void) {
    srand(time(NULL));
    int a;
    int n;
    a = rand() % 101 - 50;
    printf("Podaj liczbe pêtli ile par liczb bêdzie sprawdzane");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int b = rand() % 101 - 50;
        printf("NWD(%d, %d) = %d\n", a, b, nwd(a, b));
    }
}
int main() {
    testnwd();
    /*generowanie();
    int a, b;
    printf("Podaj pierwsza liczbe: ");
    scanf("%d", &a);
    printf("Podaj druga liczbe: ");
    scanf("%d", &b);
    printf("Najwiekszy wspolny dzielnik liczb %d i %d to: %d\n", a, b, nwd(a, b)); */
   /* unsigned int liczba;
    printf("Podaj liczbe: ");
    scanf("%u", &liczba);

    unsigned int wynik = zadania6(liczba);
    printf("Suma cyfr liczby %u do jednej cyfry: %u\n", liczba, wynik); */

    return 0;
}