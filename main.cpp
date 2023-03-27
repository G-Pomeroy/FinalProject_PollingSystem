#include <iostream>
#include <cstring>


#define candidate1 "Jim Briar"
#define candidate2 "Poppy Brande"
#define candidate3 "Mike Brown"

struct account {
    char name[20];
    char pass[20];
};

int flag, usernameCheck, passwordCheck, vote1, vote2, vote3;
bool voteFlag = false;
char usernameAdmin[]="admin", pswrdAdmin[]="1234", nameUser[]="user", pswrdUser[]="1234";
char username[20], password[20];

void adminLogIn(){

    int fileExists;

    printf("\n\n---Admin Selected---\n\n");

    while(true) {

        //Working on comparing user input and text file for password and username input
        FILE *fp;
        fp = fopen("admin_list.txt", "r");
        if(!fp) {
            perror("admin_list.txt");
            printf("File not found. Creating file...\n\n");
        } else {
            fileExists = 1;
        }

        printf("Please enter username and password: \n");

        printf("Username:");
        scanf(" %s", username);
        fflush(stdout);

        printf("Password:");
        scanf(" %s", password);
        fflush(stdout);

//        if(fileExists) {
//            while (fread(fp, " %s") != EOF) {
//                if(!strcmp(, artist)) {
//                    found = 1;
//                    break;
//                }
//
//            }
//        }



        usernameCheck = strcmp(username, usernameAdmin);
        passwordCheck = strcmp(password, pswrdAdmin);

        if (usernameCheck != 0 || passwordCheck != 0) {
            printf("Incorrect username or password. Please try again.\n\n");
        } else {
            printf("Welcome Polling Officer\n\n");
            break;
        }
    }

}

void userLogIn(){

    printf("\n--User Selected--\n");

    while(true) {
        printf("Please enter username and password: \n");

        printf("Username:");
        scanf(" %s", username);
        fflush(stdout);

        printf("Password:");
        scanf(" %s", password);
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
    fgets(newInput.name, 20, stdin);
    fputs("\n",fpWrite);

    printf("Please enter a new password (Max. 20 Characters): \n");
    scanf(" %s", newInput.pass);
    fgets(newInput.pass, 20, stdin);
    fputs("\n",fpWrite);


    fclose(fpWrite);
    printf("\n\nNew User account entered successfully\n\n");
}

void newAdmin(){

    FILE *fpWrite;

    printf("---Add a new User Account---\n\n");

    //Add new user without overwriting any existing information
    fpWrite = fopen("admin_list.txt", "a");
    if(fpWrite){
        printf("Existing file not found. Creating file...\n\n");
    }

    struct account newInput{};

    printf("Please enter a new username (Max. 20 Characters): \n");
    scanf(" %s", newInput.name);
    fgets(newInput.name, 20, stdin);
    fputs("\n",fpWrite);

    printf("Please enter a new password (Max. 20 Characters): \n");
    scanf(" %s", newInput.pass);
    fgets(newInput.pass, 20, stdin);
    fputs("\n",fpWrite);


    fclose(fpWrite);
    printf("\n\nNew User account entered successfully\n\n");
}

void userFunc(){

    int input;

    while(true) {
        printf("Please select a function (1-4):\n");
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
