/*
** EPITECH PROJECT, 2021
** evil str
** File description:
** evil str
*/

#include <unistd.h>

int my_getnbr(char const *str)
{
    long i = 0;
    long exp = 1;
    long nb = 0;
    long expect = 0;

    for (i; str[i] != '\0' && str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            exp = exp * -1;
    }
    for (i; str[i] != '\0' && str[i] >= '0' && str[i] <= '9'; i++) {
        expect = expect * 10;
        expect = expect + (str[i] - 48);
        if (expect > 2147483648 || expect < -2147483649)
            return (0);
        nb = expect;
    }
    if (exp == 1 && nb == 2147483648)
        return (0);
    return (nb * exp);
}
