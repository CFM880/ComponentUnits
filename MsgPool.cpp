#include "MsgPool.h"


MsgPool::MsgPool()
{
}


MsgPool::~MsgPool()
{
}

void MsgPool::AddComponent(ComponentBase *pComponent)
{
	m_CompList.push_back(pComponent);
}

void MsgPool::DeleteComponent(ComponentBase *pComponent)
{
	CompList_C_iter iter = m_CompList.begin();
	string name = pComponent->GetName();
	for (; iter != m_CompList.end(); ++iter)
	{
		if (name == (*iter)->GetName())
		{
			m_CompList.erase(iter);
		}
	}
}

void MsgPool::NotifyComponent(ComponentBase::Message context)
{
	CompList_C_iter iter = m_CompList.begin();
	for (; iter != m_CompList.end(); ++iter)
	{
		(*iter)->Update(context);
	}	
}
