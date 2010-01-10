#pragma once

//------------------------------------------------------------------------------------------------------------------------------
class AGGame
{
public:
			 AGGame	()	{};
	virtual	~AGGame	()	{};

	virtual void	InitEngine	() =0;
	virtual void	Init		() =0;
	virtual void	Update		() =0;
	virtual void	Destroy		() =0;
};