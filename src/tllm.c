#include "tllm_internal.h"

tllmReturn tllmClearContext(tllmContext* context)
{
    tllmReturn(SUCCESS);
}

tllmReturn tllmInitContext(tllmContext** context)
{
    if(context == 0)
        tllmReturn(NO_CONTEXT);
    *context = tllmMalloc(tllmContext);
    if(tllmClearContext(*context) != TLLM_SUCCESS)
	   tllmTerminateContext(context);
    tllmReturn(SUCCESS);
}

tllmReturn tllmTerminateContext(tllmContext** context)
{
    if(*context == 0)
	   tllmReturn(NO_CONTEXT);

    tllmFree(*context);
    *context = 0;
    tllmReturn(SUCCESS);
}

const char* tllmError()
{
    return g_tllmErrors[g_tllmError];
}
