#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int movierec() {
    char *user = (char *) malloc(20 * sizeof(char));
    if (user == NULL) {
        printf("Memory allocation failed :/");
        return EXIT_FAILURE;
    }
    printf("Enter your username:");
    scanf("%19s", user);//Restrict input to 19 characters
    char *username = realloc(user, strlen(user) + 1);//Add 1 to the length for terminating character
    if (username == NULL) {
        printf("Memory reallocation failed :/");
        free(user);
        return EXIT_FAILURE;
    } else {
        user = username;
    }
    FILE *file;
    file = fopen("user_data.txt", "r");
    char *userfile = (char *) malloc(20 * sizeof(char));
    if (file == NULL) {
        return EXIT_FAILURE;
    }
    int validate = 0;
    while (fgets(userfile, 20, file) != NULL) {
        char *temp = realloc(userfile, strlen(userfile) + 1);
        if (temp == NULL) {
            printf("Memory reallocation failed.");
            free(userfile);
            return EXIT_FAILURE;
        } else {
            userfile = temp;
        }
        //If username has a new line at the end, remove it
        if (userfile[strlen(userfile) - 1] == '\n') {
            userfile[strlen(userfile) - 1] = '\0';
        }
        //Takes only the username to compare it with the input
        char *token = strtok(userfile, " ");
        if (token != NULL && strcasecmp(token, user) == 0) {
            validate = 0;
            break;
        } else {
            validate = 1;
        }
    }
    free(userfile);
    if (validate == 1) {
        printf("User not found. Please register first.\n");
    } else {

    }
}