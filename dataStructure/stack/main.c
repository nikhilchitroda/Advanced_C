#include<stdio.h>
#include<stdlib.h>

#define TRUE  1
#define FALSE 0

struct node
{
	int data;
	struct node *ptr;
}*top=NULL;

int addNode(int value)
{
	int rc=0;
	struct node *tmp=NULL;

	do
	{
		tmp=(struct node*)malloc(sizeof(struct node*));
		if(tmp == NULL)
		{
			printf("Failed to allocate Memory\n");
			rc=1;
			break;
		}
		else
		{
			tmp->data=value;
			if(top==NULL)
			{
				tmp->ptr=NULL;
				top=tmp;
			}
			else
			{
				tmp->ptr=top;
				top=tmp;
			}
		}
	}while(FALSE);
	return rc;
}

int pushElement()
{
	int rc=0, count=0, loop=0, value=0;
	do
	{
		while(1)
		{
			printf("How many element do you want to push: ");
			scanf("%d", &count);
			printf("\n");
			if(count<0)
			{
				printf("Please, Enter positive value only.\n");
				continue;
			}
			else
			{
				for(loop=0; loop<count; loop++)
				{
					printf("Enter data you want to add into stack-%d index: ",loop);
					scanf("%d", &value);
					rc = addNode(value);
					if(rc!=0)
					{
						printf("Error, while adding node into the stack\n");
						rc=1;
						break;					
					}
				}
				break;	
			}
		}
	}while(FALSE);
	return rc;
}

int countStackMembers(int *memberCount)
{
	int rc=0;
	struct node *tmp=NULL;
	do
	{
		if(top==NULL)
                {
                        printf("Stack is empty\n");
			rc=1;
                }
                else
                {
			tmp=top;
                        while(tmp!=NULL)
                        {
                                tmp=tmp->ptr;
				(*memberCount)++;
                        }
		}
	}while(FALSE);
	return rc;
}

int popElement()
{
	int rc=0, stackCount=0, reqCount=0, value=0, loop=0;
	struct node *tmp=NULL;
	do
	{
		if(top==NULL)
		{
			printf("Stack is empty\n");
			rc=1;
		}
		rc= countStackMembers(&stackCount);
		if(rc!=0)
		{
			printf("Error, while counting stack members\n");
			break;
		}
		while(1)
		{
			tmp=top;
			printf("How many element do you want to pop[1-%d]: ", stackCount);
			scanf("%d", &reqCount);
			printf("\n");
			if( (reqCount<=0) || (reqCount > stackCount) )
			{
				printf("Please, Enter value in between [1-%d]\n", stackCount);
				continue;
			}

			for(loop=0; loop<reqCount; loop++)
			{
				printf("Poped out data is: %d\n", top->data);
				top=top->ptr;
				free(tmp);
				tmp=top;
			}
			break;
		}
	}while(FALSE);
	return rc;
}

int peekElement()
{
	int rc=0;
	do
	{
		if(top==NULL)
                {
                        printf("Stack is empty\n");
			rc=1;
                }	
		else
		{
			printf("Top most stack member value: %d\n", top->data);	
		}
	}while(FALSE);
	return rc;
}

int printStackMembers()
{
	int rc=0;
	struct node *tmp=NULL;
	do
	{
		if(top==NULL)
		{
			printf("Stack is empty\n");
			rc=1;
		}
		else
		{
			tmp=top;
			printf("Stack members are: ");
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

int choice()
{
        int choice=0, countNode=0, rc=0, stackCount=0;
        printf("\n1. Push element in stack\n");
        printf("2. Pop element from stack\n");
        printf("3. Peek element to find\n");
        printf("4. Print stack members\n");
        printf("5. Find total no of element in stack\n");
        printf("6. Exit\n");
        printf("\nEnter you choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
                case 1: rc = pushElement();
                        if(rc!=0)
                        {
                                printf("Error, while pushing the element into the stack\n");
                        }
                        break;

		case 2: rc = popElement();
                        if(rc!=0)
                        {
                                printf("Error, while popping element from the stack\n");
                        }
                        break;

                case 3: rc = peekElement();
                        if(rc!=0)
                        {
                                printf("Error, while finding peek element from stack\n");
                        }
                        break;

		case 4: rc = printStackMembers();
                        if(rc!=0)
                        {
                                printf("Error, while printing all the stack members\n");
                        }
                        break;

                case 5: rc = countStackMembers(&stackCount);
                        if(rc!=0)
                        {
                                printf("Error, while counting the stack members\n");
                        }
			printf("Total numbers of stack members are: %d\n", stackCount);
                        break;

                case 6: exit(0);

                default: printf("Please, Enter valid choice[1-6]\n");
        }
        return rc;
}

int main()
{
	int rc=0;
        printf("\n***** Use the Stack ADT *****\n");
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
