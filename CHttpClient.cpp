// CHttpClient.cpp : Defines the entry point for the console application.
//
#include "afx.h" 
#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include "wininet.h" 

 
/*********************�ඨ��***********************************/
class   CHttpClient      
{  
public:  
	void   addParam(CString   name,CString   value);  
	CString   doPost(CString   href);  
	CString   doGet(CString   href);  
	CHttpClient();  
	virtual   ~CHttpClient();  
private:  
	CString   CONTENT;  
	int   CL;  
	CStringList   values;  
	CStringList   names;  
};  
 
/*************************��ʵ��********************************/
// ����ֶ�
void   CHttpClient::addParam(CString   name,   CString   value)  
{  
	names.AddTail((LPCTSTR)name);  
	values.AddTail((LPCTSTR)value);  
	CString   eq="=";  
	CString   an="&";  
	CONTENT=CONTENT+name+eq+value+an;  
	CL=CONTENT.GetLength();  
}   
// ��http Get��ʽ����URL
CString   CHttpClient::doGet(CString   href)  
{  
	CString   httpsource="";  
	CInternetSession   session1(NULL,0);  
	CHttpFile*   pHTTPFile=NULL;  
	try{  
		pHTTPFile=(CHttpFile*)session1.OpenURL(href);  
		//session1.  
	}
	catch(CInternetException)
	{  
		pHTTPFile=NULL;  
	}  
	if(pHTTPFile)  
	{  
		CString   text;  
		for(int   i=0;pHTTPFile->ReadString(text);i++)  
		{  
			httpsource=httpsource+text+"\r\n";  
		}  
		pHTTPFile->Close();  
		delete   pHTTPFile;  
	}else  
	{  
		
	}  
	return   httpsource;  
}  
// ��Http Post��ʽ����URL
CString   CHttpClient::doPost(CString   href)  
{  
	CString   httpsource="";  
	CInternetSession   session1;  
	CHttpConnection*   conn1=NULL;  
	CHttpFile*   pFile   =   NULL;      
	CString   strServerName;  
	CString   strObject;  
	INTERNET_PORT   nPort;  
	DWORD   dwServiceType;  
	AfxParseURL((LPCTSTR)href, dwServiceType, strServerName, strObject, nPort);  
	DWORD   retcode;              
	char*   outBuff   =   CONTENT.GetBuffer(1000);  
	try      
	{                  
		conn1   =   session1.GetHttpConnection(strServerName, nPort);          
		pFile   =   conn1->OpenRequest(0,strObject,NULL,1,NULL,"HTTP/1.1",INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_NO_AUTO_REDIRECT);          
		pFile   ->   AddRequestHeaders("Content-Type:   application/x-www-form-urlencoded");          
		pFile   ->   AddRequestHeaders("Accept:   */*");                          
		pFile   ->   SendRequest(NULL,0,outBuff,strlen(outBuff)+1);                  
		pFile   ->   QueryInfoStatusCode(retcode);                  
	}                            
	catch   (CInternetException   *   e){};                  
	if(pFile)  
	{  
		CString   text;  
		for(int   i=0;pFile->ReadString(text);i++)  
		{  
			httpsource=httpsource+text+"\r\n";  
		}  
		pFile->Close();  
	}else  
	{  
		// do anything.....
	}  
	return   httpsource;  
	delete   pFile;          
	delete   conn1;          
	session1.Close();  
}  

--------------------- 
���ߣ�eldn__ 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/eldn__/article/details/38425037 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�

