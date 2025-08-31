// Doubly Linked List Operations - Complete implementation with insert, delete operations at various positions

#include <iostream>
using namespace std;
class DoublyLinkedList
{
    int data;
    DoublyLinkedList *lptr;
    DoublyLinkedList *rptr;
    DoublyLinkedList *L = NULL, *R = NULL;

public:
    void insert_front(int n)
    {
        DoublyLinkedList *temp = new DoublyLinkedList();
        temp->data = n;
        temp->lptr = NULL;
        temp->rptr = NULL;
        if (L == NULL)
        {
            L = temp;
            R = temp;
            return;
        }
        else
        {
            temp->rptr = L;
            L->lptr = temp;
            L = temp;
        }
    }
    void insert_back(int n)
    {
        DoublyLinkedList *temp = new DoublyLinkedList();
        temp->data = n;
        temp->lptr = NULL;
        temp->rptr = NULL;
        if (R == NULL)
        {
            L = temp;
            R = temp;
            return;
        }
        else
        {
            temp->lptr = R;
            R->rptr = temp;
            R = temp;
        }
    }
    void insert_before(int n, int x)
    {
        DoublyLinkedList *temp = new DoublyLinkedList();
        temp->data = n;
        temp->lptr = NULL;
        temp->rptr = NULL;
        DoublyLinkedList *trav = L;
        DoublyLinkedList *prev;
        while (trav->data != x)
        {
            prev = trav;
            trav = trav->rptr;
        }
        if (trav == NULL)
        {
            cout << "Node not found";
            return;
        }
        temp->rptr = trav;
        temp->lptr = trav->lptr;
        trav->lptr = temp;
        prev->rptr = temp;
    }
    void insert_after(int n, int x)
    {
        DoublyLinkedList *temp = new DoublyLinkedList();
        temp->data = n;
        temp->lptr = NULL;
        temp->rptr = NULL;
        DoublyLinkedList *trav = L;
        DoublyLinkedList *next = trav->rptr;
        while (trav->data != x)
        {
            trav = trav->rptr;
            next = trav->rptr;
        }
        if (trav == NULL)
        {
            cout << "Node not found";
            return;
        }
        temp->rptr = next;
        temp->lptr = trav;
        trav->rptr = temp;
        next->lptr = temp;
    }
    void delete_front()
    {
        if (L == NULL)
        {
            cout << "Underflow";
            return;
        }
        else if (L == R)
        {
            delete L;
            L = NULL;
            R = NULL;
            return;
        }
        else
        {
            DoublyLinkedList *temp = new DoublyLinkedList;
            temp = L;
            L = L->rptr;
            delete temp;
            L->lptr = NULL;
        }
    }
    void delete_back()
    {
        if (R == NULL)
        {
            cout << "Underflow";
            return;
        }
        else if (R == L)
        {
            delete R;
            L = NULL;
            R = NULL;
            return;
        }
        else
        {
            DoublyLinkedList *temp = new DoublyLinkedList;
            temp = R;
            R = R->lptr;
            delete temp;
            R->rptr = NULL;
        }
    }
    void delete_specific(int x)
    {
        DoublyLinkedList *trav = L, *prev, *next;
        if (trav == NULL)
            cout << "Underflow";
        while (trav->data != x)
        {
            prev = trav;
            trav = trav->rptr;
            next = trav->rptr;
        }
        prev->rptr = next;
        next->lptr = prev;
        delete trav;
    }
    void delete_all()
    {
        DoublyLinkedList *temp = L, *next;
        if (temp == NULL)
            cout << "Underflow";
        while (temp != NULL)
        {
            next = temp->rptr;
            delete temp;
            temp = next;
        }
        L = NULL;
        R = NULL;
    }
    void display()
    {
        DoublyLinkedList *ptr = L;
        if (ptr == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        cout << endl
             << "Linked List : ";
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->rptr;
        }
        cout << endl;
    }
    void menu()
    {
        int again, n, x;
        char choice;
        do
        {
            cout << "List Of Operations : " << endl;
            cout << "(a) Insert a node at front" << endl;
            cout << "(b) Insert a node at back" << endl;
            cout << "(c) Insert a node before a node" << endl;
            cout << "(d) Insert a node after a node" << endl;
            cout << "(e) Delete a node at front" << endl;
            cout << "(f) Delete a node at back" << endl;
            cout << "(g) Delete a specific node" << endl;
            cout << "(h) Delete all nodes of linked list" << endl;
            cout << "(i) Display linked list" << endl;
            cout << "Enter your choice : ";
            cin >> choice;
            switch (choice)
            {
            case 'a':
                cout << "Enter the Number you want to add to the front : ";
                cin >> n;
                insert_front(n);
                display();
                break;
            case 'b':
                cout << "Enter the Number you want to add to the back : ";
                cin >> n;
                insert_back(n);
                display();
                break;
            case 'c':
                cout << "Enter the Number before which you want to insert : ";
                cin >> x;
                cout << "Enter the Number you want to add : ";
                cin >> n;
                insert_before(n, x);
                display();
                break;
            case 'd':
                cout << "Enter the Number after which you want to insert : ";
                cin >> x;
                cout << "Enter the Number you want to add : ";
                cin >> n;
                insert_after(n, x);
                display();
                break;
            case 'e':
                delete_front();
                display();
                break;
            case 'f':
                delete_back();
                display();
                break;
            case 'g':
                cout << "Enter the Number you want to delete : ";
                cin >> n;
                delete_specific(n);
                display();
                break;
            case 'h':
                delete_all();
                display();
                break;
            case 'i':
                display();
                break;
            }
            cout << "Enter 1 to continue and 0 to Exit : ";
            cin >> again;
        } while (again != 0);
    }
};
int main()
{
    DoublyLinkedList dll;
    dll.menu();
    return 0;
}