/*  Design, Develop and Implement a menu driven Program for the following 
     array operations. 
     a. Creating an array of N Integer Elements.
     b. Display of array Elements with Suitable Headings.
     c. Inserting an Element (ELEM) at a given valid Position (POS) .
     d. Deleting an Element at a given valid Position (POS) .
     e. Exit. Support the program with functions for each of the above 
     operations.*/

#include<stdio.h>
#include<stdlib.h>
int a[10], n,i;

void create() {
    printf("Enter the number of elements :");
    scanf("%d",&n);
    printf("Enter the element in the array :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
void display() {
     printf("Elements in the Array are :");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
         printf(" ");
   }
}
int elem ,pos;
void insert(){
    printf("Enter the position for new element : ");
    scanf("%d",&pos);
    printf("Enter the element to be inserted : ");
    scanf("%d",&elem);
    for (i=n-1;i>=pos-1;i--){
        a[i+1]=a[i];
    }
    a[pos-1]=elem;
    n=n+1;
}
void delete(){
    printf("Enter the position to delete :");
    scanf("%d",&pos);
    printf("Deleted element is %d", a[pos-1]);
    for(i=pos;i<=n;i++){
        a[i-1]=a[i];
    }
     n=n-1;
}
int main(){
    int ch;

while(ch)
{
 printf("\n____ARRAY OPERATION____\n");
 printf("1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
 printf("Enter Your Choice:");
 scanf("%d",&ch);
 switch(ch)
 {
 case 1:create();break;
 case 2:display();break;
 case 3:insert();break;
 case 4:delete();break;
 case 5:exit(0);break;
 default :printf("INVALID CHOICE\n");
 }
}
return 0;
}
/*
 OUTPUT:-
 ____ARRAY OPERATION____
1.Create
2.Display
3.Insert
4.Delete
5.Exit
Enter Your Choice:1
Enter the number of elements :5
Enter the element in the array :1 2 3 4 5

____ARRAY OPERATION____
1.Create
2.Display
3.Insert
4.Delete
5.Exit
Enter Your Choice:3    
Enter the position for new element : 3
Enter the element to be inserted : 6

____ARRAY OPERATION____
1.Create
2.Display
3.Insert
4.Delete
5.Exit
Enter Your Choice:2
Elements in the Array are :1 2 6 3 4 5

____ARRAY OPERATION____
1.Create
2.Display
3.Insert
4.Delete
5.Exit
Enter Your Choice:4
Enter the position to delete :2
Deleted element is 2

____ARRAY OPERATION____
1.Create
2.Display
3.Insert
4.Delete
5.Exit
Enter Your Choice:2
Elements in the Array are :1 6 3 4 5

____ARRAY OPERATION____
1.Create
2.Display
3.Insert
4.Delete
5.Exit
Enter Your Choice:5 */