/*
** network.c for client in /home/loicpirez/CLionProjects/untitled/src
**
** Made by Loïc Pirez
** Login   <loic.pirez@epitech.eu>
**
** Started on  Thu Jul 13 15:28:54 2017 Loïc Pirez
** Last update Thu Jul 13 15:28:55 2017 Loïc Pirez
*/

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <args.h>
#include <error.h>

void network(t_args *args) {
    int sock;
    struct sockaddr_in server;
    char message[1000], server_reply[2000];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr(args->ip);
    server.sin_family = AF_INET;
    server.sin_port = htons(args->port);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        print_error_and_exit(ERROR_CONNECT, 84);
    }

    puts("Connected\n");

    while (1) {
        printf("Enter message : ");
        scanf("%s", message);

        //Send some data
        if (send(sock, message, strlen(message), 0) < 0) {
            puts("Send failed");
            return 1;
        }

        //Receive a reply from the server
        if (recv(sock, server_reply, 2000, 0) < 0) {
            puts("recv failed");
            break;
        }

        puts("Server reply :");
        puts(server_reply);
    }

    close(sock);
}