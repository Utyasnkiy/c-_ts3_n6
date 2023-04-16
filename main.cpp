#include <iostream>
using namespace std;

template<class T>
class Queue {
private:
    T *arr;
    int front, rear, capacity;
public:
    Queue(int size = 10) {
        arr = new T[size];
        capacity = size;
        front = rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    void enqueue(T item) {
        if (isFull()) {
            cout << "Queue is full.\n";
            return;
        }
        if (isEmpty())
            front = 0;
        arr[++rear] = item;
    }

    T dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return T();
        }
        T item = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return item;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return rear == capacity - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.display();
    cout << q1.dequeue() << endl;
    q1.display();

    Queue<string> q2(5);
    q2.enqueue("Hello");
    q2.enqueue("World");
    q2.display();
    cout << q2.dequeue() << endl;
    q2.display();

    return 0;
}
