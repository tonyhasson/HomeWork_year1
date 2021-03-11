class Point
{
public:
	Point(double a=0, double b=0) { x = a; y = b; }
	double get_x(){return(x);}
	void set_x(double new_x){x = new_x;}
	double get_y(){return(y);}
	void set_y(double new_y) { y = new_y; }

private:
	double x;
	double y;
};
