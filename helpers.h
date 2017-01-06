#pragma once
#include <map>
#include <atlbase.h>
#include <sstream>
#include "mftransform.h"
#include <MMSystem.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mferror.h>
#include <string>
#include <Propvarutil.h>
#include "DebugInfoStorage.h"

#define THROW_ON_FAIL(value)     if(FAILED(value)) { throw; }
#define BREAK_ON_FAIL(value)            if(FAILED(value)) break;
#define BREAK_ON_NULL(value, newHr)     if(value == NULL) { hr = newHr; break; }

// {7E5176FE-0263-4F8B-831C-82673386B4F6}
static const GUID WMMEDIASUBTYPE_WMAudioV9 =
{ 0x00000162, 0x0000, 0x0010,{ 0x80, 0x00, 0x00, 0xAA, 0x00, 0x38, 0x9B, 0x71 } };

void DetectSubtype(GUID guid, DebugInfoStorage* debugInfo);
void DebugLongLong(std::wstring pref, LONGLONG anything);
void DebugInfo1(std::wstring info);
IMFMediaType* GetMediaType(IMFStreamDescriptor * pStreamDescriptor);
GUID GetVideoSubtype(IMFMediaType * mediaType);
GUID GetMajorType(IMFMediaType * mediaType);
HRESULT CopyAttribute(IMFAttributes *pSrc, IMFAttributes *pDest, const GUID& key);
HRESULT UnwrapTopo(IMFTopology * pTopology);
HRESULT CopyVideoType(IMFMediaType * in_media_type, IMFMediaType * out_mf_media_type);

HRESULT UnwrapPartialTopo(IMFTopologyNode * node, int level, DebugInfoStorage* debugInfo);
IMFTransform* FindEncoderTransform(GUID out_video_format);

template <class T> void SafeRelease(T **ppT)
{
    if (*ppT)
    {
        (*ppT)->Release();
        *ppT = NULL;
    }
}


