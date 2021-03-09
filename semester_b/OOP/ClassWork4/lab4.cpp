#include <string>
#include <iostream>
#include "lab4.h"
using namespace std;

//Node Functions

int Node::op_code_counter = 1;

void Node::set_amount(int a)
{
	amount = a;
}

void Node::set_name(string n)
{
	name = n;
}

int Node::get_amount()
{
	return(amount);
}

string Node::get_name()
{
	return(name);
}

int Node::get_code()
{
	return(op_code);
}


Node::Node()
{
	
	op_code = NULL;
	Node::set_amount(0);
	Node::set_name("");
}

void Node::Create_new_account()
{
	cout << "opcode counter in create:" << op_code_counter << endl;
	op_code = op_code_counter;
	
	op_code_counter++;
	int a;
	string n;
	cout << "enter your name and amount of money: " << endl;
	cin >> n >> a;
	Node::set_amount(a);
	Node::set_name(n);
}

void Print_Node(Node n)
{
	if (n.get_code() != 0)
	{
		cout << "account number: " << n.get_code() << " name: " << n.get_name() << " amount of cash: " << n.get_amount() << endl;
	}
}


//Queue functions


int Queue::get_top_pos()
{
	return(top);
}

int Queue::get_bot_pos()
{
	return(bottom-1);
}

int Queue::get_size()
{
	return(size);
}

Node* Queue::get_array()
{
	return(node_array);
}

void Print_Queue(Queue q)
{
	int j = 1, i,top_pos= q.get_top_pos(),size=q.get_size();
	Node* ptr_arr = q.get_array();
	for (i = top_pos; i < size + top_pos; i++)
	{
		cout << "number " << j << " in queue" << endl;
		Print_Node(ptr_arr[i]);
		j++;
	}
}

void Queue::Add_Node(Node n)
{  
	node_array[bottom++] = n;
	size++;
}

Node Queue::Get_Node()
{
	if (Is_Empty())
	{
		cout<<"queue is empty!"<<endl;
		Node n;
		return(n);
	}
	else
	{
		int temp = top;
		top++;
		size--;
		return(node_array[temp]);
	}
}

Node Queue::Top_Node()
{
	if (Is_Empty())
	{
		cout << "queue is empty!" << endl;
		Node n;
		return(n);
	}
	else
	{
		return(node_array[top]);
	}
}


bool Queue::Is_Empty()
{
	if (size == 0)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}
Queue::Queue()
{
	node_array = new Node[1000];
	size = 0;
	top = 0;
	bottom = 0;
}
