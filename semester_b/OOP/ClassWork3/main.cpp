#include "Square.h"


void main()
{
	Square s;
	double area = s.Area();
	s.Print_Square();
	cout << "area of square is: " << area << endl;
	double x, y;
	cout << "enter x and y:" << endl;
	cin >> x >> y;
	Point p1(x,y);
	s.In_Area(p1);
	Square s2(1,5,8),s3(0,0,0);
	s3.Print_Square();
	s3 = s2 + s;
	s3.Print_Square();


	

}
