#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining global variables
int i , j,  main_ exit;

//declaring functions
void menu ()
void new_ entry ();
void edit ();
void view list ();
void erase ();
void see ();
void sorter ();
void closer ();

//defining structures
struct date {
    int month, day, year;
};
struct {

    char name [120];
    int age;
    char city [120];
    char mail_ id [60];
    char room _no [8];
    char father _name [60];
    int father_ phone_ no [11];
    int phone_ no [11];
    char hostel _name [6];
    char hostel_ id [10];
    struct date dob;
    int rent_ paid;
    } add, upd , check , rem, sort;

int main ()
{
    
    System ("color 0b");
    Pass ();
  Menu ();
  return 0;
}
void menu ()
{
system("CLS");
    int choice;
    printf ("\n\n\t\t\t HOSTEL MANAGEMENT SYSTEM");
    printf ("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU     \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf ("\n\n\t\t1>> Enter new Student's data\n\t\t2>> Update information of existing account\n\t\t3>> Check the details of existing account\n\t\t4>> View all Students of a particular Hostel\n\t\t5>> Removing existing account\n\t\t6>> View all students list\n\t\t7>> Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf ("%d", &choice);

    switch(choice)
    {

        case 1: new_ entry ();
        break;
        case 2: edit ();
        break;
        case 3: see ();
        break;
        case 4: sorter ();
        break;
        case 5: erase ();
        break;
        case 6: view _list ();
        break;
        case 7: closer ();
        break;
        default: menu ();
    }
}

//------------------------------------------------------------------------------------------------------------------
//function to display all students of a hostel
void sorter ()
{
    system("CLS");
    int choice, test=0;

    printf ("Enter year choice:\n\n\t\t1. BH-1 \n\t\t2. BH-2 \n\t\t3. BH-3 \n\t\t4. GH-1 \n\n");
    scanf ("%d”, & choice);

    FILE *fp, *hostel;
    switch(choice)
    {
        case 1: hostel=fopen("BH-1.dat","a+"); break;
        case 2: hostel=fopen("BH-2.dat","a+"); break;
        case 3: hostel=fopen ("BH-3.dat","a+"); break;
        case 4: hostel=fopen ("GH-1.dat","a+"); break;
        default: sorter ();
    }
    While (fscanf (hostel, "%s\n", check. hostel_ id)! = EOF)
    {
        fp=fopen ("record. dat","r");
        while (fscanf (fp,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n”, sort. Hostel_ id, sort.name, &sort. dob. month, &sort. dob. day, &sort. dob. year, &sort .age, sort. city, &sort.. phone_ no, sort. mail id, sort. father _name, &sort. father phone_ no, sort. room_ no, sort. hostel_ name, &sort. rent _paid)! = EOF)
        {
            If (strcmp (check. Hostel _id, sort.hostel _id)==0)
            {
                if(test==0)
                {
                    Printf ("\t\t Following is the list of requested students:");
                    Printf ("\n\t HOSTEL ID.\t NAME\t ROOM NO.\n");
                }
                Printf ("\n\t%8s\t %8s\t %s", sort. hostel id, sort. room no, sort.name);
                test++;
            }
        }
    }

    fclose(fp);
    if (test==0)
        printf ("\n NO RECORDS!!\n");

    sort _list_invalid:
    printf ("\n\n Enter 1 to go to the main menu and 0 to exit:");
    scanf ("%d”, & main _ exit);

    if (main _exit==1)
        menu ();
    else if (main _exit==0)
        closer ();
    else
    {
        Printf ("\n Invalid! \a");
        Goto sort_ list_ invalid;
    }

}

//------------------------------------------------------------------------------------------------------------------
//new entry function
void new _entry ()
{
    system("CLS");
    int choice;
    FILE *ptr,*hostel;

    ptr=fopen ("record.dat","a+");
    hostel_ id:

    printf ("\t\t\t\xB2\xB2\xB2 ADD STUDENTS DATA \xB2 \xB2\xB2\xB2");
    printf ("\n Enter your hostel_ id:");
    scanf("%s", check. hostel_ id);
    while (fscanf (ptr,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add. hostel_ id, add.name, &add. dob. month, &add. dob. day, &add. dob. year, &add. age, add. city, &add. phone_ no, add. mail id, add.father name, &add. father phone no, add.  room_ no, add. hostel_ name, &add. rent_ paid)!=EOF)
    {
        if (strcmp (check. hostel_ id, add. hostel _id) ==0)
            {
            Printf ("Students hostel_ id already in use!");
             goto hostel_ id;
        }
    }

    Strcpy (add. hostel_ id, check. Hostel _id);
    printf("\n Enter the name:");
    scanf("%s", add.name);
    printf ("\n Enter the date of birth (mm/dd/ yyyy):");
    scanf("%d/%d/%d”, &add. dob. month, &add. dob. day, &add. dob. year);
    printf("\n Enter the age:");
    scanf("%d",& add. age);
    printf("\n Enter the city:");
    scanf("%s”, add. city);
    printf("\n Enter the phone number:");
    scanf("%s",& add. phone _no);
    printf("\n Enter your email id :");
    scanf("%s", add. mail_ id);
    printf("\n Enter your Father's name:");
    scanf("%s", add .father _name);
    printf("\n Enter your Father's phone no.:");
    scanf("%s",& add  .father _phone _no);
    printf("\n --------------------------Each Hostel contains 10 rooms------------------------!!!!");
    printf("\n Enter your room no.:");
    scanf("%s", add. room_ no);
    printf("\n Enter your hostel name from BH-1, BH-2, BH-3, GH-1 :");
    scanf("%s", add. hostel_ name);
    printf("\n Total rent is:5000");
    printf("\n Amount of rent paid: ");
    scanf("%d" , &add. rent_ paid);
    fprintf(ptr,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add. hostel_ id, add. name, add. dob. month, add. dob. day, add. dob. year, add. age, add. city, add. phone no, add. mail id, add. father_ name, add.  father_ phone _no, add. room _no, add. hostel _name, add. rent _paid);

        //adding student hostel id. to hostels' list
    If (strcmp (add. hostel _name,"BH-1") ==0)
    {
        hostel=fopen("BH-1.dat","a [11]");
        fprintf(hostel, "%s\n", add.  hostel _id);
        fclose(hostel);
    }
    else if (strcmp(add. hostel_name,"BH-2") ==0)
    {
        hostel=fopen("BH-2.dat","[11]");
        fprintf(hostel, "%s\n", add .hostel_ id);
        fclose(hostel);
    }
    else if (strcmp(add. hostel _name,"BH-3") ==0)
    {
        hostel=fopen("BH-3.dat","a [11]");
        fprintf(hostel, "%s\n", add. hostel_ id);
        fclose(hostel);
    }
    else if (strcmp(add .hostel_name,"GH-1")==0)
    {
        hostel=fopen("GH-1.dat","[11]");
        fprintf(hostel, "%s\n" ,add .hostel_ id);
        fclose(hostel);
    }
        //----------------------------------------

    fclose(ptr);
    printf("\n Student added successfully!");
    add _invalid:
    printf("\n\n\n\t\t Enter 1 to go to the main menu and 0 to exit:");
    scanf("%d",& main_ exit);

    if (main_ exit==1)
 
        menu ();
    else if (main _exit==0)
            closer ();
    else
        {
            printf("\n Invalid!\a");
            goto add_ invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
//function to view all students
void view _list ()
{
    system("CLS");
    FILE *view;
    view=fopen ("record.dat","r");
    int test=0;

    printf("\n HOSTEL_ID\t  NAME\t\t\t City\t\t\t RENT PAID\t\t\t ROOM ALLOTED\n");

    while (fscanf (view, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n”, add. hostel _ id, add.name, &add. dob. month, &add. dob. day, &add. dob. year, &add.  age, add. city, &add. phone_ no, add. mail_ id, add. father name, &add. father phone_ no, add. room_ no, add. hostel_ name, &add. rent _ paid)! = EOF)
       {
           printf("\n%8s\t %10s\t\t\t %10s\t\t %d\t\t\t %s",add.hostel_id,add. name,add.city,add.rent_paid,add.room_no);
           test++;
       }
    fclose(view);

    if (test==0)
        {
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
            menu();
        else if (main_ exit==0)
            closer ();
        else
        {
            printf("\n Invalid!\a");
            goto view_list_invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
//function to view all data of 1 student
void see()
{
    system("CLS");
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Hostel id.\n Enter your choice:");
    scanf("%d", &choice);
    if (choice==1)
    {   printf("\n\nEnter the hostel id:");
        scanf("%s",check.hostel_id);

        while (fscanf(ptr,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid)!=EOF)
        {
            if(strcmp(add.hostel_id,check.hostel_id)==0)
            {
                test=1;

                printf("\nhostel_id:%s\nName:%s \nDOB:%d/%d/%d \nAge:%d \ncity:%s \nPhone number:%s \nE-Mail id:%s \nFather's name:%s \n Father's Phone No.:%s \nRoom No:%s \nHostel:%s \nAdd.rent_paid :%d\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);
            }
        }
    }
  

    fclose(ptr);
     if(test!=1)
        printf("\nRecord not found!!\a\a\a");
    see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer();
        else if(main_exit==0)
            erase();
        else
        {
            printf("\nInvalid!\a");
            goto see_invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
//function to update student info
void edit()
{
    system("CLS");
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the hostel id of the student whose info you want to change:");
    scanf("%s",upd.hostel_id);
    while(fscanf(old,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.city, &add.phone_no, add.mail_id, add.father_name, &add.father_phone_no, add.room_no, add.hostel_name, &add.rent_paid)!=EOF)

    {
        if (strcmp(add.hostel_id,upd.hostel_id)==0)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Room no.\n2.Phone\n\nEnter your choice(1 for room no. and 2 for phone ):");
            scanf("%d",&choice);

            if(choice==1)
                {printf("Enter the new room no.:");
                scanf("%s",upd.room_no);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add.mail_id, add.father_name, add.father_phone_no, upd.room_no, add.hostel_name, add.rent_paid);
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%d",&upd.phone_no);
                fprintf(newrec,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, upd.phone_no, add.mail_id, add.father_name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);
                printf("Changes saved!");
                }

        }
        else
            fprintf(newrec,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n",add.hostel_id, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.city, add.phone_no, add. Mail id, add. Father _name, add.father_phone_no, add.room_no, add.hostel_name, add.rent_paid);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    if(test!=1)
        printf("\nRecord not found!!\a\a\a");

    edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            closer ();
        else if(main_exit==0)
            edit ();
        else
        {
            printf("\n Invalid!\a");
            goto edit_ invalid;
        }

}

//------------------------------------------------------------------------------------------------------------------
//cpfunction to delete records
void erase ()
{
    system("CLS");
    FILE *old, *newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec =fopen("new.dat","w");
    printf("Enter the Hostel_ id of student whose data you want to delete:");
    scanf("%s", rem .hostel_ id);
    while (fscanf(old, "%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n", add. hostel_ id, add.name, &add. dob. month, &add. dob. day, &add. dob, year, &add. age, add. city, &add. phone_ no, add. mail id, add.father name, &add. father_ phone no, add. room no, add. hostel_ name, &add.rent_paid)!=EOF)
   {
        if (strcmp(add. hostel _id, rem. hostel_id)! = 0)
            fprintf(newrec,"%s %s %d/%d/%d %d %s %s %s %s %s %s %s %d\n”, add. hostel_ id, add.name, add.  dob. month, add. dob. day, add. dob. year, add. age, add. city, add. phone_ no, add. mail id, add.father_name, add. father _phone _no, add. room no, add. hostel _name, add .rent _paid);

        else
            {test++;
            printf("\n Record deleted successfully!\n");
            }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");
    if(test==0)
        printf("\n Record not found!!\a\a\a");
    erase_ invalid:
        printf("\n Enter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",& main _exit);
        if (main_ exit==1)
            menu ();
        else if (main _exit==2)
            closer ();
        else if (main_ exit==0)
            erase ();
        else
        {
            printf("\n Invalid!\a");
            goto erase_ invalid;
        }
}

//------------------------------------------------------------------------------------------------------------------
//function displaying developer credits 1353functioncalls
void closer ()
{
    system("CLS");
    printf("\n\n\n*THANK YOU*\n\n\n");
}

int pass(void)
{
   int a=0, i=0;
    char uname[10],c=' ';
    char pword[10],code [10];
    char user [10] ="user";
    char pass [10] ="pass";
    do
{
    system("cls");

    printf("\n  *  LOGIN FORM  *  ");
    printf(" \n                       ENTER USERNAME:-");
    scanf("%s", &uname);
    printf(" \n                       ENTER PASSWORD:-");
    while(i<10)
    {
        pword[i]=getch();
        c=pword[i];
        if(c==13) break;
        else printf("*");
        i++;
    }
    pword[i]='\0';
    //char code=pword;
    i=0;
    //scanf("%s",&pword);
        if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
    {
    printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
    system("PAUSE");
    break;
    }
    else
    {
        printf("\n SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
        system("PAUSE");
        a++;

        getch ();

    }
}
    while(a<=2);
    if (a>2)
    {
        printf("\n Sorry you have entered the wrong username and password for four times!!!");

        getch ();

        }
        system("cls");
}
