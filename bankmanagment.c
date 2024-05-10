#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 100

// Function prototypes
void addAccount(int accountNumbers[], char names[][50], double balances[], int *numAccounts);
void displayAccounts(int accountNumbers[], char names[][50], double balances[], int numAccounts);
void updateBalance(int accountNumbers[], double balances[], int numAccounts);

int main() {
    int accnum[MAX_ACCOUNTS];
    char names[MAX_ACCOUNTS][50];
    double balances[MAX_ACCOUNTS];
    int numAccounts = 0;
    int choice;

    while (1) {
        printf("\n1. Add account\n2. Display accounts\n3. Update balance\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount(accnum, names, balances, &numAccounts);
                break;
            case 2:
                displayAccounts(accnum, names, balances, numAccounts);
                break;
            case 3:
                updateBalance(accnum, balances, numAccounts);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// add a new account
void addAccount(int accountNumbers[], char names[][50], double balances[], int *numAccounts) {
    if (*numAccounts < MAX_ACCOUNTS) {
        printf("Enter account number: ");
        scanf("%d", &accountNumbers[*numAccounts]);

        printf("Enter name: ");
        scanf("%s", names[*numAccounts]);

        printf("Enter initial balance: ");
        scanf("%lf", &balances[*numAccounts]);

        (*numAccounts)++;
    } else {
        printf("Maximum number of accounts reached.\n");
    }
}

// Function to display account details
void displayAccounts(int accountNumbers[], char names[][50], double balances[], int numAccounts) {
    for (int i = 0; i < numAccounts; i++) {
        printf("\nAccount %d\n", accountNumbers[i]);
        printf("Name: %s\n", names[i]);
        printf("Balance: %.2lf\n", balances[i]);
    }
}

// Function to update account balance
void updateBalance(int accountNumbers[], double balances[], int numAccounts) {
    int accountNumber;
    double newBalance;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numAccounts; i++) {
        if (accountNumbers[i] == accountNumber) {
            printf("Enter new balance: ");
            scanf("%lf", &newBalance);

            balances[i] = newBalance;
            break;
        }
    }
}
