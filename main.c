#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#define PASSWORD 1234 //STATIC PASSWORD
int userORadmin; // to Check the identity before logging in
int admin_pass; // variable to store the admin password
user User;
struct book
{
    char book_name [100];
    char author_name [100];
    int book_id;
    short state; // 1 if the book is reserved and 0 if the book is available
    short studentID; //contain the id of the user who has the reserved book
};
// initializing the books data
struct book books[10] = {{"Phisycs"  , "Albaraa Ahmed" , 1 , 1 ,1 } ,
                         {"Chemistry"  , "Mahmoud Shawky" , 2 , 0 } ,
                         {"Algebra" , "Amr Mostafa" , 3 , 1 , 3} ,
                         {"Geometry"  , "Mohammed Amr" , 4 , 0} ,
                         {"Calculus-1"  , "Mohammed Emad" , 5 , 0 } ,
                         {"Calculus-2"  , "Mahmoud Elshahat" , 6 , 1,5} ,
                         {"Statics" , "Hussien Safwat" , 7 ,0 },
                         {"Dynamics" , "Eslam Zaki" , 8 , 1 ,2},
                         {"Drawing"  , "Ahmed Elmahdy" , 9 ,1,4 } ,
                         {"English"  , "Albaraa Ahmed" , 10 , 1,1}};
//~~~~~~~Admin Functions~~~~~~~~~~
void GetBackToAdmin() // to get back to the main admin page after choosing a particular page
{
    printf("Enter any key to get back\n");
    getch();
    adminPage();
}
void SHOWUSERS() // to display current users in the library
{
 printf("\n\t        L I B R A R Y\t  M A N A G E M E N T\t S Y S T E M \n\n\n");
 PrintNode();
 GetBackToAdmin();
}
void AddUser() // to add a new user to the library
{
  printf("\n\t        L I B R A R Y\t  M A N A G E M E N T\t S Y S T E M \n\n\n");
  printf("\t    ------------------------------------------------------------\n");
  printf("\n\n\n\t\t\t Please,Add the username\n");
  scanf("%s",&User.username);
  if(check_username(User.username))
  {
      system("cls");
      printf("\n\t      This username already exists!!,please choose another one :)\n\n");
      AddUser();
  }
  printf("\t\t\t Enter The Password\n");
  scanf("%d",&User.pass);
  printf("\t\t\t Enter The ID\n");
  scanf("%d",&User.id);
  AppendNode(User.username,User.pass,User.id);
  GetBackToAdmin();
}
void ReserveBook() //to reverse a book for a particular user
{
    printf("\n\t        L I B R A R Y\t  M A N A G E M E N T\t S Y S T E M \n\n\n");
    system("cls");
    int i = 0 ;
    printf("\n\n\t\t\t number  |   name \n"  );
    printf("\t\t\t ________________\n\n");
    while(i < 10 )
    {
        if(books[i].state == 0 )
        {
            printf("\t\t\t %i       |  %s \n" , i+1 , books[i].book_name );
        }
        i++;
    }
    int counter = 0 ;
    while(counter == 0){
        printf("\n \n\t\tHey! choose the book you want to reserve !\n");
        short choice = 0 ;
        scanf("%i", & choice);
        if ( (books[choice-1].state == 1))
            printf("\t\t\t The book is taken\n");
        else if(choice>10)
            printf("\t\t\t Choose a correct number(Out of range!!)\n");
        else {
            printf("\n\t Enter the id of the student you would like to reserve this book for\n");
            scanf("%i" , & books[choice-1].studentID );
            if(!(check_ID(books[choice-1].studentID))){printf("\n\t\t\t wrong id\n"); GetBackToAdmin();}
            books[choice-1].state = 1 ;
            counter = 1 ;
        }
    }
    GetBackToAdmin();
}
void MakeBookAvlbl() // to Make a reversed book available
{
    printf("\n\t        L I B R A R Y\t  M A N A G E M E N T\t S Y S T E M \n\n\n");
    system("cls");
    int i = 0 ;
    printf("\t\t\t number | name           | student ID \n "  );
    printf("\t\t\t _____________________________ \n \n");
    while(i < 10 )
    {
        if(books[i].state == 1 )
        {
            printf("\t\t\t  %i \t|%s \t | %i \t \n" , i+1 ,books[i].book_name,books[i].studentID );
        }
        i++;
    }
    int counter = 0 ;
    while(counter == 0)
    {
        printf("\n \n\t\t\t choose the book you want to make available \n");
        short choice = 0 ;
        scanf("%i", &choice);
        if ((books[choice-1].state == 0 ))
            printf("\t\t\t The book is already available\n");
        else if (choice>10)
            printf("\t\t\t Choose a correct number(Out of range!!)\n");
        else
            {
              books[choice-1].state = 0 ;
              books[choice-1].studentID  = '\0' ;
              counter = 1 ;
            }
    }
    GetBackToAdmin();
}
void adminPage()
{
 system("cls");
 printf("\n\t        L I B R A R Y\t  M A N A G E M E N T\t S Y S T E M \n\n\n");
 printf("\t\t\t !!Welcome To The Admin Page!!\n");
 printf("\t\t\t-------------------------------\t");
 printf("\n\n\t\t\t 1-View user's data \n");
 printf("\t\t\t 2-Add new user \n");
 printf("\t\t\t 3-Reserve a book \n");
 printf("\t\t\t 4-Make a reserved book available \n");
 printf("\t\t\t 5-Go Back \n");
 printf("\n\t\t Press a number \n");
 short choice;
 scanf("%d",&choice);
 switch(choice)
 {
     case 1:system("cls");SHOWUSERS();break;
     case 2:system("cls");AddUser();break;
     case 3:system("cls");ReserveBook();break;
     case 4:system("cls");MakeBookAvlbl();break;
     case 5:system("cls");logIn();break;
     default:printf("\t\t\tWrong Choice!!!\n");adminPage();
 }

}
//~~~~~~Users Functions~~~~~~~
GetBackToUser()
{
    printf("\n\t\t\tEnter any key to get back\n");
    getch();
    UserPage();
}
ShowData()
{
    system("cls");
    printf("\n\t        L I B R A R Y\t  M A N A G E M E N T\t S Y S T E M \n\n\n");
    printf("\n\n\n \t\t\t %s's data : \n",User.username);
    printf("\t\t\t ____________________\n\n ");
    printf("\t\t\t Username: %s\n" , User.username);
    printf("\t\t\t Password: %i\n",User.pass);
    printf("\t\t\t ID      : %i\n\n",_id);
    GetBackToUser();
}
ShowAvlbl()
{
    system("cls");
    printf("\n\t        L I B R A R Y\t  M A N A G E M E N T\t S Y S T E M \n\n\n");
    printf("\n\n\n*-------------------------------AVAILABLE BOOKS--------------------------------*\n\n\n"  );
    printf("\t\t NUMBER  | NAME                     | ID \n "  );
    printf("\t\t _________________________________________ \n \n");
    int i = 0 ;
    int j = 1;
    while(i < 10 )
    {
        if(books[i].state == 0  )
            {
              printf("\t\t %i       | %s                | %i \n" , j ,books[i].book_name ,books[i].book_id  );
              j++;
            }
        i++;
    }
    GetBackToUser();
}
ShowBorrowed()
{
    system("cls");
    printf("\n\t        L I B R A R Y\t  M A N A G E M E N T\t S Y S T E M \n\n\n");
    printf("\n\n\n!!**************************** REVERSED BOOKS ********************************!!\n\n\n"  );
    printf("\t\t NUMBER  | NAME \t | \t ID \n "  );
    printf("\t\t _________________________________________ \n \n");
    int i = 0 ;
    int j = 1;
    while(i < 10 )
    {
        if(books[i].state == 1 && books[i].studentID == _id  )
            {
                printf("\t\t %i \t | %s \t | \t %i \n" , j ,books[i].book_name ,books[i].book_id  );
                j++;
            }
        i++;
    }
    GetBackToUser();
}
void UserPage()
{
 system("cls");
 printf("\n\t        L I B R A R Y\t  M A N A G E M E N T\t S Y S T E M \n\n\n");
 printf("\n\n\t\t\t!!Welcome to The Users Page!!\n");
 printf("\t\t\t*****************************\n");
 printf("\n\n\t\t\t 1-View My data\n");
 printf("\t\t\t 2-Show available books\n");
 printf("\t\t\t 3-Show reversed books\n");
 printf("\t\t\t 4-Go back\n");
 printf("\n\tPress a number\n");
 short choice;
 scanf("%i",&choice);
 switch(choice)
 {
     case 1:ShowData();break;
     case 2:ShowAvlbl();break;
     case 3:ShowBorrowed();break;
     case 4:system("cls");logIn();break;
     default : printf("\t\t Wrong choice!!");UserPage();
 }
}
//now this is a function to log inside the program
void logIn()
{
    printf("\n\t        L I B R A R Y\t  M A N A G E M E N T\t S Y S T E M \n\n\n");
    printf("\t\t     ******  Are You Admin Or User?  ******\n");
    printf("\n\t\t _______________________________________________\n");
    printf("\n\t\t (1)-Admin\t\t                (2)-User\n");
    scanf("%d",&userORadmin);
    if(userORadmin==1)
    {
        printf("\t Enter The Password , Please\n");
        printf("\t Note:Password can't have any charchters(Only integer values)\n");
        scanf("%d",&admin_pass);
        if(admin_pass==PASSWORD)
            adminPage();
        else
        {
            printf("\t\t\tWrong Password\n");
            logIn();
        }

    }
    else if(userORadmin==2)
    {
        printf("\t\tEnter The Username \n");
        scanf("%s",&User.username);
        printf("\n\t\tEnter the Password\n");
        printf("\t\tNote:Password can't have any charchters(Only integer values)\n");
        scanf("%d",&User.pass);
        if((check_username(User.username))&&(check_pass(User.pass)))
            UserPage();
        else
        {
            printf("\t\t\tError!!Username Or Password is not correct:(\n\n");
            printf("\t\t\tPlease try again\n\n");
            logIn();
        }
    }
    else
    {
              printf("\t\t\tError,Please Enter correct number\n");
              logIn();
    }
}
int main()
{
    AppendNode("baraaa" ,1234 ,1 );
    AppendNode("shawky" ,1234 ,2  );
    AppendNode("amrrrr" ,1234 ,3 );
    AppendNode("mahdyy" ,1234 ,4 );
    AppendNode("khaled",1234,5);
    logIn();
        return 0 ;
}
