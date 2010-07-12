#pragma once

//------------------------------------------------------------------------------------------------------------------------------
typedef 	unsigned char		u8;
typedef 	signed char			s8;
typedef 	unsigned short		u16;
typedef 	signed short		s16;
typedef 	unsigned int		u32;
typedef 	signed int			s32;

typedef 	const char*			cStr;

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
struct AGVector2s
{
	s32 x;
	s32 y;

	AGVector2s ()				{ x=0;  y=0; };
	AGVector2s (s32 _x, s32 _y) { x=_x; y=_y; };

	inline void	 operator = (const AGVector2s& _v)		{ x = _v.x; y = _v.y; };
};

//------------------------------------------------------------------------------------------------------------------------------
struct AGVector2u
{
	u32 x;
	u32 y;

	AGVector2u ()				{ x=0;  y=0; };
	AGVector2u (u32 _x, u32 _y) { x=_x; y=_y; };

	inline void	 operator = (const AGVector2u& _v)		{ x = _v.x; y = _v.y; };
};