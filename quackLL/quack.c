
#include <assert.h>
#include "quack.h"

#define HEADDATA -99999 // dummy data

struct node {
	int data;
	struct node *next;
};

Quack createQuack(void) {
	Quack head;
	head = (Quack)malloc(sizeof(struct node));
	assert(head != NULL);
	head->data = HEADDATA; // should never be used
	head->next = NULL;
	return head;
}

void push(int data, Quack qs) {
	if (qs == NULL) {
		fprintf(stderr, "push: quack not initialised\n");
	} else {
		Quack newnode;
		newnode = (Quack)malloc(sizeof(struct node));
		assert(newnode != NULL);
		newnode->data = data;
		newnode->next = qs->next;
		qs->next = newnode;
	}
}

void qush(int data, Quack que) {
	if (que == NULL) {
		fprintf(stderr, "qush: quack not initialised\n");
	} else {
		Quack newnode;
		newnode = (Quack)malloc(sizeof(struct node));
		assert(newnode != NULL);
		newnode->data = data;
		newnode->next = NULL;
		Quack endnode = que;
		while (endnode->next != NULL) {
			endnode = endnode->next;
		}
		endnode->next = newnode;
	}
}

int pop(Quack qs) {
	int retval = 0;
	if (qs == NULL) {
		fprintf(stderr, "pop: quack not initialised\n");
	} else if (isEmptyQuack(qs)) {
		fprintf(stderr, "pop: quack underflow\n");
	} else {
		Quack topnode = qs->next; // top node must be there
		retval = topnode->data;
		qs->next = topnode->next;
		free(topnode);
	}
	return retval;
}

int isEmptyQuack(Quack qs) {
	int empty = 0;
	if (qs == NULL) {
		fprintf(stderr, "isEmptyQuack: quack not initialised\n");
	} else {
		empty = (qs->next == NULL);
	}
	return empty;
}

void makeEmptyQuack(Quack qs) {
	if (qs == NULL) {
		fprintf(stderr, "makeEmptyQuack: quack not initialised\n");
	} else {
		while (!isEmptyQuack(qs)) {
			pop(qs);
		}
	}
}
			
void showQuack(Quack qs) {
	if (qs == NULL) {
		fprintf(stderr, "showQuack: quack not initialised\n");
	} else {
		printf("Quack: ");
		if (qs->next == NULL) {
			printf("<< >>\n");		  // empty quack
		} else {
			printf("<<");			  // start with <<
			qs = qs->next;
			while (qs->next != NULL) {
				printf("%d, ", qs->data);
				qs = qs->next;
			}
			printf("%d>>\n", qs->data);	  // last element
		}
	}
}