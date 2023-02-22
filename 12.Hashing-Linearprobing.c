/*Given a file of N employee records with a set K of Keys (4-digit) which 
uniquely determines the records in file F. Assume that file F is maintained 
in memory by a Hash Table (HT) of m memory locations with L as the set 
of memory addresses (2-digit) of locations in HT. Let the keys in K and 
addresses in L are Integers. Design and develop a Program in C that uses 
Hash function H: K→ L as H(K)=K mod m (remainder method), and 
implement hashing technique to map a given key K to the address space L. 
Resolve the collision (if any) using linear probing. */

#include <stdio.h>
#define N 10

struct employee {
	int id;
       char name[15];	
};
typedef struct employee EMP;

EMP emp[N]; 
int HT[N]; 
int ht_size = 0;

void LinearProbing(int key) {
	int flag = 0, i = key % N; 
   if (HT[i] == -1) {
		flag=1;
		ht_size++;
	 }
    else{
	  printf("Collision detected\n");
	  i++;
      while(i != key && flag == 0 && ht_size < N){
			if(HT[i] == -1) {
				flag = 1;
				ht_size++;
				break;
			}
			i = (++i) % N; 
		}
       printf("Collision Avoided Successfully Using Linear probing\n");
	} 
	if (flag == 0)
		printf("Hash Table is Full\n");
	else {
		printf("Enter Employee ID: ");
		scanf("%d", &emp[i].id);
		printf("Enter Employee Name: ");
		scanf("%s",emp[i].name);
		HT[i] = i;
	}
}
void Display() {
	int i;
	int ch;
	printf("Would you like to hide empty values? (1/0) : ");
	scanf(" %c",&ch);
	printf("HT Key \tEmp ID \tEmp Name\n");
	for(i=0;i<N;i++){
		if(ch == '1' && HT[i] == -1)
			continue;
		else
		 printf("%d \t %d \t%s \n",i, emp[i].id, emp[i].name);
	}
}
void main(){
	int key,i;
	int ch;
	for(i=0;i<N;i++) HT[i]=-1;
	do {
		printf("Enter Key(4 digit): ");
		scanf("%d", &key);
		LinearProbing(key);
		printf("Do you wish to continue (1/0): ");
		scanf(" %c",&ch);
	} while(ch=='1');
	Display();
}

/*

OUTPUT:-

Enter Key(4 digit): 8921
Enter Employee ID: 1
Enter Employee Name: A
Do you wish to continue (1/0): 1

Enter Key(4 digit): 3452
Enter Employee ID: 2
Enter Employee Name: B
Do you wish to continue (1/0): 1

Enter Key(4 digit): 5433
Enter Employee ID: 3
Enter Employee Name: C
Do you wish to continue (1/0): 1

Enter Key(4 digit): 5444
Enter Employee ID: 4
Enter Employee Name: Ch
Do you wish to continue (1/0): 1

Enter Key(4 digit): 4545
Enter Employee ID: 5
Enter Employee Name: E
Do you wish to continue (1/0): 1

Enter Key(4 digit): 9891
Collision detected
Collision Avoided Successfully Using Linear probing
Enter Employee ID: 6
Enter Employee Name: F
Do you wish to continue (1/0): 1

Enter Key(4 digit): 6762
Collision detected
Collision Avoided Successfully Using Linear probing
Enter Employee ID: 7
Enter Employee Name: G
Do you wish to continue (1/0): 1

Enter Key(4 digit): 4543
Collision detected
Collision Avoided Successfully Using Linear probing
Enter Employee ID: 8
Enter Employee Name: H
Do you wish to continue (1/0): 1

Enter Key(4 digit): 9894
Collision detected
Collision Avoided Successfully Using Linear probing
Enter Employee ID: 9
Enter Employee Name: I
Do you wish to continue (1/0): 1

Enter Key(4 digit): 7675
Collision detected
Collision Avoided Successfully Using Linear probing
Enter Employee ID: 10
Enter Employee Name: J
Do you wish to continue (1/0): 0
Would you like to hide empty values? (1/0) : 0
HT Key  Emp ID  Emp Name
0        10     J 
1        1      A
2        2      B
3        3      C 
4        4      D
5        5      E
6        6      F
7        7      G 
8        8      H
9        9      I
*/