#pragma once
#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__
#ifdef __cplusplus
extern "C" {
#endif/*__cplusplus*/

#ifdef TLLM_DYNAMIC
# ifdef WIN32
#  ifdef TLLM_BUILD
#   define TLLM_EXPORT __declspec( dllexport )
#  else
#   define TLLM_EXPORT __declspec( dllimport )
#  endif
# endif
#endif
 
#ifndef TLLM_EXPORT
# define TLLM_EXPORT
#endif

typedef int tllmReturn;

typedef struct _tllmContext tllmContext;

#define TLLM_SUCCESS    0
#define TLLM_NO_CONTEXT 1

TLLM_EXPORT tllmReturn   tllmInitContext     (tllmContext** context);
TLLM_EXPORT tllmReturn   tllmTerminateContext(tllmContext** context);
TLLM_EXPORT const char*  tllmError();

#ifdef __cplusplus
}
#endif/*__cplusplus*/
#endif/*__TEMPLATE_H__*/
