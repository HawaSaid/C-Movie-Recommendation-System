#include <stdio.h>
#include "user.c"
#include "movie.c"

int main(){
    int choice=0;

    do
    {
        printf("***** Movie Recommendation System *****\n");
        printf("1. Register User\n");
        printf("2. Display Movies\n");
        printf("3. Rate a movie\n");
        printf("4. Get Movie Recommendations\n");
        printf("0. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        if (choice ==  1)
        {
            userInput();
        }
        else if (choice == 2)
        {
           movie();
        }
        else if (choice == 3)
        {
        }
        else if (choice == 4)
        {
        }

    } while (choice != 0);
    if(choice==0){
        return 0;
    }
}
