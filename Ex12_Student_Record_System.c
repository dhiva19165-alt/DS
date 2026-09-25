#include<stdio.h>

#define SIZE 50

struct Student {

     char name[30];

     int rollno;

     int sub[3];

};

void main() {

     int i, j, max, count, total, n, a[SIZE], ni;

     struct Student st[SIZE];

     printf("Enter how many students: ");

     scanf("%d", &n);

     /* for loop to read the names and roll numbers*/

     for (i = 0; i< n; i++) {

         printf("\nEnter name and roll number for student %d : ", i);

         scanf("%s", &st[i].name);

         scanf("%d", &st[i].rollno);

     }

     /* for loop to read ith student's jth subject*/

     for (i = 0; i< n; i++) {

         for (j = 0; j <= 2; j++) {

               printf("\nEnter marks of student %d for subject %d : ", i, j);

               scanf("%d", &st[i].sub[j]);

          }

     }

     /* (i) for loop to calculate total marks obtained by each student*/

     for (i = 0; i< n; i++) {

         total = 0;

         for (j = 0; j <= 2; j++) {

               total = total + st[i].sub[j];

          }

         a[i] = total;

         printf("\nTotal marks of student %d is %d", i, total);

     }

     /* (ii) for finding the student who scored maximum total marks*/

     max = a[0];

     ni = 0;

     for (i = 1; i< n; i++) {

         if (a[i] > max) {

               max = a[i];

               ni = i;

          }

     }

     printf("\n\nStudent who scored maximum total marks is:\n");

     printf("Name: %s\n", st[ni].name);

     printf("Roll No: %d\n", st[ni].rollno);

     printf("Total Marks: %d\n", max);

     /* (iii) for finding how many students scored more than average*/

     total = 0;

     for (i = 0; i< n; i++) {

         total = total + a[i];

     }

     float avg = (float)total / n;

     count = 0;

     for (i = 0; i< n; i++) {

         if (a[i] > avg) {

               count++;

          }

     }

     printf("\nAverage marks = %.2f\n", avg);

     printf("Number of students scored more than average = %d\n", count);

}
