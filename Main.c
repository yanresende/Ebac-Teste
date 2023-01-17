#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()//Função responsavel por cadastrar os usuários no sistema
{
setlocale (LC_ALL, "Portuguese_Brasil.1252"); //Definindo a linguagem

    //Inicio da criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da criação de variáveis/string

    printf("Digite o cpf a ser cadastrado:");//colentando informção do usuário
    scanf("%s", cpf);//%s refere-se a string

    strcpy(arquivo, cpf);

    FILE *file; //cria o arquivo
    file = fopen(arquivo,"w");//cria o arquivo, w significa escrever
    fprintf(file,cpf);//salvo o valor da variavel
    fclose(file);//fecha o arquivo

    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);

    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);

    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);

    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);

    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);

    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);

    system("pause");

}
int consulta()
{
    setlocale (LC_ALL, "Portuguese_Brasil.1252"); //Definindo a linguagem
    char cpf[40];
    char conteudo[200];
    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file=fopen(cpf,"r"); //r significa ler
    if(file == NULL)
    {
        printf("Não foi possivel abrir abrir o arquivo, não localizado! \n ");
    }

    while(fgets(conteudo,200,file)!=NULL)
    {
        printf("\nEssas são as informações do usuario: ");
        printf("%s", conteudo);
        printf("\n\n");
    }

    fclose(file);

    system("pause");

}
int deletar()
{
    char cpf[40];

    printf("Digite o CPF do usuário a ser deletado: ");
    scanf("%s",cpf);

    remove(cpf);

    FILE*file;
    file = fopen(cpf,"r");
    if(file == NULL)
    {
        printf("O usuário não se encontra no sistema!.\n");
        system("pause");
    }
    fclose(file);

}



int main()
{
    int opcao =0;
    int laco=1;

    for(laco=1;laco=1;)
    {

    setlocale (LC_ALL, "Portuguese_Brasil.1252"); //Definindo a linguagem
    printf("### Cartório da EBAC ###\n\n");
    printf("Escolha a opção desejada do menu:\n\n");
    printf("\t1 - Registrar nomes\n");
    printf("\t2 - Consultar nomes\n");
    printf("\t3 - Deletar nomes\n");
    printf("\t4 - Sair do sistema\n");
    printf("Opção: ");

    scanf("%d", &opcao); //armazena a escolha do usuario

    system("cls");//responsavel para limpar a tela

    switch(opcao)
    {
    case 1:
        registro();
        system("cls");
        break;

    case 2:

    consulta();
    system("cls");
    break;

    case 3:
    deletar();
    system("cls");
    break;

    case 4:
        printf("Obrigado por utilizar o sistema!\n");
        return 0;
        break;

    default:
        printf("Essa opção não está disponivel!\n");
        system("pause");
        system("cls");
        break;
    }
    }
}
