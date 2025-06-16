Code:-

		//Multi-Thread

		#include <stdio.h>
		#include <pthread.h>

		//Function to be executed by the thread
		void* print_message(void* arg)
		{
			char* message = (char*)arg;
			printf("%s\n",message);
			return NULL;
		}

		int main()
		{
			pthread_t thread1, thread2;
			
			//Create first thread
			pthread_create(&thread1, NULL, print_message,"Hello from Thread 1!");
			
			//Create second thread
			pthread_create(&thread2, NULL, print_message,"Hello from Thread 2!");
			
			//Wait for both threads to finish
			pthread_join(thread1,NULL);
			pthread_join(thread2,NULL);
			
			printf("Both threads Completed.\n");
			return 0;
			
		}

Output:-

		[2021ict62@fedora ~]$ touch multipleThread.c
		[2021ict62@fedora ~]$ vi multipleThread.c
		[2021ict62@fedora ~]$ gcc multipleThread.c -o multipleThread
		[2021ict62@fedora ~]$ ./multipleThread
		Hello from Thread 1!
		Hello from Thread 2!
		Both threads Completed.


