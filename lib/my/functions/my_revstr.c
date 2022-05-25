/*
** EPITECH PROJECT, 2021
** my_revstr.C
** File description:
** reverse string
*/

char *my_revstr(char *str)
{
    int len = 0;
    int swap = 0;

    for (len; str[len] != '\0'; len++);
    len = len - 1;
    for (int i = 0; i <= len / 2; i++) {
        swap = str[i];
        str[i] = str[len - i];
        str[len - i] = swap;
    }
    return (str);
}
