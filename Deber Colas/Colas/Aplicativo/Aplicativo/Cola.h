#pragma once
#include<string.h>
class Cola
{
private:
	int num;
	int tser;
	int tespe;
	int tsal;
	int tdes;
	int tlle;
	Cola *sgt;
	Cola*ant;
public: 
	void setTlle(int num);
	int getTlle();
	void setTdes(int num);
	int getTdes();
	void setTsal(int num);
	int getTsal();
	void setTespe(int num);
	int getTespe();
	void setNum(int num);
	void setSgt(Cola *sgt);
	void setAnt(Cola*ant);
	void setTser(int num);
	int getTser();
	int getNum();
	Cola * getSgt();
	Cola *getAnt();
};
void Cola::setTlle(int tlle)
{
	this->tlle = tlle;
}
int Cola::getTlle()
{
	return tlle;
}
void Cola::setTdes(int tdes)
{
	this->tdes = tdes;
}
int Cola::getTdes()
{
	return tdes;
}
void Cola::setTsal(int tsal)
{
	this->tsal = tsal;
}
int Cola::getTsal()
{
	return tsal;
}
void Cola::setTespe(int tespe)
{
	this->tespe = tespe;
}
int Cola::getTespe()
{
	return tespe;
}
void Cola::setTser(int tser)
{
	this->tser = tser;
}
int Cola::getTser()
{
	return tser;
}
void Cola::setNum(int num)
{
	this->num = num;
}
void Cola::setSgt(Cola *sgt)
{
	this->sgt = sgt;
}
void Cola::setAnt(Cola *ant)
{
	this->ant = ant;
}
int Cola::getNum()
{
	return num;
}
Cola * Cola::getSgt()
{
	return sgt;
}
Cola * Cola::getAnt()
{
	return ant;
}


