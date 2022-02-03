#include<stdio.h>
#include<stdlib.h>
 typedef struct Node
 {

 int info;
 struct Node*link;

 }node;
node *temp,*first;
    node*nnode;
    node*newnode;
 void cnode();
 void bnode();
 void enode();
 void search();
 void btwnode();
 void dis();
 
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
          /*case  3:enode();
        break;
        case  4:btwnode();
        break;*/
        case  5:dis();
        break;
        /*case  6:search();
        break;
        case 7:del();
        break;*/
        case 8:
        free(nnode);
        free(newnode);
        printf("\nEXITED\n");
        return;
        break;
    }


}

else
{
    printf("\nInvalid input\n");//invalid selection

}
}
}

 void cnode()//creating the first node/list
 {
newnode=(node*)malloc(sizeof(node));
first=newnode;
printf("Input the integer\n");
scanf("%d",&newnode->info);
newnode->link=NULL;
temp=first;
printf("\n%d is inputed as the first node \n",newnode->info);
     }

void bnode()//inputing nodes before first node
{
    nnode=(node*)malloc(sizeof(node));
    nnode->link=first;
    first=nnode;
    temp=first;
    printf("Input the integer\n");
    scanf("%d",&nnode->info);
    printf("\n%d is inputed before the first node \n\n",nnode->info);
}
void enode()
{


}
void dis()//traversal
{
    int i=1;
    printf("\n********Linked List******\n");
     while(temp!=NULL)
     {
         printf("%d - %d\n",i,temp->info);
         temp=temp->link;
         i++;
     }
}