#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int studentnum;
    char last[15];
    char first[15];
    char course[15];
    int year;
    int age;
    char sex[15];
    int grade;
    int present;
} Student;

int valid(int student_num){
    FILE* fp = fopen("sis.txt", "rb+");
    if(!fp){
        printf("Error!\n");
    }

    Student s; int valid = 0;
    while(fread(&s, sizeof(Student), 1, fp) && !feof(fp)){
        if(s.present == 1 && s.studentnum == student_num){
            valid = 1;
        }
    }
    fclose(fp);
    return valid; 
}

void enroll(){
    Student s;
    FILE* fp = fopen("sis.txt", "rb+");
    char temp[15];
    if(!fp){
        printf("ERROR!\n");
    }else{
        printf("\n\nEnroll\n");

        do{
            printf("Student Number [1-300]: ");
            scanf("%i", &s.studentnum);
        }while(s.studentnum <= 0 || s.studentnum > 300 || valid(s.studentnum));

        do{
            printf("Last Name: ");
            scanf("%s", &temp);
        }while(strlen(temp) > 15);
        strcpy(s.last, temp);

        do{
            printf("First Name: ");
            scanf("%s", &temp);
        }while(strlen(temp) > 15);
        strcpy(s.first, temp);

        do{
            printf("Course: ");
            scanf("%s", &temp);
        }while(strlen(temp) > 15);
        strcpy(s.course, temp);

        printf("Year: ");
        scanf("%i", &s.year);
        printf("Age: ");
        scanf("%i", &s.age);
        printf("Sex: ");
        scanf("%s", &s.sex);
        do{
            printf("Final Grade: ");
            scanf("%i", &s.grade);
        }while(s.grade < 0 || s.grade > 100);

        s.present = 1;
        fseek(fp,sizeof(Student) * (s.studentnum - 1), SEEK_SET);
        fwrite(&s, sizeof(Student), 1, fp);
        printf("%i enrolled!\n\n", s.studentnum);
    }
    fclose(fp);
}
//1 for last name, 2 for first name, 3 for course, 4 for sex
void reset_string(Student* s, char* reset, int mode){
    for(int i = 0; reset[i] != '\0'; i++){
        if(mode == 1)
            s->last[i] = reset[i];
        if(mode == 2)
            s->first[i] = reset[i];
        if(mode == 3)
            s->course[i] = reset[i];
        if(mode == 4)
            s->sex[i] = reset[i];
    }
}
//If -1, ask for student number,
void drop(int mode){
    char* reset = (char*)malloc(sizeof(char) * 15);
    Student s;
    FILE* fp = fopen("sis.txt", "rb+");
    if(!fp){
        printf("\nError!\n\n");
    }else{
        if(mode == -1){
            printf("Student Number: ");
            scanf("%i", &s.studentnum);
        }else{
            s.studentnum = mode;
        }
        if(valid(s.studentnum)){
            s.present = 0;
            reset_string(&s, reset, 1);
            reset_string(&s, reset, 2);
            reset_string(&s, reset, 3);
            s.year = 0;
            s.age = 0;
            reset_string(&s, reset, 4);
            s.grade = 0;
            fseek(fp, sizeof(Student) * (s.studentnum - 1), SEEK_SET);
            fwrite(&s, sizeof(Student), 1, fp);
            if(mode == -1){
                printf("%i dropped!", s.studentnum);
            }
        }else{
            printf("%i does not exist!", s.studentnum);
        }
    }
    free(reset);
    fclose(fp);
}

Student information(int student){
    FILE* fp = fopen("sis.txt", "rb+");
    if(!fp){
        printf("Error!\n\n");
    }
    Student s, scan;
    scan.present = 0;
    while(fread(&s, sizeof(Student), 1, fp) && !feof(fp)){
        if(s.present == 1 && s.studentnum == student)
            scan = s;
    }
    fclose(fp);
    return scan;
}
//1 for main, 2 for edit
void menu(int mode){
    switch(mode){
        case 1: 
            printf("STUDENT INFORMATION SYSTEM\n\n");
            printf("1. Enroll a student\n");
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
            printf("14. Exit\n");
            printf("? \n");
            break;
        
        case 2: 
            printf("\nEdit\n"); 
            printf("1. Student number \n");
            printf("2. Last name \n");
            printf("3. First name \n");
            printf("4. Course \n");
            printf("5. Year level \n");
            printf("6. Age\n");
            printf("7. Sex\n");
            printf("8. Final Grade \n");
            printf("9. Back \n");
            printf("? \n");
            break;
    }
    return;
}

void edit(){
    int choice, temp, pain = 0;
    Student s;
    FILE* fp = fopen("sis.txt", "rb+");
    if(!fp){
        printf("Error!\n\n");
    }else{
        printf("Student Number: ");
        scanf("%i", &s.studentnum);
        if(valid(s.studentnum)){
            s = information(s.studentnum);
            if(s.present != 1){
                printf("Error!\n\n");
                return;
            }

            do{
                menu(2);
                scanf("%i", &choice);

                switch(choice){
                    case 1:
                        temp = s.studentnum;
                        printf("Student Number [%i]: ", s.studentnum);
                        scanf("%i", &s.studentnum);
                        drop(s.studentnum);
                        s.studentnum = temp;
                        printf("\nStudent Number updated!");
                        break;
                    
                    case 2:
                        printf("Last name [%s]: ", s.last);
                        scanf("%s", &s.last);
                        printf("\nLast name updated!");
                        break;

                    case 3:
                        printf("First name [%s]: ", s.first);
                        scanf("%s", &s.first);
                        printf("\nFirst name updated!");
                        break;

                    case 4:
                        printf("Course [%s]: ", s.course);
                        scanf("%s", &s.course);
                        printf("\nCourse updated!");
                        break;
                    
                    case 5:
                        printf("Year [%i]: ", s.year);
                        scanf("%i", &s.year);
                        printf("\nYear updated!");
                        break;
                    
                    case 6:
                        printf("Age [%i]: ");
                        scanf("%i", &s.age);
                        printf("\nAge updated!");
                        break;

                    case 7:
                        printf("Sex [%s]: ", s.sex);
                        scanf("%s", &s.sex);
                        printf("\nSex updated!");
                        break;

                    case 8:
                        printf("Final Grade [%i]: ", s.grade);
                        scanf("%i", &s.grade);
                        printf("\nFinal Grade updated!");
                        break;

                    case 9:
                        pain = 1;
                        break;
                    
                    default:
                        break;
                }
            }while(pain == 0);
            fseek(fp, sizeof(Student) * (s.studentnum - 1), SEEK_SET);
            fwrite(&s, sizeof(Student), 1, fp);
        }else{
            printf("%i does not exist!", s.studentnum);
        }
    }
    fclose(fp);
}

char caps(char a){
    if(a >= 97 && a <= 122)
        a -= 32;
    return a;
}

int compare_string(char* a, char* b){
    for(int i = 0; a[i] != '\0' || b[i] != '\0'; i++){
        if(caps(a[i]) != caps(b[i]))
            return 0;
    }
    return 1;
}

//0 - all 1 - Last 2 - Studnum 3 - Year 4 - Course 5 - Sex 6/7 - Grade 
void display(int mode){
    char temp[15];
    int t, count = 0, all = 0;
    Student s;
    FILE* fp = fopen("sis.txt", "rb+");
    if(!fp){
        printf("Error!\n\n");
    }else{
        if(mode == 1){
            printf("Last Name: ");
            scanf("%s", &temp);
        }else if(mode == 2){
            printf("Student Number: ");
            scanf("%i", &t);
        }else if(mode == 3){
            printf("Year: ");
            scanf("%i", &t);
        }else if(mode == 4){
            printf("Course: ");
            scanf("%s", &temp);
        }else if(mode == 5){
            printf("Sex: ");
            scanf("%s", &temp);
        }

        while(fread(&s, sizeof(Student), 1, fp) && !feof(fp)){
            if(s.present == 1){
                if((mode == 0) || (mode == 1 && compare_string(s.last, temp)) || (mode == 2 && s.studentnum == t) || (mode == 3 && s.year == t) || (mode == 4 && compare_string(s.course, temp)) || (mode == 5 && compare_string(s.sex, temp)) || (mode == 6 && s.grade >=60) || (mode == 7 && s.grade < 60)){
                   printf("\n\nStudent Number: %i\nLast Name: %s\nFirst Name: %s\nCourse: %s\nYear : %i\nAge: %i\nSex: %s\nFinal Grade: %i\n\n",s.studentnum, s.last, s.first, s.course, s.year, s.age, s.sex, s.grade); 
                   count++;
                }
            all++;
            }
        }
        printf("Displaying %i out of %i students.\n", count, all);
    }
    fclose(fp);
}

int compare_size(char* a, char* b){
    for(int i = 0; a[i] != '\0' || b[i] != '\0'; i++){
        if(a[i] > b[i])
            return 1;
    }
    return 0;
}

void swap(Student* a, Student* b){
    Student temp = *a;
    *a = *b;
    *b = temp;
}
//1 - Last 2 - Student number
void sort(int mode){
    int size = 0, count = 0;
    Student s;
    FILE* fp = fopen("sis.txt", "rb+");
    FILE* fp2 = fopen("sis.txt", "rb+");
    if(!fp || !fp2){
        printf("Error!\n\n");
    }else{
        while(fread(&s, sizeof(Student), 1, fp) && !feof(fp)){
            if(s.present == 1)
                size++; 
        }
        Student arr[size];
        while(fread(&s, sizeof(Student), 1, fp2) && !feof(fp2)){
            if(s.present == 1)
                arr[count] = information(s.studentnum);
                count++;
        }
        for(int i = 0; i < size - 1;i++){
            for(int j = 0; j < size - i - 1; j++){
                if((mode == 1 && compare_size(arr[j].last, arr[j + 1].last)) || mode == 2 && arr[j].studentnum > arr[j + 1].studentnum)
                    swap(&arr[j], &arr[j + 1]);
            }
        }
        for(int i = 0; i < size; i++){
            printf("\n\nStudent number: %i\nLast Name: %s\nFirst Name: %s\nCourse: %s\nYear: %i\nAge: %i\nSex: %s\nFinal Grade: %i\n\n", arr[i].studentnum, arr[i].last, arr[i].first, arr[i].course, arr[i].year, arr[i].age, arr[i].sex, arr[i].grade);
        }
        printf("Displaying %i out of %i students. \n", count, size);
    }
    fclose(fp);
    fclose(fp2);
}

int main(){
    int choice, pain = 0;
    do{
        menu(1);
        scanf("%i", &choice);
        switch(choice){
            case 1:
                enroll();
                break;
            case 2:
                drop(-1);
                break;
            case 3:
                edit();
                break;
            case 4:
                display(0);
                break;
            case 5:
                display(1);
                break;
            case 6:
                display(2);
                break;
            case 7:
                display(3);
                break;
            case 8:
                display(4);
                break;
            case 9:
                display(5);
                break;
            case 10:
                display(6);
                break;
            case 11:
                display(7);
                break;
            case 12:
                sort(1);
                break;
            case 13:
                sort(2);
                break;
            case 14:
                printf("\n\nYou have exited the program!\n\n");
                pain = 1;
                break;
        }
    }while(pain == 0);
    return 0;
}
