#include<stdio.h>
#include<stdlib.h>
 typedef struct Node
 {

 int info;
 struct Node*link;

 }node;
node *temp,*first,*end,*de;
node*nnode;
node*newnode;
 
  void alloc();
 void nod();
 void stack();
 void push();
 void search();
 void dis();
 void pop();
 void dealloc();
 
 void main() 
{
int n,count=0;
 

while(1)
{
printf("\nSelect the operation \n\n **********Menu*********\n1.Create \n2.push\n3.pop  \n4.Display \n5.search\n6.Exit\n");
scanf("%d",&n);
if((n>0)&&(n<9))
 {
    switch (n)
    {
        case  1:
        if(count==0)
        {
        
        stack();
        count++;
        }
        else
        {
printf("First node already inputed,exit before creating new list \n");
        }
        break;
        case  2:push();
        break;
        case 3:pop();
        break;
        case  4:dis();
        break;
        case  5:search();
        break;
        case 6:
        dealloc();
        printf("\nEXITED\n");
        return;
        break;
    }//end of switch 


}

else
{
    printf("\nInvalid input,re-enter a new value\n");//invalid selection

}//end of if else
}//end of while loop
}//end of main function

void nod()//node data insertion
{
    if(nnode==NULL)
    {
        printf("stack overflow\n");
        return;
    }
    printf("Input the data\n\n");
    scanf("%d",&nnode->info);
}

void alloc()//dynamic memory allocation of nnodes
{
    nnode=(node*)malloc(sizeof(node));
}

void dealloc()//function to deallocate dynamically allocated memory;
{
    int i=1;
    while(temp!= NULL)
     {
        first = temp->link; 
        printf("Node %d is removed\n",i);
        free(temp);
        temp=first;
        i++;
    }
    free(temp);
    printf("stack is deleted\n",i);
}

 void stack()//creating the first node/list *first choice
 {
newnode=(node*)malloc(sizeof(node));
if(newnode==NULL)
{
    printf("stack overflow \n");
    return;
}
first=newnode;
printf("Input the integer\n");
scanf("%d",&newnode->info);
newnode->link=NULL;
temp=first;
printf("A stack is created with %d as first node \n",newnode->info);
end=newnode;
     }

void push()//pushing values to the stack*second choice
{
    alloc();
    nnode->link=first;
    first=nnode;
    temp=first;
    nod();
    printf("%d is Pushed into the stack\n",nnode->info);
}

void pop() //*3rd choice
{
    // If first node itself holds the data to be deleted
    if (temp != NULL)
     {
        first = temp->link; 
        printf("%d  is poped\n",temp->info);
        free(temp);
        temp=first;

        return;
    }
}


void dis()//traversal *4th choice
{
    int i=1;
    printf("\n********Linked List******\n");
     while(temp!=NULL)
     {
         printf("%d - %d\n",i,temp->info);
         temp=temp->link;
         i++;
     }
   temp=first;
}




void search()//searching function *5th choice
{
    int i=1,s,c=0;
    printf("Input the data that need to be searched\n");
    scanf("%d",&s);
while(temp!=NULL)
{
    printf("Searching......>\n\n");
    if(temp->info==s)
    {
     printf("\n %d is available on the stack in node no.:-%d \n",s,i);
     c++;
    }
    temp=temp->link;
    i++;
}
if(c==0)
{
   printf("\n %d is not available in the stack \n",s);
}
   temp=first;
}
