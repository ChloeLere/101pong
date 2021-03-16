/*
** EPITECH PROJECT, 2020
** main
** File description:
** main for 101pong
*/


#include <math.h>
#include "include/mymath.h"
#include <stdio.h>

float my_getfloat(char const *str)
{
    int size = my_strlen(str);   
    int entier = my_getnbr(str);
    int c = 0;
    float decimal = 0.0;

    for (;str[c] >=  '0' && str[c] <= '9'; c++, size--);
    if (str[c] != '\0' && str[0] != '-') {
        c++;
        size--;
    }
    for (;str[c] != '\0' && str[c] <= '9' && str[c] >= '0'; c++)
        decimal = (decimal * 10) + (str[c] - '0');
    for (;size > 0; size--)
        decimal /= 10;
    decimal = entier + decimal;
    return (decimal);
}

float construct_vector(float a, float b)
{
    float u;

    u = b - a;
    return (u);
}

float sub_vector(float a, float b)
{
    float res = b - a;

    return (res);
}

float search_co_ball(float a, int t, float z)
{
    float w = a * t + z;

    return (w);
}

float norm(float a, float b, float c)
{
    float norm = 0;
    float normf = 0;

    norm = (a * a) + (b * b) + (c * c);
    normf = sqrtf(norm);
    return (normf);
}

float scalaire(float x, float y, float z)
{
    float scal = 0;

    scal = 0 * x + 0 * y + 1 * z;
    return (scal);
}

float incidence_angle(float x, float y, float z)
{
    float angle = 0;
    float normV = norm(x, y, z);
    float normzV = norm(0, 0, 1);
    float scal = scalaire(x, y, z);
    float pi = 3.14159;

    angle = acosf(scal/(normV*normzV)) * 180;
    angle = - 90 + (angle / pi);
    return (angle);
    printf("The incidence angle is:\n%.2f degrees\n", angle);
}

float paddle_or_not_paddle(float xVd, float yVd, float zVd, float x0, float x1)
{
    if (zVd <= 0 && x0 <= 0 || x1 <= 0)
        return (incidence_angle(xVd, yVd, zVd));
    else
        return (-1.0);
}

int errort(char *argv)
{
    int r = 0;
    
    for (int i = my_strlen(argv) - 1; i >= 0; i--) {
        if (!(argv[i] >= '0' && argv[i] <= '9') || argv[i] == '.')
            r = 1;
    }
    return (r);
}

int error(int argc, char **argv)
{
    int r = 0;
    int nb = argc - 2;

    for (int i = 1; nb >= i; i++) {
        for (int c = my_strlen(argv[i]) - 1; c >= 0; c--) {
            if (!(argv[i][c] >= '0' && argv[i][c] <= '9') && argv[i][c] != '-' && argv[i][c] != '.')
                return (r = 1);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 8)
        return (84);
    if (errort(argv[7]) == 1)
        return (84);
    if (error(argc, argv) == 1)
        return (84);
    float x0 = my_getfloat(argv[1]);
    float y0 = my_getfloat(argv[2]);
    float z0 = my_getfloat(argv[3]);
    float x1 = my_getfloat(argv[4]);
    float y1 = my_getfloat(argv[5]);
    float z1 = my_getfloat(argv[6]);
    int t = my_getnbr(argv[7]);
    if (t < 0)
        return (84);
    float xVd = sub_vector(x0, x1);
    float yVd = sub_vector(y0, y1);
    float zVd = sub_vector(z0, z1);
    float BallX = search_co_ball(xVd, t, x1);
    float BallY = search_co_ball(yVd, t, y1);
    float BallZ = search_co_ball(zVd, t, z1);
    
    printf("The velocity vector of the ball is:\n(%.2f, %.2f, %.2f)\n", xVd, yVd, zVd);
    printf("At time t + %d, ball coordinates will be:\n(%.2f, %.2f, %.2f)\n", t, BallX, BallY, BallZ);
    paddle_or_not_paddle(xVd, yVd, zVd, x0, x1);
    return (0);
}
