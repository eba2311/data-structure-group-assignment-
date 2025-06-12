#include <iostream>
#include <limits>
using namespace std;
class Queue {
private:
    int front, rear, size, capacity;
    int* arr;
public:
    explicit Queue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        size = 0;
    }
    ~Queue() {
        delete[] arr;
    }
    bool isFull() const {
        return size == capacity;
    }
    bool isEmpty() const {
        return size == 0;
    }
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
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to dequeue." << endl;
            return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        front = (front + 1) % capacity;
        size--;
    }
    void display() const {
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
    void peekFront() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front Element: " << arr[front] << endl;
        }
    }

    void peekRear() const {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Rear Element: " << arr[rear] << endl;
        }
    }

    void getSize() const {
        cout << "Current Queue Size: " << size << endl;
    }

    void resize(int newCap) {
        if (newCap < size) {
            cout << "New capacity is less than current queue size. Resize aborted." << endl;
            return;
        }

        int* newArr = new int[newCap];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[(front + i) % capacity];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCap;
        front = 0;
        rear = size - 1;

        cout << "Queue resized to capacity: " << capacity << endl;
    }

    int getCapacity() const {
        return capacity;
    }
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int cap;
    cout << "Enter capacity of the queue: ";
    while (!(cin >> cap) || cap <= 0) {
        cout << "Invalid input. Enter a positive integer for capacity: ";
        clearInputBuffer();
    }

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
        cout << "10. Resize Queue (Future Feature)" << endl;
        cout << "Choose an option: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number." << endl;
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                if (!(cin >> value)) {
                    cout << "Invalid input. Please enter an integer." << endl;
                    clearInputBuffer();
                    break;
                }
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
            case 10:
                cout << "Enter new capacity: ";
                if (!(cin >> value) || value <= 0) {
                    cout << "Invalid input. Enter a positive integer." << endl;
                    clearInputBuffer();
                } else {
                    q.resize(value);
                }
                break;
            default:
                cout << "Invalid option! Try again." << endl;
        }

    } while (choice != 9);

    return 0;
}
