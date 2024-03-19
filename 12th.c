#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5
struct employee
{
 int id;
 char name[15];
};
typedef struct employee EMP;
EMP emp[MAX];
int a[MAX];
int create(int num)
{
 int key;
 key = num % MAX;
 return key;
}
int getemp(EMP emp[], int key)
{
 printf("\nEnter emp id: ");
 scanf("%d", &emp[key].id);
 printf("Enter emp name: ");
 // to clear the newline character left in the buffer
 fgets(emp[key].name, sizeof(emp[key].name), stdin);
 emp[key].name[strcspn(emp[key].name, "\n")] = '\0'; // remove trailing newline
 return key;
}
void display()
{
 int i;
 printf("\nThe hash table is:\n");
 printf("\nHTKey\tEmpID\tEmpName");
 for (i = 0; i < MAX; i++)
 { 
if (a[i] != -1)
 printf("\n%d\t%d\t%s", i, emp[i].id, emp[i].name);
 }
}
void linear_prob(int key, int num)
{
 int flag, i, count = 0;
 flag = 0;
 if (a[key] == -1)
 {
 a[key] = getemp(emp, key);
 }
 else
 {
 printf("\nCollision Detected...!!!\n");
 i = 0;
 while (i < MAX)
 {
 if (a[i] != -1)
 count++;
 else
 i++;
 }
 printf("\nCollision avoided successfully using LINEAR PROBING\n");
 if (count == MAX)
 {
 printf("\nHash table is full");
 display();
 exit(1);
 }
 for (i = key; i < MAX; i++)
 {
 if (a[i] == -1)
 {
 a[i] = num;
 flag = 1;
 break;
 }
 }
 i = 0;
 while ((i < key) && (flag == 0))
 {
 if (a[i] == -1)
 {
 a[i] = num;
 flag = 1;
 break;
 }
 i++; 
}
 }
}
int main()
{
 int num, key, ans = 1;
 int i;
 printf("\nCollision handling by linear probing: ");
 for (i = 0; i < MAX; i++)
 a[i] = -1;
 do
 {
 printf("\nEnter the data: ");
 scanf("%d", &num);
 key = create(num);
 linear_prob(key, num);
 printf("Do you wish to continue? (1/0): ");
 scanf("%d", &ans);
 } while (ans);
 display();
 return 0;
} 