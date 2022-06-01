#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_types.h"


#include "functions.h"


void Screeninit(void)
{
    printf(" ____________________ Clinical Management System ____________________\n");
    printf("_____________________________SHADY AHMAD_____________________________\n");
}


int SelectMode()
{
    u8 lock;
    u8 L_choice;
    printf("1- Admin mode\n");
    printf("2- User mode\n");
    printf("3- Exit\n");
    printf("Your choice: ");
    scanf("%d",&L_choice);
    if(1 == L_choice)
    {
        lock = check_admin();
        if(lock == 4)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        
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


u8 check_admin(void)
{
    u8  i;
    u32 password;
    
    for(i=1; i<=4; i++)
    {
        if(4 == i)
        {
            printf ("Sorry you tried 3 times System is locked !!!!\n");
            return 4;
        }
        
        else
        {
            printf("Enter the password: ");
            scanf("%d",&password);
            if(CONFIG_PASSWORD == password)
            {
                printf("__________________________________________Welcome in Admin mode__________________________________________________\n\n");
                AdminChoices();
                return 1;
            }
            else if(i<=3)
            {
                printf("wrong password, try again (%d trials left)\n",3-i);
            }

        }

    }

}


void AdminChoices(void)
{
    u8  admin_choice = 1;
    u32 ID;
    u8  i;
    while(admin_choice)
    {
        printf("1. Add new patient record. \n");
        printf("2. Edit patient record.\n");
        printf("3. Reserve a slot with the doctor.\n");
        printf("4. Cancel reservation.\n");

        scanf("%d",&admin_choice);

        if(1 == admin_choice)
        {
            add_record();

        }
        else if(2 == admin_choice)
        {
            edit_record();
        }
        else if(3 == admin_choice)
        {
            PrintReservationtime();
            ReservingTimeSlot();
        }
        else if(4 == admin_choice)
        {
            printf("Enter the patient ID: ");
            scanf("%d",&ID);
            for(i=0; i<5; i++)
            {
                if(ReservationArray[i] == ID)
                {
                    ReservationArray[i] == 0;
                    printf("Your reservation is cancelled successfully \n");
                }
            }

        }
        else
        {
            //Nothing
        }
        admin_choice = 1;
        return;
    }
}


void add_record(void)
{
    char gender[10];
    u8   age;
    char name[10];
    u32  ID;
    u32  x;


    printf("________________________________________________________________________________________\n");
    printf("Enter patient ID: ");
    x = scanf("%d",&ID);
    if(x)
    {
        if( search(ID) )
        {
            printf("ID already exists\n");
            add_record();
        }
        else
        {
            printf("Enter patient name: ");
            scanf("%s",name);
            printf("Enter patient age: ");
            scanf("%d",&age);
            printf("Enter patient gender: ");
            scanf("%s",gender);

            add_node(ID,name,age,gender);

            print_linkedlist();

        }
        printf("_________________________________record added_____________________________________\n\n");

    }
    else
    {
        printf("NOT VALID NUMBER! \n");
        add_record();
        return;
    }
    

}


void add_node(u32 ID, char name[10], u8 age, char gender[10])
{
    if(head == NULL)
    {
        head = (node*)malloc(sizeof(node));
        strcpy((head->name),name);
        head->age    = age;
        strcpy((head->gender),gender);
        head->ID     = ID;
        head->link   = NULL;
    }
    else
    {
        node* ptr = head;
        node* temp = (node*)malloc(sizeof(node));

        strcpy((temp->name),name);
        temp->age    = age;
        strcpy((temp->gender),gender);
        temp->ID     = ID;
        temp->link   = NULL;

        while(ptr->link != NULL)      //////// (ptr->link != NULL) and not (ptr != NULL)
        {
            ptr = ptr->link;
        }
        ptr->link = temp;

    }

}


void print_linkedlist(void)
{
    node* temp = head;

    if(head==NULL)
    {
        printf("No data...\n");
    }
    else
    {
        node* temp = NULL;
        temp = head;
        while(temp != NULL)
        {
            printf("\nID:%d\tName:%s\tAge:%d\tGender:%s\n",temp->ID,temp->name,temp->age,temp->gender);
            printf("________________________________________________________________________________________\n");
            temp = temp->link;
        }
        

    }
}


u8   search(u32 ID)
{
    node* temp = head;

    while(temp != NULL)
    {
        if(temp->ID == ID)
        {
            return ID;
        }
        temp = temp->link;
    }
    return 0;
}


void edit_record(void)
{
    char gender[10];
    u8   age;
    char name[10];
    u32  ID;
    u32  x;
    node* ptr = head;

    printf("Enter patient ID: ");
    x = scanf("%d",&ID);
    if(x)
    {
        while(ptr != NULL)
        {
            if(ptr->ID == ID)
            {
                printf("__________________________________________________________________________________________\n");
                printf("Enter new data...\n");

                printf("Enter new name: ");
                scanf("%s",name);
                printf("__________________________________________________________________________________________\n");

                printf("Enter new age: ");
                scanf("%d",&age);
                printf("__________________________________________________________________________________________\n");

                printf("Enter new gender: ");
                scanf("%s",gender);
                printf("__________________________________________________________________________________________\n");

                ptr->age = age;
                strcpy((ptr->name),name);
                strcpy((ptr->gender),gender);

                print_linkedlist();
                break;

            }
            ptr = ptr->link;
        }
    }
    else
    {
        printf("NOT VALID NUMBER! \n");
        edit_record();
        return;
    }
}


void PrintReservationtime(void)
{
    u8 j;
    for(j=0;j<5;j++)
    {
        if(ReservationArray[j] == 0)
        {
            printf ("Available Slot num %d to reserve :From %s  \n\n",j+1,Time_Slots[j]);
            printf("____________________________________________________________________________________________\n\n");
        }
        else
        {
            printf("This slot is reserved for patied ID: %d",ReservationArray[j]);
            printf("____________________________________________________________________________________________\n\n");
        }
    }
}


void ReservingTimeSlot(void)
{
    u32 TimeSlot;

    printf("__________________________________________________________________________________________\n\n");
    printf("Please enter Your selection :");
    fflush(stdin);
    scanf ("%d",&TimeSlot);


    if(TimeSlot==1)
    {
        printf("________________________________________________________________________________________\n\n");
        printf ("Enter Patient ID : ");
        fflush(stdin);
        if(scanf ("%d",&ReservationArray[0]));
        else
            {
                ReservationArray[0]=0;
                printf("NOT VALID NUMBER !!! \n");
                ReservingTimeSlot();
                return;
            }

    }



    else if(TimeSlot==2)
    {
        printf("________________________________________________________________________________________\n\n");
        printf ("Enter Patient ID : ");
        fflush(stdin);
        if(scanf ("%d",&ReservationArray[1]));
        else
            {
                ReservationArray[1]=0;
                printf("NOT VALID NUMBER !!! \n");
                ReservingTimeSlot();
                return;
            }
    }



    else if(TimeSlot==3)
    {
        printf("________________________________________________________________________________________\n\n");
        printf ("Enter Patient ID : ");
        fflush(stdin);
        if(scanf ("%d",&ReservationArray[2]));
        else
            {
                ReservationArray[2]=0;
                printf("NOT VALID NUMBER !!! \n");
                ReservingTimeSlot();
                return;
            }
    }

    else if(TimeSlot==4)
    {
        printf("________________________________________________________________________________________\n\n");
        printf ("Enter Patient ID : ");
        fflush(stdin);
        if(scanf ("%d",&ReservationArray[3]));
        else
            {
                ReservationArray[3]=0;
                printf("NOT VALID NUMBER !!! \n");
                ReservingTimeSlot();
                return;
            }
    }

    else if(TimeSlot==5)
    {
        printf("________________________________________________________________________________________\n\n");
        printf ("Enter Patient ID : ");
        fflush(stdin);
        if(scanf ("%d",&ReservationArray[4]));
        else
            {
                ReservationArray[4]=0;
                printf("NOT VALID NUMBER !!! \n");
                ReservingTimeSlot();
                return;
            }
    }
    printf("________________________________________________________________________________________\n\n");

}


void UserMode(void)
{
    u8 usermode;
    //u8 x;
    printf("__________________Welcome to user mode__________________\n");
    printf("1. View patient record.\n");
    printf("2. View today's reservations.\n");
    printf("0. To Back To Main Menu.\n\n");
    scanf("%d",&usermode);

        if(usermode == 1)
        {
            GetPatientRecord();
        }
        else if(usermode == 2)
        {
            PrintReservationtime();
        }


    usermode=1;  //set user flag to 1
    
}


void GetPatientRecord(void)
{
    int ID, x;
    node* ptr = NULL;
    ptr = head;
    

    printf("Enter patient ID: ");
    x = scanf("%d",&ID);
    if(x)
    {
        while(ptr != NULL)
        {
            if(ptr->ID == ID)
            {
                printf("ID:%d\t Name:%s\t Age:%d\t Gender:%s\n",ptr->ID,ptr->name,ptr->age, ptr->gender);
                break;
            }
            else
            {
                ptr = ptr->link;
            }

        }
        if(ptr == NULL)
        {
            printf("There is no record for such ID...");
            GetPatientRecord();
            return;
        }
    }
    else
    {
        printf("NOT VALID NUMBER !!! \n");
        GetPatientRecord();
        return;
    }
    
    
}


void Exit(void)
{
    printf("Good bye! \n");
}