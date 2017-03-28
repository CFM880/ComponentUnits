#pragma once
#include <iostream>
#include <map>
#include <vector>
using std::string;
class ComponentBase
{
public:
	struct Message
	{
		string CompName;
		std::map<string, double*> modifyValue;
		std::map<string, double*> oldValue;
	};
public:
	ComponentBase(string name){
		m_name = name;
	}
	virtual ~ComponentBase(){
	
	}
	virtual void Update(Message msg) = 0;
	virtual void InitMap() = 0;
	virtual void InitStringArray() = 0;
	virtual void InitMsg() = 0;
	virtual Message GetMsg() const{
		return m_msg;
	};
	virtual string GetName()const{
		return m_name;
	}
	virtual void SetVar(string varName, double varValue)
	{
		m_msg.oldValue = m_VarMap;
		auto iter = m_VarMap.find(varName);
		if (iter != m_VarMap.end())
		{
			*(iter->second) = varValue;
			std::pair<string, double*> temp;
			temp = std::make_pair(iter->first, iter->second);
			m_msg.modifyValue.insert(temp);
		}
		else
			return;
	}
	virtual double GetVar(string varName) const
	{
		auto iter = m_VarMap.find(varName);
		if (iter != m_VarMap.end())
			return *(iter->second);
		else
			return -1.0;
	}
protected:
	string m_name;
	std::map<string, double*> m_VarMap;
	std::vector<string> m_VarNameArray;
	Message m_msg;
};

