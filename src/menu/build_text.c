/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** build_text
*/

#include "rpg.h"

text_t *build_text(char *filepath)
{
    text_t *text = malloc(sizeof(text_t));

    text->text = sfText_create();
    text->font = sfFont_createFromFile(filepath);
    if (text->font == NULL)
        return (NULL);
    sfText_setFont(text->text, text->font);
    return (text);
}
