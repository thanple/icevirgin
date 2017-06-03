#ifndef OP_SOCKET_H_  
#define OP_SOCKET_H_  
#include <stdio.h>  
#include <errno.h>  
#include <string.h>  
#include <stdlib.h>  
#include <iostream>  
#include <string>  
#ifndef WIN32  
#include <sys/types.h>  
#include <sys/wait.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>  
#include <netinet/in.h>  
#include <signal.h>  
#include <netdb.h>  
#include <unistd.h>  
#include <fcntl.h>  
#else  
#include <winsock2.h>  
#pragma comment(lib, "ws2_32.lib")  
#endif  
// Linux  
#ifndef WIN32  
#define OP_SOCKET               int  
#define OP_SOCKADDR_IN          struct sockaddr_in  
#define OP_SOCKADDR             struct sockaddr  
#define OP_SOCKLEN_T            socklen_t  
// Windows  
#else  
#define OP_SOCKET               SOCKET  
#define OP_SOCKADDR_IN          SOCKADDR_IN  
#define OP_SOCKADDR             SOCKADDR  
#define OP_SOCKLEN_T            int FAR  
#endif  
#define OP_PORT                     8080  
#define BUFFER_SIZE                 1024  
#define LISTEN_QUEUE                20  
#define MD5_SIZE                    32  
#define FILE_PATH_MAX_SIZE          512  
#define FILE_NAME_MAX_SIZE          260  
#define FILE_FULL_NAME_MAX_SIZE     1024  
#define HOST                        "localhost"  
#define DEFAULT_SERVER_IP           "127.0.0.1"  
#ifndef WIN32  
#define CLI_FILE_PATH           "/tmp/data/client/" // 客户端存储文件的初始化路径  
#define SERV_FILE_PATH          "/tmp/data/server/" // 服务器端存储文件的初始化路径  
#else  
#define CLI_FILE_PATH           "D://download//"    // 客户端存储文件的初始化路径  
#define SERV_FILE_PATH          "D://data//"        // 客户端存储文件的初始化路径  
#endif  
// 把一段内存区的内容全部设置为  
void op_clean_buffer(void *buffer, int len);
// 设置sockaddr_in, internet协议族, INADDR_ANY表示自动获取本机地址  
void op_set_sockaddr_in(OP_SOCKADDR_IN &addr, short op_sin_family, unsigned long op_s_addr, unsigned short op_sin_port);
// 创建用于internet的流协议(TCP)socket, 用server_socket代表服务器socket  
int op_socket(int domain, int type, int protocol);
// 接受一个到server_socket代表的socket的一个连接  
// 如果没有连接请求,就等待到有连接请求--这是accept函数的特性  
// accept函数返回一个新的socket, 这个socket(new_server_socket)用于同连接到的客户的通信  
// new_server_socket代表了服务器和客户端之间的一个通信通道  
// accept函数把连接到的客户端信息填写到客户端的socket地址结构client_addr中  
int op_accept(OP_SOCKET sockfd, OP_SOCKADDR *addr, OP_SOCKLEN_T *addrlen);
// IP的点分十记转化为IP的结构体  
unsigned long op_inet_addr(const char *dst);
// 向服务器发起连接,连接成功后client_socket代表了客户机和服务器的一个socket连接  
int op_connect(OP_SOCKET sockfd, const OP_SOCKADDR *addr, OP_SOCKLEN_T addrlen);
// addr指定的地址分配给与文件描述符socket关联的未命名套接字  
int op_bind(OP_SOCKET sockfd, const OP_SOCKADDR *addr, OP_SOCKLEN_T addrlen);
// 监听client请求，backlog指定最大连接数  
int op_listen(OP_SOCKET sockfd, int backlog);
// send发送消息  
int op_send(OP_SOCKET sockfd, const char *buffer, size_t len, int flags);
// recv接收消息  
int op_recv(OP_SOCKET sockfd, char *buffer, size_t len, int flags);
// 关闭socket或文件指针  
FILE* op_fopen(const char *path, const char *mode);
// 打开文件  
int op_close(OP_SOCKET sockfd);
// 关闭文件指针  
int op_fclose(FILE *stream);
// 休眠函数  
void op_sleep(int micro_seconds);
// 字符串比较函数  
int op_stricmp(char *s1, char * s2);
#endif  