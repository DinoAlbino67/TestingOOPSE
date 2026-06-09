/*********************************************************************
	Rhapsody	: 10.0.1 
	Login		: LabPOIO-29
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Keyboard
//!	Generated Date	: Tue, 9, Jun 2026  
	File Path	: DefaultComponent/DefaultConfig/Keyboard.h
*********************************************************************/

#ifndef Keyboard_H
#define Keyboard_H

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include <aom/aom.h>
//## auto_generated
#include "Default.h"
//## package Default

//## class Keyboard
class Keyboard {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedKeyboard;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Keyboard();
    
    //## auto_generated
    ~Keyboard();
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedKeyboard : virtual public AOMInstance {
    DECLARE_META(Keyboard, OMAnimatedKeyboard)
};
//#]
#endif // _OMINSTRUMENT

#endif
/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Keyboard.h
*********************************************************************/
