#define _CRT_SECURE_NO_WARNINGS
constexpr auto LMAX = 5;
#include <stdio.h>
#include <stdlib.h>

void input_mass(int* mass, int len)
{
    for (int i = 0; i < len; i++)
    {
        scanf("%d", mass + i);
    };
};

void print_mass(int* mass, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", *(mass + i));
        //printf("%d ", mass[i]);
    };
}

void scanf_d(const char message[], int& number)
{
    int len;
    do
    {
        printf("%s", message);
        len = scanf("%d", &number);
        while ((getchar()) != '\n');
    } while (len != 1);
};

int* get_mass(void)
{
    int len;
    scanf_d("Write the length of massive: ", len);
    int mass[LMAX];
    input_mass(mass, len);
    return(mass);
    print_mass(mass, len);
    //free(mass);
};

int in_mass (int el, int* mass, int len)
{
    int flag = 0;
    for (int i = 0; i < len; i ++)
    {
        if (el == *(mass + i))
        {
            printf("el = %d, mass[%d] = %d\nLogic = %d\n", el, i, *(mass + i), (el==*(mass+i)));
            flag = 1;
            break;
        }
    };
    return flag;
};

int main()
{
    int A[LMAX], B[LMAX];
    printf("Massive A\n");
    printf("Adress of the A mass: %p\n", A);
    input_mass(A, LMAX);
    for (int i = 0; i < LMAX; i++)
    {
        printf("A[%d] = %d\n", i, A[i]);
    };

    printf("Massive B\n");
    printf("Adress of the B mass: %p\n", B);
    input_mass(B, LMAX);
    for (int i = 0; i < LMAX; i++)
    {
        printf("B[%d] = %d\n", i, B[i]);
    };
    printf("\n");
    
    /*
    printf("%d\n",in_mass(0, A, LMAX));
    printf("%d\n", in_mass(1, A, LMAX) );
    printf("%d\n", in_mass(10, A, LMAX) );
    printf("%d\n", in_mass(-55, B, LMAX));
    printf("%d\n", in_mass(1, B, LMAX) );
    */
    int C[LMAX * 2];

    int ind_C = 0;
    for (int i = 0; i < LMAX; i ++)
    {
        printf("%d in B = %d\n", *(A + i), in_mass(*(A + i), B, LMAX));
        printf("%d in C = %d\n", *(A + i), in_mass(*(A + i), C, LMAX));

        if (in_mass(*(A + i), B, LMAX) && (in_mass(*(A + i), C, ind_C) == 0))
        {
            printf("Element %d of A massive: %d\n", i, *(A + i));
            
            *(C + ind_C) = *(A + i);
            ind_C++;
            printf("C: ");
            print_mass(C, ind_C);
            printf("\n-----\n");
        };
    };

    printf("C: ");
    print_mass(C, ind_C);
    printf("\n");

    /*
    int M[] = { 1,2,3,4,5 };
    printf("True = %d\nFalse = %d\n", in_mass(1, M, 5), in_mass(6,M,5));
    */
    
    return 0;
}