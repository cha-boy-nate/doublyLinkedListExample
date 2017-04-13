#include "doublyLinkedList.h"
#include <iostream>

int main() {
	
	int a = 1, b = 2, c = 3;

	doublyLinkedList list;
	list.insertDataItem(a);
	list.insertDataItem(b);
	list.insertDataItem(c);

	std::cout << "List printed forward: " << std::endl;
	list.printFront();
	std::cout << std::endl;
	std::cout << "List print backward" << std::endl;
	list.printBack();
	std::cout << std::endl;

	list.deleteDataItem(b);

	std::cout << "Printed forward without b: " << std::endl;
	list.printFront();
	std::cout << std::endl;

	return 0;
}
