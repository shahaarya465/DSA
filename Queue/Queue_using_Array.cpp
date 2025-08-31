// Implement Queue using array

#include <iostream>
using namespace std;
class Queue
{
    int a[5];
    int F, R, N = 5;

public:
    Queue() { F = R = -1; }
    void enqueue(int n)
    {
        if (R == N - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        else
        {
            R = R + 1;
            a[R] = n;
            if (F == -1)
                F = 0;
        }
    }
    int dequeue()
    {
        if (F == -1)
        {
            cout << "Queue Overflow" << endl;
            return -1;
        }
        else if (F == R)
        {
            int x = a[F];
            F = 0;
            R = 0;
            return x;
        }
        else
        {
            int x = a[F];
            F = F + 1;
            return x;
        }
    }
    void display()
    {
        if (F == -1)
            cout << "Queue is empty" << endl;
        else
            cout << a[F] << endl;
    }
    void query()
    {
        int Q, queryType;
        cout << "Enter Total Queries : ";
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
        cout << endl;
        cout << "Queue : ";
        display();
    }
};
int main()
{
    Queue Q;
    Q.query();
    return 0;
}