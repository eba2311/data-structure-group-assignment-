#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front, rear, size, capacity;

public:
    // Constructor
    Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (isFull()) {
            cout << "❌ Queue Overflow! Cannot enqueue " << value << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << "✅ " << value << " added to the queue.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "❌ Queue Underflow! Nothing to dequeue.\n";
            return;
        }
        cout << "✅ Removed " << arr[front] << " from the queue.\n";
        front = (front + 1) % capacity;
        size--;
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "🔽 Queue Elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << "\n";
    }

    // Peek front element
    void peekFront() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Front Element: " << arr[front] << "\n";
    }

    // Peek rear element
    void peekRear() {
        if (isEmpty()) {
            cout << "Queue is
