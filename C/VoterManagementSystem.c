#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

addVoter ();
int main {
    addVoter();
    return 0;
}

void addVoter(){
    int voters_number = 0;
    char str[20]; //location for int to str
     srand (time(NULL));
     printf("Voters Identification Number: ");

        int number = (rand () % 90000000) +10000000; // for 8 digits number
        sprintf(str, "%d",number); // convert int to string
        printf ("%s",str);
     printf("\n");
        
    char Lname[30] = "";
    char Fname[30] = "";
    char Mname[30] ="";
    char Precint[30] = "";
    int age = 0;
    char Status[30];
    int choice = 0;

       printf ("Last Name: ");
       fgets(Lname , sizeof(Lname), stdin);
       Lname[strlen(Lname) -1] = '\0'; //remove new line
       for (int i =0; Lname[i];i++){
        Lname[i] = toupper(Lname[i]); // loop for uppercase
       }

       printf ("First Name: ");
       fgets(Fname , sizeof(Fname), stdin);
       Fname[strlen(Fname) -1] = '\0';
       for (int i =0; Fname[i];i++){
        Fname[i] = toupper(Fname[i]); // loop for uppercase
       }

       printf ("Middle Name: ");
       fgets(Mname , sizeof(Mname), stdin);
       Mname[strlen(Mname) -1] = '\0';
       for (int i =0; Mname[i];i++){
        Mname[i] = toupper(Mname[i]); // loop for uppercase
       }

       printf("Age: ");
       scanf("%d", &age);
       while (getchar ()!= '\n'); // clear input buffer

       printf ("Precint:");
       fgets(Precint , sizeof(Precint), stdin);
       Precint[strlen (Precint) -1] = '\0';
       for (int i =0; Precint[i];i++){
        Precint[i] = toupper(Precint[i]); // loop for uppercase
       }
       if (age < 18){
        strcpy(Status, " Minor");
       }else{
        printf("Choose voter status:\n");
        printf("1.Registered\n");
        printf("2.Non voter\n");
        printf ("Choice: ");
        scanf("%d", &choice);
        while (getchar ()!= '\n'); // clear input buffer
       
     /*  switch (choice){
        case 1: 
        strcpy(Status, " REGISTERED");
        break;
       
       case 2: 
        strcpy(Status, "NON-VOTER");
        break;
       }*/
    }
       printf ("\n");
       printf("Voters Identification Number:%s \n",str);
        printf("Voters Fullname:%s %s %s \n", Lname,Fname, Mname);
        printf("Age: %d\n", age);
        printf("Precint: %s\n", Precint);
         printf("Status: %s", Status);

        printf ("\n");
        int main(){
int choose;
do{
    printf("\nVoter management System:\n");
    printf("1. Add voter\n");
    printf("2. Show Minors:");
    printf("3. Show Registered:");
    printf("4. Show Non-Voters:");
    printf("5. Exit");
    printf("Choose:");
    scanf("%d",&choose);
    get(); //clear new line
    
    switch(choose){
        case 1:
        addVoter(); // addVoter Function
        break;
         case 2:
        Status("MINOR"); // addVoter Function
        break;
        case 3:
        Status("REGISTERED"); // addVoter Function
        break;
        case 4:
        Status("Non-Voter"); // addVoter Function
        break;
        case 5:
        printf("program end"); // addVoter Function
    }

    }
    while (choose !=5);

    return 0 ;
}


 return 0;
}