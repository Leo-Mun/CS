#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define SEMPERM 0600
#define TRUE 1
#define FALSE 0

// semaphore union
typedef union   _semun {
             int val;
             struct semid_ds *buf;
             ushort *array;
             } semun;

// initialize semaphore (to access semaphore)
// parameter(key, set_#_of_semaphore)
int initsem (key_t semkey, int n) {
   int status = 0, semid;

   // IPC_CREAT : make new share semaphore if semaphore doesn't exist
   // IPC_EXCL : fail if semaphore exist
   if ((semid = semget (semkey, 1, SEMPERM | IPC_CREAT | IPC_EXCL)) == -1)
   {
       if (errno == EEXIST)
                semid = semget (semkey, 1, 0);
   }
   else
   {
       semun arg;
       arg.val = n;
       // set semphore count
       status = semctl(semid, 0, SETVAL, arg);
   }
   if (semid == -1 || status == -1)
   {
       perror("initsem failed");
       return (-1);
   }
   return (semid);
}

// semaphore p()
int p (int semid) {
   struct sembuf p_buf;
   p_buf.sem_num = 0;
   p_buf.sem_op = -1;
   p_buf.sem_flg = SEM_UNDO;
   if (semop(semid, &p_buf, 1) == -1)
   {
      printf("p(semid) failed");
      exit(1);
   }
   return (0);
}

// semaphore v()
int v (int semid) {
   struct sembuf v_buf;
   v_buf.sem_num = 0;
   v_buf.sem_op = 1;
   v_buf.sem_flg = SEM_UNDO;
   if (semop(semid, &v_buf, 1) == -1)
   {
      printf("v(semid) failed");
      exit(1);
   }
   return (0);
}

// Shared variable by file
void reset(char *fileVar) {
// fileVar라는 이름의 텍스트 화일을 새로 만들고 0값을 기록한다.
  // if the file didn't exist, execute reset function
  // else pass
  if( access(fileVar, F_OK) == -1) {
    FILE * fp;

    // buf to make file direction
    char buf[256];

    int value = 0;

    time_t c_time;
    time(&c_time);
  
    sprintf(buf, "/home/moon/Desktop/%s", fileVar);
    
    fp = fopen(buf, "w");

    if (fp == NULL) {
      perror("FD Error");
      exit(1);
    }
    
    fprintf(fp, "%d %d %d\n", value, getpid(), c_time);

    fclose(fp);
  }

}

void add(char *fileVar,int i) {
// fileVar 화일의 마지막 값을 읽어서 i를 더한 후에 이를 끝에 append 한다.
  FILE * fp;
  char buf[256];
  int value;

  // variables just to store last pid and time
  int tmp;
  long tmp2;

  time_t c_time;
  time(&c_time);

  sprintf(buf, "/home/moon/Desktop/%s", fileVar);
  
  fp = fopen(buf, "a+");

  if (fp == NULL) {
    perror("FD Error");
    exit(1);
  }
  while (!feof(fp)) {
    fscanf(fp, "%d %d %ld\n", &value, &tmp, &tmp2);
  }
  fprintf(fp, "%d %d %ld\n", value + i, getpid(), c_time);

  fclose(fp);

}

void sub(char *fileVar,int i) {
// fileVar 화일의 마지막 값을 읽어서 i를 뺀 후에 이를 끝에 append 한다.
  FILE * fp;
  char buf[256];
  int value;
  time_t seconds;

  // variables just to store last pid and time
  int tmp;
  long tmp2;

  time_t c_time;
  time(&c_time);

  sprintf(buf, "/home/moon/Desktop/%s", fileVar);
  
  fp = fopen(buf, "a+");

  if (fp == NULL) {
    perror("FD Error");
    exit(1);
  }
  while (!feof(fp)) {
    fscanf(fp, "%d %d %ld\n", &value, &tmp, &tmp2);
  }
  fprintf(fp, "%d %d %ld\n", value - i, getpid(), c_time );

  fclose(fp);
}

void Store(char *fileVar,int i) {
// fileVar 화일 끝에 i 값을 append한다.
  char buf[256];
  char append[2];

  append[0] = '\n'; append[1] = i;

  sprintf(buf, "/home/moon/Desktop/%s", fileVar);
  int fd = open(buf, O_RDWR | O_APPEND);
  if (fd < 0) {
    perror("FD Error");
    exit(1);
  }

  write(fd, append, 2);

  close(fd);


  
}

int Load(char *fileVar) {
// fileVar 화일의 마지막 값을 읽어 온다.

  FILE * fp;
  char buf[256];
  int value;

  // variables just to store last pid and time
  long tmp2;
  int tmp;

  sprintf(buf, "/home/moon/Desktop/%s", fileVar);
  
  fp = fopen(buf, "r+");

  if (fp == NULL) {
    perror("FD Error");
    exit(1);
  }
  while (!feof(fp)) {
    fscanf(fp, "%d %d %ld\n", &value, &tmp, &tmp2);
  }

  fclose(fp);

  return value;
}

// Class Lock
typedef struct _lock { 
   int semid;
} Lock;

void initLock(Lock *l, key_t semkey) {
   if ((l->semid = initsem(semkey,1)) < 0)    
   // 세마포를 연결한다.(없으면 초기값을 1로 주면서 새로 만들어서 연결한다.)
      exit(1);
}

void Acquire(Lock *l) {
   p(l->semid);
}

void Release(Lock *l) {

   v(l->semid);
}

// Class CondVar
typedef struct _cond {
   int semid;
   char *queueLength;
} CondVar;

void initCondVar(CondVar *c, key_t semkey, char *queueLength) {
   c->queueLength = queueLength;
   reset(c->queueLength); // queueLength=0
   if ((c->semid = initsem(semkey,0)) < 0)    
   // 세마포를 연결한다.(없으면 초기값을 0로 주면서 새로 만들어서 연결한다.)
      exit(1); 
}

// enqueue to waiting queue and wait
void Wait(CondVar *c, Lock *lock) {
   add(c -> queueLength, 1);
   Release(lock);
   p(c->semid);
   Acquire(lock);
}

// dequeue in waiting queue and wake up one thread
void Signal(CondVar *c) {
  if (Load(c->queueLength) > 0) {
    v(c->semid);
    sub(c -> queueLength, 1);
  }
}

// dequeue and wake up all threads
void Broadcast(CondVar *c) {
  while (Load(c -> queueLength) > 0) {
    v(c -> semid);
    sub(c->queueLength, 1);
  }
}

void main(int argc, char *argv[]) {
   key_t semkey1 = 0x1631040;
   key_t semkey2 = 0x1631041;
   key_t semkey3 = 0x1631042; 
   //  서버에서 작업할 때는 자기 학번 등을 이용하여 다른 사람의 키와 중복되지 않게 해야 한다.
   //  실행하기 전에 매번 세마포들을 모두 지우거나 아니면 다른 semkey 값을 사용해야 한다.
   //  $ ipcs                 // 남아 있는 세마포 확인
   //  $ ipcrm -s <semid>     // <semid>라는 세마포 제거

   int semid;
   pid_t pid;
   Lock lock;


   // State variables
   CondVar okToRead;
   CondVar okToWrite;

   // initial condition value
   initCondVar(&okToWrite, semkey1, "queueLength");
   initCondVar(&okToRead, semkey2, "queueLength");

   reset("AR");
   reset("AW");
   reset("WR");
   reset("WW");

   // int AR = Load("AR");
   // int WR = Load("WR");
   // int AW = Load("AW");
   // int WW = Load("WW");

   pid = getpid();
   initLock(&lock,semkey3);
   printf("\nprocess %d before critical section\n", pid);
   
   // sleep as soon as start
   sleep(atoi(argv[1]));
   // Writer (First check self into system)
   Acquire(&lock);   // lock.Acquire()
   printf("process %d in critical section\n",pid);

   // write or not read, break the while loop
   // wait at the beginning
   // use while to prevent read and write at the same time
   while ((Load("AW") + Load("AR")) > 0) {
      add("WW", 1); // WW++;
      Wait(&okToWrite, &lock);
      sub("WW", 1); // WW--;
   }
   add("AW", 1); // AW++;
   Release(&lock);
   sleep(atoi(argv[2]));

   // Check out of system
   Acquire(&lock);
   sub("AW", 1); // AW--;
   // wake up one waiting writer or wake up all waiting reader
   if (Load("WW") > 0) {
    Signal(&okToWrite);
   } else if (Load("WR") > 0) {
    Broadcast(&okToRead);
   }

   printf("process %d leaving critical section\n", pid);
   Release(&lock);   // lock.Release()
   printf("process %d exiting\n",pid);
   exit(0);
}