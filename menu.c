#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

int main() {
    al_init();
    al_init_primitives_addon();
    al_init_font_addon();
    al_install_keyboard();

    ALLEGRO_DISPLAY *display = al_create_display(640, 360);
    if (!display) return -1;

    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    if (!queue) {
        al_destroy_display(display);
        return -1;
    }

    ALLEGRO_FONT *fonte = al_create_builtin_font();

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());

    char texto[60] = "";
    int tamanho = 0;
    int rodando = 1;

    while (rodando) {
        ALLEGRO_EVENT event;

        while (al_get_next_event(queue, &event)) {
            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                rodando = 0;
            }

            if (event.type == ALLEGRO_EVENT_KEY_CHAR && tamanho < 58) {
                if (event.keyboard.unichar >= 32 && event.keyboard.unichar <= 126) {
                    texto[tamanho] = (char)event.keyboard.unichar;
                    tamanho++;
                    texto[tamanho] = '\0';
                }
            }
        }

        al_clear_to_color(al_map_rgb(30, 30, 30));
        al_draw_filled_rectangle(50, 150, 590, 210, al_map_rgb(255, 255, 255));
        al_draw_text(fonte, al_map_rgb(0, 0, 0), 320, 175, ALLEGRO_ALIGN_CENTRE, texto);

        al_flip_display();
    }

    al_destroy_font(fonte);
    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}