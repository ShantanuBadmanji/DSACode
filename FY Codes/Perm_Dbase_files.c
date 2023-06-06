#include <stdio.h>
#include <stdlib.h>
struct student
{
    char name[20];
    int marks, roll;
};
void insert(FILE *fp)
{
    struct student s;
    char ch;
    fp = fopen("student.txt", "a+");
    if (fp == NULL)
    {
        printf("file cannot be opened ");
        return;
    }
    do
    {
        printf("enter the name ");
        scanf("%s", s.name);
        printf("enter the roll");
        scanf("%d", &s.roll);
        printf("enter the marks");
        scanf("%d", &s.marks);
        fwrite(&s, sizeof(s), 1, fp);
        printf("do you want to add more record? (Y/N).");
        scanf("%c", &ch);
    } while (ch == 'Y' || ch == 'y');
    fclose(fp);
}
void display(FILE *fp)
{
    struct student s;
    int i = 0;
    fp = fopen("student.txt", "r");
    if (fp == NULL)
    {
        printf("File cannot be openned");
        return;
    }
    while (fread(&s, sizeof(s), 1, fp))
    {
        i++;
        printf("\n Details of record %d", i + 1);
        printf("\nName :%s ", s.name);
        printf("\nrollno :%d", s.roll);
        printf("\nmarks :%d", s.marks);
        printf("\n");
    }
    fclose(fp);
}
void search(FILE *fp)
{
    struct student s;
    int i = 0, n;
    fp = fopen("student.txt", "r");
    if (fp == NULL)
    {
        printf("file cannot be openned");
        return;
    }
    printf("\n enter the roll no of student to be searched");
    scanf("%d", &n);
    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll == n)
        {
            printf("record found a location %d", i + 1);
            printf("Name :%s", s.name);
            printf("roll no:%d", s.roll);
            printf("marks:%d", s.marks);
            printf("\n");
            fclose(fp);
            return;
        }
        i++;
    }
    printf("\n Record Not Found");
    fclose(fp);
}
void del(FILE *fp, FILE *fs)
{
    struct student s;
    int n, i = 0, flag = 0;
    fp = fopen("Student.txt", "r+");
    if (fp == NULL)
    {
        printf("\n Source file cannot be opened");
        return;
    }
    fs = fopen("Temp.txt", "w+");
    if (fs == NULL)
    {
        printf("/n destioination file cannot be opened");
        return;
    }
    printf("\nEnter roll no. of student to be deleted:");
    scanf("%d", &n);
    while (fread(&s, sizeof(s), i, fp))
    {
        if (s.roll == n)
        {
            printf("\nrecord %d deleted successfully", i + 1);
            printf("\n\ndetails of record:");
            printf("\nName :%s", s.name);
            printf("\nroll no.:%d", s.roll);
            printf("\n marks:%d", s.marks);
            printf("\n");
            flag - 1;
        }
        else
        {
            fwrite(&s, sizeof(s), 1, fs);
        }
        i++;
    }
    if (flag == 0)
    {
        printf("\nrecord not found");
        return;
    }
    remove("student.txt");
    rename("tem.txt", "student.txt");
    fclose(fp);
    fclose(fs);
}
void modify(FILE *fp)
{
    struct student s;
    int n, i = 0, flag = 0;
    fp = fopen("student.txt", "r+");
    if (fp == NULL)
    {
        printf("\nfile cannot be opened!");
        return;
    }
    printf("\nenteer roll no. of student to be modified ");
    scanf("%d", &n);
    while (fread(&s, sizeof(s), 1, fp))
    {
        if (s.roll == n)
        {
            printf("\nrecord found at location %d", i - 1);
            printf("\nenter the new fields");
            printf("\nenter the name");
            scanf("%s", s.name);
            printf("\nenter roll no");
            scanf("%d", &s.roll);
            printf("\nenter marks");
            scanf("%d", &s.marks);
            //fseek(fp, (-1) * sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, fp);
            printf("\nrecord modified successfully");
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 0)
    {
        printf("\nrcord not foudn");
    }
    fclose(fp);
}
int main()
{
    FILE *fp, *fs;
    int choice;
    char ch;
    do
    {
        printf("\nMenu\n");
        printf("1.add student detail\n2.display\n3.search");
        printf("\n4.delete \n5.modify\n.6.Exit \nyour choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(fp);
            break;
        case 2:
            display(fp);
            break;
        case 3:
            search(fp);
            break;
        case 4:
            del(fp, fs);
            break;
        case 5:
            modify(fp);
            break;
        case 6:
            exit(0);
        default:
            printf("\nenter correct choice");
        }
    } while (choice != 0);
}
