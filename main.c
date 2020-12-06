#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

int main(){

  srand(time(NULL));
  printf("This is the pre-fork message.\n");

  int f = fork();
  if (f)
    f = fork();

  if(f){
    int status;
    int pid = wait(&status);
    int time = WEXITSTATUS(status);
    printf("Child %d exited after sleeping %d seconds.\n", pid, time);
    printf("Parent finished.\n");
  }

  else{
    printf("Child pid: %d\n", getpid());
    int s = abs(rand()) % 9 + 2;
    sleep(s);
    printf("Child %d exited.\n", getpid());
    return s;
  }

  return 0;
}
