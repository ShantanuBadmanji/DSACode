#include <stdio.h>
#include <stdlib.h>

/*
 * This stores the total number of books in each shelf.
 */
int* total_number_of_books;

/*
 * This stores the total number of pages in each book of each shelf.
 * The rows represent the shelves and the columns represent the books.
 */
int** total_number_of_pages;

int main()
{
    int total_number_of_shelves;
    printf("total shelves :");
    scanf("%d", &total_number_of_shelves);
    total_number_of_pages = (int**)calloc(total_number_of_shelves,sizeof(int*));
    total_number_of_books = (int*)calloc(total_number_of_shelves,sizeof(int));
    
    int total_number_of_queries;
    printf("total query :");
    scanf("%d", &total_number_of_queries);
    
    while (total_number_of_queries--) {
        int type_of_query;
        printf("Query :");
        scanf("%d", &type_of_query);
        
        if (type_of_query == 1) {
            /*
             * Process the query of first type here.
             */
            int x, y;
            printf(" Insert a book with yth pages at the end of the xth  shelf");
            scanf("%d %d", &x, &y);
            if(total_number_of_books[x]==0){
                total_number_of_pages[x]=(int*)calloc(1, sizeof(int));
            }
            else {
                total_number_of_pages[x]=(int*)realloc(total_number_of_pages[x],total_number_of_books[x]+1);
            }
            total_number_of_pages[x][total_number_of_books[x]++] = y;
         

        } else if (type_of_query == 2) {
            int x, y;
            printf("Print the number of pages in the yth book on the xth shelf.");
            scanf("%d %d", &x, &y);
            printf("%d\n", *(*(total_number_of_pages + x) + y));
        } else {
            int x;
            printf("Print the number of books on the xth shelf.");
            scanf("%d", &x);
            printf("%d\n", *(total_number_of_books + x));
        }
    }

    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (*(total_number_of_pages + i)) {
            free(*(total_number_of_pages + i));
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
    
    return 0;
}