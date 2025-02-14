













 
#define	PURE_C_SOURCE
#include "stdio_64.h"
#include <dce/dce_error.h>
#include <dce/rpc.h>
#include "SMI_InterFace.h"
#include "Intellect_Common.h"
#include "CR_Common.h"
#define	S_CDS_PATH_LEN	100

int int_no_context_used=0;

main(int argc, char ** argv)
{
	unsigned32				status_ind, status1;
	dce_error_string_t	error_string;
	rpc_binding_vector_t	*binding_vector;
	char						chr_cds_path[S_CDS_PATH_LEN];
	DEBUG_INFO_STRUCT_H			*l_debug_info_ptr;
	uuid_vector_t *uuid_list;

	if ( argc < 2 )
	{
		fprintf(stderr,"usage : [Server Name] [No of connections to take]");
		exit(1);
	}

	int_no_context_used = atoi(argv[1]);
	
	if(CO_AppInit( chr_cds_path,
						&uuid_list,
						l_debug_info_ptr)==APL_FAILURE)
						exit(-1);


	strcat(chr_cds_path,"/SMI_Server");

	
	rpc_server_use_all_protseqs(1,
										(unsigned32 *) &status_ind
										);
	if (status_ind != rpc_s_ok)
	{
		dce_error_inq_text(status_ind, error_string, &status1);
		fprintf(stderr, "%s\n", error_string);
		exit(1);
	}

	

	rpc_server_inq_bindings( &binding_vector, (unsigned32 *)&status_ind);
	if (status_ind != rpc_s_ok)
	{
		dce_error_inq_text(status_ind, error_string, &status1);
		fprintf(stderr, "%s\n", error_string);
		exit(1);
	}

	

	rpc_ep_register(core_smi_v1_0_s_ifspec,
						binding_vector,
						(uuid_vector_t*)uuid_list,
						"Endpoint for SMI_Server",
						(unsigned32*) &status_ind
						);
	if (status_ind != rpc_s_ok)
	{
		dce_error_inq_text(status_ind, error_string, &status1);
		fprintf(stderr, "%s\n", error_string);
		exit(1);
	}

	

	rpc_ns_binding_export(rpc_c_ns_syntax_dce,
								chr_cds_path,
								core_smi_v1_0_s_ifspec,
								binding_vector,
								(uuid_vector_t*)uuid_list,
								(unsigned32 *) &status_ind);
	if (status_ind != rpc_s_ok)
	{
		dce_error_inq_text(status_ind, error_string, &status1);
		fprintf(stderr, "%s\n", error_string);
		exit(1);
	}

	

	rpc_server_register_if(core_smi_v1_0_s_ifspec,
									(uuid_t *)NULL,
									(rpc_mgr_epv_t)NULL,
									(unsigned32 *)&status_ind
									);
	if (status_ind != rpc_s_ok)
	{
		dce_error_inq_text(status_ind, error_string, &status1);
		fprintf(stderr, "%s\n", error_string);
		exit(1);
	}

    
   rpc_mgmt_set_server_stack_size(2*262144, (unsigned32 *)&status_ind);
   if (status_ind != rpc_s_ok)
   {
      dce_error_inq_text(status_ind, error_string, &status1);
      fprintf(stderr, "%s\n", error_string);
      exit(1);
   }

	

	rpc_server_listen(int_no_context_used, (unsigned32 *)&status_ind);
	if (status_ind != rpc_s_ok)
	{
		dce_error_inq_text(status_ind, error_string, &status1);
		fprintf(stderr, "%s\n", error_string);
		exit(1);
	}

	rpc_ns_binding_unexport(rpc_c_ns_syntax_dce,
									chr_cds_path,
									core_smi_v1_0_s_ifspec,
									(uuid_vector_t*)NULL,
									(unsigned32 *)&status_ind);
	if (status_ind != rpc_s_ok)
	{
		dce_error_inq_text(status_ind, error_string, &status1);
		fprintf(stderr, "%s\n", error_string);
		exit(1);
	}

	rpc_ep_unregister(core_smi_v1_0_s_ifspec,
							binding_vector,
							(uuid_vector_t*)NULL,
							&status_ind);
	if (status_ind != rpc_s_ok)
	{
		dce_error_inq_text(status_ind, error_string, &status1);
		fprintf(stderr, "%s\n", error_string);
		exit(1);
	}

	rpc_server_unregister_if(core_smi_v1_0_s_ifspec,
										(uuid_t *)NULL,
										&status_ind);

	if (status_ind != rpc_s_ok)
	{
		dce_error_inq_text(status_ind, error_string, &status1);
		fprintf(stderr, "%s\n", error_string);
		exit(1);
	}
}
