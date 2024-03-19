#include<stdio.h>
#include<stdlib.h>
#define QSIZE 4
int q[QSIZE], r=-1, f=0, count=0, item;
void insert() {
 if(count == QSIZE) { 
 printf("Queue Overflow\n");
 return;
 }
 r = (r+1) % QSIZE; 
 q[r] = item; 
 count++;
}
void del() {
 if(count == 0) {
 printf("Queue Underflow\n");
 return;
 }
 printf("The item deleted is: %d\n", q[f]);
 f = (f+1) % QSIZE;
 count--;
}
void display() {
 int i, front = f; // Corrected to use f as front
 if(count == 0) {
 printf("Queue is Empty\n");
 return;
 }
 printf("Contents of the queue\n");
 for(i=0; i<count; i++) {
 printf("%d\n", q[front]);
 front = (front+1) % QSIZE;
 }
}
int main() {
 int choice;
 do{
 printf("***********************\n");
 printf("Circular Queue Operations\n");
 printf("1. Insert\n");
 printf("2. Delete\n");
 printf("3. Display\n");
 printf("4. Quit\n");
 printf("Enter your choice: ");
 scanf("%d",&choice);
 switch(choice) {
 case 1:
 printf("Enter the item to be inserted: ");
 scanf("%d", &item); 
insert();
 break;
 case 2:
 del();
 break;
 case 3:
 display();
 break;
 case 4:
 exit(0);
 break;
 default:
 printf("Invalid choice\n");
 break;
 }
 } while(choice != 4);
 return 0;
} 
