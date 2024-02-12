#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ratings.h"

extern int moviedatabase();

int ratemovie(){
    char* user= (char*)malloc(20*sizeof(char));
    if(user==NULL){
        printf("Memory allocation failed :/");
        return EXIT_FAILURE;
    }
    printf("Enter your username:");
    scanf("%19s",user);//Restrict input to 19 characters
    char *username= realloc(user, strlen(user)+1);//Add 1 to the length for terminating character
    if(username==NULL){
        printf("Memory reallocation failed :/");
        free(user);
        return EXIT_FAILURE;
    }else{
        user=username;
    }
    FILE *file;
    file= fopen("user_data.txt","r");
    if(file==NULL){
        return EXIT_FAILURE;
    }
    char *userfile= (char*)malloc(20*sizeof (char));
    if(userfile==NULL){
        return 1;
    }
    int validate = 0;
    int userCount= 0;
    while(fgets(userfile,100,file)!=NULL) {
        userCount++;
        char *temp = realloc(userfile, strlen(userfile) + 1);
        if (temp == NULL) {
            printf("Memory reallocation failed.");
            free(userfile);
            return EXIT_FAILURE;
        } else {
            userfile = temp;
        }
        //If username has a new line at the end, remove it
        if(userfile[strlen(userfile)-1]=='\n'){
            userfile[strlen(userfile)-1]='\0';
        }
        //Takes only the username to compare it with the input
        char *token = strtok(userfile, " ");
        if (token != NULL && strcasecmp(token, user) == 0) {
            validate=0;
            break;
        } else {
             validate = 1;
        }
    }
    printf("%d",userCount);
    fclose(file);
    free(userfile);//Free memory allocated to the usernames in the file

    if (validate == 1) {
            printf("User not found. Please register first.\n");
        } else {
            int movienumber;
            int rating;
            printf("***** Movie Database *****\n");
            moviedatabase();
            printf("Enter the number of the movie you want to rate:");
            scanf("%d", &movienumber);
            while (movienumber > 10 || movienumber < 1) {
                printf("Invalid movie number. Please enter a number between 1 and 10.\n");
                printf("Enter the number of the movie you want to rate:");
                scanf("%d", &movienumber);
            }
            printf("Enter your rating(1-5):");
            scanf("%d", &rating);
            while(rating > 5 || rating < 1) {
                printf("Invalid rating.Please enter a rating between 1 and 5.\n");
                printf("Enter your rating(1-5):");
                scanf("%d", &rating);
            }
            printf("Rating recorded successfully.\n");
            FILE *userFile;
            userFile = fopen("user_ratings.txt","a");//Open file to write new ratings without overwriting the existing content of the file
            struct RatingMatrix matrix;
            matrix.numofusers=userCount;
            matrix.numofmovies=10;
            float ratings[matrix.numofusers][matrix.numofmovies];
            fprintf(userFile,"%d",matrix.numofusers,matrix.numofmovies);
            free(username);
        }
        return 0;

}
