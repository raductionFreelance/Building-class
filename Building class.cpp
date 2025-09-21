#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
private:
    string* name = new string;
    int* age = new int;
public:
    Person() {
		*name = "No name";
		*age = 0;
    };
	Person(const string& n, const int& a) {
		*name = n;
		*age = a;
    };
	Person(const Person& p) {
		name = new string(*p.name);
		age = new int(*p.age);
	};

	Person& operator=(const Person& other) {
		if (this != &other) {
			*name = *other.name;
			*age = *other.age;
		}
		return *this;
	}

    void add() {
		cin.ignore();
		cout << "Enter name: ";
		getline(cin, *name);
		cout << "Enter age: ";
        cin >> *age;
    }

	void print() {
		cout << "Name: " << *name << ", Age: " << *age << endl;
	}

	~Person() {
		delete name;
		delete age;
	}
};

class Apartmant {
private:
	vector<Person> residents;
	int* rooms = new int;
	int* anumber = new int;
public:
	Apartmant() : rooms(new int(0)), anumber(new int(0)) {};
	Apartmant(vector<Person> p, int r) : residents(p), rooms(new int(r)) {};

	Apartmant(const Apartmant& a) {
		residents = a.residents;
		rooms = new int(*a.rooms);
		anumber = new int(*a.anumber);
	}

	Apartmant& operator=(const Apartmant& a) {
		if (this != &a) {
			residents = a.residents;
			*rooms = *a.rooms;
			*anumber = *a.anumber;
		}
		return *this;
	}


	void add() {
		cout << "Enter your apartmants number: ";
		cin >> *anumber;
		cout << "Enter number of rooms: ";
		cin >> *rooms;
		cout << "Enter number of residents: ";
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			Person p;
			p.add();
			residents.push_back(p);
		}
	}

	void print() {
		cout << "Apartmant number: " << *anumber << ", Rooms: " << *rooms << endl;
		for (int i = 0; i < residents.size(); i++) {
			residents[i].print();
		}
	}

	~Apartmant() {
		delete rooms;
		delete anumber;
	}
};

class Building {
private:
	vector<Apartmant> apartmants;
	string* address = new string;
public:
	Building() : address(new string("No address")) {};
	Building(vector<Apartmant> a, string addr) : apartmants(a), address(new string(addr)) {};

	Building(const Building& b) {
		apartmants = b.apartmants;
		address = new string(*b.address);
	};

	Building& operator=(const Building& b) {
		if (this != &b) {
			apartmants = b.apartmants;
			*address = *b.address;
		}
		return *this;
	}

	void add() {
		cout << "Enter address: ";
		getline(cin, *address);
		cout << "Enter number of apartmants: ";
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			Apartmant a;
			a.add();
			apartmants.push_back(a);
		}
	}

	void print() {
		cout << "Address: " << *address << endl;
		for (int i = 0; i < apartmants.size(); i++) {
			apartmants[i].print();
		}
	}

	~Building() {
		delete address;
	}
};





int main()
{
	Building b;
	b.add();
	b.print();
	return 0;
}

