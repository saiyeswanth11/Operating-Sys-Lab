#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main() {

    char str[] = "Hello World";
    int len = 10;
    for(int max=0; max<=len;max++){
        int p_id = fork();
        if(p_id >0)
        {
            printf("%c %d\n", str[max], p_id);
            sleep(rand()%4 + 1);
        
        } 
        else if (p_id==0)
        {
           exit(0);
        }
        
    }
}