#include<stdio.h> 
#include<unistd.h>
#include<time.h>
#include<stdlib.h>

int main() {
	int is_parent, status, duration, child_that_finished;
	printf("Pre fork\n");
	
	//fork returns pid of created child process
	is_parent = fork();
	
	if (is_parent) is_parent = fork();
	
	/*
	The child process does actually have a separate memory space,
	the initial values are duplicated over, the actual memory spaces
	aren't
	
	At this point, the processes should have roughly values in is_parent:
		parent: pid of child two (cuz we overwrote the first value)
		child 1: 0
		child 2: 0
	*/
	if (!is_parent) {
		/*
		pid will be different for each process
		
		The processes will be created in quick succession
		to each other, so time(NULL) will return the same value,
		thus causing the first number generated to be the same
		*/
		srand(getpid());
		
		printf("child pid: %d\n", getpid());
		duration = rand() % 16 + 5;
		
		sleep(duration);
		printf("child is done!\n");
		
		return duration;
	}
	else {
		child_that_finished = wait(&status);
		printf("child with pid %d finished after %d seconds\n",
			child_that_finished, *( (char *)&status+1) );
		printf("parent is done\n");
	}
	
	
	return 0;
}
