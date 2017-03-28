#pragma once
#include "MessageBase.h"
#include <vector>
class MsgPool :
	public MessageBase
{
public:
	MsgPool();
	~MsgPool();
	void AddComponent(ComponentBase *pComponent);
	void DeleteComponent(ComponentBase *pComponent);
	void NotifyComponent(ComponentBase::Message context);
private:
	std::vector<ComponentBase*> m_CompList;
	typedef std::vector<ComponentBase*>::const_iterator CompList_C_iter;
};

