#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>


static GtkWidget *window1;
static GtkWidget *window2;
static GtkWidget *window3;
static GtkWidget *age;
static GtkWidget *weight;
static GtkWidget *height;
static GtkWidget *man;
static GtkWidget *woman;
static GtkWidget *tryb;
static GtkWidget *tryb1;
static GtkWidget *tryb2;
static GtkWidget *tryb3;
static GtkWidget *window, *grid, *desc, *desc1, *button;
void funkcj(void);
int main(int argc, char **argv) {
    
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    age = gtk_label_new("Podaj swoj wiek");
    gtk_grid_attach(GTK_GRID(grid), age, 0, 0, 1, 1);

    window1 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), window1, 1, 0, 1, 1);    

    weight = gtk_label_new("Podaj swoja wage");
    gtk_grid_attach(GTK_GRID(grid), weight, 0, 1, 1, 1);

    window2 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), window2, 1, 1, 1, 1);

    height = gtk_label_new("Podaj swoj wzrost");
    gtk_grid_attach(GTK_GRID(grid), height, 0, 2, 1, 1);

    window3 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), window3, 1, 2, 1, 1);

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

    button = gtk_button_new_with_label("Wyślij dane");
    gtk_grid_attach(GTK_GRID(grid), button, 1, 9, 1, 1);
    g_signal_connect(button, "clicked", G_CALLBACK(funkcj), NULL);

    gtk_widget_show_all(window);
    gtk_main();
}

void funkcj(){
    printf("test wywolania funkcji");
}