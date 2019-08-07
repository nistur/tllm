#include "tllm_internal.h"

tllmReturn tllmClearContext(tllmContext* context)
{
    tllmReturnCode(SUCCESS);
}

tllmReturn tllmInitContext(tllmContext** context)
{
    tllmAssert((context != 0), NO_CONTEXT);
    
    *context = tllmMalloc(tllmContext);
    if(tllmClearContext(*context) != TLLM_SUCCESS)
	   tllmTerminateContext(context);
    tllmReturnCode(SUCCESS);
}

tllmReturn tllmTerminateContext(tllmContext** context)
{
    tllmAssert((*context != 0), NO_CONTEXT);

    tllmFree(*context);
    *context = 0;
    tllmReturnCode(SUCCESS);
}

const char* tllmError()
{
    return g_tllmErrors[g_tllmError];
}
