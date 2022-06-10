#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *ptr;
}*head=NULL, *tail=NULL;

void addNode(int value)
{
	struct node *tmp;
	tmp=(struct node*)malloc(sizeof(struct node));
	tmp->data=value;
	tmp->ptr=NULL;

	if(head==NULL)
	{
		head=tmp;
		tail=head;
	}
	else
	{
		tail->ptr=tmp;
		tail=tmp;
	}
}

void createList()
{
	int no=0, loop=0, value=0;
	printf("How many nodes you want: ");
	scanf("%d", &no);
	printf("\n");
	for(loop=0; loop<no; loop++)
	{
		printf("Enter data value for '%d' element: ", loop+1);
		scanf("%d", &value);
		addNode(value);	
	}
	printf("Successfully, created the list!\n");
}

void printList()
{
	struct node *tmp=NULL;
	tmp=head;

	printf("All node are: ");
	while(tmp!=NULL)
	{
		printf("%d ", tmp->data);
		tmp=tmp->ptr;
	}
	printf("\n");
}

void addNodeAtBeginning()
{
	int value=0;
	struct node *tmp=NULL;

	printf("Enter number to add: ");
	scanf("%d", &value);

	tmp=(struct node*)malloc(sizeof(struct node*));
	tmp->data=value;
	if(head==NULL)
	{
		head=tmp;
		tmp->ptr=NULL;
	}
	else
	{
		tmp->ptr=head;
		head=tmp;
	}
}

void addNodeAtPertPoint()
{

}

void addNodeAtEnd()
{

}

void deleteTheNode()
{

}

void countAllNodes()
{

}

void searchNode()
{

}

void choice()
{
	int choice=0;
	printf("\n1. Create the list\n");
	printf("2. print the list\n");
	printf("3. Add node at the beginning\n");
	printf("4. Add node at particular point\n");
	printf("5. Add node at the end\n");
	printf("6. Delete the particular node\n");
	printf("7. Count of total no of nodes\n");
	printf("8. Serach the node data value\n");
	printf("9. Exit\n");
	printf("\nEnter you choice: ");
	scanf("%d", &choice);

	switch(choice)
	{
		case 1: createList();
			break;

		case 2:	printList();
			break;

		case 3: addNodeAtBeginning();
			break;

		case 4:	addNodeAtPertPoint();
			break;

		case 5: addNodeAtEnd();
			break;

		case 6:	deleteTheNode();
			break;
		
		case 7: countAllNodes();
			break;

		case 8:	searchNode();
			break;

		case 9: exit(0);

		default: printf("Please, Enter valid choice\n");
	}
}

int main()
{
	printf("\n***** Use the Singly Linked list *****\n");
	while(1)
	{
		choice();
	}
	return 0;
}
