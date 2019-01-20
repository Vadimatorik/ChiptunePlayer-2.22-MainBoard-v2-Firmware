#pragma once

#include "module_digital_potentiometer_ad5204.h"
#include "shift_register_base.h"
#include "shift_register_8bit_port.h"
#include "shift_register_pin.h"
#include "microsd_card_sdio.h"
#include "mono_lcd_lib_st7565.h"
#include "ay_ym_low_lavel.h"
#include "ay_ym_file_play.h"
#include "ltc6903.h"

extern ShiftRegister::Base boardShiftRegisters;
extern MicrosdSdio sd;
extern MonoLcd::ST7565 lcd;
extern DigitalPotentiometer::AD5204 soundDp;
extern AyYmLowLavel ayLow;

extern ShiftRegister::Pin pwrAy[2];
extern ShiftRegister::Pin ay1Res;
extern ShiftRegister::Pin ay2Res;
extern ShiftRegister::Pin bc1;
extern ShiftRegister::Pin bdir;
extern ShiftRegister::Pin shdn;

extern McHardwareInterfaces::Port8bit *ayPorts[2];

extern WaveGenerators::LTC6903 ltc;
