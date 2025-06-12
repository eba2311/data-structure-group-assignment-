#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front, rear, size, capacity;

public:
    // Constructor
    Queue(int cap) {
        if (cap <= 0) {
            cout << "Invalid capacity! Setting to default (10)." << endl;
            capacity = 10;
        } else {
            capacity = cap;
        }
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
            cout << "Queue Overflow! Cannot enqueue " << value << "." << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
        cout << value << " added to the queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to dequeue." << endl;
            return;
        }
        cout << "Removed " << arr[front] << " from the queue." << endl;
        front = (front + 1) % capacity;
        size--;
    }

    // Display all elements
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue Elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }

    // Peek front element
    void peekFront() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Front Element: " << arr[front] << endl;
    }

    // Peek rear element
    void peekRear() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Rear Element: " << arr[rear] << endl;
    }

    // Show current size
    void getSize() const {
        cout << "Current Queue Size: " << size << endl;
    }

    // Check if queue is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Check if queue is full
    bool isFull() const {
        return size == capacity;
    }

    // Clear the queue
    void clear() {
        front = 0;
        rear = -1;
        size = 0;
    }

    // Check if queue contains a value
    bool contains(int value) const {
        for (int i = 0; i < size; i++) {
            if (arr[(front + i) % capacity] == value) {
                return true;
            }
        }
        return false;
    }

    // Get maximum capacity
    int getCapacity() const {
        return capacity;
    }

    // Print elements in reverse order
    void printReverse() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue in reverse: ";
        for (int i = size - 1; i >= 0; i--) {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the queue: ";
    cin >> capacity;

    Queue q(capacity);
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
        cout << "10. Clear Queue" << endl;
        cout << "11. Search Element" << endl;
        cout << "12. Show Capacity" << endl;
        cout << "13. Print in Reverse" << endl;
        cout << "Enter your choice: ";
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
            cout << (q.isEmpty() ? "Yes, the queue is empty." : "No, the queue is not empty.") << endl;
            break;
        case 8:
            cout << (q.isFull() ? "Yes, the queue is full." : "No, the queue is not full.") << endl;
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
        case 10:
            q.clear();
            cout << "Queue cleared successfully." << endl;
            break;
        case 11:
            cout << "Enter value to search: ";
            cin >> value;
            cout << (q.contains(value) ? "Value exists in the queue." : "Value not found in the queue.") << endl;
            break;
        case 12:
            cout << "The maximum capacity of the queue is: " << q.getCapacity() << endl;
            break;
        case 13:
            q.printReverse();
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
