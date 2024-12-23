#include "HSMSActive.h"
#include "HSMSPassive.h"
#include "TCPServer.h"
#include "TCPClient.h"
int main()
{
	HSMSActive t;
	HSMSPassive s;
	s.open(1235);
	Sleep(100);
	t.connect("127.0.0.1", 1235);
	Sleep(100);
	s.sendRequest(HSMS_SESSION::SELECT_REQ, 0);
	while (1)
	{
		Sleep(1000);
		s.sendData("HSMS_TEST", 0);
		if (s.sendRequest(HSMS_SESSION::LINKTEST_REQ, 0)) std::cerr << "LINKTEST SUCCESS" << std::endl;
	}
	return 0;
}