#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include "Linked List.cpp"
#include "Stack.cpp"
#include "Queue.cpp"
#include "Binary Search Tree.cpp"
#include "Doubly Linked List.cpp"

using namespace std;

int main()
{
    //test space for our data structures
    cout <<"Data structures demo"<<endl;

    LinkedList collection;
    collection.AddItem(1);
    collection.AddItem(3);
    collection.AddItem(5);
    collection.AddItem(7);
    collection.AddItem(9);
    collection.AddItem(11);
    collection.AddItem(13);
    collection.isEmpty();
    collection.DisplayList();
    collection.RemoveFirst();
    collection.RemoveItem(5);
    collection.RemoveItem(9);
    collection.RemoveLast();
    collection.DisplayList();

    cout <<"\nStack demo"<<endl;
    Stack s;
    s.Display();
    cout<<"\nIs the stack empty? "<<s.IsEmpty();
    s.Push(32);
    s.Push(64);
    s.Push(128);
    s.Push(256);
    s.Push(512);
    s.Push(768);
    s.Display();
    cout<<"\nWe just popped this from stack: "<<s.Pop();
    cout<<"\nWhats at the top: "<<s.Peek();
    cout<<"\nIs the stack empty? "<<s.IsEmpty();
    s.Display();

    BST tree;
	tree.Add(5);
	tree.Add(3);
	tree.Add(7);
	tree.Add(2);
	tree.Add(4);
	tree.Add(6);
	tree.Add(8);
	cout<<endl;
	cout<<"Tree..."<<endl;
	tree.PrintInOrder();
	cout<<endl;
	tree.Find(8);
	tree.Remove(2);
	tree.PrintInOrder();
	cout<<endl;
	tree.Remove(77);
	tree.Remove(5);
	tree.PrintInOrder();
	cout<<endl;

	Queue q;
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(30);
	q.Enqueue(40);
	q.Enqueue(50);
	q.Enqueue(75);
	q.Enqueue(100);
    cout<<endl;
    cout<<"Queue..."<<endl;
    q.DisplayQueue();
    cout<<endl;
    q.Dequeue();
    q.Dequeue();
    q.Dequeue();
    cout<<"After items dequeued..."<<endl;
    q.DisplayQueue();

    cout<<endl;
    cout<<endl;
    cout<<"Doubly Linked List..."<<endl;
    Doubly_Linked_List dll;
    dll.Add(5);
    dll.Add(10);
    dll.Add(15);
    dll.Add(20);
    dll.Add(25);
    dll.Add(30);
    dll.Add(50);
    dll.PrintForward();

    dll.PrintReverse();

    dll.Delete(20);
    dll.Delete(50);
    cout<<endl;
    dll.PrintForward();

    cin.get();

    return 0;
}
