/*
** EPITECH PROJECT, 2022
** physique_engine
** File description:
** event
*/

#include "event.h"

int analyse_up_and_down(game_t *game)
{
    if (game->event.key.code == game->game_info->commands[1]) {
        move_entitie(game, 1, Y);
        game->generator->sprite_pos.y -= 48;
        update_sprite_player_move(game->player->obj);
        return (0);
    } else if (game->event.key.code == game->game_info->commands[0]) {
        move_entitie(game, -1, Y);
        game->generator->sprite_pos.y += 48;
        update_sprite_player_move(game->player->obj);
        return (0);
    }
    return (-1);
}

int analyse_key_movement(game_t *game)
{
    if (game->event.key.code == game->game_info->commands[2]) {
        move_entitie(game, -1, X);
        update_sprite_player_move(game->player->obj);
        game->generator->sprite_pos.x += 48;
        return (0);
    } else if (game->event.key.code == game->game_info->commands[3]) {
        move_entitie(game, 1, X);
        game->generator->sprite_pos.x -= 48;
        update_sprite_player_move(game->player->obj);
        return (0);
    }
    if (analyse_up_and_down(game) == 0)
        return (0);
    return (-1);
}

void handle_inventory(game_t *game)
{
    if (game->event.key.code == game->game_info->commands[5] &&
    game->gameplay->pause->display == false) {
        update_inventory(game, -game->player->inventory->is_display);
        return;
    }
}

void handle_movement(game_t *game)
{
    player_t *player = game->player;
    clockk_t *clock = player->obj->clock_move;
    int speed = get_speed_running(game);

    if (clock->seconds > speed && game->gameplay->pause->display == false
    && game->chests->is_display != 1 && game->quest->is_display != 1) {
        if (analyse_key_movement(game) == 0) {
            sfClock_restart(clock->clock);
            game->player->obj->clock_move->seconds = 0;
            decrease_movement(game);
        }
    }
}

void analyse_event_gameplay(game_t *game)
{
    if (game->game_info->scene->actual_game_scene != GAMEPLAY ||
    game->game_info->scene->actual_scene != GAME)
        return;
    if (game->event.type == sfEvtKeyPressed &&
    game->gameplay->pause->display == false) {
        handle_key_pressed(game);
    } else if (game->event.type == sfEvtMouseButtonPressed &&
    game->gameplay->pause->display == false) {
        handle_click(game);
    }
    if (game->event.type == sfEvtMouseButtonPressed &&
    game->gameplay->pause->display == true &&
    game->game_info->scene->actual_game_scene == GAMEPLAY) {
        manage_pause_buttons(game, game->event.mouseButton);
    }
    if (game->event.type == sfEvtKeyPressed)
        handle_pause(game);
}
