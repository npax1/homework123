#include "pattern.h"

int main()
{
	FactoryOfWeapon* fow = new FactoryOfBow();
	performing(*fow);
	cout << endl;
	FactoryOfWeapon* fow2 = new FactoryOfSword();
	performing(*fow2);
	cout << endl;
	FactoryOfWeapon* fow3 = new FactoryOfDagger();
	performing(*fow3);
	cout << endl;
}