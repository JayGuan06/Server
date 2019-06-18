#pragma once
#include "protocol.h"
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//typedef map<string, string> http_reposer;

//200 OK //����ɹ�, ��������Ϣ����Ӧ��Ϣ�з���
//301 Moved Permanently  //������Ķ���������Ǩ��, �µ�URL�ڱ���Ӧ��Ϣ�ģ�location����ͷ��ָ��
//400 Bad Request  //�������ܱ����������
//404 Not Found  //�������ϲ������������ĵ�
//505 HTTP Version Not Supported

enum body_type
{
	ASEC_STRING,
	ASEC_FILE,
};

class http_response
{
public:
	http_response();

	void AddStatusLineToMsg(string status_line);
	void AddHeadToMsg(string key,string value);
	void AddBodyToMsg(string body,body_type type);
	void ResposerClean();


	string operator+(string str);

	const string& GetResponse();


	~http_response();
private:
	
	string resposer;
};

