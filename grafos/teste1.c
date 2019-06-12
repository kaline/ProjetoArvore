#include <stdio.h>
#include <stdlib.h>
typedef struct tipoVertice *apontadorTipoVertice; 
typedef struct tipoAresta *apontadorTipoAresta; 
 
struct tipoVertice { 
  int vertice; 
  int grau; 
  int visitado; 
  apontadorTipoVertice proximoVertice; 
  apontadorTipoAresta primeiraAresta; 
  apontadorTipoAresta ultimaAresta; 
}; 

struct tipoAresta { 
  int vertice; 
  int distancia; 
  apontadorTipoAresta proximaAresta; 
}; 
 
struct tipoGrafo { 
  apontadorTipoVertice primeiroVertice; 
  apontadorTipoVertice ultimoVertice; 
}; 
