/********************************************************************
	Rhapsody	: 10.0.1 
	Login		: LabPOIO-29
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Tue, 9, Jun 2026  
	File Path	: DefaultComponent/DefaultConfig/Default.cpp
*********************************************************************/

//#[ ignore
#define NAMESPACE_PREFIX
//#]

//## auto_generated
#include "Default.h"
//## classInstance itsController
#include "Contoller.h"
//## auto_generated
#include "Detector.h"
//## auto_generated
#include "Display.h"
//## auto_generated
#include "Drive.h"
//## auto_generated
#include "Keyboard.h"
//## auto_generated
#include "Lamp.h"
//## auto_generated
#include "Module.h"
//## auto_generated
#include "Receiver.h"
//#[ ignore
#define eventmessage_1_SERIALIZE OM_NO_OP

#define eventmessage_1_UNSERIALIZE OM_NO_OP

#define eventmessage_1_CONSTRUCTOR eventmessage_1()

#define evSignal_SERIALIZE OM_NO_OP

#define evSignal_UNSERIALIZE OM_NO_OP

#define evSignal_CONSTRUCTOR evSignal()

#define set_state_SERIALIZE OM_NO_OP

#define set_state_UNSERIALIZE OM_NO_OP

#define set_state_CONSTRUCTOR set_state()

#define evStart_SERIALIZE OMADD_SER(state, x2String((int)myEvent->state))

#define evStart_UNSERIALIZE OMADD_UNSER(int, state, OMDestructiveString2X)

#define evStart_CONSTRUCTOR evStart(state)

#define evStep_SERIALIZE OMADD_SER(disp, x2String(myEvent->disp))

#define evStep_UNSERIALIZE OMADD_UNSER(float, disp, OMDestructiveString2X)

#define evStep_CONSTRUCTOR evStep(disp)

#define eventmessage_0_SERIALIZE OM_NO_OP

#define eventmessage_0_UNSERIALIZE OM_NO_OP

#define eventmessage_0_CONSTRUCTOR eventmessage_0()

#define evCheckCollision_SERIALIZE OM_NO_OP

#define evCheckCollision_UNSERIALIZE OM_NO_OP

#define evCheckCollision_CONSTRUCTOR evCheckCollision()

#define evCollision_SERIALIZE OM_NO_OP

#define evCollision_UNSERIALIZE OM_NO_OP

#define evCollision_CONSTRUCTOR evCollision()

#define reset_counters_SERIALIZE OM_NO_OP

#define reset_counters_UNSERIALIZE OM_NO_OP

#define reset_counters_CONSTRUCTOR reset_counters()

#define evActivate_SERIALIZE OMADD_SER(active, x2String(myEvent->active))

#define evActivate_UNSERIALIZE OMADD_UNSER(bool, active, OMDestructiveString2X)

#define evActivate_CONSTRUCTOR evActivate(active)

#define evStop_SERIALIZE OM_NO_OP

#define evStop_UNSERIALIZE OM_NO_OP

#define evStop_CONSTRUCTOR evStop()

#define ecStart_SERIALIZE OM_NO_OP

#define ecStart_UNSERIALIZE OM_NO_OP

#define ecStart_CONSTRUCTOR ecStart()

#define evCheckCollison_SERIALIZE OMADD_SER(check_collison, x2String(myEvent->check_collison))

#define evCheckCollison_UNSERIALIZE OMADD_UNSER(bool, check_collison, OMDestructiveString2X)

#define evCheckCollison_CONSTRUCTOR evCheckCollison(check_collison)

#define ecStep_SERIALIZE OM_NO_OP

#define ecStep_UNSERIALIZE OM_NO_OP

#define ecStep_CONSTRUCTOR ecStep()

#define validate_signal_SERIALIZE OM_NO_OP

#define validate_signal_UNSERIALIZE OM_NO_OP

#define validate_signal_CONSTRUCTOR validate_signal()

#define evError_SERIALIZE OM_NO_OP

#define evError_UNSERIALIZE OM_NO_OP

#define evError_CONSTRUCTOR evError()

#define evSuccess_SERIALIZE OM_NO_OP

#define evSuccess_UNSERIALIZE OM_NO_OP

#define evSuccess_CONSTRUCTOR evSuccess()

#define evRegulate_SERIALIZE OM_NO_OP

#define evRegulate_UNSERIALIZE OM_NO_OP

#define evRegulate_CONSTRUCTOR evRegulate()

#define evFirmware_SERIALIZE OM_NO_OP

#define evFirmware_UNSERIALIZE OM_NO_OP

#define evFirmware_CONSTRUCTOR evFirmware()

#define evTest_SERIALIZE OM_NO_OP

#define evTest_UNSERIALIZE OM_NO_OP

#define evTest_CONSTRUCTOR evTest()

#define evFail_SERIALIZE OM_NO_OP

#define evFail_UNSERIALIZE OM_NO_OP

#define evFail_CONSTRUCTOR evFail()

#define evOK_SERIALIZE OM_NO_OP

#define evOK_UNSERIALIZE OM_NO_OP

#define evOK_CONSTRUCTOR evOK()

#define evFAIL_SERIALIZE OM_NO_OP

#define evFAIL_UNSERIALIZE OM_NO_OP

#define evFAIL_CONSTRUCTOR evFAIL()

#define evCheckCollsion_SERIALIZE OM_NO_OP

#define evCheckCollsion_UNSERIALIZE OM_NO_OP

#define evCheckCollsion_CONSTRUCTOR evCheckCollsion()
//#]

//## package Default


//## classInstance itsController
Contoller itsController;

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */);

static void RenameGlobalInstances();

IMPLEMENT_META_PACKAGE(Default, Default)
#endif // _OMINSTRUMENT

void Default_initRelations() {
    {
        {
            itsController.setShouldDelete(false);
        }
    }
    
    #ifdef _OMINSTRUMENT
    RenameGlobalInstances();
    #endif // _OMINSTRUMENT
}

bool Default_startBehavior() {
    bool done = true;
    done &= itsController.startBehavior();
    return done;
}

#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes* /* aomsAttributes */) {
}

static void RenameGlobalInstances() {
    OM_SET_INSTANCE_NAME(&itsController, Contoller, "itsController", AOMNoMultiplicity);
}
#endif // _OMINSTRUMENT

//#[ ignore
Default_OMInitializer::Default_OMInitializer() {
    Default_initRelations();
    Default_startBehavior();
}

Default_OMInitializer::~Default_OMInitializer() {
}
//#]

//## event eventmessage_1()
eventmessage_1::eventmessage_1() {
    NOTIFY_EVENT_CONSTRUCTOR(eventmessage_1)
    setId(eventmessage_1_Default_id);
}

bool eventmessage_1::isTypeOf(const short id) const {
    return (eventmessage_1_Default_id==id);
}

IMPLEMENT_META_EVENT_P(eventmessage_1, Default, Default, eventmessage_1())

//## event evSignal()
evSignal::evSignal() {
    NOTIFY_EVENT_CONSTRUCTOR(evSignal)
    setId(evSignal_Default_id);
}

bool evSignal::isTypeOf(const short id) const {
    return (evSignal_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evSignal, Default, Default, evSignal())

//## event set_state()
set_state::set_state() {
    NOTIFY_EVENT_CONSTRUCTOR(set_state)
    setId(set_state_Default_id);
}

bool set_state::isTypeOf(const short id) const {
    return (set_state_Default_id==id);
}

IMPLEMENT_META_EVENT_P(set_state, Default, Default, set_state())

//## event evStart(States)
//#[ ignore
evStart::evStart(int p_state) : state((States)p_state) {
    NOTIFY_EVENT_CONSTRUCTOR(evStart)
    setId(evStart_Default_id);
}
//#]

evStart::evStart() {
    NOTIFY_EVENT_CONSTRUCTOR(evStart)
    setId(evStart_Default_id);
}

evStart::evStart(States p_state) : state(p_state) {
    NOTIFY_EVENT_CONSTRUCTOR(evStart)
    setId(evStart_Default_id);
}

bool evStart::isTypeOf(const short id) const {
    return (evStart_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evStart, Default, Default, evStart(States))

//## event evStep(float)
evStep::evStep() {
    NOTIFY_EVENT_CONSTRUCTOR(evStep)
    setId(evStep_Default_id);
}

evStep::evStep(float p_disp) : disp(p_disp) {
    NOTIFY_EVENT_CONSTRUCTOR(evStep)
    setId(evStep_Default_id);
}

bool evStep::isTypeOf(const short id) const {
    return (evStep_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evStep, Default, Default, evStep(float))

//## event eventmessage_0()
eventmessage_0::eventmessage_0() {
    NOTIFY_EVENT_CONSTRUCTOR(eventmessage_0)
    setId(eventmessage_0_Default_id);
}

bool eventmessage_0::isTypeOf(const short id) const {
    return (eventmessage_0_Default_id==id);
}

IMPLEMENT_META_EVENT_P(eventmessage_0, Default, Default, eventmessage_0())

//## event evCheckCollision()
evCheckCollision::evCheckCollision() {
    NOTIFY_EVENT_CONSTRUCTOR(evCheckCollision)
    setId(evCheckCollision_Default_id);
}

bool evCheckCollision::isTypeOf(const short id) const {
    return (evCheckCollision_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evCheckCollision, Default, Default, evCheckCollision())

//## event evCollision()
evCollision::evCollision() {
    NOTIFY_EVENT_CONSTRUCTOR(evCollision)
    setId(evCollision_Default_id);
}

bool evCollision::isTypeOf(const short id) const {
    return (evCollision_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evCollision, Default, Default, evCollision())

//## event reset_counters()
reset_counters::reset_counters() {
    NOTIFY_EVENT_CONSTRUCTOR(reset_counters)
    setId(reset_counters_Default_id);
}

bool reset_counters::isTypeOf(const short id) const {
    return (reset_counters_Default_id==id);
}

IMPLEMENT_META_EVENT_P(reset_counters, Default, Default, reset_counters())

//## event evActivate(bool)
evActivate::evActivate() {
    NOTIFY_EVENT_CONSTRUCTOR(evActivate)
    setId(evActivate_Default_id);
}

evActivate::evActivate(bool p_active) : active(p_active) {
    NOTIFY_EVENT_CONSTRUCTOR(evActivate)
    setId(evActivate_Default_id);
}

bool evActivate::isTypeOf(const short id) const {
    return (evActivate_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evActivate, Default, Default, evActivate(bool))

//## event evStop()
evStop::evStop() {
    NOTIFY_EVENT_CONSTRUCTOR(evStop)
    setId(evStop_Default_id);
}

bool evStop::isTypeOf(const short id) const {
    return (evStop_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evStop, Default, Default, evStop())

//## event ecStart()
ecStart::ecStart() {
    NOTIFY_EVENT_CONSTRUCTOR(ecStart)
    setId(ecStart_Default_id);
}

bool ecStart::isTypeOf(const short id) const {
    return (ecStart_Default_id==id);
}

IMPLEMENT_META_EVENT_P(ecStart, Default, Default, ecStart())

//## event evCheckCollison(bool)
evCheckCollison::evCheckCollison() {
    NOTIFY_EVENT_CONSTRUCTOR(evCheckCollison)
    setId(evCheckCollison_Default_id);
}

evCheckCollison::evCheckCollison(bool p_check_collison) : check_collison(p_check_collison) {
    NOTIFY_EVENT_CONSTRUCTOR(evCheckCollison)
    setId(evCheckCollison_Default_id);
}

bool evCheckCollison::isTypeOf(const short id) const {
    return (evCheckCollison_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evCheckCollison, Default, Default, evCheckCollison(bool))

//## event ecStep()
ecStep::ecStep() {
    NOTIFY_EVENT_CONSTRUCTOR(ecStep)
    setId(ecStep_Default_id);
}

bool ecStep::isTypeOf(const short id) const {
    return (ecStep_Default_id==id);
}

IMPLEMENT_META_EVENT_P(ecStep, Default, Default, ecStep())

//## event validate_signal()
validate_signal::validate_signal() {
    NOTIFY_EVENT_CONSTRUCTOR(validate_signal)
    setId(validate_signal_Default_id);
}

bool validate_signal::isTypeOf(const short id) const {
    return (validate_signal_Default_id==id);
}

IMPLEMENT_META_EVENT_P(validate_signal, Default, Default, validate_signal())

//## event evError()
evError::evError() {
    NOTIFY_EVENT_CONSTRUCTOR(evError)
    setId(evError_Default_id);
}

bool evError::isTypeOf(const short id) const {
    return (evError_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evError, Default, Default, evError())

//## event evSuccess()
evSuccess::evSuccess() {
    NOTIFY_EVENT_CONSTRUCTOR(evSuccess)
    setId(evSuccess_Default_id);
}

bool evSuccess::isTypeOf(const short id) const {
    return (evSuccess_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evSuccess, Default, Default, evSuccess())

//## event evRegulate()
evRegulate::evRegulate() {
    NOTIFY_EVENT_CONSTRUCTOR(evRegulate)
    setId(evRegulate_Default_id);
}

bool evRegulate::isTypeOf(const short id) const {
    return (evRegulate_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evRegulate, Default, Default, evRegulate())

//## event evFirmware()
evFirmware::evFirmware() {
    NOTIFY_EVENT_CONSTRUCTOR(evFirmware)
    setId(evFirmware_Default_id);
}

bool evFirmware::isTypeOf(const short id) const {
    return (evFirmware_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evFirmware, Default, Default, evFirmware())

//## event evTest()
evTest::evTest() {
    NOTIFY_EVENT_CONSTRUCTOR(evTest)
    setId(evTest_Default_id);
}

bool evTest::isTypeOf(const short id) const {
    return (evTest_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evTest, Default, Default, evTest())

//## event evFail()
evFail::evFail() {
    NOTIFY_EVENT_CONSTRUCTOR(evFail)
    setId(evFail_Default_id);
}

bool evFail::isTypeOf(const short id) const {
    return (evFail_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evFail, Default, Default, evFail())

//## event evOK()
evOK::evOK() {
    NOTIFY_EVENT_CONSTRUCTOR(evOK)
    setId(evOK_Default_id);
}

bool evOK::isTypeOf(const short id) const {
    return (evOK_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evOK, Default, Default, evOK())

//## event evFAIL()
evFAIL::evFAIL() {
    NOTIFY_EVENT_CONSTRUCTOR(evFAIL)
    setId(evFAIL_Default_id);
}

bool evFAIL::isTypeOf(const short id) const {
    return (evFAIL_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evFAIL, Default, Default, evFAIL())

//## event evCheckCollsion()
evCheckCollsion::evCheckCollsion() {
    NOTIFY_EVENT_CONSTRUCTOR(evCheckCollsion)
    setId(evCheckCollsion_Default_id);
}

bool evCheckCollsion::isTypeOf(const short id) const {
    return (evCheckCollsion_Default_id==id);
}

IMPLEMENT_META_EVENT_P(evCheckCollsion, Default, Default, evCheckCollsion())

/*********************************************************************
	File Path	: DefaultComponent/DefaultConfig/Default.cpp
*********************************************************************/
