//
//  bst.h
//  Twenty
//
//  Created by Diego Gayosso Hernandez on 10/13/24.
//

#ifndef bst_h
#define bst_h

#include <stdio.h>
#include <string.h>

typedef struct node {
	int data;
	char* question;
	char* guess;
	struct node* left;
	struct node* right;
}node;

node* insert(node *head, int data, char Question[], char Gues[]);
node* createNode(int data, char Question[], char Guess[]);
void search(node *head);

#endif /* bst_h */
