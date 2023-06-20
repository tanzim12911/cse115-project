/*
 * Name: Jawadul Karim Tanzim
 * ID: 2311730042
 * Section: 03
 * CSE115 Project
 */
#include <stdio.h>
#include "login.h"
#include "menu.h"
#include "splash.h"

int main(void)
{
    splash();

    if(login() == 1)
    {
        sleep(2);
        system("cls");
        menu();
    }

    return 0;
}
