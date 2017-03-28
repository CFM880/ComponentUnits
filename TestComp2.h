#pragma once
#include "ComponentBase.h"
class TestComp2 :
	public ComponentBase
{
public:
	struct TestComp2Struct
	{
		double m_slope;
		TestComp2Struct(){
			m_slope = 0.0f;
		}
	};
public:
	TestComp2(string name);
	~TestComp2();
	void Update(Message msg);
	void InitMap();
	void InitStringArray();
	void InitMsg();
private:
	TestComp2Struct m_struct;
};

