#include "base.h"

namespace AyPlayer {

void Base::waitToInsertCorrectSdCard ( void ) {
	do {
		if ( !this->sd->getState() ) {
			const char SD_NOT_PRESENT[]	=	"SD not present!";
			this->gui->addMessage( SD_NOT_PRESENT );
			this->gui->update();

			while( !this->sd->getState() ) {
				this->printMessage( RTL_TYPE_M::RUN_MESSAGE_ISSUE, "SD not present!" );
				USER_OS_DELAY_MS( 100 );
			}
				this->gui->removeMessage();
				this->gui->update();
		}

		this->cfg->l->sendMessage( RTL_TYPE_M::INIT_OK, "SD is detected!" );

		EC_MICRO_SD_TYPE	sdInitResult;
		sdInitResult = this->cfg->pcb->sd->initialize();

		if ( sdInitResult == EC_MICRO_SD_TYPE::ERROR ) {
			this->printMessage( RTL_TYPE_M::INIT_OK, "SD was not been initialized!" );

			const char SD_NOT_INITIALIZED[]	=	"SD was not been initialized!\nRemove SD!";
			this->gui->addMessage( SD_NOT_INITIALIZED );

			this->gui->update();

			while( this->sd->getState() ) {
				USER_OS_DELAY_MS( 100 );
			}

			this->gui->removeMessage();

			continue;
		}
	} while( false );
}

}
