#include <stdio.h>
#include <stdlib.h>

// Cria a célula cabeça da lista de vértices: 
// 1. cria uma célula do tipoVertice colocando o endereço no campo primeiroVertice do Grafo 
// 2. incializa os campos do tipoVertice: vertice, grau, proximoVertice, primeiraAresta e  
//    ultimaAresta com valores nulos 
// 3. o apontador ultimoVertice recebe o endereço da célula cabeça 
void fazGrafoVazio(struct tipoGrafo *grafo) { 
  grafo->primeiroVertice = (apontadorTipoVertice)malloc(sizeof(tipoVertice)); 
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
