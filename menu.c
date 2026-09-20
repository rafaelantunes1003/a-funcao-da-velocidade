#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

int main() {

    al_init();
    al_init_primitives_addon();
    al_init_image_addon();

    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);

    // função para criar uma janela
    ALLEGRO_DISPLAY *display = al_create_display(640, 360);
    if (!display){
        return -1;
    }

    // largura e altura da tela
    int largura_tela = al_get_display_width(display);
    int altura_tela = al_get_display_height(display);

    // eventos 
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    if (!queue){
        al_destroy_display(display); 
        return -1;
    }

    ALLEGRO_BITMAP *imagem = al_load_bitmap("capa.png");
    if (!imagem) {
        al_destroy_event_queue(queue);
        al_destroy_display(display);
        return -1; 
    }

    al_register_event_source(queue, al_get_display_event_source(display));

    int rodando = 1;

    // while para deixar a janela aberta
    while (rodando){
        ALLEGRO_EVENT event;

        while (al_get_next_event(queue, &event)) {
            if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
                rodando = 0;
            }
        }

        al_clear_to_color(al_map_rgb(0, 0, 100));

        // faz a imagem de acordo com o tamanho da tela
        al_draw_scaled_bitmap(
            imagem,
            0, 0, al_get_bitmap_width(imagem), al_get_bitmap_height(imagem),
            0, 0, largura_tela, altura_tela,                                   
        );

        al_flip_display();
    }

    al_destroy_bitmap(imagem);
    al_destroy_event_queue(queue);
    al_destroy_display(display);

    return 0;
}