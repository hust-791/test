#pragma once

class ClashCheckManager
{
public:
	static ClashCheckManager& getInstance();

	void clashCheck();

	void addMovingEntry(Entry* ent);

	void deleteMovingEntry(Entry* ent);

	void addStillEntry(Entry* ent);

	void deletestillEntry(Entry* ent);

	ClashCheckManager(const ClashCheckManager&) = delete;
	ClashCheckManager& operator=(const ClashCheckManager&) = delete;

private:
	ClashCheckManager() {}
	~ClashCheckManager() {};

	std::vector<Entry*> m_movingEntry;
	std::vector<Entry*> m_stillEntry;
};
