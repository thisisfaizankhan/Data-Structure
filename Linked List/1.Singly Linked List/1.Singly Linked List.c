#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//Use structure for 2 nodes of linked List, the data and the linked part
struct node{
    int data;
    struct node* next;
};
// ptd for Print_the_Data
void ptd();
//aae for Add_at_end.
void aae();
/*aab for Add_at_Beginning with no pointer of pointer we do it with only assiging*/
struct node* aab();
/* aabp is for add at beginning using pointer of pointer for direct changes in main function*/
void aabp();
/* anp is for Add at n'th position*/
void anp();
/*Delete from first position using dfn*/
struct node* dfn();

/* dln use for delte node at the end of the list*/
struct node* dln();

int main(){
    int i1, i2, i3, i4, i5, i6, i7, i8, choose;
    char c1;
    float f1;
        printf("\t Welcome To My Singly Linked List\n");
        printf("\n Here You Can Make Your Own Singly Linked\n");
        printf("\n Enter Your Elements of List\n");
        printf("\n And Enter ""00"" When You Want To Stop\n");

        scanf("%d",&i1);
        struct node *head= malloc(sizeof(struct node));
        head->data=i1;
        head->next= NULL;

        while(i1!=00){
            scanf("%d",&i2);
            aae(head, i2);
            i1 = i2;
        }
printf("\n Congratulation You Created The Singly Linked List\n");
printf("\n Now what operation we can do with our list\n");
printf("\n Press 1: For Print The List\n");
printf("\n Press 2: For Insert Element at Beginning with Using Pointer\n");
printf("\n Press 3: For Insert Element at Beginning\n");
printf("\n Press 4: For Insert Element at Nth Position\n");
printf("\n Press 5: For Delete The First Element\n");
printf("\n Press 6: For delete The Last Element\n");
printf("\n Press 0: For Nothing\n");
printf("\n\tYou can do all this operations Multiple Time\n");
for(;;){
scanf("%d",&choose);

switch(choose){
    case 0:
        break;
    case 1:
        ptd(head);
        getch();
        break;

   case 2:
       printf("\n Enter Element For Adding At Beginning\n");
       scanf("%d", &i4);
       head = aab(head,i4);
       getch();
       break;
   case 3:
        printf("\n Enter Element For Adding At Beginning\n");
        scanf("%d",&i5);
        aabp(head,i5);
        getch();
        break;
   case 4:
        printf("\n Please Enter a Element\n");
        scanf("%d",&i6);
        printf("\n Please Enter The Position Of Element\b");
        scanf("%d",&i7);
        anp(head,i7,i6);
        getch();
        break;
   case 5:
       printf("\n First Element Deleted Successfully \n");
        head = dfn(head);
        getch();
        break;
   case 6:
       printf("\nLast Element Delete Successfully\n");
        head = dln(head);
        getch();
        break;
}}

}
void ptd(struct node* head){
    struct node* cf = NULL;
    cf = head;
    printf("Here Is The List\n");
    while(cf != NULL){
        printf("%d",cf->data);
        cf = cf->next;
        printf("\n");
    }
}
void aae(struct node* head,int x){
    struct node* aae=malloc(sizeof(struct node));
    aae = head;
    struct node* temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->next =NULL;
    while(aae->next != NULL){
        aae = aae->next;
        }
    aae->next=temp;
}
struct node* aab(struct node* head, int x){
    struct node* temp= malloc(sizeof(struct node));
    temp->data= x;
    temp->next= head;
    head = temp;
    return head;
}

void aabp(struct node** head, int x){

    struct node* temp =  malloc(sizeof(struct node));
    temp ->data= x;
    temp->next = *head;
    *head = temp;
}
 void anp(struct node* head,int pos,int x){
    struct node* ptr=head;
    struct node* temp = malloc(sizeof(struct node));
    temp ->data = x;
    temp-> next = NULL;
     while (pos !=  2){
            ptr = ptr->next;
            pos--;
     }
    temp->next = ptr->next;
    ptr->next= temp;
 }

 struct node* dfn(struct node*head){
     struct node* temp= head;
     head = head->next;
     free(temp);
     temp=NULL;
    return head;
 }

struct node *dln(head){
    int i;
    struct node* temp= head;
    struct node* temp2= head;
        while(temp->next!= NULL){
            temp2 = temp;
            temp= temp->next;
            }
    temp2->next= NULL;
    free(temp);
    temp =NULL;
    return head;
}
