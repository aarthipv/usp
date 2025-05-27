//5.b) Write a C program using sigaction system call which calls a signal handler on SIGINT signal and then reset the default action of the SIGINT signal.
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
void s_h(int sn){
printf("\ncaught sigint %d\n",sn);
struct sigaction sa;
sa.sa_handler=SIG_DFL;
sa.sa_flags=0;
sigemptyset(&sa.sa_mask);
if(sigaction(SIGINT,&sa,NULL)==-1){
printf("error\n");
exit(EXIT_FAILURE);
}
}
int main(){
struct sigaction sa;
sa.sa_handler=s_h;
sa.sa_flags=0;
sigemptyset(&sa.sa_mask);
if(sigaction(SIGINT,&sa,NULL)==-1){
printf("error\n");
exit(EXIT_FAILURE);
}
while(1){
printf("press ctrl+c to trigger\n");
pause();
}
return 0;
}


'''
Commands to Execute:
vi program_name.c (type program here)
cc program_name.c
./a.out
Then press CTRL+C twice to show output
'''