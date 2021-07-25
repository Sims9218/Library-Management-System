#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library {
    char book_name[50];
    char author[50];
    int pages;
    float price;
};

int main()
{
    struct library lib[100];
    char s_bk[50], auth_name[50], x[50];
    int i, input, count, j;
  
    i = j = input = count = 0;		//i is tracking the index of books
  
    while (input != 6) {
        printf("\n1. Add a new book information");
        printf("\n2. Display the Complete list of the books");
        printf("\n3. Search a book");
        printf("\n4. Search a book by Author's' name");
        printf("\n5. Sort the list of books by name");
        printf("\n6. Exit");
  
        printf("\nEnter one of the above: ");
        scanf("%d", &input);
  
        switch(input){
        case 1:		//Add book information

			printf("Enter book name = ");
            scanf("%s", lib[i].book_name);
  
            printf("Enter author name = ");
            scanf("%s", lib[i].author);
  
            printf("Enter no. of pages = ");
            scanf("%d", &lib[i].pages);
  
            printf("Enter price = ");
            scanf("%f", &lib[i].price);
            count++;
            i++;
			break;
  
        case 2:		//Display Complete list of the books
            printf("\nThe following books have been stored: ");
            for (i=0; i < count; i++){
                printf("\nBook Name = %s", lib[i].book_name);
                
                printf("\nAuthor Name = %s", lib[i].author);
                
                printf("\nNumber of pages = %d", lib[i].pages);
                
                printf("\nPrice = Rs.%f", lib[i].price);
            }
            break;
  
        case 3:		//Search a book
            printf("Enter book to search: ");
            scanf("%s", s_bk);
            for (i = 0; i < count; i++){
                if (strcmp(s_bk, lib[i].book_name) == 0)
                    printf("The book %s written by %s has %d pages with a price of Rs.%f", lib[i].book_name, lib[i].author, lib[i].pages, lib[i].price);
            }
            break;
  
        case 4:		//Search book by Author name
            printf("\nEnter book to search by author name: ");
            scanf("%s", auth_name);
            for(i = 0; i < count; i++){
            	if(strcmp(auth_name, lib[i].author) == 0)
            		printf("Book %s is written by %s", lib[i].book_name, lib[i].author);
			}
            break;
            
        case 5:		//Sort list of books by name
        	for(i = 0; i < count; i++){
				for(j = i+1; j < count; j++){
					if(strcmp(lib[i].book_name, lib[j].book_name) > 0){
            			strcpy(x, lib[i].book_name);
            			strcpy(lib[i].book_name, lib[j].book_name);
            			strcpy(lib[j].book_name, x);
        			}
      			}
   			}
   			printf("\nBooks in the sorted order are: \n");
   			for(i = 0; i < count; i++){
      			printf("%s\n", lib[i].book_name);
   			}
        	
        case 6:		// Exit the loop
        	exit(0);
        }
    }
    return 0;
}
