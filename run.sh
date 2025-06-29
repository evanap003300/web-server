gcc -c network.c -o build/network.o
gcc -c server.c -o build/server.o
gcc -c client.c -o build/client.o
gcc build/server.o build/network.o -o out/server
gcc build/client.o build/network.o -o out/client
