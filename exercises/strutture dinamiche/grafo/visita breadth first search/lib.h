#ifndef VISITA_BREADTH_FIRST_SEARCH_LIB_H
#define VISITA_BREADTH_FIRST_SEARCH_LIB_H

#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

typedef enum{false,true} boolean;

struct queue { // implemento una struct che fungerà da queue, che contiene i nodi e la testa e il fondo
	int items[SIZE];
	int head;
	int bottom;
};

// implemento una struct per il singolo nodo che contiene il campo vertice e il puntatore al nodo successivo
struct node {
	int vertex;
	struct node *next;
};

/* implemento una struct per l'intera struttura del grafo, che contiene il numero dei vertici, un array per
controllare se i nodi del grafo sono già stati visitati e un doppio puntatore di tipo struct nodo per puntare
alla lista di adiacenze dei nodi del grafo */
struct Graph {
	int numVertices;
	boolean* visited;
	struct node** adjLists;
};

void BFS_visit(struct Graph *graph, int startVertex);
struct node* create_node(int);
struct Graph* create_graph(int);
void add_edge(struct Graph *graph, int x, int y);
struct queue* create_queue();
void enqueue(struct queue*, int);
int dequeue(struct queue*);
void display(struct queue*);
boolean is_empty(struct queue *q);
void print_queue(struct queue *q);

#endif //VISITA_BREADTH_FIRST_SEARCH_LIB_H
