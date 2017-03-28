#include "TestComp1.h"


TestComp1::TestComp1(string name) :ComponentBase(name)
{
	InitMap();
	InitStringArray();
	InitMsg();
}


TestComp1::~TestComp1()
{
}

void TestComp1::Update(Message msg)
{
	if (msg.CompName == m_name)
	{
		for (auto iter1 :msg.modifyValue)
			for (auto iter2 : m_VarMap)
			{
				if (iter2.first == iter1.first)
					*(iter2.second) = *(iter1.second);
			}
	}
}

void TestComp1::InitMap()
{
	m_VarMap.insert(std::make_pair("m_width", &(m_struct.m_width)));
	m_VarMap.insert(std::make_pair("m_height", &(m_struct.m_height)));
}

void TestComp1::InitStringArray()
{
	m_VarNameArray.push_back("m_width");
	m_VarNameArray.push_back("m_height");
}

void TestComp1::InitMsg()
{
	m_msg.CompName = m_name;
	m_msg.oldValue.insert(std::make_pair("m_width", &(m_struct.m_width)));
	m_msg.oldValue.insert(std::make_pair("m_height", &(m_struct.m_height)));
	m_msg.modifyValue.insert(std::make_pair("m_width", &(m_struct.m_width)));
	m_msg.modifyValue.insert(std::make_pair("m_height", &(m_struct.m_height)));
}
