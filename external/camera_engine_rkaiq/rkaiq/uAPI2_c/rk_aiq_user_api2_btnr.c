/*
 * Copyright (c) 2019-2022 Rockchip Eletronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "newStruct/bayertnr/include/bayertnr_algo_api.h"
#include "aiq_core_c/algo_handlers/RkAiqBtnrHandler.h"
#include "uAPI2_c/rk_aiq_user_api2_common.h"

RKAIQ_BEGIN_DECLARE

#ifdef RK_SIMULATOR_HW
#define CHECK_USER_API_ENABLE
#endif

static XCamReturn
_btnr_SetStrength(const rk_aiq_sys_ctx_t* sys_ctx, abtnr_strength_t *strg)
{
    XCamReturn ret = XCAM_RETURN_NO_ERROR;
    AiqBtnrHandler_t* algo_handle =
        (AiqBtnrHandler_t*)sys_ctx->_analyzer->mAlgoHandleMaps[RK_AIQ_ALGO_TYPE_AMFNR];
    if (algo_handle) {
        AiqBtnrHandler_setStrength(algo_handle, strg);
    }
    return ret;
}

XCamReturn
rk_aiq_user_api2_btnr_SetStrength(const rk_aiq_sys_ctx_t* sys_ctx, abtnr_strength_t *strg)
{
    XCamReturn ret = XCAM_RETURN_NO_ERROR;
    CHECK_USER_API_ENABLE2(sys_ctx);
    CHECK_USER_API_ENABLE(RK_AIQ_ALGO_TYPE_AMFNR);
    RKAIQ_API_SMART_LOCK(sys_ctx);

	rk_aiq_sys_ctx_array_t ctx_array = rk_aiq_user_api2_common_getSysCtxArray(sys_ctx);
    for (int i = 0; i < ctx_array.num; i++) {
        ret = _btnr_SetStrength(ctx_array.ctx[i], strg);
    }
    return ret;
}

static XCamReturn
_btnr_GetStrength(const rk_aiq_sys_ctx_t* sys_ctx, abtnr_strength_t *strg)
{
    XCamReturn ret = XCAM_RETURN_NO_ERROR;
    AiqBtnrHandler_t* algo_handle =
        (AiqBtnrHandler_t*)sys_ctx->_analyzer->mAlgoHandleMaps[RK_AIQ_ALGO_TYPE_AMFNR];
    if (algo_handle) {
        AiqBtnrHandler_getStrength(algo_handle, strg);
    }
    return ret;
}

XCamReturn
rk_aiq_user_api2_btnr_GetStrength(const rk_aiq_sys_ctx_t* sys_ctx, abtnr_strength_t *strg)
{
    CHECK_USER_API_ENABLE2(sys_ctx);
    CHECK_USER_API_ENABLE(RK_AIQ_ALGO_TYPE_AMFNR);
    RKAIQ_API_SMART_LOCK(sys_ctx);

	const rk_aiq_sys_ctx_t* _ctx = rk_aiq_user_api2_common_getSysCtx(sys_ctx);
    if (_ctx) {
        return _btnr_GetStrength(_ctx, strg);
    }
    return XCAM_RETURN_ERROR_UNKNOWN;
}

XCamReturn
rk_aiq_user_api2_btnr_SetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, btnr_api_attrib_t* attr)
{
    XCamReturn ret = XCAM_RETURN_NO_ERROR;
    CHECK_USER_API_ENABLE2(sys_ctx);
    CHECK_USER_API_ENABLE(RK_AIQ_ALGO_TYPE_AMFNR);
    RKAIQ_API_SMART_LOCK(sys_ctx);

	rk_aiq_sys_ctx_array_t ctx_array = rk_aiq_user_api2_common_getSysCtxArray(sys_ctx);

	int type = RESULT_TYPE_TNR_PARAM;
	int man_param_size = sizeof(btnr_param_t);
	int aut_param_size = sizeof(btnr_param_auto_t);

    for (int i = 0; i < ctx_array.num; i++) {
        if (attr->opMode == RK_AIQ_OP_MODE_MANUAL || attr->opMode == RK_AIQ_OP_MODE_AUTO) {
            ret = rk_aiq_user_api2_common_processParams(ctx_array.ctx[i], true,
                    &attr->opMode, &attr->en, &attr->bypass,
                    type, man_param_size, &attr->stMan, aut_param_size,  &attr->stAuto);
        } else {
            ret = XCAM_RETURN_ERROR_FAILED;
            LOGE_ANR("wrong mode %d !", attr->opMode);
        }
    }

    return ret;
}

XCamReturn
rk_aiq_user_api2_btnr_GetAttrib(const rk_aiq_sys_ctx_t* sys_ctx, btnr_api_attrib_t* attr)
{
    CHECK_USER_API_ENABLE2(sys_ctx);
    CHECK_USER_API_ENABLE(RK_AIQ_ALGO_TYPE_AMFNR);
    RKAIQ_API_SMART_LOCK(sys_ctx);

	const rk_aiq_sys_ctx_t* ctx = rk_aiq_user_api2_common_getSysCtx(sys_ctx);
	int type = RESULT_TYPE_TNR_PARAM;
	int man_param_size = sizeof(btnr_param_t);
	int aut_param_size = sizeof(btnr_param_auto_t);

    return rk_aiq_user_api2_common_processParams(ctx, false,
				&attr->opMode, &attr->en, &attr->bypass,
				type, man_param_size, &attr->stMan, aut_param_size,  &attr->stAuto);
}

XCamReturn
rk_aiq_user_api2_btnr_QueryStatus(const rk_aiq_sys_ctx_t* sys_ctx, btnr_status_t* status)
{
    XCamReturn ret = XCAM_RETURN_NO_ERROR;
    CHECK_USER_API_ENABLE2(sys_ctx);
    CHECK_USER_API_ENABLE(RK_AIQ_ALGO_TYPE_AMFNR);
    RKAIQ_API_SMART_LOCK(sys_ctx);

	const rk_aiq_sys_ctx_t* ctx = rk_aiq_user_api2_common_getSysCtx(sys_ctx);
	AiqAlgoHandler_t* algo_handle =
		ctx->_analyzer->mAlgoHandleMaps[RK_AIQ_ALGO_TYPE_AMFNR];

	if (algo_handle) {
		ret = AiqAlgoHandler_queryStatus_common(algo_handle,
				&status->opMode, &status->en, &status->bypass, &status->stMan);
	}

	return ret;
}

RKAIQ_END_DECLARE