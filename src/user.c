#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

int userInput() {
    char username[20];
    printf("Enter username for registration:");
    scanf("%s", &username);
    FILE *user_data;
    user_data = fopen("user_data.txt", "r");// Open & Read the user_data txt file

    if (user_data == NULL) {//If content of txt file empty, program is terminated unsuccessfully
        return EXIT_FAILURE;
    }
    char *fileuser=NULL;
    char user[20];
    //malloc, realloc & free to use
    while (fgets(user, sizeof(user), user_data) != NULL) {
        char *temp= realloc(fileuser,sizeof(user)+1);
        if(strcasecmp(username,user)==0){
            printf("User already exists. Please choose a different name.");
            printf("Enter username for registration:");
            scanf("%s", &username);
            free(fileuser);
        }else{

        }


    }
}
