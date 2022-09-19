#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int msum;
int csum;
void *runner(void *param);

int main(int argc, char *argv[]){
	pthread_t tid;
	pthread_attr_t  attr;
	pthread_attr_init(&attr);
	
	if(atoi(argv[1]) <= 0){
		printf("input must be number and higher than 0 \n");
		exit(0);
	}

	pthread_create(&tid, &attr, runner, argv[1]);
//	printf("waiting child \n");
	pthread_join(tid,NULL);

	int input = atoi(argv[1]);
	msum = 0;
	if(input > 0){
		for(int i = 1; i <= input; i++)
			msum += i;
		
	}
	printf("csum = %d , msum = %d \n",csum, msum );
	printf("difference = %d  \n",csum - msum );
	return 0;
}

void *runner(void *param){
	int upper = atoi(param)*2;
	int j;
	csum = 0;
	if(upper > 0){
		for(j = 1; j <= upper; j++)
			csum += j;
	}
	pthread_exit(0);
}


