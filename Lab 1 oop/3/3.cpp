#include <stdio.h>
#include <string.h>

struct employee{
    char name[100];
    char embg[100];
    char department[100];
    int salary;
};

typedef struct employee Employee;

struct company{
    char name[100];
    int numEmployees;
    Employee employees[100];
};

typedef struct company Company;

void printEmployeesBelowAverageSalary(Company *comp, int numCompanies){
    int i,j;
    float average;
    
    for(i=0;i<numCompanies;i++)
    {
        average=0.0;
        for(j=0;j<comp[i].numEmployees;j++)
        {
            average+=comp[i].employees[j].salary;
        }
        average/=comp[i].numEmployees;
        
        for(j=0;j<comp[i].numEmployees;j++)
        {
            if(comp[i].employees[j].salary < average)
            {
                printf("%s %s %s %d\n",comp[i].employees[j].name,
                comp[i].employees[j].embg,
                comp[i].employees[j].department,
                comp[i].employees[j].salary);
            }
        }
    }
}

void printHighestSalaryEmployee(Company *comp, int numCompanies, char *department){
    int i, j, maxSalary;
    Employee highestSalaryEmployee;
    
    for(i=0;i<numCompanies;i++)
    {
        maxSalary=0;
        for(j=0;j<comp[i].numEmployees;j++)
        {
            if(strcmp(comp[i].employees[j].department, department) == 0 
            && comp[i].employees[j].salary > maxSalary)
            {
                maxSalary=comp[i].employees[j].salary;
                highestSalaryEmployee=comp[i].employees[j];
            }
        }
        printf("%s %s %s %d\n", highestSalaryEmployee.name,
        highestSalaryEmployee.embg,
        highestSalaryEmployee.department,
        highestSalaryEmployee.salary);
    }
}

int main()
{
    int numCompanies,i,j;
    char department[100];
    Company companies[100];
        
    scanf("%d", &numCompanies);
    for(i=0;i<numCompanies;i++)
    {
        scanf("%s", companies[i].name);
        scanf("%d", &companies[i].numEmployees);
        for(j=0;j<companies[i].numEmployees;j++)
        {
                scanf("%s %s %s %d", companies[i].employees[j].name,
                companies[i].employees[j].embg,
                companies[i].employees[j].department,
                &companies[i].employees[j].salary);
        }
    }
    
    scanf("%s", department);
    
    printf("Employees with salaries below the average:\n");
    printEmployeesBelowAverageSalary(companies,numCompanies);
    
    printf("Employees with highest salaries for given department: \n");
    printHighestSalaryEmployee(companies,numCompanies, department);
    
    return 0;
}
