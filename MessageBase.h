#pragma once
#include "ComponentBase.h"
class MessageBase
{
public:
	MessageBase(){

	}
	virtual ~MessageBase(){

	}
	virtual void AddComponent(ComponentBase *pComponent) = 0;
	virtual void DeleteComponent(ComponentBase *pComponent) = 0;
	virtual void NotifyComponent(ComponentBase::Message context) = 0;
};

