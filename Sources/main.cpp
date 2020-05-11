#include <Irrlicht/irrlicht.h>
#include <iostream>
#include <Bindable.hpp>

using namespace irr;

void onUpdate(const float& aaa)
{
	std::cout << "Value updated!! " << aaa << std::endl;
}

int main()
{
	Bindable t(0.0f, onUpdate);

	t = 3.654f;
	t.SetValue(0.065f);
	system("PAUSE");
	return 0;
}