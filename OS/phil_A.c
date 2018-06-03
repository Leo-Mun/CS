/**
- 20163104 문다민
⁃	철학자 세명 A,B,C
⁃	젓가락 세개 R1,R2,R3
⁃	각 젓가락을 Mutual Exclusive 하게 만들기 위한 Lock L1, L2, L3
⁃	젓가락이 없으면 기다리는 Condition Variable C1, C2, C3
⁃	Lock 과 Condition Variable은 앞의 숙제처럼 리눅스 커널의 세마포로 구현
⁃	R1,R2,R3는 앞의 숙제처럼 텍스트 화일(fileVar)로 구현
**/

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

    sprintf(buf, "/home/moon/Desktop/Source/%s", fileVar);
    
    fp = fopen(buf, "w");

    if (fp == NULL) {
      perror("FD Error");
      exit(1);
    }
    
    fprintf(fp, "%d\n", value);

    fclose(fp);
  }

}

void add(char *fileVar,int i) {
// fileVar 화일의 마지막 값을 읽어서 i를 더한 후에 이를 끝에 append 한다.
  FILE * fp;
  char buf[256];
  int value;

  sprintf(buf, "/home/moon/Desktop/Source/%s", fileVar);
  
  fp = fopen(buf, "a+");

  if (fp == NULL) {
    perror("FD Error");
    exit(1);
  }
  while (!feof(fp)) {
    fscanf(fp, "%d\n", &value);
  }
  fprintf(fp, "%d\n", value + i);

  fclose(fp);

}

void sub(char *fileVar,int i) {
// fileVar 화일의 마지막 값을 읽어서 i를 뺀 후에 이를 끝에 append 한다.
  FILE * fp;
  char buf[256];
  int value;
  time_t seconds;

  sprintf(buf, "/home/moon/Desktop/Source/%s", fileVar);
  
  fp = fopen(buf, "a+");

  if (fp == NULL) {
    perror("FD Error");
    exit(1);
  }
  while (!feof(fp)) {
    fscanf(fp, "%d\n", &value);
  }
  fprintf(fp, "%d\n", value - i);

  fclose(fp);
}

void Store(char *fileVar,int i) {
// fileVar 화일 끝에 i 값을 append한다.
  FILE * fp;
  char buf[256];
  int value;

  sprintf(buf, "/home/moon/Desktop/Source/%s", fileVar);
  
  fp = fopen(buf, "a+");

  if (fp == NULL) {
    perror("FD Error");
    exit(1);
  }
  while (!feof(fp)) {
    fscanf(fp, "%d\n", &value);
  }
  fprintf(fp, "%d\n", i);

  fclose(fp);


  
}

int Load(char *fileVar) {
// fileVar 화일의 마지막 값을 읽어 온다.

  FILE * fp;
  char buf[256];
  int value;

  // variables just to store last pid and time
  long tmp2;
  int tmp;

  sprintf(buf, "/home/moon/Desktop/Source/%s", fileVar);
  
  fp = fopen(buf, "r+");

  if (fp == NULL) {
    perror("FD Error");
    exit(1);
  }
  while (!feof(fp)) {
    fscanf(fp, "%d\n", &value);
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

Lock L1;
Lock L2;
Lock L3;

CondVar C1;
CondVar C2;
CondVar C3;

void Take_R1() {
   int s;

   Acquire(&L1);
   // R1이 1이면 젓가락이 있고 0이면 젓가락이 없어서 기다려야 함
   while (Load("R1") == 0) {
        // print message: getpid()가 R1을 기다림
        printf("%ld is waiting R1\n", getpid());

        Wait(&C1, &L1);

        // print message: getpid()가 R1을 기다리다가 깨어남
        printf("%ld wakes up\n", getpid());
       }
   Store("R1",0); 
   // print message: getpid()가  R1을 가져옴
   printf("%ld takes R1\n", getpid());

   Release(&L1);
}
void Take_R2() {
   int s;
   
   Acquire(&L2);
   // R2이 1이면 젓가락이 있고 0이면 젓가락이 없어서 기다려야 함
   while (Load("R2") == 0) {
        // print message: getpid()가 R2을 기다림
        printf("%ld is waiting R2\n", getpid());

        Wait(&C2, &L2);

        // print message: getpid()가 R2을 기다리다가 깨어남
        printf("%ld wakes up\n", getpid());
       }
   Store("R2",0); 
   // print message: getpid()가  R2을 가져옴
   printf("%ld takes R2\n", getpid());

   Release(&L2);
}
void Take_R3() {
   int s;

   Acquire(&L3);
   // R3이 1이면 젓가락이 있고 0이면 젓가락이 없어서 기다려야 함
   while (Load("R3") == 0) {
        // print message: getpid()가 R3을 기다림
        printf("%ld is waiting R3\n", getpid());
        
        Wait(&C3, &L3);

        // print message: getpid()가 R3을 기다리다가 깨어남
        printf("%ld wakes up\n", getpid());
       
       }
   Store("R3",0); 
   // print message: getpid()가  R3을 가져옴
   printf("%ld takes R3\n", getpid());

   Release(&L3);
}
// Take_R2(), Take_R3()도 구현

void Put_R1() {
   Acquire(&L1);
   Store("R1",1);
   Signal(&C1);
   
   // print message: getpid()가 R1을 기다림
   printf("%ld puts down the R1 chopstick\n", getpid());

   Release(&L1);
}
void Put_R2() {
   Acquire(&L2);
   Store("R2",1);
   Signal(&C2);
   
   // print message: getpid()가 R2을 기다림
   printf("%ld puts down the R2 chopstick\n", getpid());
   
   Release(&L2);
}
void Put_R3() {
   Acquire(&L3);
   Store("R3",1);
   Signal(&C3);
  
   // print message: getpid()가 R3을 기다림
   printf("%ld puts down the R3 chopstick\n", getpid());

   Release(&L3);
}

// Put_R2(), Put_R3()도 구현

void Phil_A() {
   Take_R1();
   // print message: getpid()가  생각을 시작함
   printf("%ld, A is thinking\n", getpid());
   sleep(2); // sleep()으로 구현
   
   // print message: getpid()가  생각을 멈춤
   printf("%ld, A stops thinking\n", getpid());
   Take_R2();

   // print message: getpid()가  먹기 시작함
   printf("%ld, A starts to eat\n", getpid());
   sleep(4); // sleep()으로 구현

   // print message: getpid()가  먹기를 멈춤
   printf("%ld, A stops eating\n", getpid());

   Put_R1();
   Put_R2();
}

void Phil_B() {
   Take_R2();
   // print message: getpid()가  생각을 시작함
   printf("%ld, B is thinking\n", getpid());
   sleep(2); // sleep()으로 구현
   
   // print message: getpid()가  생각을 멈춤
   printf("%ld, B stops thinking\n", getpid());
   Take_R3();

   // print message: getpid()가  먹기 시작함
   printf("%ld, B starts to eat\n", getpid());
   sleep(4); // sleep()으로 구현

   // print message: getpid()가  먹기를 멈춤
   printf("%ld, B stops eating\n", getpid());
   
   Put_R2();
   Put_R3();
}

void Phil_C() {
   Take_R1();
   // print message: getpid()가  생각을 시작함
   printf("%ld, C is thinking\n", getpid());
   sleep(2); // sleep()으로 구현
   
   // print message: getpid()가  생각을 멈춤
   printf("%ld, C stops thinking\n", getpid());
   Take_R3();

   // print message: getpid()가  먹기 시작함
   printf("%ld, C starts to eat\n", getpid());
   sleep(4); // sleep()으로 구현

   // print message: getpid()가  먹기를 멈춤
   printf("%ld, C stops eating\n", getpid());
   
   Put_R1();
   Put_R3();
}

// Phil_B(), Phil_C()도 구현


int main() {
   //  서버에서 작업할 때는 자기 학번 등을 이용하여 다른 사람의 키와 중복되지 않게 해야 한다.
   //  실행하기 전에 매번 세마포들을 모두 지우거나 아니면 다른 semkey 값을 사용해야 한다.
   //  $ ipcs                 // 남아 있는 세마포 확인
   //  $ ipcrm -s <semid>     // <semid>라는 세마포 제거

   key_t semkey1 = 0x1631040;
   key_t semkey2 = 0x1631041;
   key_t semkey3 = 0x1631042;
   key_t semkey4 = 0x1631043;
   key_t semkey5 = 0x1631044;
   key_t semkey6 = 0x1631045;

   int semid;
   pid_t pid;
      
   initLock(&L1, semkey4);
   initLock(&L2, semkey5);   
   initLock(&L3, semkey6);


   initCondVar(&C1, semkey1, "C1");
   initCondVar(&C2, semkey2, "C2");
   initCondVar(&C3, semkey3, "C3");

   reset("R1");
   reset("R2");
   reset("R3");

   if (Load("R1") == 0 && Load("R2") == 0 && Load("R3") == 0) {
     Store("R1", 1);
     Store("R2", 1);
     Store("R3", 1);  
   }


   int i;

   for(i=0;i<100;i++) 
       Phil_A();

   return 0;
}

// Phil_A, Phil_B, Phil_C 는 별도의 프로세스로 실행되어야 함
