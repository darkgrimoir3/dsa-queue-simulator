
#include <iostream>
//this is simple file of traffic simulation
class Queue {
private:
    static const int MAX_SIZE = 10; // Max queue size
    int arr[MAX_SIZE];
    int front, rear;

public:
    Queue() : front(-1), rear(-1) {}

    void enqueue(int value) {
        if (isFull()) {
            std::cout << "Queue is full! Cannot enqueue.\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty! Cannot dequeue.\n";
            return -1;
        }
        int value = arr[front];
        if (front >= rear) front = rear = -1; // Reset queue when empty
        else front++;
        return value;
    }

    bool isEmpty() const { return front == -1; }
    bool isFull() const { return rear == MAX_SIZE - 1; }

    void display() const {
        if (isEmpty()) {
            std::cout << "Queue is empty.\n";
            return;
        }
        for (int i = front; i <= rear; i++) std::cout << arr[i] << " ";
        std::cout << "\n";
    }
};

int main() {
    Queue laneQueue;

    // Simulating vehicles arriving
    laneQueue.enqueue(1);
    laneQueue.enqueue(2);
    laneQueue.enqueue(3);

    std::cout << "Processing vehicles:\n";
    while (!laneQueue.isEmpty()) {
        std::cout << "Vehicle from lane " << laneQueue.dequeue() << " passed.\n";
    }
    return 0;
}

