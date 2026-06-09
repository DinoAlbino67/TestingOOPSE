/*********************************************************************
	Rhapsody	: 10.0.1 
	Login		: LabPOIO-29
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Receiver
//!	Generated Date	: Tue, 9, Jun 2026  
	File Path	: DefaultComponent/DefaultConfig/Receiver.h
*********************************************************************/

#ifndef Receiver_H
#define Receiver_H

//## auto_generated
#include <oxf/oxf.h>
//## auto_generated
#include <aom/aom.h>
//## auto_generated
#include "Default.h"
//## auto_generated
#include <oxf/omthread.h>
//## auto_generated
#include <oxf/omreactive.h>
//## auto_generated
#include <oxf/state.h>
//## auto_generated
#include <oxf/event.h>
//## class Receiver
#include "Module.h"
//## link itsController
class Contoller;

//## package Default

//## class Receiver
class Receiver : public OMReactive, public Module {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedReceiver;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Receiver(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Receiver();
    
    ////    Additional operations    ////
    
    //## auto_generated
    bool getSingal_ok() const;
    
    //## auto_generated
    void setSingal_ok(bool p_singal_ok);
    
    //## auto_generated
    Contoller* getItsController() const;
    
    //## auto_generated
    void setItsController(Contoller* p_Contoller);
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cleanUpRelations();
    
    ////    Attributes    ////
    
    bool singal_ok;		//## attribute singal_ok
    
    ////    Relations and components    ////
    
    Contoller* itsController;		//## link itsController
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void __setItsController(Contoller* p_Contoller);
    
    //## auto_generated
    void _setItsController(Contoller* p_Contoller);
    
    //## auto_generated
    void _clearItsController();
    
    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // validate:
    //## statechart_method
    inline bool validate_IN() const;
    
    // sendaction_4:
    //## statechart_method
    inline bool sendaction_4_IN() const;
    
    // Inactive:
    //## statechart_method
    inline bool Inactive_IN() const;
    
    // Active:
    //## statechart_method
    inline bool Active_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum Receiver_Enum {
        OMNonState = 0,
        validate = 1,
        sendaction_4 = 2,
        Inactive = 3,
        Active = 4
    };
    
    int rootState_subState;
    
    int rootState_active;
//#]
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedReceiver : public OMAnimatedModule {
    DECLARE_REACTIVE_META(Receiver, OMAnimatedReceiver)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void validate_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void sendaction_4_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Inactive_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Active_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline bool Receiver::rootState_IN() const {
    return true;
}

inline bool Receiver::validate_IN() const {
    return rootState_subState == validate;
}

inline bool Receiver::sendaction_4_IN() const {
    return rootState_subState == sendaction_4;
}

inline bool Receiver::Inactive_IN() const {
    return rootState_subState == Inactive;
}

inline bool Receiver::Active_IN() const {
    return rootState_subState == Active;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Receiver.h
*********************************************************************/
