#pragma once
#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;
class Point;
class Square
{
public:
	//construcer without input in decleration
	Square()
	{
		double new_x, new_y, new_length;
		cout << "enter x,y and length: " << endl;
		cin >> new_x >> new_y >> new_length;
		set_point(new_x, new_y);
		while (new_length <= 0)
		{
			cout << "error! length is negetive,enter a positive length: " << endl;
			cin >> new_length;
		}
		set_length(new_length);
	}
	//construcer with input in decleration
	Square(double new_x,double new_y,double new_length)
	{
		set_point(new_x, new_y);
		if (new_length > 0)
		{
			set_length(new_length);
		}
		else
		{
			set_length(1);
		}

	}
	Square operator+(Square);
	Point get_point(){return(p);}
	void set_point(double new_x, double new_y)
	{
		p.set_x(new_x);
		p.set_y(new_y);
	}
	double get_length() { return(length); }
	void set_length(double new_length)
	{
		length = new_length;
	}
	void Print_Square();
	double Area();
	void In_Area(Point);
private:
	Point p;
	double length;
};
