#include <iostream>

using namespace std;

template<typename T>
class PriorityQueue
{
private:
    struct Node {
        T data;
        int priority;
    };

    Node* data;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        Node* newData = new Node[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    PriorityQueue(int cap = 10) : size(0), capacity(cap), data(new Node[capacity]) {}

    ~PriorityQueue() {
        delete[] data;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    bool IsFull() const {
        return size >= capacity;
    }

    void InsertWithPriority(const T& value, int priority) {
        if (IsFull()) {
            resize();
        }
        data[size].data = value;
        data[size].priority = priority;
        size++;
    }

    T PullHighestPriorityElement() {
        if (IsEmpty()) {
            throw exception("Queue is empty");
        }
        int highestPriorityIndex = 0;
        for (int i = 1; i < size; i++) {
            if (data[i].priority > data[highestPriorityIndex].priority) {
                highestPriorityIndex = i;
            }
        }
        T highestPriorityElement = data[highestPriorityIndex].data;
        for (int i = highestPriorityIndex; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        return highestPriorityElement;
    }

    T Peek() const {
        if (IsEmpty()) {
            throw exception("Queue is empty");
        }
        int highestPriorityIndex = 0;
        for (int i = 1; i < size; i++) {
            if (data[i].priority > data[highestPriorityIndex].priority) {
                highestPriorityIndex = i;
            }
        }
        return data[highestPriorityIndex].data;
    }

    int GetSize() const {
        return size;
    }

    void Show() const {
        for (int i = 0; i < size; i++) {
            cout << "Value: " << data[i].data << ", Priority: " << data[i].priority << endl;
        }
    }
};

int main() {
    PriorityQueue<int> pq;

    pq.InsertWithPriority(10, 1);
    pq.InsertWithPriority(20, 2);
    pq.InsertWithPriority(30, 3);
    pq.InsertWithPriority(40, 0);

    cout << "Queue elements: " << endl;
    pq.Show();

    cout << "Highest priority element: " << pq.Peek() << endl;
    cout << "Pulling highest priority element: " << pq.PullHighestPriorityElement() << endl;
    cout << "Queue elements after pull: " << endl;
    pq.Show();
}
