#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment (lib,"ws2_32.lib")
#include<iostream>
#include<WinSock2.h>
#include<string>
using namespace std;
int main(){
    cout <<"Atempting to create a server";

    SOCKET wsocket;
    SOCKET new_wsocket;
    struct sockaddr_in server;
    int server_len;
    int BUFFER_SIZE = 30720;

    //Initialize  --> Syntax-->

    //int WSAStartup( [in] WORD wVersionRequired, [out] LPWSADATA lpWSAData);
    
    WORD wversionRequired;
    WSADATA wsadata;
    int err;

    wversionRequired = MAKEWORD(2,2);
    err = WSAStartup(wversionRequired, &wsadata);

    if(err == 0){
        cout <<"\nWSAStartup done without err "<<err;
    }


    //Create a Socket -->Syntax -->
    //SOCKET WSAAPI socket([in] int af, [in] int type, [in] int protocol);

    wsocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(wsocket == INVALID_SOCKET){
        cout <<"Socket Craetion Failed!";
    }

    //Bind Socket to address
    //int bind([in] SOCKET s,const sockaddr *addr,[in] int namelen);

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_port = htons(5000);
    server_len = sizeof(server);

    if(bind(wsocket,(SOCKADDR *)&server , server_len) != 0){
        cout <<"Bindind Failed!";
    }

    //listening to address --> syntax-->
    //int WSAAPI listen( [in] SOCKET s,[in] int backlog);

    if(listen(wsocket,20)!= 0){
        cout <<"Could not start listening\n";
    }
    cout <<"\nListening on 127.0.0.1:5000\n";
    

    int bytes[30720];
    while(1){
        //Accept--.Syntax-->
    //SOCKET WSAAPI accept([in] SOCKET s,[out] sockaddr *addr,[in, out] int *addrlen);
        new_wsocket = accept(wsocket,(SOCKADDR*) &server, &server_len);
        if(new_wsocket == INVALID_SOCKET){
            cout <<"Could not accept connection\n";
        }

        //Read Request
        char buff[30720] = {0};
        int bytes = recv(new_wsocket,buff,BUFFER_SIZE,0);
        if(bytes < 0){
            cout <<"Could not read client request";
        }

        string serverMessage  = "HTTP/1.1 200 OK\n Content-Type : text/html\nContent-Length";
        string response = "<html><B>Hello world</B></html>";
        serverMessage.append(to_string(response.size()));
        serverMessage.append("\n\n");
        serverMessage.append(response);

    int bytesSent = 0;
    int totalBytesSent = 0;
    if(totalBytesSent < serverMessage.size()){

        //int WSAAPI send([in] SOCKET s,[in] const char *buf,[in] int len,[in] int flags);
        bytesSent = send(new_wsocket, serverMessage.c_str(), serverMessage.size(),0);
        if(bytesSent < 0){
        cout <<"Could not sent response\n";
        }
        totalBytesSent += bytesSent;
    }
    cout <<"Sent response to client\n";

    closesocket(new_wsocket);
    } 

    closesocket(wsocket);
    WSACleanup();
    return 0;
}

//Run the file -->
//./TCPserver.exe
