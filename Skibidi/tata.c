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
struct Posilek obiady[] = {
	{"Pierœ z kurczaka z ry¿em i warzywami", 500, 35.0, 15.0, 50.0},
	{"£osoœ z kasz¹ i broku³ami", 550, 40.0, 25.0, 35.0},
	{"Gulasz warzywny z ciecierzyc¹", 480, 20.0, 18.0, 55.0}
};

struct Posilek kolacje[] = {
	{"Kanapki z jajkiem i warzywami", 300, 15.0, 12.0, 30.0},
	{"Sa³atka z tuñczykiem", 320, 25.0, 15.0, 10.0},
	{"Zupa krem z dyni z grzankami", 280, 10.0, 10.0, 35.0}
};