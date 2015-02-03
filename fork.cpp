#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int MyFork(char letter);
int main(){
char tab[4];
tab[0] = 'A';
tab[1] = 'B';
tab[2] = 'C';
tab[3] = 'D';
/*for(int i=0; i< 4;i++){
cout<<tab[i]<<endl;
}/*/
/*cout<<rand()%4<<endl;
cout<<rand()%4+1<<endl;
cout<<rand()%4+1<<endl;
cout<<rand()%4+1<<endl;*/
MyFork(tab[rand()%4 ]);
MyFork(tab[rand()%4 ]);
MyFork(tab[rand()%4 ]);
MyFork(tab[rand()%4 ]);
//the four process
return 0;
}

int MyFork(char letter)
{
//cout<<letter<<endl;
int pid1 = fork();
cout<<"PID CREATED >> "<<pid1<<endl;
if(pid1 == -1){
        perror("fork failed");
exit(pid1);
}
else if(pid1 ==0){
        //child process
	for(int i = 0 ; i < 1001;i++){
	cout<<i<<":"<<letter<<"-";
		cout.flush();
	}
cout<<endl;
exit(0);
}
else{
        //parent process
        wait(NULL);
}

}
