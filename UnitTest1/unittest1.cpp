#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "MsgBase.h"
#include "MsgBus.h"
#include "MsgBusBase.h"

#include <iostream>
using namespace std;

class MyClass1 : public CMsgBase
{
public:
	MyClass1(CSingletonMsgBus* pIns) : CMsgBase(pIns) {};
	bool ParseMsg(CMsgBase* pSrcMsg);

private:

};

bool MyClass1::ParseMsg(CMsgBase* pSrcMsg)
{
	string tmp = this->GetMsgName();
	cout << tmp << endl;
	return true;
}



class MyClass2 : public CMsgBase
{
public:
	MyClass2(CSingletonMsgBus* pIns) : CMsgBase(pIns) {};
	bool ParseMsg(CMsgBase* pSrcMsg);
private:

};

bool MyClass2::ParseMsg(CMsgBase* pSrcMsg)
{
	string tmp1 = this->GetMsgName();
	string tmp2 = pSrcMsg->GetMsgName();
	//cout << tmp << endl;
	string result1 = "bbbb";
	string result2 = "aaaa";
	Assert::AreEqual(result1, tmp1);
	Assert::AreEqual(result2, tmp2);
	return true;
}



namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			CSingletonMsgBus* pIns = CSingletonMsgBus::getInstance();
			MyClass1 test1(pIns);
			MyClass2 test2(pIns);
			test1.SetMsgName("aaaa");
			test2.SetMsgName("bbbb");
			string in = "bbbb";
			//test1.SendMsg(in);
			Assert::AreEqual(true, (bool)test1.SendMsg(in));
		}

	};
}