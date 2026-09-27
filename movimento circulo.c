#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main(){

    al_init();
    al_init_primitives_addon();

    ALLEGRO_DISPLAY *janela = al_create_display(800, 600);

    float x = 50;
    float y = 300;
    float velocidade = 3;

    while (1){

        x = x + velocidade;

        if (x >= 750){
            velocidade = -3;
        }

        if (x <= 50){
            velocidade = 3;
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));

        al_draw_filled_circle(
            x,
            y,
            30,
            al_map_rgb(255, 0, 0)
        );

        al_flip_display();

        al_rest(0.01);
    }

    return 0;
}
