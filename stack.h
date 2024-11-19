#include <iostream>
using namespace std;

typedef int T;
class Stack {
	T* elements;
	int top_index = -1;
	int capacity = 1000000; //ø…¿©»›

public:
	Stack() { elements = new T[capacity]; }
	~Stack() { delete[]elements; }
	void push(const T& x) {
		if (top_index == capacity - 1)cout << "Stack Overflow!" << endl;
		elements[++top_index] = x;
	}
	void pop() {
		if (empty())cout << "Stack Empty!" << endl;
		top_index--;
	}
	T top() { 
		if (empty())cout << "Stack Empty!" << endl;
		return elements[top_index];
	}
	T bottom() {
		if (empty())cout << "Stack Empty!" << endl;
		return elements[0];
	}
	bool empty()const { return top_index == -1; }
	int size()const { return top_index + 1; }
	void clear() { top_index = -1; }
};