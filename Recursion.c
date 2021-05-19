#include <stdio.h>

int division(int A, int B);
int prime(int A, int B);
int binarySearch(int arr[], int first, int last, int x);

int main()
{
    int choice, a, b;

    printf("Choice:");
    scanf("%i", &choice);

    if (choice == 1)
    {
        printf("Enter  A and B:");
        scanf("%i %i", &a, &b);

        printf("%i", division(a, b));
    }

    if (choice == 2)
    {
        printf("Enter A and B: ");
        scanf("%i %i", &a, &b);

        if (prime(a, b) == 1)
            printf("1");
        else
            printf("0");
    }

    if (choice == 3)
    {
        int size, i, input_array[20], N, ans;

        printf("Enter the size of the array: ");
        scanf("%i", &size);

        printf("Enter ascending integers:");
        for (i = 0; i < size; i++)
        {
            scanf("%i", &input_array[i]);
        }

        printf("Enter the number to be searched: ");
        scanf("%i", &N);

        ans = binarySearch(input_array, 0, size - 1, N);
        if(ans == 1)
            printf("1");
        else
            printf("0");
    }
    return 0;
}

int division(int A, int B)
{
    A -= B;
    if (A < B)
        return 1;
    return 1 + division(A, B);
}

int prime(int A, int B)
{
    if (B != 0)
        return prime(B, A % B);
    else
        return A;
}

int binarySearch(int arr[], int first, int last, int search)
{
        int mid = (first + last) / 2;

        if (arr[mid] == search)
            return 1;
        else if (arr[mid] > search && last != mid - 1)
            return binarySearch(arr, first, mid - 1, search);
        else if (arr[mid] < search && first != mid + 1)
            return binarySearch(arr, mid + 1, last, search);
        else
            return 0;
}