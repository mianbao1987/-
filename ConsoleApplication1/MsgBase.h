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
	virtual bool ParseMsg(CMsgBase* pSrcMsg) = 0;		//子类自行解析协议

private:

	void Parse(CMsgBase* pSrcMsg, CMsgBase* dstMsg);
	void Register();
	string m_strMsgName;

};
