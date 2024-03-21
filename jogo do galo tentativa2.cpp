/*
O jogo do Galo
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>





void numerosnamatriz(char matriz[3][3]) //define uma função que ira encher a matriz de numeros de 1 a 9
{
	int y = '1'; //varivavel que dara os valores a matriz

	
	
	for(int i  = 0; i < 3; i++) // vai executar o for dentro dele 3 vezes
	{
		for(int e = 0; e < 3; e++) //vai executar o comando dentro dele 3 vezes
		{
			matriz[i][e] = y; // vai dizer que a posição na matriz é equeivalente a i e e o que faz com que todos os espços da matriz sejam percorridos
			y++; //icrementa o valor da varivale que da os numeros a posição da matriz
		}
	}
	
	/*
	resulta numa matriz assim 
	[1][2][3]
	[4][5][6]
	[7][8][9]
	*/
}

void imprimir(char matriz[3][3]) //funçao que imprime a matriz no ecra
{
	for(int i = 0; i < 3; i++) //recorre a ciclos fo encadiados para mover-se por cada posiçao e imprimir uma a uma no ecra
	{
		printf("\t");
		for(int e = 0; e < 3; e++)
		{
			if(matriz[i][e] == 'X')
			{
				printf("\033[1;31m[ %c ]\033[0m", matriz[i][e]); //Muda o codigo de cor para imprimir a vermelho
			}
			else if(matriz[i][e] == 'O')
			{
				printf("\033[1;34m[ %c ]\033[0m", matriz[i][e]); //muda o codigo de cor para imprimir o caractere para azul
			}
			else
			{
				printf("[ %c ]", matriz[i][e]);
			}
			
		}
		printf("\n");
	}
}

char ofim(char matriz[3][3]) //verifica se ha vitorias
{
    
	char vencedor = ' ';

    
    for (int i = 0; i < 3; i++) {
        if ((matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2]) || (matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i])) //verifica vitoria nas linhas e colunas
		{
            if(matriz[i][0] == matriz[i][1] && matriz[i][0] == matriz[i][2]) //verifica individualmente as linhas
            {
            	vencedor = matriz[i][0];
            	break;
			} else if(matriz[0][i] == matriz[1][i] && matriz[0][i] == matriz[2][i]) //verifica individualmente as colunas
			{
				vencedor = matriz[0][i];
            	break;	
			}
        }
    }

  
    if ((matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2]) || (matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0])) //verifica as diagonais
	{
        vencedor = matriz[1][1];
    }

    return vencedor; //devolve a variavel que contem, quem ganhou ou um espaço em branco no caso de n existir vitoria
}



int main() //funçao principal
{
	char matriz[3][3], vencedor; //declaraçao de variaveis
	int jogador1[5], jogador2[4], jogadas = 0;
	
	
	printf("\n----------Jogo_do_Galo----------\n\n"); //imprime titlo do jogo no ecra
	
	numerosnamatriz(matriz); //chama as funçoes necessarias
	imprimir(matriz);
	
	do //começa o ciclo do principal
	{
		
	do //do da primeira jogada
	{
	printf("\n");
	printf("\nJogador 1 : "); //pde a jogada
	scanf("%d", &jogador1[0]);
	
	if(jogador1[0] < 1 || jogador1[0] > 9) //verifica se É valida
	{
		printf("Jogada invalida");
	}
	else if(jogador1[0] >= 1 || jogador1[0] <= 9) //SE for imprime a matriz
	{
		matriz[(jogador1[0] - 1) / 3][(jogador1[0] - 1) % 3] = 'X';
		printf("\n");
		system("cls");
		printf("\n----------Jogo_do_Galo----------\n\n");
		imprimir(matriz);
		jogadas++; //incrementa numeros de jogadas
		
		break;
	}
	
	
	} while(true);
	
	
	
	
	vencedor = ofim(matriz); //chama a funçao que verifica as vitorias
	
	
	if(vencedor != ' ') //ve se a vitoria e se sim imprime no ecra
	{
		printf("%c ganhou", ofim(matriz));
		break;
	}
	else if(jogadas == 9) //se jogadas for igual a nove a um empate
	{
		printf("Empate ");
	}
	else  //senao continua o codigo
	{
		
	do //realiza a mesma logica para o jogador 2
	{
	printf("\n");
	printf("\nJogador 2 : ");
	scanf("%d", &jogador2[0]);
	
	if(jogador2[0] < 1 || jogador2[0] > 9)
	{
		printf("Jogada invalida");
	}
	else if(jogador2[0] == jogador1[0])
	{
		printf("Ja foi feita uma jogada neste local!!");
	} 
	else if(jogador2[0] >= 1 || jogador2[0] <= 9)
	{
		matriz[(jogador2[0] - 1) / 3][(jogador2[0] - 1) % 3] = 'O';
		printf("\n");
		system("cls");
		printf("\n----------Jogo_do_Galo----------\n\n");
		imprimir(matriz);
		jogadas++;
		
		break;
	}
	
	
	} while(true);
	
	
	vencedor = ofim(matriz);
	//o mesmo ciclo para verificar a vitoria
	
	if(vencedor != ' ')
	{
		printf("%c ganhou", ofim(matriz));
		break;
	}
	else if(jogadas == 9)
	{
		printf("Empate");
	}
	else
	{
		
	do //verifica a 2 jjogada do jogador 1
	{
	printf("\n");
	printf("\nJogador 1 : ");
	scanf("%d", &jogador1[1]);
	
	if(jogador1[1] < 1 || jogador1[1] > 9)
	{
		printf("Jogada invalida");
	}
	else if(jogador2[0] == jogador1[1] || jogador1[0] == jogador1[1])
	{
		printf("Ja foi feita uma jogada neste local!!");
	}
	else if(jogador1[1] >= 1 || jogador1[1] <= 9 && jogador2[0] != jogador1[1] && jogador1[0] != jogador1[0])
	{
	
		matriz[(jogador1[1] - 1) / 3][(jogador1[1] - 1) % 3] = 'X';
		printf("\n");
		system("cls");
		printf("\n----------Jogo_do_Galo----------\n\n");
		imprimir(matriz);
		jogadas++;
		
		break;
	}
	
	
	
	} while(true);
	
	vencedor = ofim(matriz);
	
	//repete a verificaçao
	if(vencedor != ' ')
	{
		printf("%c ganhou", ofim(matriz));
		break;
	}
	else if(jogadas == 9)
	{
		printf("Empate");
	}
	else
	{
		
	do // segunda jogada do jogador 2
	{
	printf("\n");

	printf("\nJogador 2 : ");
	scanf("%d", &jogador2[1]);
	
	if(jogador2[1] < 1 || jogador2[1] > 9)
	{
		printf("Jogada invalida");
	}
	else if(jogador2[1] == jogador2[0] || jogador2[1] == jogador1[0] || jogador2[1] == jogador1[1])
	{
		printf("Ja foi feita uma jogada neste local!!");
	} 
	else if(jogador2[0] >= 1 || jogador2[0] <= 9 && jogador2[1] != jogador2[0] && jogador2[1] != jogador1[0] && jogador2[1] != jogador1[1])
	{
		matriz[(jogador2[1] - 1) / 3][(jogador2[1] - 1) % 3] = 'O';
		printf("\n");
		system("cls");
		printf("\n----------Jogo_do_Galo----------\n\n");
		imprimir(matriz);
		jogadas++;
		
		break;
	}
	
	
	} while(true);
	
	vencedor = ofim(matriz);
	
		//repete a verificaçao
	if(vencedor != ' ')
	{
		printf("%c ganhou", ofim(matriz));
		break;
	}
	else if(jogadas == 9)
	{
		printf("Empate");
	}
	else
	{
		
	do // terceira jogada do jogador 1
	{
	printf("\n");
	printf("\nJogador 1 : ");
	scanf("%d", &jogador1[2]);
	
	if(jogador1[2] < 1 || jogador1[2] > 9)
	{
		printf("Jogada invalida");
	}
	else if(jogador2[0] == jogador1[2] || jogador1[0] == jogador1[2] || jogador1[1] == jogador1[2] || jogador2[1] == jogador1[2])
	{
		printf("Ja foi feita uma jogada neste local!!");
	}
	else if(jogador1[1] >= 1 || jogador1[1] <= 9 && jogador2[0] != jogador1[2] && jogador1[0] != jogador1[2] && jogador1[1] != jogador1[2] && jogador2[1] != jogador1[2])
	{
		matriz[(jogador1[2] - 1) / 3][(jogador1[2] - 1) % 3] = 'X';
		printf("\n");
		system("cls");
		printf("\n----------Jogo_do_Galo----------\n\n");
		imprimir(matriz);
		jogadas++;
		
		break;
	} 
	
	
	}while(true);
	
	vencedor = ofim(matriz);
	
		//repete a verificaçao
	if(vencedor != ' ')
	{
		printf("%c ganhou", ofim(matriz));
		break;
	}
	else if(jogadas == 9)
	{
		printf("Empate");
	}
	else
	{
		
	do // terceira jogada do jogador 2
	{
	printf("\n");
	printf("\nJogador 2 : ");
	scanf("%d", &jogador2[2]);
	
	if(jogador2[2] < 1 || jogador2[2] > 9)
	{
		printf("Jogada invalida");
	}
	else if(jogador2[1] == jogador2[2] || jogador2[0] == jogador2[2] || jogador1[1] == jogador2[2] || jogador1[2] == jogador2[2] || jogador1[0] == jogador2[2] || jogador1[1] == jogador2[2])
	{
		printf("Ja foi feita uma jogada neste local!!");
	} 
	else if(jogador2[0] >= 1 || jogador2[0] <= 9 && jogador2[1] != jogador2[2] && jogador2[0] != jogador2[2] && jogador1[1] != jogador2[2] && jogador1[2] != jogador2[2] && jogador1[0] != jogador2[2] && jogador1[1] != jogador2[2])
	{
		matriz[(jogador2[2] - 1) / 3][(jogador2[2] - 1) % 3] = 'O';
		printf("\n");
		system("cls");
		printf("\n----------Jogo_do_Galo----------\n\n");
		imprimir(matriz);
		jogadas++;
		
		break;
	}
	
	
	} while(true);
	
	vencedor = ofim(matriz);
	
		//repete a verificaçao
	if(vencedor != ' ')
	{
		printf("%c ganhou", ofim(matriz));
		break;
	}
	else if(jogadas == 9)
	{
		printf("Empate");
	}
	else
	{
		
	do // quarta jogada do jogador 1
	{
	printf("\n");
	printf("\nJogador 1 : ");
	scanf("%d", &jogador1[3]);
	
	if(jogador1[3] < 1 || jogador1[3] > 9)
	{
		printf("Jogada invalida");
	}
	else if(jogador1[3] == jogador1[2] || jogador1[3] == jogador1[1] || jogador1[3] == jogador1[0] || jogador1[3] == jogador2[3] || jogador1[3] == jogador2[2] || jogador1[3] == jogador2[1] || jogador1[3] == jogador2[0])
	{
		printf("Ja foi feita uma jogada neste local!!");
	} 
	else if(jogador2[0] >= 1 || jogador2[0] <= 9 && jogador1[3] != jogador1[2] && jogador1[3] != jogador1[1] && jogador1[3] != jogador1[0] && jogador1[3] != jogador2[3] && jogador1[3] != jogador2[2] && jogador1[3] != jogador2[1] && jogador1[4] != jogador2[0]) 
	{
		matriz[(jogador1[3] - 1) / 3][(jogador1[3] - 1) % 3] = 'X';
		printf("\n");
		system("cls");
		printf("\n----------Jogo_do_Galo----------\n\n");
		imprimir(matriz);
		jogadas++;
		
		break;	
	} 
	
	
	}while(true);
	
	vencedor = ofim(matriz);
	
		//repete a verificaçao
	if(vencedor != ' ')
	{
		printf("%c ganhou", ofim(matriz));
		break;
	}
	else if(jogadas == 9)
	{
		printf("Empate");
	}
	else
	{
		
		
	do // quarta jogada do jogador 2
	{
	printf("\n");
	printf("\nJogador 2 : ");
	scanf("%d", &jogador2[3]);
	
	if(jogador2[3] < 1 || jogador2[3] > 9)
	{
		printf("Jogada invalida");
	}
	else if(jogador2[3] == jogador2[2] || jogador2[3] == jogador2[1] || jogador2[3] == jogador2[0] || jogador2[3] == jogador1[3] || jogador2[3] == jogador1[2] || jogador2[3] == jogador1[1] || jogador2[3] == jogador1[0])
	{
		printf("Ja foi feita uma jogada neste local!!");
	} 
	else if(jogador2[0] >= 1 || jogador2[0] <= 9 && jogador2[3] != jogador2[2] && jogador2[3] != jogador2[1] && jogador2[3] != jogador2[0] && jogador2[3] != jogador1[3] && jogador2[3] != jogador1[2] && jogador2[3] != jogador1[1] && jogador2[3] != jogador1[0])
	{
		matriz[(jogador2[3] - 1) / 3][(jogador2[3] - 1) % 3] = 'O';
		printf("\n");
		system("cls");
		printf("\n----------Jogo_do_Galo----------\n\n");
		imprimir(matriz);
		jogadas++;
		
		break;
	}
	
	
	} while(true);
	
	
	
	vencedor = ofim(matriz);
		//repete a verificaçao
	if(vencedor != ' ')
	{
		printf("%c ganhou", ofim(matriz));
		break;
	}
	else if(jogadas == 9)
	{
		printf("Empate");
	}
	else
	{
		
	do // quinta jogada do jogador 1
	{
	printf("\n");
	printf("Jogador 1 : ");
	scanf("%d", &jogador1[4]);
	
	if(jogador1[4] < 1 || jogador1[4] > 9)
	{
		printf("Jogada invalida");
	}
	else if(jogador1[4] == jogador1[3] || jogador1[4] == jogador1[2] || jogador1[4] == jogador1[1] || jogador1[4] == jogador1[0] || jogador1[4] == jogador2[3] || jogador1[4] == jogador2[2] || jogador1[4] == jogador2[1] || jogador1[4] == jogador2[0])
	{
		printf("Ja foi feita uma jogada neste local!!");
	} 
	else if(jogador2[0] >= 1 || jogador2[0] <= 9 && jogador1[4] != jogador1[3] && jogador1[4] != jogador1[2] && jogador1[4] != jogador1[1] && jogador1[4] != jogador1[0] && jogador1[4] != jogador2[3] && jogador1[4] != jogador2[2] && jogador1[4] != jogador2[1] && jogador1[4] != jogador2[0])
	{
		matriz[(jogador1[4] - 1) / 3][(jogador1[4] - 1) % 3] = 'X';
		printf("\n");
		system("cls");
		printf("\n----------Jogo_do_Galo----------\n\n");
		imprimir(matriz);
		jogadas++;
		
		break;
	}
	
	
	} while(true);
		//verificaçao final
	if(ofim(matriz) != ' ' || jogadas == 9)
	{
		if(ofim(matriz) != ' ')
		{
			printf("%c ganhou", ofim(matriz));
			break;
		}
		else if(ofim(matriz) == ' ')
		{
			printf("\nO Jogo Resultou num empate");
		}
		
		break;
		
	} 
	
	
		
	}
	
	
	}
	
	
	}
	
	
	}
	
	
	}
	
	
	}
	
	
	}
	
	
	}
	
	
	} while (true); //true para ser infinito e so sair com um break 
	
	
	
	
	return 0; //devolve o valor de 0
}
