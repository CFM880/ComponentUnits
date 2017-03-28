#pragma once
#include "ComponentBase.h"
class TestComp1 :
	public ComponentBase
{
public:
	struct TestComp1Struct
	{
		double m_width;
		double m_height;
		TestComp1Struct(){
			m_height = 10.0;
			m_width = 5.0;
		}
	};
public:
	TestComp1(string name);
	~TestComp1();
	void Update(Message msg);
	void InitMap();
	void InitStringArray();
	void InitMsg();
private:
	TestComp1Struct m_struct;
};

