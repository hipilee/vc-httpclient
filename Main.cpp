#include "stdafx.h"
#include "HttpClient.h"
int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	CHttpClient conn; 
	
	//Get方法示例
    CString urlGet="http://127.0.0.1/swipe/in";  
    CString resGet=conn.doGet(urlGet);
	printf("Get method result is "+resGet);

    //Post方法示例
	CString urlPost="http://127.0.0.1/swipe/in";  

	//添加参数
	conn.addParam("city","徐州市");
    CString resPost=conn.doPost(urlPost);
	printf("Post method result is "+resPost);

	return 0;
}