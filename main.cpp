#include <iostream>
#include <string.h>
#include <stdlib.h>

#define candidate1 "Jim Briar"
#define candidate2 "Poppy Seede"
#define candidate3 "Mike Brown"

typedef struct account {
    char name[20];
    char pass[20];
} account;

int flag, usernameCheck, passwordCheck, vote1, vote2, vote3;
bool voteFlag = false;
char usernameAdmin[]="admin", pswrdAdmin[]="1234", nameUser[]="user", pswrdUser[]="9876";
char username[20], password[10];

void adminLogIn(){

    printf("Admin Selected\n");

    while(true) {
        printf("Please enter username and password: \n");

        scanf("%s", username);
        fflush(stdout);
        scanf("%s", password);
        fflush(stdout);

        usernameCheck = strcmp(username, usernameAdmin);
        passwordCheck = strcmp(password, pswrdAdmin);

        if (usernameCheck != 0 || passwordCheck != 0) {
            printf("Incorrect username or password. Please try again.\n");
        } else {
            printf("Welcome Polling Officer\n");
            break;
        }
    }

}

void userLogIn(){

    printf("User Selected\n");

    while(true) {
        printf("Please enter username and password: \n");

        scanf("%s", username);
        fflush(stdout);
        scanf("%s", password);
        fflush(stdout);

        usernameCheck = strcmp(username, nameUser);
        passwordCheck = strcmp(password, pswrdUser);

        if (usernameCheck != 0 || passwordCheck != 0) {
            printf("Incorrect username or password. Please try again.\n");
        } else {
            printf("Welcome User\n");
            voteFlag = true;
            break;
        }
    }
}

void voteCount(){

    printf("---Total Vote Count Per Candidate---\n\n");
    printf("1. %s - %d\n", candidate1, vote1);
    printf("2. %s - %d\n", candidate2, vote2);
    printf("3. %s - %d\n\n", candidate3, vote3);

    if(vote1 > vote2 && vote1 > vote3){
        printf("%s has won the election.\n", candidate1);
    } else if (vote2 > vote1 && vote2 > vote3){
        printf("%s has won the election.\n", candidate2);
    } else if (vote3 > vote1 && vote3 > vote2){
        printf("%s has won the election.\n", candidate3);
    } else {
        printf("There is no winner currently\n");
    }

}

void candidateVote(){

    if(voteFlag = true){
        printf("---Please select a candidate to vote for:--- \n");
        printf("1. %s\n", candidate1);
        printf("2. %s\n", candidate2);
        printf("3. %s\n", candidate3);

        printf("Please enter your choice (1 - 3):\n");
        scanf("%d", &flag);

        switch(flag){
            case 1:
                vote1++;
                break;
            case 2:
                vote2++;
                break;
            case 3:
                vote3++;
                break;
            default:
                printf("Invalid input");
        }
        voteFlag = false;
    } else if(voteFlag = false){
        printf("You have already voted for a candidate. If this is incorrect, please contact an Polling Officer.");
    }


}

void exitProgram(){

    char input;

    printf("Would you like to exit the Polling Program?\n");
    printf("Y / N?\n");
    scanf(" %c", &input);

    if(input == 'y' || input == 'Y'){
        printf("Exiting program...");
        exit(0);
    } else if (input == 'n' || input == 'N') {
        printf("Returning to main menu...\n\n");
    }

}

void newUser(){

    account a;
    FILE *fpwrite,*fpread;

    fpwrite = fopen("user_list.txt", "w");
    if(fpwrite == NULL){
        printf("File not found.");
    }

    printf("Please enter a new username: \n");
    gets(a.name);
    printf("Please enter a new password: \n");
    gets(a.pass);
    fflush(stdin);
    fwrite(&a, sizeof(a),1,fpwrite);
    fclose(fpwrite);
    printf("New user account entered successfully");

    fpread = fopen("user_list.txt", "r");
    while(fread(&a, sizeof(a),1,fpread) > 0)
        printf("%s %s", a.name, a.pass);
    fclose(fpread);
}

void newAdmin(){

    account a;
    FILE *fpwrite,*fpread;

    fpwrite = fopen("admin_list.txt", "w");
    if(fpwrite == NULL){
        printf("File not found.");
    }

    printf("Please enter a new username: \n");
    gets(a.name);
    printf("Please enter a new password: \n");
    gets(a.pass);
    fflush(stdin);
    fwrite(&a, sizeof(a),1,fpwrite);
    fclose(fpwrite);
    printf("New user account entered successfully");

    fpread = fopen("admin_list.txt", "r");
    while(fread(&a, sizeof(a),1,fpread) > 0)
        printf("%s %s", a.name, a.pass);
    fclose(fpread);
}

void changeInfo(){


}

void userFunc(){

    int input;

    while(true) {
        printf("Please select a function (1-4):\n");
        printf("1. Vote for a candidate\n");
        printf("2. Return to Main Menu\n");

        switch (input) {
            case 1:
                candidateVote();
                break;
            case 2:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

void adminFunc(){

    int input;

    while(true) {
        printf("Please select a function (1-4):\n");
        printf("1. Perform vote count and declare winner of election\n");
        printf("2. Register New User\n");
        printf("3. Register New Admin\n");
        printf("4. Fix username and/or password\n");
        printf("5. Return to Main Menu\n");

        switch (input) {
            case 1:
                voteCount();
                break;
            case 2:
                newUser();
                break;
            case 3:
                newAdmin();
                break;
            case 4:
                changeInfo();
                break;
            case 5:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}

int main() {


    while(true) {
        //User and Admin select loop
    printf("---Polling System---\n");
    printf("Main Menu:\n\n");
    printf("Please select a user type:\n");
    printf("Type 1 for Admin, Type 2 for User, Type 3 to Exit\n");
        scanf("%d", &flag);

        switch (flag) {
            //Access Admin functions
            case 1: adminLogIn();
                    adminFunc();
            break;

            //Access User Functions
            case 2: userLogIn();
                    userFunc();
            break;

            //Exit the program
            case 3: exitProgram();
            break;

            //default output
            default:
            printf("Invalid Input, please try again.\n");
            break;
        }
    }
    return 0;
}
