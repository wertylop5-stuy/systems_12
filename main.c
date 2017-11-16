#include<stdio.h> 
#include<unistd.h>
#include<time.h>
#include<stdlib.h>

int main() {
	int is_parent, status, duration, child_that_finished;
	printf("Pre fork\n");
	
	is_parent = fork();
	
	//printf("post fork\n");
	
	if (!is_parent) {
		srand(time(NULL));
		
		duration = rand() % 6;
		is_parent = fork();
		if (!is_parent) {
			duration = rand() % 6;
		}
		
		sleep(duration);
		printf("child pid: %d\tduration: %d\n", getpid(), duration);
		return duration;
	}
	else {
		child_that_finished = wait(&status);
		printf("child with pid %d finished after %d seconds\n",
			child_that_finished, *( (char *)&status+1) );
	}
	
	
	return 0;
}
