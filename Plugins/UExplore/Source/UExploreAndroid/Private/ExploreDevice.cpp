#include"ExploreDevice.h"
#include"InputCoreTypes.h"

DEFINE_LOG_CATEGORY_STATIC(LogExploreDevice, Log, All);

const FGamepadKeyNames::Type Bindings::Axis2_Type("Motus_ExploreForward");
const FKey Bindings::Axis2_Key(Bindings::Axis2_Type);

FExploreDevice::FExploreDevice(const TSharedRef<FGenericApplicationMessageHandler> &InMessageHandler):IExploreDevice(InMessageHandler)
{
    // allocate unreal device
    UnrealDeviceID = IPlatformInputDeviceMapper::Get().AllocateNewInputDeviceId();
    UnrealUserID  = IPlatformInputDeviceMapper::Get().GetPrimaryPlatformUser();
    IPlatformInputDeviceMapper::Get().Internal_MapInputDeviceToUser(UnrealDeviceID,UnrealUserID, EInputDeviceConnectionState::Connected);

    ValueFloat=0;
}

void FExploreDevice::SendControllerEvents()
{

    auto Player = GEngine->FindFirstLocalPlayerFromPlatformUserId(UnrealUserID);
    if(Player==NULL){
        return;
    }
    auto Controller = Player->PlayerController;
    if(Controller==NULL){
        return;
    }
    auto PlayerInput = Controller->PlayerInput;
    if(PlayerInput==NULL){
        return;
    }
//    float NewValue=PlayerInput->GetKeyValue(EKeys::I);
//    UE_LOG(LogExploreDevice, Log, TEXT("Motus %d Axis  %f "), UnrealDeviceID,  NewValue);
    float NewValue=Controller->PlayerInput->GetKeyValue(EKeys::Gamepad_LeftY);
    if(NewValue!=ValueFloat && MessageHandler!=NULL){
        ValueFloat=NewValue;
           UE_LOG(LogExploreDevice, Log, TEXT("Updating axis"));
//        MessageHandler->OnControllerAnalog(Bindings::Axis2_Type, UnrealUserID, UnrealDeviceID,ValueFloat);
    }
}

FExploreDevice::~FExploreDevice() 
{

}
