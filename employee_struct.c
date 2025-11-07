#include<stdio.h>
#include <string.h>
typedef struct emp{
	int empno;
	char ename[10];
	int esal;
	int dno;
}emp;
emp read(){
	emp e;
	printf("enter the emp no:\n");
	scanf("%d",&e.empno);
	printf("enter the emp name:\n");
	scanf("%s",e.ename);//no &
	printf("enter the emp sal:\n");
	scanf("%d",&e.esal);
	printf("enter the emp dno:\n");
	scanf("%d",&e.dno);
	return e;
}
void search(int key,emp e[],int n){
	int i;
	int found =0;
	for(i=0;i<n;i++){
		if(e[i].empno == key){
		
			printf("found");
			display(e[i]);
			found = 1;
			break;
		}}
		if(found==0){
			printf("not");
		
	}
}
void sortname(emp e[],int n ){
	int i,j;
	emp temp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(strcmp(e[i].ename,e[j].ename)>0){//< 0 ? first string is smaller (comes before)0 ? strings are equal,> 0 ? first string is greater (comes after)
				temp = e[i];
				e[i]=e[j];
				e[j]=temp;
		}
		
	}
}
}
void sortsal(emp e[],int n ){
	int i,j;
	emp temp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(e[i].esal>e[j].esal) {//< 0 ? first string is smaller (comes before)0 ? strings are equal,> 0 ? first string is greater (comes after)
				temp = e[i];
				e[i]=e[j];
				e[j]=temp;
		}

	}
}
}
int delete(int key,int n,emp e[]){
	int i,j;
	int found =0;
	for(i=0;i<n;i++){
		if(e[i].empno==key){
			found =1;
			break;	
		}
	}
	if(found){
		for(j=i;j<n-1;j++){
			e[j]=e[j+1];
		}
		n--;
	printf("Employee '%d' deleted successfully.\n", e[i].empno);
    } else {
        printf("Employee '%d' not found.\n", e[i].empno);
    }
    return n;
	}

void display(emp e[]){

	printf(" the emp no :%d\n",e.empno);
	printf(" the emp name:%s\n",e.ename);
	printf(" the emp sal:%d\n",e.esal);
	printf(" the emp dno:%d\n",e.dno);
}
int main(){
	emp e[10];
	int i,n=0,key,ch;
//	printf("enter the numbr of employees\n");
//	scanf("%d",&n);
	while(1){

        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Delete Employee by Name\n");
        printf("4. Sort Employees by name (Ascending)\n");
        printf("5. search\n");
  		printf("6. sort sal\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
	
	switch(ch){
		case 1:
			e[n]=read();
			n++;
			break;
			
		case 2:
			for (i = 0; i < n; i++)
                display(e[i]);
            break;
			
		case 3:
			printf("enter the no to delete:\n");
			scanf("%d",&key);
			n=delete(key,n,e);
			break;
			
		case 4:
			printf("\nEmployees sorted by name:\n");
			sortname(e, n);
			for(i = 0; i < n; i++){
		    display(e[i]);}
		    break;
			
		
		case 5:
			printf("enter the no to search:\n");
			scanf("%d",&key);
			search(key,e,n);
			break;
		case 6:
            sortsal(e, n);
            break;
 		default:
            printf("Invalid choice. Try again.\n");
	return 0;
}
}
}

