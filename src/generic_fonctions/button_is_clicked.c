/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-quentin.brejoin
** File description:
** button_is_clicked
*/

#include "rpg.h"

int button_is_clicked(button_t *button, sfVector2f click_position)
{
    if (button->sprite->pos.x <= click_position.x && button->sprite->pos.x +
    button->sprite->size.x >= click_position.x && button->sprite->pos.y <=
    click_position.y && button->sprite->pos.y + button->sprite->size.y >=
    click_position.y) {
        return (1);
    }
    return (0);
}
