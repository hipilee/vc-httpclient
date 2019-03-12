#include   "stdafx.h"   
//#include   "emailsenderv2.h"   
#include   "HttpClient.h"   
 
#ifdef   _DEBUG   
#undef   THIS_FILE   
static   char   THIS_FILE[]=__FILE__;   
#define   new   DEBUG_NEW   
#endif   
 
//////////////////////////////////////////////////////////////////////   
//   Construction/Destruction   
//////////////////////////////////////////////////////////////////////   
 
CHttpClient::CHttpClient()   
{   
 
}   
 
CHttpClient::~CHttpClient()   
{   
 
}   
 
CString   CHttpClient::doGet(CString   href)   
{   
	CString   httpsource="";   
	//CInternetSession   session1(NULL,0);  
	CInternetSession session1(_T("Update 1.0"), 1,INTERNET_OPEN_TYPE_DIRECT);
	CHttpFile*   pHTTPFile=NULL;   
	try{   
		pHTTPFile=(CHttpFile*)session1.OpenURL(href);   
		//session1.   
	}catch(CInternetException){   
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
 
CString   CHttpClient::doPost(CString   href)   
{   
	CString   httpsource="";   
//	CInternetSession   session1; 
	CInternetSession session1(_T("Update 1.0"), 1,INTERNET_OPEN_TYPE_DIRECT);
	CHttpConnection*   conn1=NULL;   
	CHttpFile*   pFile   =   NULL;       
	CString   strServerName;   
	CString   strObject;   
	INTERNET_PORT   nPort;   
	DWORD   dwServiceType;   
	AfxParseURL((LPCTSTR)href,dwServiceType,   strServerName,   strObject,   nPort);   
	DWORD   retcode;               
	char*   outBuff   =   CONTENT.GetBuffer(1000);   
	try       
	{                   
		conn1   =   session1.GetHttpConnection(strServerName,nPort);           
		pFile   =   conn1->OpenRequest(0,strObject,NULL,1,NULL,"HTTP/1.1",INTERNET_FLAG_EXISTING_CONNECT|INTERNET_FLAG_NO_AUTO_REDIRECT);          
		pFile   ->   AddRequestHeaders("Content-Type:   application/x-www-form-urlencoded");           
		pFile   ->   AddRequestHeaders("Accept:   */*");                           
		pFile   ->   SendRequest(NULL,0,outBuff,strlen(outBuff)+1);                   
		pFile   ->   QueryInfoStatusCode(retcode);                   
	}                             
	catch   (CInternetException *e){};                   
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
 
	}   
	return   httpsource;   
	delete   pFile;           
	delete   conn1;           
	session1.Close();   
}   
 
void   CHttpClient::addParam(CString   name,   CString   value)   
{   
	names.AddTail((LPCTSTR)name);   
	values.AddTail((LPCTSTR)value);   
	CString   eq="=";   
	CString   an="&";   
	CONTENT=CONTENT+name+eq+value+an;   
	CL=CONTENT.GetLength();   
} 
