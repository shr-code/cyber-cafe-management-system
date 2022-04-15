
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h> 
#include <time.h>   
#include <ctype.h>  
typedef struct customer
{
    int id;
    char fname[20];
    char lname[20];
    char gender;
    char email[50];
    char contact[10];
    char checkin_time[26];
} customer;

void welcomescreen();
int loginScreen();
void Title();
void MainMenu();
void checkin();
void checkout();
void ViewRec();
void search_record();
void Edit_Rec();
time_t t, t1;

int main()
{
    system("cls");
    welcomescreen();
    loginScreen();
    return 0;
}
//============welcome screen=============
void welcomescreen()
{
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t#######################################################");
    printf("\n\t\t\t\t\t\t\t\t##\t\t\tWELCOME TO\t\t     ##");
    printf("\n\t\t\t\t\t\t\t\t##\t      CYBER CAFE MANAGEMENT PROGRAM.\t     ##");
    printf("\n\t\t\t\t\t\t\t\t#######################################################");
    printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tPress any key to continue.");
    getch();
    system("cls");
}
//=============title=============
void Title(void)
{
    printf("\n\n\n\t\t\t\t\t\t\t---------------------------------------------------------------");
    printf("\n\t\t\t\t\t\t\t\t\t CYBER CAFE MANAGEMENT SYSTEM");
    printf("\n\t\t\t\t\t\t\t---------------------------------------------------------------");
}
//=======admin login credentials===============
int loginScreen()
{

    int turns = 0, i;
    char ch1;
    char Username[15];
    char Password[15];
    char Org_Username[15] = "Cyber";
    char Org_Password[15] = "12345";

    while (turns < 3)
    {
        printf("\n\n\n\n\t\t\t\t\t\t\tCAFE OWNER LOGIN CREDENTIALS");
        printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t USERNAME  :  ");

        gets(Username);

        printf("\n\t\t\t\t\t\t\t\t\t\t PASSWORD  :  ");
        for (i = 0; i < 15; i++)
        {
            ch1 = getch();
            Password[i] = ch1;

            if (ch1 != 13) 
                printf("*");
            if (ch1 == 13)
                break;
        }
        Password[i] = '\0';
        // gets(Password);
        if (strcmp(Username, Org_Username) == 0 && strcmp(Password, Org_Password) == 0)
        {
            printf("\n\t\t\t\t\t\t\t\t\t\t------------------------\n");
            printf("\n\t\t\t\t\t\t\t\t\t\t    Login successful\n");
            printf("\n\t\t\t\t\t\t\t\t\t\t------------------------\n");
            printf("\n\t\t\t\t\t\t\tPress any key to continue.");
            getch();
            MainMenu();
            break;
        }
        else
        {
            printf("\n\t\t\t\t\t\t\t\t\t\t!!  Unauthorized credentials  !!\n");
            printf("\n\t\t\t\t\t\t\t\t\t\tPress ENTER to Retry...\n");
            getch();
            system("cls");
            turns++;
        }
    }
    if (turns >= 3)
    {
        Title();
        printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tYou have crossed the limit.\n");
        printf("\n\t\t\t\t\t\t\t\t\t\tPress ENTER to close...\n");
        getch();
    }
    system("cls");
    return 0;
}
//=============Main Menu=============
void MainMenu()
{
menu:
    system("cls");
    int choice;
    Title();
    printf("\n\n\n\n\t\t\t\t\t\t\t1. Checkin User \n");
    printf("\t\t\t\t\t\t\t2. Checkout User\n");
    printf("\t\t\t\t\t\t\t3. View User Record\n");
    printf("\t\t\t\t\t\t\t4. Search User Record\n");
    printf("\t\t\t\t\t\t\t5. Update User Record\n");
    printf("\t\t\t\t\t\t\t6. Exit\n");

    printf("\n\n\n\t\t\t\t\t\t\tEnter Choice  :  ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        checkin();
        getch();
        goto menu;
        break;
    case 2:
        checkout();
        getch();
        goto menu;
        break;
    case 3:
        ViewRec();
        getch();
        goto menu;
        break;
    case 4:
        search_record();
        getch();
        goto menu;
        break;
    case 5:
        Edit_Rec();
        getch();
        goto menu;
        break;
    case 6:
        exit(1);
        break;

    default:
        printf("\t\t\tInvalid Entry.Please Enter Choice from 1 to 6.");
        getch();
        fflush(stdin);
        goto menu;
    }
}
//============checkin==============
void checkin()
{
    system("cls");

    printf("\n\n\n\t\t\t\t\t\t\t\t\t--------------------------------");
    printf("\n\t\t\t\t\t\t\t\t\t\t    CHECKIN USER");
    printf("\n\t\t\t\t\t\t\t\t\t--------------------------------");
    time(&t);
    char choice = 'y';
    FILE *fp, *fp1; //file structure pointer
    int u_id, dt, hh, mm, ss, yyyy;
    char eaddress[50], contact[10], day[3], mon[3];
    char fname[25], lname[25], gender;
    fp = fopen("cyber1.txt", "a");
    fp1 = fopen("cyber1.txt", "r");
    if (fp == NULL)
    {
        perror("\n\n\t\t\t\t\t\t\tError");
        printf("\n\n\t\t\t\t\t     Press any key to continue ");
        return;
    }
    fflush(stdin);
    while (choice == 'y')
    {
        fp = fopen("cyber1.txt", "a");
        Title();
        customer c;
    userid:
        printf("\n\t\t\t\t\t\tEnter user id                         :         ");
        scanf("%d", &c.id);
        while (fscanf(fp1, "%d\t%s %s\t%c\t%s\t%s\t%s %s %d %d:%d:%d %d", &u_id, fname, lname, &gender, eaddress, contact, day, mon, &dt, &hh, &mm, &ss, &yyyy) != EOF)
        {
            if (c.id == u_id)
            {
                rewind(fp1);
                printf("\n\t\t\t\t\t\tId already exists!");
                goto userid;
            }
        }
        fflush(stdin);
        printf("\n\t\t\t\t\t\tEnter your first name                 :         ");
        scanf("%s", c.fname);
        fflush(stdin);
        printf("\n\t\t\t\t\t\tEnter your last name                  :         ");
        scanf("%s", c.lname);
        fflush(stdin);
    chk_gen:
        printf("\n\t\t\t\t\t\tEnter your gender(M/F)                :         ");
        scanf("%c", &c.gender);
        fflush(stdin);
        if (c.gender != 'M' && c.gender != 'F' && c.gender != 'f' && c.gender != 'm')
        {
            printf("\n\t\t\t\t\t\tPlease enter M for male or F for female!");
            goto chk_gen;
        }
        printf("\n\t\t\t\t\t\tEnter your email address              :         ");
        scanf("%s", c.email);
        fflush(stdin);
    chk_no:
        printf("\n\t\t\t\t\t\tEnter your contact number             :         ");
        scanf("%s", c.contact);
        fflush(stdin);
        if (strlen(c.contact) > 10 || strlen(c.contact) < 10)
        {
            printf("\n\t\t\t\t\t\tPlease enter a valid number!");
            goto chk_no;
        }
        else
        {
            for (int i = 0; i < strlen(c.contact); i++)
            {

                if (isdigit(c.contact[i]) == 0)
                {
                    printf("\n\t\t\t\t\t\tOnly digits to be entered!");
                    goto chk_no;
                }
            }
        }
        printf("\n\t\t\t\t\t\tCheckin time and date is              :         ");
        printf("%s", ctime(&t));
        fflush(stdin);
        fprintf(fp, "%d\t%s %s\t%c\t%s\t%s\t%s\n", c.id, c.fname, c.lname, c.gender, c.email, c.contact, ctime(&t));
        printf("\n\t\t\t\t\t\tDo you want to add more?(y/n)         :         ");
        fflush(stdin);
        scanf("%c", &choice);
        fflush(stdin);
        system("cls");
        fclose(fp);
    }

    printf("\n\n\t\t\t\t\t     Press any key to continue ");
    getch();
    MainMenu();
    fclose(fp1);
}
//==============checkout===========
void checkout()
{
    system("cls");
    Title();
    printf("\n\n\t\t\t\t\t\t\t\t\t--------------------------------");
    printf("\n\t\t\t\t\t\t\t\t\t\t  CHECKOUT USERS");
    printf("\n\t\t\t\t\t\t\t\t\t--------------------------------\n\n");
    int i = 1;
    int u_id, dt, hh, mm, ss, yyyy, found = 0, found1 = 0;
    char eaddress[50], day[3], mon[3];
    float contact;
    char fname[25], lname[25], gender;
    FILE *fp, *fp1;
    fp = fopen("cyber1.txt", "r");
    customer c;
    if (fp == NULL)
    {
        perror("\n\n\t\t\t\t\t\t\tError");
        return;
    }
    printf("\n\t\t\t\t\t\tEnter user id to checkout     :           ");
    scanf("%d", &c.id);
    time(&t1);
    while (fscanf(fp, "%d   %s %s   %c  %s  %f  %s %s %d %02d:%02d:%02d %d", &u_id, fname, lname, &gender, eaddress, &contact, day, mon, &dt, &hh, &mm, &ss, &yyyy) != EOF)
    {
        fp1 = fopen("chkoutdetails.txt", "a+");
        if (c.id == u_id)
        {
            found = 1;
            printf("\n\t\t\t\t\t\tUser-id                       :           %d", u_id);
            printf("\n\t\t\t\t\t\tFirst Name                    :           %s", fname);
            printf("\n\t\t\t\t\t\tLast Name                     :           %s", lname);
            printf("\n\t\t\t\t\t\tGender                        :           %c", gender);
            printf("\n\t\t\t\t\t\tContact Number                :           %.0f", contact);
            printf("\n\t\t\t\t\t\t\t   ------------Checkin details------------");
            printf("\n\t\t\t\t\t\tDate                          :           %d/%s/%d", dt, mon, yyyy);
            printf("\n\t\t\t\t\t\tTime                          :           %02d:%02d:%02d", hh, mm, ss);

            while (fscanf(fp1, "%d %s %s %d %02d:%02d:%02d %d", &u_id, day, mon, &dt, &hh, &mm, &ss, &yyyy) != EOF)
            {
                if (c.id == u_id)
                {
                    printf("\n");
                    printf("\n\t\t\t\t\t\tUser already logged out!");
                    printf("\n");
                    found1 = 1;
                    printf("\n\t\t\t\t\t\t\t   ------------Checkout details------------");
                    printf("\n\t\t\t\t\t\tDate                          :           %d/%s/%d", dt, mon, yyyy);
                    printf("\n\t\t\t\t\t\tTime                          :           %02d:%02d:%02d", hh, mm, ss);
                    break;
                }
            }
            if (!found1)
            {
                fprintf(fp1, "%d %s", c.id, ctime(&t1));
                printf("\n");
                printf("\n\t\t\t\t\t\t\tUser logged out!");
                printf("\n");
                printf("\n\t\t\t\t\t\t\t   ------------Checkout details------------");
                printf("\n\t\t\t\t\t\tCheckout date and time        :           %s", ctime(&t1));
            }
            fclose(fp1);
        }
    }
    if (!found)
        printf("\n\n\t\t\t\t\tUser Id doesn't exist!");
    printf("\n\n\t\t\t\t\t     Press any key to continue ");
    getch();
    system("cls");
    MainMenu();
    fclose(fp);
    return;
}
// //================view all the records===========
void ViewRec()
{
    system("cls");
    Title();
    printf("\n\n\t\t\t\t\t\t\t\t\t--------------------------------");
    printf("\n\t\t\t\t\t\t\t\t\t\t    USER RECORDS");
    printf("\n\t\t\t\t\t\t\t\t\t--------------------------------\n\n");
    int i = 1;
    int u_id, dt, hh, mm, ss, yyyy, u_id1;
    char eaddress[50], day[3], mon[3];
    double contact;
    char fname[25], lname[25], gender;
    FILE *fp, *fp1;
    fp = fopen("cyber1.txt", "r");
    fp1 = fopen("chkoutdetails.txt", "a+");
    customer c;
    if (fp == NULL)
    {
        perror("\n\n\t\t\t\t\t\t\tError");
        return;
    }

    while (fscanf(fp, "%d   %s %s   %c  %s  %lf  %s %s %d %02d:%02d:%02d %d", &u_id, fname, lname, &gender, eaddress, &contact, day, mon, &dt, &hh, &mm, &ss, &yyyy) != EOF)
    {
        printf("\n\t\t\t\t\t\t\t ------------");
        printf("\n\t\t\t\t\t\t\t Record no.%d ", i);
        printf("\n\t\t\t\t\t\t\t ------------\n");
        printf("\n\t\t\t\t\t\tUser-id                       :           %d", u_id);
        printf("\n\t\t\t\t\t\tFirst Name                    :           %s", fname);
        printf("\n\t\t\t\t\t\tLast Name                     :           %s", lname);
        printf("\n\t\t\t\t\t\tGender                        :           %c", gender);
        printf("\n\t\t\t\t\t\tContact Number                :           %.0lf", contact);
        printf("\n\t\t\t\t\t\t\t   ------------Checkin details------------");
        printf("\n\t\t\t\t\t\tDate                          :           %d/%s/%d", dt, mon, yyyy);
        printf("\n\t\t\t\t\t\tTime                          :           %02d:%02d:%02d", hh, mm, ss);
        while (fscanf(fp1, "%d %s %s %d %02d:%02d:%02d %d", &u_id1, day, mon, &dt, &hh, &mm, &ss, &yyyy) != EOF)
        {
            if (u_id1 == u_id)
            {

                printf("\n\t\t\t\t\t\t\t   ------------Checkout details------------");
                printf("\n\t\t\t\t\t\tDate                          :           %d/%s/%d", dt, mon, yyyy);
                printf("\n\t\t\t\t\t\tTime                          :           %02d:%02d:%02d", hh, mm, ss);
                rewind(fp1);
                printf("\n");
                break;
            }
        }
        if (u_id1 != u_id)
        {
            rewind(fp1);
        }

        i++;
    }
    printf("\n\n\t\t\t\t\t     Press any key to continue ");
    getch();
    MainMenu();
    fclose(fp);
    return;
}
//===================search records=========================
void search_record()
{
    system("cls");
    Title();
    printf("\n\n\t\t\t\t\t\t\t\t\t--------------------------------");
    printf("\n\t\t\t\t\t\t\t\t\t\t   SEARCH RECORDS");
    printf("\n\t\t\t\t\t\t\t\t\t--------------------------------\n\n");
    int i = 1;
    int u_id, u_id1, dt, hh, mm, ss, yyyy, found = 0;
    char eaddress[50], day[3], mon[3];
    double contact;
    char fname[25], lname[25], gender;
    FILE *fp, *fp1;
    fp = fopen("cyber1.txt", "r");
    fp1 = fopen("chkoutdetails.txt", "a+");
    customer c;
    if (fp == NULL)
    {
        perror("\n\n\t\t\t\t\t\t\tError");
        return;
    }
    printf("\n\t\t\t\t\t\tEnter userid to fetch information            :         ");
    scanf("%d", &c.id);
    while (fscanf(fp, "%d   %s %s   %c  %s  %lf  %s %s %d %02d:%02d:%02d %d", &u_id, fname, lname, &gender, eaddress, &contact, day, mon, &dt, &hh, &mm, &ss, &yyyy) != EOF)
    {
        if (c.id == u_id)
        {
            found = 1;
            printf("\n\t\t\t\t\t\tUser-id                       :           %d", u_id);
            printf("\n\t\t\t\t\t\tFirst Name                    :           %s", fname);
            printf("\n\t\t\t\t\t\tLast Name                     :           %s", lname);
            printf("\n\t\t\t\t\t\tGender                        :           %c", gender);
            printf("\n\t\t\t\t\t\tContact Number                :           %.0lf", contact);
            printf("\n\t\t\t\t\t\t\t   ------------Checkin details------------");
            printf("\n\t\t\t\t\t\tDate                          :           %d/%s/%d", dt, mon, yyyy);
            printf("\n\t\t\t\t\t\tTime                          :           %02d:%02d:%02d", hh, mm, ss);
            printf("\n\n");
        }
    }
    while (fscanf(fp1, "%d %s %s %d %02d:%02d:%02d %d", &u_id1, day, mon, &dt, &hh, &mm, &ss, &yyyy) != EOF)
    {
        if (u_id1 == c.id)
        {

            printf("\n\t\t\t\t\t\t\t   ------------Checkout details------------");
            printf("\n\t\t\t\t\t\tDate                          :           %d/%s/%d", dt, mon, yyyy);
            printf("\n\t\t\t\t\t\tTime                          :           %02d:%02d:%02d", hh, mm, ss);
            rewind(fp1);
            printf("\n");
            break;
        }
    }
    if (u_id1 != u_id)
    {
        rewind(fp1);
    }
    if (!found)
        printf("\n\t\t\t\t\t\tUser Id doesn't exist!");

    printf("\n\n\t\t\t\t\t     Press any key to continue ");
    getch();
    MainMenu();
    fclose(fp);
    return;
}
//================update record==============
void Edit_Rec()
{
    system("cls");
    printf("\n\n\n\t\t\t\t\t\t\t\t\t--------------------------------");
    printf("\n\t\t\t\t\t\t\t\t\t\t    UPDATE RECORD");
    printf("\n\t\t\t\t\t\t\t\t\t--------------------------------");
    FILE *fp, *fp1;
    int u_id, dt, hh, mm, ss, yyyy, found = 0, cho, confound = 0;
    char eaddress[50], contact[10], day[3], mon[3];
    char fname[25], lname[25], gender;
    double fcontact;
    customer c;
    fp = fopen("cyber1.txt", "r");
    fp1 = fopen("temporary.txt", "w");
    if (fp == NULL)
    {
        perror("\n\n\t\t\t\t\t\t\tError");
        printf("\n\n\t\t\t\t\t     Press any key to continue ");
        return;
    }
    fflush(stdin);
    printf("\n\t\t\t\t\t\tEnter user id to update           :             ");
    scanf("%d", &c.id);

    while (fscanf(fp, "%d   %s %s   %c  %s  %lf  %s %s %d %02d:%02d:%02d %d", &u_id, fname, lname, &gender, eaddress, &fcontact, day, mon, &dt, &hh, &mm, &ss, &yyyy) != EOF)
    {
        if (c.id == u_id)
        {
            found = 1;
            printf("\n\t\t\t\t\t\tDETAILS OF THE USER ID %d\n", u_id);
            printf("\n\t\t\t\t\t\tUser-id                       :           %d", u_id);
            printf("\n\t\t\t\t\t\tFirst Name                    :           %s", fname);
            printf("\n\t\t\t\t\t\tLast Name                     :           %s", lname);
            printf("\n\t\t\t\t\t\tGender                        :           %c", gender);
            printf("\n\t\t\t\t\t\tEmail id                      :           %s", eaddress);
            printf("\n\t\t\t\t\t\tContact Number                :           %.0lf", fcontact);
            printf("\n\t\t\t\t\t\t\t   ------------Checkin details------------");
            printf("\n\t\t\t\t\t\tDate                          :           %d/%s/%d", dt, mon, yyyy);
            printf("\n\t\t\t\t\t\tTime                          :           %d:%d:%d", hh, mm, ss);
            printf("\n\n");
            printf("\n\n\t\t\t\t\t     Press any key to continue ");

            getch();
            fflush(stdin);
            system("cls");
            printf("\n\t\t\t\t\t\tWHAT DO YOU WANT TO UPDATE?");
            printf("\n\t\t\t\t\t\t1.First Name");
            printf("\n\t\t\t\t\t\t2.Last Name");
            printf("\n\t\t\t\t\t\t3.Gender");
            printf("\n\t\t\t\t\t\t4.Contact Number");
            printf("\n\t\t\t\t\t\tEnter your selection: ");
            scanf("%d", &cho);
            fflush(stdin);
            switch (cho)
            {
            case 1:
                printf("\n\t\t\t\t\t\tUpdated First Name        :          ");
                scanf("%s", fname);
                fflush(stdin);
                break;
            case 2:
                printf("\n\t\t\t\t\t\tUpdated Last Name         :          ");
                scanf("%s", lname);
                fflush(stdin);
                break;
            case 3:
            label1:
                printf("\n\t\t\t\t\t\tUpdated Gender            :          ");
                scanf("%c", &gender);
                fflush(stdin);
                if (gender != 'M' && gender != 'F' && gender != 'f' && gender != 'm')
                {
                    printf("\n\t\t\t\t\t\tPlease enter M for male or F for female!");
                    goto label1;
                }
                break;
            case 4:
                confound = 1;
                fprintf(fp1, "%d\t%s %s\t%c\t%s\t", u_id, fname, lname, gender, eaddress);
            label2:
                printf("\n\t\t\t\t\t\tUpdated Contact Number    :          ");
                scanf("%s", contact);
                fflush(stdin);
                if (strlen(contact) > 10 || strlen(contact) < 10)
                {
                    printf("\n\t\t\t\t\t\tPlease enter a valid number!");
                    goto label2;
                }
                else
                {
                    for (int i = 0; i < strlen(contact); i++)
                    {
                        if (isdigit(contact[i]) == 0)
                        {
                            printf("\n\t\t\t\t\t\tOnly digits to be entered!");
                            goto label2;
                        }
                    }
                }
                printf("\n\t\t\t\t\t\tUpdated number is: ");
                printf("%s", contact);
                fprintf(fp1, "%s\t--- %s %d %d:%d:%d %d\n", contact, mon, dt, hh, mm, ss, yyyy);
                break;
            default:
                printf("\n\t\t\t\t\t\tInvalid Choice!");
                break;
            }
        }
        if (c.id != u_id || confound == 0)
            fprintf(fp1, "%d\t%s %s\t%c\t%s\t%0.lf\t--- %s %d %d:%d:%d %d\n", u_id, fname, lname, gender, eaddress, fcontact, mon, dt, hh, mm, ss, yyyy);
    }
    fclose(fp);
    fclose(fp1);
    if (found)
    {
        fp1 = fopen("temporary.txt", "r");
        fp = fopen("cyber1.txt", "w");
        char ch = fgetc(fp1);
        while (ch != EOF)
        {
            fputc(ch, fp);
            ch = fgetc(fp1);
        }
    }
    else
    {
        printf("\n\t\t\t\t\t\tRecord not found!");
    }
    printf("\n\n\t\t\t\t\t     Press any key to continue ");
    getch();
    fclose(fp1);
    fclose(fp);
    MainMenu();
}
