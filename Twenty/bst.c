//
//  bst.c
//  Twenty
//
//  Created by Diego Hernandez on 10/13/24.
//

#include "bst.h"
#include <stdlib.h>
#include <string.h>

/**
 it takes a reference of a head node, and checks if it is null to initalize it
 otherwose it uses that refrence to triverse the tree to properly insert node in the
 correct place due to its data value
 **/

node* insert(node *head, int data, char Question[], char Guess[]) {
	node *card = NULL;
	node *parent = NULL; // To keep track of the parent node
	node *currentNode = head;
	
	// iterate the tree to find the correct place
	while(currentNode != NULL) {
		parent = currentNode;
		// Ensure currentNode is not NULL
		if(currentNode->data > data) {
			currentNode = currentNode->left;
		} else {
			currentNode = currentNode->right;
		}
	}
	
	// Create a new node
	card = createNode(data, Question, Guess);
	
	// If the tree is empty, make the new node the head
	if(parent == NULL) {
		head = card;
	} else {
		if(parent->data > data) {
			parent->left = card;
		} else {
			parent->right = card;
		}
	}
	
	return head;
}

node* createNode(int data, char Question[], char Guess[]) { // strcopy error
	node *card = NULL;
	card = malloc(sizeof(node));
	card->data = data;
	card->question = (char*) malloc(strlen(Question) + 1); //bullshit null pointer issue, stackoverflow FTW
	strcpy(card->question, Question);
	card->guess = (char*) malloc(strlen(Guess) + 1);
	strcpy(card->guess, Guess);
	card->left = NULL;
	card->right = NULL;
	
	return card;
}



