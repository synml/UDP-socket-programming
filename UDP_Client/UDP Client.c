#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment (lib, "ws2_32")
#include <WinSock2.h>
#include <stdio.h>
#define SERVERIP "127.0.0.1"


//오류 메시지를 출력하고 프로그램을 종료하는 함수
void err_quit(char *msg)
{
	//에러 코드로부터 오류 메시지를 만든다.
	LPSTR msgBuf;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL,
		WSAGetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&msgBuf, 0, NULL);

	//오류 메시지를 알림창으로 띄운다.
	MessageBox(NULL, msgBuf, msg, MB_ICONERROR);

	//버퍼 메모리 반환
	LocalFree(msgBuf);

	//프로그램 종료
	exit(1);
}

//오류 메시지를 출력하는 함수
void err_display(char *msg)
{
	//에러 코드로부터 오류 메시지를 만든다.
	LPSTR msgBuf;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL,
		WSAGetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&msgBuf, 0, NULL);

	//오류 메시지를 콘솔창에 출력한다.
	printf("[%s] %s\n", msg, msgBuf);

	//버퍼 메모리 반환
	LocalFree(msgBuf);
}

int main()
{
	int retval;

	//윈속을 초기화한다.
	WSADATA wsa;
	retval = WSAStartup(MAKEWORD(2, 2), &wsa);
	if (retval != 0)
	{
		printf("WSAStartup() 오류: %d", retval);
		return 1;
	}

	//통신용 소켓을 생성한다.
	SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock == INVALID_SOCKET)
		err_quit("socket()");

	//원격 IP, Port번호를 설정한다.
	SOCKADDR_IN serveraddr = { 0 };
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(SERVERIP);
	serveraddr.sin_port = htons(50000);

	//통신에 사용할 변수를 선언한다.
	SOCKADDR_IN recvaddr;
	int addrlen = sizeof(recvaddr);
	char buffer[512] = { '\0' };

	while (1)
	{
		//송신할 데이터를 입력한다.
		printf("send: ");
		gets_s(buffer, sizeof(buffer));

		//데이터를 송신한다.
		retval = sendto(sock, buffer, (int)strlen(buffer) + 1, 0, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
		if (retval == SOCKET_ERROR)
		{
			err_display("sendto()");
			continue;
		}

		//데이터를 수신한다.
		addrlen = sizeof(recvaddr);
		retval = recvfrom(sock, buffer, sizeof(buffer), 0, (SOCKADDR *)&recvaddr, &addrlen);
		if (retval == SOCKET_ERROR)
		{
			err_display("recvfrom()");
			continue;
		}

		//송신자의 IP, Port번호를 검사한다.
		if (memcmp(&recvaddr, &serveraddr, sizeof(recvaddr)) != 0)
		{
			printf("recvfrom() 오류: 잘못된 송신자의 데이터입니다. \n");
			continue;
		}

		//받은 데이터를 출력한다.
		printf("Recv: %s\n", buffer);
	}

	//통신용 소켓을 닫는다.
	retval = closesocket(sock);
	if (retval != 0)
		err_display("closesocket()");

	//윈속을 종료한다.
	retval = WSACleanup();
	if (retval != 0)
		err_display("WSACleanup()");

	return 0;
}