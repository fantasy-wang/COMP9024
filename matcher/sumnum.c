#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	if (argc > 1){
		int i , n;
		int sum = 0;
		for(i = 1; i < argc; i++){
			fprintf(stderr, "error: argument %s is not non-numeric\n", argv[i]);
			return 1;
		}
		sum = sum + n;
		printf("%d\n", sum);
	}

	return 1;

}