/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** build_audio
*/

#include "gameplay.h"

int create_sound(audio_t *audio)
{
    sfSoundBuffer *ak = sfSoundBuffer_createFromFile("assets/game/AK.ogg");
    sfSoundBuffer *eat = sfSoundBuffer_createFromFile("assets/game/Eat.ogg");
    sfSoundBuffer *zombie =
    sfSoundBuffer_createFromFile("assets/game/zombie.ogg");
    audio->ak_sound = sfSound_create();
    audio->eat_sound = sfSound_create();
    audio->zombie = sfSound_create();

    if (ak == NULL || audio->ak_sound == NULL ||audio->eat_sound == NULL
    || audio->zombie == NULL || eat == NULL || zombie == NULL) {
        return (84);
    }
    sfSound_setBuffer(audio->ak_sound, ak);
    sfSound_setBuffer(audio->eat_sound, eat);
    sfSound_setBuffer(audio->zombie, zombie);
    return (0);
}

void init_load_audio(audio_t *sound)
{
    sound->boss_fight =
    sfMusic_createFromFile("assets/game/IDEA_RPG_Fight.ogg");
    sound->classic_fight =
    sfMusic_createFromFile("assets/game/RPG_Fight.ogg");
    sound->menu_music = sfMusic_createFromFile("assets/game/Fight.ogg");
    sound->night_music = sfMusic_createFromFile("assets/game/horror.ogg");
    sound->intro = sfMusic_createFromFile("assets/game/intro_rpg.ogg");
    sound->is_played = -1;
}

audio_t *load_audio(void)
{
    audio_t *sound = malloc(sizeof(audio_t));

    if (sound == NULL)
        return (NULL);
    init_load_audio(sound);
    if (sound->boss_fight == NULL ||sound->classic_fight == NULL ||
    sound->menu_music == NULL || sound->night_music == NULL ||
    sound->intro == NULL) {
        return (NULL);
    } else if (create_sound(sound) == 84) {
        return (NULL);
    }
    sfMusic_setLoop(sound->boss_fight, sfTrue);
    sfMusic_setLoop(sound->classic_fight, sfTrue);
    sfMusic_setLoop(sound->menu_music, sfTrue);
    sfMusic_setLoop(sound->night_music, sfTrue);
    sfMusic_setLoop(sound->intro, sfTrue);
    return (sound);
}
