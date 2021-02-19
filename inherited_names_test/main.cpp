#include <iostream>

class Base
{
public:
	virtual void mf1() = 0;
	virtual void mf1(int) { std::cout << "base mf1" << std::endl; }
	virtual void mf2() { std::cout << "base mf2" << std::endl; }
	void mf3() { std::cout << "base mf3 non" << std::endl; }
	void mf3(double) { std::cout << "base mf3" << std::endl; }

private:
	int x;
};

class Derived :public Base
{
public:
	using Base::mf1;
	using Base::mf3;
	virtual void mf1() { std::cout << "derived mf1" << std::endl; }
	void mf3() { std::cout << "derived mf3" << std::endl; }
	void mf4() { std::cout << "derived mf4" << std::endl; }
};

int main()
{
	Derived d;
	int x = 0;

	d.mf1();
	d.mf1(x);  //错误！因为derived::mf1遮掩了Base::mf1
	d.mf2();
	d.mf3();
	d.mf3(x); //错误！因为derived::mf3遮掩了Base::mf3
}