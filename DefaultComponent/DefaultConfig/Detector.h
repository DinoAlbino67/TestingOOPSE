/*********************************************************************
	Rhapsody	: 10.0.1 
	Login		: LabPOIO-29
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Detector
//!	Generated Date	: Tue, 9, Jun 2026  
	File Path	: DefaultComponent/DefaultConfig/Detector.h
*********************************************************************/

#ifndef Detector_H
#define Detector_H

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
//## class Detector
#include "Module.h"
//## link itsController
class Contoller;

//## package Default

//## class Detector
class Detector : public OMReactive, public Module {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedDetector;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Detector(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Detector();
    
    ////    Operations    ////
    
    //## operation check_collison()
    bool check_collison();
    
    //## operation message_0()
    void message_0();
    
    ////    Additional operations    ////
    
    //## auto_generated
    int getMargin() const;
    
    //## auto_generated
    void setMargin(int p_margin);
    
    //## auto_generated
    int getPulses_received() const;
    
    //## auto_generated
    void setPulses_received(int p_pulses_received);
    
    //## auto_generated
    int getPulses_sent() const;
    
    //## auto_generated
    void setPulses_sent(int p_pulses_sent);
    
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
    
    int margin;		//## attribute margin
    
    int pulses_received;		//## attribute pulses_received
    
    int pulses_sent;		//## attribute pulses_sent
    
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
    
    // sendaction_2:
    //## statechart_method
    inline bool sendaction_2_IN() const;
    
    // Inactive:
    //## statechart_method
    inline bool Inactive_IN() const;
    
    // Active:
    //## statechart_method
    inline bool Active_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum Detector_Enum {
        OMNonState = 0,
        sendaction_2 = 1,
        Inactive = 2,
        Active = 3
    };
    
    int rootState_subState;
    
    int rootState_active;
//#]
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedDetector : public OMAnimatedModule {
    DECLARE_REACTIVE_META(Detector, OMAnimatedDetector)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void sendaction_2_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Inactive_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Active_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline bool Detector::rootState_IN() const {
    return true;
}

inline bool Detector::sendaction_2_IN() const {
    return rootState_subState == sendaction_2;
}

inline bool Detector::Inactive_IN() const {
    return rootState_subState == Inactive;
}

inline bool Detector::Active_IN() const {
    return rootState_subState == Active;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Detector.h
*********************************************************************/
