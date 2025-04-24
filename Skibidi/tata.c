#include <stdio.h>
#include <string.h>

struct Posilek {
	char nazwa_posilku[100];
	int kcal;
	float bialko;
	float tluszcz;
	float wegle;
};
struct Posilek sniadania[] = {
	{"Owsianka z owocami", 350, 10.5, 8.2, 55.0},
	{"Jajecznica z warzywami", 300, 20.0, 22.0, 5.0},
	{"Jogurt naturalny z musli", 320, 15.0, 10.0, 40.0}
};

