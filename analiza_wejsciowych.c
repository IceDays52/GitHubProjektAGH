#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

// Callback wywoływany po kliknięciu przycisku
void on_button_clicked(GtkWidget *widget, gpointer data) {
    GtkEntry *entry = GTK_ENTRY(data);
    const gchar *text = gtk_entry_get_text(entry);
    g_print("Wprowadzono: %s\n", text);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);


}