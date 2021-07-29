#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

static GtkWidget *number1;
static GtkWidget *number2;
static GtkWidget *result;
static GtkWidget *radio1;
static GtkWidget *radio2;

void do_calculate(GtkWidget *calculate, gpointer data) {
    int num1 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number1)));
    int num2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number2)));

    char buffer[32];

    // TODO: operation for the result
    // addition button selected?
    int enable = 0;
    if (enable = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio1))) {
        snprintf(buffer, sizeof(buffer), "result: %d", num1 + num2);
    }
    else if (enable = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio2))) {
        snprintf(buffer, sizeof(buffer), "result: %d", num1 - num2);
    }
    else {
        snprintf(buffer, sizeof(buffer), "result: %d", 0);
    }

    gtk_label_set_text(GTK_LABEL(result), buffer);
}

// gcc 007_gtk.c -o 007_gtk `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
int main(int argc, char **argv) {
    GtkWidget *window, *grid, *calculate;
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    number1 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), number1, 0, 0, 1, 1);

    number2 = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), number2, 1, 0, 1, 1);

    calculate = gtk_button_new_with_label("calculate");
    g_signal_connect(calculate, "clicked", G_CALLBACK(do_calculate), NULL);
    gtk_grid_attach(GTK_GRID(grid), calculate, 2, 0, 1, 1);

    result = gtk_label_new("result:");
    gtk_grid_attach(GTK_GRID(grid), result, 3, 0, 1, 1);

    // create radio buttons
    radio1 = gtk_radio_button_new_with_label_from_widget (
        NULL,
        "Addition");
    gtk_grid_attach(GTK_GRID(grid), radio1, 0, 1, 1, 1);

    radio2 = gtk_radio_button_new_with_label_from_widget (
        GTK_RADIO_BUTTON (radio1),
        "Subtract");
    gtk_grid_attach(GTK_GRID(grid), radio2, 0, 2, 1, 1);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
