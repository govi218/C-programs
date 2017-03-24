#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char** first, char** second) {
	char* temp = *first;
//	strcpy(temp, first);
//	strcpy(first, second);
//	strcpy(second, temp);
//	temp = first;
//	printf("sdvg\n");
	*first = *second;
	*second = temp;
//	free(temp);
}

int main() {
	char* animal1 = "dog";
	char* animal2 = "cat";
	swap(&animal1, &animal2);
	printf("%s %s\n", animal1, animal2);
	return 0;
}
