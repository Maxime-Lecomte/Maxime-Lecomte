/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-mydefender-louison.kalifa
** File description:
** music.c
*/

#include <SFML/Audio.h>

sfMusic *open_music(char const *filename)
{
    sfMusic *music = sfMusic_createFromFile(filename);

    if (music == NULL)
        return NULL;
    return (music);
}

void close_music(sfMusic *music)
{
    if (music == NULL)
        return;
    sfMusic_destroy(music);
}

void increase_volume(sfMusic *music)
{
    float volume = sfMusic_getVolume(music) + 1;

    if (volume > 10)
        volume = 10;
    sfMusic_setVolume(music, volume);
}

void decrease_volume(sfMusic *music)
{
    float volume = sfMusic_getVolume(music) - 0.99;

    if (volume < 0)
        volume = 0;
    sfMusic_setVolume(music, volume);
}

void play_music(sfMusic *music, float volume)
{
    sfMusic_setVolume(music, volume);
    sfMusic_play(music);
    sfMusic_setLoop(music, sfTrue);
}