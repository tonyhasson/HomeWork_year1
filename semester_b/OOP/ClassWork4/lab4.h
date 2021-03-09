#pragma once
#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
	Node();
	int get_amount();
	string get_name();
	int get_code();
	void set_amount(int);
	void set_name(string);
	void Create_new_account();
	friend void Print_Node(Node);
    

private:
	int amount;
	int op_code;
	string name;
	static int op_code_counter;
	
};

class Queue
{
public:
	//void Create_Queue();
	Queue();
	void Add_Node(Node);
	Node Get_Node();
	Node Top_Node();
	bool Is_Empty();
	int get_top_pos();
	int get_bot_pos();
	int get_size();
	Node* get_array();
	friend void Print_Queue(Queue);

private:
	const int capacity=INT_MAX;
	int size;
	int top;
	int bottom;
	Node* node_array;

};
