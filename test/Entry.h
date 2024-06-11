#pragma once

#define TopWall 0
#define BottomWall 41
#define LeftWall 0
#define RightWall 81

#define XRange (RightWall -1)
#define YRange (BottomWall -1)

#define DefaultXpos (RightWall + 2) 
#define DefaultYpos (BottomWall - 2)

#define DefaultPos Pos(DefaultXpos,DefaultYpos)
struct Pos
{
	int x;
	int y;
	Pos(int a, int b) :x(a), y(b) {};
	Pos() { x = DefaultXpos; y = DefaultYpos; };
	bool operator==(Pos const& ps)
	{
		return(x == ps.x && y == ps.y);
	}
};


void goTo(Pos ps);

void gotoxy(int x, int y);


enum class EntryType
{
	en_None = 0,
	en_Self,
	en_Ghost,
	en_Wall,
	en_Medicine,
	en_Door,
	en_Key
};

class Entry
{
public:
	Entry(Pos ps);
	virtual void _Clash(Entry ent) {};
	void UpDataUI();

	void move(Pos ps);
	virtual void forward();
	virtual void back();
	virtual void left();
	virtual	void right();

	void recover(size_t val);
	void damage(size_t val);

private:

	virtual void __Descreption();

public:
	Pos m_pos;
	Pos m_Lastpos;
	EntryType m_type;

private:
	int m_hp;
};


class Self :public Entry
{
public:
	static Self* getInstance();

	virtual void _Clash(Entry ent) override;

	Self(const Self&) = delete;
	Self& operator=(const Self&) = delete;
private:
	Self(Pos ps);
	~Self() {};

	virtual void __Descreption() override;
};

class Wall :public Entry
{
public:
	Wall(Pos ps);
private:
	virtual void __Descreption() override;
};

class Goust :public Entry
{
public:
	Goust(Pos ps);

	virtual void _Clash(Entry ent) override;

private:
	virtual void __Descreption() override;

};