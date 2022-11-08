#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <unistd.h>
#include <stdio.h>
#include<arpa/inet.h>

//Este es el cliente

int main(){
    int udp_socket,lbind,tam;
    struct sockaddr_in local, remota;
    unsigned char msj[100]="Hello brave world\n";
    udp_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if (udp_socket == -1)
    {
    perror(" \n ERROR AL ABRIR EL SOCKET");
        }
    else
    {
        perror("\n exito al abrir el socket");
            local.sin_family=AF_INET;
            local.sin_port=htons(0);
            local.sin_addr.s_addr=INADDR_ANY;
            lbind=bind(udp_socket,(struct sockaddr *)&local, sizeof(local));
            if (lbind == -1)
            {
                perror("\nerror en bind ");
            }
            else
            {
                perror("\n exito en bind");
            remota.sin_family=AF_INET;
            remota.sin_port=htons(8080); //Puerto 
            remota.sin_addr.s_addr=inet_addr("172.100.74.5"); //Mi IP
            tam=sendto(udp_socket,msj,20,0,(struct sockaddr *)&remota,sizeof(remota));
            if (tam==-1)
            {
                perror("\nerror al enviar ");
            }
            else{
             perror("\nexito al enviar");
            }
            }
    }
    close(udp_socket);
    return 0;}


/*
Practica: HAcer el chat
Pedir cadena al usuario
cliente-servidor

*/