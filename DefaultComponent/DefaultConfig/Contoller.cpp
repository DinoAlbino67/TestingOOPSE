/********************************************************************
	Rhapsody	: 10.0.1 
	Login		: LabPOIO-29
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Contoller
//!	Generated Date	: Tue, 9, Jun 2026  
	File Path	: DefaultComponent/DefaultConfig/Contoller.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "Contoller.h"
//#[ ignore
#define Default_Contoller_Contoller_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Contoller
Contoller::Contoller(IOxfActive* theActiveContext) : state(STOPPED), state0(CLOSING) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Contoller, Contoller(), 0, Default_Contoller_Contoller_SERIALIZE);
    setActiveContext(theActiveContext, false);
    {
        {
            itsDetector.setShouldDelete(false);
        }
        {
            itsDrive.setShouldDelete(false);
        }
        {
            itsReceiver.setShouldDelete(false);
        }
        {
            itsLamp.setShouldDelete(false);
        }
    }
    initRelations();
    initStatechart();
}

Contoller::~Contoller() {
    NOTIFY_DESTRUCTOR(~Contoller, true);
    cancelTimeouts();
}

int Contoller::getParams() const {
    return params;
}

void Contoller::setParams(int p_params) {
    params = p_params;
}

float Contoller::getPosition() const {
    return position;
}

void Contoller::setPosition(float p_position) {
    position = p_position;
}

float Contoller::getPosition_max() const {
    return position_max;
}

void Contoller::setPosition_max(float p_position_max) {
    position_max = p_position_max;
}

float Contoller::getPosition_min() const {
    return position_min;
}

void Contoller::setPosition_min(float p_position_min) {
    position_min = p_position_min;
}

States Contoller::getState() const {
    return state;
}

void Contoller::setState(States p_state) {
    state = p_state;
}

States Contoller::getState0() const {
    return state0;
}

void Contoller::setState0(States p_state0) {
    state0 = p_state0;
}

bool Contoller::getState_indication() const {
    return state_indication;
}

void Contoller::setState_indication(bool p_state_indication) {
    state_indication = p_state_indication;
}

Detector* Contoller::getItsDetector() const {
    return (Detector*) &itsDetector;
}

Display* Contoller::getItsDisplay() const {
    return (Display*) &itsDisplay;
}

Drive* Contoller::getItsDrive() const {
    return (Drive*) &itsDrive;
}

Keyboard* Contoller::getItsKeyboard() const {
    return (Keyboard*) &itsKeyboard;
}

Lamp* Contoller::getItsLamp() const {
    return (Lamp*) &itsLamp;
}

Receiver* Contoller::getItsReceiver() const {
    return (Receiver*) &itsReceiver;
}

bool Contoller::startBehavior() {
    bool done = true;
    done &= itsDetector.startBehavior();
    done &= itsDrive.startBehavior();
    done &= itsLamp.startBehavior();
    done &= itsReceiver.startBehavior();
    done &= OMReactive::startBehavior();
    return done;
}

void Contoller::initRelations() {
    itsDetector._setItsController(this);
    itsDrive._setItsController(this);
    itsReceiver._setItsController(this);
}

void Contoller::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    Stop_subState = OMNonState;
    Start_subState = OMNonState;
    rootState_timeout = NULL;
}

void Contoller::cancelTimeouts() {
    cancel(rootState_timeout);
}

bool Contoller::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(rootState_timeout == arg)
        {
            rootState_timeout = NULL;
            res = true;
        }
    return res;
}

void Contoller::setActiveContext(IOxfActive* theActiveContext, bool activeInstance) {
    OMReactive::setActiveContext(theActiveContext, activeInstance);
    {
        itsDetector.setActiveContext(theActiveContext, false);
        itsDrive.setActiveContext(theActiveContext, false);
        itsReceiver.setActiveContext(theActiveContext, false);
        itsLamp.setActiveContext(theActiveContext, false);
    }
}

void Contoller::destroy() {
    itsDetector.destroy();
    itsDrive.destroy();
    itsLamp.destroy();
    itsReceiver.destroy();
    OMReactive::destroy();
}

void Contoller::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.Servicing");
        pushNullTransition();
        rootState_subState = Servicing;
        rootState_active = Servicing;
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus Contoller::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State Servicing
        case Servicing:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Servicing");
                    NOTIFY_STATE_ENTERED("ROOT.Auth");
                    rootState_subState = Auth;
                    rootState_active = Auth;
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
        }
        break;
        // State Auth
        case Auth:
        {
            if(IS_EVENT_TYPE_OF(evSuccess_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("4");
                    NOTIFY_STATE_EXITED("ROOT.Auth");
                    NOTIFY_STATE_ENTERED("ROOT.Operation");
                    rootState_subState = Operation;
                    rootState_active = Operation;
                    NOTIFY_TRANSITION_TERMINATED("4");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evError_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    NOTIFY_STATE_EXITED("ROOT.Auth");
                    NOTIFY_STATE_ENTERED("ROOT.Error");
                    rootState_subState = Error;
                    rootState_active = Error;
                    rootState_timeout = scheduleTimeout(2000, "ROOT.Error");
                    NOTIFY_TRANSITION_TERMINATED("3");
                    res = eventConsumed;
                }
            
        }
        break;
        // State Error
        case Error:
        {
            if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == rootState_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("2");
                            cancel(rootState_timeout);
                            NOTIFY_STATE_EXITED("ROOT.Error");
                            NOTIFY_STATE_ENTERED("ROOT.Auth");
                            rootState_subState = Auth;
                            rootState_active = Auth;
                            NOTIFY_TRANSITION_TERMINATED("2");
                            res = eventConsumed;
                        }
                }
            
        }
        break;
        // State Operation
        case Operation:
        {
            if(IS_EVENT_TYPE_OF(evTest_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("7");
                    NOTIFY_STATE_EXITED("ROOT.Operation");
                    NOTIFY_STATE_ENTERED("ROOT.Testing");
                    rootState_subState = Testing;
                    rootState_active = Testing;
                    //#[ state Testing.(Entry) 
                    bool receiver_ok = itsReceiver.is_ok();
                    bool detector_ok = itsDetector.is_ok();
                    bool drive_ok=itsDrive.is_ok();
                    bool lamp_ok=itsLamp.is_ok();
                    bool state_indication;
                    bool all_ok = receiver_ok && detector_ok && drive_ok &&(state_indication ? lamp_ok:true);
                    if(all_ok)
                    	GEN(evOK());
                    else
                    	GEN(evFAIL());		
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("7");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evRegulate_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("5");
                    NOTIFY_STATE_EXITED("ROOT.Operation");
                    NOTIFY_STATE_ENTERED("ROOT.Regulations");
                    pushNullTransition();
                    rootState_subState = Regulations;
                    rootState_active = Regulations;
                    NOTIFY_TRANSITION_TERMINATED("5");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evFirmware_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("6");
                    NOTIFY_STATE_EXITED("ROOT.Operation");
                    NOTIFY_STATE_ENTERED("ROOT.Firmware");
                    pushNullTransition();
                    rootState_subState = Firmware;
                    rootState_active = Firmware;
                    NOTIFY_TRANSITION_TERMINATED("6");
                    res = eventConsumed;
                }
            
        }
        break;
        // State Regulations
        case Regulations:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    NOTIFY_TRANSITION_STARTED("8");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Regulations");
                    NOTIFY_STATE_ENTERED("ROOT.terminationstate_7");
                    rootState_subState = terminationstate_7;
                    rootState_active = terminationstate_7;
                    NOTIFY_TRANSITION_TERMINATED("8");
                    res = eventConsumed;
                }
            
        }
        break;
        // State Firmware
        case Firmware:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    NOTIFY_TRANSITION_STARTED("9");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Firmware");
                    NOTIFY_STATE_ENTERED("ROOT.terminationstate_7");
                    rootState_subState = terminationstate_7;
                    rootState_active = terminationstate_7;
                    NOTIFY_TRANSITION_TERMINATED("9");
                    res = eventConsumed;
                }
            
        }
        break;
        // State Testing
        case Testing:
        {
            if(IS_EVENT_TYPE_OF(evOK_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("12");
                    NOTIFY_STATE_EXITED("ROOT.Testing");
                    //#[ transition 12 
                    itsReceiver.GEN(evActivate(true));
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.Ready");
                    rootState_subState = Ready;
                    rootState_active = Ready;
                    NOTIFY_TRANSITION_TERMINATED("12");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evFAIL_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("11");
                    NOTIFY_STATE_EXITED("ROOT.Testing");
                    //#[ transition 11 
                    itsReceiver.GEN(evActivate(false));
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.Blockade");
                    pushNullTransition();
                    rootState_subState = Blockade;
                    rootState_active = Blockade;
                    NOTIFY_TRANSITION_TERMINATED("11");
                    res = eventConsumed;
                }
            
        }
        break;
        // State Blockade
        case Blockade:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    NOTIFY_TRANSITION_STARTED("10");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Blockade");
                    NOTIFY_STATE_ENTERED("ROOT.terminationstate_7");
                    rootState_subState = terminationstate_7;
                    rootState_active = terminationstate_7;
                    NOTIFY_TRANSITION_TERMINATED("10");
                    res = eventConsumed;
                }
            
        }
        break;
        // State Ready
        case Ready:
        {
            res = Ready_handleEvent();
        }
        break;
        // State sendaction_10
        case sendaction_10:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    NOTIFY_TRANSITION_STARTED("13");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.sendaction_10");
                    NOTIFY_STATE_ENTERED("ROOT.Ready");
                    rootState_subState = Ready;
                    rootState_active = Ready;
                    NOTIFY_TRANSITION_TERMINATED("13");
                    res = eventConsumed;
                }
            
        }
        break;
        // State sendaction_11
        case sendaction_11:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 15 
                    if(state_indication)
                        {
                            NOTIFY_TRANSITION_STARTED("16");
                            NOTIFY_TRANSITION_STARTED("15");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.sendaction_11");
                            NOTIFY_STATE_ENTERED("ROOT.Ready");
                            rootState_subState = Ready;
                            rootState_active = Ready;
                            NOTIFY_TRANSITION_TERMINATED("15");
                            NOTIFY_TRANSITION_TERMINATED("16");
                            res = eventConsumed;
                        }
                    else
                        {
                            NOTIFY_TRANSITION_STARTED("16");
                            NOTIFY_TRANSITION_STARTED("14");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.sendaction_11");
                            NOTIFY_STATE_ENTERED("ROOT.sendaction_10");
                            pushNullTransition();
                            rootState_subState = sendaction_10;
                            rootState_active = sendaction_10;
                            //#[ state sendaction_10.(Entry) 
                            itsLamp.GEN(evStep(0));
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("14");
                            NOTIFY_TRANSITION_TERMINATED("16");
                            res = eventConsumed;
                        }
                }
            
        }
        break;
        // State Step
        case Step:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    NOTIFY_TRANSITION_STARTED("17");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Step");
                    NOTIFY_STATE_ENTERED("ROOT.sendaction_11");
                    pushNullTransition();
                    rootState_subState = sendaction_11;
                    rootState_active = sendaction_11;
                    //#[ state sendaction_11.(Entry) 
                    itsDetector.GEN(evCheckCollision);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("17");
                    res = eventConsumed;
                }
            
        }
        break;
        // State sendaction_14
        case sendaction_14:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    NOTIFY_TRANSITION_STARTED("24");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Stop.sendaction_14");
                    NOTIFY_STATE_ENTERED("ROOT.Stop.sendaction_16");
                    pushNullTransition();
                    Stop_subState = sendaction_16;
                    rootState_active = sendaction_16;
                    //#[ state Stop.sendaction_16.(Entry) 
                    itsDetector.GEN(evStop);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("24");
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = Stop_handleEvent();
                }
        }
        break;
        // State sendaction_15
        case sendaction_15:
        {
            res = sendaction_15_handleEvent();
        }
        break;
        // State sendaction_16
        case sendaction_16:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    NOTIFY_TRANSITION_STARTED("26");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Stop.sendaction_16");
                    NOTIFY_STATE_ENTERED("ROOT.Stop.terminationstate_17");
                    Stop_subState = terminationstate_17;
                    rootState_active = terminationstate_17;
                    NOTIFY_TRANSITION_TERMINATED("26");
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = Stop_handleEvent();
                }
        }
        break;
        // State terminationstate_17
        case terminationstate_17:
        {
            res = Stop_handleEvent();
        }
        break;
        // State sendaction_19
        case sendaction_19:
        {
            res = sendaction_19_handleEvent();
        }
        break;
        // State sendaction_20
        case sendaction_20:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    NOTIFY_TRANSITION_STARTED("38");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Start.sendaction_20");
                    NOTIFY_STATE_ENTERED("ROOT.Start.sendaction_21");
                    pushNullTransition();
                    Start_subState = sendaction_21;
                    rootState_active = sendaction_21;
                    //#[ state Start.sendaction_21.(Entry) 
                    itsDrive.GEN(evStart(0));
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("38");
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = Start_handleEvent();
                }
        }
        break;
        // State sendaction_21
        case sendaction_21:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    NOTIFY_TRANSITION_STARTED("40");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Start.sendaction_21");
                    NOTIFY_STATE_ENTERED("ROOT.Start.terminationstate_22");
                    Start_subState = terminationstate_22;
                    rootState_active = terminationstate_22;
                    NOTIFY_TRANSITION_TERMINATED("40");
                    res = eventConsumed;
                }
            
            if(res == eventNotConsumed)
                {
                    res = Start_handleEvent();
                }
        }
        break;
        // State terminationstate_22
        case terminationstate_22:
        {
            res = Start_handleEvent();
        }
        break;
        default:
            break;
    }
    return res;
}

void Contoller::Stop_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.Stop");
    pushNullTransition();
    rootState_subState = Stop;
    NOTIFY_TRANSITION_STARTED("21");
    //#[ transition 21 
    set_state(STOPPED);
    //#]
    NOTIFY_STATE_ENTERED("ROOT.Stop.sendaction_15");
    pushNullTransition();
    Stop_subState = sendaction_15;
    rootState_active = sendaction_15;
    //#[ state Stop.sendaction_15.(Entry) 
    itsDrive.GEN(evStop);
    //#]
    NOTIFY_TRANSITION_TERMINATED("21");
}

void Contoller::Stop_exit() {
    popNullTransition();
    switch (Stop_subState) {
        // State sendaction_14
        case sendaction_14:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.Stop.sendaction_14");
        }
        break;
        // State sendaction_15
        case sendaction_15:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.Stop.sendaction_15");
        }
        break;
        // State sendaction_16
        case sendaction_16:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.Stop.sendaction_16");
        }
        break;
        // State terminationstate_17
        case terminationstate_17:
        {
            NOTIFY_STATE_EXITED("ROOT.Stop.terminationstate_17");
        }
        break;
        default:
            break;
    }
    Stop_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.Stop");
}

IOxfReactive::TakeEventStatus Contoller::Stop_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 32 
            if(IS_COMPLETED(Stop)==true)
                {
                    NOTIFY_TRANSITION_STARTED("32");
                    Stop_exit();
                    NOTIFY_STATE_ENTERED("ROOT.Ready");
                    rootState_subState = Ready;
                    rootState_active = Ready;
                    NOTIFY_TRANSITION_TERMINATED("32");
                    res = eventConsumed;
                }
        }
    
    return res;
}

IOxfReactive::TakeEventStatus Contoller::sendaction_15_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 25 
            if(state_indication)
                {
                    NOTIFY_TRANSITION_STARTED("22");
                    NOTIFY_TRANSITION_STARTED("25");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Stop.sendaction_15");
                    NOTIFY_STATE_ENTERED("ROOT.Stop.sendaction_16");
                    pushNullTransition();
                    Stop_subState = sendaction_16;
                    rootState_active = sendaction_16;
                    //#[ state Stop.sendaction_16.(Entry) 
                    itsDetector.GEN(evStop);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("25");
                    NOTIFY_TRANSITION_TERMINATED("22");
                    res = eventConsumed;
                }
            else
                {
                    NOTIFY_TRANSITION_STARTED("22");
                    NOTIFY_TRANSITION_STARTED("23");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Stop.sendaction_15");
                    NOTIFY_STATE_ENTERED("ROOT.Stop.sendaction_14");
                    pushNullTransition();
                    Stop_subState = sendaction_14;
                    rootState_active = sendaction_14;
                    //#[ state Stop.sendaction_14.(Entry) 
                    itsLamp.GEN(evStop);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("23");
                    NOTIFY_TRANSITION_TERMINATED("22");
                    res = eventConsumed;
                }
        }
    
    if(res == eventNotConsumed)
        {
            res = Stop_handleEvent();
        }
    return res;
}

void Contoller::Start_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.Start");
    pushNullTransition();
    rootState_subState = Start;
    NOTIFY_TRANSITION_STARTED("35");
    NOTIFY_STATE_ENTERED("ROOT.Start.sendaction_19");
    pushNullTransition();
    Start_subState = sendaction_19;
    rootState_active = sendaction_19;
    //#[ state Start.sendaction_19.(Entry) 
    itsDetector.GEN(evStart(0));
    //#]
    NOTIFY_TRANSITION_TERMINATED("35");
}

void Contoller::Start_exit() {
    popNullTransition();
    switch (Start_subState) {
        // State sendaction_19
        case sendaction_19:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.Start.sendaction_19");
        }
        break;
        // State sendaction_20
        case sendaction_20:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.Start.sendaction_20");
        }
        break;
        // State sendaction_21
        case sendaction_21:
        {
            popNullTransition();
            NOTIFY_STATE_EXITED("ROOT.Start.sendaction_21");
        }
        break;
        // State terminationstate_22
        case terminationstate_22:
        {
            NOTIFY_STATE_EXITED("ROOT.Start.terminationstate_22");
        }
        break;
        default:
            break;
    }
    Start_subState = OMNonState;
    
    NOTIFY_STATE_EXITED("ROOT.Start");
}

IOxfReactive::TakeEventStatus Contoller::Start_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 34 
            if(IS_COMPLETED(Start)==true)
                {
                    NOTIFY_TRANSITION_STARTED("34");
                    Start_exit();
                    NOTIFY_STATE_ENTERED("ROOT.Ready");
                    rootState_subState = Ready;
                    rootState_active = Ready;
                    NOTIFY_TRANSITION_TERMINATED("34");
                    res = eventConsumed;
                }
        }
    
    return res;
}

IOxfReactive::TakeEventStatus Contoller::sendaction_19_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMNullEventId))
        {
            //## transition 39 
            if(!state_indication)
                {
                    NOTIFY_TRANSITION_STARTED("36");
                    NOTIFY_TRANSITION_STARTED("39");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Start.sendaction_19");
                    NOTIFY_STATE_ENTERED("ROOT.Start.sendaction_21");
                    pushNullTransition();
                    Start_subState = sendaction_21;
                    rootState_active = sendaction_21;
                    //#[ state Start.sendaction_21.(Entry) 
                    itsDrive.GEN(evStart(0));
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("39");
                    NOTIFY_TRANSITION_TERMINATED("36");
                    res = eventConsumed;
                }
            else
                {
                    NOTIFY_TRANSITION_STARTED("36");
                    NOTIFY_TRANSITION_STARTED("37");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Start.sendaction_19");
                    NOTIFY_STATE_ENTERED("ROOT.Start.sendaction_20");
                    pushNullTransition();
                    Start_subState = sendaction_20;
                    rootState_active = sendaction_20;
                    //#[ state Start.sendaction_20.(Entry) 
                    itsLamp.GEN(evStart(0));
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("37");
                    NOTIFY_TRANSITION_TERMINATED("36");
                    res = eventConsumed;
                }
        }
    
    if(res == eventNotConsumed)
        {
            res = Start_handleEvent();
        }
    return res;
}

IOxfReactive::TakeEventStatus Contoller::ReadyTakeevSignal() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    //## transition 30 
    if(state!=STOPPED)
        {
            NOTIFY_TRANSITION_STARTED("29");
            NOTIFY_TRANSITION_STARTED("30");
            NOTIFY_STATE_EXITED("ROOT.Ready");
            Stop_entDef();
            NOTIFY_TRANSITION_TERMINATED("30");
            NOTIFY_TRANSITION_TERMINATED("29");
            res = eventConsumed;
        }
    else
        {
            //## transition 27 
            if(state0 == CLOSING)
                {
                    NOTIFY_TRANSITION_STARTED("29");
                    NOTIFY_TRANSITION_STARTED("28");
                    NOTIFY_TRANSITION_STARTED("27");
                    NOTIFY_STATE_EXITED("ROOT.Ready");
                    //#[ transition 27 
                    set_state(OPENING);
                    //#]
                    Start_entDef();
                    NOTIFY_TRANSITION_TERMINATED("27");
                    NOTIFY_TRANSITION_TERMINATED("28");
                    NOTIFY_TRANSITION_TERMINATED("29");
                    res = eventConsumed;
                }
            else
                {
                    //## transition 33 
                    if(state0==OPENING)
                        {
                            NOTIFY_TRANSITION_STARTED("29");
                            NOTIFY_TRANSITION_STARTED("28");
                            NOTIFY_TRANSITION_STARTED("33");
                            NOTIFY_STATE_EXITED("ROOT.Ready");
                            //#[ transition 33 
                            set_state(CLOSING);
                            //#]
                            Start_entDef();
                            NOTIFY_TRANSITION_TERMINATED("33");
                            NOTIFY_TRANSITION_TERMINATED("28");
                            NOTIFY_TRANSITION_TERMINATED("29");
                            res = eventConsumed;
                        }
                }
        }
    return res;
}

IOxfReactive::TakeEventStatus Contoller::Ready_handleEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evSignal_Default_id))
        {
            res = ReadyTakeevSignal();
        }
    else if(IS_EVENT_TYPE_OF(evCollision_Default_id))
        {
            NOTIFY_TRANSITION_STARTED("31");
            NOTIFY_STATE_EXITED("ROOT.Ready");
            Stop_entDef();
            NOTIFY_TRANSITION_TERMINATED("31");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(evStep_Default_id))
        {
            OMSETPARAMS(evStep);
            //## transition 19 
            if( state == OPENING ? (position < position_max):(position>position_min))
                {
                    NOTIFY_TRANSITION_STARTED("18");
                    NOTIFY_TRANSITION_STARTED("19");
                    NOTIFY_STATE_EXITED("ROOT.Ready");
                    NOTIFY_STATE_ENTERED("ROOT.Step");
                    pushNullTransition();
                    rootState_subState = Step;
                    rootState_active = Step;
                    //#[ state Step.(Entry) 
                    position +=params->disp;
                    std::cout<<"\nposition="<<position;
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("19");
                    NOTIFY_TRANSITION_TERMINATED("18");
                    res = eventConsumed;
                }
            else
                {
                    NOTIFY_TRANSITION_STARTED("18");
                    NOTIFY_TRANSITION_STARTED("20");
                    NOTIFY_STATE_EXITED("ROOT.Ready");
                    Stop_entDef();
                    NOTIFY_TRANSITION_TERMINATED("20");
                    NOTIFY_TRANSITION_TERMINATED("18");
                    res = eventConsumed;
                }
        }
    
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedContoller::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("state", x2String((int)myReal->state));
    aomsAttributes->addAttribute("state0", x2String((int)myReal->state0));
    aomsAttributes->addAttribute("state_indication", x2String(myReal->state_indication));
    aomsAttributes->addAttribute("position", x2String(myReal->position));
    aomsAttributes->addAttribute("position_max", x2String(myReal->position_max));
    aomsAttributes->addAttribute("position_min", x2String(myReal->position_min));
    aomsAttributes->addAttribute("params", x2String(myReal->params));
}

void OMAnimatedContoller::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsDetector", true, true);
    aomsRelations->ADD_ITEM(&myReal->itsDetector);
    aomsRelations->addRelation("itsDrive", true, true);
    aomsRelations->ADD_ITEM(&myReal->itsDrive);
    aomsRelations->addRelation("itsReceiver", true, true);
    aomsRelations->ADD_ITEM(&myReal->itsReceiver);
    aomsRelations->addRelation("itsLamp", true, true);
    aomsRelations->ADD_ITEM(&myReal->itsLamp);
    aomsRelations->addRelation("itsKeyboard", true, true);
    aomsRelations->ADD_ITEM(&myReal->itsKeyboard);
    aomsRelations->addRelation("itsDisplay", true, true);
    aomsRelations->ADD_ITEM(&myReal->itsDisplay);
}

void OMAnimatedContoller::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Contoller::Servicing:
        {
            Servicing_serializeStates(aomsState);
        }
        break;
        case Contoller::Auth:
        {
            Auth_serializeStates(aomsState);
        }
        break;
        case Contoller::Error:
        {
            Error_serializeStates(aomsState);
        }
        break;
        case Contoller::Operation:
        {
            Operation_serializeStates(aomsState);
        }
        break;
        case Contoller::Regulations:
        {
            Regulations_serializeStates(aomsState);
        }
        break;
        case Contoller::Firmware:
        {
            Firmware_serializeStates(aomsState);
        }
        break;
        case Contoller::Testing:
        {
            Testing_serializeStates(aomsState);
        }
        break;
        case Contoller::terminationstate_7:
        {
            terminationstate_7_serializeStates(aomsState);
        }
        break;
        case Contoller::Blockade:
        {
            Blockade_serializeStates(aomsState);
        }
        break;
        case Contoller::Ready:
        {
            Ready_serializeStates(aomsState);
        }
        break;
        case Contoller::sendaction_10:
        {
            sendaction_10_serializeStates(aomsState);
        }
        break;
        case Contoller::sendaction_11:
        {
            sendaction_11_serializeStates(aomsState);
        }
        break;
        case Contoller::Step:
        {
            Step_serializeStates(aomsState);
        }
        break;
        case Contoller::Stop:
        {
            Stop_serializeStates(aomsState);
        }
        break;
        case Contoller::Start:
        {
            Start_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedContoller::Testing_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Testing");
}

void OMAnimatedContoller::terminationstate_7_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.terminationstate_7");
}

void OMAnimatedContoller::Stop_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Stop");
    switch (myReal->Stop_subState) {
        case Contoller::sendaction_14:
        {
            sendaction_14_serializeStates(aomsState);
        }
        break;
        case Contoller::sendaction_15:
        {
            sendaction_15_serializeStates(aomsState);
        }
        break;
        case Contoller::sendaction_16:
        {
            sendaction_16_serializeStates(aomsState);
        }
        break;
        case Contoller::terminationstate_17:
        {
            terminationstate_17_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedContoller::terminationstate_17_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Stop.terminationstate_17");
}

void OMAnimatedContoller::sendaction_16_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Stop.sendaction_16");
}

void OMAnimatedContoller::sendaction_15_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Stop.sendaction_15");
}

void OMAnimatedContoller::sendaction_14_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Stop.sendaction_14");
}

void OMAnimatedContoller::Step_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Step");
}

void OMAnimatedContoller::Start_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Start");
    switch (myReal->Start_subState) {
        case Contoller::sendaction_19:
        {
            sendaction_19_serializeStates(aomsState);
        }
        break;
        case Contoller::sendaction_20:
        {
            sendaction_20_serializeStates(aomsState);
        }
        break;
        case Contoller::sendaction_21:
        {
            sendaction_21_serializeStates(aomsState);
        }
        break;
        case Contoller::terminationstate_22:
        {
            terminationstate_22_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedContoller::terminationstate_22_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Start.terminationstate_22");
}

void OMAnimatedContoller::sendaction_21_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Start.sendaction_21");
}

void OMAnimatedContoller::sendaction_20_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Start.sendaction_20");
}

void OMAnimatedContoller::sendaction_19_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Start.sendaction_19");
}

void OMAnimatedContoller::Servicing_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Servicing");
}

void OMAnimatedContoller::sendaction_11_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.sendaction_11");
}

void OMAnimatedContoller::sendaction_10_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.sendaction_10");
}

void OMAnimatedContoller::Regulations_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Regulations");
}

void OMAnimatedContoller::Ready_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Ready");
}

void OMAnimatedContoller::Operation_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Operation");
}

void OMAnimatedContoller::Firmware_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Firmware");
}

void OMAnimatedContoller::Error_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Error");
}

void OMAnimatedContoller::Blockade_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Blockade");
}

void OMAnimatedContoller::Auth_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Auth");
}
//#]

IMPLEMENT_REACTIVE_META_P(Contoller, Default, Default, false, OMAnimatedContoller)
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Contoller.cpp
*********************************************************************/
