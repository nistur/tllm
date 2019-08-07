#include "tllm-tests.h"
#include "tllm.h"

TEST(InitTerminate, Basic, 0.0f,
     // initialisation
     {
	 m_data.context = 0;
     },
     // cleanup
     {
	 tllmTerminateContext(&m_data.context);
     },
     // test
     {
	 ASSERT(tllmInitContext(&m_data.context) == TLLM_SUCCESS);
      ASSERT(m_data.context != 0);
	 ASSERT(tllmTerminateContext(&m_data.context) == TLLM_SUCCESS);
      ASSERT(m_data.context == 0)
     },
     // data
     {
	 tllmContext* context;
     }
    );
