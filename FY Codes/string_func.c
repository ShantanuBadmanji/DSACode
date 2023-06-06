#include <stdio.h>
int xstrlen(char *);
void xstrcpy(char *, char *);
void xstrcat(char *, char *);
int main()
{
    char str[] = "Shantanu";
    /*
    int len = xstrlen(str);
    printf("\nthen length of string is %d",len);
    */
   /*
    char copy[10];
    xstrcpy(copy, str);
    printf("\nthe copied string is %s\n", copy);
    for (int i = 0; i < 10; i++)
    {
        printf(" %c ", str[i]);
    }
    */
        char str1[30] = "Hello";
    xstrcat(str1, str);
    printf("the concatenated string is %s", str1);

    /*
    gets(str1);
    getline(str);
    puts(str1);
    */
}

int xstrlen(char *c)
{
    int length;
    while (*c != '\0')
    {
        length++;
        c++;
    }
    return length;
}

void xstrcpy(char *copy, char *str)
{
    while (*str != '\0')
    {
        *copy = *str;
        str++;
        copy++;
    }
    *copy = '\0';
}

void xstrcat(char *str1, char *str)
{
    while (*str1 != '\0')
    {
        str1++;
    }
    while (*str != '\0')
    {
        *str1 = *str;
        str++;
        str1++;
    }
    *str1 = '\0';
}