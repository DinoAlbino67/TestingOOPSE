/********************************************************************
	Rhapsody	: 10.0.1 
	Login		: LabPOIO-29
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Detector
//!	Generated Date	: Tue, 9, Jun 2026  
	File Path	: DefaultComponent/DefaultConfig/Detector.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "Detector.h"
//## link itsController
#include "Contoller.h"
//#[ ignore
#define Default_Detector_Detector_SERIALIZE OM_NO_OP

#define Default_Detector_check_collison_SERIALIZE OM_NO_OP

#define Default_Detector_message_0_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Detector
Detector::Detector(IOxfActive* theActiveContext) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Detector, Detector(), 0, Default_Detector_Detector_SERIALIZE);
    setActiveContext(theActiveContext, false);
    itsController = NULL;
    initStatechart();
}

Detector::~Detector() {
    NOTIFY_DESTRUCTOR(~Detector, false);
    cleanUpRelations();
}

bool Detector::check_collison() {
    NOTIFY_OPERATION(check_collison, check_collison(), 0, Default_Detector_check_collison_SERIALIZE);
    //#[ operation check_collison()
    if(pulses_sent-pulses_received>margin)
    	return true;
    else
    	return false;
    //#]
}

void Detector::message_0() {
    NOTIFY_OPERATION(message_0, message_0(), 0, Default_Detector_message_0_SERIALIZE);
    //#[ operation message_0()
    //#]
}

int Detector::getMargin() const {
    return margin;
}

void Detector::setMargin(int p_margin) {
    margin = p_margin;
}

int Detector::getPulses_received() const {
    return pulses_received;
}

void Detector::setPulses_received(int p_pulses_received) {
    pulses_received = p_pulses_received;
}

int Detector::getPulses_sent() const {
    return pulses_sent;
}

void Detector::setPulses_sent(int p_pulses_sent) {
    pulses_sent = p_pulses_sent;
}

Contoller* Detector::getItsController() const {
    return itsController;
}

void Detector::setItsController(Contoller* p_Contoller) {
    _setItsController(p_Contoller);
}

bool Detector::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Detector::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void Detector::cleanUpRelations() {
    if(itsController != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsController");
            itsController = NULL;
        }
}

void Detector::__setItsController(Contoller* p_Contoller) {
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

void Detector::_setItsController(Contoller* p_Contoller) {
    __setItsController(p_Contoller);
}

void Detector::_clearItsController() {
    NOTIFY_RELATION_CLEARED("itsController");
    itsController = NULL;
}

void Detector::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.Inactive");
        rootState_subState = Inactive;
        rootState_active = Inactive;
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus Detector::rootState_processEvent() {
    IOxfReactive::TakeEventStatus res = eventNotConsumed;
    switch (rootState_active) {
        // State Inactive
        case Inactive:
        {
            if(IS_EVENT_TYPE_OF(evStart_Default_id))
                {
                    OMSETPARAMS(evStart);
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.Inactive");
                    NOTIFY_STATE_ENTERED("ROOT.Active");
                    rootState_subState = Active;
                    rootState_active = Active;
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
        }
        break;
        // State Active
        case Active:
        {
            if(IS_EVENT_TYPE_OF(evStop_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    NOTIFY_STATE_EXITED("ROOT.Active");
                    NOTIFY_STATE_ENTERED("ROOT.Inactive");
                    rootState_subState = Inactive;
                    rootState_active = Inactive;
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evCollision_Default_id))
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    NOTIFY_STATE_EXITED("ROOT.Active");
                    //#[ transition 3 
                    pulses_sent+=margin;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.Active");
                    rootState_subState = Active;
                    rootState_active = Active;
                    NOTIFY_TRANSITION_TERMINATED("3");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evCheckCollision_Default_id))
                {
                    //## transition 4 
                    if(check_collison())
                        {
                            NOTIFY_TRANSITION_STARTED("4");
                            NOTIFY_STATE_EXITED("ROOT.Active");
                            NOTIFY_STATE_ENTERED("ROOT.sendaction_2");
                            pushNullTransition();
                            rootState_subState = sendaction_2;
                            rootState_active = sendaction_2;
                            //#[ state sendaction_2.(Entry) 
                            itsController->GEN(evCollision);
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("4");
                            res = eventConsumed;
                        }
                }
            
        }
        break;
        // State sendaction_2
        case sendaction_2:
        {
            if(IS_EVENT_TYPE_OF(OMNullEventId))
                {
                    NOTIFY_TRANSITION_STARTED("5");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.sendaction_2");
                    //#[ transition 5 
                    reset_counters();
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.Active");
                    rootState_subState = Active;
                    rootState_active = Active;
                    NOTIFY_TRANSITION_TERMINATED("5");
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
void OMAnimatedDetector::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("pulses_sent", x2String(myReal->pulses_sent));
    aomsAttributes->addAttribute("margin", x2String(myReal->margin));
    aomsAttributes->addAttribute("pulses_received", x2String(myReal->pulses_received));
    OMAnimatedModule::serializeAttributes(aomsAttributes);
}

void OMAnimatedDetector::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsController", false, true);
    if(myReal->itsController)
        {
            aomsRelations->ADD_ITEM(myReal->itsController);
        }
    OMAnimatedModule::serializeRelations(aomsRelations);
}

void OMAnimatedDetector::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Detector::Inactive:
        {
            Inactive_serializeStates(aomsState);
        }
        break;
        case Detector::Active:
        {
            Active_serializeStates(aomsState);
        }
        break;
        case Detector::sendaction_2:
        {
            sendaction_2_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedDetector::sendaction_2_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.sendaction_2");
}

void OMAnimatedDetector::Inactive_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Inactive");
}

void OMAnimatedDetector::Active_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Active");
}
//#]

IMPLEMENT_REACTIVE_META_S_P(Detector, Default, false, Module, OMAnimatedModule, OMAnimatedDetector)

OMINIT_SUPERCLASS(Module, OMAnimatedModule)

OMREGISTER_REACTIVE_CLASS
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Detector.cpp
*********************************************************************/
