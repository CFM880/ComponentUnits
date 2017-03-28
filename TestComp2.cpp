#include "TestComp2.h"


TestComp2::TestComp2(string name) :ComponentBase(name)
{
	InitMap();
	InitStringArray();
	InitMsg();
}


TestComp2::~TestComp2()
{
}

void TestComp2::Update(Message msg)
{
	if (msg.CompName == "comp1")
	{
		auto hpos = msg.modifyValue.find("m_height");
		auto wpos = msg.modifyValue.find("m_width");
		double w = -1.0f;
		double h = -1.0f;
		bool hb = (hpos != msg.modifyValue.end());
		bool wb = (wpos!=msg.modifyValue.end());
		if (hb&&wb)
		{
			h = *(hpos->second);
			w = *(wpos->second);
			m_struct.m_slope = w / h;
			m_msg.modifyValue.insert(std::make_pair("m_slope", &m_struct.m_slope));
		}
		else if (hb || wb)
		{
			if (hb)
			{
				h = *(hpos->second);
				w = *(m_msg.oldValue.find("m_width")->second);
				m_struct.m_slope = w / h;
				m_msg.modifyValue.insert(std::make_pair("m_slope", &m_struct.m_slope));
			}
			if (wb)
			{
				w = *(hpos->second);
				h = *(m_msg.oldValue.find("m_height")->second);
				m_struct.m_slope = w / h;
				m_msg.modifyValue.insert(std::make_pair("m_slope", &m_struct.m_slope));
			}
				
		}
			

	}
}

void TestComp2::InitMap()
{
	m_VarMap.insert(std::make_pair("m_slope", &m_struct.m_slope));
}

void TestComp2::InitStringArray()
{
	m_VarNameArray.push_back("m_slope");
}

void TestComp2::InitMsg()
{
	m_msg.CompName = m_name;
	m_msg.oldValue.insert(std::make_pair("m_slope", &m_struct.m_slope));
	m_msg.modifyValue.insert(std::make_pair("m_slope", &m_struct.m_slope));
}
