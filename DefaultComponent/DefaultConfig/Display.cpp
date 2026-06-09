/********************************************************************
	Rhapsody	: 10.0.1 
	Login		: LabPOIO-29
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Display
//!	Generated Date	: Tue, 9, Jun 2026  
	File Path	: DefaultComponent/DefaultConfig/Display.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Display.h"
//#[ ignore
#define Default_Display_Display_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Display
Display::Display() {
    NOTIFY_CONSTRUCTOR(Display, Display(), 0, Default_Display_Display_SERIALIZE);
}

Display::~Display() {
    NOTIFY_DESTRUCTOR(~Display, true);
}

#ifdef _OMINSTRUMENT
IMPLEMENT_META_P(Display, Default, Default, false, OMAnimatedDisplay)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Display.cpp
*********************************************************************/
