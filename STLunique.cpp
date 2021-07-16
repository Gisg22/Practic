#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <forward_list>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>

using namespace std;

class User {
public:
	User();
	User(string name, int id, int date_birthday, string work);
	void Print();
	string GetName() const;
	int GetId() const;
	int GetDateBirthday() const;
	string GetWork() const;
	bool operator ==(const User& us);

private:
	string name_;
	string work_;
	int id_;
	int date_birthday_;
};

User::User() {}

User::User(string name, int id, int date_birthday, string work) :
	name_(name), id_(id), date_birthday_(date_birthday), work_(work)
{
}

void User::Print() {
	cout << "Name - " << name_ << endl;
	cout << "Id - " << id_ << endl;
	cout << "Date birthday - " << date_birthday_ << endl;
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

bool User::operator==(const User& us)
{
	return name_ == us.name_ &&(id_ == us.id_) && (date_birthday_ == us.date_birthday_) && (work_ == us.work_);
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
	vector <User> user{ Sergey, Sergey, Vlad, Temirlan, Chehov, Chehov };
	vector <User> user2{ Sergey, Sergey, Vlad, Temirlan, Chehov, Chehov };
	for (auto& item : user) {
		cout << item << endl;
	}
	auto result = unique(begin(user), end(user)); //удаляет все повторяющие элеметы или объекты
	user.erase(result, end(user));
	cout << "DELETE: " << endl;
	for (auto & item : user) {
		cout << item << endl;
	}
	
	return 0;
};