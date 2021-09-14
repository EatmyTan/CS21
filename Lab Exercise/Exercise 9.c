#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
    int year_level, age, final_grade, year_num, stud_num;
    char last_name[15], first_name[15], course[15], sex[6];
    struct node* link;// holds the address
}* head; // Declaring head as a global pointer 
typedef struct node node;
void insertStudent(char *lasN, char* firN, char* course, char* sX, int yL, int aG, int fG, int yN, int sN){
    // Insertion at the beginning of the list
    struct node* student = (struct node*)malloc(sizeof(struct node)*15);
    student->year_level = yL;
    student->age = aG;
    student->final_grade = fG;
    student->year_num = yN;
    student->stud_num = sN;
    strcpy(student->last_name, lasN);
    strcpy(student->first_name, firN);
    strcpy(student->course, course);
    strcpy(student->sex, sX);
    student->link = NULL;
    if(head == NULL){
        head = student;
    }
    else{
        student->link = head;
        head = student;
    }
}
void drop(int x, int y)
{
    struct node* current = head; // the node that we want to delete
    struct node* previous = head; 
    while(current!=NULL){
        if(current->year_num == x && current->stud_num == y){  
            if(current==previous){// if the current node is the beginning of the list
                head = head->link;
                free(current);
            }
            else{
                previous->link = current->link;
                free(current); 
            }
            printf("%i-%i Successfully Deleted\n", x, y);
            return;           
        }
        previous = current;
        current = current->link;       
    }
    printf("Student with student number %i-%i is not found\n", x, y);
}

void edit(int x, int y){
    int sub_choice;
    struct node* temp1 = head;
    struct node* temp2;

    while(temp1!=NULL){
        if(temp1->year_num == x && temp1->stud_num == y){
            temp2 = temp1;
        }
        temp1 = temp1->link;
    }
    do{
        printf("\nEdit\n1. Student Number\n2. Last name\n3. First name\n4. Course\n5. Year level");
        printf("\n6. Age\n7. Sex\n8. Final grade\n9. Back\n\n");
        scanf("%i", &sub_choice);
        switch(sub_choice){
            case 1:
            printf("Student number(%i-%i): ", temp2->year_num, temp2->stud_num);scanf("%i-%i", &temp2->year_num, &temp2->stud_num);
            break;

            case 2:
            printf("Last name(%s):", temp2->last_name); scanf("%s", &temp2->last_name);
            break; 

            case 3:
            printf("First name(%s): ", temp2->first_name); scanf("%s", &temp2->first_name);
            break;

            case 4:  
            printf("Course(%s): ", temp2->course); scanf("%s", &temp2->course);
            break;

            case 5:
            printf("Year level(%i): ", temp2->year_level); scanf("%i", &temp2->year_level);
            break;

            case 6:
            printf("Age(%i): ", temp2->age); scanf("%i", &temp2->age);
            break;

            case 7:
            printf("Sex(%s): ", temp2->sex); scanf("%s", &temp2->sex);
            break;

            case 8:
            printf("Final grade(%i): ", temp2->final_grade); scanf("%i", &temp2->final_grade);
            break;
        }
    }while(sub_choice!=9);
}
void display_filter(struct node* temp){
    printf("\nStudent number: %04d-%05d\n", temp->year_num, temp->stud_num); 
    printf("Last name: %s\n", temp->last_name); 
    printf("First name: %s\n", temp->first_name);
    printf("Course: %s\n", temp->course); 
    printf("Year level: %i\n", temp->year_level); 
    printf("Age: %i\n", temp->age); 
    printf("Sex: %s\n", temp->sex); 
    printf("Final Grade: %i\n\n", temp->final_grade);
}
void filter(int choice){
    struct node* temp = head;
    int check = 0, pass = 0, fail = 0;
    if(choice==5){
        char last[15];
        printf("Enter the last name: "); scanf("%s", &last);
        while(temp!=NULL){
            if(strcmp(last, temp->last_name)==0){
                display_filter(temp);
                check = 1;
            }
            temp = temp->link;
        }
    }
    if(choice==6){
        int x, y;
        printf("Enter student number: "); scanf("%04d-%05d", &x, &y);
        while(temp!=NULL){
            if(temp->year_num == x && temp->stud_num == y){
                display_filter(temp);
                check = 1;
            }
            temp = temp->link;
        }
    }
    if(choice==7){
        int yearLvl;
        printf("Enter year level: "); scanf("%i", &yearLvl);
        while(temp!=NULL){
            if(yearLvl == temp->year_level){
                display_filter(temp);
                check = 1;
            }
            temp = temp->link;
        }
    }
    if(choice==8){
        char course[15];
        printf("Enter course: "); scanf("%s", &course);
        while(temp!=NULL){
            if(strcmp(course, temp->course)==0){
                display_filter(temp);
                check = 1;
            }
            temp = temp->link;
        }
    }
    if(choice==9){
        char sex[6];
        printf("Enter sex: "); scanf("%s", &sex);
        while(temp!=NULL){
            if(strcmp(sex, temp->sex)==0){
                display_filter(temp);
                check = 1;
            }
            temp = temp->link;
        }
    }
    if(choice==10){
        while(temp!=NULL){
            if(temp->final_grade >= 60 && temp->final_grade <=100){
                display_filter(temp);
                pass = 1;
            }
            temp = temp->link;
        }
        if(pass==0)
            printf("Oof, no student passed :(\n");
        return;
    }
    if(choice==11){
        while(temp!=NULL){
            if(temp->final_grade<60){
                display_filter(temp);
                fail = 1;
            }
            temp = temp->link;
        }
        if(fail==0 && choice != 10 && choice != 11)
            printf("Hooray no student failed :)\n");
        return;
    }
    if(check==0)
        printf("We do not have what you're looking for\n");
}
void display()
{
    struct node* temp = head;
    while(temp!=NULL){
        printf("\nStudent number: %04d-%05d\n", temp->year_num, temp->stud_num); 
        printf("Last name: %s\n", temp->last_name); 
        printf("First name: %s\n", temp->first_name);
        printf("Course: %s\n", temp->course); 
        printf("Year level: %i\n", temp->year_level); 
        printf("Age: %i\n", temp->age); 
        printf("Sex: %s\n", temp->sex); 
        printf("Final Grade: %i\n\n", temp->final_grade);
        temp = temp->link;
    }
}

void sort(int choice){
    if(choice==12){
        struct node *i, *j;
        struct node* temp = malloc(sizeof(struct node));
        for(i = head; i!=NULL; i = i->link){
            for(j = i->link; j!=NULL; j = j->link){
                char x[15], y[15];
                strcpy(x,i->last_name);
                strcpy(y, j->last_name);
                int check = strcmp(x, y);
                if(check == 0){
                    char a[15], b[15];
                    strcpy(a, i->first_name);
                    strcpy(b, j->first_name);
                    int check1 = strcmp(a, b);
                    if(check1 > 0){
                    //for temp swap
                    strcpy(temp->first_name, i->first_name);
                    strcpy(temp->last_name, i->last_name);
                    strcpy(temp->course, i->course);
                    strcpy(temp->sex, i->sex);
                    temp->final_grade = i->final_grade;
                    temp->year_num = i->year_num;
                    temp->stud_num = i->stud_num;
                    temp->year_level = i->year_level;
                    //end of temp swap
                    //for i swap
                    strcpy(i->first_name, j->first_name);
                    strcpy(i->last_name, j->last_name);
                    strcpy(i->course, j->course);
                    strcpy(i->sex, j->sex);
                    i->final_grade = j->final_grade;
                    i->year_num = j->year_num;
                    i->stud_num = j->stud_num;
                    i->year_level = j->year_level;
                    //end of i
                    //start of j swap
                    strcpy(j->first_name, temp->first_name);
                    strcpy(j->last_name, temp->last_name);
                    strcpy(j->course, temp->course);
                    strcpy(j->sex, temp->sex);
                    j->final_grade = temp->final_grade;
                    j->year_num = temp->year_num;
                    j->stud_num = temp->stud_num;
                    j->year_level = temp->year_level;
                    // end of j swap
                    }
                }
                else if(check > 0){
                    //for temp swap
                    strcpy(temp->first_name, i->first_name);
                    strcpy(temp->last_name, i->last_name);
                    strcpy(temp->course, i->course);
                    strcpy(temp->sex, i->sex);
                    temp->final_grade = i->final_grade;
                    temp->year_num = i->year_num;
                    temp->stud_num = i->stud_num;
                    temp->year_level = i->year_level;
                    //end of temp swap
                    //for i swap
                    strcpy(i->first_name, j->first_name);
                    strcpy(i->last_name, j->last_name);
                    strcpy(i->course, j->course);
                    strcpy(i->sex, j->sex);
                    i->final_grade = j->final_grade;
                    i->year_num = j->year_num;
                    i->stud_num = j->stud_num;
                    i->year_level = j->year_level;
                    //end of i
                    //start of j swap
                    strcpy(j->first_name, temp->first_name);
                    strcpy(j->last_name, temp->last_name);
                    strcpy(j->course, temp->course);
                    strcpy(j->sex, temp->sex);
                    j->final_grade = temp->final_grade;
                    j->year_num = temp->year_num;
                    j->stud_num = temp->stud_num;
                    j->year_level = temp->year_level;
                    // end of j swap
                }
            }
        }
        display();
    }
    if(choice==13){
        struct node* i; struct node* j; struct node* temp = malloc(sizeof(struct node));
        for(i = head; i!=NULL; i = i->link){
            for(j = i->link; j!=NULL; j = j->link){
                if(i->year_num == j->year_num){
                    if(i->stud_num > j->stud_num){
                    //for temp swap
                    strcpy(temp->first_name, i->first_name);
                    strcpy(temp->last_name, i->last_name);
                    strcpy(temp->course, i->course);
                    strcpy(temp->sex, i->sex);
                    temp->final_grade = i->final_grade;
                    temp->year_num = i->year_num;
                    temp->stud_num = i->stud_num;
                    temp->year_level = i->year_level;
                    //end of temp swap
                    //for i swap
                    strcpy(i->first_name, j->first_name);
                    strcpy(i->last_name, j->last_name);
                    strcpy(i->course, j->course);
                    strcpy(i->sex, j->sex);
                    i->final_grade = j->final_grade;
                    i->year_num = j->year_num;
                    i->stud_num = j->stud_num;
                    i->year_level = j->year_level;
                    //end of i
                    //start of j swap
                    strcpy(j->first_name, temp->first_name);
                    strcpy(j->last_name, temp->last_name);
                    strcpy(j->course, temp->course);
                    strcpy(j->sex, temp->sex);
                    j->final_grade = temp->final_grade;
                    j->year_num = temp->year_num;
                    j->stud_num = temp->stud_num;
                    j->year_level = temp->year_level;
                    // end of j swap
                    }
                }
                else if(i->year_num > j->year_num){
                    //for temp swap (I am very sorry for this hacky code)
                    strcpy(temp->first_name, i->first_name);
                    strcpy(temp->last_name, i->last_name);
                    strcpy(temp->course, i->course);
                    strcpy(temp->sex, i->sex);
                    temp->final_grade = i->final_grade;
                    temp->year_num = i->year_num;
                    temp->stud_num = i->stud_num;
                    temp->year_level = i->year_level;
                    //end of temp swap
                    //for i swap
                    strcpy(i->first_name, j->first_name);
                    strcpy(i->last_name, j->last_name);
                    strcpy(i->course, j->course);
                    strcpy(i->sex, j->sex);
                    i->final_grade = j->final_grade;
                    i->year_num = j->year_num;
                    i->stud_num = j->stud_num;
                    i->year_level = j->year_level;
                    //end of i
                    //start of j swap
                    strcpy(j->first_name, temp->first_name);
                    strcpy(j->last_name, temp->last_name);
                    strcpy(j->course, temp->course);
                    strcpy(j->sex, temp->sex);
                    j->final_grade = temp->final_grade;
                    j->year_num = temp->year_num;
                    j->stud_num = temp->stud_num;
                    j->year_level = temp->year_level;
                    // end of j swap
                }
            }
        }
        display();
    }
}
int main(){
    head = NULL;
    int choice;
    int yL, aG, fG, yN, sN;
    char lasN[15], firN[15], COURSE[15], sX[6];
    do{
        printf("\n1. Enrol a student\n");
        printf("2. Drop a student\n");
        printf("3. Edit a student\n");
        printf("4. Display all students\n");
        printf("5. Filter students by last name\n");
        printf("6. Filter students by student number\n");
        printf("7. Filter students by year level\n");
        printf("8. Filter students by course\n");
        printf("9. Filter students by sex\n");
        printf("10. Filter students by passing\n");
        printf("11. Filter students by failing\n");
        printf("12. Sort students by last name\n");
        printf("13. Sort students by student number\n");
        printf("14. Exit\n\n");
        printf("? ");scanf("%i", &choice);
        switch(choice){
            case 1:
            printf("Student number: "); scanf("%04d-%05d", &yN, &sN);
            printf("Last name: "); scanf("%s", lasN);
            printf("First name: "); scanf("%s", firN);
            printf("Course: "); scanf("%s", &COURSE);
            printf("Year level: "); scanf("%i", &yL);
            printf("Age: "); scanf("%i", &aG);
            printf("Sex: "); scanf("%s", sX);
            printf("Final Grade: "); scanf("%i", &fG);
            insertStudent(lasN, firN, COURSE, sX, yL, aG, fG, yN, sN);
            printf("\n\n%04d-%05d added\n\n", yN, sN);
            break;

            case 2:
            printf("Enter student number: "); scanf("%04d-%05d", &yN, &sN);
            drop(yN, sN);
            break;

            case 3:
            printf("Enter student number: "); scanf("%04d-%05d", &yN, &sN);
            edit(yN, sN);
            break;

            case 4:
            display();
            break;

            case 5:
            filter(choice);
            break;

            case 6:
            filter(choice);
            break;

            case 7:
            filter(choice);
            break;

            case 8: 
            filter(choice);
            break;

            case 9:
            filter(choice);
            break;

            case 10:
            filter(choice);
            break;

            case 11:
            filter(choice);
            break;
            
            case 12:
            sort(choice);
            break;

            case 13:
            sort(choice);
            break;
        }
    } while (choice!=14);
    
}