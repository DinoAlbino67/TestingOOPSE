/********************************************************************
	Rhapsody	: 10.0.1 
	Login		: LabPOIO-29
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Receiver
//!	Generated Date	: Tue, 9, Jun 2026  
	File Path	: DefaultComponent/DefaultConfig/Receiver.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "Receiver.h"
//## link itsController
#include "Contoller.h"
//#[ ignore
#define Default_Receiver_Receiver_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Receiver
Receiver::Receiver(IOxfActive* theActiveContext) : singal_ok(false) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Receiver, Receiver(), 0, Default_Receiver_Receiver_SERIALIZE);
    setActiveContext(theActiveContext, false);
    itsController = NULL;
    initStatechart();
}

Receiver::~Receiver() {
    NOTIFY_DESTRUCTOR(~Receiver, false);
    cleanUpRelations();
}

bool Receiver::getSingal_ok() const {
    return singal_ok;
}

void Receiver::setSingal_ok(bool p_singal_ok) {
    singal_ok = p_singal_ok;
}

Contoller* Receiver::getItsController() const {
    return itsController;
}

void Receiver::setItsController(Contoller* p_Contoller) {
    _setItsController(p_Contoller);
}

bool Receiver::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Receiver::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void Receiver::cleanUpRelations() {
    if(itsController != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsController");
            itsController = NULL;
        }
}

void Receiver::__setItsController(Contoller* p_Contoller) {
    itsController = p_Contoller;
    if(p_Contoller != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsController", p_Contoller, false, true);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsController");
        }
}

void Receiver::_setItsController(Contoller* p_Contoller) {
    __setItsController(p_Contoller);
}

void Receiver::_clearItsController() {
    NOTIFY_RELATION_CLEARED("itsController");
    itsController = NULL;
}

void Receiver::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("6");
        NOTIFY_STATE_ENTERED("ROOT.Inactive");
        rootState_subState = Inactive;
        rootState_active = Inactive;
        NOTIFY_TRANSITION_TERMINATED("6");
    }
}

IOxfReactive::TakeEventStatus Receiver::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State Inactive
        case Inactive:
        {
            if(IS_EVENT_TYPE_OF(evActivate_Default_id))
                {
                    OMSETPARAMS(evActivate);
                    //## transition 0 
                    if(params->active)
                        {
                            NOTIFY_TRANSITION_STARTED("0");
                            NOTIFY_STATE_EXITED("ROOT.Inactive");
                            NOTIFY_STATE_ENTERED("ROOT.Active");
                            rootState_subState = Active;
                            rootState_active = Active;
                            NOTIFY_TRANSITION_TERMINATED("0");
                            res = eventConsumed;
                        }
                }
            
        }
        break;
        // State Active
        case Active:
        {
            if(IS_EVENT_TYPE_OF(evStop_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("5");
                    NOTIFY_STATE_EXITED("ROOT.Active");
                    NOTIFY_STATE_ENTERED("ROOT.Inactive");
                    rootState_subState = Inactive;
                    rootState_active = Inactive;
                    NOTIFY_TRANSITION_TERMINATED("5");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evSignal_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.Active");
                    NOTIFY_STATE_ENTERED("ROOT.validate");
                    pushNullTransition();
                    rootState_subState = validate;
                    rootState_active = validate;
                    //#[ state validate.(Entry) 
                    validate_signal();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
        }
        break;
        // State validate
        case validate:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    //## transition 3 
                    if(singal_ok)
                        {
                            NOTIFY_TRANSITION_STARTED("7");
                            NOTIFY_TRANSITION_STARTED("3");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.validate");
                            NOTIFY_STATE_ENTERED("ROOT.sendaction_4");
                            pushNullTransition();
                            rootState_subState = sendaction_4;
                            rootState_active = sendaction_4;
                            //#[ state sendaction_4.(Entry) 
                            itsController->GEN(evSignal);
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("3");
                            NOTIFY_TRANSITION_TERMINATED("7");
                            res = eventConsumed;
                        }
                    else
                        {
                            NOTIFY_TRANSITION_STARTED("7");
                            NOTIFY_TRANSITION_STARTED("2");
                            popNullTransition();
                            NOTIFY_STATE_EXITED("ROOT.validate");
                            NOTIFY_STATE_ENTERED("ROOT.Active");
                            rootState_subState = Active;
                            rootState_active = Active;
                            NOTIFY_TRANSITION_TERMINATED("2");
                            NOTIFY_TRANSITION_TERMINATED("7");
                            res = eventConsumed;
                        }
                }
            
        }
        break;
        // State sendaction_4
        case sendaction_4:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    NOTIFY_TRANSITION_STARTED("4");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.sendaction_4");
                    NOTIFY_STATE_ENTERED("ROOT.Active");
                    rootState_subState = Active;
                    rootState_active = Active;
                    NOTIFY_TRANSITION_TERMINATED("4");
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
void OMAnimatedReceiver::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("singal_ok", x2String(myReal->singal_ok));
    OMAnimatedModule::serializeAttributes(aomsAttributes);
}

void OMAnimatedReceiver::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsController", false, true);
    if(myReal->itsController)
        {
            aomsRelations->ADD_ITEM(myReal->itsController);
        }
    OMAnimatedModule::serializeRelations(aomsRelations);
}

void OMAnimatedReceiver::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Receiver::Inactive:
        {
            Inactive_serializeStates(aomsState);
        }
        break;
        case Receiver::Active:
        {
            Active_serializeStates(aomsState);
        }
        break;
        case Receiver::validate:
        {
            validate_serializeStates(aomsState);
        }
        break;
        case Receiver::sendaction_4:
        {
            sendaction_4_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedReceiver::validate_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.validate");
}

void OMAnimatedReceiver::sendaction_4_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.sendaction_4");
}

void OMAnimatedReceiver::Inactive_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Inactive");
}

void OMAnimatedReceiver::Active_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Active");
}
//#]

IMPLEMENT_REACTIVE_META_S_P(Receiver, Default, false, Module, OMAnimatedModule, OMAnimatedReceiver)

OMINIT_SUPERCLASS(Module, OMAnimatedModule)

OMREGISTER_REACTIVE_CLASS
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Receiver.cpp
*********************************************************************/
