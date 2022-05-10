#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct HangHoa
{
	char maHang[5];
	char tenHang[20];
}HangHoa;

HangHoa inputHH()
{
	HangHoa HH;
	char error[5] = "0";
	printf("nhap ma hang: "); gets(HH.maHang); 
	if (strcmp(HH.maHang,error) != 0){
		fflush(stdin);
		printf("nhap ten hang: "); gets(HH.tenHang);
	}
	return HH;
}
void readFile(FILE * fPtr) 
{
    char ch;

    do 
    {
        ch = fgetc(fPtr);

        putchar(ch);

    } while (ch != EOF);
}
int main() 
{
	FILE *inFile = NULL;
	inFile = fopen("DMHH.DAT", "a");
	if (inFile == NULL)
	{
		printf("\n khong mo duoc file \n");
		exit(1);
	}
	while(1) 
	{
		HangHoa H = inputHH();
		char error[5] = "0";
		if(strcmp(H.maHang,error) == 0) {
			break;
		}
		fwrite(&H, sizeof(struct HangHoa), 1, inFile);
	}
	if(fwrite != 0)
		printf("ghi thanh cong !!");
	else 
		printf("ghi that bai !!");
	freopen("DSHH.DAT", "r", inFile);
	readFile(inFile);
	fclose(inFile);
	return 0;
}

