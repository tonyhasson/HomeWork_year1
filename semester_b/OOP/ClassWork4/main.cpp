#include <string>
#include <iostream>
#include "lab4.h"
using namespace std;

void main()
{
	Queue q;
	//q.Create_Queue();
	Node n;
	int i,client_num;
	cout << "enter amount of clients:" << endl;
	cin >> client_num;
	for (i = 0; i < client_num; i++)
	{
		
		n.Create_new_account();
		q.Add_Node(n);
		
	}
  //example for trying out the functions
	Print_Queue(q);
	cout << "" << endl;
	Node* arr = q.get_array();
	arr[q.get_top_pos()].set_amount(1982);
	string s = arr[q.get_bot_pos()].get_name();
	cout << "name is : " << s << endl;
	arr[q.get_bot_pos()].set_name("inbar");
	Print_Queue(q);
	cout << "" << endl;
	n=q.Get_Node();
	Print_Queue(q);
	cout << "" << endl;
	Print_Node(n);
	cout << "" << endl;
	Print_Node(q.Get_Node());
	Print_Node(q.Get_Node());
	Print_Node(q.Get_Node());


	
}
