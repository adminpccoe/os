GETPID
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
printf("Welcome to PCCOE%d\n" , getpid());
return(0);
}
output: gcc getpid.c -o getpid
./getpid
Welcome to PCCOE10973
FORK
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char*argr[])
{
int pid=fork();
printf("hello %d\n", pid);
return (0);
}
OP:gcc fork.c
./a.out
EXEC:
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char*argv[])
{
printf("Pid of file1.c= %d/n", getpid());
char*args[]={"Welcome to deparment of Computer", NULL};
execv("./file2",args);

printf("back to file1.c");
return(0);
}
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char*argv[])
{
printf("We are in file2.c\n");
printf("Pid of file2.c= %d\n", getpid());
return(0);
}
OP:
Gcc file1.c -o file1
Gcc file2.c -o file2
./file1.c
Wait without
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
pid_t p;
p=fork();
if(p==0)
{
int a=10;
int b=10;
int c=a*b;
printf("Multiplication is: %d\n",c);
printf("I am Child having id %d\n", getpid());
}
else
{
printf("I am parent having id %d\n", getpid());
}
printf("Hello\n");
return(0);

}
Op:gcc wait1.c
./a.out
I am parent having id 199
Hello
Multiplication is: 100
I am Child having id 200
Hello
With
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
pid_t p;
p=fork();
if(p==0)
{
int a=10;
int b=10;
int c=a*b;
printf("Multiplication is: %d\n",c);
printf("I am Child having id %d\n", getpid());
}
else
{
wait(NULL);
printf("I am parent having id %d\n", getpid());
}
printf("Hello\n");
return(0);
}
OP:gcc wait2.c
./a.out
Multiplication is: 100
I am Child having id 882
Hello
I am parent having id 881
Hello
