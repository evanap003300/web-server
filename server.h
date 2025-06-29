#ifndef SERVER_H
#define SERVER_H

#include "network.h"

// Server-specific functions
int start_listening(int server_fd);
int accept_connection(int server_fd, struct sockaddr_in *client_addr);

#endif