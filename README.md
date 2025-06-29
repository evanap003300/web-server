# Simple C Web Server

A basic HTTP web server implementation in C that demonstrates fundamental networking concepts and socket programming.

## Project Structure

```
.
├── network.h     - Common networking function declarations and constants
├── network.c     - Implementation of common networking functions
├── server.h      - Server-specific function declarations
├── server.c      - Main server implementation
├── client.h      - Client-specific function declarations
├── client.c      - Test client implementation
├── run.sh        - Build script
└── README.md     - This file
```

## Features

- TCP/IP server-client communication
- Basic HTTP protocol implementation
- Real-time dynamic content generation
- Clean code separation with modular design
- Error handling for network operations
- Styled HTML response
- Current time display in responses

## Prerequisites

- GCC compiler
- Linux/Unix environment
- Basic understanding of C programming
- Knowledge of networking concepts (optional)

## Building the Project

Use the provided build script:

```bash
./run.sh
```

This will compile both the server and client executables in the `out` directory.

## Running the Server

After building, start the server:

```bash
./out/server
```

The server will start listening on port 8080.

## Testing

You can test the server in two ways:

1. Using a web browser:
   - Open your browser and navigate to `http://localhost:8080`
   - You should see a styled page with the current time

2. Using the test client:
   ```bash
   ./out/client
   ```
   - This will connect to the server and display the raw HTTP response

## Technical Details

### Server Features
- Listens on port 8080
- Accepts incoming TCP connections
- Processes HTTP GET requests
- Generates dynamic HTML responses
- Displays real-time server time
- Includes basic CSS styling

### Network Implementation
- Uses BSD sockets for network communication
- Implements basic HTTP/1.1 protocol
- Handles one connection at a time sequentially
- Includes proper error handling
- Uses buffer size of 1024 bytes for communication

## Code Examples

### Creating a Socket
```c
int sockfd = create_socket();
```

### Setting Up Server Address
```c
setup_address(&server_addr, NULL);  // NULL for server mode
```

### Client Connection
```c
setup_address(&server_addr, "127.0.0.1");  // Connect to localhost
```

## Future Improvements

Potential areas for enhancement:
- Multi-threading for handling multiple clients
- Support for different HTTP methods (POST, PUT, etc.)
- Static file serving
- Request routing based on URLs
- Configuration file support
- Security improvements

## Learning Outcomes

This project demonstrates:
- Socket programming in C
- HTTP protocol basics
- Server-client architecture
- Error handling in network programming
- Dynamic content generation
- Code modularity and organization

## License

This project is open source and available for educational purposes. 