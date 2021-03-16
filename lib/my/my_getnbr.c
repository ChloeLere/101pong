/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
    int i;
    int c = 0;
    int n = -1;
    i = 0;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') 
            n = n * (-1);
        i++;
    }
    while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0') {
        if (c < ((-2147483648 + str[i] -'0') / 10))
            return (0);
        c = (c * 10) - (str[i] - '0');
        i++;
    }
    if (n == -1 && c == -2147483648)
        return (0);
    return (c * n);
}
