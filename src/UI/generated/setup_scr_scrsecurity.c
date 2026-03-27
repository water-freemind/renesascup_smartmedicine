/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_scrsecurity(lv_ui *ui)
{
    //Write codes scrsecurity
    ui->scrsecurity = lv_obj_create(NULL);
    lv_obj_set_size(ui->scrsecurity, 480, 320);
    lv_obj_set_scrollbar_mode(ui->scrsecurity, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrsecurity, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrsecurity, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrsecurity, lv_color_hex(0xF3F8FE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrsecurity, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrsecurity_contBG
    ui->scrsecurity_contBG = lv_obj_create(ui->scrsecurity);
    lv_obj_set_pos(ui->scrsecurity_contBG, 0, 0);
    lv_obj_set_size(ui->scrsecurity_contBG, 480, 70);
    lv_obj_set_scrollbar_mode(ui->scrsecurity_contBG, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrsecurity_contBG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrsecurity_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrsecurity_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrsecurity_contBG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrsecurity_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrsecurity_contBG, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrsecurity_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrsecurity_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrsecurity_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrsecurity_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrsecurity_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrsecurity_btnBack
    ui->scrsecurity_btnBack = lv_btn_create(ui->scrsecurity_contBG);
    ui->scrsecurity_btnBack_label = lv_label_create(ui->scrsecurity_btnBack);
    lv_label_set_text(ui->scrsecurity_btnBack_label, "<");
    lv_label_set_long_mode(ui->scrsecurity_btnBack_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrsecurity_btnBack_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrsecurity_btnBack, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrsecurity_btnBack_label, LV_PCT(100));
    lv_obj_set_pos(ui->scrsecurity_btnBack, 24, 20);
    lv_obj_set_size(ui->scrsecurity_btnBack, 35, 37);

    //Write style for scrsecurity_btnBack, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrsecurity_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrsecurity_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrsecurity_btnBack, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrsecurity_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrsecurity_btnBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrsecurity_btnBack, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrsecurity_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrsecurity_btnBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrsecurity_labelTitle
    ui->scrsecurity_labelTitle = lv_label_create(ui->scrsecurity);
    lv_label_set_text(ui->scrsecurity_labelTitle, "掌静脉身份认证");
    lv_label_set_long_mode(ui->scrsecurity_labelTitle, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrsecurity_labelTitle, 135, 27);
    lv_obj_set_size(ui->scrsecurity_labelTitle, 210, 37);

    //Write style for scrsecurity_labelTitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrsecurity_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrsecurity_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrsecurity_labelTitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrsecurity_labelTitle, &lv_font_st_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrsecurity_labelTitle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrsecurity_labelTitle, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrsecurity_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrsecurity_labelTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrsecurity_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrsecurity_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrsecurity_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrsecurity_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrsecurity_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrsecurity_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrsecurity_btnNext
    ui->scrsecurity_btnNext = lv_btn_create(ui->scrsecurity);
    ui->scrsecurity_btnNext_label = lv_label_create(ui->scrsecurity_btnNext);
    lv_label_set_text(ui->scrsecurity_btnNext_label, "NEXT");
    lv_label_set_long_mode(ui->scrsecurity_btnNext_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrsecurity_btnNext_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrsecurity_btnNext, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrsecurity_btnNext_label, LV_PCT(100));
    lv_obj_set_pos(ui->scrsecurity_btnNext, 190, 267);
    lv_obj_set_size(ui->scrsecurity_btnNext, 100, 43);

    //Write style for scrsecurity_btnNext, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrsecurity_btnNext, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrsecurity_btnNext, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrsecurity_btnNext, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrsecurity_btnNext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrsecurity_btnNext, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrsecurity_btnNext, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrsecurity_btnNext, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrsecurity_btnNext, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrsecurity_btnNext, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrsecurity_btnNext, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrsecurity_img_1
    ui->scrsecurity_img_1 = lv_img_create(ui->scrsecurity);
    lv_obj_add_flag(ui->scrsecurity_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrsecurity_img_1, &_scan_alpha_100x100);
    lv_img_set_pivot(ui->scrsecurity_img_1, 50,50);
    lv_img_set_angle(ui->scrsecurity_img_1, 0);
    lv_obj_set_pos(ui->scrsecurity_img_1, 190, 131);
    lv_obj_set_size(ui->scrsecurity_img_1, 100, 100);

    //Write style for scrsecurity_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrsecurity_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrsecurity_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrsecurity_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrsecurity_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scrsecurity.


    //Update current screen layout.
    lv_obj_update_layout(ui->scrsecurity);

    //Init events for screen.
    events_init_scrsecurity(ui);
}
