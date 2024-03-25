//MARIA FERNANDA MEDRANO CALDERON, MATR:373143
//MENU DE VECTORES Y MATRICES
//FECHA: 24-MAR-2024
//MFMC_ACT8_01
#include <stdio.h>
#include <stdlib.h>
#define N 10 // TAMANO DEL VECTOR
#define M 4  // TAMANO DE LA MATRIZ
void llenarvect(int vect[], int m);
void llenarvect2(int vect[], int m);
void llenarvect3(int vect[], int vect1[], int vect2[], int m);
void imprimirvect(int vect[], int m);
void llenarMat(int matriz[][M], int vect1[], int vect2[]);
void imprimirmat(int matriz[][M]);

void menu();

int main()
{
    menu();
    return 0;
}

int inicio()
{
    int op;
    system("CLS");
    printf(" ----- MENU ----- \n");
    printf("1.- LLENAR VECTOR 1 (MANUALMENTE)\n");
    printf("2.- LLENAR VECTOR 2 ALEATORIAMENTE \n");
    printf("--- Para la opcion 3 en adelante es obligatorio realizar las opciones 1 y 2 ---\n");
    printf("3.- LLENAR VECTOR 3 (CON VECTOR1 Y VECTOR2) \n");
    printf("4.- IMPRIMIR VECTORES \n");
    printf("5.- LLENA MATRIZ 4 X 4 \n");
    printf("6.- IMPRIMIR MATRIZ \n");
    printf("0.- SALIR \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu()
{
    int vect2[N], vect1[N], vect3[N * 2], matriz[M][M];
    int op;
    do
    {
        op = inicio();
        switch (op)
        {
        case 1:
            llenarvect(vect1, N);
            system("pause");
            break;
        case 2:
            llenarvect2(vect2, N);
            printf("Se lleno el VECTOR No.2\n");
            system("pause");
            break;
        case 3:
            llenarvect3(vect3, vect1, vect2, N * 2);
            printf("Se lleno el VECTOR No.3\n");
            system("pause");
            break;
        case 4:
            printf("VECTOR No. 1:\n");
            imprimirvect(vect1, N);
            printf("VECTOR No. 2:\n");
            imprimirvect(vect2, N);
            printf("VECTOR No. 3:\n");
            imprimirvect(vect3, N * 2);
            system("pause");
            break;

        case 5:
            llenarMat(matriz, vect1, vect2);
            printf("Se lleno la MATRIZ\n");
            system("pause");
            break;

        case 6:
            printf("La MATRIZ:\n");
            imprimirmat(matriz);
            system("pause");
            break;

        default:
            printf("---- Elija una de las opciones del MENU ----");
            system("pause");
            break;
        }

    } while (op != 0);
}

void llenarvect(int vect[], int m)
{
    int num, i;
    for (i = 0; i < m; i++)
    {
        printf("Ingresa el numero de la posicion No. %d: ", i);
        scanf("%d", &num);
        vect[i] = num;
        if (num < 30 || num > 70)
        {
            printf("El numero debe estar entre el 30 al 70!!\n");
            i--;
        }
    }
}

void llenarvect2(int vect[], int m)
{
    int num_existen[20] = {0};
    int i, num;

    for (i = 0; i < m; i++)
    {
        do
        {
            num = rand() % 20 + 1;
        } while (num_existen[num - 1]);
        vect[i] = num;
        num_existen[num - 1] = 1;
    }
}

void llenarvect3(int vect[], int vect1[], int vect2[], int m)
{
    int i;
    for (i = 0; i < m; i++)
    {
        if (i < N)
        {
            vect[i] = vect1[i];
        }
        else
        {
            vect[i] = vect2[i - N];
        }
    }
}

void imprimirvect(int vect[], int m)
{
    int i;
    for (i = 0; i < m; i++)
    {
        printf("%d ----> [%d] \n", i, vect[i]);
    }
}

void llenarMat(int matriz[][M], int vect1[], int vect2[])
{
    int i, j, n = 0;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (n < N)
            {
                matriz[i][j] = vect1[n];
            }
            else
            {
                matriz[i][j] = vect2[n - N];
            }
            n++;
        }
    }
}

void imprimirmat(int matriz[][M])
{
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < M; j++)
        {
            printf("[%d]\t", matriz[i][j]);
        }
        printf("\n");
    }
}