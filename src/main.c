#include <stdio.h>
#include "user.c"
#include "ratemovie.c"
#include "recommendation.c"

int moviedatabase(){
    FILE *movie;
    movie = fopen("movie_database.txt", "r");
    if (movie == NULL) {
        return 1;
    }
    int i = 1;
    char movie1[100];
    while (fgets(movie1, sizeof(movie1), movie) != NULL) {
        printf("%d. %s", i, movie1);
        i++;
    }
    fclose(movie);
    return 0;
}
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
           moviedatabase();
        }
        else if (choice == 3)
        {
            ratemovie();
        }
        else if (choice == 4)
        {
            movierec();
        }

    } while (choice != 0);
    if(choice==0){
        return 0;
    }
}
