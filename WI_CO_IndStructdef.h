/*Code Added by amitk 05-03-2007*/
typedef struct{
        short i_client;
        short i_identiy_no;
        short i_deal_cd;
        short i_instr_code;
        short i_instr_name;
        short i_qty;
        short i_exch_code;
        short i_deal_date;
        short i_cost;
        short i_setl_date;
        short i_net_amt;
        short i_mkt_type;
        short i_brokercomm;
        short i_stx_comm;
        short i_domestic_cpclt;
        short i_domestic_cpclt_name;
        short i_clh_flag;
        short i_fx_reqd;
        short i_maker;
        short i_maker_dt;
        short i_checker;
        short i_checker_dt;
        short i_deal_stat;
        short i_proc_flag;
        short i_access_stamp;
	short i_gross_rate; /* JC - 21-04-2007 */
        short i_contract_cd; /* Added by Mangesh for Web - Alleged deal creation enh 28-11-2011*/
	short i_stamp_duty;
}WI_DEAL_STRUCT_I;

/*Code Added by Amitk 05-03-2007*/

/* JC - RFS_CA_020  -- Start */
typedef struct{
        short i_corp_id;
        short i_instr_code;
        short i_cln_code;
        short i_ca_event;
        short i_instruc_date;
        short i_inp_qty;
        short i_over_sub;
        short i_maker;
        short i_maker_dt;
        short i_checker;
        short i_checker_dt;
        short i_access_stamp;
        short i_instructed;
        short i_status;
        short i_no_action;
        short i_num_of_resolutions;
}CA_INSTRUCTION_STRUCT_I;
/* JC - RFS_CA_020  -- End */

/* By Harvinder Singh RFS NO - RFS_CMM_001 Date 12/04/2007 - Start */
typedef struct{
        short i_client_code;
        short i_serial_no;
        short i_input_date;
        short i_information;
        short i_maker;
        short i_maker_dt;
        short i_checker;
        short i_checker_dt;
        short i_access_stamp;
        short i_status;
}WI_WEB_MANUAL_MSG_STRUCT_I;

/* By Harvinder Singh RFS NO - RFS_CMM_001 Date 12/04/2007 - End */
//Added For PMS
typedef struct{
        short i_sell_client;
        short i_buy_client;
        short i_instr_isin;
        short i_deal_date;
        short i_qty;
        short i_cost;
        short i_domestic_cpclt;
        short i_cpclt;
        short i_origquantity;
        short i_amt;
        short i_net_amt;
        short i_clh_flg;
        short i_ex_arena;
        short i_setldt;
        short i_dealcd;
        short i_access_stamp;
        short i_classofdl;
        short i_entry;
        short i_fx_reqd;
        short i_info1;
        short i_maker;
        short i_maker_dt;
        short i_checker;
        short i_checker_dt;
        short i_allow_part_s;
        short i_ispymtlocal;
        short i_reginstr_ind;
        short i_isspotdl;
        short i_identiy_no;
	short h_trd_exch;
	short i_trd_mkt_type;
	short i_trd_setl_no;
	short i_payin_dt;
	short i_payout_dt;
        short i_stamp_duty; /* SNOW- CS0046502 Added by Shradha for Stamp Duty Enh. */
}WI_DEAL_PMS_STRUCT_I;

