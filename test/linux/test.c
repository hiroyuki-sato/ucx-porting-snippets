#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc,char *argv[]){
    int p[2];
    int status;
    pid_t pid;
    char buf[255];

    int epoll_fd;
    struct epoll_event event, event2[10];
    int nready;
    int i;

    int wstatus;

    status = pipe(p);
    if( pipe < 0 ){
        perror("pipe");
    }

    pid = fork();
    if( pid == 0 ){ /* child */
        close(p[1]); /* close write pipe */
        epoll_fd = epoll_create(10);
        if( epoll_fd < 0 ){
            perror("epoll_create");
        }

        event.events = EPOLLIN | EPOLLET; 
        event.data.fd = p[0];

        status = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, p[0], &event);
        if ( status < 0 ){
            perror("epoll_ctl");
        }
        nready = epoll_wait(epoll_fd, event2, 10, 2000);
        printf("nready: %d\n",nready);

        if( nready < 0 ){
           perror("epoll_wait");
        }

        for( i = 0 ; i < nready ; i++ ) {
           printf("nready %d\n",i);
           printf("fd %d\n",event2[i].data.fd);
           printf("p[0] %d\n",p[0]);
           if( event2[i].data.fd == p[0] ){
              printf("stdin\n");
              read(p[0],&buf,5);
              printf("%s\n",buf);
            }
        }

    } else if( pid > 0 ){ /* parent */ 
        sleep(1);
        close(p[0]); /* close read pipe */
        printf("write \n");
        write(p[1],"0123456789",10);
        wait(&status);
    } else {
        perror("fork()");
    }
    return(0);
}
