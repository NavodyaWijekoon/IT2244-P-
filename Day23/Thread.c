Code:-

		#include <stdio.h>
		#include <stdlib.h>
		#include <unistd.h>
		#include <pthread.h>

		//A normal C function that is executed as a thread
		//When its name is specified in pthread_create()
		void *helloWorld(void *vargp)
		{
			sleep(1);
			printf("Hello World!\n");
			return NULL;
		}

		int main()
		{
			pthread_t thread_id;
			printf("Before Thread\n");
			pthread_create(&thread_id,NULL,helloWorld,NULL);
			pthread_join(thread_id,NULL);
			printf("After Thread\n");
			exit(0);
		}

Output:-

		[2021ict62@fedora ~]$ vi thread.c
		[2021ict62@fedora ~]$ gcc thread.c -o thread
		[2021ict62@fedora ~]$ ^C
		[2021ict62@fedora ~]$ ^C
		[2021ict62@fedora ~]$ touch thread.c
		[2021ict62@fedora ~]$ vi thread.c
		[2021ict62@fedora ~]$ gcc thread.c -o thread
		[2021ict62@fedora ~]$ ./thread
		Before Thread
		Hello World!
		After Thread
