/*********************************************************************
	Rhapsody	: 10.0.1 
	Login		: LabPOIO-29
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Drive
//!	Generated Date	: Tue, 9, Jun 2026  
	File Path	: DefaultComponent/DefaultConfig/Drive.h
*********************************************************************/

#ifndef Drive_H
#define Drive_H

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
//## class Drive
#include "Module.h"
//## link itsController
class Contoller;

//## package Default

//## class Drive
class Drive : public OMReactive, public Module {
    ////    Friends    ////
    
public :

#ifdef _OMINSTRUMENT
    friend class OMAnimatedDrive;
#endif // _OMINSTRUMENT

    ////    Constructors and destructors    ////
    
    //## auto_generated
    Drive(IOxfActive* theActiveContext = 0);
    
    //## auto_generated
    ~Drive();
    
    ////    Additional operations    ////
    
    //## auto_generated
    bool getDirection() const;
    
    //## auto_generated
    void setDirection(bool p_direction);
    
    //## auto_generated
    float getPeriod() const;
    
    //## auto_generated
    void setPeriod(float p_period);
    
    //## auto_generated
    float getVelocity() const;
    
    //## auto_generated
    void setVelocity(float p_velocity);
    
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
    
    //## auto_generated
    void cancelTimeouts();
    
    //## auto_generated
    bool cancelTimeout(const IOxfTimeout* arg);
    
    ////    Attributes    ////
    
    bool direction;		//## attribute direction
    
    float period;		//## attribute period
    
    float velocity;		//## attribute velocity
    
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
    enum Drive_Enum {
        OMNonState = 0,
        sendaction_2 = 1,
        Inactive = 2,
        Active = 3
    };
    
    int rootState_subState;
    
    int rootState_active;
    
    IOxfTimeout* rootState_timeout;
//#]
};

#ifdef _OMINSTRUMENT
//#[ ignore
class OMAnimatedDrive : public OMAnimatedModule {
    DECLARE_REACTIVE_META(Drive, OMAnimatedDrive)
    
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

inline bool Drive::rootState_IN() const {
    return true;
}

inline bool Drive::sendaction_2_IN() const {
    return rootState_subState == sendaction_2;
}

inline bool Drive::Inactive_IN() const {
    return rootState_subState == Inactive;
}

inline bool Drive::Active_IN() const {
    return rootState_subState == Active;
}

#endif
/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Drive.h
*********************************************************************/
