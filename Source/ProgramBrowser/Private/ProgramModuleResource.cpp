

#include "ProgramModuleResource.h"


FProgramModuleResource::FProgramModuleResource(const FString& ExeFile, bool bDeleteExistingResources)
{
#if PLATFORM_WINDOWS
    Handle = BeginUpdateResource(*ExeFile, bDeleteExistingResources);
    if (!Handle)
    {
        UE_LOG(LogTemp, Error, TEXT("File: %s BeginUpdateResource Failed!"), *ExeFile);
    }
#endif
}

FProgramModuleResource::~FProgramModuleResource()
{
#if PLATFORM_WINDOWS
    EndUpdateResource(Handle, false);
#endif
}

bool FProgramModuleResource::SetData(int32 ResourceId, void* Data, int32 DataLen)
{
#if PLATFORM_WINDOWS
    if (!UpdateResource(Handle, RT_RCDATA, MAKEINTRESOURCE(ResourceId), 1033, Data, DataLen))
    {
        UE_LOG(LogTemp, Error, TEXT("UpdateResource failed!"));
        return false;
    }
#endif
    return true;
}

bool FProgramModuleResource::SetIcon(TArray<uint8>& GroupData, TArray<uint8>& IcoData)
{
#if PLATFORM_WINDOWS
    if (!UpdateResource(Handle, RT_GROUP_ICON, MAKEINTRESOURCE(101), 1033, GroupData.GetData(), GroupData.Num()))
    {
        UE_LOG(LogTemp, Error, TEXT("UpdateResource failed!"));
        return false;
    }

    if (!UpdateResource(Handle, RT_ICON, MAKEINTRESOURCE(1), 1033, IcoData.GetData(), IcoData.Num()))
    {
        UE_LOG(LogTemp, Error, TEXT("UpdateResource failed!"));
        return false;
    }
#endif
    return true;
}