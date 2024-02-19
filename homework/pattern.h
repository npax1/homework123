#include <iostream>

using namespace std;

class Weapon
{
public:
	virtual int fireRange() const = 0;
	virtual string damageType() const = 0;
	virtual int criticalDamageBonus() const = 0;
	virtual ~Weapon() {};
};

class Sword : public Weapon
{
public:
	Sword()
	{
		this->fire_range = 1;
		this->damage_type = "Multi";
		this->critical_damage_bonus = 5;
	};

	int fireRange() const override
	{
		return this->fire_range;
	}
	string damageType() const override
	{
		return this->damage_type;
	}
	int criticalDamageBonus() const override
	{
		return this->critical_damage_bonus;
	}

private:
	int fire_range;
	string damage_type;
	int critical_damage_bonus;
};

class Bow : public Weapon
{
public:
	Bow()
	{
		this->fire_range = 10;
		this->damage_type = "Single";
		this->critical_damage_bonus = 3;
	};

	int fireRange() const override
	{
		return this->fire_range;
	}
	string damageType() const override
	{
		return this->damage_type;
	}
	int criticalDamageBonus() const override
	{
		return this->critical_damage_bonus;
	}

private:
	int fire_range;
	string damage_type;
	int critical_damage_bonus;
};

class Dagger : public Weapon
{
public:
	Dagger()
	{
		this->fire_range = 1;
		this->damage_type = "Single";
		this->critical_damage_bonus = 5;
	};

	int fireRange() const override
	{
		return this->fire_range;
	}
	string damageType() const override
	{
		return this->damage_type;
	}
	int criticalDamageBonus() const override
	{
		return this->critical_damage_bonus;
	}

private:
	int fire_range;
	string damage_type;
	int critical_damage_bonus;
};

class FactoryOfWeapon
{
public:
	virtual Weapon* factoryMethod() const = 0;
	virtual ~FactoryOfWeapon() {};

	void CreateWeapon() const
	{
		Weapon* weapon = this->factoryMethod();
		cout << "Created weapon with characteristics: \nFire range | Damage type | Bonus\n" << "    " << weapon->fireRange() << "\t\t" << weapon->damageType() << "\t     " << weapon->criticalDamageBonus() << "\t" << endl;
	}
};

class FactoryOfSword : public FactoryOfWeapon
{
public:
	Weapon* factoryMethod() const override
	{
		return new Sword();
	}
};

class FactoryOfBow : public FactoryOfWeapon
{
public:
	Weapon* factoryMethod() const override
	{
		return new Bow();
	}
};

class FactoryOfDagger : public FactoryOfWeapon
{
public:
	Weapon* factoryMethod() const override
	{
		return new Dagger();
	}
};

void performing(const FactoryOfWeapon& fow)
{
	fow.CreateWeapon();
}