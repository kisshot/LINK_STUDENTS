#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "student.h"


#define CMD_ADD    	1
#define CMD_FIND    2
#define CMD_DEL     3
#define CMD_ALTER   4
#define CMD_PRINT	5
#define CMD_EMPTY	6
#define CMD_SORT	7
#define CMD_SAVE	8

Contact con;
void menu()
{
    printf("void AddContact(Contact *p); //定义添加函数,对应数字 1\n");
    printf("void FindContact(Contact *p); //定义查找函数，对应数字 2\n");
    printf("void DelContact(Contact *p); //定义删除函数，对应数字 3\n");
    printf("void AlterContact(Contact *p); //定义修改函数，对应数字 4\n");
    printf("void PrintContact(Contact *p); //定义打印函数，对应数字 5\n");
    printf("void EmptyContact(Contact *p); //定义清空函数，对应数字 6\n");
    printf("void SortContact(Contact *p); //定义排序函数，对应数字 7\n");
    printf("void SaveContact(Contact *p); //定义排序函数，对应数字 8\n");
}

void pause_list()
{
    while(!kbhit())
    {
        if(kbhit())
        {
            int response;
            response = getchar();

            if (response == 0)
            {
                system("pause");
                printf("END");
            }
        }

    }
}


int main(void)
{
    int input = 0;

    InitContact(&con);

    do{
        menu();
        scanf("%d", &input);


        switch (input)
        {
            case 0:
                break;
            case CMD_ADD:
                AddContact(&con);
                break;
            case CMD_FIND:
                FindContact(&con);
                break;
            case CMD_DEL:
                DelContact(&con);
                break;
            case CMD_ALTER:
                AlterContact(&con);
                break;
            case CMD_PRINT:
                PrintContact(&con);
                break;
            case CMD_EMPTY:
                EmptyContact(&con);
                break;
            case CMD_SORT:
                SortContact(&con);
                break;
            case CMD_SAVE:
                SaveContact(&con);
                break;
            default:
                printf("ERROR");
                printf("\n");
                break;
        }

        printf("Hello, World!\n");
        }while(input);

    //system("pause");
    pause_list();

    return 0;

}