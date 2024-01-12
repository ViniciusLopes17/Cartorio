#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h.> //biblioteca de alocações de textos por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro(){ //Função responsável por cadastrar os usuários do sistema
	
	//início da criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: ");//coletando informações do usuário
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo, cpf);//Responsável por copiar os valores das strings

	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" refere-se a "write"
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o Nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//atualiza o arquivo
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");//atualiza o arquivo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o Sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");//atualiza o arquivo
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");//atualiza o arquivo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");//atualiza o arquivo
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");

}

int consulta(){
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Consulte o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("O Arquivo não foi localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar(){
	
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF a ser Deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}


int main(){
	int opcao = 0; //Definindo Variáveis
	int laco = 1;
	
	for(laco = 1; laco = 1;){
		
		system("cls");//responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese");//Definindo a Linguagem
	
		printf("### Cartório da EBAC ### \n\n");//Início do Menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: ");//Fim do Menu
	
		scanf("%d", &opcao);//Armazenando a escolha do usuário
	
		system("cls");//responsável por limpar a tela
		
		switch(opcao){
			case 1:
			registro();//chamada de funções
			break;
			
			case 2: 
			consulta();
			break;
			
			case 3: 
			deletar();
			break;
			 
			case 4: 
			printf("Obrigado por utilizar o sistema!\n");
			system("pause");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		}
	}
}
