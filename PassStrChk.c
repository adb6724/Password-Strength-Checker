#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LENGTH 256 // define max length

// function prototypes
void seePass(char *password, int maxPassLength, int minPasswordLength, bool allowPassPhrases, int minPhraseLength, int *passOpTest, int *failedReqTests, int *passedReqTests, bool *usePassPhr, bool *checkStrong, bool needOpTest);
void goPass(char *password, int maxPassLength, int minPasswordLength, bool allowPassPhrases, int minPhraseLength, bool needOpTest);

int isSpace(char c) { // see if char is a space
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

char* trimSpaces(char* str) { // trims the spaces 
    char* end;

    while (isSpace(*str)) str++;

    if (*str == 0) { // return empty string if spaces
        return str;
    }

    end = str + strlen(str) - 1; // cuts the trailing spaces
    while (end > str && isSpace(*end)) end--;

    *(end + 1) = 0; 

    return str;
}

int main() { // int main
    FILE *file;
    char password[MAX_LENGTH];
    int maxPassLength, minPasswordLength, checkPassPhr, minPhraseLength, checkOpTest, numOptionalTests;

    for (int i = 1; i <= 3; i++) { // read the password files
        char filename[30];
        sprintf(filename, "Proposed passwords #%d.txt", i);
        file = fopen(filename, "r");

        if (file == NULL) {
            printf("Could not open file %s\n", filename);
            return 1;
        }

        fscanf(file, "%d", &maxPassLength); // read config from file
        fscanf(file, "%d", &minPasswordLength);
        fscanf(file, "%d", &checkPassPhr);
        if (checkPassPhr) {
            fscanf(file, "%d", &minPhraseLength);
        }
        fscanf(file, "%d", &checkOpTest);
        if (checkOpTest) {
            fscanf(file, "%d", &numOptionalTests);
        }

        printf("Processing %s\n\n", filename); // print the config settings
        printf("Maximum password length: %d\n", maxPassLength);
        printf("Minimum password length: %d\n", minPasswordLength);
        printf("Pass phrases are %s", checkPassPhr ? "allowed" : "NOT allowed");
        
        if (checkPassPhr) {
            printf(" (Minimum passphrase length: %d)", minPhraseLength);
        }

        printf("\nOptional Tests are %s", checkOpTest ? "allowed" : "NOT allowed");
        
        if (checkOpTest) {
            printf(" (Minimum optional tests to pass: %d)", numOptionalTests);
        }
        printf("\n\n\n");

        while (fgets(password, sizeof(password), file)) { // read each password
            char *trimmedPassword = trimSpaces(password); // trim lines and spaces

            if (strlen(trimmedPassword) == 0) { // skip empty lines
                continue; // skip if the password is empty
            }

            goPass(trimmedPassword, maxPassLength, minPasswordLength, checkPassPhr, minPhraseLength, checkOpTest);
        }

        fclose(file);
    }

    return 0;
}

void goPass(char *password, int maxPassLength, int minPasswordLength, bool allowPassPhrases, int minPhraseLength, bool needOpTest) {
    bool usePassPhr = false; // start without phrase
    bool checkStrong = true; // start with strong belief
    int passOpTest = 0; 
    int failedReqTests = 0, Req = 0;

    if (strlen(password) != 0) { // print the password if not blank line
        printf("Potential password: %s\n", password);
    }

    seePass(password, maxPassLength, minPasswordLength, allowPassPhrases, minPhraseLength, &passOpTest, &failedReqTests, &Req, &usePassPhr, &checkStrong, needOpTest);

    printf("Failed Required Tests: %d\n", failedReqTests);
    printf("Passed Required Tests: %d\n", Req);
    printf("Is a Pass phrase: %s\n", usePassPhr ? "true" : "false");
    printf("Strong? : %s\n", checkStrong ? "true" : "false");
    
    if (needOpTest) { // print total optional tests passed
        printf("Total optional tests passed: %d\n\n", passOpTest);
    } else {
        printf("\n");
    }
}

void seePass(char *password, int maxPassLength, int minPasswordLength, bool allowPassPhrases, int minPhraseLength, int *passOpTest, int *failedReqTests, int *Req, bool *usePassPhr, bool *checkStrong, bool needOpTest) {
    int length = strlen(password);
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false, hasRepeat = false;
    int digitCount = 0, specialCount = 0;

    *usePassPhr = (strchr(password, ' ') != NULL); // check if passphrase

    if (length < minPasswordLength) { // check for minimum length requirement
        printf("The password must be at least %d characters long.\n", minPasswordLength);
        (*failedReqTests)++;
        *checkStrong = false; // checkStrong thru pointer
    } else {
        (*Req)++;
    }

    if (length > maxPassLength) { // check for maximum length requirement
        printf("The password must be fewer than %d characters.\n", maxPassLength);
        (*failedReqTests)++;
        *checkStrong = false;
    } else {
        (*Req)++;
    }

    for (int i = 0; i < length; i++) { // check for repeated characters
        if (i >= 2 && password[i] == password[i - 1] && password[i] == password[i - 2]) {
            hasRepeat = true;
            break;
        }
    }

    if (hasRepeat) {
        printf("The password may not contain sequences of three or more repeated characters.\n");
        (*failedReqTests)++;
        *checkStrong = false;
    } else {
        (*Req)++;
    }

    for (int i = 0; i < length; i++) { // run rules through passwords
        char ch = password[i];
        if (ch >= 'a' && ch <= 'z') {
            hasLower = true;
        } else if (ch >= 'A' && ch <= 'Z') {
            hasUpper = true;
        } else if (ch >= '0' && ch <= '9') {
            hasDigit = true;
            digitCount++;
        } else {
            hasSpecial = true;
            specialCount++;
        }
    }

    if (!(hasLower || hasUpper) || !hasDigit || !hasSpecial) { // check if password has letters, numbers, and symbols
        printf("The password must contain letters, numbers, AND symbols.\n");
        (*failedReqTests)++;
        *checkStrong = false;
    } else {
        (*Req)++;
    }

    if (needOpTest) { // optional tests
        if (hasLower) {
            (*passOpTest)++;
        } else {
            printf("The password must contain at least one lowercase letter.\n");
        }

        if (hasUpper) {
            (*passOpTest)++;
        } else {
            printf("The password must contain at least one uppercase letter.\n");
        }

        if (digitCount >= 2) {
            (*passOpTest)++;
        } else {
            printf("The password must contain at least two digits.\n");
        }

        if (specialCount >= 2) {
            (*passOpTest)++;
        } else {
            printf("The password must contain at least two special characters.\n");
        }
    }
}
