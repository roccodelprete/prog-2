#include <iostream>
#include <stack>
using namespace std;

void show_stack(stack <int> &s) {
    /*
     * #senza reference è possibile vedere l'intero stack
     * #con reference si visualizza solo la testa dello stack
     */
    while(!s.empty()) {
        cout << "\t" << s.top();
        s.pop();
    }
    cout << "\n";
}

int main() {
    stack <int> stack;
    cout << "Size stack -> " << stack.size() << endl;
    if(stack.empty()) {
        cout << "Stack vuoto..." << endl;
    }
    stack.push(10);
    cout << "stack.push(10) --> Lo stack contiene --> ";
    show_stack(stack);
    stack.push(20);
    cout << "stack.push(20) --> Lo stack contiene --> ";
    show_stack(stack);
    stack.push(30);
    cout << "stack.push(30) --> Lo stack contiene --> ";
    show_stack(stack);
    stack.push(5);
    cout << "stack.push(5) --> Lo stack contiene --> ";
    show_stack(stack);
    stack.push(1);
    cout << "stack.push(1) --> Lo stack contiene --> ";
    show_stack(stack);
    cout << "Size stack -> " << stack.size() << endl;
    if(!stack.empty()) {
        cout << "Top -> " << stack.top() << endl;
        stack.pop();
        cout << "stack.pop() --> Lo stack contiene --> ";
        show_stack(stack);
    }
    return 0;
}