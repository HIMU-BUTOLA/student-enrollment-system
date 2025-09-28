#include "cource_management_module.c"
int auth(int log)
{
    char p1[100],p2[100] = "Password";
    printf("TO LOGIN AS ADMINISTRATOR PLEASE ENTER PASSWORD...: ");
    scanf("%s",p1);
    int i;
    int check = strcmp(p1,p2);
    if(check == 0)
    {
        printf("LOGGED IN\n");
        log = 1;
        
    }
    else
    {
        printf("Please enter correct password...: ");
        log = 0;
    }
    return log;
    
}