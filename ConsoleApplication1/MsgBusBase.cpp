#include "stdafx.h"
#include "MsgBusBase.h"


void CSingletonMsgBus::RegisterMsg(string& strMsgName,  CMsgBase* pMsg)
{
	m_map.insert(std::make_pair(strMsgName , pMsg));
	m_bus.Attach<CMsgBase*, CMsgBase*>(strMsgName.c_str(), &CMsgBase::Parse, pMsg);
}


bool CSingletonMsgBus::SendMsg(string & dstName, CMsgBase * pMsg)
{
	if (dstName.empty() || pMsg == NULL)
	{
		return false;
	}
	std::multimap<string, CMsgBase*>::iterator iter = m_map.find(dstName);
	CMsgBase* dst = iter->second;
	m_bus.SendReq(dstName, pMsg, dst);
	return true;
}
