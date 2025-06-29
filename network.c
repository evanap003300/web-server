#include "network.h"

int create_socket(void) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        return -1;
    }
    return sockfd;
}

void setup_address(struct sockaddr_in *addr, const char *ip_address) {
    addr->sin_family = AF_INET;
    addr->sin_port = htons(PORT);
    if (ip_address == NULL) {
        // Server mode - accept any address
        addr->sin_addr.s_addr = INADDR_ANY;
    } else {
        // Client mode - connect to specific address
        inet_pton(AF_INET, ip_address, &addr->sin_addr);
    }
}

void close_socket(int sockfd) {
    close(sockfd);
}

int start_listening(int server_fd) {
    return listen(server_fd, 10);
}

int accept_connection(int server_fd, struct sockaddr_in *client_addr) {
    socklen_t addr_len = sizeof(*client_addr);
    int new_socket = accept(server_fd, (struct sockaddr *)client_addr, &addr_len);
    
    if (new_socket < 0) {
        perror("accept failed");
        return -1;
    }
    
    // Print client information
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(client_addr->sin_addr), client_ip, INET_ADDRSTRLEN);
    printf("New connection from %s:%d\n", client_ip, ntohs(client_addr->sin_port));
    
    return new_socket;
}