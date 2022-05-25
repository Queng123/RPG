/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-quentin.brejoin
** File description:
** button_is_clicked
*/

#include "rpg.h"

int text_is_clicked(button_t *button, sfVector2f click_position)
{
    if (button->text->pos.x <= click_position.x && button->text->pos.x +
    button->text->size.x >= click_position.x && button->text->pos.y <=
    click_position.y && button->text->pos.y + button->text->size.y >=
    click_position.y) {
        return (1);
    }
    return (0);
}
