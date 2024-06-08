#include "lib.h"

int main() {
	struct Graph* graph;
	int num_vertices, num_edges, vertex_1, vertex_2;

	printf("Inserire il numero di vertici del grafo -> ");
	scanf("%d", &num_vertices);
	graph = create_graph(num_vertices);

	printf("\nInserire il numero di archi -> ");
	scanf("%d", &num_edges);

	/* imposto un ciclo for per inserire il numero di archi precedentemente immesso in input tra due vertici che
	andiamo ad inserire ad ogni iterazione del ciclo, in cui alla fine richiamiamo la funzione per l'aggiunta di
	un arco */
	for(int i = 0; i < num_edges; i++) {
		printf("\nInserire i due vertici da congiungere");
		printf("\n\tVertice 1 -> ");
		scanf("%d", &vertex_1);
		fflush(stdin);
		printf("\tVertice 2 -> ");
		scanf("%d", &vertex_2);
		add_edge(graph, vertex_1, vertex_2);
	}

	BFS_visit(graph, 2);

	return 0;
}