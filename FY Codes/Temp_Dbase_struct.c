#include <stdio.h>

typedef struct Student
{
    char name[10 + 1];
    short int roll_no;
    float marks;
    short int flag;
} STUD;

STUD accept_rec();
int create_db(STUD db[]);
void display(STUD s);
void display_db(STUD db[], int db_size);
int search(STUD data_base[], int db_size, int key);
// int BinarySearch(STUD data_base[], int db_size, int key);
int modify(STUD data_base[], int db_size, int key);
int del_per(STUD data_base[], int db_size, int key);
int del_logical(STUD data_base[], int db_size, int key);
void displaydel(STUD data_base[],int db_size);
/*
void sort(STUD data_base[],int db_size);
*/
int main()
{
    int opt;
    int nRet;
    int num, db_size = 0;
    STUD data_base[5];

    do
    {
        printf("\n1.Create DataBase\n2.Display DataBase\n3.Search\n4.Modify\n5.Permanent Delete\n6.Delete\n7.Sort\n8.Insert Record\n9.Display deleted Record\n10.Exit");
        printf("\nSlect an option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            db_size = create_db(data_base);
            break;

        case 2:
            if (db_size == 0)
                printf("\nNo Records.");
            else
                display_db(data_base, db_size);
            break;

        case 3:
            printf("\nEnter the Roll No. for searching: ");
            scanf("%d", &num);
            nRet = search(data_base, db_size, num);
            if (nRet == -1)
                printf("\nNo Records.");

            else
            {
                printf("\nRecords are : ");
                display(data_base[nRet]);
            }
            break;
        case 4:
            printf("Enter the Roll No. to modify : ");
            scanf("%d", &num);
            nRet = modify(data_base, db_size, num);
            if (nRet == -1)
                printf("\nRecords not Found.\n");

            else
            {
                printf("\nRecords Modified. ");
                display(data_base[nRet]);
            }
            break;

        case 5:
            printf("Enter the roll no. to delete permenant : ");
            scanf("%d", &num);
            db_size = del_per(data_base, db_size, num);
            if (db_size == -1)
                printf("\nRecords not Found.\n");

            else
            {
                printf("\nRecords Permanently Deleted.");
            }
            break;

        case 6:
            printf("Enter the roll no. to delete : ");
            scanf("%d", &num);
            del_logical(data_base, db_size, num);
            if (db_size == -1)
                printf("\nRecords not Found.\n");

            else
            {
                printf("\nRecords Logically Deleted.");
            }

            break;

            /*
                    case 7:
                        sort(data_base, db_size);
                        display(data_base, db_size);
                        break;
            */
                    case 8:
                        data_base[db_size] = accept_rec();
                        db_size++;
                         printf("\nRecords inserted.\n");
                        break;

                    case 9:
                        displaydel(data_base, db_size);
                        break;
        }
    } while (opt != 10);

    return 0;
}

STUD accept_rec()
{
    STUD s;
    printf("\nEnter the Name(max 10 letters), Roll NO. and Marks :");
    scanf("%s %d %f", s.name, &s.roll_no, &s.marks);
    s.flag = 0;
    return s;
}

int create_db(STUD data_base[])
{
    int dbIndex = 0;
    int n;

    printf("How many student Entries( max. 5 ) ? ");
    scanf("%d", &n);

    while (dbIndex < 5 && dbIndex < n)
    {
        data_base[dbIndex] = accept_rec();
        dbIndex++;
    }

    return dbIndex;
}

void display_db(STUD db[], int db_size)
{
    printf("\nStudent Details:\n");
    for (int dbIndex = 0; dbIndex < db_size; dbIndex++)
    {
        display(db[dbIndex]);
    }
}
void display(STUD s)
{
    if (s.flag == 0)
        printf("\n Name: %s \n Roll NO.: %d \n Marks: %f\n", s.name, s.roll_no, s.marks);
}

int search(STUD data_base[], int db_size, int key)
{
    for (int i = 0; i < db_size; i++)
    {
        if (data_base[i].roll_no == key)
        {
            return i;
        }
    }
    return -1;
}
int modify(STUD data_base[], int db_size, int key)
{
    int nRet = search(data_base, db_size, key);
    if (nRet == -1)
        return -1;

    else
    {
        data_base[nRet] = accept_rec();
    }
    return nRet;
}

int del_per(STUD data_base[], int db_size, int key)
{
    int nRet = search(data_base, db_size, key);
    if (nRet == -1)
        return -1;

    else
    {
        for (nRet; nRet < db_size - 1; nRet++)
        {
            data_base[nRet] = data_base[nRet + 1];
        }
        db_size = nRet;
    }
    return db_size;
}

int del_logical(STUD data_base[], int db_size, int key)
{
    int nRet = search(data_base, db_size, key);
    if (nRet == -1)
        return -1;

    else
    {
        data_base[nRet].flag = 1;
    }
    return 0;
}


void displaydel(STUD data_base[],int db_size)
{
    printf("\nLogically Deleted Student Details:\n");
    for (int i = 0; i < db_size; i++)
    {
    if (data_base[i].flag == 1)
        printf("\n Name: %s \n Roll NO.: %d \n Marks: %f\n", data_base[i].name, data_base[i].roll_no, data_base[i].marks);
    }
}