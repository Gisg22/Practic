
#include <iostream>
using namespace std;

template<typename T>

class vector
{
public:
	vector();
	~vector();
	void pop_front();
	void clear();
	void push_back(T data);
	int GetSize();
	T& operator[] (const int index);
	void push_front(T data);
	void insert(T value, int index);
	void removeAt(int index);
	void pop_back();

private:
	template<typename T>

	class Node {
	public:
		Node* pNext_;
		T data_;
		Node(T data = T(), Node *pNext = nullptr)
			: data_(data), pNext_(pNext){}
	};
	int size;
	
	Node <T> *head;
};

template<typename T>

vector<T>::vector()
{
	size = 0;
	head = nullptr;
}

template<typename T>

vector<T>::~vector()
{
	clear();
}

template<typename T>
void vector<T>::pop_front()
{
	Node <T> *temp = head;
	head = head->pNext_;
	delete temp;
	size--;
}

template<typename T>
void vector<T>::clear()
{
	while (size) {
		pop_front();
	}
}

template<typename T>

void vector<T>::push_back(T data) {
	if (head == nullptr) {
		head = new Node <T>(data);
	}

	else {
		Node<T>* current = head;

		while (current->pNext_ != nullptr) {
			current = current->pNext_;
		}

		current->pNext_ = new Node <T>(data);

	}
	size++;
}



int vector<int>::GetSize() {
	return size;
}

template<typename T>
T& vector<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = head;
	while (current !=nullptr) {
		if (counter == index) {
			return current->data_;
		}
		current = current->pNext_;
		counter++;
	}
}

template<typename T>
void vector<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;

}

template<typename T>
void vector<T>::insert(T value, int index)
{
	if (index == 0) {
		push_front(value);
	}
	else {
		Node <T>* previous = head;
		for (int i = 0; i < index-1; i++) {
			previous = previous->pNext_;
		}

		previous->pNext_ = new Node<T>(value, previous->pNext_);
		size++;

	}

}

template<typename T>
void vector<T>::removeAt(int index)
{
	if (index == 0) {
		pop_front();
	}
	else {
		Node <T>* previous = head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext_;
		}

		Node<T> *toDelete = previous->pNext_;
		previous->pNext_ = toDelete->pNext_;
		delete toDelete;
		size--;

	}
}

template<typename T>
void vector<T>::pop_back()
{
	removeAt(size - 1);
}

int main()
{

	vector <int> number;
	number.push_back(3);
	number.push_back(7);
	number.push_back(10);
	number.push_back(1);
	number.push_back(8);
	number.insert(72, 3);
	for (int i = 0; i < number.GetSize(); i++) {
		cout << number[i] << endl;
	}

    return 0;
}

