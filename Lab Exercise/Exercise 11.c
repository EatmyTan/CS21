#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void check(int x);
struct student{
    int sNum, age, grade, yLevel;
    char fName[15], lName[15], sex[15], course[15]; 
};
int enroll(){
    // appends new data to the file
    struct student* x= malloc(sizeof(struct student));
    FILE* fp = fopen("student.dat","ab+");
    if(!fp)
        printf("Cannot open\n");
    printf("\nStudent number: "); scanf("%i", &x->sNum); fflush(stdin);
    if(x->sNum<1 || x->sNum>300){
        printf("Oops an error occured you can only enter student numbers between 1 - 300\n"); return 0;
    }
    printf("Last name: ");scanf("%s", x->lName); fflush(stdin);
    printf("First name: "); scanf("%s", x->fName); fflush(stdin);
    printf("Course: "); scanf("%s", x->course);fflush(stdin);
    printf("Year level: "); scanf("%i", &x->yLevel); fflush(stdin);
    printf("Age: "); scanf("%i", &x->age);fflush(stdin);
    printf("Sex: "); scanf("%s", x->sex);fflush(stdin);
    printf("Final grade: "); scanf("%i", &x->grade);fflush(stdin);
    fwrite(x, sizeof(struct student),1,fp);
    fclose(fp);
    printf("\n%i successfully enrolled\n", x->sNum);

}
void edit(){
    // creates a new file and stores all the new changes to the new file
    struct student* x = malloc(sizeof(struct student));
    FILE* fp = fopen("student.dat","rb");
    FILE* fp_temp = fopen("copy.dat","wb");
    int subchoice, sNum;
    printf("Enter student number: "); scanf("%i", &sNum); 
    do{
        int found = 0;
        printf("\nEdit\n1. Student Number\n2. Last name\n3. First name\n4. Course\n5. Year level");
        printf("\n6. Age\n7. Sex\n8. Final grade\n9. Back\n\n"); scanf("%i", &subchoice);
        while(fread(x, sizeof(struct student), 1, fp)){
            if(sNum == x->sNum){
                if(subchoice==1){
                    found = 1;
                    printf("Student number(%i): ", x->sNum); scanf("%i", &x->sNum);
                }
                else if(subchoice==2){
                    found = 1;
                    printf("Last name(%s): ", x->lName); scanf("%s", x->lName);
                }
                else if(subchoice==3){
                    found = 1;
                    printf("First name(%s): ", x->fName); scanf("%s", x->fName);
                }
                else if(subchoice==4){
                    found = 1;
                    printf("Course(%s): ", x->course); scanf("%s", x->course);
                }
                else if(subchoice==5){
                    found = 1;
                    printf("Year level(%i)", x->yLevel); scanf("%i", &x->yLevel);
                }
                else if(subchoice==6){
                    found = 1;
                    printf("Age(%i)", x->age); scanf("%i", &x->age);
                }
                else if(subchoice==7){
                    found = 1;
                    printf("Sex(%s)", x->sex); scanf("%s", x->sex);
                }
                else if(subchoice==8){
                    found = 1;
                    printf("Final grade(%i)", x->grade); scanf("%i", &x->grade);
                }
            }
            fwrite(x, sizeof(struct student), 1, fp_temp);
        }
        if(!found)
                printf("Record not found\n");
            else{
                fclose(fp); fclose(fp_temp);
                remove("student.dat");
                rename("copy.dat","student.dat");
                printf("File successfully updated!\n");
            }
    }while(subchoice!=9);
}
void drop(){ //only transfers the data except the to-drop student
    struct student* x = malloc(sizeof(struct student));
    FILE* fp = fopen("student.dat", "rb+");
    FILE* fp_copy = fopen("copy.dat", "ab+");
    if(!fp){
        printf("Cannot open file\n");
        exit(0);
    }
    int id;
    printf("Enter student number: "); scanf("%i", &id);
    while(fread(x, sizeof(struct student), 1, fp)){
        if(id!=x->sNum){
            fwrite(x, sizeof(struct student),1,fp_copy);
        }
    }
    fclose(fp); fclose(fp_copy);
    // the new data is now in copy.dat and will be renamed to student.dat
    remove("student.dat");
    rename("copy.dat","student.dat");
    printf("Record deleted successfully\n");
}
void display_filter(struct student* x){
    printf("\nStudent number: %i\n", x->sNum); 
    printf("Last name: %s\n", x->lName); 
    printf("First name: %s\n", x->fName);
    printf("Course: %s\n", x->course); 
    printf("Year level: %i\n", x->yLevel); 
    printf("Age: %i\n", x->age); 
    printf("Sex: %s\n", x->sex); 
    printf("Final Grade: %i\n\n", x->grade);
}
void filter(int choice){ // filters out the desired data amd prints it out
    struct student* x = malloc(sizeof(struct student));
    FILE* fp = fopen("student.dat","rb"); 
    if(choice==5){
        char lName[15];
        printf("Enter last name: "); scanf("%s", lName);
        while(fread(x,sizeof(struct student), 1, fp)){
            if(strcmp(lName, x->lName)==0)
                display_filter(x);
        }
    }
    else if(choice==6){
        int sNum;
        printf("Enter student number: "); scanf("%i", &sNum);
        while(fread(x,sizeof(struct student), 1, fp)){
            if(sNum == x->sNum)
                display_filter(x);
        }
    }
    else if(choice==7){
        int yLevel;
        printf("Enter year level: "); scanf("%i", &yLevel);
        while(fread(x, sizeof(struct student), 1, fp)){
            if(yLevel == x->yLevel)
                display_filter(x);
        }
    }
    else if(choice==8){
        char course[15];
        printf("Enter course: "); scanf("%s", course);
        while(fread(x, sizeof(struct student), 1, fp)){
            if(strcmp(course, x->course)==0)
                display_filter(x);
        }
    }
    else if(choice==9){
        char sex[15];
        printf("Enter sex: "); scanf("%s", sex);
        while(fread(x, sizeof(struct student), 1, fp)){
            if(strcmp(sex, x->sex)==0)
                display_filter(x);
        }
    }
    else if(choice==10){
        int pass = 0;
        while(fread(x, sizeof(struct student), 1, fp)){
            if(x->grade>=60){
                display_filter(x);
                pass = 1;
            }
        }
        if(pass==0)
            printf("Oh no, no student passed\n");
    }
    else if(choice==11){
        int fail = 0;
        while(fread(x, sizeof(struct student), 1, fp)){
            if(x->grade<60){
                display_filter(x);
                fail = 1;
            }
        }
        if(fail==0)
            printf("Hooray everyone passed!\n");
    }
    
    fclose(fp);
}
void display(){ // display all the records ion the file
    struct student* x = malloc(sizeof(struct student));
    FILE* fp = fopen("student.dat","rb+");
    if(!fp)
        printf("Cannot open\n");
    while(fread(x, sizeof(struct student),1,fp)){ // continues to print while there are records in the file
        printf("\nStudent number: %i\n", x->sNum);
        printf("Last name: %s\n", x->lName);
        printf("First name: %s\n", x->fName);
        printf("Course: %s\n", x->course);
        printf("Age: %i\n", x->age);
        printf("Sex: %s\n", x->sex);
        printf("Final grade: %i\n", x->grade);
    }
    fclose(fp);
}
void sort(int choice){ //sorts the file to display on the screen and not permanently on file
    struct student x;
    struct student* y;
    FILE* fp = fopen("student.dat","rb");
    fseek(fp,0, SEEK_END); // sets the pointer at the end of the file 
    int n = ftell(fp)/sizeof(struct student); // checks how many records are there in the file
    if(choice==12){
        y = calloc(n, sizeof(struct student));
        rewind(fp);
        for(int i=0; i<n; i++)
            fread(&y[i], sizeof(struct student),1,fp);
        for(int i=0; i<n;i++){
            for(int j=i+1; j<n; j++){
                // if both family names are the same, it checks the first name
                if(strcmp(y[i].lName,y[j].lName)==0){
                    if(strcmp(y[i].fName,y[j].fName)>0){
                        x = y[i];
                        y[i] = y[j];
                        y[j] = x;
                    }
                }
                else if(strcmp(y[i].lName,y[j].lName)>0){
                    x = y[i];
                    y[i] = y[j];
                    y[j] = x;
                }
            }
        }
    }
    else if(choice==13){    
        y = calloc(n, sizeof(struct student));
        rewind(fp);
        for(int i=0; i<n; i++)
            fread(&y[i], sizeof(struct student),1,fp);
        for(int i=0; i<n;i++){
            for(int j=i+1; j<n; j++){
                if(y[i].sNum > y[j].sNum){
                    x = y[i];
                    y[i] = y[j];
                    y[j] = x;
                }
            }
        }
    }
    for(int i=0; i<n; i++){
            printf("\nStudent number: %i\n", y[i].sNum);
            printf("Last name: %s\n", y[i].lName);
            printf("First name: %s\n", y[i].fName);
            printf("Course: %s\n", y[i].course);
            printf("Age: %i\n", y[i].age);
            printf("Sex: %s\n", y[i].sex);
            printf("Final grade: %i\n", y[i].grade);
        }
    fclose(fp);
}
int main(){
    int choice=0;
    do{
        printf("\n1. Enroll a student\n2. Drop a student\n3. Edit a student\n4. Display all students\n5. Filter student by last number\n");
        printf("6. Filter students by student number\n7. Filter students by year level\n8. Filter students by course\n9. Filter students by sex\n10. Filter students by passing\n11. Filter students by failing\n");
        printf("12. Sort students by last name\n13. Sort students by student number\n14. Exit\n\n? "); scanf("%i", &choice);
        switch(choice){
        case 1: enroll();break;
        case 2: drop(); break;
        case 3: edit(); break;
        case 4: display(); break;
        case 5: filter(5); break;
        case 6: filter(6); break;
        case 7: filter(7); break;
        case 8: filter(8); break;
        case 9: filter(9); break;
        case 10: filter(10); break;
        case 11: filter(11); break;
        case 12: sort(12); break;
        case 13: sort(13); break;
    }
    }while(choice!=14);

}
