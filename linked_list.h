#ifndef linked_list_h
#define linked_list_h
typedef struct USER
{
    char username [20];
    int pass;
    int id;
    struct user *next;
}user;
int _id;
int pass_;
void AppendNode(char username[20],int ID,int password);
void PrintNode();
int check_username(char username[20]);
int check_ID(int id);
int check_pass(int password);
void EDIT_NODE(char old[20],char newname[20],int id,int pass);

#endif
