// gidc
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
//通过syscall把指定的pid进程的gid改为new_gid
    // 检查当前进程是否具有更改GID的权限
    if (setgid(new_gid) == -1) {
        perror("setgid");
        return 1;
    }

    // 使用setpgid更改指定进程的GID
    if (setpgid(pid, new_gid) == -1) {
        perror("setpgid");
        return 1;
    }
    printf("GID changed successfully for PID %d\n", pid);
    return 0;
}
