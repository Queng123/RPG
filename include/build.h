/*
** EPITECH PROJECT, 2022
** lol
** File description:
** build
*/

#ifndef BUILD_H_
    #define BUILD_H_
    #include "struct.h"
    #include <stdlib.h>
    #include <fcntl.h>
    #include <stdio.h>

player_t *build_player(char *filepath);

sfSprite *build_sprite(char *filepath);

clockk_t *build_clock(void);

sfRenderWindow *build_wind(void);

void build_all_obj(obj_t *res[NB_ENT]);

void build_barbarian(obj_t *res[NB_ENT]);

void build_enemy(obj_t *res[NB_ENT]);

obj_t *build_obj(char *filepath, sfIntRect rect, state_t state, type_t type);

bar_t *build_bar(char *filepath, int max, sfIntRect rect, sfVector2f pos);

sprite_t *build_sprit(sfIntRect, const char *, sfVector2f, sfVector2f);

map_t *build_map(char *filepath);

char **str_to_word_array(char *str, char *delimiteur);

void build_tab_sprite_p_tab_zero_nine(sprite_t *tab[19], sfVector2f pos,
sfVector2f scale);

void build_tab_sprite_p_tab_nine_fivety(sprite_t *tab[19], sfVector2f pos,
sfVector2f scale);

inventory_t *build_inventory(void);

sprite_t *build_bg(char *filepath);

text_t *build_text(char *filepath);

tab_chest_t *build_tab_chest(char *filepath, sprite_t **sprite);

quest_t *build_quest(void);

void set_npc_map(map_t *map, quest_t *quest);

audio_t *load_audio(void);

#endif/* !BUILD_H_ */
