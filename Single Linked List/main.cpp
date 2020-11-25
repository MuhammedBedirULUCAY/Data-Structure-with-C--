#include <iostream>
#include "singlelinkedlist.hpp"

int main(){

	std::cout <<"======================================================" << std::endl;
	Slinklist ll1(1);
	ll1.push(2);
	ll1.push(6);
	ll1.push(7);
	ll1.insert(2,15);
	ll1.remove_val(2);
	ll1.push(13);
	ll1.pop(3);	
	std::cout << "ll1 : "<< ll1;
	std::cout << "ll1.return_nth(2) : " <<	ll1.return_nth(2) << std::endl;
	std::cout << "ll1.return_nth(15) : " <<	ll1.return_nth(15) << std::endl;
	std::cout << "ll1.return_valueOf_index(6) : " << ll1.return_valueOf_index(6) << std::endl;
	std::cout << "ll1[2] : " << ll1[2] << std::endl ;
	std::cout << std::endl;

	Slinklist ll2(13);
	std::cout << "ll2 : "<< ll2;
	std::cout << std::endl;

	ll2 = ll2 + ll1;
	std::cout << "ll2 = ll2 + ll1 \n"  << "ll2 : "<< ll2;
	std::cout << std::endl;

	Slinklist ll3 = ll1;
	std::cout << "ll3=ll1 : " <<ll3;
	std::cout <<"======================================================" << std::endl;



	return 0;
}