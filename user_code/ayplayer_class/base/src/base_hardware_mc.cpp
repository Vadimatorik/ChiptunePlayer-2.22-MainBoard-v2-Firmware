#include "base.h"

namespace AyPlayer {

void Base::initHardwareMc ( void ) {
	mc_interfaces::res r;

	r = this->cfg->mcu->wdt->reinit();
	this->checkAndExit( r );

	r = this->cfg->mcu->pwr->reinit();
	this->checkAndExit( r );

	r = this->cfg->mcu->gp->reinitAllPorts();
	this->checkAndExit( r );

	this->cfg->mcu->gpio->pwr.allPwr->set(1);

	r = this->rcc->initRccFrequancyMax();
	this->checkAndExit( r );

	this->nvic.setPriorityCallsInterruptVectors();
	this->nvic.enableAllIrq();


}

}
