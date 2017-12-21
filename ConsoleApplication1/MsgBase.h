#pragma once
#include <string>
using namespace std;


class CMsgBase
{
	friend class CSingletonMsgBus;
public:

	CMsgBase();
	virtual ~CMsgBase();
	void SetMsgName(string name);
	bool SendMsg(string& dstMsgName);

	string GetMsgName() { return m_strMsgName; };

public:
	virtual bool ParseMsg(CMsgBase* pSrcMsg) = 0;		//�������н���Э��

private:

	void Parse(CMsgBase* pSrcMsg, CMsgBase* dstMsg);
	void Register();
	string m_strMsgName;

};
