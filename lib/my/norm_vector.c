/*
** EPITECH PROJECT, 2020
** norm_vector
** File description:
** norm vector
*/

float norm_vector(float u, int n)
{
    float norm_u = 0.0;

    for (int i = 0; i < n; i++)
        norm_u += u * u;
    return (norm_u);
}
