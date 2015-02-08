#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;
//Doubly Linked list in C++
//Written by: Karim Oumghar
class Doubly_Linked_List
{
    class Node
    {
    public:
        int data;
        Node* next;
        Node* previous;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
            this->previous = NULL;
        };
        ~Node(void){};//destructor
    };
private:
    Node* first;
    Node* last;
public:
    Doubly_Linked_List()
    {
        first = NULL;
        last = NULL;
    }
    ~Doubly_Linked_List(void){};//destructor
    void Add(int data)
    {
        Node* newItem = new Node(data);
        if(IsEmpty() == true)
        {
            first = newItem;
            last = newItem;
        }
        else
        {
            newItem->previous = last;
            last->next = newItem;
            last = newItem;
        }
    }
    void PrintForward()
    {
        Node* current = first;
        while(current != NULL)
        {
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }
    void PrintReverse()
    {
        Node* current = last;
        while(current != NULL)
        {
            cout<<current->data<<" ";
            current = current->previous;
        }
        cout<<endl;
    }
    bool Find(int target)
    {
        bool isFound = false;
        Node* current = first;
        while(current != NULL)
        {
            if(current->data == target)
            {
                isFound = true;
                break;
            }
            else{current = current->next;}
        }
        current = NULL;
        return isFound;
    }
    void Delete(int target)
    {
        if(target == first->data)
        {
            DeleteFirst();
        }
        if(target == last->data)
        {
            DeleteLast();
        }
        else
        {
            Node* current = first;
            Node* temp = NULL;//node to delete
            while(current != NULL)
            {
                if(current->next->data == target)
                {
                    temp = current->next;
                    current->next->next->previous = current;
                    current->next = current->next->next;
                    delete temp;
                    temp = NULL;
                    break;
                }
                else
                {
                    current = current->next;
                }
            }
        }
    }
private:
    bool IsEmpty()
    {
        if(first == NULL)
        {
            return true;
        }
        else{return false;}
    }
    void DeleteFirst()
    {
        Node* temp = first;
        first = first->next;
        delete temp;
        temp = NULL;
        first->previous = NULL;
    }
    void DeleteLast()
    {
        Node* temp = last;
        last = last->previous;
        delete temp;
        temp = NULL;
        last->next = NULL;
    }
};
