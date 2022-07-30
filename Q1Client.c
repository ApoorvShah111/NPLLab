#include <string.h>
#include <apra/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>

main(){
	int s,r, recb1,sntb1,recb2,sntb2,x;
	printf("Input port number:");
	scanf("%d",&x);
	struct cockaddr_in server;
	//char buff[50];
	s=socket(AF_INET, SOCK_STREAM,0);
	if(s==-1){
		printf("\n Socket creation error");
		exit(0);
	}
	printf("\n Socket created at port"+x);
	server.sin_family=AF_INET;
	server.sin_port=htons(x);
	server.sin_addr.s_addr=ine_addr("127.0.0.1");
	r=connect(s,(struct sockaddr*)&server, sizeof(server));
	if(r==-1)
	{
		print("\nConnection error.");
		exit(0);
	}
	printf("\nSocket connected");
	printf("\n\n");
	printf("Enter the set of integers");
	int a[10];
	for(int i=0;i<10;i++){
		scanf("%d",&a[i]);
		}
	int ch[1];
	int ch[0]=0;
	printf("Enter the choice 1:Ascending sort	2:Split to odd or even");
	scanf("%d",&ch[0]);
	sntb1=send(s,a,sizeof(a),0);
	if(sntb1==-1)
	{
		close(s);
		printf("Message1 sending Failed");
		exit(0);
	}
	recb1=recv(s,a,sizeof(a),0);
	if(recb1==-1){
		printf("\n Message1 Recieving Failed:");
		close(s);
		exit(0);
	}
	sntb2=send(s,ch,sizeof(ch),0);
	if(sntb2==-1)
	{
		close(s);
		printf("Message1 sending Failed");
		exit(0);
	}
	recb2=recv(s,ch,sizeof(ch),0);
	if(recb2==-1){
		printf("\n Message1 Recieving Failed:");
		close(s);
		exit(0);
	}
	for(int i=0;i<10;i++){
		printf("%d",a[i]);
	}
	printf("%d",ch[0]);
	printf("\n\n");
	close(s);
}

