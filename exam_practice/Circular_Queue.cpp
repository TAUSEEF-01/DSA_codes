#include <bits/stdc++.h>
using namespace std;

struct CircularQueue
{
    int front, rear;

    int sz;
    int *arr;

    CircularQueue(int n)
    {
        front = rear = -1; // initialize value for front and rear
        sz = n;
        arr = new int[n];
    }

    void enQueue(int value)
    {
        if ((front == 0 && rear == sz - 1) || ((rear + 1) % sz == front))
        {
            cout << "Queue is full!\n";
            return;
        }
        else if (front == -1) // insert the first element
        {
            rear = front = 0;
            arr[rear] = value;
        }
        else if (rear == sz - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = value;
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
    }

    int deQueue()
    {
        if (front == -1)
        {
            cout << "Queue is empty!\n";
            return INT_MAX;
        }

        int data = arr[front];
        if (front == rear) // this condition needs to check first
        {
            front = rear = -1;
        }
        else if (front == sz - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        return data;
    }

    void printQueue()
    {
        if (front == -1)
        {
            cout << "Queue is empty!\n";
            return;
        }

        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
        else
        {
            for (int i = front; i < sz; i++)
            {
                cout << arr[i] << ' ';
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << arr[i] << ' ';
            }
            cout << endl;
        }
    }
};

int main()
{
    CircularQueue q(6);

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.enQueue(6);
    q.enQueue(1);

    q.printQueue();

    int data = q.deQueue();
    cout << data << endl;

    q.printQueue();

    return 0;
}
