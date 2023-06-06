#include <stdio.h>

/*int validate_set(int[],int);
void accept_set(int[], int);
void Display_set(int[], int);
void intersection_set(int[], int, int[], int, int[], int);
void union_set(int[], int, int[], int, int[], int);
void sub_set(int[], int, int[], int, int[], int);*/

void validate_set(int *, int *, int *);
void accept_set(int *, int *);
void Display_set(int *, int *);
void intersection_set(int *, int *, int *, int *, int *, int *);
void union_set(int *, int *, int *, int *, int *, int *);
void sub_set(int *, int *, int *, int *, int *, int *);

int main()
{
    int n1, n2, n3;
    int set1[10], set2[10], set3[10];
    int op;
    int run = 1;

    do
    {
        printf("\nMENU :\n1. Accept sets.\n2. Display sets.\n3. Intersection of the sets.\n4. Union of the sets.\n5. Substration of sets.\n6. Exit the Program.");
        printf("\nSelect an option :");

        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the no. of elements in set 1 (max 10) :");
            scanf("%d", &n1);
            // accept_set(set1, n1);
            accept_set(set1, &n1);

            printf("\nEnter the no. of elements in sets 2 (max 10):");
            scanf("%d", &n2);
            // accept_set(set2, n2);
            accept_set(set2, &n2);
            break;

        case 2:
            printf("\nThe set1 is :");
            // Display_set(set1,n1);
            Display_set(set1, &n1);

            printf("\nThe set2 is :");
            // Display_set(set2, n2);
            Display_set(set2, &n2);
            break;

        case 3:
            // intersection_set(set1, n1, set2, n2, set3, n3);
            intersection_set(set1, &n1, set2, &n2, set3, &n3);

            break;

        case 4:
            // union_set(set1, n1, set2, n2, set3, n3);
            union_set(set1, &n1, set2, &n2, set3, &n3);
            break;

        case 5:
            // sub_set(set1, n1, set2, n2, set3, n3);
            sub_set(set1, &n1, set2, &n2, set3, &n3);
            break;
        case 6:
            printf("\nThank you");
            // return 0;
            run = 0;
            break;

        default:
            printf(" \nPlease Select only from the options given.");
            break;
        }
    } while (run /*1*/);
}
/*void validate_set(int s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1 + i; j < n; j++)
        {
            if (s[i] == s[j])
            {
                return 1;
            }
        }
    }
    return 0;
}
*/
void validate_set(int *s, int *n, int *repeat)
{
    for (int i = 0; i < *n - 1; i++)
    {
        for (int j = 1 + i; j < *n; j++)
        {
            if (*(s + i) == *(s + j))
            {
                *repeat = 1;
            }
        }
    }
}

/*void accept_set(int s[], int n)
{   int repeat;
    printf("\nEnter the elements on the set :");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    repeat =validate_set(s, n);
    if (repeat == 1)
    {
        printf("\nAtleast one of the element is repeated.\nTry again!!");
        accept_set(s, n);
    }*/
void accept_set(int *s, int *n)
{
    int repeat = 0;
    printf("\nEnter the elements on the set :");
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", (s + i));
    }
    validate_set(s, n, &repeat);
    if (repeat == 1)
    {
        printf("\nAtleast one of the element is repeated.\nTry again!!");
        accept_set(s, n);
    }
}
/*void Display_set(int s[], int n)
{
    printf(" {");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", s[i]);
        if (i != n - 1)
        {
            printf(",");
        }
    }
    printf("}.\n");
}*/
void Display_set(int *s, int *n)
{
    printf(" {");
    for (int i = 0; i < *n; i++)
    {
        printf(" %d ", *(s + i));
        if (i != *n - 1)
        {
            printf(",");
        }
    }
    printf("}.\n");
}

/*void intersection_set(int s1[], int n1, int s2[], int n2, int s3[], int n3)
{
    n3 = 0;
    // int s3[10];
    for (int i = 0; i < n1; i++)
    {
        // int j =0;
        for (int j = 0; j < n2; j++)
        {
            if (s1[i] == s2[j])
            {
                s3[n3] = s1[i];
                n3++;
                break;
            }
        }
    }
    Display_set(s3, n3);
}*/
void intersection_set(int *s1, int *n1, int *s2, int *n2, int *s3, int *n3)
{
    *n3 = 0;
    // int s3[10];
    for (int i = 0; i < *n1; i++)
    {
        // int j =0;
        for (int j = 0; j < *n2; j++)
        {
            if (*(s1 + i) == *(s2 + j))
            {
                *(s3 + *n3) = *(s1 + i);
                (*n3)++; // *n3++ means *(n3++)
                break;
            }
        }
    }
    Display_set(s3, n3);
}

/*void union_set(int s1[], int n1, int s2[], int n2, int s3[], int n3)
{
    //int n3 = n1;
    //int s3[10];
    n3 = n1;
    for (int i = 0; i < n3; i++)
    {
        s3[i] = s1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        int j = 0;
        for (j = 0; j < n1; j++)
        {
            if (s2[i] == s1[j])
            {
                break;
            }
        }

        if (j == n1)
        {
            s3[n3] = s2[i];
            n3++;
        }
    }
    Display_set(s3, n3);
}*/
void union_set(int *s1, int *n1, int *s2, int *n2, int *s3, int *n3)
{
    // int n3 = n1;
    // int s3[10];
    *n3 = *n1;
    for (int i = 0; i < *n3; i++)
    {
        *(s3 + i) = *(s1 + i);
    }
    for (int i = 0; i < *n2; i++)
    {
        int j;
        for (j = 0; j < *n1; j++)
        {
            if (*(s2 + i) == *(s1 + j))
            {
                break;
            }
        }

        if (j == *n1)
        {
            *(s3 + *n3) = *(s2 + i);
            (*n3)++;
        }
    }
    Display_set(s3, n3);
}

/*void sub_set(int s1[], int n1, int s2[], int n2, int s3[], int n3)
{
    // n3 = n1;
    n3 = 0;
    for (int i = 0; i < n1; i++)
    {
        int j;
        for (j = 0; j < n2; j++)
        {
            if (s1[i] == s2[j])
            {
                break;
            }
        }
        if (j == n2)
        {
            s3[n3] = s1[i];
            n3++;
        }
    }
    Display_set(s3, n3);
}*/
void sub_set(int *s1, int *n1, int *s2, int *n2, int *s3, int *n3)
{
    // n3 = n1;
    *n3 = 0;
    for (int i = 0; i < *n1; i++)
    {
        int j;
        for (j = 0; j < *n2; j++)
        {
            /*if (s1[i] !=s2[j] )
            {
                s3[n3] = s1[i];
                n3++;
                break;
            }
            else{continue;}*/
            if (*(s1 + i) == *(s2 + j))
            {
                break;
            }
        }
        if (j == *n2)
        {
            *(s3 + *n3) = *(s1 + i);
            (*n3)++;
        }
    }
    Display_set(s3, n3);
}