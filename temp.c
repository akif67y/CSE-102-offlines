#include<stdio.h>
#include<string.h>
#include <stdlib.h>
struct Student {
    int roll;
    double cgpa;
    char* name;
}s, s2; //equivalent to: struct Student s, s2;
/*
struct Student {
    int roll;
    double cgpa;
    char* name;
};
struct Student s, s2;
*/
int a;

/*
void printStudent(struct Student *s){
    printf("Name: %s\n", s->name);
    printf("Roll: %d\n", s->roll); //printf("Roll: %d\n", s.roll); if s isnt pointer
    printf("CGPA: %lf\n", s->cgpa);
}
*/
void printStudent(){
    printf("Name: %s\n", s.name);
    printf("Roll: %d\n", s.roll);
    printf("CGPA: %lf\n", s.cgpa);

    strcpy(s.name, "Mr. Y");
    s.roll = 50000;
}

int main(){
    ///struct Student s;

    ///s = (struct Student*) malloc(sizeof(struct Student));

    /*struct Student s = {
        "Mr. X", 20, 3.50
    };
    */

    printf("Size: %d\n", sizeof(struct Student));

    s.name = (char *) malloc(100*sizeof(char));
    s.roll = 20;
    strcpy(s.name, "Mr. X");
    s.cgpa = 3.50;


    printStudent();

    printf("Name: %s\n", s.name);
    printf("Roll: %d\n", s.roll);

    return 0;
}