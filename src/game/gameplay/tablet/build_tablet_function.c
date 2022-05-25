/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** build_tablet_function
*/

#include "rpg.h"

void init_tablet(tablet_t *tablet)
{
    tablet->button[0]->text->str = "PLAYER INFO";
    tablet->button[1]->text->str = "SKILL TREE";
    tablet->button[2]->text->str = "MAP";
    tablet->button[3]->text->str = "QUEST";
}
