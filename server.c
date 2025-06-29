#include "server.h"

const char *html_response = 
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: text/html\r\n"
    "\r\n"
    "<!DOCTYPE html>\n"
    "<html>\n"
    "<head>\n"
    "    <title>C Web Server</title>\n"
    "    <style>\n"
    "        body { font-family: Arial, sans-serif; margin: 40px; }\n"
    "        h1 { color: #333; }\n"
    "        .container { background: #f0f0f0; padding: 20px; border-radius: 5px; }\n"
    "    </style>\n"
    "</head>\n"
    "<body>\n"
    "    <div class='container'>\n"
    "        <h1>Hello from C Web Server!</h1>\n"
    "        <p>This page was served by your custom C web server.</p>\n"
    "        <p>Time of request: %s</p>\n"
    "    </div>\n"
    "</body>\n"
    "</html>\n";

int main() {
    int server_fd = create_socket();
    if (server_fd < 0) return 1;

    struct sockaddr_in server_addr;
    setup_address(&server_addr, NULL);  // NULL for server mode

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return 1;
    }

    if (start_listening(server_fd) < 0) {
        perror("listen failed");
        return 1;
    }

    printf("Server is listening on port %d...\n", PORT);
    
    while (1) {  // Server main loop
        struct sockaddr_in client_addr;
        int client_socket = accept_connection(server_fd, &client_addr);
        
        if (client_socket < 0) {
            printf("Failed to accept connection. Continuing...\n");
            continue;
        }

        // Receive HTTP request
        char buffer[BUFFER_SIZE];
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            printf("Received request:\n%s\n", buffer);

            // Get current time
            time_t now = time(NULL);
            char time_str[64];
            strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&now));

            // Prepare response with current time
            char response[4096];
            snprintf(response, sizeof(response), html_response, time_str);

            // Send response
            send(client_socket, response, strlen(response), 0);
        }

        close_socket(client_socket);
    }

    close_socket(server_fd);
    return 0;
}