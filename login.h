/*
 * Login Header File
 * Contains a function called login() that prompts the user to input
 * their login credentials and verify them in order to approve login attempt.
 */

struct login_info {
    char ac_no[11];
    char pin[6];
};

int login(void)
{
    struct login_info credentials;
    struct login_info stored_credentials;

    FILE *inp = fopen("credentials.txt", "r");

    fscanf(inp, "%s %s", stored_credentials.ac_no, stored_credentials.pin);

    fclose(inp);

    splash_login();

    printf("\nAccount Number: ");
    scanf("%s", credentials.ac_no);
    printf("PIN: ");
    scanf("%s", credentials.pin);

    if (strcmp(credentials.ac_no, stored_credentials.ac_no) == 0 && strcmp(credentials.pin, stored_credentials.pin) == 0)   // credentials verification

    {
        printf("\n**************************\n");
        printf("***  Login Successful  ***\n");
        printf("**************************\n");
        return 1;
    }
    else
    {
        printf("\n******************************************\n");
        printf("***   Incorrect Account Number or PIN  ***\n");
        printf("******************************************\n");

        sleep(2);
        system("cls");
        login();    // recursive call to login()
    }
}

