#include "lib.h"

// implemento una procedura per la visita Breadth First Service(BFS_visit), che avviene in ampiezza, all'interno di un grafo
void BFS_visit(struct Graph* graph, int startVertex) {
	struct queue* q = create_queue(); // creo una coda

	graph->visited[startVertex] = true; // il nodo corrente verrà segnato come visitato
	enqueue(q,startVertex); // inserisco un elemento in fondo alla queue tramite il richiamo della procedura enqueue

	while(!is_empty(q)) { // se la queue non è vuota
		print_queue(q); // la visualizzo tramite la procedura apposita
		int currentVertex = dequeue(q); // ed estraggo l'elemento dalla testa che sarà il nodo visitato
		printf("\nNodo visitato %d\n", currentVertex);

		/* dichiaro e inizializzo un puntatore alla struttura nodo al valore della della lista di adiacenze
		del vertice	passato dal chiamante */
		struct node* temp = graph->adjLists[currentVertex];

		while(temp != NULL) { // fin quando la lista di adiacenze non è finita
			// dichiaro e inizializzo una variabile al valore del vertice del nodo corrente
			int adjVertex = temp->vertex;
			// se il nodo corrente non è stato ancora visitato
			if(!(graph->visited[adjVertex])) {
				graph->visited[adjVertex] = true; // allora lo segno come visitato
				enqueue(q, adjVertex); // e richiamo la procedura di inserimento dell'elemento in fondo
			}
			temp = temp->next; // aggiorno il puntatore al nodo corrente
		}
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
struct Graph* create_graph(int num_v) {
	struct Graph* graph = malloc(sizeof(struct Graph)); // dichiaro e alloco dinamicamente la struttura del grafo

	graph->numVertices = num_v; // che avrà come numero di vertici il valore passato dal chiamante
	// dichiaro e alloco dinamicamente la struttura delle liste adiacenti
	graph->adjLists = malloc(num_v*sizeof(struct node*));
	// dichiaro e alloco dinamicamente l'array che contiene il flag sulla visita di un nodo
	graph->visited = malloc(num_v*sizeof(int));

	/* imposto un ciclo for per inizializzare la lista di adiacenze di ogni nodo a NULL e per inizializzare il flag
	sulla visita a false */
	for(int i=0; i<num_v; i++) {
		graph->adjLists[i] = NULL;
		graph->visited[i] = false;
	}
	return graph; // ritorno il grafo
}

// implemento una procedura per l'inserimento di un arco all'interno del grafo
void add_edge(struct Graph* graph, int x, int y) {
	struct node* newNode = create_node(y); // creo un nodo tramite la function create_node a cui passo un vertice
	/* il nodo appena creato punterà al nodo con cui forma un arco e che di conseguenza fa parte della sua lista
	di adiacenze */
	newNode->next = graph->adjLists[x];
	graph->adjLists[x] = newNode; // aggiunge alla lista di adiacenze del vertice x il nuovo nodo creato

	// ripete la stessa operazione invertendo i vertici, in modo da farli risultare adiacenti per entrambi i vertici
	newNode = create_node(x);
	newNode->next = graph->adjLists[y];
	graph->adjLists[y] = newNode;
}

// Create a queue
struct queue* create_queue() {
	struct queue* q = malloc(sizeof(struct queue)); // creo dinamicamente lo spazio per una queue
	// inizializzo head e bottom a -1 poichè ancora non c'è nessun elemento nella queue
	q->head = -1;
	q->bottom = -1;
	return q;
}

// implemento una procedura per controllare se la lista è vuota o meno
boolean is_empty(struct queue* q) {
	if (q->bottom == -1)
		return true;
	else
		return false;
}

// implemento la procedura di enqueue, ossia di inserimento di un elemento sul fondo della queue
void enqueue(struct queue* q, int value) {
	if (q->bottom == SIZE - 1) // se il fondo della queue è uguale al size-1 significa che la queue è piena
		printf("\nQueue is Full...");
	else { // se invece così non è
		if(q->head == -1) // se la queue non contiene elementi
			q->head = 0; // allora devo incrementare di uno la testa della queue
		q->bottom++; // ad ogni inserimento invece incremento il fondo
		q->items[q->bottom] = value; // inserisco il valore all'interno della queue
	}
}

// implemento la procedura di dequeue, ossia di estrazione di un elemento dalla testa della queue
int dequeue(struct queue* q) {
	int item;
	if(is_empty(q)) { // se la queue è vuota
		printf("Queue is empty...");
		item = -1; // allora il valore della variabile contenente il nodo estratto avrà valore -1
	} else { // se invece non è vuota
		item = q->items[q->head]; // estraggo il nodo dalla testa e lo assegno alla variabile che ritornerò
		q->head++; // e incremento la testa della queue
		if(q->head > q->bottom) { // se la testa è maggiore della coda
			printf("\nResetting queue...");
			q->head = q->bottom = -1; // allora resetto i valori dei due indici della queue
		}
	}
	return item; // ritorno il nodo estratto o -1 se la queue è vuota
}

// implemento una procedura per la visualizzazione della queue
void print_queue(struct queue* q) {
	if(is_empty(q)) // se la coda è vuota allora stampo un messaggio a video
		printf("Queue is empty...");
	else { // se invece non è vuota
		printf("\nLa queue contiene -> \n");
		// imposto un ciclo for che parta dall'indice testa e arrivi fino all'indice fondo
		for(int i = q->head; i < q->bottom + 1; i++)
			printf("%d ", q->items[i]);
	}
}
