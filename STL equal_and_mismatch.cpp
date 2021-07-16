#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <array>
#define _DEL_ cout <<"-------------------------------------" << endl;
using namespace std;

class User {
public:
	User();
	User(string name, int id, int date_birthday, string work);
	string GetName() const;
	int GetId() const;
	int GetDateBirthday() const;
	string GetWork() const;
	bool operator==(const User &u);

private:
	string name_;
	string work_;
	int id_;
	int date_birthday_;
};

User::User()
{
}

User::User(string name, int id, int date_birthday, string work) :
	name_(name), id_(id), date_birthday_(date_birthday), work_(work)
{
}

string User::GetName() const
{
	return name_;
}

int User::GetId() const
{
	return id_;
}

int User::GetDateBirthday() const
{
	return date_birthday_;
}

string User::GetWork() const
{
	return work_;
}

bool User::operator==(const User& u)
{
	return name_ == u.name_ && id_ == u.id_ && date_birthday_ == u.date_birthday_ && work_ == u.work_;
}

ostream& operator<< (ostream& os, User& user) {
	os << user.GetName() << " " << user.GetId() << " " << user.GetDateBirthday();
	return os;
}



int main() {
	User Sergey("Sergey", 43, 1998, "Simple code");
	User Vlad("Vlad", 23, 2004, "Print dick");
	User Temirlan("Rerror", 12, 2003, "Wed fuck");
	User Chehov("Chehov", 432, 2005, "Fuck Brains");
	User Sanya("Sanya", 345, 2000, "Vodka");
	array<User, 4> arr_us1{ Sergey, Vlad, Temirlan, Chehov};
	array<User, 4> arr_us2{ Sergey, Vlad, Temirlan, Chehov};
	bool result = equal(begin(arr_us1), end(arr_us1), begin(arr_us2), [](const User&u1, const User& u2) {
		return u1.GetName() == u2.GetName();
		}); 
	bool result_ = equal(begin(arr_us1), end(arr_us1), begin(arr_us2));
	cout << "Array: " << endl;
	cout << result << endl;
	cout << result_ << endl; //равенство массивов

	_DEL_

	cout << "Vector & array: " << endl;
	vector <User> user1{ Sergey, Vlad, Temirlan, Chehov};
	vector <User> user2{ Chehov, Sergey, Vlad, Temirlan};


	sort(begin(user1), end(user1), [](const User& u1, const User& u2) {
		return u1.GetId() > u2.GetId();                                  //сортировка
		});

	sort(begin(user2), end(user2), [](const User &u1, const User& u2) {
		return u1.GetId() > u2.GetId();
		});


	bool result_vector1_arr = equal(begin(user1), end(user1), begin(arr_us2), [](const User& u1, const User& u2) {
		return u1.GetName() == u2.GetName();
		});
	bool result_vector2_arr = equal(begin(user1), end(user1), begin(arr_us2));
	cout << result_vector1_arr << endl;
	cout << result_vector2_arr << endl;

	//равенство из двух разных контейнеров
	_DEL_

	cout << "Vector:" << endl;
	bool result_vector1 = equal(begin(user1), end(user1), begin(user2), [](const User& u1, const User& u2) {
		return u1.GetName() == u2.GetName();
		});

	bool result_vector2 = equal(begin(user1), end(user1), begin(user2));
	cout << result_vector1 << endl;
	cout << result_vector2 << endl; //равенство вектора
	cout << "Mismatch:" << endl;

	auto result_mismatch = mismatch(begin(arr_us1) , end(arr_us1), begin(arr_us2), end(arr_us2));

	if (result_mismatch.first == end(arr_us1) && result_mismatch.second ==end(arr_us2))
	{
		cout << "+" << endl;
	}
	else
	{
		cout << "-" << endl;
	}
	return 0;
}