#include <stdio.h>
#include <stdlib.h>
#include "conio.h"
#include "student.h"

Contact con;
void menu()
{
    printf("void AddContact(Contact *p); //定义添加函数,对应数字 1\n");
    printf("void FindContact(Contact *p); //定义查找函数，对应数字 2\n");
    printf("void DelContact(Contact *p); //定义删除函数，对应数字 3\n");
    printf("void AlterContact(Contact *p); //定义修改函数，对应数字 4\n");
    printf("void PrintContact(Contact *p); //定义打印函数，对应数字 5\n");
    printf("void EmptyContact(Contact *p); //定义清空函数，对应数字 6\n");
    printf("void SortContact(Contact *p); //定义排序函数，对应数字 7");
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
            case 1:
                AddContact(&con);
                break;
            case 2:
                FindContact(&con);
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