#include "tllm_internal.h"

tllmReturn tllmClearContext(tllmContext* context)
{
    tllmReturnCode(SUCCESS);
}

tllmReturn tllmInitContext(tllmContext** context)
{
    tllmAssert(context != 0, NO_CONTEXT);
    
    *context = tllmMalloc(tllmContext);
    if(tllmClearContext(*context) != TLLM_SUCCESS)
    {
	tllmTerminateContext(context);
	tllmReturn();
    }
    tllmReturnCode(SUCCESS);
}

tllmReturn tllmTerminateContext(tllmContext** context)
{
    tllmAssert(context != 0, NO_CONTEXT);
    tllmAssert(*context != 0, NO_CONTEXT);

    tllmFree(*context);
    *context = 0;
    tllmReturnCode(SUCCESS);
}

tllmReturn tllmExecute(tllmContext* context, tllmProgram program)
{
    tllmAssert(context != 0, NO_CONTEXT);

    tllmProgram programCounter = program;
    while( programCounter )
    {
	tllmInstruction = *programCounter;
    }
    
    tllmReturnCode(SUCCESS);
}

const char* tllmError()
{
    return g_tllmErrors[g_tllmError];
}
