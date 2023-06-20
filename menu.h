/*
 * Menu Header File
 * Contains a function called menu() that
 * prompts the user to choose their desired operation.
 */

#define CASHOUT_CRG 0.0185
#define NUM_SIZE 14

void menu()
{
    int n;

    printf("LenDen\n");

    printf("1.Check Balance\n");
    printf("2.Send Money\n");
    printf("3.Mobile Recharge\n");
    printf("4.Cash Out\n");
    printf("5.Transaction History\n");
    printf("6.Exit\n");

    do{
        printf("\nChoose an option : ");
        scanf("%d", &n);

        if(n == 1)
        {
            double balance;
            FILE *balanceFile = fopen("balance.txt", "r");
            fscanf(balanceFile, "%lf", &balance);
            printf("\nYour Current Balance: BDT %.2f\n", balance);
            fclose(balanceFile);
        }

        if(n == 2)
        {
            double send_amount;
            char ac_no_r[NUM_SIZE];

            printf("\nEnter Receiver Account No: ");
            scanf("%s", ac_no_r);
            printf("Enter the Amount: ");
            scanf("%lf", &send_amount);

            update_balance(send_amount);

            // save transaction details
            FILE *tranj = fopen("transaction.txt", "a");
            fprintf(tranj, "BDT %.2f Send Money to %s \n", send_amount, ac_no_r);
            fclose(tranj);

            system("start 1_splash_send-money.png");   //integration of confirmation image
        }

        if(n == 3)
        {
            double recharge_amount;
            char mob_num[NUM_SIZE];

            printf("\nEnter Mobile Number: ");
            scanf("%s", mob_num);

            printf("Enter Recharge Amount: ");
            scanf("%lf", &recharge_amount);

            update_balance(recharge_amount);

            // save transaction details
            FILE *tranj = fopen("transaction.txt", "a");
            fprintf(tranj, "BDT %.2f Recharge to   %s \n", recharge_amount, mob_num);
            fclose(tranj);

            system("start 2_splash_recharge.png");  //integration of confirmation image
        }

        if(n == 4)
        {
            double cashout_amount, charge;
            char agent_num[NUM_SIZE];

            printf("\nEnter Agent Number: ");
            scanf("%s", agent_num);

            printf("Enter Cash Out Amount: ");
            scanf("%lf", &cashout_amount);

            charge = cashout_amount * CASHOUT_CRG;

            printf("Cash Out Charge: BDT %.2f\n", charge);

            cashout_amount += charge;

            update_balance(cashout_amount);

            // save transaction details
            FILE *tranj = fopen("transaction.txt", "a");
            fprintf(tranj, "BDT %.2f Cash Out from %s \n", cashout_amount, agent_num);
            fclose(tranj);

            system("start 3_splash_cashout.png");   //integration of confirmation image
        }

        if(n == 5)
        {
            printf("\nTransaction History:\n");

            FILE *file = fopen("transaction.txt", "r");

            if (file == NULL)
            {
                printf("Unable to open the file.\n");
                return 1;
            }

            char line[100];

            while (fgets(line, sizeof(line), file) != NULL)
            {
                printf("%s", line);
            }

            fclose(file);

        }

        else if (n == 6)
            printf("\nExiting the program.\n");

    }while(n != 6);


}

void update_balance(double amount)
{
    // subtract amount from balance
    FILE *balanceFile = fopen("balance.txt", "r");
    double balance;
    fscanf(balanceFile, "%lf", &balance);
    fclose(balanceFile);

    balance -= amount;

    // update new balance
    balanceFile = fopen("balance.txt", "w");
    fprintf(balanceFile, "%.2f", balance);
    fclose(balanceFile);
}

