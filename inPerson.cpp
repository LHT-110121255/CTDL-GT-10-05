#include <stdio.h>
#include <stdlib.h>

// a struct with 3 filelds
struct person
{
	int id;
	char fname[20];
	char lname[20];
};
// driver program
int main()
{
	FILE *infile;
	struct person input;
	
	//open person.dat for reading
	infile = fopen ("person.dat", "r");
	if (infile == NULL)
	{
		fprintf(stderr, "\nError opening file\n");
		exit(1);
	}
	
	// read file contents till end of file
	while (fread(&input, sizeof(struct person), 1, infile))
		printf("id = %d name = %s %s \n", input.id, input.fname, input.lname);	
}
