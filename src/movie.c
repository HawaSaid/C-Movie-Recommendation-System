#include <stdio.h>

int movie() {
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
}