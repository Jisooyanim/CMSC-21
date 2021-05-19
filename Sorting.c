#include <stdio.h>

void sort(int size, int *array);

int main(){
    int size;

    printf("Size: ");
    scanf("%i", &size);
    int array[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%i", (array + i));
    }

    sort(size,array);

    for (int i = 0; i < size; i++)
    {
        printf("%i ", *(array + i));
    }

    return 0;
}

void sort(int size, int *array){
    int temp;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if(*(array + i) > *(array + j)){
                temp = *(array + i);
                *(array + i) = *(array + j);
                *(array + j) = temp;
            }
        }
    }  
}