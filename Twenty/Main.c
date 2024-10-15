//
//  main.c
//  Twenty
//
//  Created by Diego Hernandez on 10/13/24.
//

#include <stdio.h>
#include <string.h>
#include "bst.h"



struct node* create_game_tree(void) { //dafuk, i did not know you can do this, pretty cool
	struct node* root = NULL;
		root = insert(root, 100, "Does it grow underground?", "");
		insert(root, 50, "Is it long in shape?", "");
		insert(root, 25, "Is it orange in color?", "");
		insert(root, 15, "", "It's a carrot!");
		insert(root, 35, "", "It's a parsnip!");
		insert(root, 75, "Is it red in color?", "");
		insert(root, 65, "", "It's a radish!");
		insert(root, 85, "", "It's a potato!");
		insert(root, 150, "Does it grow on a tree?", "");
		insert(root, 125, "Is it red in color?", "");
		insert(root, 115, "", "It's an apple!");
		insert(root, 135, "", "It's a peach!");
		insert(root, 175, "Is it red in color?", "");
		insert(root, 165, "", "It's a tomato!");
		insert(root, 185, "", "It's a pea!");
	return root;
}

void clearInputBuffer(void) { //from A4
	 int c;
	 while ((c = getchar()) != '\n' && c != EOF) { }
}

char displayGetInput(char text[]){ //yurrr its reusable now, although i may not need this nomore
	char input;
	printf(text);
	scanf("%c",&input);
	clearInputBuffer();
	printf("\n");
	return input;
}

void playGame(node *head) {
	node *currentCard = head;
	while (currentCard != NULL) {
		if(currentCard->question[0] != '\0') {
			printf("\n%s",currentCard->question);
			if(displayGetInput("\ny/n: ") == 'y'){
				currentCard = currentCard->left;
			}else{
				currentCard = currentCard->right;
			}
		}else{
			printf(currentCard->guess);
			break;
		}
	}
	
}


int main(void)
{
	char quit = displayGetInput("Welcome! Press 'q' to quit or any other key to continue: ");
	struct node* game_tree = create_game_tree();
	
	while(quit != 'q'){
		printf("You think of a fruit or vegetable and I will try to guess it!\n");
		playGame(game_tree);
		if(displayGetInput("\ny/n: ") == 'y'){printf("I win!\n");}
		else{printf("You win!\n");}
		quit = displayGetInput("Welcome! Press 'q' to quit or any other key to continue: ");
	}
	
	printf("Thanks for playing\n");
	return 0;

}
