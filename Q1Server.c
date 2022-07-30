#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
main(){
	int s,r,recb1,recb2,sntb1,sntb2,x,ns;
	printf("INPUT port number: ");
	scanf("%d",&x);
	socklen_t len;
	struct sockaddr_in server, client;
	//char buff[50];
	s=socket(AF_INET, SOCK_STREAM,0);
	if(s==-1){
		printf("\nSocket creation error");
		exit(0);
	}	
	printf("\n Socket created at port"+x);
	server.sin_family=AF_INET;
	server.sin_port=htons(x);
	server.sin_addr.s_addr=htonl(INADDR_ANY);
	r=bind(s,(struct sockaddr*)&server, sizeof(server));
	if(r==-1)
	{
		printf("\nBinding error.");
		exit(0);
	}
	printf("\nSocket Binded");
	r=listen(s,1);
	if(r==-1){
		close(s);
		exit(0);
	}
	printf("\nSocket listening");
	len=sizeof(client);
	ns=accept(s,(struct sockaddr*)&client,&len);
	if(ns==-1){
		close(s);
		exit(0);
	}
	printf("\nSocket accepting");
	int a[10];
	int ch[1];
	recb1=recv(ns,a,sizeof(a),0);
	if(recb1==-1){
		printf("\nMessage1 recieving failed");
		close(s);
		close(ns);
		exit(0);
	}
	printf("\nMessage1 Recieved");
	recb2=recv(ns,ch,sizeof(ch),0);
	if(recb2==-1){
		printf("\nMessage2 recieving failed");
		close(s);
		close(ns);
		exit(0);
	}
	printf("\nMessage2 Recieved");
	for(int i=0;i<10;i++){
		printf("%d",a[i]);
	}
	printf("%d",ch[0]);
	
	//if(ch[0]==1){		
	//}
	
	printf("\n\n");
	
	sntb1=send(ns,a,sizeof(a),0);
	if(sntb1==-1){
		printf("\nMessage1 Sending failed");
		close(s);
		close(ns);
		exit(0);
	}
	sntb2=send(ns,ch,sizeof(ch),0);
	if(sntb2==-1){
		printf("\nMessage2 Sending failed");
		close(s);
		close(ns);
		exit(0);
	}
	close(s);
	close(ns);
}
	
	
	
