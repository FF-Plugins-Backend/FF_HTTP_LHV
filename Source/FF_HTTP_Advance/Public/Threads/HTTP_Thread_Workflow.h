// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

// UE Includes.
#include "HAL/Runnable.h"

THIRD_PARTY_INCLUDES_START
#ifdef _WIN64
#define UI UI_ST
#include "workflow/Workflow.h"
#include "workflow/HttpMessage.h"
#include "workflow/HttpUtil.h"
#include "workflow/WFServer.h"
#include "workflow/WFHttpServer.h"
#include "workflow/WFFacilities.h"
#include "workflow/WFTaskFactory.h"
#undef UI
#endif
THIRD_PARTY_INCLUDES_END

// Fordward Declerations.
class FRunnableThread;
class AFF_HTTP_Actor;

class FHTTP_Thread_Workflow : public FRunnable
{
	
public:	
	
	// Sets default values for this actor's properties
	FHTTP_Thread_Workflow(AFF_HTTP_Actor* In_Parent_Actor);

	// Destructor.
	virtual ~FHTTP_Thread_Workflow() override;

	virtual bool Init() override;

	virtual uint32 Run() override;

	virtual void Stop() override;

	virtual void Toggle(bool bIsPause);

private:

	virtual void Callback_HTTP_Start();

	FString Server_Address_HTTPS = "";
	FString Server_Address_HTTP = "";
	FString Server_Path_Root = "";
	FString API_URI = "";

private:

	FRunnableThread* RunnableThread = nullptr;
	AFF_HTTP_Actor* Parent_Actor = nullptr;

};
