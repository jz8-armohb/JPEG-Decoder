/*
 * Small jpeg decoder library (header file)
 *
 * Copyright (c) 2006, Luc Saillard <luc@saillard.org>
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * - Redistributions of source code must retain the above copyright notice,
 *  this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright notice,
 *  this list of conditions and the following disclaimer in the documentation
 *  and/or other materials provided with the distribution.
 *
 * - Neither the name of the author nor the names of its contributors may be
 *  used to endorse or promote products derived from this software without
 *  specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <stdio.h>
#ifndef __JPEGDEC_H__
#define __JPEGDEC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* 声明全局变量 by S.Z.Zheng */
    FILE* qtabFilePtr;  // 量化表文件指针
    FILE* dcImgFilePtr; // DC图像文件指针
    FILE* acImgFilePtr; // AC图像文件指针
/* 声明结束 */

struct jdec_private;

/* Flags that can be set by any applications */
#define TINYJPEG_FLAGS_MJPEG_TABLE	(1<<1)

/* Format accepted in outout */
enum tinyjpeg_fmt {
   TINYJPEG_FMT_GREY = 1,
   TINYJPEG_FMT_BGR24,
   TINYJPEG_FMT_RGB24,
   TINYJPEG_FMT_YUV420P,
};
FILE *p_trace;//add by nxn
static char error_string[256];//add by nxn
struct jdec_private *tinyjpeg_init(void);
void tinyjpeg_free(struct jdec_private *priv);

int tinyjpeg_parse_header(struct jdec_private *priv, const unsigned char *buf, unsigned int size);
int tinyjpeg_decode(struct jdec_private *priv, int pixel_format);
const char *tinyjpeg_get_errorstring(struct jdec_private *priv);
void tinyjpeg_get_size(struct jdec_private *priv, unsigned int *width, unsigned int *height);
int tinyjpeg_get_components(struct jdec_private *priv, unsigned char **components);
int tinyjpeg_set_components(struct jdec_private *priv, unsigned char **components, unsigned int ncomponents);
int tinyjpeg_set_flags(struct jdec_private *priv, int flags);

#ifdef __cplusplus
}
#endif

#endif

#define  snprintf _snprintf//add by nxn
#define TRACE 1//add by nxn
#define  TRACEFILE "trace_jpeg.txt"//add by nxn

