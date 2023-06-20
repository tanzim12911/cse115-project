#include<dos.h>

void splash(void)
{
    printf(" _                  _____              \n");
    printf("| |                (____ \\             \n");
    printf("| |      ____ ____  _   \\ \\ ____ ____  \n");
    printf("| |     / _  )  _ \\| |   | / _  )  _ \\ \n");
    printf("| |____( (/ /| | | | |__/ ( (/ /| | | |\n");
    printf("|_______)____)_| |_|_____/ \\____)_| |_|\n");
    printf("\n	 a Shield Inc. Company\n");

    sleep(5);
    system("cls");
}

void splash_login(void)
{
    printf("**************************************\n");
    printf("***  Login to your LenDen Account  ***\n");
    printf("**************************************\n");
}
