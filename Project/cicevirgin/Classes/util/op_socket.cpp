#include "op_socket.h"  
// 把一段内存区的内容全部设置为  
void op_clean_buffer(void *buffer, int len)
{
#ifndef WIN32  
	bzero(buffer, len);
#else  
	memset(buffer, 0, len);
#endif  
}
// 设置sockaddr_in  
void op_set_sockaddr_in(OP_SOCKADDR_IN &addr, short op_sin_family, unsigned long op_s_addr, unsigned short op_sin_port)
{
	op_clean_buffer(&addr, sizeof(addr));
	addr.sin_family = op_sin_family;
	addr.sin_addr.s_addr = op_s_addr;
	addr.sin_port = op_sin_port;
}
// 创建socket  
int op_socket(int domain, int type, int protocol)
{
	int sockfd;
#ifndef WIN32  
	if ((sockfd = socket(domain, type, protocol)) < 0)
#else  
	if ((sockfd = socket(domain, type, protocol)) == INVALID_SOCKET)
#endif  
	{
		fprintf(stderr, "op_socket error/n");
		exit(EXIT_FAILURE);
	}
	return sockfd;
}
// 接收客户端的socket请求  
int op_accept(OP_SOCKET sockfd, OP_SOCKADDR *addr, OP_SOCKLEN_T *addrlen)
{
	int ret;
	if ((ret = accept(sockfd, addr, addrlen)) < 0)
	{
		fprintf(stderr, "op_accept error/n");
		exit(EXIT_FAILURE);
	}
	return ret;
}
// IP的点分十记转化为IP的结构体  
unsigned long op_inet_addr(const char *dst)
{
	long ret;
	if ((ret = inet_addr(dst)) < 0)
	{
		fprintf(stderr, "op_inet_addr error for %s/n", dst);
		exit(EXIT_FAILURE);
	}
	return (unsigned long)ret;
}
// sockfd指定的套接字连接到addr指定的服务器套接字  
int op_connect(OP_SOCKET sockfd, const OP_SOCKADDR *addr, OP_SOCKLEN_T addrlen)
{
	int ret;
	if ((ret = connect(sockfd, addr, addrlen)) < 0)
	{
		fprintf(stderr, "op_connect error/n");
		exit(EXIT_FAILURE);
	}
	return ret;
}
// addr指定的地址分配给与文件描述符socket关联的未命名套接字  
int op_bind(OP_SOCKET sockfd, const OP_SOCKADDR *addr, OP_SOCKLEN_T addrlen)
{
	int ret;
	if ((ret = bind(sockfd, addr, addrlen)) < 0)
	{
		fprintf(stderr, "op_bind error/n");
		exit(EXIT_FAILURE);
	}
	return ret;
}
// 监听client请求，backlog指定最大连接数  
int op_listen(OP_SOCKET sockfd, int backlog)
{
	int ret;
	if ((ret = listen(sockfd, backlog)) < 0)
	{
		fprintf(stderr, "op_listen error/n");
		exit(EXIT_FAILURE);
	}
	return ret;
}
// send发送消息  
int op_send(OP_SOCKET sockfd, const char *buffer, size_t len, int flags)
{
	int ret;
	if ((ret = send(sockfd, buffer, len, flags)) < 0)
	{
		fprintf(stderr, "op_send error/n");
		exit(EXIT_FAILURE);
	}
	return ret;
}
// recv接收消息  
int op_recv(OP_SOCKET sockfd, char *buffer, size_t len, int flags)
{
	size_t ret;
	op_clean_buffer(buffer, len);
	if ((ret = recv(sockfd, buffer, len, flags)) < 0)
	{
		fprintf(stderr, "op_recv error/n");
		exit(EXIT_FAILURE);
	}
	return ret;
}
// 关闭socket或文件指针  
int op_close(OP_SOCKET sockfd)
{
	int ret;
#ifndef WIN32  
	if ((ret = close(sockfd)) < 0)
#else  
	if ((ret = closesocket(sockfd)) < 0)
#endif  
	{
		fprintf(stderr, "op_close error/n");
		exit(EXIT_FAILURE);
	}
	return ret;
}
// 打开文件  
FILE* op_fopen(const char *path, const char *mode)
{
	FILE *fp = fopen(path, mode);
	if (NULL == fp)
	{
		printf("File:/t%s Can Not Open To Write/n", path);
		exit(EXIT_FAILURE);
	}
	return fp;
}
// 关闭文件指针  
int op_fclose(FILE *stream)
{
	int ret;
	if ((ret = fclose(stream)) < 0)
	{
		fprintf(stderr, "op_fclose error/n");
		exit(EXIT_FAILURE);
	}
	return ret;
}
// 休眠函数，对于usleep为微秒级别，对于Sleep为毫秒级别  
void op_sleep(int micro_seconds)
{
#ifndef WIN32  
	usleep(micro_seconds);
#else  
	Sleep(micro_seconds);
#endif  
}
// 字符串比较函数  
int op_stricmp(char *s1, char * s2)
{
#ifndef WIN32  
	return strcasecmp(s1, s2);
#else  
	return stricmp(s1, s2);
#endif  
}