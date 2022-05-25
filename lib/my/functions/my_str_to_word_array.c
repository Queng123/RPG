/*
** EPITECH PROJECT, 2021
** my_str_word_array
** File description:
** the function is a function
*/

#include <stdlib.h>

int check_character(char *str, int i)
{
    int a = 0;
    int f = 0;
    if ((str[i] >= 33 && str[i] <= 126))
        a++;
    if ((str[i + 1] < 33 || str[i + 1] > 126))
        f++;
    if (a == 1 && f == 1)
        return (1);
    else
        return (0);
}

int nbr_line(char *arg)
{
    char *str = arg;
    int a = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_character(str, i) == 1)
            a++;
    }
    return (a);
}

int check_if(char *s, int i, int a)
{
    int b = 0;
    int c = 0;
    if ((s[i + 1] < 33 || s[i + 1] > 126) && ((s[i]) > 32 && s[i] < 127))
        b++;
    if ((s[i + 1] == '\0' && a < nbr_line(s)))
        c++;
    if (b == 1 || c == 1)
        return (1);
    else
        return (0);
}

char *stock_word(char *str, int i, int f)
{
    char *s = NULL;

    s = malloc(sizeof(char) * f + 1);
    s[f] = '\0';
    for (int e = 0; f != 0; e++, f--) {
        s[e] = str[i - (f - 1)];
    }
    return (s);
}

char **my_str_to_word_array(char *str)
{
    char **array = NULL;
    int a = 0;
    int f = 0;

    array = malloc(sizeof(char*) * (nbr_line(str) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 33 && str[i] <= 126)
            f++;
        if (check_if(str, i, a) == 1) {
            array[a] = malloc(sizeof(char) * f + 1);
            array[a][f] = '\0';
            array[a] = stock_word(str, i, f);
            f = 0;
            a++;
        }
    }
    array[a] = NULL;
    return (array);
}
