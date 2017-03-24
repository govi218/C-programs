#include<stdio.h>
int main() {
	int start = 3;
	int repeat = 4;
	// both start and repeat have been assigned values 
	for(int j = 0; j <= repeat; j++) {
		for(int i = start; i > 0; i--) {
	    	if( i == 1)
	            printf("%d Blastoff", i);
	        else
	            printf("%d ", i);
		}
	}
	return 0;
}
