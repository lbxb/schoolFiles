// dlists.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include<string> 
using namespace std;
struct node {
	int val;
	string name; 
	node *back, *forward;
};
class dll {
public:
	dll() {};
	void printDll();
	void addnodefront(int v, string name, node *&t);
	void addnoderear(int v, string name, node *&t);
	void addnodeafter(int v, string name, node * &x);
	void addnodebefore(int v, string name, node * &x);
	char findwhere(int v, string name,  node *&t); //locate first node with val > v
private:
	node * rear = NULL, *front = NULL;
};
char dll::findwhere(int v,string name, node *&t) {

	node * temp;
	temp = rear;
	if (v < temp->val)
		return 'r';
	else {
		temp = temp->forward;


		while (temp != NULL) {
		
			if (v < temp->val) {
				t = temp;
				return 'b';
			}
			else
				temp = temp->forward;
		}
		return 'f';
	}
};
void dll::printDll(){
	node *temp;
	if (rear == NULL)
		cout << "There is NO ONE in the leaderbords\n";
	else {
		temp = rear;
		cout << "Leaderboards\n";
		while (temp != NULL) {
			cout << temp->name <<"'s golf score is : "  << temp->val << endl;
			temp = temp->forward;
		}
		
	}

};
void dll::addnodefront(int v, string name , node *&t) {
	node *temp;
	
	if (front == NULL) {
		front = new node;
		front->val = v;
		front->name = name; 
		front->forward = NULL;
		front->back = NULL;
		rear = front;
	}
	else {
		temp = new node;
		temp->val = v;
		temp->name = name;
		temp->back = front;
		temp->forward = NULL;
		front->forward = temp;
		front = temp;

	}
};
void dll::addnodeafter(int v, string name,  node * &x) {
	node *temp;
	temp = new node;
	temp->val = v;
	temp->name = name; 
	temp->back = x;
	temp->forward = x->forward->forward;
	x->forward = temp;
	temp->forward->back = x;
};
void dll::addnodebefore(int v, string name, node * &x) {
	node *temp;
	temp = new node;
	temp->val = v;
	temp->name = name;
	temp->forward = x; 
	temp->back = x->back; 
	x->back = temp;
	temp->back->forward = temp;
};
void dll::addnoderear(int v, string name, node *&t){
	node *temp;
	if (rear == NULL) {
		front = new node;
		front->val = v;
		front->name = name; 
		front->forward = NULL;
		front->back = NULL;
		rear = front;
	}
	else {
		temp = new node;
		temp->val = v;
		temp->name = name;
		temp->forward = rear;
		temp->back = NULL;
		rear->back = temp;
		rear = temp;

	}
};
int main()
{
	int v;
	dll test;
	string name;
	node *t;
	cout << "WELCOME TO CSC 104 Golf Tournament" << endl; 
	cout << "Please enter the NAME of the player" << endl;
	cin >> name;
	

	cout << "Please enter a score";
	cin >> v;

	test.addnodefront(v,name, t );
	test.printDll();
	for (int i = 0; i < 5; i++) {
		
		cout << "Please enter the NAME of the player" << endl;
		cin >> name;

		cout << "Please enter a SCORE " << endl;
		cin >> v;

	
		if (test.findwhere(v,name,  t) == 'r')
			test.addnoderear(v, name, t);
		else if (test.findwhere(v, name,  t) == 'f')
			test.addnodefront(v, name, t);
		else
			test.addnodebefore(v,name, t);
		test.printDll();
	}

	return 0;
}