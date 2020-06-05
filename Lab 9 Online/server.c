#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define SHSIZE 100

int main(int argc,char *argv[])
{
	int shmid;
	key_t key;
	char *shm;
	char *s;
	//Let key=some ram=ndom integer
	key=9876;

	shmid=shmget(key,SHSIZE,IPC_CREAT | 0666);

	if(shmid<0)
	{
		perror("Shmget");
		exit(1);
	}

	shm=shmat(shmid,NULL,0);

	if(shm==(char *)-1)
	{
		perror("shmat");
		exit(1);
	}

	memcpy(shm,"Balakrishnan",12);

	s=shm;
	s+=12;

	*s=0;

	while(*shm!='*')
	{
		sleep(1);
	}


}