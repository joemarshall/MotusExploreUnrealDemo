/* 
 * Copyright (c) 2022 Anders Dahnielson <anders@dahnielson.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of 
 * this software and associated documentation files (the "Software"), to deal in the 
 * Software without restriction, including without limitation the rights to use, copy, 
 * modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, 
 * and to permit persons to whom the Software is furnished to do so, subject to the 
 * following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all 
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT 
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "UExploreAndroid.h"
#include "ExploreDevice.h"
#define LOCTEXT_NAMESPACE "UExplorePlugin"

TSharedPtr<class IInputDevice> FUExploreAndroidModule::CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
{
	ExploreDevice = MakeShareable(new FExploreDevice(InMessageHandler));
	return ExploreDevice;
}

void FUExploreAndroidModule::StartupModule()
{
	IInputDeviceModule::StartupModule();

	const FName NAME_Motus(TEXT("Motus"));

	EKeys::AddMenuCategoryDisplayInfo(NAME_Motus, LOCTEXT("MotusSubCategory", "Motus"), TEXT("GraphEditor.KeyEvent_16x"));	
	EKeys::AddKey(FKeyDetails(Bindings::Axis2_Key, LOCTEXT("Motus_ExploreForward", "ExploreForward"), FKeyDetails::ButtonAxis, NAME_Motus));
}

void FUExploreAndroidModule::ShutdownModule()
{
	IInputDeviceModule::ShutdownModule();
}

IMPLEMENT_MODULE(FUExploreAndroidModule, UExploreAndroid)
