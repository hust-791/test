#pragma once

//UIøÿ÷∆¿‡
class UIControlManager
{
public:
	static UIControlManager& getUICtrl();

	void UpDataGameUI();
	void addEntry(Entry* ent);
	void deleteEntry(Entry* ent);

	UIControlManager(const UIControlManager&) = delete;
	UIControlManager& operator=(const UIControlManager&) = delete;

private:
	UIControlManager() {}
	~UIControlManager() {};

	std::vector<Entry*> m_managerEntrys;
};
