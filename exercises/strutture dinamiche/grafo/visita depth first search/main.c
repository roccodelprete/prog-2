#include <stdio.h>
#include <stdlib.h>

// implemento una struct per il singlo nodo che contiene il campo vertice e il puntatore al nodo successivo
struct node {
	int vertex;
	struct node* next;
};

typedef enum {false, true} boolean;

/* implemento una struct per l'intera struttura del grafo, che contiene il numero dei vertici, un array per
controllare se i nodi del grafo sono già stati visitati e un doppio puntatore di tipo struct nodo per puntare
alla lista di adiacenze dei nodi del grafo */
struct Graph {
	int num_vertices;
	boolean *visited;
	struct node** vicinity_list;
};

// implemento una procedura per visita Depth First Search(visita_DFS) all'interno di un grafo
void visita_DFS(struct Graph* graph, int vertex) {
	/* dichiaro e inizializzo un puntatore alla struttura nodo al valore della lista di adiacenze del vertice
	passato dal chiamante */
	struct node* temp = graph->vicinity_list[vertex];

	graph->visited[vertex] = true;             // il nodo che stiamo visitando viene settato come visitato
	printf("\nNodo visitato %d\n",vertex); // visualizziamo il nodo visitato

	while(temp != NULL) { // fin quando la lista di adiacenze non è finita
		// dichiaro e inizializzo una variabile al valore del vertice del nodo corrente
		int connectedVertex = temp->vertex;
		if(graph->visited[connectedVertex] == false)    // se il nodo corrente non è stato ancora visitato
			visita_DFS(graph, connectedVertex); // allora autoattivo la procedura di visita_DFS al nodo corrente
		temp = temp->next; // aggiorno il nodo al nodo successivo
	}
}

// implemento una function per la creazione di un nodo a partire dalla posizione del vertice
struct node* create_node(int v) {
	struct node* newNode = malloc(sizeof(struct node)); // dichiaro e inizializzo un nuovo nodo
	newNode->vertex = v; // che avrà come vertice il valore passato dal chiamante
	newNode->next = NULL; // il puntatore al nodo successivo viene inizializzato a NULL
	return newNode; // ritorno il nuovo nodo
}

// implemento una function per la creazione di un grafo a partire dal numero di vertici
struct Graph* create_graph(int num_vertex) {
	struct Graph* graph = malloc(sizeof(struct Graph));
	// dichiaro e alloco dinamicamente la struttura del grafo

	graph->num_vertices = num_vertex; // che avrà come numero di vertici il valore passato dal chiamante
	// dichiaro e alloco dinamicamente la struttura delle liste delle adiacenze
	graph->vicinity_list = malloc(num_vertex * sizeof(struct node*));
	// dichiaro e alloco dinamicamente l'array che contiene il flag sulla visita di un nodo
	graph->visited = malloc(num_vertex * sizeof(boolean));

	/* imposto un ciclo for per inizializzare la lista di adiacenze di ogni nodo a NULL e per inizializzare il flag
	sulla visita a false */
	for(int i = 0; i < num_vertex; i++) {
		graph->vicinity_list[i] = NULL;
		graph->visited[i] = false;
	}
	return graph; // ritorno il grafo
}

// implemento una procedura per l'inserimento di un arco all'interno del grafo
void addEdge(struct Graph* graph, int x, int y) {
	struct node* newNode = create_node(y); // creo un nodo tramite la function create_node a cui passo un vertice
	/* il nodo appena creato punterà al nodo con cui forma un arco e che di conseguenza fa parte della sua lista
	di adiacenze */
	newNode->next = graph->vicinity_list[x];
	graph->vicinity_list[x] = newNode; // aggiunge alla lista di adiacenze del vertice x il nuovo nodo creato

	// ripete la stessa operazione invertendo i vertici, in modo da farli risultare adiacenti per entrambi i vertici
	newNode = create_node(x);
	newNode->next = graph->vicinity_list[y];
	graph->vicinity_list[y] = newNode;
}

// implemento una procedura per visualizzare a schermo il grafo
void printGraph(struct Graph* graph) {
	for(int i = 0; i < graph->num_vertices; i++) { // imposto un ciclo for per far stampare tutte le liste di adiacenze
		struct node* temp = graph->vicinity_list[i];
		printf("\nLista di adiacenze del vertice %d\n ", i);
		// visita un vertice fin quando non si è raggiunta la fine per stampare la lista di adiacenze di ogni nodo
		while(temp != NULL) {
			printf("%d -> ", temp->vertex);
			temp = temp->next; // aggiorno il puntatore al nodo successivo
		}
		printf("\n");
	}
}

int main() {
	struct Graph* graph;
	int num_vertices, num_edges, vertex_1, vertex_2;

	printf("Inserire il numero di vertici del grafo -> ");
	scanf("%d",&num_vertices);
	fflush(stdin);
	graph = create_graph(num_vertices);

	printf("\nInserire numero archi -> ");
	scanf("%d",&num_edges);
	fflush(stdin);

	/* imposto un ciclo for per inserire il numero di archi precedentemente immesso in input tra due vertici che
	andiamo ad inserire ad ogni iterazione del ciclo, in cui alla fine richiamiamo la funzione per l'aggiunta di
	un arco */
	for(int i=0; i < num_edges; i++) {
		printf("\nInserire i due vertici da congiungere");
		printf("\nVertice 1 -> ");
		scanf("%d", &vertex_1);
		fflush(stdin);
		printf("Vertice 2 -> ");
		scanf("%d", &vertex_2);
		fflush(stdin);
		addEdge(graph, vertex_1, vertex_2);
	}

	printGraph(graph);

	visita_DFS(graph, 2);

	return 0;
}