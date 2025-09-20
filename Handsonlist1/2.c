#include <stdio.h>
#include <unistd.h>
int main(){
	while(1){
		printf("process running with pid: %d\n",getpid());
		sleep(5);
	}
	return 0;
}
