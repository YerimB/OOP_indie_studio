#include <Irrlicht/irrlicht.h>
#include <iostream>
#include <Bindable.hpp>

using namespace irr;

int onUpdate(int value)
{
	std::cout << "Value updated!! " << value << std::endl;
	return value;
}

int main()
{
	Bindable t(0.0f, onUpdate, 10);

	t = 3;
	system("PAUSE");
	return 0;
}