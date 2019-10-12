#include <arpa/inet.h> 
#include <bits/stdc++.h> 
#include <sys/socket.h> 
#include <unistd.h> 

using namespace std;  

// Driver code 
int main(int argc, char* argv[]) 
{ 
    int sock; 
    struct sockaddr_in server; 
    int server_reply[100]; 
    int number[100], i, temp, n;
    cin>>n; 
    for(int i = 0;i<100;i++) number[i] = INT_MAX;
    for(int i = 0;i<n;i++) cin>>number[i];
  
    // Create socket 
    sock = socket(AF_INET, SOCK_STREAM, 0); 
    if (sock == -1) { 
        printf("Could not create socket"); 
    } 
    puts("Socket created"); 
  
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    server.sin_family = AF_INET; 
    server.sin_port = htons(8880); 
  
    // Connect to remote server 
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) { 
        perror("connect failed. Error"); 
        return 1; 
    } 
  
    puts("Connected\n"); 
  
    if (send(sock, &number, 100 * sizeof(int), 0) < 0) { 
        puts("Send failed"); 
        return 1; 
    } 
  
    // Receive a reply from the server 
    if (recv(sock, &server_reply, 100 * sizeof(int), 0) < 0) { 
        puts("recv failed"); 
        return 0; 
    } 
  
    puts("Server reply :\n"); 
    for (i = 0; i < n; i++) { 
        cout<<server_reply[i]<<" "; 
    } 
    cout<<endl;
    // close the socket 
    close(sock); 
    return 0; 
} 

