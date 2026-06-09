/*********************************************************************
	Rhapsody	: 10.0.1 
	Login		: LabPOIO-29
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Contoller
//!	Generated Date	: Tue, 9, Jun 2026  
	File Path	: DefaultComponent/DefaultConfig/Contoller.h
*********************************************************************/

#ifndef Contoller_H
#define Contoller_H

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
//## classInstance itsDetector
#include "Detector.h"
//## classInstance itsDisplay
#include "Display.h"
//## classInstance itsDrive
#include "Drive.h"
//## classInstance itsKeyboard
#include "Keyboard.h"
//## classInstance itsLamp
#include "Lamp.h"
//## classInstance itsReceiver
#include "Receiver.h"
//## package Default

//## class Contoller
class Contoller : public OMReactive {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedContoller;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Contoller(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Contoller();
    
    ////    Additional operations    ////
    
    //## auto_generated
    int getParams() const;
    
    //## auto_generated
    void setParams(int p_params);
    
    //## auto_generated
    float getPosition() const;
    
    //## auto_generated
    void setPosition(float p_position);
    
    //## auto_generated
    float getPosition_max() const;
    
    //## auto_generated
    void setPosition_max(float p_position_max);
    
    //## auto_generated
    float getPosition_min() const;
    
    //## auto_generated
    void setPosition_min(float p_position_min);
    
    //## auto_generated
    States getState() const;
    
    //## auto_generated
    void setState(States p_state);
    
    //## auto_generated
    States getState0() const;
    
    //## auto_generated
    void setState0(States p_state0);
    
    //## auto_generated
    bool getState_indication() const;
    
    //## auto_generated
    void setState_indication(bool p_state_indication);
    
    //## auto_generated
    Detector* getItsDetector() const;
    
    //## auto_generated
    Display* getItsDisplay() const;
    
    //## auto_generated
    Drive* getItsDrive() const;
    
    //## auto_generated
    Keyboard* getItsKeyboard() const;
    
    //## auto_generated
    Lamp* getItsLamp() const;
    
    //## auto_generated
    Receiver* getItsReceiver() const;
    
    //## auto_generated
    virtual bool startBehavior();

protected :

    //## auto_generated
    void initRelations();
    
    //## auto_generated
    void initStatechart();
    
    //## auto_generated
    void cancelTimeouts();
    
    //## auto_generated
    bool cancelTimeout(const IOxfTimeout* arg);
    
    ////    Attributes    ////
    
    int params;		//## attribute params
    
    float position;		//## attribute position
    
    float position_max;		//## attribute position_max
    
    float position_min;		//## attribute position_min
    
    States state;		//## attribute state
    
    States state0;		//## attribute state0
    
    bool state_indication;		//## attribute state_indication
    
    ////    Relations and components    ////
    
    Detector itsDetector;		//## classInstance itsDetector
    
    Display itsDisplay;		//## classInstance itsDisplay
    
    Drive itsDrive;		//## classInstance itsDrive
    
    Keyboard itsKeyboard;		//## classInstance itsKeyboard
    
    Lamp itsLamp;		//## classInstance itsLamp
    
    Receiver itsReceiver;		//## classInstance itsReceiver
    
    ////    Framework operations    ////

public :

    //## auto_generated
    void setActiveContext(IOxfActive* theActiveContext, bool activeInstance);
    
    //## auto_generated
    virtual void destroy();
    
    // rootState:
    //## statechart_method
    inline bool rootState_IN() const;
    
    //## statechart_method
    inline bool rootState_isCompleted();
    
    //## statechart_method
    virtual void rootState_entDef();
    
    //## statechart_method
    virtual IOxfReactive::TakeEventStatus rootState_processEvent();
    
    // Testing:
    //## statechart_method
    inline bool Testing_IN() const;
    
    // terminationstate_7:
    //## statechart_method
    inline bool terminationstate_7_IN() const;
    
    // Stop:
    //## statechart_method
    inline bool Stop_IN() const;
    
    //## statechart_method
    inline bool Stop_isCompleted();
    
    //## statechart_method
    void Stop_entDef();
    
    //## statechart_method
    void Stop_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus Stop_handleEvent();
    
    // terminationstate_17:
    //## statechart_method
    inline bool terminationstate_17_IN() const;
    
    // sendaction_16:
    //## statechart_method
    inline bool sendaction_16_IN() const;
    
    // sendaction_15:
    //## statechart_method
    inline bool sendaction_15_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus sendaction_15_handleEvent();
    
    // sendaction_14:
    //## statechart_method
    inline bool sendaction_14_IN() const;
    
    // Step:
    //## statechart_method
    inline bool Step_IN() const;
    
    // Start:
    //## statechart_method
    inline bool Start_IN() const;
    
    //## statechart_method
    inline bool Start_isCompleted();
    
    //## statechart_method
    void Start_entDef();
    
    //## statechart_method
    void Start_exit();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus Start_handleEvent();
    
    // terminationstate_22:
    //## statechart_method
    inline bool terminationstate_22_IN() const;
    
    // sendaction_21:
    //## statechart_method
    inline bool sendaction_21_IN() const;
    
    // sendaction_20:
    //## statechart_method
    inline bool sendaction_20_IN() const;
    
    // sendaction_19:
    //## statechart_method
    inline bool sendaction_19_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus sendaction_19_handleEvent();
    
    // Servicing:
    //## statechart_method
    inline bool Servicing_IN() const;
    
    // sendaction_11:
    //## statechart_method
    inline bool sendaction_11_IN() const;
    
    // sendaction_10:
    //## statechart_method
    inline bool sendaction_10_IN() const;
    
    // Regulations:
    //## statechart_method
    inline bool Regulations_IN() const;
    
    // Ready:
    //## statechart_method
    inline bool Ready_IN() const;
    
    //## statechart_method
    IOxfReactive::TakeEventStatus ReadyTakeevSignal();
    
    //## statechart_method
    IOxfReactive::TakeEventStatus Ready_handleEvent();
    
    // Operation:
    //## statechart_method
    inline bool Operation_IN() const;
    
    // Firmware:
    //## statechart_method
    inline bool Firmware_IN() const;
    
    // Error:
    //## statechart_method
    inline bool Error_IN() const;
    
    // Blockade:
    //## statechart_method
    inline bool Blockade_IN() const;
    
    // Auth:
    //## statechart_method
    inline bool Auth_IN() const;
    
    ////    Framework    ////

protected :

//#[ ignore
    enum Contoller_Enum {
        OMNonState = 0,
        Testing = 1,
        terminationstate_7 = 2,
        Stop = 3,
        terminationstate_17 = 4,
        sendaction_16 = 5,
        sendaction_15 = 6,
        sendaction_14 = 7,
        Step = 8,
        Start = 9,
        terminationstate_22 = 10,
        sendaction_21 = 11,
        sendaction_20 = 12,
        sendaction_19 = 13,
        Servicing = 14,
        sendaction_11 = 15,
        sendaction_10 = 16,
        Regulations = 17,
        Ready = 18,
        Operation = 19,
        Firmware = 20,
        Error = 21,
        Blockade = 22,
        Auth = 23
    };
    
    int rootState_subState;
    
    int rootState_active;
    
    int Stop_subState;
    
    int Start_subState;
    
    IOxfTimeout* rootState_timeout;
//#]
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedContoller : virtual public AOMInstance {
    DECLARE_REACTIVE_META(Contoller, OMAnimatedContoller)
    
    ////    Framework operations    ////
    
public :

    virtual void serializeAttributes(AOMSAttributes* aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations* aomsRelations) const;
    
    //## statechart_method
    void rootState_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Testing_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void terminationstate_7_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Stop_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void terminationstate_17_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void sendaction_16_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void sendaction_15_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void sendaction_14_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Step_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Start_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void terminationstate_22_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void sendaction_21_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void sendaction_20_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void sendaction_19_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Servicing_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void sendaction_11_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void sendaction_10_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Regulations_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Ready_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Operation_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Firmware_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Error_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Blockade_serializeStates(AOMSState* aomsState) const;
    
    //## statechart_method
    void Auth_serializeStates(AOMSState* aomsState) const;
};
//#]
#endif // _OMINSTRUMENT

inline bool Contoller::rootState_IN() const {
    return true;
}

inline bool Contoller::rootState_isCompleted() {
    return ( IS_IN(terminationstate_7) );
}

inline bool Contoller::Testing_IN() const {
    return rootState_subState == Testing;
}

inline bool Contoller::terminationstate_7_IN() const {
    return rootState_subState == terminationstate_7;
}

inline bool Contoller::Stop_IN() const {
    return rootState_subState == Stop;
}

inline bool Contoller::Stop_isCompleted() {
    return ( IS_IN(terminationstate_17) );
}

inline bool Contoller::terminationstate_17_IN() const {
    return Stop_subState == terminationstate_17;
}

inline bool Contoller::sendaction_16_IN() const {
    return Stop_subState == sendaction_16;
}

inline bool Contoller::sendaction_15_IN() const {
    return Stop_subState == sendaction_15;
}

inline bool Contoller::sendaction_14_IN() const {
    return Stop_subState == sendaction_14;
}

inline bool Contoller::Step_IN() const {
    return rootState_subState == Step;
}

inline bool Contoller::Start_IN() const {
    return rootState_subState == Start;
}

inline bool Contoller::Start_isCompleted() {
    return ( IS_IN(terminationstate_22) );
}

inline bool Contoller::terminationstate_22_IN() const {
    return Start_subState == terminationstate_22;
}

inline bool Contoller::sendaction_21_IN() const {
    return Start_subState == sendaction_21;
}

inline bool Contoller::sendaction_20_IN() const {
    return Start_subState == sendaction_20;
}

inline bool Contoller::sendaction_19_IN() const {
    return Start_subState == sendaction_19;
}

inline bool Contoller::Servicing_IN() const {
    return rootState_subState == Servicing;
}

inline bool Contoller::sendaction_11_IN() const {
    return rootState_subState == sendaction_11;
}

inline bool Contoller::sendaction_10_IN() const {
    return rootState_subState == sendaction_10;
}

inline bool Contoller::Regulations_IN() const {
    return rootState_subState == Regulations;
}

inline bool Contoller::Ready_IN() const {
    return rootState_subState == Ready;
}

inline bool Contoller::Operation_IN() const {
    return rootState_subState == Operation;
}

inline bool Contoller::Firmware_IN() const {
    return rootState_subState == Firmware;
}

inline bool Contoller::Error_IN() const {
    return rootState_subState == Error;
}

inline bool Contoller::Blockade_IN() const {
    return rootState_subState == Blockade;
}

inline bool Contoller::Auth_IN() const {
    return rootState_subState == Auth;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Contoller.h
*********************************************************************/
