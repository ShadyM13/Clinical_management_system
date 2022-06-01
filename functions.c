#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_types.h"


#include "functions.h"

void Screeninit(void)
{
    printf(" ____________________ Clinical Management System ____________________");
}

int SelectMode()
{
    u8 L_choice;
    printf("1- Admin mode\n");
    printf("2- User mode\n");
    printf("3- Exit\n");
    printf("Your choice: ");
    scanf("%d",&L_choice);
    if(1 == L_choice)
    {
        check_admin();
        return 1;
    }
    else if(2 == L_choice)
    {
        UserMode();
    }
    else if (3 == L_choice)
    {
        Exit();
        return 0;
    }
    else
    {
        printf("Not valid entery\n");
        SelectMode();
        return 1;
    }

}

void check_admin(void)
{
    u8  i;
    u32 password;
    
    for(i=1; i<=3; i++)
    {
        if(3 == i)
        {
            printf ("Sorry you tried 3 times System is locked !!!!\n");
            return;
        }
        
        else
        {
            printf("Enter the password: ");
            scanf("%d",&password);

            if(1234 == password)
            {
                printf("__________________________________________Welcome in Admin mode__________________________________________________\n\n");
                //AdminChoices();
                return;
            }
            else if(i<3)
            {
                printf("wrong password, try again (%d trials left)",3-i);

            }
        }

    }

}
void AdminChoices(void)
{
    u8 admin_choice;
    while(admin_choice)
    {
        printf("1. Add new patient record. \n");
        printf("2. Edit patient record.\n");
        printf("3. Reserve a slot with the doctor.\n");
        printf("4. Cancel reservation.");

        scanf("%d",&admin_choice);

        if(1 == admin_choice)
        {
            //add_record();
        }
        else if(2 == admin_choice)
        {
            //edit_record();
        }
        else if(3 == admin_choice)
        {
            //PrintReservationtime();
            //ReservingTimeSlot();
        }
        else if(4 == admin_choice)
        {

        }
        else
        {

        }
    }
}
void UserMode(void)
{

}
void Exit(void)
{
    printf("Good bye! \n");
}