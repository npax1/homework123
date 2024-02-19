#include <iostream>

using namespace std;



class Clothes
{
public:
	virtual void creating() const = 0;
	virtual ~Clothes() {};
};

class TShirt : public Clothes
{
public:
	void creating() const override
	{
		cout << "T-Shirt has been created." << endl;
	}
};

class Pants : public Clothes
{
public:
	void creating() const override
	{
		cout << "Pants has been created." << endl;
	}
};

class Jacket : public Clothes
{
public:
	void creating() const override
	{
		cout << "Jacket has been created." << endl;
	}
};


class Electronic
{
public:
	virtual void creating() const = 0;
	virtual ~Electronic() {};
};

class Phone : public Electronic
{
public:
	void creating() const override
	{
		cout << "Phone has been created." << endl;
	}
};

class Laptop : public Electronic
{
public:
	void creating() const override
	{
		cout << "Laptop has been created." << endl;
	}
};

class TV : public Electronic
{
public:
	void creating() const override
	{
		cout << "TV has been created." << endl;
	}
};

class FactoryOfGoods
{
public:
	virtual Clothes* createClothesItem() const = 0;
	virtual Electronic* createElectronicItem() const = 0;
};

class ClothesFactory : public FactoryOfGoods
{
public:
	Clothes* createClothesItem() const override
	{
		cout << "1 - T-Shirt | 2 - Pants | 3 - Jacket" << endl;
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 1:
			return new TShirt();
			break;
		case 2:
			return new Pants();
			break;
		case 3:
			return new Jacket();
			break;
		default:
			break;
		}
	}
	Electronic* createElectronicItem() const override
	{
		return 0;
	}
};

class ElectronicFactory : public FactoryOfGoods
{
public:
	Clothes* createClothesItem() const override
	{
		return 0;
	}
	Electronic* createElectronicItem() const override
	{
		cout << "1 - TV | 2 - Phone | 3 - Laptop" << endl;
		int ch;
		cin >> ch;
		switch (ch)
		{
		case 1:
			return new TV();
			break;
		case 2:
			return new Phone();
			break;
		case 3:
			return new Laptop();
			break;
		default:
			break;
		}
	}
};