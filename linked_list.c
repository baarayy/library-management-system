#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
user *head=NULL ;
user *tail=NULL ;
void AppendNode(char username[20],int password,int ID)
{
    struct USER *node=(struct USER*)malloc(sizeof(struct USER));
    node->next=NULL;
    strcpy(node->username,username);
    node->id=ID;
    node->pass=password;
    if(head==NULL)
    {
        head=node;
        tail=node;
    }
    else
    {
        tail->next=node;
        tail=node;
    }
}
void PrintNode()
{
    user *node='\0';
    printf("\t\t\t UserName | PassWord  | ID\n\n");
    for(node=head;node!=NULL;node=node->next)
    {
    printf("\t\t\t %s   | %i      | %i\n\n\n " ,node->username , node->pass ,node->id  );
    }
}
int check_username(char username[20]) // to check if the username entered does exist or not
{
    user *node='\0';
    for(node=head;node!=NULL;node=node->next)
    {
        if(!(strcmp(node->username,username))) //comparing the entered username with the rest of the users
        {
            _id=node->id;
            pass_=node->pass;
            return 1;
        }
    }
    return 0;
}
int check_pass(int password)
{
    user *node='\0';
    for(node=head;node!=NULL;node=node->next)
    {
        if(password==node->pass)
            return 1;
    }
    return 0;
}
// Not used in this project ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
int check_ID(int id)
{
    user *node='\0';
    for(node=head;node!=NULL;node=node->next)
    {
        if(id==node->id)
            return 1;
    }
    return 0;
}
// Not used in this project ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
void EDIT_NODE(char old[20],char newname[20],int id,int pass)
{
    user *node=head;
    while(node!=NULL&&(strcmp(node->username,old)))
    {
        node=node->next;
    }
    strcpy(node->username,newname);
    node->id=id;
    node->pass=pass;
}
