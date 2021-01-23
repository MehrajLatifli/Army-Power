#include<iostream>
#include<assert.h>
#include <iomanip>
#include <string>
using namespace std;

class Person {
	string name;
	string surname;
	int age;
public:
	Person() : name(""), surname(""), age(0) {}

	Person(const string& name, const string& surname, const int age)
	{
		setName(name);
		setSurname(surname);
		setAge(age);
	}

	Person(const Person& person)
	{
		setName(person.name);
		setSurname(person.surname);
		setAge(person.age);
	}

	Person& operator=(const Person& person)
	{
		setName(person.name);
		setSurname(person.surname);
		setAge(person.age);

		return *this;
	}

	string getName() const {
		return this->name;
	}

	void setName(const string& name)
	{
		//assert(!name.empty() && " Name is empty. ");
		this->name = name;
	}

	string getSurname() const {
		return this->surname;
	}

	void setSurname(const string& surname)
	{
		//assert(!name.empty() && " Surname is empty. ");
		this->surname = surname;
	}

	int getAge() const {
		return this->age;
	}

	void setAge(const int& age)
	{
		//assert(age > 0 && " Age is empty. ");
		this->age = age;
	}

	virtual void show()const
	{
		cout << " Person name: \t\t\t" << getName() << endl;
		cout << " Person surname: \t\t" << getSurname() << endl;
		cout << " Person age: \t\t\t" << getAge() << endl;
	}

	~Person()
	{

	}

};


class Comander : public Person {
	double army_work_practise;
	double victory_count;
	string army_no;
public:
	Comander() :army_work_practise(0.0), victory_count(0.0), army_no(" ") {}

	Comander(const string& name, const string& surname, const int age, const double army_work_practise, const double victory_count, const string army_no) : Person(name, surname, age)
	{
		setArmy_work_practise(army_work_practise);
		setVictory_count(victory_count);
		setArmy_no(army_no);
	}

	Comander(const Comander& comander)
	{
		setName(comander.getName());
		setName(comander.getSurname());
		setAge(comander.getAge());

		setArmy_work_practise(comander.army_work_practise);
		setVictory_count(comander.victory_count);
		setArmy_no(comander.army_no);
	}


	Comander& operator=(const Comander& comander)
	{
		setName(comander.getName());
		setName(comander.getSurname());
		setAge(comander.getAge());

		setArmy_work_practise(comander.army_work_practise);
		setVictory_count(comander.victory_count);
		setArmy_no(comander.army_no);

		return *this;
	}

	double getArmy_work_practise()const {
		return this->army_work_practise;
	}

	void setArmy_work_practise(const double& army_work_practise)
	{
		assert(army_work_practise > 0 && " Army work practise is empty. ");
		this->army_work_practise = army_work_practise;
	}

	double getVictory_count()const {
		return this->victory_count;
	}

	void setVictory_count(const double& victory_count)
	{
		assert(victory_count > 0 && " Victory count is empty. ");
		this->victory_count = victory_count;
	}

	string getArmy_no()const {
		return this->army_no;
	}

	void setArmy_no(const string& army_no)
	{
		assert(!army_no.empty() && " Army no is empty. ");
		this->army_no = army_no;
	}

	~Comander()
	{

	}
};

class Fighter {
	float fight_power;
	string weapon;
public:
	Fighter() :fight_power(0.0), weapon("") {}
	Fighter(const float fight_power, const string weapon)
	{
		setFight_power(fight_power);
		setWeapon(weapon);
	}

	Fighter(const Fighter& fighter)
	{
		setFight_power(fighter.fight_power);
		setWeapon(fighter.weapon);
	}


	Fighter& operator=(const Fighter& fighter)
	{
		setFight_power(fighter.fight_power);
		setWeapon(fighter.weapon);


		return *this;
	}


	float getFight_power()const {
		return this->fight_power;
	}

	void setFight_power(const float& fight_power)
	{
		//assert(fight_power > 0 && " Fight power is empty. ");
		this->fight_power = fight_power;
	}

	string getWeapon()const {
		return this->weapon;
	}

	void setWeapon(const string& weapon)
	{
		//assert(!weapon.empty() && " Weapon is empty. ");
		this->weapon = weapon;
	}

	void showFighter()const
	{
		cout << " Fighter's fight power: \t" << getFight_power() << endl;
		cout << " Fighter's weapon: \t\t" << getWeapon() << endl;

	}

	void attack() {
		cout << " Fighter's attacked with: \t" << getFight_power() << endl;
		cout << " Fighter's damage: \t\t" << getWeapon() << endl;
	}


};





class Soldier :public Person, public Fighter {
	int  solider_id;
public:
	static int id;
	Soldier() :solider_id(0) {}

	Soldier(const string& name, const string& surname, const int age, const float fight_power, const string weapon) : Person(name, surname, age), Fighter(fight_power, weapon) {
		setSolider_id(++solider_id);
	}

	Soldier(const Soldier& soldier)
	{
		this->solider_id = ++id;
		setName(soldier.getName());
		setSurname(soldier.getSurname());
		setAge(soldier.getAge());
		setFight_power(soldier.getFight_power());
		setWeapon(soldier.getWeapon());
	}

	Soldier& operator=(const Soldier& soldier)
	{
		this->solider_id = soldier.id;
		setName(soldier.getName());
		setSurname(soldier.getSurname());
		setAge(soldier.getAge());
		setFight_power(soldier.getFight_power());
		setWeapon(soldier.getWeapon());

		return *this;
	}

	void setSolider_id(int& id)
	{
		//assert(id > 0 && "ID is empty");
		this->solider_id = ++id;
	}

	static int getSolider_id() {
		return id;
	}

	void show() const {
		cout << " Soldier id: \t\t\t" << this->solider_id << endl;
		Person::show();
		Fighter::showFighter();
		cout << endl;
	}
	friend ostream& operator<<(ostream& out, const Soldier& soldier);
};

ostream& operator<<(ostream& out, const Soldier& soldier)
{
	soldier.show();

	return out;
}


int Soldier::id = NULL;


template <class T>
class Stack
{
	T* data;
	size_t size = 0;
public:
	T* getData() {
		return data;
	}
	Stack() : data(nullptr), size(0) {}
	void push(T value)
	{
		size_t N = this->size + 1;
		T* tmp = new T[N];
		if (tmp != nullptr)
		{
			if (N - 1)
			{
				for (size_t i = 0; i < N - 1; i++)
				{
					tmp[i] = this->data[i];
				}
				delete[] this->data;
			}
			tmp[N - 1] = value;
			this->size++;
			this->data = tmp;
		}
	}
	T pop()
	{
		T deleted;
		if (!isEmpty())
		{
			size_t N = this->size - 1;
			T* tmp = new T[N];
			if (tmp != nullptr)
			{
				deleted = data[N];
				for (size_t i = 0; i < N; i++)
				{
					tmp[i] = data[i];
				}
				delete[] this->data;
				this->data = tmp;
				this->size--;
			}
		}
		return deleted;
	}
	bool isEmpty() { return size == 0; }
	T& peek() const
	{
		return data[size - 1];
	}
	size_t getSize() const
	{
		return this->size;
	}
	inline void clear()
	{
		if (this->data != nullptr)
		{
			delete[] this->data;
			this->data = nullptr;
			this->size = 0;
		}
	}
	~Stack()
	{
		//clear();
	}
};


class Tank : public Fighter {
	string vehicle_name;
	Stack<Soldier> stack_soldiers;
public:
	Tank() : vehicle_name("") {
	}

	Tank(const float& fight_power, const string& weapon, const string& vehicle_name) :
		Fighter(fight_power, weapon)
	{
		setVehicle_name(vehicle_name);
	}

	Tank(const Tank& vehicle)
	{
		setFight_power(vehicle.getFight_power());
		setWeapon(vehicle.getWeapon());
		setVehicle_name(vehicle.getVehicle_name());
		setStack(vehicle.getStack());
	}


	Tank& operator=(const Tank& vehicle)
	{
		setFight_power(vehicle.getFight_power());
		setWeapon(vehicle.getWeapon());
		setVehicle_name(vehicle.getVehicle_name());
		setStack(vehicle.getStack());

		return *this;

	}


	string getVehicle_name()const {
		return this->vehicle_name;
	}

	void setVehicle_name(const string& vehicle_name)
	{
		assert(!vehicle_name.empty() && " Tank name is empty. ");
		this->vehicle_name = vehicle_name;
	}

	const Stack<Soldier> getStack() const
	{
		return  this->stack_soldiers;
	}

	void setStack(const Stack<Soldier>& stack_soldiers)
	{
		this->stack_soldiers = stack_soldiers;
	}


	void addSolidier(const Soldier& soldiers)
	{
		stack_soldiers.push(soldiers);
	}

	void show() {
		if (stack_soldiers.isEmpty())
		{
			cout << "There is not in Warehouse!" << endl;
			return;
		}

		while (!stack_soldiers.isEmpty())
		{

			cout << stack_soldiers.pop();
			cout << " Tank name: \t\t\t" << getVehicle_name() << endl;
		}


	}



	friend ostream& operator<<(ostream& out, Tank& vehicle);
};

ostream& operator<<(ostream& out, Tank& vehicle)
{
	out << "Name of Vehicle : " << vehicle.vehicle_name << endl;
	out << "Fight power of Vehicle : " << vehicle.getFight_power() << endl;
	out << "Weapon of Vehicle : " << vehicle.getWeapon() << endl;
	int count = vehicle.stack_soldiers.getSize();
	for (size_t i = 0; i < count; i++)
	{
		vehicle.stack_soldiers.peek().show();
		vehicle.stack_soldiers.pop();
	}

	return out;
}

class MilitaryAircraft : public Fighter {
	string vehicle_name;
	Stack<Soldier> stack_soldiers;
public:
	MilitaryAircraft() : vehicle_name("") {
	}

	MilitaryAircraft(const float& fight_power, const string& weapon, const string& vehicle_name) :
		Fighter(fight_power, weapon)
	{
		setVehicle_name(vehicle_name);
	}

	MilitaryAircraft(const MilitaryAircraft& vehicle)
	{
		setFight_power(vehicle.getFight_power());
		setWeapon(vehicle.getWeapon());
		setVehicle_name(vehicle.getVehicle_name());
		setStack(vehicle.getStack());
	}


	MilitaryAircraft& operator=(const MilitaryAircraft& vehicle)
	{
		setFight_power(vehicle.getFight_power());
		setWeapon(vehicle.getWeapon());
		setVehicle_name(vehicle.getVehicle_name());
		setStack(vehicle.getStack());

		return *this;

	}


	string getVehicle_name()const {
		return this->vehicle_name;
	}

	void setVehicle_name(const string& vehicle_name)
	{
		assert(!vehicle_name.empty() && " Tank name is empty. ");
		this->vehicle_name = vehicle_name;
	}

	const Stack<Soldier> getStack() const
	{
		return  this->stack_soldiers;
	}

	void setStack(const Stack<Soldier>& stack_soldiers)
	{
		this->stack_soldiers = stack_soldiers;
	}


	void addSolidier(const Soldier& soldiers)
	{
		stack_soldiers.push(soldiers);
	}

	void show() {
		if (stack_soldiers.isEmpty())
		{
			cout << "There is not vehile in Warehouse!" << endl;
			return;
		}

		while (!stack_soldiers.isEmpty())
		{

			cout << stack_soldiers.pop();
			cout << " MilitaryAircraft name: \t" << getVehicle_name() << endl;
		}


	}



	friend ostream& operator<<(ostream& out, MilitaryAircraft& vehicle);
};

ostream& operator<<(ostream& out, MilitaryAircraft& vehicle)
{
	out << "Name of Vehicle : " << vehicle.vehicle_name << endl;
	out << "Fight power of Vehicle : " << vehicle.getFight_power() << endl;
	out << "Weapon of Vehicle : " << vehicle.getWeapon() << endl;
	int count = vehicle.stack_soldiers.getSize();
	for (size_t i = 0; i < count; i++)
	{
		vehicle.stack_soldiers.peek().show();
		vehicle.stack_soldiers.pop();
	}

	return out;
}


class MilitaryShip : public Fighter {
	string vehicle_name;
	Stack<Soldier> stack_soldiers;
public:
	MilitaryShip() : vehicle_name("") {
	}

	MilitaryShip(const float& fight_power, const string& weapon, const string& vehicle_name) :
		Fighter(fight_power, weapon)
	{
		setVehicle_name(vehicle_name);
	}

	MilitaryShip(const MilitaryShip& vehicle)
	{
		setFight_power(vehicle.getFight_power());
		setWeapon(vehicle.getWeapon());
		setVehicle_name(vehicle.getVehicle_name());
		setStack(vehicle.getStack());
	}


	MilitaryShip& operator=(const MilitaryShip& vehicle)
	{
		setFight_power(vehicle.getFight_power());
		setWeapon(vehicle.getWeapon());
		setVehicle_name(vehicle.getVehicle_name());
		setStack(vehicle.getStack());

		return *this;

	}


	string getVehicle_name()const {
		return this->vehicle_name;
	}

	void setVehicle_name(const string& vehicle_name)
	{
		assert(!vehicle_name.empty() && " Tank name is empty. ");
		this->vehicle_name = vehicle_name;
	}

	const Stack<Soldier> getStack() const
	{
		return  this->stack_soldiers;
	}

	void setStack(const Stack<Soldier>& stack_soldiers)
	{
		this->stack_soldiers = stack_soldiers;
	}


	void addSolidier(const Soldier& soldiers)
	{
		stack_soldiers.push(soldiers);
	}

	void show() {
		if (stack_soldiers.isEmpty())
		{
			cout << "There is not vehile in Warehouse!" << endl;
			return;
		}

		while (!stack_soldiers.isEmpty())
		{

			cout << " Military Ship name: \t\t" << getVehicle_name() << "\n";
			cout << stack_soldiers.pop() << endl;
		}


	}



	friend ostream& operator<<(ostream& out, MilitaryShip& vehicle);
};

ostream& operator<<(ostream& out, MilitaryShip& vehicle)
{
	out << "Name of Vehicle : " << vehicle.vehicle_name << endl;
	out << "Fight power of Vehicle : " << vehicle.getFight_power() << endl;
	out << "Weapon of Vehicle : " << vehicle.getWeapon() << endl;
	int count = vehicle.stack_soldiers.getSize();
	for (size_t i = 0; i < count; i++)
	{
		vehicle.stack_soldiers.peek().show();
		vehicle.stack_soldiers.pop();
	}

	return out;
}



class Army
{
	Stack<Soldier> stack_soldier;
	Stack<Tank> stack_tank;
	Stack<MilitaryAircraft> stack_MilitaryAircraft;
	Stack<MilitaryShip> stack_MilitaryShip;
	Comander comanders;
	int count;
public:
	Army() {}

	Army(Comander comanders)
	{

		setComander(comanders);
	}

	Army(const Army& army)
	{

		setStack_soldier(army.getStack_soldier());
		setStack_tank(army.getStack_tank());
		setStack_MilitaryAircraft(army.getStack_MilitaryAircraft());
		setStack_MilitaryShip(army.getStack_MilitaryShip());
		setComander(army.comanders);
	}

	Army& operator=(const Army& army)
	{

		setStack_soldier(army.getStack_soldier());
		setStack_tank(army.getStack_tank());
		setStack_MilitaryAircraft(army.getStack_MilitaryAircraft());
		setStack_MilitaryShip(army.getStack_MilitaryShip());
		setComander(army.comanders);

		return *this;
	}



	const Stack<Soldier> getStack_soldier() const
	{
		return  this->stack_soldier;
	}

	void setStack_soldier(const Stack<Soldier>& stack_soldiers)
	{
		this->stack_soldier = stack_soldier;
	}

	const Stack<Tank> getStack_tank() const
	{
		return  this->stack_tank;
	}

	void setStack_tank(const Stack<Tank> stack_tank)
	{
		this->stack_tank = stack_tank;
	}

	const Stack<MilitaryAircraft> getStack_MilitaryAircraft() const
	{
		return  this->stack_MilitaryAircraft;
	}

	void setStack_MilitaryAircraft(const Stack<MilitaryAircraft>& stack_MilitaryAircraft)
	{
		this->stack_MilitaryAircraft = stack_MilitaryAircraft;
	}

	const Stack<MilitaryShip> getStack_MilitaryShip() const
	{
		return  this->stack_MilitaryShip;
	}

	void setStack_MilitaryShip(const Stack<MilitaryShip>& stack_MilitaryShip)
	{
		this->stack_MilitaryShip = stack_MilitaryShip;
	}

	void showAllarmy()
	{
		showSoldier();
		showTank();
		showMilitaryAircraft();
		showMilitaryShip();
	}

	int getCount() const {
		return count;
	}

	void setCount(int count) {
		this->count = count;

	}

	Comander getComputer()const {
		return comanders;
	}

	void setComander(Comander comanders) {
		this->comanders = comanders;
	}

	void addSoldier(const Soldier& soldier)
	{
		stack_soldier.push(soldier);
	}

	void addTank(const Tank& tank)
	{
		stack_tank.push(tank);
	}

	void addMilitaryAircraft(const MilitaryAircraft& MilitaryAircraft)
	{
		stack_MilitaryAircraft.push(MilitaryAircraft);
	}

	void addMilitaryShip(const MilitaryShip& MilitaryShip)
	{
		stack_MilitaryShip.push(MilitaryShip);
	}

	void showMilitaryShip(const MilitaryShip& MilitaryShip)
	{
		stack_MilitaryShip.push(MilitaryShip);
	}

	void showSoldier()
	{
		if (stack_soldier.isEmpty())
		{
			cout << "Solider is not in army!" << endl;
			return;
		}

		while (!stack_soldier.isEmpty())
		{
			cout << stack_soldier.pop() << endl;
		}
	}

	void showTank()
	{
		if (stack_tank.isEmpty())
		{
			cout << "Tank is not  in army!" << endl;
			return;
		}
		while (!stack_tank.isEmpty())
		{
			stack_tank.pop().show();
		}
	}

	void showMilitaryAircraft()
	{
		if (stack_MilitaryAircraft.isEmpty())
		{
			cout << "Military Aircraft is not  in army!" << endl;
			return;
		}

		while (!stack_MilitaryAircraft.isEmpty())
		{
			stack_MilitaryAircraft.pop().show();
		}
	}

	void showMilitaryShip()
	{
		if (stack_MilitaryShip.isEmpty())
		{
			cout << "Military Ship is not  in army!" << endl;
			return;
		}

		while (!stack_MilitaryShip.isEmpty())
		{
			stack_MilitaryShip.pop().show();
		}
	}

	double getSoldierPower() {
		double sum1 = 0.0;
		for (size_t i = 0; i < stack_soldier.getSize(); i++)
		{
			Soldier soliderpower = stack_soldier.getData()[i];
			sum1 += soliderpower.getFight_power();
		}
		return sum1;
	}

	double getTankPower() {
		double sum2 = 0.0;
		for (size_t i = 0; i < stack_tank.getSize(); i++)
		{
			Tank tankpower = stack_tank.getData()[i];
			sum2 += tankpower.getFight_power();

		}
		return sum2;
	}

	double getMilitaryAircraftPower() {
		double sum3 = 0.0;
		for (size_t i = 0; i < stack_tank.getSize(); i++)
		{
			MilitaryAircraft MilitaryAircraftpower = stack_MilitaryAircraft.getData()[i];
			sum3 += MilitaryAircraftpower.getFight_power();

		}
		return sum3;
	}

	double getMilitaryShipPower() {
		double sum4 = 0.0;
		for (size_t i = 0; i < stack_tank.getSize(); i++)
		{
			MilitaryShip MilitaryShippower = stack_MilitaryShip.getData()[i];
			sum4 += MilitaryShippower.getFight_power();

		}
		return sum4;
	}

	double getArmyPower() {
		double sum5 = 0.0;

		sum5 = getMilitaryShipPower() + getMilitaryAircraftPower() + getTankPower() + getSoldierPower();
		return sum5;
	}


	~Army()
	{

	}

	friend ostream& operator<<(ostream& out, Army& army);
};

ostream& operator<<(ostream& out, Army& army)
{
	int count2 = army.stack_soldier.getSize();
	for (size_t i = 0; i < count2; i++)
	{
		out << "Solder : \n";  army.stack_soldier.peek().show();
		army.stack_soldier.pop();
		cout << endl;
		out << "Tank : \n";  army.stack_tank.peek().show();
		army.stack_tank.pop();
		cout << endl;


	}


	return out;
}




void main()
{
	Comander* c1 = new Comander("Mete", "Atilla", 40, 20, 500, "B24");

	Army army(*c1);

	Soldier soldier1("Mahmud", "Fazilov", 25, 50, "AK -45");
	Soldier soldier2("Eli", "Ibrahimli", 25, 70, "M6");
	Tank tank1(1000, "400 mm Top", "T35");
	Tank tank2(1000, "300 mm Top", "Leopar");
	tank1.addSolidier(soldier1);
	tank2.addSolidier(soldier2);
	army.addTank(tank1);
	army.addTank(tank2);



	Soldier soldier3("Hesen", "Cavidli", 27, 50, "AK -45");
	Soldier soldier4("Baqir", "Sahinli", 21, 70, "M6");
	MilitaryAircraft m_aircraft1(2500, "600 mm Top", "F 35");
	MilitaryAircraft m_aircraft2(2500, "600 mm Top", "M 40");
	m_aircraft1.addSolidier(soldier3);
	m_aircraft2.addSolidier(soldier4);
	army.addMilitaryAircraft(m_aircraft1);
	army.addMilitaryAircraft(m_aircraft2);


	Soldier soldier5("Mehdi", "Ekberli", 27, 50, "AK -45");
	Soldier soldier6("Bilal", "Mahmudlu", 21, 70, "M6");
	MilitaryShip m_ship1(5000, "1000 mm top", "Alyaska");
	MilitaryShip m_ship2(5000, "1000 mm top", "Ural");
	m_ship1.addSolidier(soldier5);
	m_ship2.addSolidier(soldier6);
	army.addMilitaryShip(m_ship1);
	army.addMilitaryShip(m_ship2);

	Soldier soldier7("Mahmud", "Qasimli", 25, 50, "AK -45");
	Soldier soldier8("Ekber", "Ibrahimli", 21, 70, "M6");
	army.addSoldier(soldier7);
	army.addSoldier(soldier8);




	cout << " Army common power: " << army.getArmyPower() << endl << endl;
	army.showAllarmy();






}
