#include <stdio.h>
#include <stdlib.h>
#include <math.h>


main()
{
    int pontos, n, grau, cont, i, j;
    float Px, valorCalcular, Li,sub;
    char resp;

    //Ponteiros
    float *valoresX = NULL;
    float *valoresFX = NULL;

    printf("Digite o grau da funcao que deseja obter: ");
    scanf("%i", &grau);
    fflush(stdin);

	//Obtendo o número de pontos a partir do grau indicado
    pontos = grau + 1;

    //Alocação do tamanho solicitado
    valoresX = (float*)malloc(n*sizeof(float));
    valoresFX = (float*)malloc(n*sizeof(float));


    for(cont=0; cont<pontos; cont++)
    {
        //receber valores de x e F(x):
        printf("Digite o valor de X%i: ", cont);
        scanf("%f", valoresX+cont);
        fflush(stdin);

        printf("Digite o de f(X%i): ", cont);
        scanf("%f", valoresFX+cont);
        fflush(stdin);
        printf("\n");
    }

    do
    {
        //recebe o valor para calcular
        printf("Digite o valor que deseja calcular: ");
        scanf("%f", &valorCalcular);
        fflush(stdin);

        Px = 0;

        //Implementar o calculo do Teorema de Lagrange
        for(i=0; i<pontos; i++)
        {
            Li = 1;
            for(j=0; j<pontos; j++)
            {
               if(j != i)
               {
                   sub = *(valoresX+i) - *(valoresX+j);
                   Li = Li * ((valorCalcular - *(valoresX+j))/ sub);
               }
            }
            //Calculo do Px
            Px = Px + (*(valoresFX+i) * Li);
        }
        //mostra ao usuario a resposta
        printf("F(%.2f) = %.4f\n\n",valorCalcular, Px);
        printf("Deseja calcular outro valor (s/n)? ");
        scanf("%c", &resp);
        fflush(stdin);
    }while (resp == 's' || resp == 'S');

    //Liberando a memória
    free(valoresX);
    free(valoresFX);

    system("pause");
}
