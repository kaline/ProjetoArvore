// bintree.c
// fonte original:https://www.cprogramming.com/tutorial/c/lesson18.html
// gcc -Wall bintree.c -o bintree
#include <stdio.h>
#include <stdlib.h>

/*
 * o primeiro passo é definir uma estrutura pra representar os nós da árvore
 */
struct node
{
  int key_value;
  struct node *left;
  struct node *right;
};

/*
 * aqui a inserção clássica. 
 * 
 * se nó vazio, inicializa.
 *
 * se já existente, verificamos o valor da chave pra saber se é pra jogar no
 * galho esquerdo ou no galho direito.
 *
 * o ponteiro duplo é só pra ter o luxo de inicializar o nó caso ele venha 
 * vazio.
 */
void insert(int key, struct node **leaf)
{
    if( *leaf == 0 )
    {
        *leaf = (struct node*) malloc( sizeof( struct node ) );
        (*leaf)->key_value = key;
        /* initialize the children to null */
        (*leaf)->left = 0;    
        (*leaf)->right = 0;  
    }
    else if(key < (*leaf)->key_value)
    {
        insert( key, &(*leaf)->left );
    }
    else if(key > (*leaf)->key_value)
    {
        insert( key, &(*leaf)->right );
    }
}

/*
 * função pra mostrar como destruir a árvore inteira. posto que usamos  o 
 * malloc() pra inicializar os nós, devemos destruí-los com o free() pois
 * isso é a lei.
 */
void destroy_tree(struct node *leaf)
{
  if( leaf != 0 )
  {
      destroy_tree(leaf->left);
      destroy_tree(leaf->right);
      free( leaf );
  }
}

/*
 * a busca devolve um nó. como entrada você deve dar a chave que procura eo
 * nó raíz. deveolve o nó contendo a chave, se existir, ou nulo/zero	
 */
struct node *search(int key, struct node *leaf)
{
  if( leaf != 0 )
  {
      if(key==leaf->key_value)
      {
          return leaf;
      }
      else if(key<leaf->key_value)
      {
          return search(key, leaf->left);
      }
      else
      {
          return search(key, leaf->right);
      }
  }
  else return 0;
}

/*
 * aqui no ponto de entrada, um exemplo. vamos inserir 7 números
 */
int main(int argc, char **argv)
{

	// inicializamos a árove com um nó vazio
	struct node *root = 0;
	
	// inserimos alguns valores (aqui você podia dar uns scanf)
	insert(1,&root);
	insert(10,&root);
	insert(3,&root);
	insert(5,&root);
	insert(7,&root);
	insert(11,&root);
	insert(2,&root);
	
	// e por fim fazemos umas buscas de exemplo, duas que existem, uma inexistente
	struct node *n;
	n = search(3,root);
	if(n)
		printf("encontrei o %d!\n",n->key_value);
	n = search(7,root);
	if(n)
		printf("encontrei o %d!\n",n->key_value);
	n = search(15,root);
	if(n)
		printf("encontrei o %d!\n",n->key_value);
	else
		printf("chave %d não encontrada.\n",15);
	
	return 0;
}
