#include <stdio.h> //comunicação com usuario
#include <stdlib.h> //espaço em memoria
#include <locale.h> //alocação de texto por região
#include <string.h> //cuidar das string

int registro() //cadastra usuarios
{	
	//criação de variaveis/string
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser registrado: "); //coletando infirmação do usuario
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //copiar valores das sting
	
	FILE *file; //CRIA O ARQUIVO
	file = fopen(arquivo, "w"); //cria arquivo "w" significa escrever
	fprintf(file,cpf); //salvar o valor da variavel
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf ("Digite o nome a ser cadastrado: ");
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf ("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);	
	fclose(file);
	
	system("pause");
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Arquivo não localizado!\n");
		system("pause");
		return;
	}
	
	while(fgets(conteudo, 200,file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
}
int deletar()
{
	char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    int resultado = remove(cpf);  // tenta deletar o arquivo

    if (resultado == 0) {
        printf("Usuário deletado com sucesso!\n");
    } else {
        printf("Usuário não encontrado!\n");
    }

    system("pause");
			
}



int main()

{
	int opcao=0; //variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system ("cls");
		
		
		setlocale(LC_ALL, "Portuguese"); //linguagem
	
		printf ("\t--Cartório da EBAC--\n\n");
		printf ("Escolha a opção desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes:\n");
		printf ("\t2 - Consultar nomes:\n");
		printf ("\t3 - Deletar nomes:\n\n");
		printf ("\t4 - Sair do sistema\n\n");
		printf ("Opção: ");
	
		scanf("%d", &opcao); //armazenando escolhas do usuario
	
		system("cls"); //limpar a tela
	
		switch(opcao) //inicio de menu
		{
			case 1:
			registro();
			break;
			
			case 2:	
			consulta();
			break;
			
			case 3:
			deletar();
			break;	
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf ("Essa opção não existe\n");
			system("pause");
			break;
			
		}
}
}
