/*
*********************************************************************************************************
*											        ePDK
*						            the Easy Portable/Player Develop Kits
*									           willow app sample
*
*						        (c) Copyright 2006-2007, JOHN, China
*											All	Rights Reserved
*
* File    : spctrm_uipara.c
* By      : john.fu
* Version : V1.00
*********************************************************************************************************
*/
#include "beetles_app.h"

#include "spctrm_i.h"

#include "spctrm_uipara.h"

static __spctrm_uipara_t spectrum_uipara_400_240 =
{
    {    	
 //   	230,	40,	160,	80			//frame win
 		420,100,700-420,350-100
    },
    {
    	//0, 0, (16+16/3)*NUM_SPCTRM, 60			//160 61
    	0, 0, 200, 81
    },    
	ID_MUSIC_PARTICLE_BMP,	//height of  particle is 60, ID_MUSIC_PARTICLE_UF_800X480_BMP	
	ID_MUSIC_BOUY_BMP//ID_MUSIC_BALL_UF_800X480_BMP
};

__spctrm_uipara_t* spctrm_get_uipara(void)
{
	__s32 			screen_width;
	__s32 			screen_height;
	
	dsk_display_get_size(&screen_width, &screen_height);

	if((screen_width == 400 )&&( screen_height == 240))
		return &spectrum_uipara_400_240;
	
	__msg("NULL ui para...\n");
	return &spectrum_uipara_400_240;
	
}


//���Explorer ����layer size
__s32 spctrm_get_screen_rect(RECT *screen_rect)
{

	__spctrm_uipara_t *ui_param;
	ui_param = spctrm_get_uipara();
	
	screen_rect->x = ui_param->para_frmwin.x;
	screen_rect->y = ui_param->para_frmwin.y;
	screen_rect->width = ui_param->para_frmwin.width;
	screen_rect->height = ui_param->para_frmwin.height;
	return EPDK_OK;

}


