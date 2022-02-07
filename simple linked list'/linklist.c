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
 void cnode();
 void bnode();
 void enode();
 void search();
 void btwnode();
 void dis();
 void del();
 void dealloc();
 
 void main() 
{
int n,count=0;
 

while(1)
{
printf("\nSelect the operation \n\n **********Menu*********\n1.Create node \n2.Add a node at the begining\n3. Add a node at the end of list\n4.Add a nodes in between other nodes\n5.Display list \n6.Search for element\n7.Delete a node \n8.Exit\n");
scanf("%d",&n);
if((n>0)&&(n<9))
 {
    switch (n)
    {
        case  1:
        if(count==0){
        
        cnode();
        count++;
        }
        else
        {
printf("First node already inputed,exit before creating new list \n");
        }
        break;
        case  2:bnode();
        break;
        case 3:enode();
        break;
        case  4:btwnode();
        break;
        case  5:dis();
        break;
        case  6:search();
        break;
       case 7:del();
        break;
        case 8:
        dealloc();
        printf("\nEXITED\n");
        return;
        break;
    }//end of switch 


}

else
{
    printf("\nInvalid input,reenter a new value\n");//invalid selection

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




void alloc()//dynamic memeory allocation of nnodes
{
    nnode=(node*)malloc(sizeof(node));
}

void dealloc()//function to deallocate dynamically allocated memory;
{
    int i=1;
    while(temp->link!= NULL)
     {
        first = temp->link; 
        printf("Node %d is removed\n",i);
        free(temp);
        temp=first;
        i++;
    }
    free(temp);
    printf("Node %d is removed \n",i);
}


 void cnode()//creating the first node/list *first choice
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
printf("A node is created \n",newnode->info);
end=newnode;
     }





void bnode()//inputing nodes before first node *second choice
{
    alloc();
    nnode->link=first;
    first=nnode;
    temp=first;
    nod();
    printf("A new node is added in the begining\n",nnode->info);
}



void enode()//Add a new node at the end of the list *third choice
{
 alloc();
nnode->link=NULL;
nod();
end->link=nnode;
end=nnode;
temp=first;//if i don't add this statement here ,data won't be printed the second time when we Use endnode fuction ,updation is not possible .
printf("\n A new node is added in the end\n");

}




void btwnode()//to add node before a node *fourth choice
{
    int s,i=0;
    alloc();
    nod();
  
    printf("Iput the data of node after  which you need to input new node\n");
    scanf("%d",&s);
   while(temp!=NULL)
{
    if(temp->info==s)
    {
   nnode->link=temp->link;
   temp->link=nnode;
   printf("New node is added after %d",s);
    }
    temp=temp->link;
    i++;
}
if(i=0)
{
   printf("\n %d is not available in the list \n",s);
}
temp=first;

}


void dis()//traversal *5 th choice
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





void search()//searching function *6th choice
{
    int i=1,s,c=0;
    printf("Input the data that need to be searched\n");
    scanf("%d",&s);
while(temp!=NULL)
{
    printf("Searching......>\n\n");
    if(temp->info==s)
    {
     printf("\n %d is available in the list in node no.:-%d \n",s,i);
     c++;
    }
    temp=temp->link;
    i++;
}
if(c==0)
{
   printf("\n %d is not available in the list \n",s);
}
   temp=first;
}

void del() //*7th choice
{
   int i=1,d,c=0;
    printf("Input the data that need to be removed\n");
    scanf("%d",&d);


    // If first node itself holds the data to be deleted
    if (temp != NULL && temp->info == d)
     {
        first = temp->link; 
        printf("The first node is removed\n");
        free(temp);
        temp=first;

        return;
    }
 
 
    while ((temp != NULL) && (temp->info!= d))
     {
        de = temp;
        temp = temp->link;
       
    }
 
   
    if((temp!= NULL) && (temp->info= d))
     {
       
    de->link = temp->link;
     free(temp);
       printf("Node removed\n");

     }


    if (temp == NULL)
    {
    printf("The data is not available to remove\n");

    }
    temp=first;
}