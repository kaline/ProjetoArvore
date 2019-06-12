
    //  Programação Estruturada:Trabalho final 1
    //  Tópico:Árvore.
    //  Autor: Kaline Brandão Farias Mesquita 
    //         Calina Lídia.


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

typedef struct Node
{
    int dado;
    struct Node *root;
    struct Node *left;  // <----
    struct Node *right; // <----
} node;

// Pesquisa umm dado em uma BST
node *pesquisa(node *root, int dado)
{
    // root é null or dado está presente no root
    if (root == NULL || root->dado == dado)
        return root;

    // dado é maior que o dado do root
    if (root->dado < dado)
        return pesquisa(root->right, dado);

    // Dado é menor que o  dado do root
    return pesquisa(root->left, dado);
}

//Cria um novo node da BST
node *newNode(int item)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->dado = item;
    temp->left = temp->right = NULL;
    return temp;
}

void preorder(node *root)
{
    if (root != NULL)
    {        
         printf("%d \n", root->dado);
         preorder(root->left);
         preorder(root->right);
       
    }
}

//Cria uma BST traversal em ordem
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->dado);
        inorder(root->right);
    }
}

void porder(node *root)
{
    if (root != NULL)
    {    
        porder(root->left);
        porder(root->right);
        printf("%d \n", root->dado);
        
    }
}

//Insere um novo nodo em uma BST
node *insert(node *node, int dado)
{
    /* Se a árvore está vazia retorna um novo nodo */
    if (node == NULL)
        return newNode(dado);

    /* Caso contrário, percorrer a árvore */
    if (dado < node->dado)
        node->left = insert(node->left, dado);
    else if (dado > node->dado)
        node->right = insert(node->right, dado);

    /* retorna o (estático)  ponteiro node */
    return node;
}

int main();

int menu(node* root)
{
    printf("************** MENU **************\n");
    printf("1. Ordenar\n");
    printf("2. Pesquisar\n");
    printf("3. Nova arvore\n");
    printf("4. Sair\n");
    printf("Escolha: ");

    fflush(stdin);
    char opcao = getchar();
    switch (opcao)
    {
    case '1':
        inorder(root);
        break;
    case '2':
        printf("Digite o numero que voce quer pesquisar:\n");
        
        int procura;
        scanf("%d", &procura);

        node *nodePesquisa = pesquisa(root, procura);

        if (nodePesquisa == NULL)
        {
            printf("O dado digitado nao foi encontrado. Poderia digitar novamente? (S/N)");
            fflush(stdin);
            char resp = getchar();
            if (resp == 'S')
            {
                printf("Loading...");
                return menu(root);
            }
            else
            {
                return 0;
            }
        }
        else
        {
            printf("O numero encontrado e: %d\n", procura);
        }

        break;
    case '3':
        return main();
    case '4':
        return 0;
    }

    menu(root);
}

int main()
{
    system("cls");
    setlocale(LC_ALL, "pt_BR");
    int n;
    FILE * pFile;

    pFile = fopen("arvoreData.txt", "w");

    printf("Digite o tamanho da sua arvore:\n");
    node *root = NULL;
    scanf("%d", &n);
    printf("Digite os elementos da arvore:\n");
    for (int i = 0; i < n; i++)
    {
        int dado1;
        scanf("%d", &dado1);
             fprintf(pFile, "Dado %d %d\n",i+1, dado1);

        if (root == NULL)
        {
            root = insert(root, dado1);
        }
        else
        {
            insert(root, dado1);
        }
    }
    fclose(pFile);
    menu(root);
    return 0;
}
