#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int userInput() {
    char *username=(char*)malloc(20*sizeof (char));// Allocate memory for 20 characters
    if(username==NULL){
        printf("Memory allocation failed. ");
        return EXIT_FAILURE;
    }
    printf("Enter username for registration:");
    scanf("%19s", username);// Restrict input to 19 characters
    char *username1= realloc(username,strlen(username)+1);//Reallocate the memory to match the length of the string the user input
    if(username1==NULL){
        printf("Memory reallocation failed. ");
        free(username);
        return EXIT_FAILURE;
    }else {
        username = username1;//Pointer updated after reallocating memory
    }
    FILE *user_data;
    user_data = fopen("user_data.txt", "r");// Open & Read the user_data txt file
    if (user_data == NULL) {//If content of txt file empty, program is terminated unsuccessfully
        return EXIT_FAILURE;
    }
    char *user= malloc(20 * sizeof(char));//Allocates memory for 20 characters
    if(user==NULL){
        printf("Memory allocation failed.");
        return EXIT_FAILURE;
    }
    while (fgets(user, 20, user_data) != NULL) {//Checks if line being read in the txt file is not NULL
        char *temp= realloc(user, strlen(user) + 1);
        if(temp==NULL){
            printf("Memory reallocation failed.");
            free(user);
            return EXIT_FAILURE;
        }else{
            user=temp;
        }
        char *token = strtok(user," ");
        if (token !=NULL && strcasecmp(username, token) == 0) {
            printf("User already exists. Please choose a different name\n");
            printf("Enter username for registration:");
            scanf("%19s", username);
            fseek(user_data, 0, SEEK_SET);
        }
    }
    free(user);
    fclose(user_data);
    printf("User %s is successfully registered\n", username);
    user_data = fopen("user_data.txt", "a");
    if(user_data==NULL){
        return EXIT_FAILURE;
    }
    fprintf(user_data, "%s\n", username);
    fclose(user_data);
    free(username);
    return 0;
}
