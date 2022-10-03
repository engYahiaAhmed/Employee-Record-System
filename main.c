/************************************************/
/* Title       : NTI Embedded C final project   */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : August 11, 2022                */
/************************************************/
/********************************************************************/
/**********************project description**************************/
/**Employee record system that keep track of the employees        */
/**data in a company and be able to add, delete, modify          */
/**and show any required records                                */
/***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"std_types_MT.h"
#include"Link.h"

int main()
{
    companyEmpList clist;
    clist.head=NULL;
    clist.size=0;//to hold number of the employees in the company
    u32 opCode;// to hold the code of the operation that will be applied on the data
    u32 empId;//for taking the ID from the user
    s8 ch;//for asking the user if he wants to clear the screen or not
    while(1)
    {
        printf("****************************************************\n");
        printf("****************************************************\n");
        printf("Enter code of the operation: \n");
        printf("1.Add a new employee data.\n2.Delete the data of an employee.\n3.Modify the data of an employee.\n");
        printf("4.View the data of an employee.\n5.View all the employees data.\n6.Exit\n");
        printf("operation code= ");
        scanf("%d",&opCode);
        printf("======================================================\n");

        switch(opCode)
        {
        case 1:
            employee_addNewEmp(&clist);
            break;
        case 2:
            printf("Enter Employee ID to delete: ");
            scanf("%d",&empId);
            delete_EmpData(&clist,empId);
            break;
        case 3:
            printf("Enter Employee ID to modify: ");
            scanf("%d",&empId);
            employee_editEmpData(&clist,empId);
            break;
        case 4:
            printf("Enter Employee ID to view its data: ");
            scanf("%d",&empId);
            employee_showEmpData(&clist,empId);
            break;
        case 5:
            print_list(&clist);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid Input\n");

        }
        printf("\nCurrent number of employees in the company = %d\n",clist.size);
        do
        {
            printf("clear screen ?(Y/N)\n");
            fflush(stdin);
            scanf(" %c",&ch);
        }
        while(ch=='N' || ch=='n');
        system("cls");
    }
    return 0;
}
