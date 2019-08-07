#pragma once
#ifndef __TLLM_INTERNAL_H__
#define __TLLM_INTERNAL_H__

#include "tllm.h"

/***************************************
 * Library context
 * - holds current state
 ***************************************/
struct _tllmContext
{
};

/***************************************
 * Some basic memory management wrappers
 ***************************************/
#include <stdlib.h>
#define tllmMalloc(x) (x*)malloc(sizeof(x))
#define tllmFree(x)   free(x)

/***************************************
 * Error handling
 ***************************************/
extern tllmReturn  g_tllmError;
extern const char* g_tllmErrors[];
#define tllmReturn()				\
    {						\
	return g_tllmError;			\
    }
#define tllmReturnCode(x)			\
    {						\
	g_tllmError = TLLM_##x;			\
	return TLLM_##x;			\
    }

#define tllmAssert(CHECK,ERROR)			\
    if( !(CHECK) )				\
    {						\
	g_tllmError = TLLM_##ERROR;		\
	return TLLM_##ERROR;			\
    }

#endif/*__TLLM_INTERNAL_H__*/
