#include <dds/DdsDcpsInfrastructureC.h>
#include <dds/DdsDcpsPublicationC.h>

#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/WaitSet.h>

#include <dds/DCPS/StaticIncludes.h>



#define DEFINE_MSG_TYPE(type, dds_type) \
  struct type { \
  using TypeSupportImpl = dds_type##TypeSupportImpl; \
  using TypeSupport_var = dds_type##TypeSupport_var; \
  using DataReader_var = dds_type##DataReader_var; \
  using DataReader = dds_type##DataReader; \
  using DataWriter_var = dds_type##DataWriter_var; \
  using DataWriter = dds_type##DataWriter; \
  using Msg = dds_type; \
  };

