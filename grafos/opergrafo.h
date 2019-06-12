#include <stdio.h>
#include <stdlib.h>
#include "teste1.h"

// Cria a célula cabeça da lista de vértices: 
// 1. cria uma célula do tipoVertice colocando o endereço no campo primeiroVertice do Grafo 
// 2. incializa os campos do tipoVertice: vertice, grau, proximoVertice, primeiraAresta e  
//    ultimaAresta com valores nulos 
// 3. o apontador ultimoVertice recebe o endereço da célula cabeça 
void fazGrafoVazio(struct tipoGrafo *grafo) { 
  grafo->primeiroVertice = (apontadorTipoVertice)malloc(sizeof(struct tipoVertice)); 
  grafo->primeiroVertice->vertice = -1; 
  grafo->primeiroVertice->grau = -1; 
  grafo->primeiroVertice->proximoVertice = NULL; 
  grafo->primeiroVertice->primeiraAresta = NULL; 
  grafo->primeiroVertice->ultimaAresta = NULL; 
  grafo->ultimoVertice = grafo->primeiroVertice; 
} 
 
// verifica se o Grafo está vazio (sem nenhum vértice) 
int grafoVazio(struct tipoGrafo *grafo) { 
  return(grafo->primeiroVertice == grafo->ultimoVertice); 
} 
 
// retorna o endereço do "vertice" (NULL se o vértice não for localizado) 
apontadorTipoVertice localizaVertice(int vertice, struct tipoGrafo *grafo) { 
  apontadorTipoVertice p = grafo->primeiroVertice->proximoVertice; 
  while ((p != NULL) && (p->vertice != vertice)) { 
    p = p->proximoVertice; 
  } 
  return(p); 
} 


// Cria a célula cabeça da lista de adjacências do vértice: 
// 1. cria uma célula do tipoAresta colocando o endereço no campo primeiroAresta do vértice 
// 2. incializa os campos do tipoAresta: vertice, distancia e proximaAresta com valores nulos 
// 3. o apontador ultimoAresta recebe o endereço da célula cabeça 
void fazListaAdjacenciasVazia(apontadorTipoVertice vertice) { 
  vertice->primeiraAresta = (apontadorTipoAresta)malloc(sizeof(struct tipoAresta)); 
  vertice->primeiraAresta->vertice = -1; 
  vertice->primeiraAresta->distancia = -1; 
  vertice->primeiraAresta->proximaAresta = NULL; 
  vertice->ultimaAresta = vertice->primeiraAresta; 
} 
 
// verifica se a lista de adjacências do vértice está vazia 
int listaAdjacenciasVazia(apontadorTipoVertice vertice) { 
  return(vertice->primeiraAresta == vertice->ultimaAresta); 
} 
 
// retorna o endereço da "aresta" na lista de adjacências do vértice (NULL se a aresta 
// não for localizada) 
apontadorTipoAresta localizaAresta(apontadorTipoVertice vertice, int aresta) { 
  apontadorTipoAresta p = vertice->primeiraAresta->proximaAresta; 
  while ((p != NULL) && (p->vertice != aresta)) { 
    p = p->proximaAresta; 
  } 
 
  return(p); 
} 


// Insere um novo vértice no final da lista de vértices: 
// 1. cria uma nova célula colocando-a no final da lista (campo ultimoVertice) 
// 2. atualiza o apontador ultimoVertice 
// 3. armazena o valor do vértice no campo correspondente 
// 4. inicializa o grau do vértice com o valor zero 
// 5. faz a nova célula através do campo proximoVertice apontar para o vazio 
// 6. faz a lista de adjacências do novo vértice vazia  
void insereVertice(int vertice, struct tipoGrafo *grafo) { 
  grafo->ultimoVertice->proximoVertice = (apontadorTipoVertice)malloc(sizeof(struct tipoVertice)); 
  grafo->ultimoVertice = grafo->ultimoVertice->proximoVertice; 
  grafo->ultimoVertice->vertice = vertice; 
  grafo->ultimoVertice->grau = 0; 
  grafo->ultimoVertice->proximoVertice = NULL; 
  fazListaAdjacenciasVazia(grafo->ultimoVertice); 
} 
 
// Insere uma nova aresta no final da lista de adjacências do vértice de origem: 
// 1. cria uma nova célula colocando-a no final da lista de adjacências (campo ultimaAresta) 
// 2. atualiza o apontador ultimaAresta 
// 3. armazena o valor do vértice destino da aresta no campo correspondente 
// 4. armazena a distância da aresta 
// 5. faz a nova célula através do campo proximoAresta apontar para o vazio 
// 6. atualiza o grau do vértice de origem  
void insereAresta(apontadorTipoVertice verticeOrigem, int verticeDestino, int distancia) { 
  verticeOrigem->ultimaAresta->proximaAresta = (apontadorTipoAresta)malloc(sizeof(struct tipoAresta)); 
  verticeOrigem->ultimaAresta = verticeOrigem->ultimaAresta->proximaAresta; 
  verticeOrigem->ultimaAresta->vertice = verticeDestino; 
  verticeOrigem->ultimaAresta->distancia = distancia; 
  verticeOrigem->ultimaAresta->proximaAresta = NULL; 
 
  verticeOrigem->grau = verticeOrigem->grau + 1; 
} 

// No processo para remover uma célula em listas encadeadas com apontadores é realizado usando como 
// referência o endereço da célula "anterior" àquela que efetivamente será removida. 
 
// retorna o endereço da célula "anterior" a aresta do vértice que será removida 
apontadorTipoAresta localizaArestaAnterior(apontadorTipoVertice vertice, int aresta) { 
  apontadorTipoAresta pAnt = vertice->primeiraAresta; 
  apontadorTipoAresta p = vertice->primeiraAresta->proximaAresta; 
  while ((p != NULL) && (p->vertice != aresta)) { 
    pAnt = p; 
    p = p->proximaAresta; 
  } 
 
  return(pAnt); 
} 
 
// remove a "próxima" aresta de "p" da lista de adjacência de "pVertice": 
// 1. "q" recebe o endereço da aresta que será devolvido ao sistema de gerenciamento de memória 
// 2. a aresta anterior aponta para a próxima aresta àquela que será removida 
// 3. verifica se a aresta que será removida não é a última aresta da lista de adjacências 
// 4. atuliza o grau do vértice 
// 5. libera (free) o endereço da aresta removida 
// void removeAresta(apontadorTipoAresta p, apontadorTipoVertice pVertice) { 
//   apontadorTipoAresta q = p->proximaAresta; 
 
//   p->proximaAresta = q->proximaAresta; 
// //  se retirando a última aresta da lista de adjacencias 
//   if (p->proximaAresta == NULL) 
//      pVertice->ultimaAresta = p; 
 
//   struct Vertice->grau = pVertice->grau - 1; 
 
//   free(q); // libera a memória ocupada pela aresta 
// } 
