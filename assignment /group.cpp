#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size, capacity;
    int* arr;

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

    // Check if the queue is full
    bool isFull() {
        return size == capacity;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return size == 0;
    }

    // Enqueue operation
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << item << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = item;
        size++;
        cout << "Enqueued: " << item << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % capacity;
        size--;
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    // Peek front element
    void peekFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front Element: " << arr[front] << endl;
        }
    }

    // Peek rear element
    void peekRear() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Rear Element: " << arr[rear] << endl;
        }
    }

    // Get current size
    void getSize() {
        cout << "Current Queue Size: " << size << endl;
    }
};

// Main function to test the queue
int main() {
    int cap;
    cout << "Enter capacity of the queue: ";
    cin >> cap;

    Queue q(cap);

    int choice, value;
    do {
        cout << "\n--- Queue Operations Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display Queue" << endl;
        cout << "4. Peek Front" << endl;
        cout << "5. Peek Rear" << endl;
        cout << "6. Queue Size" << endl;
        cout << "7. Is Queue Empty?" << endl;
        cout << "8. Is Queue Full?" << endl;
        cout << "9. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.peekFront();
                break;
            case 5:
                q.peekRear();
                break;
            case 6:
                q.getSize();
                break;
            case 7:
                cout << (q.isEmpty() ? "Queue is empty." : "Queue is not empty.") << endl;
                break;
            case 8:
                cout << (q.isFull() ? "Queue is full." : "Queue is not full.") << endl;
                break;
            case 9:
                cout << "Exiting... Thank you!" << endl;
                break;
            default:
                cout << "Invalid option! Try again." << endl;
        }

    } while (choice != 9);

    return 0;
}
