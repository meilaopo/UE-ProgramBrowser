#pragma once

#include "CoreMinimal.h"

#if PLATFORM_WINDOWS
#include <windows.h>
#include <tchar.h>
#endif
#include <stdio.h>

/**
 * 
*/
class FProgramModuleResource
{
public:
    FProgramModuleResource(const FString& ExeFile, bool bDeleteExistingResources);
    ~FProgramModuleResource();

    bool SetData(int32 ResourceId, void* Data, int32 DataLen);

    bool SetIcon(TArray<uint8>& GroupData, TArray<uint8>& IcoData);

private:

#if PLATFORM_WINDOWS
    HANDLE Handle = nullptr;
#endif
};