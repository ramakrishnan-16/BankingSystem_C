#include <stdio.h>
#include <stdlib.h>

// Structure to represent a bank account

struct BankAccount {
    int accountNumber;
    char name[50];
    float balance;
};

// Function to create bank account

void createAccount(struct BankAccount *accounts, int *numAccounts) {
    printf("Enter the account holder's name: ");
    scanf(" %s", accounts[*numAccounts].name);

    accounts[*numAccounts].accountNumber = *numAccounts + 1;
    accounts[*numAccounts].balance = 0.0;

    printf("Account created successfully. Account number: %d\n", accounts[*numAccounts].accountNumber);
    (*numAccounts)++;
}

// Function to deposit cash amount in bank account

void deposit(struct BankAccount *accounts, int numAccounts) {
    int accountNumber;
    float amount;
    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= numAccounts && accountNumber > 0) {
        printf("Enter the amount to deposit: $");
        scanf("%f", &amount);

        accounts[accountNumber - 1].balance += amount;
        printf("Deposit successful. New balance: $%.2f\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}

// Function to withdraw cash amount from bank account

void withdraw(struct BankAccount *accounts, int numAccounts) {
    int accountNumber;
    float amount;
    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= numAccounts && accountNumber > 0) {
        printf("Enter the amount to withdraw: $");
        scanf("%f", &amount);

        if (amount > accounts[accountNumber - 1].balance) {
            printf("Insufficient balance.\n");
        } else {
            accounts[accountNumber - 1].balance -= amount;
            printf("Withdrawal successful. New balance: $%.2f\n", accounts[accountNumber - 1].balance);
        }
    } else {
        printf("Invalid account number.\n");
    }
}

// Function to display the balance in bank account

void checkBalance(struct BankAccount *accounts, int numAccounts) {
    int accountNumber;
    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= numAccounts && accountNumber > 0) {
        printf("Account Holder: %s\n", accounts[accountNumber - 1].name);
        printf("Account Balance: $%.2f\n", accounts[accountNumber - 1].balance);
    } else {
        printf("Invalid account number.\n");
    }
}

int main() {
    struct BankAccount accounts[100];
    int numAccounts = 0;
    int choice;

    while (1) {
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numAccounts < 100) {
                    createAccount(accounts, &numAccounts);
                } else {
                    printf("Maximum account limit reached.\n");
                }
                break;
            case 2:
                deposit(accounts, numAccounts);
                break;
            case 3:
                withdraw(accounts, numAccounts);
                break;
            case 4:
                checkBalance(accounts, numAccounts);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

