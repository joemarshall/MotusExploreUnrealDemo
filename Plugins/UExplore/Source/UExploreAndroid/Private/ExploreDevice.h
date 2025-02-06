#pragma once

#include"UExploreAndroid.h"

struct Bindings
{
    static const FGamepadKeyNames::Type Axis2_Type;
	static const FKey Axis2_Key;
};

class FExploreDevice: public IExploreDevice
{
    public:
	FExploreDevice(const TSharedRef<FGenericApplicationMessageHandler> &InMessageHandler);
	virtual ~FExploreDevice() override ;

    virtual void SendControllerEvents() override;

	virtual void Tick(float DeltaTime) override
    {}
	/** Set which MessageHandler will get the events from SendControllerEvents. */
	virtual void SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler> &InMessageHandler) override
    {
        MessageHandler=InMessageHandler;
    }
	/** Exec handler to allow console commands to be passed through for debugging */
	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override
    {
        return false;

    };
	// IForceFeedbackSystem pass through functions
	virtual void SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) override
    {

    };
	virtual void SetChannelValues(int32 ControllerId, const FForceFeedbackValues &Values) override
    {

    };


private:
    FPlatformUserId UnrealUserID;
    FInputDeviceId UnrealDeviceID;
    float ValueFloat;
    TSharedPtr<FGenericApplicationMessageHandler> MessageHandler;

};