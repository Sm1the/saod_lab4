#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

const int k=10;
///----FillInc---------------///
void FillInc (int num[], int n)
{   int o;
    for (o=0;o<n;o++)
        num[o]=o+1;
    //printf("FillInc\n");
}
///----FillDec---------------///
void FillDec (int num[], int n)
{   int o;
    for (o=0;o<n;o++)
        num[o]=n-o;
    //printf("FillDec\n");
}
///----FillRand--------------///
void FillRand(int num[], int n)
{   int o;
    for (o=0;o<n;o++)
        num[o]=rand()%100+1;
    //printf("FillRand\n");
}
///----PrintMas--------------///
void PrintMas(int num[], int n)
{   int o;
    printf("|");
    for (o=0;o<n;o++)
        printf("%2d|",num[o]);
    printf("\n");
}
void ShakerSort(int *A, int n, int &Mf, int &Cf){
    int L=0, R=n-1, K=n-1, t, j;
    do {
        for (j=R; j>L; j--) {
            Cf++;
            if (A[j]<A[j-1]) {
                t=A[j];
                A[j]=A[j-1];
                A[j-1]=t;
                K=j;
                Mf=Mf+3;
            }
        }
        L=K;
        for (j=L; j<R; j++){
            Cf++;
            if (A[j]>A[j+1]){
                t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
                K=j;
                Mf=Mf+3;
            }
        }
        R=K;
    }
    while (L<R);
}


void BubbleSort(int *A, int n, int &Mf, int &Cf) {
    int b, j, i;
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            Cf += 1;
            if (A[j] < A[j - 1]) {
                Mf += 3, b = A[j], A[j] = A[j - 1], A[j - 1] = b;
            }
        }
    }
}

void SortCount(int *mas, int k){
    int Mf,Cf,C,M;
    printf("До сортировки: ");
    PrintMas(mas,k);
    printf("\nПосле сортировки: ");
    Mf=0; Cf=0;
    ShakerSort(mas,k,Mf,Cf);
    PrintMas(mas,k);
    M=(3*(k*k-k))/4;
    C=(k*k-k)/2;
    printf("\nФактическое количество пересылок: %d\nТеоретическое количество пересылок: %d\n",Mf,M);
    printf("Фактическое количество сравнений: %d\nТеоретическое количество сравнений: %d\n",Cf,C);
}

void MainFunction(int *A, int n){
    int  Mf,Cf,C,M,Py,Pc,Pv,Sy,Sc,Sv;
    FillDec(A,n);
    Mf=0; Cf=0;
    ShakerSort(A,n,Mf,Cf);
    Sy=Mf+Cf;

    FillRand(A,n);
    Mf=0; Cf=0;
    ShakerSort(A,n,Mf,Cf);
    Sc=Mf+Cf;

    FillInc(A,n);
    printf("\n");
    Mf=0; Cf=0;
    ShakerSort(A,n,Mf,Cf);
    Sv=Mf+Cf;

    FillDec(A,n);
    Mf=0; Cf=0;
    BubbleSort(A,n,Mf,Cf);
    Py=Mf+Cf;

    FillRand(A,n);
    Mf=0; Cf=0;
    BubbleSort(A,n,Mf,Cf);
    Pc=Mf+Cf;

    FillInc(A,n);
    Mf=0; Cf=0;
    BubbleSort(A,n,Mf,Cf);
    Pv=Mf+Cf;

    printf("|%5d|%7d|%7d|%7d|%7d|%7d|%7d|\n",n,Py,Pc,Pv,Sy,Sc,Sv);
    printf("|-----+-------+-------+-------|-------+-------+-------|\n");
}

int main()
{
                setlocale(LC_ALL, "Rus");
                int mas[k];
                FillDec(mas,k);
    SortCount(mas, k);
                printf("\n");
                FillRand(mas,k);
    SortCount(mas, k);
                printf("\n");
                FillInc(mas,k);
    SortCount(mas, k);
                printf("\n");

                int n;
                printf("+-----+-----------------------+-----------------------+\n");
                printf("|     |       Mф+Сф пузыр.    |       Мф+Сф шейкер.   |\n");
                printf("|  n  +-------+-------+-------|-------+-------+-------|\n");
                printf("|     | Убыв. | Случ. | Возр. | Убыв. | Случ. | Возр. |\n");
                printf("|-----+-------+-------+-------|-------+-------+-------|\n");
                int* A;
                n=100;
                A=(int *)malloc(500*sizeof(int));
    MainFunction(A, n);
                n=200;
    MainFunction(A, n);
                n=300;
    MainFunction(A, n);
                n=400;
    MainFunction(A, n);
                n=500;
    MainFunction(A, n);




}




