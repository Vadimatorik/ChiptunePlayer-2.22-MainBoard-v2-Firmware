#include "module_digital_potentiometer_AD5204.h"
#include "ayplayer_mc_hardware.h"
#include "ayplayer_os_object.h"
#include "ayplayer_pcb_hardware.h"

#define AD5204_CHIP_COUNT				2

static uint8_t				ad5204Buffer[ AD5204_BUF_SIZE( AD5204_CHIP_COUNT ) ];
static ad5204chipData		ad5204StructBuffer[ AD5204_CHIP_COUNT ];

ad5204StaticCfg soundDpCfg = {
	.spi				=	&boardSpi,
	.mutex				=	&osData.mBoardSpi,
	.cs					=	&ad5204Cs,
	.shdn				=	&bdir,
	.countChip			=	AD5204_CHIP_COUNT,
	.bufOutput			=	ad5204Buffer,
	.arraySize			=	AD5204_BUF_SIZE( AD5204_CHIP_COUNT ),
	.internalStructData	=	ad5204StructBuffer
};

AD5204 soundDp( &soundDpCfg );
