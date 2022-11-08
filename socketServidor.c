#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include<arpa/inet.h>


//Este es el servidor 

int main()
{
int udp_socket,lbind,tam,lrecv;
struct sockaddr_in SERVIDOR,CLIENTE;
unsigned char paqRec[100];
unsigned char msj[100] = "hello new brave world";
udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
if (udp_socket == -1)
{
perror("\nError al abrir el socket");
exit(0);
}
else
{//2=bites familia af.packed  largen link 2familia 2protocolo 4bites index familia af.inet addr internet 2familia 2para el port(puerto) 4direccion ip familiaaf.unix local familia y trayectoria funciones bind sendto recivefrom sock addr 2bites familia y un arreglo sa_data de [14]bites se acen  un cast para que entre en las funciones anteriores
perror("\nExito al abrir el socket");
SERVIDOR.sin_family=AF_INET;
SERVIDOR.sin_port=htons(8080);//Puerto efimero ya que es del cliente  por eso es 0 todos los puertos que reciben lo hacen por el puerto 53
SERVIDOR.sin_addr.s_addr=INADDR_ANY;//manual
lbind=bind(udp_socket,(struct sockaddr *)&SERVIDOR,sizeof(SERVIDOR));//manual man bind
if(lbind==-1){
perror("\nError en bind");
exit(0);
}else{
perror("\nExito bind");
tam=recvfrom(udp_socket,paqRec,512,0,(struct sockaddr *)&CLIENTE,&lrecv);
if(tam==-1){
perror("\nError al recibir");
exit(0);
}else{
printf("\nEl mensaje es :%s",paqRec);
}
}
}
close(udp_socket);
return 0;
}