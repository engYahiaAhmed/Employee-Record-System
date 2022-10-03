/************************************************/
/* Title       : NTI Embedded C final project   */
/* Author      : Yahia Ahmed                    */
/* Release     : 1.0                            */
/* Last Update : August 11, 2022                */
/************************************************/
/***********************************************************************************/
/*This file holds the implementation of the APIS                                  */
/*that will deal wih the employee data                                           */
/********************************************************************************/
#include"Link.h"
//function to insert new Employee to the company List 
//all the employee data will be token from 
//the user during the running time of the program
u8 employee_addNewEmp(companyEmpList* compEmpList)
{
    employeeNode*current = compEmpList->head;
	
    s8 titleEmp[30];//array of char to take the the position title of the employee
    u8 age;
    u8 nameEmp[30];
    u32 salary ;
    u8 id;

    //creating a new employee node
    employeeNode* newEmpNode = (employeeNode*)calloc(1,sizeof(employeeNode));
    //if there is no space in memory
    if(newEmpNode==NULL)
        return FAILURE;
	//taking the employee data from the user
    printf("\n**************************************************\n");
    printf("Enter Employee Data:\n\n");
    printf("Enter Employee %d name: ",compEmpList->size+1);
    fflush(stdin);
    gets(nameEmp);
    printf("Enter Employee %d age: ",(compEmpList->size)+1);
    scanf("%d",&age);
    printf("Enter Employee %d ID: ",(compEmpList->size)+1);
    scanf("%d",&id);
    printf("Enter Employee %d title: ",(compEmpList->size)+1);
    fflush(stdin);
    gets(titleEmp);

    printf("Enter Employee %d salary: ",(compEmpList->size)+1);
    scanf("%d",&salary);
    strcpy(newEmpNode->name  , nameEmp);
    strcpy(newEmpNode->title , titleEmp);
	newEmpNode->age=age;
	newEmpNode->salary=salary;

	newEmpNode->id=id;


    newEmpNode->next=NULL;
    //if the list is empty
    if(compEmpList->head == NULL)
    {
        compEmpList->head = newEmpNode;
    }else{
        //reaching the last node
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next=newEmpNode;
    }
    compEmpList->size=compEmpList->size+1;
    return SUCESS;
}

/*****************function to View all the employees data in the company***************/
void print_list(companyEmpList* compEmpList)
{
    employeeNode*current= compEmpList->head;

    if(compEmpList->head == NULL) // the linked list is empty
    {
        printf("\nthe list is empty\n");
    }
    while (current!=NULL)
    {
        printf("\n*************************************************\n");
        printf("the employee name is: %s\n",current->name);
        printf("%s ID is: %d\n",current->name,current->id);
        printf("%s age is: %d\n",current->name,current->age);
        printf("%s salary is: %d\n",current->name , current->salary);
        printf("%s title is: %s\n",current->name , current->title);
        current = current->next;
    }
    printf("\n");
}
//it's an auxiliary function that search for an employee with an ID
//and return a pointer to the employee node
employeeNode* search_node(companyEmpList* compEmpList,u32 ID)
{

    employeeNode* current= compEmpList->head;
    while (current!=NULL &&current->id !=ID )
    {
        current = current->next;
    }
    return current;
}
//function that Modify the data of an employee 
//the function will take the company list address and the employee ID 
//and by using the auxiliary function search_node will get the employee 
//address and then ask the user to enter the new Employee data
void employee_editEmpData(companyEmpList* compEmpList,u32 id)
 {
    employeeNode* search = search_node(compEmpList,id);
    s8 titleEmp[30];
    u8 age;
    u32 salary ;
    u8 nameEmp[30];
    if(search==NULL)
    {
        printf("ID value not found\n");
        return;
    }
    printf("\n**************************************************\n");
    printf("Enter Employee new Data:\n\n");
    printf("Enter Employee name: ");
    fflush(stdin);
    gets(nameEmp);
    printf("Enter Employee age: ");
    scanf("%d",&age);
    printf("Enter Employee ID: ");
    scanf("%d",&id);
    printf("Enter Employee title: ");
    fflush(stdin);
    gets(titleEmp);

    printf("Enter Employee salary: ");
    scanf("%d",&salary);
    strcpy(search->name  , nameEmp);
    strcpy(search->title , titleEmp);
	search->age=age;
	search->salary=salary;
	search->id=id;
 }
//function View the data of an employee
//the function will take the company list address and the employee ID 
//and by using the auxiliary function search_node will get the employee 
//then it will display his data
void employee_showEmpData(companyEmpList* compEmpList,u32 id){
    employeeNode* search = search_node(compEmpList,id);
    if(search==NULL)
    {
        printf("ID value not found\n");
        return;
    }
    printf("\n*************************************************\n");
        printf("the employee name is: %s\n",search->name);
        printf("%s ID is: %d\n",search->name,search->id);
        printf("%s age is: %d\n",search->name,search->age);
        printf("%s salary is: %d\n",search->name , search->salary);
        printf("%s title is: %s\n",search->name , search->title);
}
/*********************function to delete the data of an employee*******************/
void delete_EmpData(companyEmpList* compEmpList,u32 id)
{
    if(compEmpList->head == NULL)
        return;
    employeeNode*current = compEmpList->head;
    employeeNode*prev    = compEmpList->head;
    //if the element is in the first node
    if(current->id==id)
    {
        compEmpList->head = current->next;
        free(current);
        compEmpList->size--;
        return;
    }
    while (current!=NULL &&current->id!=id)
    {
        prev = current;
        current = current->next;
    }
    if(current == NULL)
    {
        printf("value not found\n");
        return;
    }else{
        prev->next = current->next;
        free(current);
        compEmpList->size--;
    }
}
