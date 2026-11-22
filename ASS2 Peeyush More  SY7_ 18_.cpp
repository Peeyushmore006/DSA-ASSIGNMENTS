#include <iostream>
using namespace std;

#define MAX 5

class Queue
{
private:
    int queue[MAX];
    int front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    // Enqueue
    void enqueue(int value)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue Overflow!" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = value;
        cout << value << " added to the queue." << endl;
    }

    // Dequeue
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow! Queue is empty." << endl;
            return;
        }

        cout << queue[front] << " removed from the queue." << endl;
        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }

    // Display
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements are: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n===== Queue Menu =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
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
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}

// ----------------------------------------------------------------------------------------------------------------------------------------------------

//___________________________________*.  OUTPUT. *_____________________________________________________________________________________________________

//-----------------------------------------------------------------------------------------------------------------------------------------------------




/* peeyushmore@Peeyushs-MacBook DSA CLASSROOM % "/Users/peeyushmore/Python.app/DSA CLASSROOM/pract2"

===== Queue Menu =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value: 20
20 added to the queue.

===== Queue Menu =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter value: 30
30 added to the queue.

===== Queue Menu =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
20 removed from the queue.

===== Queue Menu =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements are: 30 

===== Queue Menu =====
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
Exiting...
peeyushmore@Peeyushs-MacBook DSA CLASSROOM % 

*/