/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *scrHome;
	bool scrHome_del;
	lv_obj_t *scrHome_contBG;
	lv_obj_t *scrHome_contMain;
	lv_obj_t *scrHome_contSetup;
	lv_obj_t *scrHome_imgIconSetup;
	lv_obj_t *scrHome_labelSetup;
	lv_obj_t *scrHome_contPrint;
	lv_obj_t *scrHome_imgIconPrint;
	lv_obj_t *scrHome_labelPrint;
	lv_obj_t *scrHome_contCopy;
	lv_obj_t *scrHome_imgIconCopy;
	lv_obj_t *scrHome_labelCopy;
	lv_obj_t *scrHome_contScan;
	lv_obj_t *scrHome_imgIconScan;
	lv_obj_t *scrHome_labelScan;
	lv_obj_t *scrHome_contTop;
	lv_obj_t *scrHome_imgIconWIFI;
	lv_obj_t *scrHome_imgIconCall;
	lv_obj_t *scrHome_imgIconEco;
	lv_obj_t *scrHome_imgIconPC;
	lv_obj_t *scrHome_labelDate;
	lv_obj_t *scrHome_labelPrompt;
	lv_obj_t *scrHome_contColorInk;
	lv_obj_t *scrHome_barBlueInk;
	lv_obj_t *scrHome_barRedInk;
	lv_obj_t *scrHome_barYellowInk;
	lv_obj_t *scrHome_barBlackInk;
	lv_obj_t *scrCopy;
	bool scrCopy_del;
	lv_obj_t *scrCopy_contBG;
	lv_obj_t *scrCopy_labelTitle;
	lv_obj_t *scrCopy_btnNext;
	lv_obj_t *scrCopy_btnNext_label;
	lv_obj_t *scrCopy_btnBack;
	lv_obj_t *scrCopy_btnBack_label;
	lv_obj_t *scrCopy_img_1;
	lv_obj_t *scrCopy2;
	bool scrCopy2_del;
	lv_obj_t *scrCopy2_contBG;
	lv_obj_t *scrCopy2_btnBack;
	lv_obj_t *scrCopy2_btnBack_label;
	lv_obj_t *scrCopy2_labelTitle;
	lv_obj_t *scrCopy2_imgScanned;
	lv_obj_t *scrScan;
	bool scrScan_del;
	lv_obj_t *scrScan_contBG;
	lv_obj_t *scrScan_labelTitle;
	lv_obj_t *scrScan_imgScanned;
	lv_obj_t *scrScan_contPanel;
	lv_obj_t *scrScan_imgIconBright;
	lv_obj_t *scrScan_imgIconHue;
	lv_obj_t *scrScan_sliderBright;
	lv_obj_t *scrScan_sliderHue;
	lv_obj_t *scrScan_btnNext;
	lv_obj_t *scrScan_btnNext_label;
	lv_obj_t *scrScan_btnBack;
	lv_obj_t *scrScan_btnBack_label;
	lv_obj_t *scrPrintMenu;
	bool scrPrintMenu_del;
	lv_obj_t *scrPrintMenu_contBG;
	lv_obj_t *scrPrintMenu_labelTitle;
	lv_obj_t *scrPrintMenu_btnBack;
	lv_obj_t *scrPrintMenu_btnBack_label;
	lv_obj_t *scrPrintMenu_contMain;
	lv_obj_t *scrPrintMenu_btnleft;
	lv_obj_t *scrPrintMenu_imgInternet;
	lv_obj_t *scrPrintMenu_btndown;
	lv_obj_t *scrPrintMenu_imgMobile;
	lv_obj_t *scrPrintMenu_btnup;
	lv_obj_t *scrPrintMenu_imgUSB;
	lv_obj_t *scrPrintMenu_btnright;
	lv_obj_t *scrPrintMenu_img_1;
	lv_obj_t *scrSetup;
	bool scrSetup_del;
	lv_obj_t *scrSetup_contBG;
	lv_obj_t *scrSetup_imgPrinter;
	lv_obj_t *scrSetup_imgWave;
	lv_obj_t *scrSetup_imgCloud;
	lv_obj_t *scrSetup_labelPrompt;
	lv_obj_t *scrSetup_btnBack;
	lv_obj_t *scrSetup_btnBack_label;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_scrHome(lv_ui *ui);
void setup_scr_scrCopy(lv_ui *ui);
void setup_scr_scrCopy2(lv_ui *ui);
void setup_scr_scrScan(lv_ui *ui);
void setup_scr_scrPrintMenu(lv_ui *ui);
void setup_scr_scrSetup(lv_ui *ui);

LV_IMG_DECLARE(_btn_bg_4_100x141);
LV_IMG_DECLARE(_setup_alpha_40x40);

LV_IMG_DECLARE(_btn_bg_3_100x141);
LV_IMG_DECLARE(_wave_alpha_40x40);

LV_IMG_DECLARE(_btn_bg_1_100x141);
LV_IMG_DECLARE(_copy_alpha_37x47);

LV_IMG_DECLARE(_btn_bg_2_100x141);
LV_IMG_DECLARE(_mobile_alpha_37x47);
LV_IMG_DECLARE(_wifi_alpha_33x29);
LV_IMG_DECLARE(_tel_alpha_28x28);
LV_IMG_DECLARE(_eco_alpha_29x25);
LV_IMG_DECLARE(_pc_alpha_30x28);
LV_IMG_DECLARE(_scan_alpha_100x100);
LV_IMG_DECLARE(_scan_alpha_100x100);
LV_IMG_DECLARE(_example_alpha_310x228);
LV_IMG_DECLARE(_bright_alpha_20x20);
LV_IMG_DECLARE(_hue_alpha_18x18);

LV_IMG_DECLARE(_btn_bg_4_100x70);
LV_IMG_DECLARE(_right_alpha_40x40);

LV_IMG_DECLARE(_btn_bg_3_75x100);
LV_IMG_DECLARE(_down_alpha_40x40);

LV_IMG_DECLARE(_btn_bg_2_75x100);
LV_IMG_DECLARE(_up2_alpha_40x40);

LV_IMG_DECLARE(_btn_bg_1_100x70);
LV_IMG_DECLARE(_left_alpha_40x40);
LV_IMG_DECLARE(_printer2_alpha_84x91);
LV_IMG_DECLARE(_no_internet_alpha_40x43);
LV_IMG_DECLARE(_cloud_alpha_74x60);

LV_FONT_DECLARE(lv_font_st_18)
LV_FONT_DECLARE(lv_font_st_30)
LV_FONT_DECLARE(lv_font_st_20)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_montserratMedium_25)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_16)


#ifdef __cplusplus
}
#endif
#endif
