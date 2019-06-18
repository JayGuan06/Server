#pragma once

/*
LSX MSG format
#app protocol
 
 base:
	 ------------------------------------------------------
	|  package_num(4B)   |   msg_id(4B)     |   body(nB)   |
	 ------------------------------------------------------
1.
1001:�ͻ���֪ͨ��������Ҫ������������     :1001
1002:������֪ͨ�ͻ��˿��Է�����������
1003:�ͻ��˷�����������                  :һ��������800B
1004:�ͻ��˷����������ݽ���
	 --------------------------------------------------------------------------------------
	|  package_num(4B)   |   msg_id(4B)   |    body(nB)   |    ack(4B)(1:finaish 0:error)  |
	 --------------------------------------------------------------------------------------
	
1005:������֪ͨ�ͻ����������ݽ������
	 --------------------------------------------------------------------------------------
	|  package_num(4B)   |   msg_id(4B)   |    body(nB)   |    ack(4B)(1:finaish 0:error)  |
	 --------------------------------------------------------------------------------------

1007:Ԥ�� �ͻ��˷���������֤
1008:Ԥ�� �ͻ��˷���ȷ��������֤


*/
#include <iostream>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

//struct _MSG;
//using LSX_MSG = struct _MSG;
//DYNAMIC



typedef struct _MSG
{
	char *head;			//msg head  not used
	char **msg_arr;		//all msg complete
}LXS_MSG;

typedef struct _HEADER LSX_HEADER;

class CProtocol
{
public:
	CProtocol() {};

	virtual LXS_MSG &GetMsg() = 0;

	/*
	@���������Ϣ��
	@����1����Ϣ�洢��ָ��
	@����2�������Ϣ������
	@����3���齨��Ϣ��ʼλ��
	@����4���齨��Ϣ����λ��
	*/

	//virtual void AddHeadToMsg(char* msg_ptr, int msg_id, int msg_length) = 0;

	virtual void AddHeadToMsg(char* msg_ptr, void*header_prt) = 0;					
	virtual void AddBodyToMsg(char * msg_pt, char *byte, int begin, int end) = 0;	

	/*
	@������Ϣ
	*/
	virtual void ProtocolParser(char * data) = 0;

	/*
	@�����м���Э��
	*/
	virtual void SetMsgSize(int size) = 0;//msg num
	/*
	@��������ÿһ����Ϣ
	@����1����Ϣid
	@����2����Ϣ����
	@����3����Ϣ��
	//��ǰЭ��֮��������Ϣ�� ��Э��
	*/
	virtual void InsertMsg(int msg_id, int msg_length) = 0;
	virtual void InsertMsg(int msg_id,int msg_length,char * body) = 0;
	virtual void InsertMsg(int msg_id, int msg_length, int body) = 0;

	/*
	@����������Ϣͷ 8�ֽ� ����С+��Ϣid
	@����1����Ϣ�洢��ָ��
	@����2����Ϣid
	@����3����Ϣ����
	*/

	virtual ~CProtocol() {};

};


class APPProtocolIMPL;
class APPProtocol:public CProtocol
{
public:
	APPProtocol();

	virtual LXS_MSG &GetMsg();
	/*
	@���������Ϣ��
	@����1����Ϣ�洢��ָ��
	@����2�������Ϣ������
	@����3���齨��Ϣ��ʼλ��
	@����4���齨��Ϣ����λ��
	*/
	//virtual void AddHeadToMsg(char* msg_ptr, int msg_id, int msg_length);

	virtual void AddHeadToMsg(char* msg_ptr, void*header_prt);
	virtual void AddBodyToMsg(char * msg_pt, char *byte, int begin, int end);

	/*
	@������Ϣ
	*/
	virtual void ProtocolParser(char * data);

	/*
	@�����м���Э��
	*/
	virtual void SetMsgSize(int size);//msg num
	/*
	@��������ÿһ����Ϣ
	@����1����Ϣid
	@����2����Ϣ����
	@����3����Ϣ��
	//��ǰЭ��֮��������Ϣ�� ��Э��
	*/
	virtual void InsertMsg(int msg_id, int msg_length);
	virtual void InsertMsg(int msg_id,int msg_length,char * body);
	virtual void InsertMsg(int msg_id, int msg_length, int body);

	/*
	@����������Ϣͷ 8�ֽ� ����С+��Ϣid
	@����1����Ϣ�洢��ָ��
	@����2����Ϣid
	@����3����Ϣ����
	*/

	virtual ~APPProtocol();
private:
	APPProtocolIMPL * _impl;

};


