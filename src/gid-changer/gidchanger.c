#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    pid_t pid = atoi(argv[1]);
    gid_t new_gid = 3005;

    if (setresgid(new_gid, new_gid, new_gid) == -1) {
        perror("setresgid");
        return 1;
    }

    printf("GID changed successfully for PID %d\n", pid);
    return 0;
}
