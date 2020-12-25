#include <sys/wait.h>
#include <unistd.h>
#include <iostream>
#include "include/command_checker.h"
#include "include/second_process.h"

int main() {
    int p1[2];
    int p2[2];
    pid_t pid;

    if (pipe(p1) == -1) {
        perror("Failed to Pipe");
        exit(EXIT_FAILURE);
    }

    if (pipe(p2) == -1) {
        perror("Failed to Pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        close(p1[0]);
        close(p2[1]);
        commands_applier(p1, p2);
        close(p1[1]);
        close(p2[0]);
    } else {
        close(p1[1]);
        close(p2[0]);
        commands_sender(p1, p2);
        close(p1[0]);
        close(p2[1]);
        waitpid(pid, &errno, 0);
    }
    return 0;
}
