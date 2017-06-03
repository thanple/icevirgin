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
#define CLI_FILE_PATH           "/tmp/data/client/" // �ͻ��˴洢�ļ��ĳ�ʼ��·��  
#define SERV_FILE_PATH          "/tmp/data/server/" // �������˴洢�ļ��ĳ�ʼ��·��  
#else  
#define CLI_FILE_PATH           "D://download//"    // �ͻ��˴洢�ļ��ĳ�ʼ��·��  
#define SERV_FILE_PATH          "D://data//"        // �ͻ��˴洢�ļ��ĳ�ʼ��·��  
#endif  
// ��һ���ڴ���������ȫ������Ϊ  
void op_clean_buffer(void *buffer, int len);
// ����sockaddr_in, internetЭ����, INADDR_ANY��ʾ�Զ���ȡ������ַ  
void op_set_sockaddr_in(OP_SOCKADDR_IN &addr, short op_sin_family, unsigned long op_s_addr, unsigned short op_sin_port);
// ��������internet����Э��(TCP)socket, ��server_socket���������socket  
int op_socket(int domain, int type, int protocol);
// ����һ����server_socket�����socket��һ������  
// ���û����������,�͵ȴ�������������--����accept����������  
// accept��������һ���µ�socket, ���socket(new_server_socket)����ͬ���ӵ��Ŀͻ���ͨ��  
// new_server_socket�����˷������Ϳͻ���֮���һ��ͨ��ͨ��  
// accept���������ӵ��Ŀͻ�����Ϣ��д���ͻ��˵�socket��ַ�ṹclient_addr��  
int op_accept(OP_SOCKET sockfd, OP_SOCKADDR *addr, OP_SOCKLEN_T *addrlen);
// IP�ĵ��ʮ��ת��ΪIP�Ľṹ��  
unsigned long op_inet_addr(const char *dst);
// ���������������,���ӳɹ���client_socket�����˿ͻ����ͷ�������һ��socket����  
int op_connect(OP_SOCKET sockfd, const OP_SOCKADDR *addr, OP_SOCKLEN_T addrlen);
// addrָ���ĵ�ַ��������ļ�������socket������δ�����׽���  
int op_bind(OP_SOCKET sockfd, const OP_SOCKADDR *addr, OP_SOCKLEN_T addrlen);
// ����client����backlogָ�����������  
int op_listen(OP_SOCKET sockfd, int backlog);
// send������Ϣ  
int op_send(OP_SOCKET sockfd, const char *buffer, size_t len, int flags);
// recv������Ϣ  
int op_recv(OP_SOCKET sockfd, char *buffer, size_t len, int flags);
// �ر�socket���ļ�ָ��  
FILE* op_fopen(const char *path, const char *mode);
// ���ļ�  
int op_close(OP_SOCKET sockfd);
// �ر��ļ�ָ��  
int op_fclose(FILE *stream);
// ���ߺ���  
void op_sleep(int micro_seconds);
// �ַ����ȽϺ���  
int op_stricmp(char *s1, char * s2);
#endif  