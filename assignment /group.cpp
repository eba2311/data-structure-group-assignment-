#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <stack>
using namespace std;

// ========================== Queue Manager Class ==========================
class QueueManager {
private:
    queue<int> q;

public:
    void enqueue(int val) {
        q.push(val);
        cout << "Enqueued " << val << " into the queue.\n";
    }

    void dequeue() {
        if (!q.empty()) {
            cout << "Dequeued: " << q.front() << endl;
            q.pop();
        } else {
            cout << "❌ Queue is empty. Cannot dequeue.\n";
        }
    }

    void display() {
        if (q.empty()) {
            cout << "📭 Queue is empty.\n";
            return;
        }
        queue<int> temp = q;
        cout << "📋 Queue Elements: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }

    void peekFront() {
        if (!q.empty()) {
            cout << "Front Element: " << q.front() << endl;
        } else {
            cout << "Queue is empty.\n";
        }
    }

    void peekRear() {
        if (!q.empty()) {
            queue<int> temp = q;
            while (temp.size() > 1) temp.pop();
            cout << "Rear Element: " << temp.front() << endl;
        } else {
            cout << "Queue is empty.\n";
        }
    }

    void clear() {
        while (!q.empty()) q.pop();
        cout << "🧹 Queue cleared.\n";
    }

    void search(int key) {
        queue<int> temp = q;
        int pos = 1;
        bool found = false;
        while (!temp.empty()) {
            if (temp.front() == key) {
                cout << " Found " << key << " at position " << pos << ".\n";
                found = true;
            }
            temp.pop();
            pos++;
        }
        if (!found)
            cout << "❌ " << key << " not found in queue.\n";
    }

    void countFrequency(int key) {
        queue<int> temp = q;
        int count = 0;
        while (!temp.empty()) {
            if (temp.front() == key)
                count++;
            temp.pop();
        }
        cout << "Frequency of " << key << ": " << count << endl;
    }

    void reverseQueue() {
        vector<int> v;
        while (!q.empty()) {
            v.push_back(q.front());
            q.pop();
        }
        reverse(v.begin(), v.end());
        for (int x : v) q.push(x);
        cout << "Queue reversed.\n";
    }

    void sortQueue() {
        vector<int> v;
        while (!q.empty()) {
            v.push_back(q.front());
            q.pop();
        }
        sort(v.begin(), v.end());
        for (int x : v) q.push(x);
        cout << " Queue sorted in ascending order.\n";
    }

    void removeDuplicates() {
        vector<int> v;
        while (!q.empty()) {
            v.push_back(q.front());
            q.pop();
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int x : v) q.push(x);
        cout << " Duplicates removed.\n";
    }

    void saveToFile(const string& filename) {
        ofstream out(filename);
        queue<int> temp = q;
        while (!temp.empty()) {
            out << temp.front() << "\n";
            temp.pop();
        }
        out.close();
        cout << "Queue saved to " << filename << endl;
    }

    void loadFromFile(const string& filename) {
        ifstream in(filename);
        if (!in) {
            cout << "File not found.\n";
            return;
        }
        clear();
        int value;
        while (in >> value) {
            q.push(value);
        }
        in.close();
        cout << " Queue loaded from " << filename << endl;
    }

    void convertToStack() {
        stack<int> s;
        queue<int> temp = q;
        while (!temp.empty()) {
            s.push(temp.front());
            temp.pop();
        }
        cout << "Stack View (top to bottom): ";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    void visualView() {
        queue<int> temp = q;
        cout << "Visual View: [ ";
        while (!temp.empty()) {
            cout << setw(3) << temp.front() << " ";
            temp.pop();
        }
        cout << "]\n";
    }

    int size() {
        return q.size();
    }

    bool isEmpty() {
        return q.empty();
    }
};

// ======================= Menu Display ==========================
void showMenu() {
    cout << "\n========== Queue Operations Menu ==========\n";
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Display\n";
    cout << "4. Peek Front\n";
    cout << "5. Peek Rear\n";
    cout << "6. Clear Queue\n";
    cout << "7. Search Element\n";
    cout << "8. Count Frequency\n";
    cout << "9. Reverse Queue\n";
    cout << "10. Sort Queue\n";
    cout << "11. Remove Duplicates\n";
    cout << "12. Save to File\n";
    cout << "13. Load from File\n";
    cout << "14. Convert to Stack View\n";
    cout << "15. Visual View\n";
    cout << "16. Queue Size\n";
    cout << "0. Exit\n";
    cout << "===========================================\n";
    cout << "Enter choice: ";
}

// ======================= Main Driver Function ==========================
int main() {
    QueueManager qm;
    int choice, value;
    string filename;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                qm.enqueue(value);
                break;
            case 2:
                qm.dequeue();
                break;
            case 3:
                qm.display();
                break;
            case 4:
                qm.peekFront();
                break;
            case 5:
                qm.peekRear();
                break;
            case 6:
                qm.clear();
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                qm.search(value);
                break;
            case 8:
                cout << "Enter value to count frequency: ";
                cin >> value;
                qm.countFrequency(value);
                break;
            case 9:
                qm.reverseQueue();
                break;
            case 10:
                qm.sortQueue();
                break;
            case 11:
                qm.removeDuplicates();
                break;
            case 12:
                cout << "Enter filename to save: ";
                cin >> filename;
                qm.saveToFile(filename);
                break;
            case 13:
                cout << "Enter filename to load: ";
                cin >> filename;
                qm.loadFromFile(filename);
                break;
            case 14:
                qm.convertToStack();
                break;
            case 15:
                qm.visualView();
                break;
            case 16:
                cout << "Queue size: " << qm.size() << endl;
                break;
            case 0:
                cout << "Exiting. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
