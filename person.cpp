#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a struct read && write
typedef struct person
{
	int id;
	char fname[20];
	char lname[20];
}person;

person inputPerson()
{
	person p;
	printf("Nhap ID: "); scanf("%d", &p.id);
	fflush(stdin);
	printf("Nhap fist name: "); gets(p.fname);
	fflush(stdin);
	printf("Nhap last name: "); gets(p.lname);
	return p;
}

int main() 
{
	FILE *outfile;
	// open file for writting 
	outfile = fopen("person.dat", "a");
	if (outfile == NULL)
	{
		fprintf(stderr, "\nError opened file\n");
		exit(1);
	}
//	person input1 = {1, "rohan", "sharma"};
//	person input2 = {2, "mahendra", "dhoni"};
	person input = inputPerson();
	//write struct to file
//	fwrite (&input1, sizeof(struct person), 1, outfile);
//	fwrite (&input2, sizeof(struct person), 1, outfile);
	fwrite (&input, sizeof(struct person), 1, outfile);
	if (fwrite != 0)
		printf("contents to file written successfully !\\n");
	else
		printf("error writting file !\n");
	// close file
	fclose(outfile);
	return 0;
}

