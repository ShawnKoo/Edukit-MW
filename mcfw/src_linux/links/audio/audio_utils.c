/*******************************************************************************
 *                                                                            
 * Copyright (c) 2012 Texas Instruments Incorporated - http://www.ti.com/      
 *                        ALL RIGHTS RESERVED                                  
 *                                                                            
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <mcfw/interfaces/ti_media_std.h>

#include <ti/syslink/SysLink.h>
#include <ti/syslink/ProcMgr.h>
#include <ti/ipc/MultiProc.h>
#include <ti/syslink/utils/IHeap.h>
#include <ti/syslink/utils/Memory.h>
#include <ti/ipc/SharedRegion.h>
#include <mcfw/interfaces/ti_audio.h>

#define SR_FRAME_BUFFERS_ID     1   /* same as UTILS_MEM_VID_BITS_BUF_HEAP */
/**  ------ Globals  */
ProcMgr_Handle              procMgrHandle;

Void Audio_systemProcInit (Void)
{
    Int32   status;
    Int16   procId;
    Int16   state;

    /* 
     * SysLink_setup is the first APIs needs to be called by user side
     * application to use any SysLink functionality 
     */
    SysLink_setup ();

    procId = MultiProc_getId ("DSP");

    status = ProcMgr_open (&procMgrHandle, procId);
    if (0 > status) {
        AUDIO_ERROR_PRINT(("AUDIO: ProcMgr_open() Failed \n"));
        goto EXIT;
    }

    state = ProcMgr_getState (procMgrHandle);

EXIT:
    return;
}


Void Audio_systemProcDeInit (Void)
{
    Int32  state;
    Int32  status;

    state = ProcMgr_getState (procMgrHandle);

    status = ProcMgr_close (&procMgrHandle);

    SysLink_destroy ();
}

Void* Audio_allocMem (Int32 _size)
{
    if (_size)
        return malloc (_size);
    else
        return NULL;
}

Void Audio_freeMem (Void *buf)
{
    if (buf)
        free(buf);
}


Void *Audio_allocateSharedRegionBuf (Int32 bufSize)
{
    IHeap_Handle    heap = NULL;

    int cache0 = 0;
    int cache1 = 0;	
    UInt32 cacheLineSize;
    heap = SharedRegion_getHeap(SR_FRAME_BUFFERS_ID);
    cache0 = SharedRegion_isCacheEnabled(SR_FRAME_BUFFERS_ID);
    cache1 = SharedRegion_isCacheEnabled(0);
    cacheLineSize = SharedRegion_getCacheLineSize(SR_FRAME_BUFFERS_ID);
    //	printf("-------------------------------------------------------\n");
    //	printf("-------------------------------------------------------\n");
    printf("===cach0=%d,cach1=%d,cacheLineSize:%d\n",cache0,cache1,cacheLineSize);
    //	printf("-------------------------------------------------------\n");
    //	printf("-------------------------------------------------------\n");


    return Memory_alloc (heap, bufSize, cacheLineSize, NULL);
}

Void Audio_freeSharedRegionBuf (Void *buf, Int32 bufSize)
{
    IHeap_Handle    heap = NULL;

    heap = SharedRegion_getHeap(SR_FRAME_BUFFERS_ID);
    Memory_free(heap, buf, bufSize);
}

