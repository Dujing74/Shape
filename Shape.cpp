#include<iostream>
using namespace std;
const double PI = 3.14;

class Shape
{
public:
	virtual double GetArea() = 0;
	virtual void SetDate() = 0;
protected:
	double area;
};

class Rectangle:public Shape
{
private:
	double width;
	double longth;
public:
	Rectangle(double w,double l):width(w),longth(l){}
	virtual double GetArea()
	{
		area = width * longth;
		return area;
	}
	virtual void SetDate()
	{
		cout << "Rectanle" << endl;
	}
};
class Circle :public Shape
{
private:
	double radius;
public:
	Circle(double r):radius(r){}
	virtual double GetArea()
	{
		area = radius * radius * PI;
		return area;
	}
	virtual void SetDate()
	{
		cout << "Circle" << endl;
		
	}
};
class Area
{
private:
	Shape* ptr;
	double total;
public:
	Area(Shape* p = NULL,double t=0) :ptr(p) {};
	void Total(Rectangle& r1,Circle& c1)
	{
		ptr = &r1;
		ptr->SetDate();
		total += ptr->GetArea();
		ptr = &c1;
		ptr->SetDate();
		total += ptr->GetArea();
	}
	void print()
	{
		cout << total << endl;
	}
};
void test01()
{
	Shape* p = new Rectangle(7.0, 4.0);
	p->SetDate();
	cout<<p->GetArea()<<endl;
	delete p;
	p = new Circle(7.0);
	p->SetDate();
	cout << p->GetArea() << endl;
}
/*void test02()
{
	Area a1;
	Rectangle r1(7.0, 4.0);
	Circle c1(7.0);
	a1.Total(r1, c1);
	a1.print();
}*/
int main()
{
	test01();
	return 0;
}