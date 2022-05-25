/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** manage_audio
*/

#include "rpg.h"

void manage_volume_right(game_t *game, sfVector2f click_pos)
{
    if (button_is_clicked(game->menu->buttons[18], click_pos) == 1 &&
    game->menu->buttons[11]->sprite->rect.width > 0 &&
        game->menu->buttons[11]->sprite->rect.width <= 555) {
        game->game_info->volume_sound -= 20;
        game->menu->buttons[15]->sprite->pos.x -= 70;
        game->menu->buttons[11]->sprite->rect.width -= 111;
        if (game->game_info->volume_sound == 0)
            game->menu->buttons[13]->sprite->rect.top = 0;
        else
            game->menu->buttons[13]->sprite->rect.top = 256;
    }
    if (button_is_clicked(game->menu->buttons[19], click_pos) == 1 &&
    game->menu->buttons[11]->sprite->rect.width >= 0 &&
        game->menu->buttons[11]->sprite->rect.width < 555) {
        game->game_info->volume_sound += 20;
        game->menu->buttons[15]->sprite->pos.x += 70;
        game->menu->buttons[11]->sprite->rect.width += 111;
        game->menu->buttons[13]->sprite->rect.top = 256;
    }
    update_sound_parameters(game);
}

void manage_volume_left(game_t *game, sfVector2f click_pos)
{
    if (button_is_clicked(game->menu->buttons[16], click_pos) == 1 &&
    game->menu->buttons[10]->sprite->rect.width > 0 &&
        game->menu->buttons[10]->sprite->rect.width <= 555) {
        game->game_info->volume_music -= 20;
        game->menu->buttons[14]->sprite->pos.x -= 70;
        game->menu->buttons[10]->sprite->rect.width -= 111;
        if (game->game_info->volume_music == 0)
            game->menu->buttons[12]->sprite->rect.top = 0;
        else
            game->menu->buttons[12]->sprite->rect.top = 256;
    }
    if (button_is_clicked(game->menu->buttons[17], click_pos) == 1 &&
    game->menu->buttons[10]->sprite->rect.width >= 0 &&
        game->menu->buttons[10]->sprite->rect.width < 555) {
        game->game_info->volume_music += 20;
        game->menu->buttons[14]->sprite->pos.x += 70;
        game->menu->buttons[10]->sprite->rect.width += 111;
        game->menu->buttons[12]->sprite->rect.top = 256;
    }
    update_sound_parameters(game);
}

void manage_audio_mouse_released(sfMouseButtonEvent event, game_t *game)
{
    sfVector2f click_pos = (sfVector2f) {event.x, event.y};

    if (game->game_info->scene->actual_scene == MENU &&
    game->game_info->scene->actual_menu_scene == OPTIONS &&
    game->game_info->scene->options_scene == AUDIO) {
        if (button_is_clicked(game->menu->buttons[13], click_pos) == 1) {
            game->game_info->sound_on = (game->game_info->sound_on == 1)
            ? 0 : 1;
            game->menu->buttons[13]->sprite->rect.top =
            (game->menu->buttons[13]->sprite->rect.top == 256) ? 0 : 256;
        }
        if (button_is_clicked(game->menu->buttons[12], click_pos) == 1) {
            game->game_info->music_on = (game->game_info->music_on == 1)
            ? 0 : 1;
            game->menu->buttons[12]->sprite->rect.top =
            (game->menu->buttons[12]->sprite->rect.top == 256) ? 0 : 256;
        }
        manage_volume_left(game, click_pos);
        manage_volume_right(game, click_pos);
        update_sound_status(game);
    }
}
