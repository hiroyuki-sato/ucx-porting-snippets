#include "gtest/gtest.h"

#include <string>
using std::string;

extern "C" {
#include <stdio.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/wait.h>
}

TEST(epoll_usage_test, basic_epoll) {
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

    memset(buf,0,sizeof(buf));
    pid = fork();
    if( pid == 0 ){ /* child */
        close(p[1]); /* close write pipe */
        epoll_fd = epoll_create(10);
        if( epoll_fd < 0 ){
            perror("epoll_create");
        }

        event.events = EPOLLIN; // | EPOLLET;
        event.data.fd = p[0];

        status = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, p[0], &event);
        if ( status < 0 ){
            perror("epoll_ctl");
        }

        nready = epoll_wait(epoll_fd, event2, 10, 2000);
        if( nready < 0 ){
           perror("epoll_wait");
        }

        EXPECT_EQ(1, nready);
        EXPECT_EQ(p[0], event2[0].data.fd);
        read(p[0],buf,255);
        EXPECT_STREQ("0123456789", buf);
    } else if( pid > 0 ){ /* parent */
        sleep(1);
        close(p[0]); /* close read pipe */

        write(p[1],"0123456789",10);
        wait(&status);
    } else {
        perror("fork()");
    }
}
TEST(epoll_usage_test2, use_epoll_twice) {
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

    memset(buf,0,sizeof(buf));
    pid = fork();
    if( pid == 0 ){ /* child */
        close(p[1]); /* close write pipe */
        epoll_fd = epoll_create(10);
        if( epoll_fd < 0 ){
            perror("epoll_create");
        }

        event.events = EPOLLIN; // | EPOLLET;
        event.data.fd = p[0];

        status = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, p[0], &event);
        if ( status < 0 ){
            perror("epoll_ctl");
        }

        nready = epoll_wait(epoll_fd, event2, 10, 2000);
        if( nready < 0 ){
           perror("epoll_wait");
        }

        EXPECT_EQ(1, nready);
        EXPECT_EQ(p[0], event2[0].data.fd);
        /* read five bytes only. So the buffer remain data */
        read(p[0],buf,5);

        memset(buf,0,sizeof(buf));
        nready = epoll_wait(epoll_fd, event2, 10, 2000);
        if( nready < 0 ){
           perror("epoll_wait");
        }
        EXPECT_EQ(1,nready);
        read(p[0],buf,5);
        EXPECT_STREQ("56789", buf);

    } else if( pid > 0 ){ /* parent */
        sleep(1);
        close(p[0]); /* close read pipe */

        write(p[1],"0123456789",10);
        wait(&status);
    } else {
        perror("fork()");
    }
}

TEST(epoll_usage_test3, use_epoll_twice) {
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

    memset(buf,0,sizeof(buf));
    pid = fork();
    if( pid == 0 ){ /* child */
        close(p[1]); /* close write pipe */
        epoll_fd = epoll_create(10);
        if( epoll_fd < 0 ){
            perror("epoll_create");
        }

        /* set EPOLLET together */
        event.events = EPOLLIN | EPOLLET;
        event.data.fd = p[0];

        status = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, p[0], &event);
        if ( status < 0 ){
            perror("epoll_ctl");
        }

        nready = epoll_wait(epoll_fd, event2, 10, 2000);
        if( nready < 0 ){
           perror("epoll_wait");
        }

        EXPECT_EQ(1, nready);
        EXPECT_EQ(p[0], event2[0].data.fd);
        /* read five bytes only. So the buffer remain data */
        read(p[0],buf,5);

        memset(buf,0,sizeof(buf));
        nready = epoll_wait(epoll_fd, event2, 10, 2000);
        if( nready < 0 ){
           perror("epoll_wait");
        }
        /* timeout */
        EXPECT_EQ(0,nready);

    } else if( pid > 0 ){ /* parent */
        sleep(1);
        close(p[0]); /* close read pipe */

        write(p[1],"0123456789",10);
        wait(&status);
    } else {
        perror("fork()");
    }
}
