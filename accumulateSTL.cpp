#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

class User {
public:
	User();
	User(string name, int id, int date_birthday, string work);
	string GetName() const;
	int GetId() const;
	int GetDateBirthday() const;
	string GetWork() const;


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

ostream& operator<< (ostream& os, User& user) {
	os << user.GetName() << " " << user.GetId() << " " << user.GetDateBirthday();
	return os;
}



int main() {
	User Sergey("Sergey", 43, 1998, "Simple code");
	User Vlad("Vlad", 23, 2004, "Print dick");
	User Temirlan("Rerror", 12, 2003, "Wed fuck");
	User Chehov("Chehov", 432, 2005, "Fuck Brains");
	vector <User> user{ Sergey, Vlad, Temirlan, Chehov };
	  auto result = accumulate(user.begin(), user.end(), 0, [](int i, const User &u) {
		return  u.GetId() + i; 
		});
        auto result_ = accumulate(user.begin(), user.end(), 0, [](int i, const User& u) {
		if (u.GetId() % 2 == 0) {
			return u.GetId() + i;
		}
		else {
			return i;
		}

		});

	//cout << result << endl;
	cout << result_ << endl;
	return 0;
}
