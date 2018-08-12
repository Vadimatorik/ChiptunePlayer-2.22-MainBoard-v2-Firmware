#include "ay_ym_low_lavel.h"
#include "ayplayer_os_object.h"
#include "ayplayer_mc_hardware.h"
#include "ayplayer_pcb_hardware.h"

/*!
 * Remap выводов.
 * Тут описаны соответствие бит сдвигового регистра и бит AY/YM чипов.
 * Этим компенсируется легкая разводка.
 */
ayYmConnectionChipCfg ay1ConnectCfg = { 0, 1, 2, 3, 4, 5, 6, 7 };
ayYmConnectionChipCfg ay2ConnectCfg = { 0, 1, 2, 3, 4, 5, 6, 7 };

ayYmConnectionChipCfg arrayConnectCfg[] = {
	ay1ConnectCfg,
	ay2ConnectCfg
};

void ayplayerFuncFrequencyAyControl ( bool state ) {
	( void )state;
}

void ayplayerFuncTimInterruptTask ( bool state ) {
	interruptAy.setState( state );
}

const ayYmLowLavelCfg ayLowCfg = {
	.mutex						=	nullptr,
	.ports						=	ayPorts,
	.semaphoreSecOut			=	&osData.sPlayTic,
	.bdir						=	&bdir,
	.bc1						=	&bc1,
	.queueArray					=	osData.qAyLow,
	.ayNumber					=	2,
	.connectCfg					=	arrayConnectCfg,
	.taskPrio					=	4,
	.funcFrequencyAyControl		=	ayplayerFuncFrequencyAyControl,
	.funcTimInterruptTask		=	ayplayerFuncTimInterruptTask
};

AyYmLowLavel ayLow( &ayLowCfg );
