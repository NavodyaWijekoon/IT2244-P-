Code:-

		#include <stdio.h>
		#include <stdlib.h>
		#include <unistd.h>
		#define MSGSIZE 16

		char* msg1 = "Hello, World #1";
		char* msg2 = "Hello, World #2";
		char* msg3 = "Hello, World #3";

		int main()
		{
			char inbuf[MSGSIZE];
			int p[2], i;
			
			if(pipe(p)<0)
				exit(1);
			
			//Continued
			//Write pipe
			
			write(p[1], msg1, MSGSIZE); // write(fileds,message,message size)
			write(p[1], msg2, MSGSIZE);
			write(p[1], msg3, MSGSIZE);
			
			for(i=0;i<3;i++)
			{
				//Read pipe
				read(p[0], inbuf, MSGSIZE); // read(fileds,message,message size)
				printf("%s\n", inbuf);
			}
			return 0;
		}

Output:- 

		[2021ict62@fedora ~]$ touch pipe.c
		[2021ict62@fedora ~]$ vi pipe.c
		[2021ict62@fedora ~]$ gcc pipe.c -o pipe
		[2021ict62@fedora ~]$ ./pipe
		Hello, World #1
		Hello, World #2
		Hello, World #3


