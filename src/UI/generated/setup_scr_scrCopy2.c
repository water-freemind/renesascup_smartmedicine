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



void setup_scr_scrCopy2(lv_ui *ui)
{
    //Write codes scrCopy2
    ui->scrCopy2 = lv_obj_create(NULL);
    lv_obj_set_size(ui->scrCopy2, 480, 320);
    lv_obj_set_scrollbar_mode(ui->scrCopy2, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrCopy2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrCopy2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrCopy2, lv_color_hex(0xF3F8FE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrCopy2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrCopy2_contBG
    ui->scrCopy2_contBG = lv_obj_create(ui->scrCopy2);
    lv_obj_set_pos(ui->scrCopy2_contBG, 0, 0);
    lv_obj_set_size(ui->scrCopy2_contBG, 480, 70);
    lv_obj_set_scrollbar_mode(ui->scrCopy2_contBG, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrCopy2_contBG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrCopy2_contBG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrCopy2_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrCopy2_contBG, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrCopy2_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrCopy2_btnBack
    ui->scrCopy2_btnBack = lv_btn_create(ui->scrCopy2_contBG);
    ui->scrCopy2_btnBack_label = lv_label_create(ui->scrCopy2_btnBack);
    lv_label_set_text(ui->scrCopy2_btnBack_label, "<");
    lv_label_set_long_mode(ui->scrCopy2_btnBack_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrCopy2_btnBack_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrCopy2_btnBack, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrCopy2_btnBack_label, LV_PCT(100));
    lv_obj_set_pos(ui->scrCopy2_btnBack, 25, 20);
    lv_obj_set_size(ui->scrCopy2_btnBack, 35, 37);

    //Write style for scrCopy2_btnBack, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrCopy2_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrCopy2_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrCopy2_btnBack, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrCopy2_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrCopy2_btnBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrCopy2_btnBack, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrCopy2_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrCopy2_btnBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrCopy2_labelTitle
    ui->scrCopy2_labelTitle = lv_label_create(ui->scrCopy2);
    lv_label_set_text(ui->scrCopy2_labelTitle, "处方单扫描");
    lv_label_set_long_mode(ui->scrCopy2_labelTitle, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrCopy2_labelTitle, 134, 27);
    lv_obj_set_size(ui->scrCopy2_labelTitle, 210, 37);

    //Write style for scrCopy2_labelTitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrCopy2_labelTitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrCopy2_labelTitle, &lv_font_st_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrCopy2_labelTitle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrCopy2_labelTitle, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrCopy2_labelTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrCopy2_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrCopy2_imgScanned
    ui->scrCopy2_imgScanned = lv_img_create(ui->scrCopy2);
    lv_obj_add_flag(ui->scrCopy2_imgScanned, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrCopy2_imgScanned, &_scan_alpha_100x100);
    lv_img_set_pivot(ui->scrCopy2_imgScanned, 0,0);
    lv_img_set_angle(ui->scrCopy2_imgScanned, 0);
    lv_obj_set_pos(ui->scrCopy2_imgScanned, 190, 150);
    lv_obj_set_size(ui->scrCopy2_imgScanned, 100, 100);

    //Write style for scrCopy2_imgScanned, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrCopy2_imgScanned, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrCopy2_imgScanned, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrCopy2_imgScanned, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrCopy2_imgScanned, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scrCopy2.


    //Update current screen layout.
    lv_obj_update_layout(ui->scrCopy2);

    //Init events for screen.
    events_init_scrCopy2(ui);
}
