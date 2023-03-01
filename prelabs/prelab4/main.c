#include "prelab4.h"
#define FILENAME "emp.csv"

void Print(Employee *empArray);
int main(){
	FILE *fp = fopen(FILENAME, "r");
	Employee *empArray;
	empArray = readEmployeeArray(fp);
	
	Print(empArray);
	setEmpSalary(empArray, 2, 199020.00);
	setEmpJobType(empArray,2,15);
	printf("--------------------------------------------------------\n");
	Print(empArray);
	float x;
	int y;
	getEmpSalary(empArray, 2, &x);
	getEmpJobType(empArray, 2, &y);
	printf("%.2f\n", x);
	printf("%d\n",y);
}
	

void Print(Employee *empArray){
	for(int i = 0; i <10;i++){
		printf("EmpID: %d, Job: %d, Salary: %.2f\n", empArray[i].empID, empArray[i].jobType, empArray[i].salary);
	}
}