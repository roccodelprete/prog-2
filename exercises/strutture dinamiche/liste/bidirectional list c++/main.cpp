#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void show_forward_list(list <int> blist) {
	list <int>::iterator it;
	for (it = blist.begin(); it != blist.end(); it++) {
		cout << "\t" << *it;
	}
	cout << "\n";
}

void show_back_list(list <int> blist) {
	list <int>::reverse_iterator r_it;
	for (r_it = blist.rbegin(); r_it != blist.rend(); r_it++) {
		cout << "\t" << *r_it;
	}
	cout << "\n";
}
int main() {
    list <int> blist;
	list <int>::iterator it;
	list <int>::reverse_iterator r_it;
	if(blist.empty())
		cout << "Lista bidirezionale vuota..." << endl;
	blist.push_front(10);   /*inserisce in testa */
	cout << "blist.push_front(10) --> La lista bidirezionale contiene --> ";
	show_forward_list(blist);
	blist.push_front(30);   /*inserisce in testa */
	cout << "blist.push_front(30) --> La lista bidirezionale contiene --> ";
	show_forward_list(blist);
	blist.push_back(20);   /*inserisce in coda */
	cout << "blist.push_back(20) --> La lista bidirezionale contiene --> ";
	show_back_list(blist);
	it = blist.begin();
	++it;   /* it punta al secondo nodo */
	cout << "it = blist.begin(); ++it; --> *it = " << *it <<endl;
	it = blist.insert(it, {1,3,5});     /* inserisce prima del nodo puntato da it */
	cout << "it = blist.insert(it, {1,3,5}) --> La lista bidirezionale contiene --> ";
	show_forward_list(blist);
	cout << "*it = " << *it << endl;
	it = blist.end();
	it--;   /* it punta all'ultimo nodo */
	cout << "it = blist.end(); it-- --> *it = " << *it << endl;
	r_it = blist.rbegin();
	cout << "r_it = blist.rbegin() --> *r_it = " << *r_it << endl;
	it = blist.insert(it, 2, 15);   /* inserisce 2 volte 15 prima del nodo puntato da it */
	cout << "it = blist.insert(it, 2, 15) --> La lista bidirezionale contiene --> ";
	show_forward_list(blist);
	blist.pop_front();  /* elimina nodo dalla testa */
	cout << "blist.pop_front() --> La lista contiene --> ";
	show_forward_list(blist);
	blist.pop_back();   /* elimina nodo dalla coda */
	cout << "blist.pop_back() --> La lista contiene --> ";
	show_forward_list(blist);
	it = blist.end();   /* it punta oltre l'ultimo nodo */
	advance(it, -3);    /* it arretra di 3 nodi */
	cout << "it = blist.end(); advance(it, -3); --> *it = " << *it << endl;
    return 0;
}
