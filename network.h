#ifndef NETWORK_H
#define NETWORK_H

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024

// Common functions
int create_socket(void);
void setup_address(struct sockaddr_in *addr, const char *ip_address);
void close_socket(int sockfd);
int start_listening(int server_fd);
int accept_connection(int server_fd, struct sockaddr_in *client_addr);

#endif