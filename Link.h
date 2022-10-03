/************************************************/
/* Title       : NTI Embedded C final project   */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : August 11, 2022                */
/************************************************/
/***********************************************************************************/
/*This file holds the prototypes of the APIS                                      */
/*that will deal wih the employee data                                           */
/*struct represents the employee and holds his data                             */
/*and another struct represrnts the employee on the company view side          */
/******************************************************************************/
#ifndef _COMPANY_EMPLOYEE_LIST_H
#define _COMPANY_EMPLOYEE_LIST_H
#include<stdio.h>
#include<stdlib.h>
#include"std_types_MT.h"
//declaration of employee stucture
typedef struct employee{
    s8 name[30];
	u8 age;
    s8 title[30];
    u32 salary;
	u32 id;
    struct employee * next;
}employeeNode;

// declaration of company list stucture
typedef struct company{
    u32 size;
    employeeNode* head;
}companyEmpList;
//prototypes of methods that will deal with employee data
extern u8 employee_addNewEmp(companyEmpList*);
extern void print_list(companyEmpList* compEmpList);
extern employeeNode* search_node(companyEmpList* compEmpList,u32 ID);
extern void employee_editEmpData(companyEmpList* compEmpList,u32 id );
extern void employee_showEmpData(companyEmpList* compEmpList,u32 id);
extern void delete_EmpData(companyEmpList* compEmpList,u32 id);
#endif
