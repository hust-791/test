#include "stdafx.h"
#include "Entry.h"
#include "UIControl.h"

 UIControlManager& UIControlManager::getUICtrl()
{
	static UIControlManager _instance;
	return _instance;
}

void UIControlManager::UpDataGameUI()
{
	for (auto& ent : m_managerEntrys)
	{
		if (ent)
			ent->UpDataUI();
	}
}

void UIControlManager::addEntry(Entry* ent)
{
	m_managerEntrys.push_back(ent);
}

void UIControlManager::deleteEntry(Entry* ent)
{
	auto it = std::find(m_managerEntrys.begin(), m_managerEntrys.end(), ent);
	if (it != m_managerEntrys.end())
		m_managerEntrys.erase(it);
}
