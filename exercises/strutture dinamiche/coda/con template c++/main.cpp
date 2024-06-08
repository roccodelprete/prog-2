#include <iostream>
#include <queue>
using namespace std;

void show_queue(queue <int> &q) {
    /*
     * #senza reference è possibile vedere l'intera coda
     * #con reference si visualizza solo la testa della coda
     */
    while (!q.empty()) {
        cout << "\t" << q.front();
        q.pop();
    }
    cout << "\n";
}
int main() {
    queue <int> q;
    cout << "Size coda -> " << q.size() << endl;
    if (q.empty()) {
        cout << "Coda vuota..." << endl;
    }
    q.push(10);
    cout << "q.push(10) --> La coda contiene --> ";
    show_queue(q);
    q.push(20);
    cout << "q.push(20) --> La coda contiene --> ";
    show_queue(q);
    q.push(30);
    cout << "q.push(30) --> La coda contiene --> ";
    show_queue(q);
    q.push(5);
    cout << "q.push(5) --> La coda contiene --> ";
    show_queue(q);
    q.push(1);
    cout << "q.push(1) --> La coda contiene --> ";
    show_queue(q);
    cout << "Size q -> " << q.size() << endl;
    if(!q.empty()) {
        cout << "Top -> " << q.front() << endl;
        q.pop();
        cout << "q.pop() --> La coda contiene --> ";
        show_queue(q);
    }
    return 0;
}
