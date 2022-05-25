/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game
*/

#ifndef HOWTWOPLAY_H_
    #define HOWTWOPLAY_H_

/******************************include*****************************************/

    #include "struct.h"

/******************************fonctions***************************************/

int init_how2play(game_t *game_s);
void init_struct_howplay(game_t *game);
void build_all_howtwoplay(game_t *game);
void display_help(game_t *game);
void build_st_one(howtwoplay_t *howtwoplay_s, int i);
void build_st_two(howtwoplay_t *howtwoplay_s, int i);
void build_st_three(howtwoplay_t *howtwoplay_s, int i);
void build_st_four(howtwoplay_t *howtwoplay_s, int i);
void build_st_five(howtwoplay_t *howtwoplay_s, int i);
void build_st_six(howtwoplay_t *howtwoplay_s, int i);

#endif/* !HOWTWOPLAY_H_ */
