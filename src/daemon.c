//
// Created by Alex on 2019-04-19.
//

#include "sniffer.h"

static void signal_handler(int sig){
    switch(sig){
        case SIGHUP:
            syslog(LOG_DEBUG, "%s", "Hangup Signal Catched");
            break;
        case SIGTERM:

            syslog(LOG_DEBUG, "%s", "Terminate Signal Catched");
            closelog();
            exit(0);
    }
}

void create_demon() {

    id_t pid = fork();

    if (pid < 0) {
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }
    if (setsid() < 0) {
        exit(EXIT_FAILURE);
    }
    umask(0);
    chdir("/");
    close(STDIN_FILENO);
    //close(STDOUT_FILENO);
    //close(STDERR_FILENO);

    signal(SIGCHLD, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);

    signal(SIGHUP,signal_handler);
    signal(SIGTERM,signal_handler);

    // и где он создается?? я хз
    openlog ("test", LOG_PID | LOG_NDELAY, LOG_DAEMON);
}