#include "doublyLinkedList.h"
#include <iostream> //for printing functions
#include <cstddef>		// for NULL

doublyLinkedList::doublyLinkedList()	// Default Constructor
	: size(0), head(NULL), tail(NULL)
{
}

void doublyLinkedList::insertDataItem(dataItem newDataItem) {
	
	//First we create a new node assigning the user's desired input to the item variable of the node. 
	//Since we are adding each node to the end of the list we can declare the next variable as null.
	node *newPtr = new node;
	newPtr->item = newDataItem;
	newPtr->next = NULL;
	tail = newPtr;

	//Next check to see if the list is empty.
	if (head == NULL) {
		//if the list is empty assign the newPtr to the head of the list.
		head = newPtr;
		head->prev = NULL;
	} else {

		//If the isn't empty we need to find the end of the list.
		node *cur = head;
		node *previousNode = NULL;

		//loop through the linked lists to find the end linked list.
		//Example of while list to loop through the linked list.
		while (cur != NULL) {
			previousNode = cur;
			cur = cur->next;
		}

		//Inserting at the end of the list by assigning previous->next to the newPtr
		//and the newPtr-> prev to the previousNode.
		previousNode->next = newPtr;
		newPtr->prev = previousNode;
	}
	//Increase the size of the linked list by one every time we insert a new data member.
	size++;
}


bool doublyLinkedList::deleteDataItem(int itemPosition)
{
	//First we need to check that the itemPosition is valid within our linked list.
	bool success = ((itemPosition >= 1) && (itemPosition <= size));
	
	//Then we need to create a node, we will use this later to delete the node.
	node *cur;

	if (success) {
		//Decrease the size of the linked list by one.
		--size;

		//If the item we want to delete is the head we need to reasign head.
		if (itemPosition == 1) {
			//Save the node the the cur pointer.
			cur = head;
			//Assign the next node in the list as the new head node in the list node.
			head = head->next;
		} else {
			//If the node we want to delete is in the middle of the list we will need to reassign
			//the previousNode->next and the nextNode->previous.
			node *previousNode = ptrTo(itemPosition - 1);
			node *nextNode = ptrTo(itemPosition + 1);

			//Save cur to the node we want to delete. One could also use ptrTo.
			cur = previousNode->next;
			//If the node we want to delete is the tail it wont have a next node.
			if (nextNode != NULL) {
				nextNode->prev = cur->prev;
			}
			previousNode->next = cur->next;
		}

		//delete the node we saved as cur from the memory
		cur->next = NULL;
		cur->prev = NULL;
		delete cur;
		cur = NULL;
	}

	return success;
}

doublyLinkedList::node *doublyLinkedList::ptrTo(int itemPosition) const
{
	//First make sure that the itemPosition that is greater than one and less than the total length of the list.
	//If the node doesn't exist the function will return null here.
	if ((itemPosition < 1) || (itemPosition > size)) {
		return NULL;
	} else {
		//Else we need to sort through the list until we find the correct node.
		node *cur = head;
		//Example of for loop to loop through list.
		for (int skip = 1; skip < itemPosition; ++skip) {
			cur = cur->next;
		}
		//Return the pointer.
		return cur;
	}
}

void doublyLinkedList::printFront()
{
	//Point the loop to the head of the list.
	node *cur = head;
	
	//Loop until we reach the end of the list. 
	while (cur != NULL) //One could also use the tail varaible here.
	{
		//Print the data item.
		std::cout << cur->item << std::endl;
		cur = cur->next;
	}
}

void doublyLinkedList::printBack()
{
	//Point the loop to the tail of the list.
	node *cur = tail;

	//Loop through until we reach the head.
	while (cur != NULL)
	{
		//Print the data item.
		std::cout << cur->item << std::endl;
		cur = cur->prev;
	}
}
