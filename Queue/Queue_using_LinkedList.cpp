// Queue Implementation using Linked List - Basic queue operations (enqueue, dequeue) using linked list

#include <iostream>
using namespace std;
class Queue
{
    int data;
    Queue *next;
    Queue *F, *R;

public:
    Queue() : F(NULL), R(NULL) {}
    void enqueue(int n)
    {
        Queue *temp = new Queue;
        temp->data = n;
        temp->next = NULL;
        if (R == NULL)
        {
            F = temp;
            R = temp;
        }
        else
        {
            R->next = temp;
            R = temp;
        }
    }
    void display()
    {
        Queue *temp = F;
        if (F == NULL)
            cout << "Queue Underflow" << endl;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int dequeue()
    {
        if (F == NULL)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else if (F == R)
        {
            int temp = F->data;
            F = NULL;
            R = NULL;
            return temp;
        }
        else
        {
            int temp = F->data;
            F = F->next;
            return temp;
        }
    }
    void query()
    {
        int Q, queryType;
        cout << "Enter Queries : ";
        cin >> Q;
        for (int i = 0; i < Q; i++)
        {
            cin >> queryType;
            if (queryType == 1)
            {
                int x;
                cin >> x;
                enqueue(x);
            }
            else if (queryType == 2)
            {
                cout << "Popped Element : " << dequeue() << endl;
            }
        }
        cout << endl
             << "Query : ";
        display();
    }
};
int main()
{
    Queue q;
    q.query();
    return 0;
}