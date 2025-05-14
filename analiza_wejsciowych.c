#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>


static GtkWidget *age, *age_res;
static GtkWidget *weight, *weight_res;
static GtkWidget *height, *height_res;
static GtkWidget *man;
static GtkWidget *woman;
static GtkWidget *tryb;
static GtkWidget *tryb1;
static GtkWidget *tryb2;
static GtkWidget *tryb3;
static GtkWidget *lose_weight, *lose_weight_res;
static GtkWidget *window, *grid, *desc, *desc1, *button;

typedef struct {
    GtkWidget *age_res;
    GtkWidget *weight_res;
    GtkWidget *height_res;
    GtkWidget *lose_weight_res;
    int sex;
    float lifestyle;
} dane_struktury;

void funkcj(GtkWidget *widget, gpointer data);
void button_toggle(GtkWidget *widget, gpointer data);

int main(int argc, char **argv) {
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    age = gtk_label_new("Podaj swoj wiek");
    gtk_grid_attach(GTK_GRID(grid), age, 0, 0, 1, 1);
    age_res = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), age_res, 1, 0, 1, 1);    

    weight = gtk_label_new("Podaj swoja wage");
    gtk_grid_attach(GTK_GRID(grid), weight, 0, 1, 1, 1);
    weight_res = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), weight_res, 1, 1, 1, 1);

    height = gtk_label_new("Podaj swoj wzrost");
    gtk_grid_attach(GTK_GRID(grid), height, 0, 2, 1, 1);
    height_res = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), height_res, 1, 2, 1, 1);

    desc = gtk_label_new("Jaka jest twoja plec");
    gtk_grid_attach(GTK_GRID(grid), desc, 0, 3, 1, 1);
    man = gtk_check_button_new_with_label("Męzczyzna");
    gtk_grid_attach(GTK_GRID(grid), man, 1, 3, 1, 1);
    woman = gtk_check_button_new_with_label("Kobieta");
    gtk_grid_attach(GTK_GRID(grid), woman, 1, 4, 1, 1);

    desc1 = gtk_label_new("Tryb zycia");
    gtk_grid_attach(GTK_GRID(grid), desc1, 0, 5, 1, 1);
    tryb = gtk_check_button_new_with_label("Siedzacy");
    gtk_grid_attach(GTK_GRID(grid), tryb, 1, 5, 1, 1);
    tryb1 = gtk_check_button_new_with_label("Niska aktywnosc");
    gtk_grid_attach(GTK_GRID(grid), tryb1, 1, 6, 1, 1);
    tryb2 = gtk_check_button_new_with_label("Srednia aktywnosc");
    gtk_grid_attach(GTK_GRID(grid), tryb2, 1, 7, 1, 1);
    tryb3 = gtk_check_button_new_with_label("Wysoka aktywnosc");
    gtk_grid_attach(GTK_GRID(grid), tryb3, 1, 8, 1, 1);

    lose_weight = gtk_label_new("Ile chcesz stracić na wadze?");
    gtk_grid_attach(GTK_GRID(grid), lose_weight, 0, 9, 1, 1);
    lose_weight_res = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), lose_weight_res, 1, 9, 1, 1);

    

    dane_struktury *data = g_malloc(sizeof(dane_struktury));
    data->age_res = age_res;
    data->weight_res = weight_res;
    data->height_res = height_res;
    data->lose_weight_res = lose_weight_res;
    data->sex = 0;
    g_signal_connect(man, "toggled", G_CALLBACK(button_toggle), data);
    g_signal_connect(woman, "toggled", G_CALLBACK(button_toggle), data);
    g_signal_connect(tryb, "toggled", G_CALLBACK(button_toggle), data);
    g_signal_connect(tryb1, "toggled", G_CALLBACK(button_toggle), data);
    g_signal_connect(tryb2, "toggled", G_CALLBACK(button_toggle), data);
    g_signal_connect(tryb3, "toggled", G_CALLBACK(button_toggle), data);




    button = gtk_button_new_with_label("Wyślij dane");
    gtk_grid_attach(GTK_GRID(grid), button, 1, 10, 1, 1);
    g_signal_connect(button, "clicked", G_CALLBACK(funkcj), data);

    gtk_widget_show_all(window);
    gtk_main();
}

void button_toggle(GtkWidget *widget, gpointer data) {
    dane_struktury *data_p = (dane_struktury *) data;
    if (widget == man) {data_p->sex = 5;}

    if (widget == woman) {data_p->sex = -161;}

    if (widget == tryb) {data_p->lifestyle = 1.2;}

    if (widget == tryb1) {data_p->lifestyle = 1.45;}

    if (widget == tryb2) {data_p->lifestyle = 1.65;}

    if (widget == tryb3) {data_p->lifestyle = 1.86;}
}

void funkcj(GtkWidget *widget, gpointer data){
    dane_struktury *data_p = (dane_struktury *) data;
    int wiek = atoi(gtk_entry_get_text(GTK_ENTRY(data_p->age_res)));
    int waga = atoi(gtk_entry_get_text(GTK_ENTRY(data_p->weight_res))); 
    int lose  = atoi(gtk_entry_get_text(GTK_ENTRY(data_p->lose_weight_res)));
    int wzrost = atoi(gtk_entry_get_text(GTK_ENTRY(data_p->height_res)));
    int ppm, breakfast, lunch, dinner, snacks;
    ppm = (10*waga+6.25*wzrost-5*wiek+data_p->sex)*data_p->lifestyle;
    breakfast = ppm*0.25;
    lunch = ppm*0.4;
    dinner = ppm*0.25;
    snacks = ppm*0.1;

    printf("Zapotrzebowanie kaloryczne: %d \nSniadanie: %d \nObiad: %d \nKolacja: %d \nPrzekąski: %d\n", ppm, breakfast, lunch, dinner, snacks);
}