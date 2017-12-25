// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MsgBus.h"
#include <iostream>
using namespace std;

/*
class MyStruct
{
public:
	int sss;
	MyStruct()
	{
		sss = 111;
	}
	void print()
	{
		this->sss++;
		cout << this->sss << endl;
	}
};

class A
{
public:
	void Test(int x) { cout << x << endl; }
	void GTest()
	{
		cout << "it is a test" << endl;
	}
	void HTest(int x) const
	{
		cout << "it is a HTest" << endl;
	}
	void testPara(int a, double b, bool c, MyStruct& d, char* p)
	{
		d.print();
		cout << "it is a testPara" << endl;
	}
};

void GG(int x)
{
	cout << "it is a gg" << endl;
}

void GG1()
{
	cout << "it is a GG" << endl;
}

void TestMessageBus()
{
	A a;
	MessageBus<> bus;
	bus.Attach<int>("aa", &A::Test, &a);
	int x = 3;
	bus.SendReq("aa", 3);


	bus.Attach<int, double, bool, MyStruct, char*>("sss", &A::testPara, &a);
	int aa = 3;
	double bb = 0.21;
	bool cc = true;
	MyStruct tmp;
	char* pp = "adsfasdfasdaf";
	bus.SendReq("sss", aa,bb,cc,tmp,pp);

	bus.Attach<int>("hh", &A::HTest, &a);
	bus.SendReq("hh", x);
	bus.Attach("bb", &A::GTest, &a);
	bus.SendReq("bb");

	bus.Attach<int>("gg", GG);
	bus.SendReq("gg", 3);

	bus.Attach("gg", GG1);
	bus.SendReq("gg");
}
*/

#include "MsgBusBase.h"
MessageBus<> g_bus;
CSingletonMsgBus::Object_Creator CSingletonMsgBus::_object_creator;

class MyClass1 : public CMsgBase
{
public:
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
	bool ParseMsg(CMsgBase* pSrcMsg);
private:

};

bool MyClass2::ParseMsg(CMsgBase* pSrcMsg)
{
	string tmp1 = this->GetMsgName();
	string tmp2 = pSrcMsg->GetMsgName();
	cout << tmp1 << tmp2 << endl;

	return true;
}




int main()
{
	//TestMessageBus();

	MyClass1 test1;
	MyClass2 test2;
	test1.SetMsgName("aaaa");
	test2.SetMsgName("bbbb");
	string in = "bbbb";
	test1.SendMsg(in);


    return 0;
}

