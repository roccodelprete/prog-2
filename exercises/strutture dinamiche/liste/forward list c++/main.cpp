#include <iostream>
#include <iterator>
#include <forward_list>

using namespace std;

void show_forward_list(forward_list <int> flist) {
    for (int &r : flist) {
        cout << "\t" << r;
    }
    cout << "\n";
}

int main() {
    forward_list <int> flist;
    forward_list <int>::iterator it;
    if(flist.empty())
        cout << "Lista vuota..." << endl;
    flist.push_front(10);   /* inserisce in testa */
    cout << "flist.push_front(10) -- > La lista contiene --> ";
    show_forward_list(flist);
    flist.push_front(20);   /* inserisce in testa */
    cout << "flist.push_front(20) -- > La lista contiene --> ";
    show_forward_list(flist);
    flist.push_front(30);   /* inserisce in testa */
    cout << "flist.push_front(30) -- > La lista contiene --> ";
    show_forward_list(flist);
    it = flist.insert_after(flist.begin(), {1, 3, 5}); /* inserisce dopo il primo nodo */
    cout << "it = flist.insert_after(flist.begin(), {1, 3, 5}) --> La lista contiene --> ";
    show_forward_list(flist);
    cout << "*it = " << *it << endl;
    it = flist.insert_after(it, 7); /*inserisce dopo nodo puntato da it */
    cout << "it = flist.insert_after(it, 7) --> La lista contiene --> ";
    show_forward_list(flist);
    cout << "*it = " << *it << endl;
    it = flist.begin();
    advance(it, 3);     /* it punta al terzo nodo dopo il primo */
    cout << "it = flist.begin(); advance(it, 3); --> *it = " << *it << endl;
    it = flist.insert_after(it, 9);
    cout << "it = flist.insert_after(it, 9) --> La lista contiene --> ";
    show_forward_list(flist);
    cout << "*it = " << *it << endl;
    flist.pop_front();      /* elimina nodo dalla testa */
    cout << "flist.pop_front() --> La lista contiene --> ";
    show_forward_list(flist);
    it = flist.begin();
    cout << "*it = " << *it << endl;
    flist.erase_after(it, flist.end());     /* elimina nodi dopo quello puntato da it fino alla fine */
    cout << "flist.erase_after(it, flist.end()) --> La lista contiene --> ";
    show_forward_list(flist);
    return 0;
}