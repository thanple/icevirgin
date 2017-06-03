
#include "MyProtoSocket.h"

#include "protocol\GameServerCMsg.pb.h"
#include "protocol\GameServerSMsg.pb.h"

OP_SOCKET MyProtoSocket::client_sockfd = NULL;
int MyProtoSocket::connect()
{
	//OP_SOCKET client_sockfd;
	OP_SOCKADDR_IN server_addr;
	OP_SOCKADDR_IN client_addr;
	char buffer[BUFFER_SIZE + 1];
	int bytes;
#ifdef WIN32  
	WSADATA  Ws;
	//Init Windows Socket  
	if (WSAStartup(MAKEWORD(2, 2), &Ws) != 0)
	{
		fprintf(stderr, "Init Windows Socket Failed::%s", GetLastError());
		return EXIT_FAILURE;
	}
#endif  
	client_sockfd = op_socket(AF_INET, SOCK_STREAM, 0);
	op_set_sockaddr_in(server_addr, AF_INET, op_inet_addr(DEFAULT_SERVER_IP), htons(OP_PORT));
	int flag = op_connect(client_sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr));

	return flag;
}


int MyProtoSocket::send(int id,string protostr)
{
	GameServerCMsg cmsg;
	cmsg.set_id(id);
	cmsg.set_msg(protostr);
	string buff = cmsg.SerializeAsString();

	//加上32位长度
	int nLen = google::protobuf::io::CodedOutputStream::VarintSize32(buff.length());
	google::protobuf::uint8 *pLen = new google::protobuf::uint8[nLen];
	google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(buff.length(), pLen);
	string st((const char *)pLen, nLen);
	st += buff;
	delete[] pLen;

	int flag = op_send(client_sockfd, st.c_str(), st.size(), 0);
	return flag;
}

void MyProtoSocket::receive()
{
	//从网络通道读取bytes
	char buffer[BUFFER_SIZE + 1];
	int nbytes = op_recv(client_sockfd, buffer, BUFFER_SIZE, 0);
	if (nbytes == -1)	return;
	buffer[nbytes] = '/0';

	//读取前int32位长度
	google::protobuf::uint32 uiLength = 0;
	google::protobuf::io::CodedInputStream is((google::protobuf::uint8 *)buffer, nbytes);
	is.ReadVarint32(&uiLength);

	//剩下的字节读到buff里
	char *pBuf = new char[uiLength];
	is.ReadRaw(pBuf, uiLength);
	string strCommonMsg(pBuf, uiLength);
	delete[] pBuf;

	//读取通用数据格式
	GameServerSMsg sMsg;
	sMsg.ParseFromString(strCommonMsg);

	//分发数据处理逻辑
	int msgId = sMsg.id();
	string data = sMsg.msg();

	std::thread threadDispatch(&Dispatch::run, msgId, data);
	threadDispatch.detach();
	//Dispatch::run(msgId, data);
}