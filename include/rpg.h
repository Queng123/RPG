/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** rpg
*/

#ifndef RPG_H_
    #define RPG_H_
    #define ERROR 84
    #define SUCCESS 0

/******************************include*****************************************/

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Network.h>
//!lib
    #include "my.h"
//!others
    #include <stdlib.h>
//!project
    #include "game.h"
    #include "menu.h"
    #include "new_game.h"
    #include "load_game.h"

/******************************structurs***************************************/

/******************************fonctions***************************************/

//!useful fonctions
int my_rpg(void);
void free_all(game_t *game);
int initialize_var(game_t *game);
void analyse_event(sfEvent event, game_t *game);
void start_new_game(game_t *game);
void display_button(button_t *button, sfRenderWindow *window);
int text_is_clicked(button_t *button, sfVector2f click_position);
int button_is_clicked(button_t *button, sfVector2f click_position);
void display_inventory_item(game_t *game);
void display_current_item_hud(game_t *game);
void display_waiting(game_t *game);
void display_mini_map(game_t *game);
void update_sound_parameters(game_t *game);
void update_sound_status(game_t *game);
void set_map(map_t *map, chest_t *chest[30]);
void display_boss(game_t *game);
void display_game_bar(game_t *game);
void analyse_how_to_play_event(sfMouseButtonEvent event, game_t *game);
int init_howtwoplay(game_t *game_s);
void free_sound(game_t *game);
void free_music(game_t *game);
int error_handling(void);
void play_song(game_t *game);
void init_tablet(tablet_t *tablet);

#endif/* !RPG_H_ */
