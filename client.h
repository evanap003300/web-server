#ifndef CLIENT_H
#define CLIENT_H

#include "network.h"

// Client-specific functions
int connect_to_server(int sockfd, struct sockaddr_in *server_addr);

#endif