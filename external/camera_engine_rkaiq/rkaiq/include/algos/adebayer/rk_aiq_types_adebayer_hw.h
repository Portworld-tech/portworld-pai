#ifndef _RK_AIQ_TYPES_ADEBAYER_HW_H_
#define _RK_AIQ_TYPES_ADEBAYER_HW_H_

#define RK_DEBAYER_V2_FIX_BIT_INT_TO_FLOAT      7
#define RK_DEBAYER_V2_FIX_BIT_LOG2              12

#define RK_DEBAYER_V2_FIX_BIT_IIR_WGT_CLIP      3
#define RK_DEBAYER_V2_FIX_BIT_IIR_GHOST         6

#define RK_DEBAYER_V2_FIX_BIT_ALPHA_SCALE       10
#define RK_DEBAYER_V2_FIX_BIT_EDGE_SCALE        10

#define RK_DEBAYER_V2_FIX_BIT_INV_SIGMA         16
#define RK_DEBAYER_V2_FIX_BIT_INV_BF_SIGMA      16

#define RK_DEBAYER_V2_FIX_BIT_WGT_SLOPE         7

#define RK_DEBAYER_V31_FIX_BIT_BF_WGT           7
#define RK_DEBAYER_V31_FIX_BIT_BF_RATIO         10
#define RK_DEBAYER_V31_FIX_BIT_INV_BF_SIGMA     16
#define RK_DEBAYER_V31_FIX_BIT_INV_SIGMA        16
#define RK_DEBAYER_V31_FIX_BIT_INT_TO_FLOAT     7
#define RK_DEBAYER_V31_FIX_BIT_IIR_WGT          6
#define RK_DEBAYER_V31_FIX_BIT_SLOPE            7
#define RK_DEBAYER_V31_FIX_BIT_WGT_RATIO        3
#define RK_DEBAYER_V31_FIX_BIT_CNR_WGT          12
#define RK_DEBAYER_V31_FIX_BIT_LOG2             12
#define RK_DEBAYER_V31_FIX_BIT_GRAD_FLT_ALPHA   6
#define RK_DEBAYER_V31_FIX_BIT_WGT_FLT_ALPHA    6


typedef struct AdebayerHwConfigV1_s {
    unsigned char enable;
    unsigned char filter_c_en;
    unsigned char filter_g_en;
    unsigned char gain_offset;
    unsigned short hf_offset;
    unsigned char thed1;
    unsigned char thed0;
    unsigned char dist_scale;
    unsigned char max_ratio;
    unsigned char clip_en;
    signed char filter1_coe[5];
    signed char filter2_coe[5];
    unsigned char offset;
    unsigned char shift_num;
    unsigned char order_max;
    unsigned char order_min;
    bool updatecfg;
} AdebayerHwConfigV1_t;


typedef struct AdebayerHwConfigV2_s {
    /* CONTROL */
    bool updatecfg;
    unsigned char enable;
    unsigned char filter_g_en;
    unsigned char filter_c_en;
    /* G_INTERP */
    unsigned char clip_en;
    unsigned char dist_scale;
    unsigned char thed0;
    unsigned char thed1;
    unsigned char select_thed;
    unsigned char max_ratio;
    /* G_INTERP_FILTER */
    int  filter1_coe[4];
    int  filter2_coe[4];

    /* C_FILTER_GUIDE_GAUS */
    int  guid_gaus_coe[3];
    /* C_FILTER_CE_GAUS */
    int  ce_gaus_coe[3];
    /* C_FILTER_ALPHA_GAUS */
    int  alpha_gaus_coe[3];

    /* C_FILTER_IIR_0 */
    unsigned char ce_sgm;
    unsigned char exp_shift;
    /* C_FILTER_IIR_1 */
    unsigned char wet_clip;
    unsigned char wet_ghost;
    /* C_FILTER_BF */
    unsigned char bf_clip;
    unsigned char bf_curwgt;
    unsigned short bf_sgm;
    /* G_INTERP_OFFSET */
    unsigned short hf_offset;
    unsigned short gain_offset;
    /* G_FILTER_OFFSET */
    unsigned short offset;
    /* C_FILTER_LOG_OFFSET */
    unsigned short loghf_offset;
    unsigned short loggd_offset;
    /* C_FILTER_IIR_0 */
    unsigned short wgtslope;
    /* C_FILTER_ALPHA */
    unsigned short alpha_offset;
    /* C_FILTER_EDGE */
    unsigned short edge_offset;
    unsigned int edge_scale;
    /* C_FILTER_ALPHA */
    unsigned int alpha_scale;
} AdebayerHwConfigV2_t;

typedef struct AdebayerHwConfigV3_s {
    /* CONTROL */
    bool updatecfg;
    unsigned char enable;
    unsigned char filter_g_en;
    unsigned char filter_c_en;
    /* LUMA_DX */
    unsigned char luma_dx[7];
    /* G_INTERP */
    unsigned char clip_en;
    unsigned char dist_scale;
    unsigned char thed0;
    unsigned char thed1;
    unsigned char select_thed;
    unsigned char max_ratio;
    /* G_INTERP_FILTER1 */
    int filter1_coe1;
    int filter1_coe2;
    int filter1_coe3;
    int filter1_coe4;
    /* G_INTERP_FILTER2 */
    int filter2_coe1;
    int filter2_coe2;
    int filter2_coe3;
    int filter2_coe4;
    /* G_INTERP_OFFSET_ALPHA */
    unsigned short gain_offset;
    unsigned char gradloflt_alpha;
    unsigned char wgt_alpha;
    /* G_INTERP_DRCT_OFFSET */
    unsigned short drct_offset[8];
    /* G_FILTER_MODE_OFFSET */
    unsigned char gfilter_mode;
    unsigned short bf_ratio;
    unsigned short offset;
    /* G_FILTER_FILTER */
    int filter_coe0;
    int filter_coe1;
    int filter_coe2;
    /* G_FILTER_VSIGMA */
    unsigned short vsigma[8];
    /* C_FILTER_GUIDE_GAUS */
    int guid_gaus_coe0;
    int guid_gaus_coe1;
    int guid_gaus_coe2;
    /* C_FILTER_CE_GAUS */
    int ce_gaus_coe0;
    int ce_gaus_coe1;
    int ce_gaus_coe2;
    /* C_FILTER_ALPHA_GAUS */
    int alpha_gaus_coe0;
    int alpha_gaus_coe1;
    int alpha_gaus_coe2;
    /* C_FILTER_LOG_OFFSET */
    unsigned short loghf_offset;
    unsigned short loggd_offset;
    unsigned char log_en;
    /* C_FILTER_ALPHA */
    unsigned short alpha_offset;
    unsigned int alpha_scale;
    /* C_FILTER_EDGE */
    unsigned short edge_offset;
    unsigned int edge_scale;
    /* C_FILTER_IIR_0 */
    unsigned char ce_sgm;
    unsigned char exp_shift;
    unsigned short wgtslope;
    /* C_FILTER_IIR_1 */
    unsigned char wet_clip;
    unsigned char wet_ghost;
    /* C_FILTER_BF */
    unsigned short bf_sgm;
    unsigned char bf_clip;
    unsigned char bf_curwgt;
} AdebayerHwConfigV3_t;

#endif//_RK_AIQ_TYPES_ADEBAYER_HW_H_
