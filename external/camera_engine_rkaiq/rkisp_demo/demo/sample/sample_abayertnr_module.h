/*
 *  Copyright (c) 2019 Rockchip Corporation
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
 *
 */

#ifndef _SAMPLE_ABAYERTNR_MODULE_H_
#define _SAMPLE_ABAYERTNR_MODULE_H_

#include "xcore/base/xcam_common.h"

void sample_print_abayertnr_info(const void *arg);
XCamReturn sample_abayertnr_module(const void* arg);
#ifdef USE_NEWSTRUCT
void sample_btnr_test(const rk_aiq_sys_ctx_t* ctx);
#endif
#endif
