/*Reverse Linked List
Given the head of a singly linked list, reverse the list, and return the reversed list. */

#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *first = NULL;
void reverseList()
{
    struct node *current = first;
    struct node *prev = NULL;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    first = prev;
}
void insert(int n)
{
    struct node *temp = new node;
    temp->data = n;
    temp->next = NULL;
    if (first == NULL)
    {
        first = temp;
    }
    else
    {
        temp->next = first;
        first = temp;
    }
}
void display()
{
    struct node *trav;
    trav = first;
    if (first == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    cout << endl
         << "Linked List : " << endl;
    while (trav != NULL)
    {
        printf("%d ", trav->data);
        trav = trav->next;
    }
}
int main()
{
    int again;
    while (1)
    {
        char choice;
        cout << "Enter your choice" << endl
             << "(a) Insert a Value" << endl
             << "(b) Reverse List" << endl
             << "Enter Your Choice : ";
        cin >> choice;
        int number;
        switch (choice)
        {
        case 'a':
            cout << "Enter the number to insert at front: ";
            cin >> number;
            insert(number);
            display();
            break;
        case 'b':
            reverseList();
            display();
            break;
        default:
            cout << "Invalid Choice!";
            break;
        }
        cout << endl
             << "Enter 0 to Exit : ";
        cin >> again;
        cout << endl;
        if (again == 0)
            break;
    }
}