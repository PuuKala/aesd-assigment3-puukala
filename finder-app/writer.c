#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>

int main(int argc, char *argv[]) {

  int ret = 0;
  openlog("writer-log", LOG_CONS, LOG_USER);
  
  // Lazy check correct input
  if (argc < 3){
    printf("ERR: Not enough arguments\n");
    printf("USAGE: writer FILE STRING\n");
    syslog(LOG_ERR, "Writer error, not enough arguments");
    ret = 1;
    goto log_exit;
  }

  int fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT,
                S_IRWXU | S_IRGRP | S_IROTH);
  if (fd == -1) {
    printf("Could not open or create file %s\n", argv[1]);
    syslog(LOG_ERR, "Writer error, couldn't open file");
    ret = 1;
    goto log_exit;
  }

  ret = write(fd, argv[2], strlen(argv[2]));
  if (ret == -1) {
    printf("ERR: Writing failed!\n");
    syslog(LOG_ERR, "Writer error, write failed");
  }
  else {
    ret = 0;
    syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
  }
  close(fd);

  
log_exit:
  closelog();
  return ret;
}
