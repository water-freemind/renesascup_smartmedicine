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



void setup_scr_scrscan(lv_ui *ui)
{
    //Write codes scrscan
    ui->scrscan = lv_obj_create(NULL);
    lv_obj_set_size(ui->scrscan, 480, 320);
    lv_obj_set_scrollbar_mode(ui->scrscan, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrscan, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrscan, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrscan, lv_color_hex(0xF3F8FE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrscan, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrscan_contBG
    ui->scrscan_contBG = lv_obj_create(ui->scrscan);
    lv_obj_set_pos(ui->scrscan_contBG, 0, 0);
    lv_obj_set_size(ui->scrscan_contBG, 480, 70);
    lv_obj_set_scrollbar_mode(ui->scrscan_contBG, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrscan_contBG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrscan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrscan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrscan_contBG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrscan_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrscan_contBG, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrscan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrscan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrscan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrscan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrscan_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrscan_btnBack
    ui->scrscan_btnBack = lv_btn_create(ui->scrscan_contBG);
    ui->scrscan_btnBack_label = lv_label_create(ui->scrscan_btnBack);
    lv_label_set_text(ui->scrscan_btnBack_label, "<");
    lv_label_set_long_mode(ui->scrscan_btnBack_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrscan_btnBack_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrscan_btnBack, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrscan_btnBack_label, LV_PCT(100));
    lv_obj_set_pos(ui->scrscan_btnBack, 25, 20);
    lv_obj_set_size(ui->scrscan_btnBack, 35, 37);

    //Write style for scrscan_btnBack, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrscan_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrscan_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrscan_btnBack, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrscan_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrscan_btnBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrscan_btnBack, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrscan_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrscan_btnBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrscan_labelTitle
    ui->scrscan_labelTitle = lv_label_create(ui->scrscan);
    lv_label_set_text(ui->scrscan_labelTitle, "处方单扫描");
    lv_label_set_long_mode(ui->scrscan_labelTitle, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrscan_labelTitle, 134, 26);
    lv_obj_set_size(ui->scrscan_labelTitle, 210, 37);

    //Write style for scrscan_labelTitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrscan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrscan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrscan_labelTitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrscan_labelTitle, &lv_font_st_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrscan_labelTitle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrscan_labelTitle, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrscan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrscan_labelTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrscan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrscan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrscan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrscan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrscan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrscan_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrscan_imgScanned
    ui->scrscan_imgScanned = lv_img_create(ui->scrscan);
    lv_obj_add_flag(ui->scrscan_imgScanned, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrscan_imgScanned, &_scan_alpha_174x167);
    lv_img_set_pivot(ui->scrscan_imgScanned, 0,0);
    lv_img_set_angle(ui->scrscan_imgScanned, 0);
    lv_obj_set_pos(ui->scrscan_imgScanned, 153, 105);
    lv_obj_set_size(ui->scrscan_imgScanned, 174, 167);

    //Write style for scrscan_imgScanned, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrscan_imgScanned, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrscan_imgScanned, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrscan_imgScanned, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrscan_imgScanned, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrscan_label_1
    ui->scrscan_label_1 = lv_label_create(ui->scrscan);
    lv_label_set_text(ui->scrscan_label_1, "Scanning.......");
    lv_label_set_long_mode(ui->scrscan_label_1, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_pos(ui->scrscan_label_1, 182, 166);
    lv_obj_set_size(ui->scrscan_label_1, 117, 38);

    //Write style for scrscan_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrscan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrscan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrscan_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrscan_label_1, &lv_font_montserratMedium_27, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrscan_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrscan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrscan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrscan_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrscan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrscan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrscan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrscan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrscan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrscan_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scrscan.


    //Update current screen layout.
    lv_obj_update_layout(ui->scrscan);

    //Init events for screen.
    events_init_scrscan(ui);
}
