


#include "beetles_app.h"
#include "Explorer.h"
#include "Explorer_UI.h"


//libaiao 


#define	C_DATE_Y_SPACE			18


#define	C_DEL_FILE_PECENT_AREA_X	0
#define	C_DEL_FILE_PECENT_AREA_Y	(55+110+1)
#define	C_DEL_FILE_PECENT_AREA_W	(130)
#define	C_DEL_FILE_PECENT_AREA_H	(60)


static explorer_viewer_ui_t  explr_viewer_ui_1024_768 =
{    
    //layer window
    { 
        PIXEL_COLOR_ARGB8888,       //fmt 
        { 1024, 768 },               //fb size
        { 0, 0, 1024, 768 },         //src rect
        { 0, 0, 1024, 768 },         //scn rect
        { 0 },                      //reserved
    },
        
    //menuview attribute  
    { 0, 0, 720, 576 },             //menuview(frame window)    
    { 0, 0, 720, 576 },             //browser bg
    { 0, 0, 720, 20  },              //browser bg top
    { 0, 0, 0, 	0 },                 //browser bg bottom
    { 0, 0, 0,  0 },              //browser bg left

/*
	{ 650,	70,	8,	420},			//scroll bg rect
    	{ 650,	74,	8,	392},      		 //scroll rect
      	4, 	4, 	4,                        //scroll head/body/tail height
*/
	{ 1000,	72,	14,	592},			//scroll bg rect
    	{ 1000,	90,	14,	552},      		 //scroll rect
      	 10, 	4, 	10,                        //scroll head/body/tail height

/*
    { 391,	8,	7,	224},            //scroll bg rect
    { 393,	22,	3,	194},      		 //scroll rect
      6, 	1, 	6,                        //scroll head/body/tail height
*/

    { 0, 8, 660, 530},        //(the whole listbar rectangle)
    
    //list item attribute，以下坐标为点对于listbar rectangle的相对坐标   
    { 
    	{ 344, 75, 636, 616},				//all item rect     		//整个列表的显视区域           	
        { 344, 0, 606, 77 },       			//item rect                	//一行的的大小
        { 0 , 20, 254, 2 },        			//item_top_line;
        { 0 , 0, 254, 2 },        			//item_bottom_line;
        { 0 , 10, 2, 38},       				//item_dividing_line;
        
 //       { 24, 4, 15, 15 },        			//icon rect 
 	    { 10, 0, 15, 15 },        			//icon rect 		// 小图标的位置
        { 40, 0, 50, 30 },       			//miniature rect, 缩略图 UI 参数
        
//        { 24+35, 0, 254 -24 -35 - 2 - 7, 30 },  //text rect
		{ 96, 0, 488, 62 },  //text rect  		//文件的名字
          
//        { 7, 2, 254, 30 },      			//focus icon rect(select picture)
        { 0, 0, 500, 52 }, 				//选择背景
//        { 24, 53, 88, 110},					//媒体类型图标位置(显示在左边区域的大图标) 
            { 40, 151, 260, 270},
            
        {40, 72, 260, 22 },      			//title rect, only for file manager
        {40, 425,260, 22},      		//file size rect 
        {40, 458,260, 22},      		//file create time rect
        {0, 0, 150, 34 },      				//number rect                
    },
    
    //square item attribute，以下坐标为点对于menu的相对坐标  
    {
	//    { 0, 8, 390, 200},        			//(the whole listbar rectangle)
    //    { 0, 0, 130, 80 },       			//item rect in listbar
    //    { 8, 0, 112, 71 },      			//focus rect
    //    { 55, 20, 106, 65 },       			//icon rect
   //     { 11, 3, 106, 65 },       			//miniature rect
   //     { 13, 3 + 71 - 35, 100, 30},      	//title rect
        	    { 0, 8, 660, 530},        			//(the whole listbar rectangle)
        { 0, 4, 130, 76 },       			//item rect in listbar
//        { 8, 0, 114, 76 },      			//focus rect
	{ 58, 4, 114, 76 },      			//focus rect
        { 11, 7, 108, 55 },       			//icon rect
        { 11, 7, 108, 55 },       			//miniature rect
        { 15, 3+55 + 1 , 100, 16},      	//title rect
    },        
    
    //icon table    
    {				//ID															res	handle,    	res buffer
    
		{ NULL,           NULL,  				 NULL },    //调色板
        { NULL,           NULL,  				 NULL },    //背景图

        { ID_EXPLORER_USB_BMP,      			NULL,  			 NULL }, 	// USB                                                 				
        { ID_EXPLORER_USB_ICON_UNFOCUSED_BMP, 	NULL,  			 NULL }, 	// USB
        { ID_EXPLORER_USB_ICON_FOCUSED_BMP,   	NULL,  			 NULL }, 	//                                                       				        

        { ID_EXPLORER_SD_BMP,      				NULL,  			 NULL }, 	// SD 
        { ID_EXPLORER_SD_ICON_UNFOCUSED_BMP, 	NULL,  			 NULL }, 	// 
        { ID_EXPLORER_SD_ICON_FOCUSED_BMP,   	NULL,  			 NULL }, 	//                                                       				        


        { ID_EXPLORER_FOLDER_BMP,      			 NULL,  		 NULL }, 	//  
        { ID_EXPLORER_FOLDER_ICON_UNFOCUSED_BMP, NULL,  		 NULL }, 	// video文件icon图标,与文件名一起的                                                      				
        { ID_EXPLORER_FOLDER_ICON_FOCUSED_BMP,   NULL,  		 NULL }, 	//                                                       				        

        { ID_EXPLORER_UNKNOWN_FILE_BMP,      	NULL,  			 NULL }, 	//  video文件标志                                                     				
        { ID_EXPLORER_UNKNOWN_ICON_UNFOCUSED_BMP, NULL,  		 NULL }, 	// video文件icon图标,与文件名一起的                                                      				
        { ID_EXPLORER_UNKNOWN_ICON_FOCUSED_BMP,   NULL,  		 NULL }, 	//                                                       				        

        { ID_EXPLORER_VIDEO_FILE_BMP,      		NULL,  				 NULL }, 	//  video文件标志                                                     				
        { ID_EXPLORER_VIDEO_ICON_UNFOCUSED_BMP, NULL,  				 NULL }, 	// video文件icon图标,与文件名一起的                                                      				
        { ID_EXPLORER_VIDEO_ICON_FOCUSED_BMP,   NULL,  				 NULL }, 	//                                                       				        

        { ID_EXPLORER_MUSIC_FILE_BMP,      		NULL,  				 NULL }, 	// music文件标志                                                     				
		{ ID_EXPLORER_MUSIC_ICON_UNFOCUSED_BMP, NULL,  				 NULL }, 	// music文件icon图标,与文件名一起的                                                      				        
		{ ID_EXPLORER_MUSIC_ICON_FOCUSED_BMP, 	NULL,  				 NULL }, 	// music文件icon图标,与文件名一起的                                                      				        		

        { ID_EXPLORER_PHOTO_FILE_BMP,      		NULL,  				 NULL }, 	// picture文件标志                                                     				
		{ ID_EXPLORER_PHOTO_ICON_UNFOCUSED_BMP, NULL,  				 NULL }, 	// picture文件icon图标,与文件名一起的                                                      				        
		{ ID_EXPLORER_PHOTO_ICON_FOCUSED_BMP, 	NULL,  				 NULL }, 	// picture文件icon图标,与文件名一起的                                                      				        				

        { ID_EXPLORER_UNKNOWN_FILE_BMP,      		NULL,  				 NULL }, 	// Ebook文件标志                                                     				
		{ ID_EXPLORER_UNKNOWN_ICON_UNFOCUSED_BMP, NULL,  				 NULL }, 	// Ebook文件icon图标,与文件名一起的                                                      				        
		{ ID_EXPLORER_UNKNOWN_ICON_FOCUSED_BMP, 	NULL,  				 NULL }, 	// Ebook文件icon图标,与文件名一起的                                                      				        				
		
		{ ID_EXPLORER_DELETE_ICON_UNFOCUSED_BMP,NULL,  			 	 NULL }, 	// 删除文件icon图标,
		{ ID_EXPLORER_DELETE_ICON_FOCUSED_BMP, 	NULL,  				 NULL }, 	// 删除文件icon图标,

        { ID_EXPLORER_LIST_ITEM_FOCUSED_BG_BMP,   NULL,  				 NULL }, 	// 条目焦点背景框图
        { NULL,      	NULL,  				 NULL }, 	//缩略图焦点框图,目前暂时未用
        
        { ID_EXPLORER_LIST_SCROLL_BG_BMP,       NULL,  				 NULL }, 	// scroll bar 背景图
        { ID_EXPLORER_LIST_SCROLL_HEAD_BMP,     NULL,  				 NULL }, 	// scroll bar 头部icon
        { ID_EXPLORER_LIST_SCROLL_BODY_BMP,     NULL,  				 NULL }, 	// scroll bar , 滑块，高度必须为1
        { ID_EXPLORER_LIST_SCROLL_TAIL_BMP,     NULL,  				 NULL }, 	// scroll bar , 滑块，高度必须为1        

		{ ID_EXPLORER_LONG_STR_SCROLL_BG_BMP,     NULL,  				 NULL }, 	// 长字符串滚动背景//ID_EXPLORER_LONG_STR_SCROLL_BG_BMP
		{ID_EXPLORER_ERROR_BMP ,				 NULL,				 NULL } ,
        { 0,                                    NULL,  				 NULL }      //browser_icon_max
    },                                                 				
};

static explorer_viewer_ui_t  explr_viewer_ui_1280_768 =
{    
    //layer window
    { 
        PIXEL_COLOR_ARGB8888,       //fmt 
        { 1280, 768 },               //fb size
        { 0, 0, 1280, 768 },         //src rect
        { 0, 0, 1280, 768 },         //scn rect
        { 0 },                      //reserved
    },
        
    //menuview attribute  
    { 0, 0, 720, 576 },             //menuview(frame window)    
    { 0, 0, 720, 576 },             //browser bg
    { 0, 0, 720, 20  },              //browser bg top
    { 0, 0, 0, 	0 },                 //browser bg bottom
    { 0, 0, 0,  0 },              //browser bg left

/*
	{ 650,	70,	8,	420},			//scroll bg rect
    	{ 650,	74,	8,	392},      		 //scroll rect
      	4, 	4, 	4,                        //scroll head/body/tail height
*/
	{ 1254,	72,	14,	592},			//scroll bg rect
    	{ 1254,	90,	14,	552},      		 //scroll rect
      	 10, 	4, 	10,                        //scroll head/body/tail height

/*
    { 391,	8,	7,	224},            //scroll bg rect
    { 393,	22,	3,	194},      		 //scroll rect
      6, 	1, 	6,                        //scroll head/body/tail height
*/

    { 0, 8, 660, 530},        //(the whole listbar rectangle)
    
    //list item attribute，以下坐标为点对于listbar rectangle的相对坐标   
    { 
    	{ 484, 75, 636, 616},				//all item rect     		//整个列表的显视区域           	
        { 484, 0, 606, 77 },       			//item rect                	//一行的的大小
        { 0 , 20, 254, 2 },        			//item_top_line;
        { 0 , 0, 254, 2 },        			//item_bottom_line;
        { 0 , 10, 2, 38},       				//item_dividing_line;
        
 //       { 24, 4, 15, 15 },        			//icon rect 
 	    { 10, 0, 15, 15 },        			//icon rect 		// 小图标的位置
        { 40, 0, 50, 30 },       			//miniature rect, 缩略图 UI 参数
        
//        { 24+35, 0, 254 -24 -35 - 2 - 7, 30 },  //text rect
		{ 96, 0, 488, 62 },  //text rect  		//文件的名字
          
//        { 7, 2, 254, 30 },      			//focus icon rect(select picture)
        { 0, 0, 500, 52 }, 				//选择背景
//        { 24, 53, 88, 110},					//媒体类型图标位置(显示在左边区域的大图标) 
            { 80, 151, 260, 270},
            
        {80, 72, 260, 22 },      			//title rect, only for file manager
        {80, 425,260, 22},      		//file size rect 
        {80, 458,260, 22},      		//file create time rect
        {0, 0, 150, 34 },      				//number rect                
    },
    
    //square item attribute，以下坐标为点对于menu的相对坐标  
    {
	//    { 0, 8, 390, 200},        			//(the whole listbar rectangle)
    //    { 0, 0, 130, 80 },       			//item rect in listbar
    //    { 8, 0, 112, 71 },      			//focus rect
    //    { 55, 20, 106, 65 },       			//icon rect
   //     { 11, 3, 106, 65 },       			//miniature rect
   //     { 13, 3 + 71 - 35, 100, 30},      	//title rect
        	    { 0, 8, 660, 530},        			//(the whole listbar rectangle)
        { 0, 4, 130, 76 },       			//item rect in listbar
//        { 8, 0, 114, 76 },      			//focus rect
	{ 58, 4, 114, 76 },      			//focus rect
        { 11, 7, 108, 55 },       			//icon rect
        { 11, 7, 108, 55 },       			//miniature rect
        { 15, 3+55 + 1 , 100, 16},      	//title rect
    },        
    
    //icon table    
    {				//ID															res	handle,    	res buffer
    
		{ NULL,           NULL,  				 NULL },    //调色板
        { NULL,           NULL,  				 NULL },    //背景图

        { ID_EXPLORER_USB_BMP,      			NULL,  			 NULL }, 	// USB                                                 				
        { ID_EXPLORER_USB_ICON_UNFOCUSED_BMP, 	NULL,  			 NULL }, 	// USB
        { ID_EXPLORER_USB_ICON_FOCUSED_BMP,   	NULL,  			 NULL }, 	//                                                       				        

        { ID_EXPLORER_SD_BMP,      				NULL,  			 NULL }, 	// SD 
        { ID_EXPLORER_SD_ICON_UNFOCUSED_BMP, 	NULL,  			 NULL }, 	// 
        { ID_EXPLORER_SD_ICON_FOCUSED_BMP,   	NULL,  			 NULL }, 	//                                                       				        


        { ID_EXPLORER_FOLDER_BMP,      			 NULL,  		 NULL }, 	//  
        { ID_EXPLORER_FOLDER_ICON_UNFOCUSED_BMP, NULL,  		 NULL }, 	// video文件icon图标,与文件名一起的                                                      				
        { ID_EXPLORER_FOLDER_ICON_FOCUSED_BMP,   NULL,  		 NULL }, 	//                                                       				        

        { ID_EXPLORER_UNKNOWN_FILE_BMP,      	NULL,  			 NULL }, 	//  video文件标志                                                     				
        { ID_EXPLORER_UNKNOWN_ICON_UNFOCUSED_BMP, NULL,  		 NULL }, 	// video文件icon图标,与文件名一起的                                                      				
        { ID_EXPLORER_UNKNOWN_ICON_FOCUSED_BMP,   NULL,  		 NULL }, 	//                                                       				        

        { ID_EXPLORER_VIDEO_FILE_BMP,      		NULL,  				 NULL }, 	//  video文件标志                                                     				
        { ID_EXPLORER_VIDEO_ICON_UNFOCUSED_BMP, NULL,  				 NULL }, 	// video文件icon图标,与文件名一起的                                                      				
        { ID_EXPLORER_VIDEO_ICON_FOCUSED_BMP,   NULL,  				 NULL }, 	//                                                       				        

        { ID_EXPLORER_MUSIC_FILE_BMP,      		NULL,  				 NULL }, 	// music文件标志                                                     				
		{ ID_EXPLORER_MUSIC_ICON_UNFOCUSED_BMP, NULL,  				 NULL }, 	// music文件icon图标,与文件名一起的                                                      				        
		{ ID_EXPLORER_MUSIC_ICON_FOCUSED_BMP, 	NULL,  				 NULL }, 	// music文件icon图标,与文件名一起的                                                      				        		

        { ID_EXPLORER_PHOTO_FILE_BMP,      		NULL,  				 NULL }, 	// picture文件标志                                                     				
		{ ID_EXPLORER_PHOTO_ICON_UNFOCUSED_BMP, NULL,  				 NULL }, 	// picture文件icon图标,与文件名一起的                                                      				        
		{ ID_EXPLORER_PHOTO_ICON_FOCUSED_BMP, 	NULL,  				 NULL }, 	// picture文件icon图标,与文件名一起的                                                      				        				

        { ID_EXPLORER_UNKNOWN_FILE_BMP,      		NULL,  				 NULL }, 	// Ebook文件标志                                                     				
		{ ID_EXPLORER_UNKNOWN_ICON_UNFOCUSED_BMP, NULL,  				 NULL }, 	// Ebook文件icon图标,与文件名一起的                                                      				        
		{ ID_EXPLORER_UNKNOWN_ICON_FOCUSED_BMP, 	NULL,  				 NULL }, 	// Ebook文件icon图标,与文件名一起的                                                      				        				
		
		{ ID_EXPLORER_DELETE_ICON_UNFOCUSED_BMP,NULL,  			 	 NULL }, 	// 删除文件icon图标,
		{ ID_EXPLORER_DELETE_ICON_FOCUSED_BMP, 	NULL,  				 NULL }, 	// 删除文件icon图标,

        { ID_EXPLORER_LIST_ITEM_FOCUSED_BG_BMP,   NULL,  				 NULL }, 	// 条目焦点背景框图
        { NULL,      	NULL,  				 NULL }, 	//缩略图焦点框图,目前暂时未用
        
        { ID_EXPLORER_LIST_SCROLL_BG_BMP,       NULL,  				 NULL }, 	// scroll bar 背景图
        { ID_EXPLORER_LIST_SCROLL_HEAD_BMP,     NULL,  				 NULL }, 	// scroll bar 头部icon
        { ID_EXPLORER_LIST_SCROLL_BODY_BMP,     NULL,  				 NULL }, 	// scroll bar , 滑块，高度必须为1
        { ID_EXPLORER_LIST_SCROLL_TAIL_BMP,     NULL,  				 NULL }, 	// scroll bar , 滑块，高度必须为1        

		{ ID_EXPLORER_LONG_STR_SCROLL_BG_BMP,     NULL,  				 NULL }, 	// 长字符串滚动背景//ID_EXPLORER_LONG_STR_SCROLL_BG_BMP
		{ID_EXPLORER_ERROR_BMP ,				 NULL,				 NULL } ,
        { 0,                                    NULL,  				 NULL }      //browser_icon_max
    },                                                 				
};

//获得整个explorer AP设计的UI参数
explorer_viewer_ui_t* explorer_get_viewer_ui_param(void)
{	
	__s32 screen_width, screen_height;

	dsk_display_get_size(&screen_width, &screen_height);
	if(screen_width == 1280 && screen_height == 768)
		return &(explr_viewer_ui_1280_768);
	else
		return &(explr_viewer_ui_1024_768);
}

RECT* explorer_get_listview_ui_param(void)
{	
	__s32 screen_width, screen_height;

	dsk_display_get_size(&screen_width, &screen_height);
	if(screen_width == 1280 && screen_height == 768)
		return &(explr_viewer_ui_1280_768.listview);
	else
		return &(explr_viewer_ui_1024_768.listview);
}

//获得list 中 item 设计的UI参数
explorer_list_item_ui_param_t * explorer_get_list_item_ui_param(void)
{	
	__s32 screen_width, screen_height;

	dsk_display_get_size(&screen_width, &screen_height);
	if(screen_width == 1280 && screen_height == 768)
		return &(explr_viewer_ui_1280_768.list_item_ui_param);	
	else
		return &(explr_viewer_ui_1024_768.list_item_ui_param);
}

//获得list 中 square 设计的UI参数
explorer_square_item_ui_param_t * explorer_get_square_item_ui_param(void)
{
	__s32 screen_width, screen_height;

	dsk_display_get_size(&screen_width, &screen_height);
	if(screen_width == 1280 && screen_height == 768)
		return &(explr_viewer_ui_1280_768.square_item_ui_param);	
	else
		return &(explr_viewer_ui_1024_768.square_item_ui_param);	
}


__u32 explorer_get_listbar_pagenum(explr_list_para_t *list_para)
{
	__u32 pagenum = 0, col, row;	
	__u32 item_width, item_height, lbar_width, lbar_height;
	
    explorer_viewer_ui_t *ui_param = explorer_get_viewer_ui_param();			//获得整个AP的UI设计参数    	
		
	if(list_para->view_mode == EXPLR_LIST_MODE)
	{
    	item_width = ui_param->list_item_ui_param.item_rect.width;						//根据list or square模式不同
	    item_height = ui_param->list_item_ui_param.item_rect.height;			
    	lbar_width = ui_param->list_item_ui_param.ListBarArea.width;
    	lbar_height = ui_param->list_item_ui_param.ListBarArea.height;			
	}
	else if(list_para->view_mode == EXPLR_SQUARE_MODE)
	{
        item_width = ui_param->square_item_ui_param.item_rect.width;
        item_height = ui_param->square_item_ui_param.item_rect.height;						
    	lbar_width = ui_param->square_item_ui_param.ListBarArea.width;
    	lbar_height = ui_param->square_item_ui_param.ListBarArea.height;			
	}
	else
	{
    	item_width = ui_param->list_item_ui_param.item_rect.width;				
	    item_height = ui_param->list_item_ui_param.item_rect.height;			
    	lbar_width = ui_param->list_item_ui_param.ListBarArea.width;
    	lbar_height = ui_param->list_item_ui_param.ListBarArea.height;				
	}
	
    col         = lbar_width  / item_width;
    row         = lbar_height / item_height;
    pagenum     = col * row;

	return pagenum;
}
/*
************************************************************************************************************************
*Function	:         void* explorer_get_listview_icon_res(__u32 index)
*
*Description	: 		
*					
*Arguments  	: 		
*
*Return     	: 	
*
************************************************************************************************************************
*/
void* explorer_get_listview_icon_res(__u32 index)
{
    explorer_icon_data_t *icon_table = NULL;
    
    
    icon_table = explr_viewer_ui_1024_768.icon_table;
        
    //__msg("----icon_id: %d, res_id: %d\n", index, icon_table[index].res_id);
    if(icon_table == NULL)
    {
        return NULL;
    }    
    else if(icon_table[index].res_id == 0)
    {
        return NULL;
    }    
    else if(icon_table[index].res_handle == NULL)
    {
        icon_table[index].res_handle = theme_open(icon_table[index].res_id);
        icon_table[index].res_buffer = theme_hdl2buf(icon_table[index].res_handle);                        
        return icon_table[index].res_buffer;
    }
    else
    {
    	//--------------------------------------------------------------------------
    	//加这个判断仅仅是为了避开listbar, 684行，GUI_BitStringDrawEx()冲掉该图片buffer
    	//后续应彻底根除
    	//if(index == ID_EXP_LONG_STR_SCROLL_BG)
    	/*
    	{
    		theme_close(icon_table[index].res_handle); 
	        icon_table[index].res_handle = theme_open(icon_table[index].res_id);
	        icon_table[index].res_buffer = theme_hdl2buf(icon_table[index].res_handle);                        
	        return icon_table[index].res_buffer;			
    	}
    	*/
    	//--------------------------------------------------------------------------		
        return icon_table[index].res_buffer;
    }
}

/*
************************************************************************************************************************
*Function	:         __s32 explorer_free_listview_icon_res(void)
*
*Description	: 		
*					
*Arguments  	: 		
*
*Return     	: 	
*
************************************************************************************************************************
*/
__s32 explorer_free_listview_icon_res(void)
{    
    __s32 i = 0;
    explorer_icon_data_t *icon_table = NULL;
    icon_table = explr_viewer_ui_1024_768.icon_table;
    
    if(icon_table == NULL)
    {
        return EPDK_FAIL;
    }
    else
    {
        for(i = 0; i < BROWSER_ICON_MAX; i++)
        {
            if(icon_table[i].res_handle != NULL)
            {
                theme_close(icon_table[i].res_handle); 
                icon_table[i].res_handle = NULL;
                icon_table[i].res_buffer = NULL;
            }
        }        
        return EPDK_OK;       
    }
}

//获得Explorer 窗口layer size
__s32 explorer_get_screen_rect(RECT *screen_rect)
{	
	explorer_viewer_ui_t *ui_param;
	ui_param = explorer_get_viewer_ui_param();
	
	screen_rect->x = ui_param->layer.scn_rect.x;
	screen_rect->y = ui_param->layer.scn_rect.y;
	screen_rect->width = ui_param->layer.scn_rect.width;
	screen_rect->height = ui_param->layer.scn_rect.height;
	return EPDK_OK;
}



//获得缩略图区域(according to the view mode of list)
__s32 explorer_get_item_miniature_rect(explr_list_para_t *para, RECT *miniature_rect)
{
	explorer_viewer_ui_t *ui_param;
	ui_param = explorer_get_viewer_ui_param();	
	
	switch(para->view_mode)
	{
		case EXPLR_LIST_MODE:
			miniature_rect->x = ui_param->list_item_ui_param.miniature_rect.x;
			miniature_rect->y = ui_param->list_item_ui_param.miniature_rect.y;
			miniature_rect->width = ui_param->list_item_ui_param.miniature_rect.width;
			miniature_rect->height = ui_param->list_item_ui_param.miniature_rect.height;			
			break;
		case EXPLR_SQUARE_MODE:
			miniature_rect->x = ui_param->square_item_ui_param.miniature_rect.x;
			miniature_rect->y = ui_param->square_item_ui_param.miniature_rect.y;
			miniature_rect->width = ui_param->square_item_ui_param.miniature_rect.width;
			miniature_rect->height = ui_param->square_item_ui_param.miniature_rect.height;			
			break;			
	}	
	return EPDK_OK;
}

//获得显示文本区域  //文件名字
__s32 explorer_get_item_text_rect(explr_list_para_t *para, RECT *text_rect)
{
	explorer_viewer_ui_t *ui_param;
	ui_param = explorer_get_viewer_ui_param();	
	
	switch(para->view_mode)
	{
		case EXPLR_LIST_MODE:
			text_rect->x = ui_param->list_item_ui_param.text_rect.x;
			text_rect->y = ui_param->list_item_ui_param.text_rect.y;
			text_rect->width = ui_param->list_item_ui_param.text_rect.width;
			text_rect->height = ui_param->list_item_ui_param.text_rect.height;			
			break;
		case EXPLR_SQUARE_MODE:
			text_rect->x = ui_param->square_item_ui_param.title_rect.x;
			text_rect->y = ui_param->square_item_ui_param.title_rect.y;
			text_rect->width = ui_param->square_item_ui_param.title_rect.width;
			text_rect->height = ui_param->square_item_ui_param.title_rect.height;			
			break;			
		default:
			break;
	}	
	return EPDK_OK;
}

//获得条目开始的图标显示区域  //小图标
__s32 explorer_get_item_icon_rect(explr_list_para_t *para, RECT *icon_rect)
{
	explorer_viewer_ui_t *ui_param;
	ui_param = explorer_get_viewer_ui_param();	
	
	switch(para->view_mode)
	{
		case EXPLR_LIST_MODE:
			icon_rect->x = ui_param->list_item_ui_param.icon_rect.x;
			icon_rect->y = ui_param->list_item_ui_param.icon_rect.y;
			icon_rect->width = ui_param->list_item_ui_param.icon_rect.width;
			icon_rect->height = ui_param->list_item_ui_param.icon_rect.height;			
			break;
		case EXPLR_SQUARE_MODE:
			icon_rect->x = ui_param->square_item_ui_param.icon_rect.x;
			icon_rect->y = ui_param->square_item_ui_param.icon_rect.y;
			icon_rect->width = ui_param->square_item_ui_param.icon_rect.width;
			icon_rect->height = ui_param->square_item_ui_param.icon_rect.height;			
			break;			
		default:
			break;
	}	
	return EPDK_OK;
}


//获得焦点条目图标
__s32 explorer_get_item_focus_icon_rect(explr_list_para_t *para, RECT *focus_icon_rect)
{
	explorer_viewer_ui_t *ui_param;
	ui_param = explorer_get_viewer_ui_param();	
	
	switch(para->view_mode)
	{
		case EXPLR_LIST_MODE:
			focus_icon_rect->x = ui_param->list_item_ui_param.focus_icon_rect.x;
			focus_icon_rect->y = ui_param->list_item_ui_param.focus_icon_rect.y;
			focus_icon_rect->width = ui_param->list_item_ui_param.focus_icon_rect.width;
			focus_icon_rect->height = ui_param->list_item_ui_param.focus_icon_rect.height;			
			break;
		case EXPLR_SQUARE_MODE:
			focus_icon_rect->x = ui_param->square_item_ui_param.focus_rect.x;
			focus_icon_rect->y = ui_param->square_item_ui_param.focus_rect.y;
			focus_icon_rect->width = ui_param->square_item_ui_param.focus_rect.width;
			focus_icon_rect->height = ui_param->square_item_ui_param.focus_rect.height;			
			break;			
		default:
			break;
	}	
	return EPDK_OK;
}


//画背景图片
__s32 explorer_draw_background(explr_list_para_t *list_para)
{
	void *pic_buf;		
	__s32 picX, picY;		
		
	//ret = explorer_get_item_focus_icon_rect(list_para, &FocusIconRect);

	picX = 0;
	picY = 0;
	pic_buf = explorer_get_listview_icon_res(ID_EXP_BACKGROUND);			//draw select border
	//picW =  GUI_BMP_GetXSize(pic_buf);										//获得图片宽
	//picH =  GUI_BMP_GetYSize(pic_buf);										//获得图片高度
	if(pic_buf != NULL)
	{
		GUI_BMP_Draw(pic_buf, picX, picY);	
	}
	return EPDK_OK;
}


// 打印右上角的文件类型图标
__s32 explorer_draw_FileTypeIcon(explr_list_para_t *list_para, rat_media_type_t media_type)
{
	void *pic_buf = NULL;		
	__s32 picX = 0, picY = 0;		
	explorer_viewer_ui_t *ui_param;
	ui_param = explorer_get_viewer_ui_param();
	//GUI_LyrWinSel(list_para->BG_layer);	
	//com_set_palette_by_id(ID_EXPLORER_PALETTE_BMP);	
	//ret = explorer_get_item_focus_icon_rect(list_para, &FocusIconRect);
	picX = ui_param->list_item_ui_param.media_type_rect.x;		//24
	picY = ui_param->list_item_ui_param.media_type_rect.y;		//73
	switch(media_type)
	{
		case RAT_MEDIA_TYPE_VIDEO:
			pic_buf = explorer_get_listview_icon_res(ID_EXP_VIDEO_FILE);			//draw select border
			break;		
		case RAT_MEDIA_TYPE_PIC:
			pic_buf = explorer_get_listview_icon_res(ID_EXP_PHOTO_FILE);			//draw select border
			break;
		case RAT_MEDIA_TYPE_AUDIO:	
			pic_buf = explorer_get_listview_icon_res(ID_EXP_MUSIC_FILE);			//draw select border
			break;		
//		case RAT_MEDIA_TYPE_EBOOK:
//			pic_buf = explorer_get_listview_icon_res(ID_EXP_EBOOK_FILE);			//draw select border
			break;		
		case RAT_MEDIA_TYPE_FOLDER:
			pic_buf = explorer_get_listview_icon_res(ID_EXP_FOLDER);				//draw select border
			break;
		case RAT_MEDIA_TYPE_EBOOK:			
		case RAT_MEDIA_TYPE_ALL:
		case RAT_MEDIA_TYPE_UNKNOWN:												//
			pic_buf = explorer_get_listview_icon_res(ID_EXP_UNKNOWN_FILE);			//draw select border
			break;
		case RAT_MEDIA_TYPE_USB_DEVICE:
			pic_buf = explorer_get_listview_icon_res(ID_EXP_USB);			//draw select border
			break;
		case RAT_MEDIA_TYPE_SD_DEVICE:
			pic_buf = explorer_get_listview_icon_res(ID_EXP_SD);			//draw select border
			break;
		default:
			break;		
	}
	//picW =  GUI_BMP_GetXSize(pic_buf);										//获得图片宽
	//picH =  GUI_BMP_GetYSize(pic_buf);										//获得图片高度		
	if(pic_buf != NULL)
	{
		GUI_ClearRect(picX,picY, \
					picX+ui_param->list_item_ui_param.media_type_rect.width, \
					picY+ui_param->list_item_ui_param.media_type_rect.height);
		GUI_BMP_Draw(pic_buf, picX, picY);	
	}	
	return EPDK_OK;
}

__s32 explorer_clear_filesize_area(void)
{
	explorer_viewer_ui_t *ui_param;	
	GUI_RECT rect;
	__u32 file_size;
	
	ui_param = explorer_get_viewer_ui_param();
	
	rect.x0 = ui_param->list_item_ui_param.file_size_rect.x;		
	rect.y0 = ui_param->list_item_ui_param.file_size_rect.y;			
	rect.x1 = rect.x0 + ui_param->list_item_ui_param.file_size_rect.width;		
	rect.y1 = rect.y0 + ui_param->list_item_ui_param.file_size_rect.height;
	GUI_ClearRect(rect.x0,rect.y0, rect.x1, rect.y1);

	return EPDK_OK;
}
__s32 explorer_draw_FileSize(file_item_t *item)
{
	char str[20];
	explorer_viewer_ui_t *ui_param;	
	GUI_RECT rect;
	__u32 file_size;
	if(item == NULL)
	{
		return EPDK_FAIL;
	}

	
	file_size = item->file_size;
	eLIBs_memset(str, 0, sizeof(str));
	filesize2str(file_size, str);
	
	ui_param = explorer_get_viewer_ui_param();
	
	rect.x0 = ui_param->list_item_ui_param.file_size_rect.x;		
	rect.y0 = ui_param->list_item_ui_param.file_size_rect.y;			
	rect.x1 = rect.x0 + ui_param->list_item_ui_param.file_size_rect.width;		
	rect.y1 = rect.y0 + ui_param->list_item_ui_param.file_size_rect.height;
	GUI_ClearRect(rect.x0,rect.y0, rect.x1, rect.y1);

	if(item->fatdirattr & FSYS_ATTR_DIRECTORY)
	{
		return EPDK_OK;
	}
	GUI_DispStringInRect(str, &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);		
	return EPDK_OK;
}

//时间转换为字符串函数(年月日字符串)
__s32 mtime_to_date_string(ES_TIMESTAMP *m_time, char *string)
{
	char temp_str[20];
	//eLIBs_memset(temp_str, 0, sizeof(temp_str));
	
	
    temp_str[0]   = m_time->year / 1000 + '0';
    temp_str[1]   = (m_time->year % 1000) / 100 + '0';
    temp_str[2]   = (m_time->year % 100) / 10 + '0';
    temp_str[3]   = m_time->year % 10 + '0';
	temp_str[4]   = 0;
	eLIBs_strcpy(string, temp_str);
	
	eLIBs_memset(temp_str, 0, sizeof(temp_str));
	get_menu_text(STRING_EXPLR_TIME_YEAR, temp_str, sizeof(temp_str));
	eLIBs_strcat(string, temp_str);
	

	if(m_time->month >= 10)
	{
    	temp_str[0]   = m_time->month / 10 + '0';
	    temp_str[1]   = m_time->month % 10 + '0';
		temp_str[2]   = 0;
	}
	else
	{
    	temp_str[0]   = m_time->month + '0';
		temp_str[1]   = 0;	
	}
	
	eLIBs_strcat(string, temp_str);
	eLIBs_memset(temp_str, 0, sizeof(temp_str));
	get_menu_text(STRING_EXPLR_TIME_MONTH, temp_str, sizeof(temp_str));
	eLIBs_strcat(string, temp_str);	

	if(m_time->day >= 10)
	{
    	temp_str[0]   = m_time->day / 10 + '0';
    	temp_str[1]   = m_time->day % 10 + '0';
		temp_str[2]   = 0;
	}
	else
	{
    	temp_str[0]   = m_time->day + '0';
    	temp_str[1]   = 0;		
	}
	eLIBs_strcat(string, temp_str);	
	
	eLIBs_memset(temp_str, 0, sizeof(temp_str));
	get_menu_text(STRING_EXPLR_TIME_DAY, temp_str, sizeof(temp_str));
	eLIBs_strcat(string, temp_str);	
	//eLIBs_strcat(string, ",");	
	
	/*	
    	temp_str[0]   = m_time->hour / 10 + '0';
    	temp_str[1]   = m_time->hour % 10 + '0';
	temp_str[2]   = ':';
    	temp_str[3]  = m_time->minute / 10 + '0';
    	temp_str[4]  = m_time->minute % 10 + '0';
	temp_str[5]   = ':';
    	temp_str[6]  = m_time->second / 10 + '0';
    	temp_str[7]  = m_time->second % 10 + '0';
    	temp_str[8]  = '\0';
	eLIBs_strcat(string, temp_str);		
	*/
	
    return EPDK_OK;
}
__s32 mtime_to_time_string(ES_TIMESTAMP *m_time, char *string)
{
    	string[0]   = m_time->hour / 10 + '0';
    	string[1]   = m_time->hour % 10 + '0';
		string[2]   = ':';
    	string[3]  = m_time->minute / 10 + '0';
    	string[4]  = m_time->minute % 10 + '0';
		string[5]   = ':';
    	string[6]  = m_time->second / 10 + '0';
    	string[7]  = m_time->second % 10 + '0';
    	string[8]  = '\0';
#if 0
	char temp_str[10];
    temp_str[0]   = m_time->hour / 10 + '0';
    temp_str[1]   = m_time->hour % 10 + '0';
	temp_str[2]   = '\0';
	eLIBs_strcat(string, temp_str);
	
	eLIBs_memset(temp_str, 0, sizeof(temp_str));
	get_menu_text(STRING_EXPLR_TIME_HOUR, temp_str, sizeof(temp_str));
	eLIBs_strcat(string, temp_str);
	
    temp_str[0]  = m_time->minute / 10 + '0';
    temp_str[1]  = m_time->minute % 10 + '0';
	temp_str[2]   = '\0';
	eLIBs_strcat(string, temp_str);	
	eLIBs_memset(temp_str, 0, sizeof(temp_str));
	get_menu_text(STRING_EXPLR_TIME_MINUTE, temp_str, sizeof(temp_str));
	eLIBs_strcat(string, temp_str);

    temp_str[0]  = m_time->second / 10 + '0';
    temp_str[1]  = m_time->second % 10 + '0';
	temp_str[2]   = '\0';
	eLIBs_strcat(string, temp_str);	
	eLIBs_memset(temp_str, 0, sizeof(temp_str));
	get_menu_text(STRING_EXPLR_TIME_MINUTE, temp_str, sizeof(temp_str));
	eLIBs_strcat(string, temp_str);	
#endif	
	return EPDK_OK;
}

//清除文件创建时间区域
__s32 explorer_clear_file_create_time_area(void)
{
	int ret = 0;
	explorer_viewer_ui_t *ui_param;	
	GUI_RECT rect;
	
	ui_param = explorer_get_viewer_ui_param();	
	rect.x0 = ui_param->list_item_ui_param.time_rect.x;		
	rect.y0 = ui_param->list_item_ui_param.time_rect.y;			
	rect.x1 = rect.x0 + ui_param->list_item_ui_param.time_rect.width;		
	rect.y1 = rect.y0 + ui_param->list_item_ui_param.time_rect.height;			
	
	GUI_ClearRect(rect.x0,rect.y0, rect.x1, rect.y1);
	GUI_ClearRect(rect.x0,rect.y0+C_DATE_Y_SPACE, rect.x1, rect.y1+C_DATE_Y_SPACE);	
	
	return EPDK_OK;
}


__s32 explorer_draw_file_create_time(char *file_name)
{
	char str[20];
	ES_TIMESTAMP mtime;
	int ret = 0;
	explorer_viewer_ui_t *ui_param;	
	GUI_RECT rect;
	
	ui_param = explorer_get_viewer_ui_param();	
	rect.x0 = ui_param->list_item_ui_param.time_rect.x;		
	rect.y0 = ui_param->list_item_ui_param.time_rect.y;			
	rect.x1 = rect.x0 + ui_param->list_item_ui_param.time_rect.width;		
	rect.y1 = rect.y0 + ui_param->list_item_ui_param.time_rect.height;
	
	ret = eLIBs_GetFileMTime(file_name,&mtime);
	if(ret == EPDK_FAIL)
	{
		GUI_ClearRect(rect.x0,rect.y0, rect.x1, rect.y1);
		GUI_ClearRect(rect.x0,rect.y0+C_DATE_Y_SPACE, rect.x1, rect.y1+C_DATE_Y_SPACE);
		return EPDK_FAIL;				//清除显示区域
	}	
	eLIBs_memset(str, 0, sizeof(str));		

	mtime_to_time_string(&mtime, str);		
	GUI_ClearRect(rect.x0,rect.y0, rect.x1, rect.y1);
	GUI_DispStringInRect(str, &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);	
	
	
	mtime_to_date_string(&mtime, str);		
	rect.y0 += C_DATE_Y_SPACE;
	rect.y1 += C_DATE_Y_SPACE;
	GUI_ClearRect(rect.x0,rect.y0, rect.x1, rect.y1);
	GUI_DispStringInRect(str, &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);		
	return EPDK_OK;
}

void explorer_delete_file_draw_process(file_op_info_t *op_info)
{
	char str[10];
	GUI_RECT rect;
	eLIBs_memclr(str, sizeof(str));
	eLIBs_sprintf(str, "%d % ",op_info->percent);	

	rect.x0 = C_DEL_FILE_PECENT_AREA_X;
	rect.y0 = C_DEL_FILE_PECENT_AREA_Y;
	rect.x1 = C_DEL_FILE_PECENT_AREA_X + C_DEL_FILE_PECENT_AREA_W;
	rect.y1 = C_DEL_FILE_PECENT_AREA_Y + C_DEL_FILE_PECENT_AREA_H;
	
	GUI_ClearRect(rect.x0,rect.y0, rect.x1, rect.y1);
	GUI_DispStringInRect(str, &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);			
	return;
}
//只显示字符串到左边窗口
void explorer_delete_file_draw_process_ext(void)
{
	char str[64];
	GUI_RECT rect;
	
	eLIBs_memclr(str, sizeof(str));
	//eLIBs_sprintf(str, "%d % ",op_info->percent);	

	rect.x0 = C_DEL_FILE_PECENT_AREA_X;
	rect.y0 = C_DEL_FILE_PECENT_AREA_Y;
	rect.x1 = C_DEL_FILE_PECENT_AREA_X + C_DEL_FILE_PECENT_AREA_W;
	rect.y1 = C_DEL_FILE_PECENT_AREA_Y + C_DEL_FILE_PECENT_AREA_H;
	get_menu_text(STRING_EXPLR_DELETE_HINT, str, sizeof(str));
	GUI_ClearRect(rect.x0,rect.y0, rect.x1, rect.y1);	
	//GUI_DispStringInRect(str, &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);	
	GUI_DispStringInRect(str, &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);
	
	return;
}


//清除删除文件字符提示区域
void explorer_clean_delete_file_hint_area(void)
{
	GUI_RECT rect;

	rect.x0 = C_DEL_FILE_PECENT_AREA_X;
	rect.y0 = C_DEL_FILE_PECENT_AREA_Y;
	rect.x1 = C_DEL_FILE_PECENT_AREA_X + C_DEL_FILE_PECENT_AREA_W;
	rect.y1 = C_DEL_FILE_PECENT_AREA_Y + C_DEL_FILE_PECENT_AREA_H;
	
	GUI_ClearRect(rect.x0,rect.y0, rect.x1, rect.y1);	
	
}
//删除文件失败提示字符
void explorer_draw_delete_file_failed(void)
{
	char str[64];
	GUI_RECT rect;
	
	eLIBs_memclr(str, sizeof(str));
	//eLIBs_sprintf(str, "%d % ",op_info->percent);	

	rect.x0 = C_DEL_FILE_PECENT_AREA_X;
	rect.y0 = C_DEL_FILE_PECENT_AREA_Y;
	rect.x1 = C_DEL_FILE_PECENT_AREA_X + C_DEL_FILE_PECENT_AREA_W;
	rect.y1 = C_DEL_FILE_PECENT_AREA_Y + C_DEL_FILE_PECENT_AREA_H;
	get_menu_text(STRING_EXPLR_DELETE_FAILED, str, sizeof(str));
	GUI_ClearRect(rect.x0,rect.y0, rect.x1, rect.y1);	
	//GUI_DispStringInRect(str, &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);	
	GUI_DispStringInRect(str, &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);
	
	return;
}
__s32 explorer_draw_file_manager_title(void)
{
	char str[30];
	explorer_viewer_ui_t *ui_param;	
	GUI_RECT rect;
	ui_param = explorer_get_viewer_ui_param();	
	rect.x0 = ui_param->list_item_ui_param.title_rect.x;		
	rect.y0 = ui_param->list_item_ui_param.title_rect.y;			
	rect.x1 = rect.x0 + ui_param->list_item_ui_param.title_rect.width;		
	rect.y1 = rect.y0 + ui_param->list_item_ui_param.title_rect.height;
	
	get_menu_text(STRING_EXPLR_MANAGER_TITLE, str, sizeof(str));
	GUI_ClearRect(rect.x0,rect.y0, rect.x1, rect.y1);	
	GUI_DispStringInRect(str, &rect, GUI_TA_VCENTER|GUI_TA_HCENTER);		
	
	return EPDK_OK;
}
void *explorer_get_file_item_icon(explorer_view_mode_e view_mode, rat_media_type_t media_type, exp_icon_status_e status)
{
	void *pic_buf = NULL;		
	//__s32 picX, picY;		
	//explorer_viewer_ui_t *ui_param;
	//ui_param = explorer_get_viewer_ui_param();

	//picX = ui_param->list_item_ui_param.icon_rect.x;
	//picY = ui_param->list_item_ui_param.icon_rect.y;
	
	switch(media_type)
	{
		case RAT_MEDIA_TYPE_VIDEO:
			if(status == FOCUSED)
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_VIDEO_ICON_FOCUSED);			
			}
			else  if(status == UNFOCUSED)
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_VIDEO_ICON_UNFOCUSED);			
			}
			break;			
		case RAT_MEDIA_TYPE_PIC:
			if(status == FOCUSED)
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_PHOTO_ICON_FOCUSED);			
			}
			else
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_PHOTO_ICON_UNFOCUSED);			
			}
			break;
		case RAT_MEDIA_TYPE_AUDIO:	
			if(status == FOCUSED)
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_MUSIC_ICON_FOCUSED);			
			}
			else
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_MUSIC_ICON_UNFOCUSED);			
			}
			break;			
/*		case RAT_MEDIA_TYPE_EBOOK:
			if(status == FOCUSED)
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_EBOOK_ICON_FOCUSED);			
			}
			else
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_EBOOK_ICON_UNFOCUSED);			
			}
			break;		
*/			
		case RAT_MEDIA_TYPE_FOLDER:
			if(status == FOCUSED)
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_FOLDER_ICON_FOCUSED);			
			}
			else
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_FOLDER_ICON_UNFOCUSED);			
			}
			break;
		case RAT_MEDIA_TYPE_EBOOK:	
		case RAT_MEDIA_TYPE_UNKNOWN:			//未知文件先以ebook为准
		case RAT_MEDIA_TYPE_FIRMWARE:
			if(status == FOCUSED)
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_UNKNOWN_FILE_ICON_FOCUSED);			
			}
			else
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_UNKNOWN_FILE_ICON_UNFOCUSED);			
			}			
			break;
		case RAT_MEDIA_TYPE_USB_DEVICE:
			if(status == FOCUSED)
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_USB_ICON_FOCUSED);			
			}
			else
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_USB_ICON_UNFOCUSED);			
			}
			break;
		case RAT_MEDIA_TYPE_SD_DEVICE:
			if(status == FOCUSED)
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_SD_ICON_FOCUSED);			
			}
			else
			{
				pic_buf = explorer_get_listview_icon_res(ID_EXP_SD_ICON_UNFOCUSED);			
			}
			break;
			
		default:
			break;		
	}
	//picW =  GUI_BMP_GetXSize(pic_buf);										//获得图片宽
	//picH =  GUI_BMP_GetYSize(pic_buf);										//获得图片高度		
	if(pic_buf != NULL)
	{
		//GUI_BMP_Draw(pic_buf, picX, picY);
	}
	return pic_buf;
}



