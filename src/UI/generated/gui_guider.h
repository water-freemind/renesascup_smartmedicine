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
	lv_obj_t *scrsecurity;
	bool scrsecurity_del;
	lv_obj_t *scrsecurity_contBG;
	lv_obj_t *scrsecurity_btnBack;
	lv_obj_t *scrsecurity_btnBack_label;
	lv_obj_t *scrsecurity_labelTitle;
	lv_obj_t *scrsecurity_btnNext;
	lv_obj_t *scrsecurity_btnNext_label;
	lv_obj_t *scrsecurity_img_1;
	lv_obj_t *scrscan;
	bool scrscan_del;
	lv_obj_t *scrscan_contBG;
	lv_obj_t *scrscan_btnBack;
	lv_obj_t *scrscan_btnBack_label;
	lv_obj_t *scrscan_labelTitle;
	lv_obj_t *scrscan_imgScanned;
	lv_obj_t *scrscan_label_1;
	lv_obj_t *scrstore;
	bool scrstore_del;
	lv_obj_t *scrstore_contBG;
	lv_obj_t *scrstore_labelTitle;
	lv_obj_t *scrstore_btnBack;
	lv_obj_t *scrstore_btnBack_label;
	lv_obj_t *scrcontrol;
	bool scrcontrol_del;
	lv_obj_t *scrcontrol_contBG;
	lv_obj_t *scrcontrol_labelTitle;
	lv_obj_t *scrcontrol_btnBack;
	lv_obj_t *scrcontrol_btnBack_label;
	lv_obj_t *scrcontrol_contMain;
	lv_obj_t *scrcontrol_btnleft;
	lv_obj_t *scrcontrol_imgInternet;
	lv_obj_t *scrcontrol_btndown;
	lv_obj_t *scrcontrol_imgMobile;
	lv_obj_t *scrcontrol_btnup;
	lv_obj_t *scrcontrol_imgUSB;
	lv_obj_t *scrcontrol_btnright;
	lv_obj_t *scrcontrol_img_1;
	lv_obj_t *scrSetting;
	bool scrSetting_del;
	lv_obj_t *scrSetting_contBG;
	lv_obj_t *scrSetting_btnBack;
	lv_obj_t *scrSetting_btnBack_label;
	lv_obj_t *scrSetting_btn_1;
	lv_obj_t *scrSetting_btn_1_label;
	lv_obj_t *scrSetting_cont_1;
	lv_obj_t *scrSetting_label_text;
	lv_obj_t *scrSetting_label_x_pos;
	lv_span_t *scrSetting_label_x_pos_span;
	lv_obj_t *scrSetting_label_y_pos;
	lv_span_t *scrSetting_label_y_pos_span;
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
void setup_scr_scrsecurity(lv_ui *ui);
void setup_scr_scrscan(lv_ui *ui);
void setup_scr_scrstore(lv_ui *ui);
void setup_scr_scrcontrol(lv_ui *ui);
void setup_scr_scrSetting(lv_ui *ui);

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
LV_IMG_DECLARE(_scan_alpha_174x167);

LV_IMG_DECLARE(_btn_bg_4_100x70);
LV_IMG_DECLARE(_right_alpha_40x40);

LV_IMG_DECLARE(_btn_bg_3_75x100);
LV_IMG_DECLARE(_down_alpha_40x40);

LV_IMG_DECLARE(_btn_bg_2_75x100);
LV_IMG_DECLARE(_up2_alpha_40x40);

LV_IMG_DECLARE(_btn_bg_1_100x70);
LV_IMG_DECLARE(_left_alpha_40x40);

LV_FONT_DECLARE(lv_font_st_18)
LV_FONT_DECLARE(lv_font_st_30)
LV_FONT_DECLARE(lv_font_montserratMedium_25)
LV_FONT_DECLARE(lv_font_st_20)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_montserratMedium_27)
LV_FONT_DECLARE(lv_font_montserratMedium_20)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_14)


#ifdef __cplusplus
}
#endif
#endif
