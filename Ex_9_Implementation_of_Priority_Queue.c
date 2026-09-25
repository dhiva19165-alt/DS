#include <stdio.h>
#include <stdlib.h>
struct heap {
     int c;
// capacity
     int s;
// size
     int *element;
};
typedef struct heap *pqueue;
pqueue initialize(int max) {
     pqueue heap1;
     if (max <= 3) {
         printf("\n Priority queue is too small\n");
         exit(EXIT_FAILURE);
     }
     heap1 = (pqueue)malloc(sizeof(struct heap));
     if (heap1 == NULL) {
         printf("\n Out of space\n");
         exit(EXIT_FAILURE);
     }
     heap1->element = (int *)malloc((max + 1) * sizeof(int));
     if (heap1->element == NULL) {
         printf("\n Out of space\n");
         exit(EXIT_FAILURE);
     }
     heap1->c = max;
     heap1->s = 0;
     heap1->element[0] = 0;
     return heap1;
}
void insert(int x, pqueue heap1) {
     int i;
     if (heap1->s >= heap1->c) {
         printf("\n Priority queue is full\n");
         return;
     }
     for (i = ++heap1->s; heap1->element[i / 2] > x; i /= 2)
         heap1->element[i] = heap1->element[i / 2];
     heap1->element[i] = x;
}
int deletemin(pqueue heap1) {
     int i, child;
     int min, last;
     if (heap1->s == 0) {
         printf("\n Priority queue is empty\n");
         return -1;
     }
     min = heap1->element[1];
     last = heap1->element[heap1->s--];
     for (i = 1; i * 2 <= heap1->s; i = child) {
         child = i * 2;
         if (child != heap1->s && heap1->element[child + 1] < heap1->element[child])
             child++;
         if (last > heap1->element[child])
             heap1->element[i] = heap1->element[child];
         else
             break;
     }
     heap1->element[i] = last;
     return min;
}
void display(pqueue heap1) {
     int i;
     if (heap1->s == 0) {
         printf("\n Priority queue is empty\n");
         return;
     }
     printf("\n Priority Queue elements: ");
     for (i = 1; i <= heap1->s; i++)
         printf("%d ", heap1->element[i]);
     printf("\n");
}
int main() {
     pqueue heap1;
     int choice, x, max;
     printf("Enter the maximum size of priority queue: ");
     scanf("%d", &max);
     heap1 = initialize(max);
     while (1) {
         printf("\n1. Insert 2. Delete Min 3. Display 4. Exit\n");
         printf("Enter choice: ");
         scanf("%d", &choice);
         switch (choice) {
             case 1:
                 printf("Enter element to insert: ");
                 scanf("%d", &x);
                 insert(x, heap1);
                 break;
             case 2:
                 x = deletemin(heap1);
                 if (x != -1)
                     printf("Deleted min element: %d\n", x);
                 break;
             case 3:
                 display(heap1);
                 break;
             case 4:
                 free(heap1->element);
                 free(heap1);
                 return 0;
         }
     }
}
