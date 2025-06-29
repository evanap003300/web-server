#include "client.h"

int main() {
    int sock = create_socket();
    if (sock < 0) return 1;

    struct sockaddr_in server_addr;
    setup_address(&server_addr, "127.0.0.1");  // Connect to localhost

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    printf("Connected to server!\n");
    
    // Send HTTP GET request
    const char *request = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n";
    send(sock, request, strlen(request), 0);
    printf("Sent request: %s\n", request);

    // Receive response
    char buffer[BUFFER_SIZE];
    int bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';  // Null terminate the string
        printf("Received response:\n%s\n", buffer);
    }
    
    close_socket(sock);
    return 0;
}