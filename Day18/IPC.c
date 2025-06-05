//Inter Process Communication(IPC)-Communication between two or more processes

Codes:-

		//send
		#include <stdio.h>
		#include <sys/msg.h>
		#include <sys/ipc.h>
		#define MAX 10
		//Structure for message queue
		struct mesg_buffer
		{
			long mesg_type;
			char mesg_text[100];
		}
		message;
		int main()
		{
			key_t key;
			int msgid;
			//ftok to generate unique key
			key = ftok("progfile",65);
			//msgget create a message queue and returns identifire
			msgid = msgget(key, 0666 | IPC_CREAT);
			message.mesg_type = 1;
			printf("Write Data: ");
			fgets(message.mesg_text,MAX,stdin);
			//msgsnd to send message
			msgsnd(msgid,&message,sizeof(message),0);
			//display the message
			printf("Data send is: %s \n", message.mesg_text);
			return 0;
		}

		//Receive
		#include <stdio.h>
		#include <sys/msg.h>
		#include <sys/ipc.h>
		//Structure for message queue
		struct mesg_buffer
		{
			long mesg_type;
			char mesg_text[100];	
		}
		message;
		int main()
		{
			key_t key;
			int msgid;
			//ftok to generate unique key
			key = ftok("progfile",65);
			//msgget create a message queue and returns identifire
			msgid = msgget(key, 0666 | IPC_CREAT);
			//msgrcv to receive message
			msgrcv(msgid,&message,sizeof(message),1,0);
			//display the message
			printf("Data received is: %s \n", message.mesg_text);
			//to destroy the msg queue
			msgctl(msgid, IPC_RMID, NULL);
			return 0;
		}


Output:-

		[2021ict62@fedora ~]$ touch IPCsend.c
		[2021ict62@fedora ~]$ vi IPCsend.c
		[2021ict62@fedora ~]$ gcc IPCsend.c -o IPCsend
		[2021ict62@fedora ~]$ ./IPCsend
		Write Data: Hello...!
		Data send is: Hello...!
		[2021ict62@fedora ~]$ touch IPCreceive.c
		[2021ict62@fedora ~]$ vi IPCreceive.c
		[2021ict62@fedora ~]$ gcc IPCreceive.c -o IPCreceive
		[2021ict62@fedora ~]$ ./IPCreceive
		Data received is: Hello...!


