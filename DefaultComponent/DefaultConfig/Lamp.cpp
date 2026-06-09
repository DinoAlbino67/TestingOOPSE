/********************************************************************
	Rhapsody	: 10.0.1 
	Login		: LabPOIO-29
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Lamp
//!	Generated Date	: Tue, 9, Jun 2026  
	File Path	: DefaultComponent/DefaultConfig/Lamp.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "Lamp.h"
//#[ ignore
#define Default_Lamp_Lamp_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Lamp
Lamp::Lamp(IOxfActive* theActiveContext) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Lamp, Lamp(), 0, Default_Lamp_Lamp_SERIALIZE);
    setActiveContext(theActiveContext, false);
    initStatechart();
}

Lamp::~Lamp() {
    NOTIFY_DESTRUCTOR(~Lamp, false);
}

bool Lamp::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Lamp::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void Lamp::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("4");
        NOTIFY_STATE_ENTERED("ROOT.Inactive");
        rootState_subState = Inactive;
        rootState_active = Inactive;
        NOTIFY_TRANSITION_TERMINATED("4");
    }
}

IOxfReactive::TakeEventStatus Lamp::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State Inactive
        case Inactive:
        {
            if(IS_EVENT_TYPE_OF(evStart_Default_id))
                {
                    OMSETPARAMS(evStart);
                    NOTIFY_TRANSITION_STARTED("2");
                    NOTIFY_STATE_EXITED("ROOT.Inactive");
                    NOTIFY_STATE_ENTERED("ROOT.Active");
                    rootState_subState = Active;
                    rootState_active = Active;
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            
        }
        break;
        // State Active
        case Active:
        {
            if(IS_EVENT_TYPE_OF(evStop_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    NOTIFY_STATE_EXITED("ROOT.Active");
                    NOTIFY_STATE_ENTERED("ROOT.Inactive");
                    rootState_subState = Inactive;
                    rootState_active = Inactive;
                    NOTIFY_TRANSITION_TERMINATED("3");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(ecStep_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.Active");
                    NOTIFY_STATE_ENTERED("ROOT.Blink");
                    pushNullTransition();
                    rootState_subState = Blink;
                    rootState_active = Blink;
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
        }
        break;
        // State Blink
        case Blink:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    NOTIFY_TRANSITION_STARTED("0");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.Blink");
                    NOTIFY_STATE_ENTERED("ROOT.Active");
                    rootState_subState = Active;
                    rootState_active = Active;
                    NOTIFY_TRANSITION_TERMINATED("0");
                    res = eventConsumed;
                }
            
        }
        break;
        default:
            break;
    }
    return res;
}

#ifdef _OMINSTRUMENT
//#[ ignore
void OMAnimatedLamp::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    OMAnimatedModule::serializeAttributes(aomsAttributes);
}

void OMAnimatedLamp::serializeRelations(AOMSRelations* aomsRelations) const {
    OMAnimatedModule::serializeRelations(aomsRelations);
}

void OMAnimatedLamp::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Lamp::Inactive:
        {
            Inactive_serializeStates(aomsState);
        }
        break;
        case Lamp::Active:
        {
            Active_serializeStates(aomsState);
        }
        break;
        case Lamp::Blink:
        {
            Blink_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedLamp::Inactive_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Inactive");
}

void OMAnimatedLamp::Blink_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Blink");
}

void OMAnimatedLamp::Active_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Active");
}
//#]

IMPLEMENT_REACTIVE_META_S_P(Lamp, Default, false, Module, OMAnimatedModule, OMAnimatedLamp)

OMINIT_SUPERCLASS(Module, OMAnimatedModule)

OMREGISTER_REACTIVE_CLASS
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Lamp.cpp
*********************************************************************/
