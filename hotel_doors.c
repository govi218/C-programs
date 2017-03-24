#include <stdio.h>

int main(int argc, char const *argv[])
{	
	int A[101] = {0};
	for(int i = 1; i < 101; i++) {
		for(int j = 1; j < 101; j++) {
			if((j % i) == 0){
				if(A[j] == 1) {
					A[j] = 0;
					continue;
				}
				A[j] = 1;
			}
		}
	}
	int count = 0;
	for (int i = 1; i < 101; i++) {
		if (A[i] == 0)
		{
			count++;
		}
	}
	printf("The number of doors that are closed is %d\n", count);
	return 0;
}