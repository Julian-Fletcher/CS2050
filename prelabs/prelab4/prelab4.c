#include "prelab4.h"

void * createArray(int size, int dataTypeSize){
	int *array;
	array = malloc(size * dataTypeSize + sizeof(int));
	array[0] = size;
	return (void *)(array+1);
}
int getArraySize(void *array){
	return *(((int *)array) - 1);
}
void freeArray(void *array){
	free(((int *)array)-1);
}



Employee * readEmployeeArray(FILE *fp){
	if(!fp){
		return NULL;
	}
	int size;
	Employee *empArray;
	fscanf(fp, "%d", &size);
	
	empArray = createArray(size, sizeof(Employee));
	if(empArray){
		for(int i = 0; i <size;i++){
			fscanf(fp,"%d, %d, %f", &empArray[i].empID, &empArray[i].jobType, &empArray[i].salary);
		}
		return empArray;
	}
	else{
		return NULL;
	}
	return empArray;
}
	
Employee * getEmployeeByID(Employee *empArray, int empID){
	Employee * p = NULL;
	int size = getArraySize((void *)empArray);
	for(int i = 0; i <size;i++){
		if(empArray[i].empID == empID){
			p = &empArray[i];
		}
	}
	return p;
}

int setEmpSalary(Employee *empArray, int empID, float salary){
	if(!empArray){
		return 1;
	}
	Employee *emp = getEmployeeByID(empArray, empID);
	
	emp[0].salary = salary;
	return 0;
}
	
int getEmpSalary(Employee *empArray, int empID, float *salary){
	if(!empArray){
		return 1;
	}
	Employee *emp = getEmployeeByID(empArray, empID);
	*salary = emp[0].salary;
	return 0;
}


int setEmpJobType(Employee *empArray, int empID, int job){
	if(!empArray){
		return 1;
	}
	Employee *emp = getEmployeeByID(empArray, empID);
	
	emp[0].jobType = job;
	return 0;
}
int getEmpJobType(Employee *empArray, int empID, int *job){
	if(!empArray){
		return 1;
	}
	Employee *emp = getEmployeeByID(empArray, empID);
	*job = emp[0].jobType;
	return 0;
}




