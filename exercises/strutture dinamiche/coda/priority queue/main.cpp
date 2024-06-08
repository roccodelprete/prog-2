#include <iostream>
#include <queue>
using namespace std;

void show_priority_queue(priority_queue<int> queue) {
	while (!queue.empty()) {
		cout << "\t" << queue.top();
		queue.pop();
	}
	cout << endl;
}

int main() {
	priority_queue<int> queue;
	cout << "Queue size -> " << queue.size() << endl;

	queue.push(10);
	cout << "\nqueue.push(10) --> ";
	show_priority_queue(queue);

	queue.push(1);
	cout << "queue.push(1) --> ";
	show_priority_queue(queue);

	queue.push(20);
	cout << "queue.push(20) --> ";
	show_priority_queue(queue);

	queue.push(5);
	cout << "queue.push(5) --> ";
	show_priority_queue(queue);

	queue.push(30);
	cout << "queue.push(30) --> ";
	show_priority_queue(queue);

	cout << "\nQueue size -> " << queue.size() << endl;

	if (!queue.empty()) {
		cout << "queue.top() -> " << queue.top() << endl;
		queue.pop();
		cout << "queue.pop() --> ";
		show_priority_queue(queue);
	}

	return 0;
}
