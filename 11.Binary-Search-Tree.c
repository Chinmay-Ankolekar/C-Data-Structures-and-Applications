/*Design, Develop and Implement a menu driven Program for the following 
operations on Binary Search Tree (BST) of Integers . 
a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2. 
b. Traverse the BST in Inorder, Preorder and Post Order. 
c. Search the BST for a given element (KEY) and report the appropriate 
message.
d. Exit.*/

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};
void inorder(struct node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
void preorder(struct node* root){
    if(root==NULL) return;
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}
struct node* create(int value){
    struct node* newnode=malloc(sizeof(struct node));
    newnode->data =value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node* insert(struct node* node,int value){
    if(node ==NULL) return create(value);
   if(value<node->data)
   node->left=insert(node->left,value);
   else node->right=insert(node->right,value);
    return node;
}
int flag=0;
void search(struct node* root,int key){
    if(root->data==key){
        flag=1;
        return;
    }
    else{
    if(flag==0 && root->left!=NULL){
        search(root->left,key);
    }
    if(flag==0 && root->right!=NULL){
        search(root->right,key);
    }
    return;
    }
}
int main(){
    int i,n,k,m,ch;
    printf("Enter the No. of values:");
    scanf("%d",&n);
    struct node* root=NULL;
  while(1){
      printf("\nBinary Search Tree\n");
      printf("1.Create\n");
      printf("2.Traversal\n");
      printf("3.Search\n");
      printf("4.Exit\n");
      printf("Enter your choice:");
      scanf("%d",&ch);
      switch(ch){
          case 1:for(i=0;i<n;i++){
                printf("Enter node :");
                scanf("%d",&k);
                root=insert(root,k);}
                break;
          case 2:printf("\nInorder :");
                   inorder(root);
                printf("\nPreorder :");
                   preorder(root);
                printf("\nPostorder :");
                   postorder(root);
                break;
          case 3:printf("Enter the Element to search:");
                 scanf("%d",&m);
                 search(root,m);
                 if(flag==0) printf("Element %d not found",m);
                 else printf("Element %d found",m);
                 break;
          case 4:exit(0);
          default:printf("Invalid choice!!");
       }
   }
}
/*   
Enter the No. of values:12

Binary Search Tree
1.Create
2.Traversal
3.Search
4.Exit
Enter your choice:1
Enter node :6
Enter node :9
Enter node :5
Enter node :2
Enter node :8
Enter node :15
Enter node :24
Enter node :14
Enter node :7
Enter node :8
Enter node :5
Enter node :2

Binary Search Tree
1.Create
2.Traversal
3.Search
4.Exit
Enter your choice:2

Inorder: 2      2       5       5       6       7       8       8       9       14      15      24
Preorder :6     5       2       2       5       9       8       7       8       15      14      24
Postorder :2    2       5       5       7       8       8       14      24      15      9       6

Binary Search Tree
1.Create
2.Traversal
3.Search
4.Exit
Enter your choice:3
Enter the Element to search:16
Element 16 not found

Binary Search Tree
1.Create
2.Traversal
3.Search
4.Exit
Enter your choice:3
Enter the Element to search:14
Element 14 found

Binary Search Tree
1.Create
2.Traversal
3.Search
4.Exit
Enter your choice:4
*/
