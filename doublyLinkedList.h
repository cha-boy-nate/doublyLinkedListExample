#pragma once
//Header file for doublyLinked.cpp, a doubly linked pointer based list.

//typedef will allow us to easier refer to the dataItem both in reading and writing the code.
typedef int dataItem;

class doublyLinkedList {
public:

	//Default constructor.
	doublyLinkedList();

	//Function should properely input nodes into the end of the list assuring the begining of the list isn't empty.
	//The function will take the user's desired input value, create a node assining the user's derired input value
	//to that node, and doubly link that node in the doublyLinkedList class.
	//Inputs: the user's desired input value. Outputs: None. Acheieves: Inserts new node into the linked list.
	void insertDataItem(dataItem newDataItem);

	//Function should properely delete any specified node in the list. Be sure to assign the previous node's next
	//pointer to the appropriate node as well as the next node's previous pointer.
	//Inputs: number of node user desires to delete. Outputs: Either the function succeeds . Acheieves: Deletes a node from the linked list.
	bool deleteDataItem(int itemPosition);

	//Function should print each node's dataItem for the linked list from the head (beginning) to the tail (end) of list. 
	//Inputs: none. Outputs: prints to console linked list's data items. Achieves: loops through list and prints all data items.
	void doublyLinkedList::printFront();

	//Function should print each node's dataItem for the linked list from the tail (end) to the head (beginning) of list.
	//Inputs: none. Outputs: prints to console linked list's data items. Achieves: loops through lists and prints all data items. 
	void doublyLinkedList::printBack();

private: 
	struct node {
		
		//This is the data item for each node. Also known as the user's desired input in the insertDataItem function.
		dataItem	item;
		//These are the pointers for that we will use to link one node to another.
		node	   *next;
		node	   *prev;

	};
	
	//These are the nodes we will use to point to the front (head) and end (tail) of the doublyLinkedList.
	node	*head;
	node	*tail;

	int		 size;

	//Function that will create a pointer to the specified node in the linked list.
	//We keep this in private because only client should access nodes by position.
	node *ptrTo(int position) const;
	 
};
