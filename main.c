
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define max 3

// Parallel arrays
char Lname[max][30], Fname[max][30], Mname[max][30], Precint[max][30], Status[max][20], ID[max][20];
char Birthday[max][11]; // Format: YYYY-MM-DD
int Age[max];
int count = 0; // total number of voters added

void addVoter();                  // function prototype
void showVoterByStatus(char[]);   // show voters by status
int calculateAge(int year, int month, int day); // helper function

int main() {
    srand(time(NULL)); // Seed once

    int choose;
    do {
        printf("\nVoter Management System:\n");
        printf("1. Add voter\n");
        printf("2. Show Minors\n");
        printf("3. Show Registered\n");
        printf("4. Show Non-Voters\n");
        printf("5. Exit\n");
        printf("Choose: ");
        scanf("%d", &choose);
        while (getchar() != '\n'); // clear input buffer

        switch (choose) {
            case 1:
                if (count < max)
                    addVoter();
                else
                    printf("Maximum number of voters (%d) reached.\n", max);
                break;
            case 2:
                showVoterByStatus("MINOR");
                break;
            case 3:
                showVoterByStatus("REGISTERED");
                break;
            case 4:
                showVoterByStatus("NON-VOTER");
                break;
            case 5:
                printf("Program end.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choose != 5);

    return 0;
}

void addVoter() {
    int year, month, day;

    int number = (rand() % 90000000) + 10000000; // 8-digit ID
    sprintf(ID[count], "%d", number);

    printf("\nVoter Identification Number: %s\n", ID[count]);

    printf("Last Name: ");
    fgets(Lname[count], sizeof(Lname[count]), stdin);
    Lname[count][strcspn(Lname[count], "\n")] = '\0';
    for (int i = 0; Lname[count][i]; i++)
        Lname[count][i] = toupper(Lname[count][i]);

    printf("First Name: ");
    fgets(Fname[count], sizeof(Fname[count]), stdin);
    Fname[count][strcspn(Fname[count], "\n")] = '\0';
    for (int i = 0; Fname[count][i]; i++)
        Fname[count][i] = toupper(Fname[count][i]);

    printf("Middle Name: ");
    fgets(Mname[count], sizeof(Mname[count]), stdin);
    Mname[count][strcspn(Mname[count], "\n")] = '\0';
    for (int i = 0; Mname[count][i]; i++)
        Mname[count][i] = toupper(Mname[count][i]);

    // Birthday input and validation
    do {
        printf("Enter Birthdate (YYYY-MM-DD): ");
        scanf("%d-%d-%d", &year, &month, &day);
        while (getchar() != '\n'); // clear buffer
        Age[count] = calculateAge(year, month, day);
        if (Age[count] < 15)
            printf("Error: Age must be 15 or older. Current calculated age: %d\n", Age[count]);
    } while (Age[count] < 15);

    // Save birthday string
    sprintf(Birthday[count], "%04d-%02d-%02d", year, month, day);

    printf("Precinct: ");
    fgets(Precint[count], sizeof(Precint[count]), stdin);
    Precint[count][strcspn(Precint[count], "\n")] = '\0';
    for (int i = 0; Precint[count][i]; i++)
        Precint[count][i] = toupper(Precint[count][i]);

    // Voter status assignment
    if (Age[count] < 18) {
        strcpy(Status[count], "MINOR");
    } else {
        int choice;
        printf("Choose voter status:\n");
        printf("1. Registered\n");
        printf("2. Non-voter\n");
        printf("Choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');
        switch (choice) {
            case 1:
                strcpy(Status[count], "REGISTERED");
                break;
            case 2:
                strcpy(Status[count], "NON-VOTER");
                break;
            default:
                strcpy(Status[count], "UNKNOWN");
        }
    }

    // Show confirmation
    printf("\nVoter successfully added:\n");
    printf("ID: %s\n", ID[count]);
    printf("Full Name: %s %s %s\n", Lname[count], Fname[count], Mname[count]);
    printf("Birthdate: %s \n", Birthday[count]);
    printf ("Age: %d y/o\n", Age[count]);
    printf("Precinct: %s\n", Precint[count]);
    printf("Status: %s\n", Status[count]);

    count++; // Increase voter count
}

void showVoterByStatus(char filter[]) {
    int found = 0;
    printf("\n--- Showing voters with status: %s ---\n", filter);
    for (int i = 0; i < count; i++) {
        if (strcmp(Status[i], filter) == 0) {
            printf("ID: %s\n", ID[i]);
            printf("Full Name: %s %s %s\n", Lname[i], Fname[i], Mname[i]);
            printf("Birthdate: %s (Age: %d)\n", Birthday[i], Age[i]);
            printf("Precinct: %s\n", Precint[i]);
            printf("Status: %s\n\n", Status[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No voters found with status: %s\n", filter);
    }
}

// Helper function to calculate age from birthdate
int calculateAge(int year, int month, int day) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    int age = t->tm_year + 1900 - year;

    if (t->tm_mon + 1 < month || (t->tm_mon + 1 == month && t->tm_mday < day)) {
        age--; // Birthday hasn't occurred yet this year
    }

    return age;
}
