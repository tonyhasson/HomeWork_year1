#include "Square.h"


//adding two squares objects
Square Square::operator+(Square s)
{
	double new_x,new_y,new_length;
	new_x = this->get_point().get_x() + s.get_point().get_x();
	new_y = this->get_point().get_y() + s.get_point().get_y();
	new_length = this->get_length() + s.get_length();
	Square s_new(new_x, new_y, new_length);
	return(s_new);
}
//printing square object
void Square::Print_Square()
{
	cout << "point is: (" << this->get_point().get_x() << "," << this->get_point().get_y() << ") , length is: " << this->get_length() << endl;
	
}
//getting area size
double Square::Area()
{
	double a = this->get_length() * this->get_length();
	return(a);
}
//checking if given point is inside area
void Square::In_Area(Point p1)
{
	if (p1.get_x() >= this->get_point().get_x() && p1.get_y() >= this->get_point().get_y())
	{
		double x2 = p1.get_x(),x1= this->get_point().get_x(), y2 =p1.get_y(), y1 = this->get_point().get_y();
		double calc_x = pow(x2 - x1, 2), calc_y = pow(y2 - y1, 2);
		double sum = calc_x + calc_y;
		if (sqrt(sum)<=length*sqrt(2))
		{
			cout << "point (" << x2 << "," << y2 << ") is in square" << endl;
			
		}
		else
		{
			cout << "point ("<<x2<<","<<y2<<") is not in square" << endl;
		}
	}
	else
	{
		cout << "point (" << p1.get_x() << "," << p1.get_y() << ") is not in square" << endl;
	}
}
