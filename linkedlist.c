#include <stdlib.h>
#include <stdio.h>

enum bool{ false = 0 , true = 1 };
typedef enum bool bool;
/*Data structure to hold data*/
struct node
{
	int data;
	struct node* next;
};

/*Returns memory address of an initiliased node*/
struct node* createNode(int d)
{
	struct node* p = malloc(sizeof(struct node));
	p->data = d;
	p->next = NULL;
	return p;
}

/*Change memory address pointed to node*/
void updateNodeP(struct node** input, struct node* p)
{
	*input = &p;
}

/*Get user input and create a linked list from each instance of node */
void getGetInputFromUser(struct node** entry ,struct node ** itr)
{
	int data;	

	do 
	{
		fprintf(stdout, "%s\n", "Enter in a single positive integer , use negative integers to quit");
		scanf_s("%d", &data);
		if (data < 0)
		{
			break;
		}
		if (*entry == NULL)
		{
			*entry = createNode(data);
			*itr = *entry;		
		}
		else
		{
			(**entry).next = createNode(data);			
			*entry = (**entry).next;
		}
	} while (1);
}

/*Display contents of a node*/
void displayNode(struct node* p)
{
	int nodeCount = 0;
	while (p != NULL)
	{
		nodeCount++;
		fprintf(stdout, "Node: %d, Contains %d\n",nodeCount, p->data);
		p = p->next;
	}
}

/*Return the memory address of a node that contains data
Returns null when no data is found*/
struct node* search(struct node* start, int data)
{
	while (start != NULL)
	{
		if (start->data = data)
		{
			return start;
		}
		else
		{
			start = start->next;
		}
	}
	return NULL;
}

/*Delete a node that contains search criteria defined as data
deleteAllInstance flag deletes all items that contain data*/
void deleteANode(struct node** start,int data, bool deleteAllInstance)
{
	struct node* prev = NULL;
	struct node* itr = *start;
	struct node* next = NULL;

	while (itr != NULL)
	{
		if (itr->data == data)
		{
			next = itr->next;
			free(itr);
			
			if (prev == NULL && itr == *start)
			{
				*start = next;
			}
			else
			{
				prev->next = next;
			}
			/*We update itr pointer to point to next node for continous search,
			otherwise itr points to nothing after free operation*/
			if (deleteAllInstance)
			{
				itr = next;
			}
			else /*Exit node traverse operation, only delete one node*/
			{
				break;
			}
		}
		else
		{
			prev = itr;
			itr = itr->next;
		}
	}
}

/*
void reverseList(struct node** start)
{
	struct node* prev = NULL;
	struct node* next = NULL;
	struct node* itr = NULL;

	int count = 0;
	itr = *start;
	
	while (itr != NULL)
	{
		prev = itr;
		next = itr->next;
		itr = next->next;
		next->next = prev;
	}
	*start = prev;
}
*/

/*Return heap memory after we finish*/
void freeMemory(struct node* itr)
{
	struct node* p = itr;
	while (p != NULL)
	{
		p = itr->next;
		free(itr);
		itr = p;
	}
}

int main()
{
	/*Base pointer for list*/
	struct node* start = NULL;
	/*Iterator pointer for list*/
	struct node* itr = NULL;
	/*Creates a linked list here*/
	getGetInputFromUser(&itr,&start);
	/*Show contents of linked list*/
	displayNode(start);
	//deleteANode(&start,1 , true);
	/*Print new line character for better readability*/
	printf("\n");
	//reverseList(&start);
	/*Show changes from operations on list*/
	displayNode(start);
	/*Return heap memory*/
	freeMemory(start);
	return 0;
}