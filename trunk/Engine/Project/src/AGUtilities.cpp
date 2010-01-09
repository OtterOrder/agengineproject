#include "AGUtilities.h"
#include "windows.h"

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
bool Warning(bool _test, cStr _str)
{
	if (_test)
		return false;

	OutputDebugStr("Warning : ");
	OutputDebugStr(_str);
	OutputDebugStr("\n");

	return true;
}

//------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------
u32 CRC::_mUlTable [256] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void CRC::Initialize(void)
{
	//0x04C11DB7 is the official polynomial used by PKZip, WinZip and Ethernet.
	u32 ulPolynomial = 0x04C11DB7;

	memset(&_mUlTable, 0, sizeof(_mUlTable));

	// 256 values representing ASCII character codes.
	for(s32 iCodes = 0; iCodes <= 0xFF; iCodes++)
	{
		_mUlTable[iCodes] = Reflect(iCodes, 8) << 24;

		for(s32 iPos = 0; iPos < 8; iPos++)
		{
			_mUlTable[iCodes] = (_mUlTable[iCodes] << 1) ^ ((_mUlTable[iCodes] & (1 << 31)) ? ulPolynomial : 0);
		}

		_mUlTable[iCodes] = Reflect(_mUlTable[iCodes], 32);
	}
}

//------------------------------------------------------------------------------------------------------------------------------
u32 CRC::Reflect (u32 ulReflect, const s8 cChar)
{
	u32 ulValue = 0;

	// Swap bit 0 for bit 7, bit 1 For bit 6, etc....
	for(s32 iPos = 1; iPos < (cChar + 1); iPos++)
	{
		if(ulReflect & 1)
		{
			ulValue |= (1 << (cChar - iPos));
		}
		ulReflect >>= 1;
	}

	return ulValue;
}

//------------------------------------------------------------------------------------------------------------------------------
void CRC::PartialCRC (u32* ulCRC, cStr sData, u32 ulDataLength)
{
	while(ulDataLength--)
	{
		*ulCRC = (*ulCRC >> 8) ^ _mUlTable[(*ulCRC & 0xFF) ^ *sData++];
	}
}

//------------------------------------------------------------------------------------------------------------------------------
u32 CRC::GetCRC (cStr sData)
{
	u32 ulCRC = 0xffffffff; //Initialize the CRC.

	PartialCRC(&ulCRC, sData, strlen(sData));

	return(ulCRC ^ 0xffffffff); //Finalize the CRC and return.
}