/*******************************************************************************
 *                                                                             *
 * Copyright (c) 2009 Texas Instruments Incorporated - http://www.ti.com/      *
 *                        ALL RIGHTS RESERVED                                  *
 *                                                                             *
 ******************************************************************************/

#ifndef _DEVICE_ADV7844_PRIV_H_
#define _DEVICE_ADV7844_PRIV_H_

#include <osa_sem.h>
#include <osa_i2c.h>

#include "../../inc/device_adv7844.h"

#include "ti_vcap_common_def.h"


//#define DEVICE_ADV7844_DEBUG
//#define DEVICE_ADV7844_VERBOSE_DEBUG

//#define DEVICE_ADV7844_ENABLE_NF
#define DEVICE_ADV7844_ENABLE_FIRMWARE_PATCHES

#define DEVICE_ADV7844_ENABLE_COMB_FILTER_SETUP

/* Uncomment this to NOT download ADV7844 patch */
#ifdef TI_814X_BUILD
#define DEVICE_ADV7844_NO_PATCH_DOWNLOAD
#endif

/* Uncomment this to FORCE ADV7844 patch download each time
  IOCTL_DEVICE_VIDEO_DECODER_SET_VIDEO_MODE is called
*/
/*#define DEVICE_ADV7844_FORCE_PATCH_DOWNLOAD*/

/* Max possible channel per ADV7844 device  */
#define DEVICE_ADV7844_CH_PER_DEVICE_MAX    (4)

/* Max possible devices cascade together to feed video data to one video port */
#define DEVICE_ADV7844_DEV_MAX              (4)

/* ADV7844 handle state - not in use  */
#define DEVICE_ADV7844_OBJ_STATE_UNUSED   (0)

/* ADV7844 handle state - in use and in idle state  */
#define DEVICE_ADV7844_OBJ_STATE_IDLE     (1)

/* Apply settings to all core's */
#define DEVICE_ADV7844_CORE_ALL    (0xF)

/* ADV7844 registers  */
#define DEVICE_ADV7844_REG_STATUS_1        (0x00)
#define DEVICE_ADV7844_REG_STATUS_2        (0x01)
#define DEVICE_ADV7844_REG_ROM_VERSION     (0x04)
#define DEVICE_ADV7844_REG_RAM_VERSION_0   (0x05)
#define DEVICE_ADV7844_REG_RAM_VERSION_1   (0x06)
#define DEVICE_ADV7844_REG_CHIP_ID_MSB     (0x08)
#define DEVICE_ADV7844_REG_CHIP_ID_LSB     (0x09)
#define DEVICE_ADV7844_REG_VID_STD_STATUS  (0x0C)
#define DEVICE_ADV7844_REG_VID_STD_SELECT  (0x0D)
#define DEVICE_ADV7844_REG_AUTO_SW_MASK    (0x0E)
#define DEVICE_ADV7844_REG_Y_BRIGHTNESS    (0x10)
#define DEVICE_ADV7844_REG_Y_CONTRAST      (0x11)
#define DEVICE_ADV7844_REG_C_SATURATION    (0x13)
#define DEVICE_ADV7844_REG_C_HUE           (0x14)
#define DEVICE_ADV7844_REG_Y_CTRL_1        (0x18)
#define DEVICE_ADV7844_REG_Y_CTRL_2        (0x19)
#define DEVICE_ADV7844_REG_C_CTRL_1        (0x1B)
#define DEVICE_ADV7844_REG_C_CTRL_2        (0x1C)
#define DEVICE_ADV7844_REG_NR_MAX_NOISE    (0x5C)
#define DEVICE_ADV7844_REG_NR_CTRL         (0x5D)
#define DEVICE_ADV7844_REG_OP_MODE_CTRL    (0x60)
#define DEVICE_ADV7844_REG_FV_DEC_CTRL     (0x88)
#define DEVICE_ADV7844_REG_FV_CTRL         (0x89)
#define DEVICE_ADV7844_REG_FBIT_DURATION   (0x8B)
#define DEVICE_ADV7844_REG_ESYNC_OFFSET_1  (0xAE)
#define DEVICE_ADV7844_REG_ESYNC_OFFSET_2  (0xAF)
#define DEVICE_ADV7844_REG_AVD_OUT_CTRL_1  (0xB0)
#define DEVICE_ADV7844_REG_AVD_OUT_CTRL_2  (0xB1)
#define DEVICE_ADV7844_REG_OFM_MODE_CTRL   (0xB2)
#define DEVICE_ADV7844_REG_OFM_CH_SEL_1    (0xB3)
#define DEVICE_ADV7844_REG_OFM_CH_SEL_2    (0xB4)
#define DEVICE_ADV7844_REG_OFM_CH_SEL_3    (0xB5)
#define DEVICE_ADV7844_REG_OFM_SFRAME_LSB  (0xB6)
#define DEVICE_ADV7844_REG_OFM_SFRAME_MSB  (0xB7)
#define DEVICE_ADV7844_REG_OFM_HBLANK_LSB  (0xB8)
#define DEVICE_ADV7844_REG_OFM_HBLANK_MSB  (0xB9)
#define DEVICE_ADV7844_REG_MISC_OFM_CTRL   (0xBA)
#define DEVICE_ADV7844_REG_AUDIO_SAMPLE_HZ (0xC0)
#define DEVICE_ADV7844_REG_AUDIO_GAIN_1    (0xC1)
#define DEVICE_ADV7844_REG_AUDIO_GAIN_2    (0xC2)
#define DEVICE_ADV7844_REG_AUDIO_CTRL      (0xC3)
#define DEVICE_ADV7844_REG_AUDIO_MIXER     (0xC4)
#define DEVICE_ADV7844_REG_AUDIO_MUTE     (0xC5)
#define DEVICE_ADV7844_REG_AUDIO_CASCADE   (0xC8)
#define DEVICE_ADV7844_REG_MIN_F1_ACT      (0xD5)
#define DEVICE_ADV7844_REG_DEC_WR_EN       (0xFE)
#define DEVICE_ADV7844_REG_DEC_RD_EN       (0xFF)

/* ADV7844 register field values  */

/* Mode of operation  */
#define DEVICE_ADV7844_NON_INTERLEAVED_MODE          (0)
#define DEVICE_ADV7844_PIXEL_INTERLEAVED_MODE        (1)
#define DEVICE_ADV7844_LINE_INTERLEAVED_MODE         (2)
#define DEVICE_ADV7844_LINE_INTERLEAVED_HYBRID_MODE  (3)

/* Number of channels */
#define DEVICE_ADV7844_1CH_MUX                       (0)
#define DEVICE_ADV7844_2CH_MUX                       (1)
#define DEVICE_ADV7844_4CH_MUX                       (2)
#define DEVICE_ADV7844_8CH_MUX                       (3)

/* Resolution */
#define DEVICE_ADV7844_RES_D1                        (0)
#define DEVICE_ADV7844_RES_HALF_D1                   (2)
#define DEVICE_ADV7844_RES_CIF                       (3)

/* 8-bit or 16-bit data width */
#define DEVICE_ADV7844_OUT_TYPE_8BIT                 (0)
#define DEVICE_ADV7844_OUT_TYPE_16BIT                (1)

/* Super-frame size type  */
#define DEVICE_ADV7844_SUPER_FRAME_SIZE_525_STD      (0)
#define DEVICE_ADV7844_SUPER_FRAME_SIZE_625_STD      (1)
#define DEVICE_ADV7844_SUPER_FRAME_SIZE_MANUAL       (3)

/* Bit pattern to enable ADV7844 output */
#define DEVICE_ADV7844_OUT_ENABLE      (0x05)

/* ADV7844 status */
#define DEVICE_ADV7844_HSYNC_LOCKED    (0x02)
#define DEVICE_ADV7844_VSYNC_LOCKED    (0x04)
#define DEVICE_ADV7844_SIGNAL_DETECT   (0x80)

#define DEVICE_ADV7844_SIGNAL_60HZ     (0x20)

#define DEVICE_ADV7844_VID_STD_MASK    (0x07)

/* ADV7844 video standard's */
#define DEVICE_ADV7844_VID_STD_PAL_BDGHIN  (0x02)
#define DEVICE_ADV7844_VID_STD_PAL_M       (0x03)
#define DEVICE_ADV7844_VID_STD_PAL_COMB_N  (0x04)
#define DEVICE_ADV7844_VID_STD_PAL_60      (0x07)
#define DEVICE_ADV7844_VID_STD_NTSC_MJ     (0x01)
#define DEVICE_ADV7844_VID_STD_NTSC_4_43   (0x05)

#define DEVICE_ADV7844_NTSC_PAL_WIDTH      (720)
#define DEVICE_ADV7844_NTSC_HEIGHT         (240)
#define DEVICE_ADV7844_PAL_HEIGHT          (288)

/* Audio sampling rate  */
#define DEVICE_ADV7844_AUDIO_16KHZ                   (0)
#define DEVICE_ADV7844_AUDIO_8KHZ                    (2)

/* Audio TDM mode */
#define DEVICE_ADV7844_AUDIO_TDM_2CH       (0x0)
#define DEVICE_ADV7844_AUDIO_TDM_4CH       (0x1)
#define DEVICE_ADV7844_AUDIO_TDM_8CH       (0x2)
#define DEVICE_ADV7844_AUDIO_TDM_12CH      (0x3)
#define DEVICE_ADV7844_AUDIO_TDM_16CH      (0x4)

/*
  ADV7844 Object
*/
typedef struct
{
    Bool   isPalMode;
    /*palMode to be set based on detect status */
    Device_VideoDecoderVideoModeParams videoModeParams;
    /* video mode params */
    Device_VideoDecoderCreateParams createArgs;
    /* create time arguments */
} Device_Adv7844Obj;

typedef Device_Adv7844Obj * Device_Adv7844Handle;
/*
  Overall ADV7844 driver object
*/
typedef struct
{

    OSA_I2cHndl i2cHandle;
    /* i2cHandle for i2c read write operations */
    Device_Adv7844Handle adv7844handle[DEVICE_MAX_HANDLES];
    /*
     * ADV7844 handle objects
     */

} Device_Adv7844CommonObj;

Device_Adv7844CommonObj gDevice_adv7844CommonObj;

typedef enum
{
	ADV7844_DIGITAL_INPUT = 0,
	ADV7844_ANALOG_INPUT,
	ADV7844_YPbPr_INPUT,
	ADV7844_INPUT_UNKNOW
    /**< Should be the last value of this enumeration.
         Will be used by driver for validating the input parameters. */
} ADV7844_INPUT;

typedef struct 
{
	unsigned short HFreq;
	unsigned short VFreq;
	unsigned short HTotPix;
	unsigned short VTotPix;
	unsigned short Width;
	unsigned short Hight;
	unsigned char Interlaced;
	unsigned char TMDS_A;
	unsigned char TMDS_B;
}ADV7844_SyncInfo;

typedef struct
{
	unsigned char name[48];
	unsigned int hpv;
	unsigned int vps;
	unsigned int lps;
	unsigned int width;
	unsigned int hight;
    /**< Handle objects. */
} Vps_Adv7844_hpv_vps;

typedef struct
{
	unsigned char name[48];
	unsigned int sav;
	unsigned int eav;
	unsigned int s_vbi;
	unsigned int e_vbi;
    /**< Handle objects. */
} Vps_Adv7844_sav_eav_vbi;

typedef struct
{
    unsigned char name[48];
    unsigned int config[11];
    /**< Handle objects. */
} Vps_Adv7844_InMode;

Int32 Device_adv7844GetChipId ( Device_Adv7844Obj * pObj,
                             Device_VideoDecoderChipIdParams * pPrm,
                             Device_VideoDecoderChipIdStatus * pStatus );

Int32 Device_adv7844GetVideoStatus ( Device_Adv7844Obj * pObj,
                                     VCAP_VIDEO_SOURCE_STATUS_PARAMS_S * pPrm,
                                     VCAP_VIDEO_SOURCE_CH_STATUS_S     * pStatus );

Int32 Device_adv7844Reset ( Device_Adv7844Obj * pObj );

Int32 Device_adv7844SetVideoMode ( Device_Adv7844Obj * pObj,
                                Device_VideoDecoderVideoModeParams * pPrm );

Int32 Device_adv7844Start ( Device_Adv7844Obj * pObj );

Int32 Device_adv7844Stop ( Device_Adv7844Obj * pObj );

Int32 Device_adv7844SetVideoColor ( Device_Adv7844Obj * pObj,
                                 Device_VideoDecoderColorParams * pPrm );

Int32 Device_adv7844SetVideoNf ( Device_Adv7844Obj * pObj,
                                 Device_Adv7844VideoNfParams * pPrm );

Int32 Device_adv7844RegWrite ( Device_Adv7844Obj * pObj,
                            Device_VideoDecoderRegRdWrParams * pPrm );

Int32 Device_adv7844RegRead ( Device_Adv7844Obj * pObj,
                           Device_VideoDecoderRegRdWrParams * pPrm );

Int32 Device_adv7844OfmReset ( Device_Adv7844Obj * pObj);

Int32 Device_adv7844SelectWrite ( Device_Adv7844Obj * pObj,
                               UInt32 devId, UInt32 value );

Int32 Device_adv7844VbusWrite ( Device_Adv7844Obj * pObj,
                             UInt32 devId, UInt32 vbusAddr, UInt8 val,
                             UInt32 len );

Int32 Device_adv7844VbusRead ( Device_Adv7844Obj * pObj,
                            UInt32 devId, UInt32 vbusAddr, UInt8 * val );

Int32 Device_adv7844PatchDownload ( Device_Adv7844Obj * pObj, UInt32 devId );

Int32 Device_adv7844OutputEnable ( Device_Adv7844Obj * pObj, UInt32 enable );

Int32 Device_adv7844CheckVideoSettings ( UInt32 interleaveMode,
                                      UInt32 chMuxNum, UInt32 vidResSel,
                                      UInt32 outputType );

Int32 Device_adv7844SetAudioMode ( Device_Adv7844Obj * pObj,
                                Device_Adv7844AudioModeParams * pPrm );

Int32 Device_adv7844SetAudioVolume ( Device_Adv7844Obj * pObj,
                                  UInt32 channelNum, UInt32 audioVolume );

Int32 Device_adv7844NfEnableAll(Device_Adv7844Obj * pObj, Bool enable);

Int32 Device_adv7844PrintChipId ( Device_Adv7844Obj * pObj);

Int32 Device_adv7844SetExtendedSettings( Device_Adv7844Obj * pObj);

Int32 Device_adv7844SetIndirectRegisters(Device_Adv7844Obj * pObj);
Int32 Device_adv7844SetDirection ( Device_Adv7844Obj * pObj,
                             unsigned int *direction );
Int32 Device_adv7844GetDirection ( Device_Adv7844Obj * pObj,
                             unsigned int *direction );
Int32 Device_adv7844SetSourceChan ( Device_Adv7844Obj * pObj,
						unsigned int *source);
Int32 Device_adv7844GetSourceChan ( Device_Adv7844Obj * pObj,
						unsigned int *source);
Int32 Device_adv7844InvertCbCr ( Device_Adv7844Obj * pObj);
Int32 Device_adv7844_CSC ( Device_Adv7844Obj * pObj,unsigned char *data);
Int32 Device_adv7844GetExternInformation(Device_Adv7844Obj * pObj,
							Device_VideoDecoderExternInforms* extenInfor);                            
                             



#endif /*  _DEVICE_ADV7844_PRIV_H_  */
