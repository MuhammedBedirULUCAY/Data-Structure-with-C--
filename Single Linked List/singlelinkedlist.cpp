#include <iostream>
#include "singlelinkedlist.hpp"


Slinklist::Slinklist() : head(nullptr)
{}

Slinklist::Slinklist(int data) : head(new Node)
{head->data = data;}

Slinklist::Slinklist(Slinklist& other){
	Node* tmp = other.head;
	Node* iter;
	head = new Node;				//We creating a new list head and using is head of new object
	iter = head;
	while(tmp){
		iter ->data = tmp->data;		//Assaing the value one by one until the last one
		iter ->next = NULL;
		tmp = tmp ->next;
		if(tmp == NULL)
			break;
		iter->next = new Node;
		iter = iter->next;
	}
}

void Slinklist::disp(){
	Node *tmp = head;
	while(tmp){
		std::cout << tmp->data << " ";
		tmp = tmp -> next;
	}
	std::cout << std::endl;
}

void Slinklist::push(int data){			//Add the data end of list
		
	if(head == NULL){
		head = new Node;
		head->data = data;
		head ->next == NULL;
	}else{
		Node* tmp = head;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new Node;
		tmp->next->data = data;
		tmp->next->next = NULL;
	}	
}

void Slinklist::pop(){				//Remove the last element of list
	if(head == NULL){
		std::cout << "LL has no member" << std::endl;
		return;
	}
	Node *tmp = head;
	while(tmp->next->next != NULL)
		tmp = tmp->next;
	delete tmp->next;		
	tmp->next = NULL;
} 

void Slinklist::pop(int index){			//Remove the index element of list
	if(head == NULL && index < 0){
		std::cout << "LL has no member" << std::endl;
		return;
	}
	Node* tmp = head;
	if(index == 0)
		head = head->next;
	else{
		for(int i=1; i<index; ++i){		//Counter to index
			tmp = tmp->next;
			if(tmp == NULL){
				std::cout << index << " Out of size" << std::endl;
				return;
			}
		}
		tmp->next = tmp->next->next;
	}
}

int  Slinklist::return_nth(int nth){		//Return the value of index in list

	if(head == NULL){
		std::cout << "LL has no member" << std::endl;
		return 0;
	}
	Node* tmp = head;	
	for(int i=0; i<nth;i++){
		tmp = tmp->next;
		if(tmp == NULL){
			std::cout << "\nOut of size ";
			return 0;
		}
	}	
	return tmp->data;
}

int  Slinklist::return_valueOf_index(int data){		//returning to index of value in list
	if(head == NULL){
		std::cout << "LL has no member" << std::endl;
		return -1;
	}
	Node* tmp = head;
	int index = 0;
	while(tmp->data != data){
		index++;
		tmp = tmp->next;
		if(tmp == NULL){
			std::cout << "LL has no  "<< data << std::endl;
			return -1; 
 		}
	}
	return index;
}

void Slinklist::insert(int index,int data){			//Insert the data in the list at anywhere

	if(head == NULL && index != 0 && index < 0){
		std::cout << index << " is out of size" << std::endl; 
	}
	Node* tmp = new Node;
	tmp->data = data;
	tmp->next = NULL;
	if(index == 0){
		head = tmp;
	}else{
		Node* iter = head;
		for(int i=1; i<index; ++i){
			iter = iter->next;
			if(iter == NULL){
				std::cout << index << " out of size" << std::endl;
				return;
			}
		}
		tmp ->next = iter->next;
		iter->next = tmp;
	}
}

void Slinklist::remove_val(int data){
	Node* tmp = head;
	while(tmp->next->data != data){					//search the value in list if it can finf it remove the value in list 
		tmp = tmp->next;			
		if(tmp == NULL){
			std::cout <<  data  <<" is not in the list " << std::endl;
			return;
		} 
	}
	Node* remove = tmp->next;
	tmp->next = tmp->next->next;
	delete remove;
}

Slinklist Slinklist::operator+(Slinklist& other){
	Slinklist newList;
	Node* tmp = head;
	while(tmp){										//Connecting two linked list
		newList.push(tmp->data);
		tmp = tmp->next;
	}
	tmp = other.head;
	while(tmp){
		newList.push(tmp->data);
		tmp = tmp->next;
	}
	return newList;
}

int Slinklist::operator[](int index){			//It allow us to index operator in linked list
	
	return return_nth(index);
}

std::ostream& operator<<(std::ostream& sout, Slinklist& obj){
	obj.disp();							//it is print the list
	return sout;
}

std::istream& operator>>(std::istream& input, Slinklist& obj){
	int val;
	std::cin >> val;					//using cin >> ll directly pushing the value in list
	obj.push(val);
	return input;
}
