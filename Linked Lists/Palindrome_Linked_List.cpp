// Palindrome Linked List - Check if a singly linked list is a palindrome

#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *first = NULL;
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
struct node *reverseList(struct node *head)
{
    struct node *current = head;
    struct node *prev = NULL;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
void display()
{
    struct node *trav = first;
    if (first == NULL)
    {
        cout << "Underflow" << endl;
        return;
    }
    cout << endl
         << "Linked List : " << endl;
    while (trav != NULL)
    {
        cout << trav->data << " ";
        trav = trav->next;
    }
    cout << endl;
}
bool compare(struct node *a, struct node *b)
{
    while (a != NULL && b != NULL)
    {
        if (a->data != b->data)
        {
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);
}
bool isPallindrome()
{
    struct node *slow_ptr = first, *fast_ptr = first;
    struct node *second_half = NULL, *prev_of_slow_ptr = first;
    struct node *midnode = NULL;
    bool isPallindrome = true;
    if (first != NULL && first->next != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        if (fast_ptr != NULL)
        {
            midnode = slow_ptr;
            slow_ptr = slow_ptr->next;
        }
        second_half = slow_ptr;
        prev_of_slow_ptr->next = NULL;
        second_half = reverseList(second_half);
        isPallindrome = compare(first, second_half);
        second_half = reverseList(second_half);
        if (midnode != NULL)
        {
            prev_of_slow_ptr->next = midnode;
            midnode->next = second_half;
        }
        else
        {
            prev_of_slow_ptr->next = second_half;
        }
    }
    return isPallindrome;
}
int main()
{
    int again;
    bool Pallindrome;
    while (1)
    {
        char choice;
        cout << "Enter your choice" << endl
             << "(a) Insert a Value" << endl
             << "(b) Check for Pallindrome" << endl
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
            Pallindrome = isPallindrome();
            if (Pallindrome)
                cout << "True";
            else
                cout << "False";
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