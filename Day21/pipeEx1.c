Exercise 1

1). Get two inputs from user(//parent process)
	name:
	reg No:
	age:
	
	Print the output from the child(//child process)
	name: ABC
	reg No:2021/ICT/62
	age:23

Code:-

		#include <stdio.h>
		#include <stdlib.h>
		#include <unistd.h>
		#include <string.h>

		#define MSGSIZE 200

		int main() {
			int pipefd[2];
			char name[50], regno[50];
			int age;
			char msg[MSGSIZE];

			pipe(pipefd);  // Create the pipe

			pid_t pid = fork(); // Create child

			if (pid == 0) {
				// Child process
				close(pipefd[1]);  // Close write end
				char buffer[MSGSIZE];
				read(pipefd[0], buffer, MSGSIZE);  // Read from pipe
				printf("\n--- Child Process Output ---\n%s\n", buffer);
			} else {
				// Parent process
				close(pipefd[0]);  // Close read end

				printf("Enter Name: ");
				scanf("%s", name);

				printf("Enter RegNo: ");
				scanf("%s", regno);

				printf("Enter Age: ");
				scanf("%d", &age);

				// Combine inputs into one message
				snprintf(msg, MSGSIZE, "Name: %s\nReg No: %s\nAge: %d", name, regno, age);

				// Send message to child
				write(pipefd[1], msg, strlen(msg)+1);  // +1 for '\0'
			}

			return 0;
		}

Output:-

		[2021ict62@fedora ~]$ touch pipeEx1.c
		[2021ict62@fedora ~]$ vi pipeEx1.c
		[2021ict62@fedora ~]$ gcc pipeEx1.c -o pipeEx1
		[2021ict62@fedora ~]$ ./pipeEx1
		Enter Name: Navo
		Enter RegNo: 2021ICT62
		Enter Age: 23

		--- Child Process Output ---
		Name: Navo
		Reg No: 2021ICT62
		Age: 23


