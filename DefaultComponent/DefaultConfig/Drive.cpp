/********************************************************************
	Rhapsody	: 10.0.1 
	Login		: LabPOIO-29
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Drive
//!	Generated Date	: Tue, 9, Jun 2026  
	File Path	: DefaultComponent/DefaultConfig/Drive.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX

#define _OMSTATECHART_ANIMATED
//#]

//## auto_generated
#include "Drive.h"
//## link itsController
#include "Contoller.h"
//#[ ignore
#define Default_Drive_Drive_SERIALIZE OM_NO_OP
//#]

//## package Default

//## class Drive
Drive::Drive(IOxfActive* theActiveContext) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Drive, Drive(), 0, Default_Drive_Drive_SERIALIZE);
    setActiveContext(theActiveContext, false);
    itsController = NULL;
    initStatechart();
}

Drive::~Drive() {
    NOTIFY_DESTRUCTOR(~Drive, false);
    cleanUpRelations();
    cancelTimeouts();
}

bool Drive::getDirection() const {
    return direction;
}

void Drive::setDirection(bool p_direction) {
    direction = p_direction;
}

float Drive::getPeriod() const {
    return period;
}

void Drive::setPeriod(float p_period) {
    period = p_period;
}

float Drive::getVelocity() const {
    return velocity;
}

void Drive::setVelocity(float p_velocity) {
    velocity = p_velocity;
}

Contoller* Drive::getItsController() const {
    return itsController;
}

void Drive::setItsController(Contoller* p_Contoller) {
    _setItsController(p_Contoller);
}

bool Drive::startBehavior() {
    bool done = false;
    done = OMReactive::startBehavior();
    return done;
}

void Drive::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    rootState_timeout = NULL;
}

void Drive::cleanUpRelations() {
    if(itsController != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsController");
            itsController = NULL;
        }
}

void Drive::cancelTimeouts() {
    cancel(rootState_timeout);
}

bool Drive::cancelTimeout(const IOxfTimeout* arg) {
    bool res = false;
    if(rootState_timeout == arg)
        {
            rootState_timeout = NULL;
            res = true;
        }
    return res;
}

void Drive::__setItsController(Contoller* p_Contoller) {
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

void Drive::_setItsController(Contoller* p_Contoller) {
    __setItsController(p_Contoller);
}

void Drive::_clearItsController() {
    NOTIFY_RELATION_CLEARED("itsController");
    itsController = NULL;
}

void Drive::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.Inactive");
        rootState_subState = Inactive;
        rootState_active = Inactive;
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

IOxfReactive::TakeEventStatus Drive::rootState_processEvent() {
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
                    //#[ transition 2 
                    direction = params->state;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.Active");
                    rootState_subState = Active;
                    rootState_active = Active;
                    rootState_timeout = scheduleTimeout(period, "ROOT.Active");
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
                    NOTIFY_TRANSITION_STARTED("1");
                    cancel(rootState_timeout);
                    NOTIFY_STATE_EXITED("ROOT.Active");
                    NOTIFY_STATE_ENTERED("ROOT.Inactive");
                    rootState_subState = Inactive;
                    rootState_active = Inactive;
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(OMTimeoutEventId))
                {
                    if(getCurrentEvent() == rootState_timeout)
                        {
                            NOTIFY_TRANSITION_STARTED("4");
                            cancel(rootState_timeout);
                            NOTIFY_STATE_EXITED("ROOT.Active");
                            //#[ transition 4 
                            std::cout<<"\nDrive: period="<<period<<", velocity="<<velocity<<", dir="<<direction;
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.sendaction_2");
                            pushNullTransition();
                            rootState_subState = sendaction_2;
                            rootState_active = sendaction_2;
                            //#[ state sendaction_2.(Entry) 
                            itsController->GEN(evStep());
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
                    NOTIFY_TRANSITION_STARTED("3");
                    popNullTransition();
                    NOTIFY_STATE_EXITED("ROOT.sendaction_2");
                    NOTIFY_STATE_ENTERED("ROOT.Active");
                    rootState_subState = Active;
                    rootState_active = Active;
                    rootState_timeout = scheduleTimeout(period, "ROOT.Active");
                    NOTIFY_TRANSITION_TERMINATED("3");
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
void OMAnimatedDrive::serializeAttributes(AOMSAttributes* aomsAttributes) const {
    aomsAttributes->addAttribute("direction", x2String(myReal->direction));
    aomsAttributes->addAttribute("period", x2String(myReal->period));
    aomsAttributes->addAttribute("velocity", x2String(myReal->velocity));
    OMAnimatedModule::serializeAttributes(aomsAttributes);
}

void OMAnimatedDrive::serializeRelations(AOMSRelations* aomsRelations) const {
    aomsRelations->addRelation("itsController", false, true);
    if(myReal->itsController)
        {
            aomsRelations->ADD_ITEM(myReal->itsController);
        }
    OMAnimatedModule::serializeRelations(aomsRelations);
}

void OMAnimatedDrive::rootState_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Drive::Inactive:
        {
            Inactive_serializeStates(aomsState);
        }
        break;
        case Drive::Active:
        {
            Active_serializeStates(aomsState);
        }
        break;
        case Drive::sendaction_2:
        {
            sendaction_2_serializeStates(aomsState);
        }
        break;
        default:
            break;
    }
}

void OMAnimatedDrive::sendaction_2_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.sendaction_2");
}

void OMAnimatedDrive::Inactive_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Inactive");
}

void OMAnimatedDrive::Active_serializeStates(AOMSState* aomsState) const {
    aomsState->addState("ROOT.Active");
}
//#]

IMPLEMENT_REACTIVE_META_S_P(Drive, Default, false, Module, OMAnimatedModule, OMAnimatedDrive)

OMINIT_SUPERCLASS(Module, OMAnimatedModule)

OMREGISTER_REACTIVE_CLASS
#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Drive.cpp
*********************************************************************/
