/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_audio
*/

#include "rpg.h"

char *file_path[] = {"assets/menu/volume_bar.jpg",
"assets/menu/volume_bar.jpg", "assets/menu/switch_button.png",
"assets/menu/switch_button.png", "assets/menu/button_volume.png",
"assets/menu/button_volume.png", NULL};

void volume_buttons(game_t *game)
{
    game->menu->buttons[16]->sprite->pos = (sfVector2f) {444, 735};
    game->menu->buttons[17]->sprite->pos = (sfVector2f) {910, 735};
    game->menu->buttons[18]->sprite->pos = (sfVector2f) {1038, 735};
    game->menu->buttons[19]->sprite->pos = (sfVector2f) {1506, 735};
    game->menu->buttons[16]->sprite->size = (sfVector2f) {50, 50};
    game->menu->buttons[17]->sprite->size = (sfVector2f) {50, 50};
    game->menu->buttons[18]->sprite->size = (sfVector2f) {50, 50};
    game->menu->buttons[19]->sprite->size = (sfVector2f) {50, 50};
}

void set_pos_audio(game_t *game)
{
    game->menu->buttons[14]->sprite->pos = (sfVector2f) {859, 755};
    game->menu->buttons[15]->sprite->pos = (sfVector2f) {1455, 757};
    game->menu->buttons[12]->sprite->pos = (sfVector2f) {625, 480};
    game->menu->buttons[13]->sprite->pos = (sfVector2f) {1220, 480};
    game->menu->buttons[10]->sprite->pos = (sfVector2f) {515, 757};
    game->menu->buttons[11]->sprite->pos = (sfVector2f) {1112, 759};
    game->menu->buttons[12]->sprite->scale = (sfVector2f) {0.3, 0.3};
    game->menu->buttons[13]->sprite->scale = (sfVector2f) {0.3, 0.3};
    game->menu->buttons[12]->sprite->rect = (sfIntRect) {0, 256, 487, 256};
    game->menu->buttons[13]->sprite->rect = (sfIntRect) {0, 256, 487, 256};
    game->menu->buttons[12]->sprite->size = (sfVector2f) {487 * 0.3, 256 * 0.3};
    game->menu->buttons[13]->sprite->size = (sfVector2f) {487 * 0.3, 256 * 0.3};
    game->menu->buttons[10]->sprite->rect = (sfIntRect) {0, 0, 555, 18};
    game->menu->buttons[11]->sprite->rect = (sfIntRect) {0, 0, 555, 18};
    volume_buttons(game);
}

int init_buttons_volume(game_t *game)
{
    for (int i = 16; i != 20; i++) {
        game->menu->buttons[i] = malloc(sizeof(button_t));
        if (game->menu->buttons[i] == NULL)
            return (84);
        game->menu->buttons[i]->sprite = malloc(sizeof(sprite_t));
        if (game->menu->buttons[i]->sprite == NULL)
            return (84);
        game->menu->buttons[i]->sprite->sprite = NULL;
        game->menu->buttons[i]->sprite->size = (sfVector2f) {50, 50};
    }
    return (0);
}

int init_buttons_audio(game_t *game)
{
    for (int i = 10; i != 16; i++) {
        game->menu->buttons[i] = malloc(sizeof(button_t));
        if (game->menu->buttons[i] == NULL)
            return (84);
        game->menu->buttons[i]->sprite = build_bg(file_path[i - 10]);
        if (game->menu->buttons[i]->sprite == NULL)
            return (84);
        game->menu->buttons[i]->sprite->scale = (sfVector2f) {1.3 / 2, 1.3 / 2};
        game->menu->buttons[i]->text = malloc(sizeof(text_t));
        if (game->menu->buttons[i]->text == NULL)
            return (84);
        game->menu->buttons[i]->text->text = NULL;
    }
    if (init_buttons_volume(game) == 84)
        return (84);
    set_pos_audio(game);
    return (0);
}

int init_audio(game_t *game)
{
    game->menu->background[3] = malloc(sizeof(sprite_t));
    if (game->menu->background[3] == NULL)
        return (84);
    game->menu->background[3]->texture =
    sfTexture_createFromFile("assets/menu/audio_options.jpg", NULL);
    if (game->menu->background[3]->texture == NULL)
        return (84);
    game->menu->background[3]->sprite = sfSprite_create();
    if (game->menu->background[3]->sprite == NULL)
        return (84);
    game->menu->background[3]->pos = (sfVector2f) {375, 257};
    game->menu->background[3]->scale = (sfVector2f) {1.3 / 2, 1.3 / 2};
    game->menu->background[3]->size = (sfVector2f) {100, 100};
    sfSprite_setTexture(game->menu->background[3]->sprite,
    game->menu->background[3]->texture, sfTrue);
    if (init_buttons_audio(game) == 84)
        return (84);
    return (0);
}
