#include <stdio.h>
#include <math.h>

#define MAX 2
#define X 1
#define Y 2

double distance(double point1[], double point2[]);

int main(void)
{
    double coord1[MAX], coord2[MAX];

    puts("\nCalculando a distancia entre dois pontos.");

    printf("Digite as coordenadas para o ponto 1: ");
    scanf("%lf %lf", &coord1[X], &coord1[Y]);

    printf("Digite as coordenadas para o ponto 2: ");
    scanf("%lf %lf", &coord2[X], &coord2[Y]);

    printf("Distancia: %.2f\n", distance(coord1, coord2));
    return 0;
}

/* Recebe dois pontos e retorna a distância entre eles */
double distance(double point1[], double point2[])
{
    double dist = sqrt(pow((point2[X] - point1[X]), 2) + pow((point2[Y] - point1[Y]), 2));
    return dist;
}
