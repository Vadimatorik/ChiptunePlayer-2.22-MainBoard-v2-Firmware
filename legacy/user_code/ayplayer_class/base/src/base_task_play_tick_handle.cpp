#include "base.h"

namespace AyPlayer {

void Base::playTickHandlerTask ( void* obj  ) {
	Base* o =( Base* ) obj;
	while ( true ) {
		xSemaphoreTake( o->cfg->os->sPlayTic, portMAX_DELAY );

		/// Обновляем только если в основном окне.
		if ( o->wNow == AYPLAYER_WINDOW_NOW::MAIN ) {
			o->gui->incTickPlayBarInMainWindow();
			o->gui->updateWithoutLed();
		}
	}
}

}
