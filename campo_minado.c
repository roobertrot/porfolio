//campo minado
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main ()
{
	int tamanhotab, contjog,jogadas, qtdbombas;
	scanf("%d \n",&contjog);





	int i, j, h, a, b, x,y;

	for(h=0; h<contjog; h++)
	{
	    scanf("%d \n",&tamanhotab);
    char T[tamanhotab][tamanhotab];
	int count=0;
    int teste = 0;

		for (i=0; i<tamanhotab; i++)
		{
	  	for (j=0; j<tamanhotab; j++)
			{
				scanf("%s",&T[i][j]);
				if (T[j][i]=='b')
				{
					qtdbombas++;
				}
			}
		}

		scanf("%d \n",&jogadas); //recebe quantos pares de coordenadas o jogador escrever�

    for(int qtdjogadas = 1; qtdjogadas <= jogadas; qtdjogadas++)
    {
			scanf("%d %d",&x,&y);

			if (T[x][y]=='b')
			{
				printf("PERDEU \n");
        teste = 1;
			}
			else if (x+1>=tamanhotab && y+1>=tamanhotab) //Verifico o canto inferior direito
			{
        T[x][y]='z';
				if(T[x-1][y]!='b' && T[x][y-1]!='b') //verifica��o para abrir os adjacentes
				{
					T[x-1][y]='z';
          T[x][y-1]='z';
          //printf("canto inferior direito");
				}
			}

			else if (x-1<0 && y+1>=tamanhotab) //Verifico o canto superior direito
			{
        T[x][y]='z';
				if(T[x+1][y]!='b' && T[x][y-1]!='b') //verifica��o para abrir os adjacentes
				{
					T[x+1][y]='z';
          T[x][y-1]='z';
          //printf("canto superior direito");
				}
			}

			else if (x-1<0 && y-1<0) //Verifico o canto superior esquerdo
			{
        T[x][y]='z';
				if(T[x+1][y]!='b' && T[x][y+1]!='b') //verifica��o para abrir os adjacentes
				{
					T[x+1][y]='z';
          T[x][y+1]='z';
          //printf("canto superior esquerdo");
				}
			}
			else if (x+1>=tamanhotab && y-1<0) //Verifico o canto inferior esquerdo
			{
        T[x][y]='z';
				if(T[x-1][y]!='b' && T[x][y+1]!='b') //verifica��o para abrir os adjacentes
				{
					T[x-1][y]='z';
          T[x][y+1]='z';
          //printf("canto inferior esquerdo");
				}
			}

			else if(x-1<0 && y!=0 && y!=tamanhotab) //Verifica��o laterais
			{
        T[x][y]='z';
				if(T[x+1][y]!='b' && T[x][y-1]!='b' && T[x][y+1]!='b')
				{
					T[x+1][y]='z';
          T[x][y-1]='z';
          T[x][y+1]='z';
          //printf("Verifica��o laterais CIMA");
				}
			}

			else if(y+1>=tamanhotab && x!=0 && x!=tamanhotab) //Verifica��o laterais
			{
        T[x][y]='z';
				if(T[x-1][y]!='b' && T[x+1][y]!='b' && T[x][y-1]!='b')
				{
					T[x-1][y]='z';
          T[x+1][y]='z';
          T[x][y-1]='z';
          //printf("Verifica��o laterais DIREITA");
				}
			}

			else if(x+1>=tamanhotab && y!=0 && y!=tamanhotab) //Verifica��o laterais
			{
        T[x][y]='z';
				if(T[x-1][y]!='b' && T[x][y-1]!='b' && T[x][y+1]!='b')
				{
					T[x-1][y]='z';
          T[x][y-1]='z';
          T[x][y+1]='z';
          //printf("Verifica��o laterais BAIXO");
				}
			}

			else if(y-1>=tamanhotab && x!=0 && x!=tamanhotab) //Verifica��o laterais
			{
        T[x][y]='z';
				if(T[x-1][y]!='b' && T[x+1][y]!='b' && T[x][y+1]!='b')
				{
					T[x-1][y]='z';
          T[x+1][y]='z';
          T[x][y+1]='z';
          //printf("Verifica��o laterais ESQUERDA");
				}
			}
			else {
        T[x][y]='z';

        if(T[x-1][y]!='b' && T[x][y+1]!='b' && T[x+1][y]!='b' && T[x][y-1]!='b')
        {
          T[x-1][y]='z';
          T[x][y+1]='z';
          T[x+1][y]='z';
          T[x][y-1]='z';
        }

        //printf("MEIO");
			}

      count=0;
      for(a=0; a<tamanhotab; a++)
      {
        for(b=0; b<tamanhotab; b++)
        {
          if(T[a][b] == 'z')
          {
            count++;
          }
        }
      }
/*
      for(b=0; b<tamanhotab; b++)
      {
        printf("\n");
        for(a=0; a<tamanhotab; a++)
        {
          printf("%c ", T[b][a]);
        }
      }
*/
		}
    if (teste == 0)
    {
      if (count==(tamanhotab*tamanhotab)-qtdbombas)
		  {
		  	printf("GANHOU \n");
		  }

		  if (count<(tamanhotab*tamanhotab)-qtdbombas)
		  {
		  	printf("FALTOU TERMINAR \n");
		  }

    }

	}
}
