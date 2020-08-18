#include <stdio.h> 
#include <stdlib.h> // For exit() 

int main() 
{ 
	FILE *fptr1, *fptr2; 
	char f_name[50];  // File name
   char buff[1000]; // char array to store date of one file temporarily

	printf("Enter the file name which you want to open for reading \n"); 
	scanf("%s", f_name); 

	// Open one file for reading 
	fptr1 = fopen(f_name, "r"); 
	if (fptr1 == NULL) 
	{ 
		printf("ERROR: \n Cannot open file %s .....\n", f_name); 
		exit(0); 
	} 

	printf("Enter the filename that you want to open for writing \n"); 
	scanf("%s", f_name); 

	// Open file for writing 
	fptr2 = fopen(f_name, "w"); 
	if (fptr2 == NULL) 
	{ 
		printf("ERROR: \n Cannot open file %s \n", f_name); 
		exit(0); 
	} 

	// Read contents from file 
	while (fgets(buff, 1000, fptr1)!= NULL) 
	{ 
       // writting content to the other file
		fputs(buff, fptr2); 
	} 

	printf("\nSuccessfuly copied content into %s \n", f_name); 

	fclose(fptr1); 
	fclose(fptr2); 
   
	return 0; 
}
