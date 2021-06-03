#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Student{
    char studentnum[15];
    char last[15];
    char first[15];
    char course[15];
    int year;
    int age;
    char sex;
    int grade;

    struct Student* next;
};
typedef struct Student Student;

typedef struct{
    Student* head;
    Student* tail;
    int size;
}SLL;

void initlist(SLL* list){
    list->head = 0;
    list->tail = 0;
    list->size = 0;
}

int valid(char* a){
    int valid = 0;
    for(int i = 0; a[i] != '\0'; i++){
        if(a[i] == 45)
            valid = 1;
        if((a[i] < 48 || a[i] > 57) && a[i] != 45)
            return 0;
    }
    return valid * 1;
}

Student* information(){
    Student* s = (Student*)malloc(sizeof(Student));
    char temp[15];
    
    printf("\n\nEnroll\n");
    do{
        printf("Student Number: ");
        scanf("%s", &temp);
    }while(!valid(temp));
    strcpy(s->studentnum, temp);

    do{
        printf("Last Name: ");
        scanf("%s", &temp);
    }while(strlen(temp) > 15);
    strcpy(s->last, temp);

    do{
        printf("First Name: ");
        scanf("%s", &temp);
    }while(strlen(temp) > 15);
    strcpy(s->first, temp);

    do{
        printf("Course: ");
        scanf("%s", &temp);
    }while(strlen(temp) > 15);
    strcpy(s->course, temp);

    printf("Year: ");
    scanf("%i", &s->year);
    printf("Age: ");
    scanf("%i", &s->age);

    do{
        printf("Sex [M/F]: ");
        scanf("%c", &s->sex);
        scanf("%c", &s->sex);
        s->sex = toupper(s->sex);
    }while(s->sex != 'M' && s->sex != 'F');

    do{
        printf("Final Grade: ");
        scanf("%i", &s->grade);
    }while(s->grade < 0 || s->grade > 100);

    s->next = 0;
    return s;
}

Student* getinfo(SLL* list, int index){
    Student* current = list->head;
    if(index >= 0 && index < list->size){
        for(int i = 0; i < index;i++){
            current = current->next;
        }
        return current;
    }
}

void insert(Student* s, SLL* list, int index){
    if(index >= 0 && index <= list->size){
        if(index == 0){
            s->next = list->head;
            list->head = s;
        }
        if(index == list->size){
            if(list->tail != 0)
                list->tail->next = s;
            list->tail = s;
        }
        if(index > 0 && index < list->size){
            Student* previous = getinfo(list, index - 1);
            s->next = previous->next;
            previous->next = s;
        }
    }
    return;
}

int enroll(Student* s, SLL* list){
    insert(s, list, list->size);
    list->size++;
    return list->size;
}

void drop(SLL* list, int index){
    Student* bye = list->head;

    if(index >= 0 && index < list->size){
        Student* bye;

        if(index == 0){
            bye = list->head;
            list->head = bye->next;
        }else{
            Student* previous = getinfo(list, index - 1);
            bye = previous->next;
            previous->next = bye->next;

            if(index == list->size - 1)
                list->tail = previous;
        }
        free(bye);
        list->size--;
    }
    return;
}

void edit(SLL* list, int index, int choice){
    Student* s = getinfo(list, index);
    char temp[15];
    char tmp;
    int t;
    
    switch(choice){
        case 1:                                                     
            printf("Student number [%s]: ", s->studentnum);
            scanf("%s", &temp);

            if (valid(temp))
                strcpy(s->studentnum, temp);
            else 
                printf("Invalid Student Number!\n");
            break;

        case 2:                                                     
            printf("Last Name [%s]: ", s->last);
            scanf("%s", &temp);

            if (strlen(temp) <= 15)
                strcpy(s->last, temp);
            else
                printf("Invalid Last Name!\n");
            break;

        case 3:                                                     
            printf("First Name [%s]: ", s->first);
            scanf("%s", &temp);

            if (strlen(temp) <= 15)
                strcpy(s->first, temp);
            else
                printf("Invalid First Name!\n");
            break;

        case 4:                                                     
            printf("Course [%s]: ", s->course);
            scanf("%s", &temp);

            if (strlen(temp) <= 15)
                strcpy(s->course, temp);
            else
                printf("Invalid Course.\n");
            break;

        case 5:                                                     
            printf("Year [%i]: ", s->year);
            scanf("%i", &s->year);
            break;

        case 6:                                                     
            printf("Age [%i]: ", s->age);
            scanf("%i", &s->age);
            break;

        case 7:                                                     
            printf("Sex [%c]: ", s->sex);
            scanf("%c", &tmp);
            scanf("%c", &tmp);
            tmp = toupper(tmp);

            if (tmp == 'M' || tmp == 'F')
                s->sex = tmp;
            else 
                printf("Invalid Sex!\n");
            break; 

        case 8:                                                     
            printf("Final Grade [%d]: ", s->grade);
            scanf("%i", &t);

            if (t >= 0 && t <= 100)
                s->grade = t;
            else
                printf("Invalid Final Grade!\n");
            break;
    }    
    return;
}
//1 - display 2 - edit
void submenu(Student* s, int mode){
    switch(mode){
        case 1: 
            printf("Student number: %s\n", s->studentnum);
            printf("Last name: %s\n", s->last);
            printf("First name: %s\n", s->first);
            printf("Course: %s\n", s->course);
            printf("Year level: %i\n", s->year);
            printf("Age: %i\n", s->age);
            printf("Sex: %c\n", s->sex);
            printf("Final Grade: %i\n", s->grade);
            break;
        case 2: 
            printf("\n\nEditing %s \n", s->studentnum); 
            printf("1. Student number: \n");
            printf("2. Last name: \n");
            printf("3. First name: \n");
            printf("4. Course: \n");
            printf("5. Year level: \n");
            printf("6. Age: \n");
            printf("7. Sex: \n");
            printf("8. Final Grade: \n");
            printf("9. Back \n");
            break;
    }
    return;
}

void display(SLL list){
    Student* current = list.head;
    for(int i = 0; i < list.size; i++){
        printf("\n\n");
        submenu(current, 1);
        current = current->next;
    }
    return;
}

int compare_string(char* a, char* b){
    for(int i = 0; a[i] != '\0' || b[i] != '\0'; i++){
        if(tolower(a[i]) > tolower(b[i]))
            return 1;
        else if(tolower(a[i]) < tolower(b[i]))
            return 2;
    }
    return 0;
}

int similar_string(char* a, char* b){
    if(strlen(a) == strlen(b)){
        for(int i = 0; i < strlen(a); i++){
            if(a[i] != b[i])
                return 0;
        }
        return 1;
    }
    return 0;
}
// 1 - last 2- student number 3 - year 4 - course 5 - sex 6/7 - grade
void filter(SLL* list, char* filter, int mode){
    int valid, present = 0;
    Student* current = list->head;

    for(int i = 0; i < list->size; i++){
        valid = 0;
        switch(mode){
            case 1:
                if(compare_string(current->last, filter) == 0)
                    valid = 1;
                break;
            
            case 2:
                if(similar_string(current->studentnum, filter) == 1)
                    valid = 1;
                break;

            case 3:
                if(atoi(filter) == current->year)
                    valid = 1;
                break;

            case 4:
                if(compare_string(current->course, filter) == 0)
                    valid = 1;
                break;
            
            case 5:
                if(filter[0] == current->sex)
                    valid = 1;
                break;

            case 6:
                if(current->grade >= 60)
                    valid = 1;
                break;

            case 7:
                if(current->grade < 60)
                    valid = 1;
                break;
        }

        if(valid == 1){
            printf("\n\n");
            submenu(current, 1);
            present = 1;
        }
        current = current->next;
    }
        if(present != 1)
            printf("\nStudent not found!\n");
        else    
            printf("\n");
    return;
}
// 1 - last 2 - student number
void sort(SLL* list, int mode){
    int valid, i;
    Student* previous, *current, *sorting;

    for(int k = 1; i < list->size; i++){
        previous = getinfo(list, k - 1);
        current = previous->next;
        valid = -1;

        switch(mode){
            case 1:
                if(compare_string(previous->last, current->last) == 1){
                    sorting = list->head;
                    for(i = 0; i <= k; i++){
                        if(compare_string(sorting->last, current->last) == 1){
                            valid = 0;
                            break;
                        }else if(compare_string(sorting->next->last, current->last) == 1){
                            valid = 1;
                            break;
                        }
                        sorting = sorting->next;
                    }
                }
                break;

            case 2:
                if(strcmp(previous->studentnum, current->studentnum) == 1){
                    sorting = list->head;

                    for(i = 0; i <= k; i++){
                        if(strcmp(sorting->studentnum, current->studentnum) == 1){
                            valid = 0;
                            break;
                        }else if(strcmp(sorting->next->studentnum, current->studentnum) == 1){
                            valid = 1;
                            break;
                        }
                        sorting = sorting->next;
                    }
                }
                break;
        }
        if(valid == 0 || valid == 1){
            if(current == list->tail){
                list->tail = previous;
                previous->next = 0;
            }else
                previous->next = current->next;

            if(valid == 0){
                current->next = sorting;
                list->head = current;
            }else if(valid == 1){
                current->next = sorting->next;
                sorting->next = current;
            }
        }
        previous = current;
        current = current->next;
    }
    return;
}

int get_student(SLL list, char* studentnumber){
    Student* current = list.head;
    if(valid(studentnumber) == 1){
        for(int i = 0; i < list.size; i++){
            if(similar_string(studentnumber, current->studentnum))
                return i;
            current = current->next;
        }
        return -1;
    }
}

void menu(){
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
    printf("?\n");
    return;
}

int main(){
    Student* s; SLL list;
    char temp[15];
    int index;

    initlist(&list);
    int choice, ch_edit;
    int pain = 0;

    do{
        menu();
        scanf("%i", &choice);

        switch(choice){
            case 1:
                s = information();
                if(get_student(list, s->studentnum) == -1){
                    enroll(s, &list);
                    printf("%s added!\n", s->studentnum);
                }
                else
                    printf("Error!\n\n");
                break;

            case 2:
                printf("\n\nDrop\nEnter Student Number: ");
                scanf("%s", &temp);
                
                if(valid(temp)){
                    index = get_student(list, temp);
                    if(index != -1){
                        drop(&list, index);
                        printf("\nSuccessful!\n\n");
                    }else{
                        printf("\nStudent does not exist!\n\n");
                    }
                }else   
                    printf("Error!\n\n");
                break;

            case 3:
                printf("\n\nEdit\nEnter Student Number: ");
                scanf("%s", &temp);
                if(valid(temp)){
                    index = get_student(list, temp);
                    if(index != -1){
                        s = getinfo(&list, index);
                        do{
                            submenu(s,2);
                            printf("\n? ");
                            scanf("%i", &ch_edit);
                            edit(&list, index, ch_edit);
                        }while(ch_edit != 9);
                    }else   
                        printf("\nStudent does not exist!\n\n");
                }else   
                    printf("\nError!\n\n");
                break;
            
            case 4:
                if(list.size != 0)
                    display(list);
                else
                    printf("\nEmpty record!\n\n");
                break;
            
            case 5:
                printf("Enter last name: ");
                scanf("%s", &temp);
                filter(&list, temp, 1);
                break;
            
            case 6:
                printf("Enter Student Number: ");
                scanf("%s", &temp);
                if(valid(temp))
                    filter(&list, temp, 2);
                else
                    printf("\nError!\n\n");
                break;
            
            case 7:
                printf("Enter Year: ");
                scanf("%i", &index);
                if(index >= 1 && index <= 7){
                    itoa(index, temp, 10);
                    filter(&list, temp, 3);
                }else
                    printf("\nError!\n\n");
                break;

            case 8:
                printf("Enter Course: ");
                scanf("%s", &temp);
                filter(&list, temp, 4);
                break;

            case 9:
                printf("Enter Sex: ");
                scanf("%c", &temp[0]);
                scanf("%c", &temp[0]);
                temp[0] = toupper(temp[0]);
                filter(&list, temp, 5);
                break;

            case 10:
                filter(&list, "", 6);
                break;
            
            case 11:
                filter(&list, "", 7);
                break;

            case 12:
                if(list.size != 0){
                    sort(&list, 1);
                    display(list);
                }else
                    printf("\nEmpty record!\n\n");
                break;
            
            case 13:
                if(list.size != 0){
                    sort(&list, 2);
                    display(list);
                }else
                    printf("\nEmpty record!\n\n");
                break;
            
            case 14:
                pain = 1;
                break;
            
            default:
                break;
        }
    }while(pain == 0);
    return 0;
}