#include "stdafx.h"
#include "HttpClient.h"
int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	CHttpClient conn; 
	
	//Get����ʾ��
    CString urlGet="http://127.0.0.1/swipe/in";  
    CString resGet=conn.doGet(urlGet);
	printf("Get method result is "+resGet);

    //Post����ʾ��
	CString urlPost="http://127.0.0.1/swipe/in";  

	//��Ӳ���
	conn.addParam("city","������");
    CString resPost=conn.doPost(urlPost);
	printf("Post method result is "+resPost);

	return 0;
}