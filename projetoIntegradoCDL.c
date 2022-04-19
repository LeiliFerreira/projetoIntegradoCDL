#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

void forca(int estado) {
	if(estado ==0) {
		printf("----------\n" );
		printf("|        |\n" );
		printf("|         \n" );
		printf("|         \n" ); 
		printf("|         \n" );
		printf("|         \n" );
		printf("|         \n" );
		printf("|         \n" );		
	}

	if(estado ==1) {
		printf("----------\n" );
		printf("|        |\n" );
		printf("|        O\n" );
		printf("|         \n" ); 
		printf("|         \n" );
		printf("|         \n" );
		printf("|         \n" );
		printf("|         \n" );		
	}

	else if(estado==2) {
		 printf("---------- \n" );
		 printf("|        | \n" );
		 printf("|        O \n" );
		 printf("|        | \n" ); 
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );	
	}

	else if(estado==3) {
		 printf("---------- \n" );
		 printf("|        | \n" );
		 printf("|        O \n" );
		 printf("|       /| \n" ); 
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );	
	}

	else if(estado==4) {
		 printf("---------- \n" );
		 printf("|        | \n" );
		 printf("|        O \n" ); 
		 printf("|       /|\\\n" ); 
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );	
	}
	
	else if(estado==5) {
		 printf("---------- \n" );
		 printf("|        | \n" );
		 printf("|        O \n" );
		 printf("|       /|\\\n" ); 
		 printf("|       /  \n" );
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("|          \n" );	
	}
	
	else if(estado==6) {
		 printf("---------- \n" );
		 printf("|        | \n" );
		 printf("|        O \n" );
		 printf("|       /|\\\n" ); 
		 printf("|       / \\\n" );
		 printf("|          \n" );
		 printf("|          \n" );
		 printf("| Você perdeu!\n" );
		
	}
}

int main_forca(void) {
	setlocale(LC_ALL,"Portuguese");
	system("cls");
	printf("----JOGO DA FORCA----\n\n"); 
	sleep(1); 
	printf("- Sorteando palavra...\n"); 
	sleep(3); 
	printf("- Preparando forca...\n"); 
	sleep(3); 
	printf("- Começando em...\n"); 
	sleep(1); 
	printf("3\n");
	sleep(1); 
	printf(" 2\n"); 
	sleep(1); 
	printf("  1...");
	sleep(1); 
	
	fflush(stdin);	
	char bancoPalavras[10][30] = {"abacate", "caracol", "notbook", "programar", "laranja", "sushi", "internet", "cpu", "python", "computador"}; 
	char palavra[30];
	int c,i,a,b;
	int num=0;
	char palavraTela[30]; 
	int erros =0; 
	int errouLetra = 1; 
	char letra; 

	srand(time(NULL));
	num = rand() % 9;
	for(c=0;c<10;c++){
	palavra[c]=bancoPalavras[num][c];
	}
	system("cls");

	palavra[strlen(palavra)] = '\0'; 
	strcpy(palavraTela, palavra); 
	
	for(i=0;i<strlen(palavraTela);i++){
	palavraTela[i] = '_'; 
	}
 
	while(1){
		forca(erros); 
		printf("\nAdivinhe: "); 
		for(a=0;a<strlen(palavraTela);a++){
			printf("%c ", palavraTela[a]); 
		}
	
		printf("\nLetra: "); 
		scanf(" %c", &letra); 
		
		int errouLetra = 1; 
		int b; 
		for(b = 0; b<strlen(palavraTela);b++) {
		if(letra == palavra[b]) {
			palavraTela[b] = letra; 
			errouLetra = 0; 		
		}
	}
	
	if (errouLetra == 1) {
		erros++; 
	}
		
	if(strcmp(palavraTela,palavra)==0) {
		printf("\nVocê venceu! Parabéns!!!!");
		printf("\n---------------------------");
		printf("\nResposta: %s", &palavra);
		
		int jogarNovamente; 
		printf("\n\nJogar novamente? 1 - sim / 2 - não: "); 
		scanf("%d", &jogarNovamente); 
	
   		while (jogarNovamente != 1 && jogarNovamente != 2) {
			
			printf("\nOpção inválida!!!");
			printf("\n\nJogar novamente? 1 - sim / 2 - não: "); 
			scanf("%d", &jogarNovamente); 
		}
	
		if (jogarNovamente == 1) {
			return main_forca();
		} else if (jogarNovamente == 2) {
			return main();
		}
	}
		
	if (erros == 6){
		forca(erros);
		printf("\n---------------------------");
		printf("\nResposta: %s", &palavra);
		
	int jogarNovamente; 
		printf("\n\nJogar novamente? 1 - sim / 2 - não: "); 
		scanf("%d", &jogarNovamente); 
	
   		while (jogarNovamente != 1 && jogarNovamente != 2) {
			
			printf("\nOpção inválida!!!");
			printf("\n\nJogar novamente? 1 - sim / 2 - não: "); 
			scanf("%d", &jogarNovamente); 
		}
	
		if (jogarNovamente == 1) {
			return main_forca();
		} else if (jogarNovamente == 2) {
			return main();
			}
		}
	}
}

char jogo[3][3];
char jogador1[50], jogador2[50];

void inicializarMatriz() {
    int i,j;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            jogo[i][j] = ' ';
        }
    }
}

int eValido(char letra) {
    if(letra == 'x' || letra == '0')
        return 1;
    else
        return 0;
}

int coordenadaEhValida(int x, int y) {
    if(x >= 0 && x < 3) {
        if(y >= 0 && y < 3)
            return 1;
    }
    return 0;
}

int posicaVazia(int x, int y) {
    if(jogo[x][y] != 'x' && jogo[x][y] != '0')
        return 1;
    return 0;
}

int ganhouLinhas() {
    int i, j, igual = 1;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            if(eValido(jogo[i][j]) && jogo[i][j] == jogo[i][j+1])
                igual++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;
}

int ganhouColunas() {
    int i, j, igual = 1;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 2; j++) {
            if(eValido(jogo[j][i]) && jogo[j][i] == jogo[j+1][i])
                igual++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;
}

int ganhoudiagPrincipal() {
    int i, igual = 1;
    for(i = 0; i < 2; i++) {
        if(eValido(jogo[i][i]) && jogo[i][i] == jogo[i+1][i+1])
            igual++;
    }
    if(igual == 3)
        return 1;
    else
        return 0;
}

int ganhoudiagSecundaria() {
    int i, igual = 1;
    for(i = 0; i < 2; i++) {
        if(eValido(jogo[i][3-i-1]) && jogo[i][3-i-1] == jogo[i+1][3-i-2])
            igual++;
    }
    if(igual == 3)
        return 1;
    else
        return 0;
}

void imprimir() {
    int lin, col;

    printf("\n\t    0  1  2\n");
    for(lin = 0; lin < 3; lin++) {
        printf("\t%d ", lin);
        for(col = 0; col < 3; col++) {
            if(col < 2)
                printf(" %c |", jogo[lin][col]);
            else
                printf(" %c ", jogo[lin][col]);
        }
        if(lin < 2)
            printf("\n\t   ---------\n");
    }
}

void jogar() {
    int x, y, valida, jogadas = 0, ganhou = 0, ordem = 1;

    do {
        do {
            imprimir();
            printf("\nDigite a coordenada que deseja jogar: ");
            scanf("%d%d", &x, &y);
            valida = coordenadaEhValida(x, y);
            if(valida == 1)
                valida += posicaVazia(x, y);
        } while(valida != 2);
        if(ordem == 1)
            jogo[x][y] = 'x';
        else
            jogo[x][y] = '0';
        jogadas++;
        ordem++;
        if(ordem == 3)
            ordem = 1;
        ganhou += ganhouLinhas();
        ganhou += ganhouColunas();
        ganhou += ganhoudiagPrincipal();
        ganhou += ganhoudiagSecundaria();
    } while(ganhou == 0 && jogadas < 9);

   	if(ganhou != 0) {
        imprimir();
        if(ordem - 1 == 1)
            printf("\n\nJogador X venceu!!!\n", jogador1);
        else
            printf("\n\nJogador 0 venceu!!!!\n", jogador2);
    } else
        printf("\nQue feio. Ninguem venceu!\n\n");
}

int main_velha() {

    int op;	
	char jogador1[50]; 
	char jogador2[50];
	
	system("cls"); 
	printf("**** Jogo da Velha *****"); 
    printf("\n\nJogador X digite seu nome: ");
    scanf("%s", jogador1); 
    printf("Jogador 0 digite seu nome: ");
   	scanf("%s", jogador2);

   	inicializarMatriz();
    jogar();
       
    int jogarNovamente; 
	printf("\n\nJogar novamente? 1 - sim / 2 - não: "); 
	scanf("%d", &jogarNovamente); 
	
   	while (jogarNovamente != 1 && jogarNovamente != 2) {
		printf("\nOpção inválida!!!");
		printf("\n\nJogar novamente? 1 - sim / 2 - não: "); 
		scanf("%d", &jogarNovamente); 
		}
	
		if (jogarNovamente == 1) {
			return main_velha();
		} else if (jogarNovamente == 2) {
			return main();
			}
		}
    
int main_jkp()
{
 int cpu;
 char jogador;
 char nome[20];
 char desejaJogarDeNovo='1';
 
 system("cls"); 
 printf("\n\n** BEM VINDO AO JOKENPO **"); 
 printf("\n\n   Regras:\n 1. Vence o melhor de 3 jogadas!\n 2. Pedra ganha de tesoura!\n 3. Papel vence de  pedra!\n 4. Tesoura vence de papel\n");
 printf("\n\nDigite seu nome:");
 scanf("%s",nome);
    
 system("cls");
 
while(desejaJogarDeNovo=='1')
{
  int pontos_jogador=0, pontos_cpu=0;
  
 while( (pontos_jogador + pontos_cpu) < 3)
 {
     
    system("cls");   
    printf ("\n-------------------------JokenPo---------------------------\n\n");
    printf ("                   %d %s X CPU %d\n", pontos_jogador,nome, pontos_cpu);
    printf ("\n-----------------------------------------------------------\n");
    printf ("0. Pedra\n");
    printf ("1. Papel\n");
    printf ("2. Tesoura\n");
    jogador = getch();
    srand(time(NULL));
    cpu = rand() % 3; 
    switch(cpu)
    {
        case 0: printf ("\n\nCPU = Pedra"); break;
        case 1: printf ("\n\nCPU = Papel"); break;
        case 2: printf ("\n\nCPU = Tesoura"); 
    }
     switch(jogador)
    {
        case '0': printf ("\n%s = Pedra\n",nome); break;
        case '1': printf ("\n%s = Papel\n",nome); break;
        case '2': printf ("\n%s = Tesoura\n",nome); break;
    }
    
    if(jogador > '2')
    {
               printf("\n\n     Você escolheu uma opção invalida, escolha novamente!\n\n");
                  
                    switch(jogador)
    {
        case '0': printf ("\n%s = Pedra\n",nome); break;
        case '1': printf ("\n%s = Papel\n",nome); break;
        case '2': printf ("\n%s = Tesoura\n",nome); break;
    }
    
    }
    else
    {
    
    if ((jogador == '0' && cpu==2) || (jogador == '1' && cpu == 0) || (jogador == '2' && cpu == 1)) 
    {
            printf("\n\n     %s venceu!\n\n", nome);
            printf ("\n\n   Placa atualiza na proxima rodada, aperte qualquer tecla para continuar jogando ou x, alt+f4 para fechar!\n\n");
            pontos_jogador++;
    }
    else
    {
		if ((jogador == '0' && cpu == 0) || (jogador == '1' && cpu == 1) || (jogador == '2' && cpu == 2)) 
           {
           printf ("\n\n    Empate!\n\n");
           printf ("\n\n   Placa atualiza na proxima rodada, aperte qualquer tecla para continuar jogando ou x, alt+f4 para fechar!\n\n");
            pontos_jogador++;
            pontos_cpu++;
            }
        else
        {
            printf ("\n\n   CPU venceu!\n\n");
             printf ("\n\n   Placa atualiza na proxima rodada, aperte qualquer tecla para continuar jogando ou x, alt+f4 para fechar!\n\n");
            pontos_cpu++;
        }
    }
}
  getch();
 }
    system("cls");   
    printf ("\n-------------------------JokenPo---------------------------\n\n");
    printf ("                   %d %s X CPU %d\n", pontos_jogador,nome, pontos_cpu);
    printf ("\n-----------------------------------------------------------\n");
  if(pontos_jogador>pontos_cpu)
     printf("\n\n     %s venceu a melhor de 3!",nome);
  else
     printf("\n\n     CPU venceu a melhor de 3!");
     
     	int jogarNovamente; 
		printf("\n\nJogar novamente? 1 - sim / 2 - não: "); 
		scanf("%d", &jogarNovamente); 
	
   		while (jogarNovamente != 1 && jogarNovamente != 2) {
			
			printf("\nOpção inválida!!!");
			printf("\n\nJogar novamente? 1 - sim / 2 - não: "); 
			scanf("%d", &jogarNovamente); 
		}
	
		if (jogarNovamente == 1) {
			return main_jkp();
		} else if (jogarNovamente == 2) {
			return main();
			}
		}
	}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	int opcaoMenu;
	system("cls"); 
	printf("****** Bem-vindos ao FCDL-Games ******\n\n");
	printf("************* J O G O S *************\n");
	printf("1 - Forca\n"); 
	printf("2 - Jogo da Velha\n"); 
	printf("3 - JokenPo\n"); 
	printf("4 - Sair\n"); 
	printf("*************************************\n"); 
	printf("Digite sua opção:"); 
	scanf("%d", &opcaoMenu); 
	
	switch (opcaoMenu)
	{
		case 1:  
			main_forca();
		case 2: 
			main_velha();
		case 3: 
			main_jkp();
		case 4: 
			printf("\n Você saiu, até a proxima!! \n");
			break; 
		default:
			printf("\nOpção inválida!!!"); 
			sleep(2); 
			return main(); 
		}
	}

