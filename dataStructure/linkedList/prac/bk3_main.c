#include<stdio.h>
#include<stdlib.h>

#define TRUE  1
#define FALSE 0

struct node
{
	int data;
	struct node *ptr;
}*head=NULL, *tail=NULL;

int addNode(int value)
{
	int rc=0;
	struct node *tmp=NULL;

	do
	{
		tmp=(struct node*)malloc(sizeof(struct node));
		if(tmp == NULL)
		{
			printf(" Failed to allocated Memory\n");
			rc=1;
			break;
		}
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
	}while(FALSE);
	return rc;
}

int createList()
{
	int no=0, loop=0, value=0, rc=0;
	do
	{
		printf("How many nodes you want: ");
		scanf("%d", &no);
		printf("\n");
		for(loop=0; loop<no; loop++)
		{
			printf("Enter data value for '%d' element: ", loop+1);
			scanf("%d", &value);
			rc = addNode(value);
			if(rc!=0)
                        {
                                printf("Error, adding nodes\n");
                                break;
			}	
		}
		printf("Successfully, created the list!\n");
	}while(FALSE);
	return rc;
}

int printList()
{
	int rc=0;
	struct node *tmp=NULL;
	do
	{
		if(head == NULL)
		{
			printf("Node list is empty, please create the list!\n");

		}
		else
		{
			tmp=head;
			printf("All nodes are: ");
			while(tmp!=NULL)
			{
				printf("%d ", tmp->data);
				tmp=tmp->ptr;
			}
			printf("\n");
		}
	}while(FALSE);
	return rc;
}

int addNodeAtBeginning()
{
	int value=0, rc=0;
	struct node *tmp=NULL;

	do
	{
		printf("Enter number to add: ");
		scanf("%d", &value);

		tmp=(struct node*)malloc(sizeof(struct node*));
		if(tmp == NULL)
		{
			printf(" Failed to allocated Memory\n");
			rc=1;
			break;
		}
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
	}while(FALSE);
	return rc;
}

int countAllNodes(int *countPtr)
{
	int rc=0;
	struct node *tmp=NULL;
	do
	{
		tmp=(struct node*)malloc(sizeof(struct node *));
		if(tmp == NULL)
		{
			printf(" Failed to allocated Memory\n");
			rc=1;
			break;
		}
		if(head == NULL)
		{
			*countPtr=0;
		}
		else
		{
			tmp=head;
			while(tmp!=NULL)
			{
				tmp=tmp->ptr;
				(*countPtr)++;
			}	
		}
	}while(FALSE);
	return rc;
}

int addNodeAtPartiPoint()
{
	int count=0, nodeLoc=0, rc=0, value=0, currCount=1;
	struct node *testP=NULL, *tmp=NULL;
	do
	{
		rc = countAllNodes(&count);
		if(rc!=0)
		{
			printf("Error, while counting all nodes\n");
		}
		while(1)
		{
			printf("Enter node location in between [1-%d]: ", count);
			scanf("%d",&nodeLoc);
			if(nodeLoc > count)
			{
				printf("Please, Enter node location in between [1-%d]\n", count);
				continue;	
			}
			else
			{
				testP=head;
				printf("Enter number to add: ");
				scanf("%d", &value);

				tmp=(struct node*)malloc(sizeof(struct node*));
				if(tmp == NULL)
				{
					printf(" Failed to allocated Memory\n");
					rc=1;
					break;
				}
				tmp->data=value;

				while(currCount != (nodeLoc-1))
				{
					testP=testP->ptr;
					currCount++;
				}
				tmp->ptr=testP->ptr;
				testP->ptr=tmp;
				break;
			}
		}
	}while(FALSE);
	return rc;
}

int addNodeAtEnd()
{
	int value=0, rc=0;
	do
	{
		printf("Enter number to add: ");
		scanf("%d", &value);
		rc=addNode(value);
		if(rc!=0)
		{
			printf("Error, while adding node to list\n");
		}
	}while(FALSE);
	return rc;
}

int deleteTheNode()
{
	int reqLoc=0, rc=0, count=0, currCount=1;
	struct node *prev=NULL, *next=NULL;
	do
	{
		if(head==NULL)
		{
			printf("Unable to delete the node, bcz node list is empty\n");
			rc=1;
			break;
		}
		else
		{
			rc = countAllNodes(&count);
			if(rc!=0)
			{
				printf("Error, while counting all nodes\n");
				rc=1;
				break;
			}
			prev=next=head;
			printf("Enter node which you want to delete [1-%d]: ", count);
			while(1)
			{
				scanf("%d", &reqLoc);
				if(reqLoc > count)
				{
					printf("Please, Enter valid node location in between [1-%d]: ", count);
					continue;
				}

				if(reqLoc == 1)
				{
					head=head->ptr;
					free(prev);
					break;
				}
				else
				{
					while(currCount != (reqLoc-1))
					{
						prev=prev->ptr;
						currCount++;
					}

					if(reqLoc != count)
					{
						next=prev->ptr;
						prev->ptr=next->ptr;
						free(next);
					}
					else
					{	
						prev->ptr=NULL;
						free(tail);
						tail=prev;
					}
					break;
				}
			}
		}
	}
	while(FALSE);
	return rc;
}

void searchNode()
{

}

int choice()
{
	int choice=0, countNode=0, rc=0;
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
		case 1: rc = createList();
			if(rc!=0)
                        {
                                printf("Error, while creating list\n");
			}
			break;

		case 2:	rc = printList();
			if(rc!=0)
                        {
                                printf("Error, while printing all node values\n");
                        }
			break;

		case 3: rc = addNodeAtBeginning();
			if(rc!=0)
                        {
                                printf("Error, while adding node at begining\n");
                        }
			break;

		case 4:	rc = addNodeAtPartiPoint();
			if(rc!=0)
                        {
                                printf("Error, while adding node at particular point\n");
                        }
			break;

		case 5: rc = addNodeAtEnd();
			if(rc!=0)
                        {
                                printf("Error, while adding node at end\n");
                        }
			break;

		case 6:	deleteTheNode();
			break;
		
		case 7: rc = countAllNodes(&countNode);
			if(rc!=0)
			{
				printf("Error, while counting nodes\n");
			}
			printf("Total number of node count is: %d\n", countNode);
			break;

		case 8:	searchNode();
			break;

		case 9: exit(0);

		default: printf("Please, Enter valid choice\n");
	}
	return rc;
}

int main()
{
	int rc=0;
	printf("\n***** Use the Singly Linked list *****\n");
	while(1)
	{
		rc = choice();
		if(rc!=0)
		{
			printf("Error, printing choice function\n");
			break;
		}
	}
	return 0;
}
