#include "stdafx.h"
#include "Entry.h"
#include "UIControl.h"
#include "ClashCheck.h"

using namespace std;

void goTo(Pos ps)
{
	COORD coord;
	coord.X = 2 * ps.x;
	coord.Y = ps.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = 2 * x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Entry::Entry(Pos ps) :m_pos(ps)
{
	m_Lastpos = DefaultPos;
	m_type = EntryType::en_None;
	m_hp = 10;
};

void Entry::UpDataUI()
{
	goTo(m_Lastpos);
	cout << "  ";
	goTo(m_pos);
	__Descreption();
	m_Lastpos = DefaultPos;
}

void Entry::move(Pos ps)
{
	m_Lastpos = m_pos;
	m_pos = ps;
}

void Entry::forward()
{
	if (m_pos.y > TopWall + 1)
	{
		m_Lastpos = m_pos;
		m_pos.y--;
	}
}

void Entry::back()
{
	if (m_pos.y < BottomWall - 2)
	{
		m_Lastpos = m_pos;
		m_pos.y++;
	}
}

void Entry::left()
{
	if (m_pos.x > LeftWall + 1)
	{
		m_Lastpos = m_pos;
		m_pos.x -= 1;
	}
}

void Entry::right()
{
	if (m_pos.x < RightWall - 2)
	{
		m_Lastpos = m_pos;
		m_pos.x += 1;
	}
}

void Entry::recover(size_t val)
{
	m_hp += (int)val;
}

void Entry::damage(size_t val)
{
	m_hp -= (int)val;
}

void Entry::__Descreption()
{
	cout << "  ";
}


////////////////Self////////////////

Self* Self::getInstance()
{
	static Self _instance = Pos(1, 1);
	return &_instance;
}

void Self::_Clash(Entry ent)
{
	switch (ent.m_type)
	{
	case EntryType::en_None:
	case EntryType::en_Self:
		break;

	case EntryType::en_Ghost:
	{

	}break;
	case EntryType::en_Wall:
	{
		m_pos = m_Lastpos;
		m_Lastpos = DefaultPos;
	}break;
	case EntryType::en_Medicine:
	{

	}break;
	case EntryType::en_Door:
	{

	}break;
	case EntryType::en_Key:
	{

	}break;
	default:
		break;
	}
}

Self::Self(Pos ps) :Entry(ps)
{
	m_Lastpos = DefaultPos;
	m_type = EntryType::en_Self;
	UIControlManager::getUICtrl().addEntry(this);
	ClashCheckManager::getInstance().addMovingEntry(this);
}

void Self::__Descreption()
{
	cout << "ÎÒ";
}


////////////////Wall////////////////

Wall::Wall(Pos ps) :Entry(ps)
{
	m_type = EntryType::en_Wall;
	UIControlManager::getUICtrl().addEntry(this);
	ClashCheckManager::getInstance().addStillEntry(this);
}

void Wall::__Descreption()
{
	cout << "Ç½";
}


////////////////Goust////////////////


Goust::Goust(Pos ps) :Entry(ps)
{
	m_Lastpos = DefaultPos;
	m_type = EntryType::en_Ghost;
	UIControlManager::getUICtrl().addEntry(this);
	ClashCheckManager::getInstance().addMovingEntry(this);
}

void Goust::_Clash(Entry ent)
{
}

void Goust::__Descreption()
{
	cout << "¹í";
}
