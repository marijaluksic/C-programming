// Auditorne 2  Kolači.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    // FLOOR FUNKCIJA, ZAOKRUZIVANJE NA NIZU VRIJEDNOST
    float dzeparac = 0;
    float brstranica = 0;
    float duljinastr = 0;
    float visina = 0;
    float cijenakomada = 0;
    float volumenkolaca = 0;
    float isplativost = 0;
    float brojkolaca = 0;
    scanf("%f %f %f %f %f", &dzeparac, &brstranica, &duljinastr, &visina, &cijenakomada);
    if (brstranica < 3 || duljinastr < 0)
    {
        printf("Krivi unos! Molim probajte opet.");
        scanf("%f %f %f %f %f", &dzeparac, &brstranica, &duljinastr, &visina, &cijenakomada);
        volumenkolaca = visina * brstranica * (duljinastr * duljinastr) * (cos(3.14 / brstranica) / sin(3.14 / brstranica)) / 4;
        isplativost = cijenakomada / volumenkolaca;
        brojkolaca = dzeparac / cijenakomada;
        printf("Perica moze kupiti: %.f kolaca, a platit ce %.2fkn/cm^3.", floor(brojkolaca), isplativost);
    }
    else
    {
        volumenkolaca = visina * brstranica * (duljinastr * duljinastr) * (cos(3.14 / brstranica) / sin(3.14 / brstranica)) / 4;
        isplativost = cijenakomada / volumenkolaca;
        brojkolaca = dzeparac / cijenakomada;
        printf("Perica moze kupiti: %.f kolaca, a platit ce %.2fkn/cm^3.", floor(brojkolaca), isplativost);
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
