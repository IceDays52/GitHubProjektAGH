#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>


static GtkWidget *window1;
static GtkWidget *window2;
static GtkWidget *window3;
static GtkWidget *age;
static GtkWidget *weight;
static GtkWidget *height;

int main(int argc, char **argv) {
    GtkWidget *window, *grid;
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

    gtk_widget_show_all(window);
    gtk_main();
}