#include <iostream>
#include <cstring>
#include <stdio.h>


//Defining candidates to vote for
#define candidate1 "Jim Briar"
#define candidate2 "Poppy Brande"
#define candidate3 "Mike Brown"

//User and Admin accounts both added and accessed as a struct
struct account {
    char name[20];
    char pass[20];
};

//Declare variables
int flag, vote1, vote2, vote3;
bool voteFlag = false;
char username[20], password[20],passwordCheck[20], usernameCheck[20];

//Func to log in Admin
void adminLogIn() {

    bool admin = false;
    int tries = 0;

    printf("\n\n---Admin Selected---\n\n");


    FILE *fp;
    fp = fopen("admin_list.txt", "rb");
    if (!fp) {
        printf("File not found. Creating file...\n\n");
    }

    rewind(fp);
    printf("Please enter username and password: \n");

    printf("Username:");
    scanf("%s", username);

    printf("Password:");
    scanf("%s", password);


while(1){
    while (fscanf(fp, "%s %s", usernameCheck, passwordCheck) == 2) {
        if (strcmp(username, usernameCheck) == 0 && strcmp(password, passwordCheck) == 0) {
            printf("\nLogin successful!\n\n");
            admin = true;
            break;
        }
    }

    if (admin) {
        break;
    } else {
        printf("Incorrect values. Please try again.\n\n");
        tries++;

        if (tries > 2) {
            printf("Login unsuccessful!\n");
            break;
        }

        rewind(fp);                         /* Reset the file and try again */
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);
        }
    }
        fclose(fp);
}

//Func to Log in a registered user
void userLogIn(){

    bool admin = false;
    int tries = 0;

    printf("\n\n---User Selected---\n\n");


    FILE *fp;
    fp = fopen("user_list.txt", "rb");
    if (!fp) {
        printf("File not found. Creating file...\n\n");
    }

    rewind(fp);
    printf("Please enter username and password: \n");

    printf("Username:");
    scanf("%s", username);

    printf("Password:");
    scanf("%s", password);

    while(1){
        while (fscanf(fp, "%s %s", usernameCheck, passwordCheck) == 2) {
            if (strcmp(username, usernameCheck) == 0 && strcmp(password, passwordCheck) == 0) {
                printf("\nLogin successful!\n\n");
                admin = true;
                break;
            }
        }

        if (admin) {
            break;
        } else {
            printf("Incorrect values. Please try again.\n\n");
            tries++;

            if (tries > 2) {
                printf("Login unsuccessful!\n");
                break;
            }

            rewind(fp);                         /* Reset the file and try again */
            printf("Username: ");
            scanf("%s", username);
            printf("Password: ");
            scanf("%s", password);
        }
    }
    fclose(fp);
}

//Func for Admins to tally votes and declare winner
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

//Func to allow Users to vote
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

//Func to Exit program completely
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

//Func for Admin to create a new user
void newUser(){

    FILE *fpWrite;

    printf("---Add a new User Account---\n\n");

    //Add new user without overwriting any existing information
    fpWrite = fopen("user_list.txt", "a");
    if(fpWrite){
        printf("Existing file not found. Creating file...\n\n");
    }

    struct account newInput{};

    printf("Please enter a new username (Max. 20 Characters): \n");
    scanf(" %s", newInput.name);
    fprintf(fpWrite,newInput.name);
    fprintf(fpWrite,"\n");


    printf("Please enter a new password (Max. 20 Characters): \n");
    scanf(" %s", newInput.pass);
    fprintf(fpWrite,newInput.pass);
    fprintf(fpWrite,"\n");

    fclose(fpWrite);
    printf("\n\nNew User account entered successfully\n\n");
}

//Func to allow Admin to create a nee Admin
void newAdmin(){

    FILE *fpWrite;

    printf("---Add a new Admin Account---\n\n");

    //Add new user without overwriting any existing information
    fpWrite = fopen("admin_list.txt", "a");
    if(fpWrite){
        printf("Existing file not found. Creating file...\n\n");
    }

    struct account newInput{};

    printf("Please enter a new username (Max. 20 Characters): \n");
    scanf(" %s", newInput.name);
    fprintf(fpWrite,newInput.name);
    fprintf(fpWrite,"\n");


    printf("Please enter a new password (Max. 20 Characters): \n");
    scanf(" %s", newInput.pass);
    fprintf(fpWrite,newInput.pass);
    fprintf(fpWrite,"\n");

    fclose(fpWrite);
    printf("\n\nNew Admin account entered successfully\n\n");
}

//User menu to select functions
void userFunc(){

    int input;

    while(true) {
        printf("Please select a function:\n");
        printf("1. Vote for a candidate\n");
        printf("2. Return to Main Menu\n");

        scanf("%d", &input);

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
        break;
    }
}

//Admin menu to select functions
void adminFunc(){

    int input;

    while(true) {
        printf("Please select a function (1-4):\n");
        printf("1. Perform vote count and declare winner of election\n");
        printf("2. Register New User\n");
        printf("3. Register New Admin\n");
        printf("4. Return to Main Menu\n");

        scanf("%d", &input);

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
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;

        }
        break;
    }
}

int main() {


    while(true) {
        //User and Admin select loop
    printf("---Polling System---\n");
    printf("Main Menu:\n\n");
    printf("Please select a user type:\n");
    printf("1. Admin\n");
    printf("2. User\n");
    printf("3. Exit Program\n");

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
