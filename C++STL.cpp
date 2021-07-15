
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
	string GetName();
	int GetId();
	int GetDateBirthday();
	string GetWork();


private:
	string name_;
	string work_;
	int id_;
	int date_birthday_;
};

User::User()
{
}

User::User(string name, int id, int date_birthday, string work):
	name_(name), id_(id), date_birthday_(date_birthday), work_(work)
{
}

void User::Print() {
	cout << "Name - "<<name_ << endl;
	cout <<"Id - "<< id_ << endl;
	cout << "Date birthday - "<<date_birthday_ << endl;
}

string User::GetName()
{
	return name_;
}

int User::GetId()
{
	return id_;
}

int User::GetDateBirthday()
{
	return date_birthday_;
}

string User::GetWork()
{
	return work_;
}

ostream& operator<< (ostream& os, User& user) {
	os << user.GetName() << " " << user.GetId() << " " << user.GetDateBirthday();
	return os;
}
template <typename T> 

void PrintList( list<T> &list) {
	for (auto it = list.begin(); it != list.end(); ++it) {
		cout << *it << endl;
	}
}


int main()
{
	User Sasha("Sasha", 45, 2000, "Бухает");
	User Gena("Gena", 7, 1990, "Football");
	User Mark("Mark", 21, 2003, "History Proffesor");
	User Sergey("Sergey", 2, 1987, "Programmer C++ / C#. #SimpleCode.");
	User Dias("Dias", 78, 1978, "CJNG");
	vector <User> user{ Sasha, Gena, Mark, Sergey };
	/*for (auto& item : user) {
		cout << item << endl;
	}
	
	/*for (vector <User>::iterator it = user.begin(); it != user.end(); it++) {
		cout << *it << endl;
	} */
	
	//list <User> user_list{ Sasha, Gena, Mark, Sergey};
	/*user_list.push_front(Dias);
	cout << "i++" << endl;
	cout << "---------------------------" << endl;
	for (auto it = user_list.begin(); it != user_list.end(); it++) {
		cout << *it << endl;
	}

	cout << "___________________________ ++i" << endl;
	PrintList(user_list);
	cout << "______________________pop_back" << endl;
	user_list.pop_back();
	PrintList(user_list);
	user_list.pop_front();
	cout <<"______________________pop_front" << endl;
	PrintList(user_list);
	return 0; */
	
	//forward_list<User> user_fl;
	//deque<User> user_d{ Sasha, Gena, Mark, Sergey };
/*	set<int> set_int{ 65, 54, 32, 45 };
	for (auto& item : set_int) {
		cout << item << endl;
	}

	set_int.erase(65);
	set_int.insert(22);
	
	for (auto &item : set_int) {
		cout << item << endl;
	} 

	/*pair<User, string> user_pair(Sergey, "Programmer C++/C#. #SimpleCode.");
	cout << user_pair.first<< endl;
	cout << user_pair.second << endl; */
/*	map<string, int> vodka_map;

   vodka_map.emplace("Sergey", 546);

	vodka_map.emplace("Sasha", 5464);

	vodka_map.emplace("Dias", 4564);
	
	cout << vodka_map["Dias"] << endl; */

	/* <User, vector<User>> stack_user;
	stack_user.emplace(Sergey);
	stack_user.emplace(Sasha);
	stack_user.emplace(Dias);
	stack_user.emplace(Mark);
	stack_user.pop();

	priority_queue <int, vector<int>> uq;

	uq.emplace(43);
	uq.emplace(32);
	uq.emplace(86);
	uq.emplace(343);  */


    
	return 0;
}