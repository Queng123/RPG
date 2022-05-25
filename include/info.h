/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** info
*/

#ifndef INFO_H_
    #define INFO_H_

    #include <SFML/Window.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Network.h>
    #include <stdbool.h>
    #include "enum.h"

typedef struct scene_s {
    enum_scene actual_scene;
    enum_scene previous_scene;
    enum_save actual_save;
    enum_menu_scene actual_menu_scene;
    enum_menu_scene previous_menu_scene;
    enum_game_scene actual_game_scene;
    enum_game_scene previous_game_scene;
    enum_how_to_play_scene actual_how_to_play_scene;
    enum_how_to_play_scene previous_how_to_play_scene;
    enum_options_scene options_scene;
    enum_tablet tablet_scene;
}scene_t;

typedef struct info_s {
    scene_t *scene;
    sfRenderWindow *window;
    sfVideoMode mode;
    sfVector2u window_size;
    sfKeyCode commands[9];
    int fps;
    int sound_on;
    int music_on;
    int volume_sound;
    int volume_music;
    int particles_on;
    int screen_size;
} info_t;

#endif/* !INFO_H_ */
