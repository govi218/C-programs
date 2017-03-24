#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	FILE* fstream;
	char* path = "/home/gov/Documents/test.txt";
	char* test = "This is a test input\n";
	fstream = fopen(path, "a");
	if (!fstream)
	{
		perror("nah dawg");
		return 0;
	}
	printf("fdsf\n");
	fputs(test, fstream);
	fclose(fstream);
	return 0;
}