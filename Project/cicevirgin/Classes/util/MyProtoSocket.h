
#pragma once
#include <iostream>
using namespace std;
#include "op_socket.h"

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
//protobuff¡¥Ω”lib
#pragma comment(lib, "libprotobuf.lib")  
#pragma comment(lib, "libprotoc.lib")  

#include "server\Dispatch.h"

#include "cocos2d.h"


class MyProtoSocket
{
private:
	static OP_SOCKET client_sockfd;
	

public:
	static int connect();
	static int send(int id,string protostr);
	static void receive();

};
