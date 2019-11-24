#include <stdio.h>
#include <stdlib.h>
#include <lib.h>

int getgroup(int pid){
  message m;
  m.m1_i1 = pid;
  return _syscall(MM, GETGROUP, &m);
}

void setgroup(int pid, char group){
  message m;
  m.m1_i1 = pid;
  m.m1_i2 = group;
  _syscall(MM, SETGROUP, &m);
}

int main(int argc, char* argv[])
{
  pid_t pid = getpid();
  int group;
  
  if (argc != 2){
    printf("Error: Lack of inputs", argv[0]);
    return 0;
  }
  
  group = atoi(argv[1]);
  if (group <0 || group > 2){
    printf("Error: Invalid group code\n");
    return 0;
  }
  
  setgroup(pid, group);
  group = getgroup(pid);
  printf("Process' (pid=%d) group '%d'\n", pid, group);
  
  while (1);
  return 0;
}
