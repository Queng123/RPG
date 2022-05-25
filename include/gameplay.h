/*
** EPITECH PROJECT, 2021
** B-MUL-100-NAN-1-1-myhunter-timothee.lesellier
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include "struct.h"
    #include <stdio.h>
    #include <SFML/Graphics.h>
    #include <unistd.h>
    #include <SFML/System.h>
    #include <stdlib.h>
    #include <SFML/Window.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include "game.h"

    void my_putchar(char c);

    void my_put_nbr(int nb);

    void my_putstr(char const *str);

    int my_strlen(char const *str);

    int my_getnbr(char const *str);

    void analyse_event_gameplay(game_t *game_s);

    void display_obj(game_t *game_s);

    void move_obj(obj_t *obj);

    void handle_friction(obj_t *obj, float time);

    void check_collision(game_t *game_s, obj_t *obj, int pos_obj);

    void change_state(game_t *game_s);

    int get_hitbox_size(obj_t *obj, axe_t idx);

    void activate_tower(game_t *game_s, type_t type);

    void destroy_all(game_t *game_s);

    void destroy_sprite(game_t *game_s);

    void check_event_close_window(game_t *game_s);

    void check_event_mouse(game_t *game_s);

    void manage_clock_obj(game_t *game);

    char *my_revstr(char *str);

    void destroy_tab_entitie(obj_t *obj[NB_ENT]);

    void play_game(game_t *game_s);

    void create_clock(game_t *game_s);

    void check_menu_main_background(game_t *game_s);

    void check_menu_actif_and_fps_menu_egal_zero(game_t *game_s);

    void check_manage_clock(game_t *game_s);

    void display_sprite(game_t *game_s, sfSprite *sprite);

    void display_end_game(game_t *game_s);

    void check_music_sound(game_t *game_s);

    void check_menu(game_t *game_s);

    void check_menu_setting_main(game_t *game_s);

    void check_menu_actif(game_t *game_s);

    sfSprite *get_sprite(sfTexture *texture, sfIntRect rect);

    sfTexture *get_texture(char *filepath, sfIntRect rect);

    void get_orientation(game_t *game);

    void update_sprite_obj(obj_t *temp);

    void get_orientation_zombie(game_t *game, obj_t *zombie);

    void spawn_zombies(game_t *game);

    void update_zombie_mov(game_t *game);

    void move_to_player(game_t *game, obj_t *zombie);

    void try_display_player(game_t *game, int y);

    void display_obj_based_on_distance(game_t *game);

    void check_if_dead(game_t *game);

    obj_t *build_obj(char *filepath, sfIntRect rect, state_t state,
    type_t type);

    void player_punch(game_t *game, sfMouseButtonEvent mouse);

    void display_near_dead_obj(game_t *game);

    void update_sprite_player_move(obj_t *temp);

    void display_player_health_stamina(game_t *game);

    void attack_player(game_t *game);

    void display_full_map(game_t *game);

    void display_map_p(game_t *game);

    void display_player(game_t *game_s, float move);

    void display_zombie(game_t *game, int x, int y);

    void display_inventory(game_t *game);

    void reset_inventory_item(game_t *game);

    char *int_to_char(int nb);

    void change_hours(button_t *button, sfRenderWindow *window, int h);

    void change_minutes(button_t *button, sfRenderWindow *window, int m);

    void change_seconds(button_t *button, sfRenderWindow *window, int s);

    void display_chest(game_t *game, int x, int y);

    void display_chest_menu(game_t *game);

    int get_idx_chest(game_t *game, int x, int y);

    item_t *get_specific_item(game_t *game, enum_item_t item);

    void display_npc(game_t *game, int x, int y);

    void display_sell_book(game_t *game);

    int is_mouse_in_rect(sfVector2i mpos, sfIntRect rect);

    void set_map(map_t *map, chest_t *chest[30]);

    int same_position(chest_t *chest, int x, int y);

    void close_filestream(game_t *game);

    void reset_musique(game_t *game);

    void play_song(game_t *game);

    void add_exp(game_t *game, int add);

    void update_stamina(game_t *game);

    void print_time(int sec, button_t *button, sfRenderWindow *window,
    game_t *game);

    void init_game_bar(game_t *game);

    void display_game_bar(game_t *game);

    void display_tree(game_t *game, sprite_t *sprite, int x, int y);

#endif/* !MY_H_ */
