#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Prototipo das funcoes
//Criar funcao para calcular a DICOTOMIA
float CalculaValorK(float a, float b, float erro);
float funcaoX(float ponto);
void ImprimirCabecalhoTabela();
void ImprimirTabela(int iteracao, float a, float b, float m, float fA, float fB, float fM, char fAfM, char fMfB);
void Diconomia(int K, float *ptrA, float *ptrB);

int grau;
float multi[7]; //Indice 0 a 6

main()
{
    int i, op;
    float erro, a, b;
    float *ptrA = &a, *ptrB = &b;
    do{
        system("cls");

        //Receber o grau da funcao entre 2 a 6
        printf("Informe o grau da funcao (2 a 6): ");
        scanf("%i", &grau);

        //Receber os multiplicadores. Dica: Armazenar os valores em um vetor.
        //aX^0 + bX^1 + cX^2 --->Indice do vetor igual ao expoente
        for(i=grau; i>=0; i--)
        {
            printf("Informe o fator multiplicador de x^%i(%c): ", i, 65+(grau-i));
            scanf("%f", &multi[i]);
        }
        printf("\n");

        //Exibindo a funcao recebida
        printf("A funcao recebida foi: ");
        for(i=grau; i>=0; i--)
        {
            if(i==0)
                printf("%.2f = 0", multi[i], i);
            else
                printf("%.2fx^%i + ", multi[i], i);
        }
        printf("\n\n");
        //Receber os valores de a, b e erro
        printf("Informe o valor do inicio do intervalo:");
        scanf("%f", ptrA);
        printf("Informe o valor do final do intervalo:");
        scanf("%f", ptrB);
        printf("Informe o valor do erro:");
        scanf("%f", &erro);

        //Verificar se no intervalo [A, B] existe zero de funcao
        if((funcaoX(*ptrA)*funcaoX(*ptrB)) >= 0){
            printf("\n\nNesse intervalo nao tem 0 na funcao!!!!\n\n");
            exit(0);
        }

        //descobre o valor de K
        int K = ceil(CalculaValorK(*ptrA, *ptrB, erro));
        printf("Resultado K = %i", K);

        printf("\n\n");
        system("pause");
        printf("\n");

        //Exibindo o cabecalho
        ImprimirCabecalhoTabela();

        //Implementacao da DICOTOMIA
        Diconomia(K, ptrA, ptrB);
        printf("\n");
        printf("deseja continuar ?(Sim [0], Nao[1]): ");
        scanf("%i", &op);
    }while(op != 1);
}

//Realiza o calculo do K (numero de passo)
float CalculaValorK(float a, float b, float erro)
{
    float fValorK;

    //Realizar o calculo do valor do K
    fValorK = (log10(b-a) - log10(erro))/(log10(2));
    return ceil(fValorK);
}

//Funcao que realiza o calculo em em determinado ponto
float funcaoX(float ponto)
{
    int i;
    float resultado;
    resultado = 0;
    for(i=0; i<=grau; i++)
    {
        resultado = resultado + multi[i]*pow(ponto, i);
    }
    return resultado;
}

//Imprimindo o cabecalho
void ImprimirCabecalhoTabela()
{
    //Impressao do cabecalho
    printf("I |\ta\t|\tb\t|\tm\t|\tf(a)\t|\tf(b)\t|\tf(m)\t|fa*fm\t|fm*fb\t|\n");
    printf("--+-------------+---------------+---------------+---------------+---------------+---------------+-------+-------+\n");
}

//Imprimindo a tabela com os valores
void ImprimirTabela(int iteracao, float a, float b, float m, float fA, float fB, float fM, char fAfM, char fMfB)
{
    printf("%i |%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%.5f\t|%c\t|%c\t|\n", iteracao, a, b, m, fA, fB, fM, fAfM, fMfB);
}

void Diconomia(int K, float *ptrA, float *ptrB)
{
    int i = 1;
    float media;
    char am, bm;
    do{
        //Faz as medias de [a,b]
        media = (*ptrA + *ptrB)/2;

        //verifica aonde o 0 esta na fun��o
        if((funcaoX(*ptrA)*funcaoX(media)) < 0){
            am = '-';
            bm = '+';
        }else{
            am = '+';
            bm = '-';
        }

        //Exibindo os valores na tabela
        ImprimirTabela(i, *ptrA, *ptrB, media, funcaoX(*ptrA), funcaoX(*ptrB), funcaoX(media),am, bm);

        if(am == '+')
            *ptrA = media;
        else
            *ptrB = media;

        i++;
    }while(i <= K);
}
