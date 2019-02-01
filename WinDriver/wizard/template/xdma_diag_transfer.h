/* Jungo Connectivity Confidential. Copyright (c) 2018 Jungo Connectivity Ltd.  https://www.jungo.com */

/****************************************************************************
*  File: $$$nl$$$_diag_transfer.h
*
*  Header for common functions for user-mode diagnostics application for
*  accessing Xilinx PCI Express cards with XDMA support, using the WinDriver
*  WDC API.
*
*  Note: This code sample is provided AS-IS and as a guiding sample only.
*****************************************************************************/

#ifndef _$$$nu$$$_DIAG_TRANSFER_H_
#define _$$$nu$$$_DIAG_TRANSFER_H_

#include <stdio.h>
#include "wdc_lib.h"
#include "utils.h"
#include "status_strings.h"
#include "samples/shared/diag_lib.h"
#include "samples/shared/wdc_diag_lib.h"
#include "pci_regs.h"
#include "$$$nl$$$_lib.h"

#if defined(UNIX)
    #include <sys/time.h>
    typedef struct timeval TIME_TYPE;
#else
    typedef LARGE_INTEGER TIME_TYPE;
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* DMA performance menu options */
enum {
    MENU_DMA_PERF_TO_DEV = 1,
    MENU_DMA_PERF_FROM_DEV,
    MENU_DMA_PERF_BIDIR,
    MENU_DMA_PERF_EXIT = DIAG_EXIT_MENU
};

/* DMA performance common functions */
void DmaPerformanceBiDir(WDC_DEVICE_HANDLE hDev, DWORD dwBytes,
    BOOL fPolling, DWORD dwSeconds);
void DmaPerformanceSingleDir(WDC_DEVICE_HANDLE hDev, DWORD dwBytes,
    BOOL fPolling, DWORD dwSeconds, DWORD fToDevice);
void $$$nu$$$_DIAG_DmaPerformance(WDC_DEVICE_HANDLE hDev, DWORD dwOption,
    DWORD dwBytes, BOOL fPolling, DWORD dwSeconds);

/* DMA transfer common functions */
$$$nu$$$_DMA_HANDLE $$$nu$$$_DIAG_DmaOpen(WDC_DEVICE_HANDLE hDev, BOOL fPolling,
    DWORD dwChannel, BOOL fToDevice, UINT32 u32Pattern, DWORD dwNumPackets,
    UINT64 u64FPGAOffset);
void $$$nu$$$_DIAG_DmaClose(WDC_DEVICE_HANDLE hDev, $$$nu$$$_DMA_HANDLE hDma);

#ifdef __cplusplus
}
#endif /* C */

#endif /* _$$$nu$$$_DIAG_TRANSFER_H_ */