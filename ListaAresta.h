//
// Created by fernando on 28/03/2021.
//

#ifndef TRABED2___2020_2_LISTAARESTA_H
#define TRABED2___2020_2_LISTAARESTA_H

#include "Aresta.h"

typedef struct listaAresta ListaAresta;

ListaAresta* iniciaListaAresta();
ListaAresta* adicionaAresta(ListaAresta* lista, Aresta* aresta);
void imprimeLista(ListaAresta * lista);

#endif //TRABED2___2020_2_LISTAARESTA_H
