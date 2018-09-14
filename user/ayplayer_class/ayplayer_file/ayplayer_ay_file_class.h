#pragma once

#include "../fat/fat.h"
#include "ay_ym_file_play.h"
#include "ay_ym_low_lavel.h"
#include "pin.h"

#define AY_YM_FILE_PLAY_FLASH_BUFFER_SIZE_BYTE				1024 * 10

/*
struct AyYmFilePlayCfg {
	AyYmLowLavel*							ayLow;
	McHardwareInterfaces::Pin*			pwr;				/// Массив выводов управления питанием всех AY.
};

class AyYmFilePlay : public AyYmFilePlayBase {
public:
	AyYmFilePlay( const AyYmFilePlayCfg* const cfg ) :
		cfg( cfg ) {}

	void	setUsingChip				(	uint32_t	chipNumber	);
	void	setPlayFileName				(	const char* fileName	);

	void	setPause					(	bool	state	);
	void	stop						(	void	);

private:
	int	openFile						(	void	);
	int	closeFile						(	void	);
	int	getFileLen						(	uint32_t&		returnFileLenByte	);
	int	setOffsetByteInFile				(	const uint32_t	offsetByte	);
	int	readInArray						(	uint8_t*		returnDataBuffer,
											const uint32_t	countByteRead	);
	int	setPwrChip						(	bool			state	);
	int	initChip						(	void	);
	int	sleepChip						(	const uint32_t	countTick	);
	int	writePacket						(	const uint8_t	reg,
											const uint8_t	data	);

	void	abort						(	void	);

private:
	const AyYmFilePlayCfg* const cfg;

	AyYmLowLavel*			ayLow;
	const char*				fileName			=	nullptr;
	FIL*					f					=	nullptr;
	uint32_t				usingChip;
	bool					flagStop;

	/// Т.к. методы зачастую читают по 1 байту, то чтобы ускорить этот процесс
	/// сразу копируется значительный кусок трека.
	__attribute__((__aligned__(4)))
	uint8_t					flashBuffer[ AY_YM_FILE_PLAY_FLASH_BUFFER_SIZE_BYTE ];

	/// Смещение, с которого было скопирован кусок.
	uint32_t				pointStartSeekBuffer;

	/// Смещение, с которого будет считан следующий байт/последовательность
	/// байт (относительно буффера).
	uint32_t				pointInBuffer;
};*/
