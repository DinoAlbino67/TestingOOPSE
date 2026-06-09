/********************************************************************
	Rhapsody	: 10.0.1 
	Login		: LabPOIO-29
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Keyboard
//!	Generated Date	: Tue, 9, Jun 2026  
	File Path	: DefaultComponent/DefaultConfig/Keyboard.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Keyboard.h"
//#[ ignore
#define Default_Keyboard_Keyboard_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Keyboard
Keyboard::Keyboard() {
    NOTIFY_CONSTRUCTOR(Keyboard, Keyboard(), 0, Default_Keyboard_Keyboard_SERIALIZE);
}

Keyboard::~Keyboard() {
    NOTIFY_DESTRUCTOR(~Keyboard, true);
}

#ifdef _OMINSTRUMENT
IMPLEMENT_META_P(Keyboard, Default, Default, false, OMAnimatedKeyboard)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Keyboard.cpp
*********************************************************************/
