#include "TestComp1.h"
#include "TestComp2.h"
#include "MsgPool.h"
void printVar(TestComp1* Test1,TestComp2* Test2)
{
	std::cout << "T1.h: " << Test1->GetVar("m_height") << std::endl;
	std::cout << "T1.w: " << Test1->GetVar("m_width") << std::endl;
	std::cout << "T2.s: " << Test2->GetVar("m_slope") << std::endl;
}
int main()
{
	TestComp1 *Test1 = new TestComp1("comp1");
	TestComp2 *Test2 = new TestComp2("comp2");
	MsgPool Msgp;
	printVar(Test1, Test2);
	Msgp.AddComponent(Test1);
	Msgp.AddComponent(Test2);
	Msgp.NotifyComponent(Test1->GetMsg());
	printVar(Test1, Test2);
	Test1->SetVar("m_width", 3.0f);
	Msgp.NotifyComponent(Test1->GetMsg());
	printVar(Test1, Test2);
	getchar();
	return 0;
}