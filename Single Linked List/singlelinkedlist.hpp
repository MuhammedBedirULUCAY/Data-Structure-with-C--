#ifndef SLL_H_
#define SLL_H_

#include <iostream>

struct Node{
	int data;
	Node *next;
};

class Slinklist{

	public:
		Slinklist();
		Slinklist(int data);			//data assaign the first value
		Slinklist(Slinklist& other);	//Copy constructor

		void push(int data);				//add the val end of list
		void pop();							//remove the end of list
		void pop(int index);				//remove the index value in list
		void insert(int index,int data);	//add the value entered index
		void remove_val(int data);			//if data in list, then this remove it
		int  return_nth(int nth);			//it return the nth val in list
		int  return_valueOf_index(int data);//it return value which index of list 

		Slinklist operator+(Slinklist& other);//connet two list		
		int operator[](int index);			  //returning the index value	 
		friend std::ostream& operator<<(std::ostream& sout, Slinklist& obj); 
		//cin >> ll is directly push
		friend std::istream& operator>>(std::istream& input, Slinklist& obj);
		//cout << ll print the list
		
		//add these member func
		//sorting
		//operation overlaoafin
		//big three
		
		void disp();

	private:
		Node *head;
};


#endif