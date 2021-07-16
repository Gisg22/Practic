#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <array>
#include <ctime>

using namespace std;

class Animals
{
public:
	virtual void Speak() = 0;

};

class Cat : public Animals{
public:
	 virtual void Speak() override;

};

void Cat::Speak()
{
	cout << "Mrrrrrr......." << endl;
}

class Dog :public Animals {
public:
	virtual void Speak() override;

};

void Dog::Speak()
{
	cout << "GAFFF!!!!!!!" << endl;
}

class Parrot : public Animals {
public:
	virtual void Speak() override;
};

void Parrot::Speak()
{
	cout << "Temirlan alkash! Temirlan alkash! Temirlan alkash!" << endl;
}


int main() {
	array <int, 5> arr{ 4, 3, 7, 8, 5 };
	for (auto& item : arr) {
		cout << item << endl;
	}
	cout << "Random:" << endl;
	srand(time(NULL));
	random_shuffle(begin(arr), end(arr));
	for (auto& item : arr) {
		cout << item << endl;
	}
	cout << "__________________" << endl;
	cout << "class Animals: " << endl;
	Animals *animals[]{new Cat(), new Dog(), new Parrot()};
	
	for (auto& item : animals) {
		item->Speak();
	}
	cout << endl;

	cout << "Random: " << endl;

	random_shuffle(begin(animals), end(animals));

	for (auto& item : animals) {
		item->Speak();
	}
	cout << endl;


	//delete[] animals;
	//*animals = 0;
	return 0;
}
