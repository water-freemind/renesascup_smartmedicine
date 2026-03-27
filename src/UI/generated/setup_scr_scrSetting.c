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



void setup_scr_scrSetting(lv_ui *ui)
{
    //Write codes scrSetting
    ui->scrSetting = lv_obj_create(NULL);
    lv_obj_set_size(ui->scrSetting, 480, 320);
    lv_obj_set_scrollbar_mode(ui->scrSetting, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrSetting, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrSetting, 254, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrSetting, lv_color_hex(0xF3F8FE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrSetting, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrSetting_contBG
    ui->scrSetting_contBG = lv_obj_create(ui->scrSetting);
    lv_obj_set_pos(ui->scrSetting_contBG, 0, 0);
    lv_obj_set_size(ui->scrSetting_contBG, 480, 320);
    lv_obj_set_scrollbar_mode(ui->scrSetting_contBG, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrSetting_contBG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrSetting_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrSetting_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrSetting_contBG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrSetting_contBG, lv_color_hex(0xbff2ff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrSetting_contBG, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrSetting_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrSetting_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrSetting_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrSetting_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrSetting_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrSetting_btnBack
    ui->scrSetting_btnBack = lv_btn_create(ui->scrSetting_contBG);
    ui->scrSetting_btnBack_label = lv_label_create(ui->scrSetting_btnBack);
    lv_label_set_text(ui->scrSetting_btnBack_label, "BACK");
    lv_label_set_long_mode(ui->scrSetting_btnBack_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrSetting_btnBack_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrSetting_btnBack, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrSetting_btnBack_label, LV_PCT(100));
    lv_obj_set_pos(ui->scrSetting_btnBack, 180, 251);
    lv_obj_set_size(ui->scrSetting_btnBack, 120, 45);

    //Write style for scrSetting_btnBack, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrSetting_btnBack, 220, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrSetting_btnBack, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrSetting_btnBack, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrSetting_btnBack, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->scrSetting_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->scrSetting_btnBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->scrSetting_btnBack, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrSetting_btnBack, 22, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrSetting_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrSetting_btnBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrSetting_btnBack, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrSetting_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrSetting_btnBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrSetting_btn_1
    ui->scrSetting_btn_1 = lv_btn_create(ui->scrSetting);
    ui->scrSetting_btn_1_label = lv_label_create(ui->scrSetting_btn_1);
    lv_label_set_text(ui->scrSetting_btn_1_label, "Set_zero");
    lv_label_set_long_mode(ui->scrSetting_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrSetting_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrSetting_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrSetting_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->scrSetting_btn_1, 25, 97);
    lv_obj_set_size(ui->scrSetting_btn_1, 100, 43);

    //Write style for scrSetting_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrSetting_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrSetting_btn_1, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrSetting_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrSetting_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrSetting_btn_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrSetting_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrSetting_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrSetting_btn_1, &lv_font_montserratMedium_18, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrSetting_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrSetting_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for scrSetting_btn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_bg_opa(ui->scrSetting_btn_1, 198, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_color(ui->scrSetting_btn_1, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_bg_grad_dir(ui->scrSetting_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui->scrSetting_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_radius(ui->scrSetting_btn_1, 5, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->scrSetting_btn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->scrSetting_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->scrSetting_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->scrSetting_btn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write codes scrSetting_cont_1
    ui->scrSetting_cont_1 = lv_obj_create(ui->scrSetting);
    lv_obj_set_pos(ui->scrSetting_cont_1, 0, 0);
    lv_obj_set_size(ui->scrSetting_cont_1, 480, 70);
    lv_obj_set_scrollbar_mode(ui->scrSetting_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrSetting_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrSetting_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrSetting_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrSetting_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrSetting_cont_1, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrSetting_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrSetting_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrSetting_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrSetting_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrSetting_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrSetting_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrSetting_label_text
    ui->scrSetting_label_text = lv_label_create(ui->scrSetting);
    lv_label_set_text(ui->scrSetting_label_text, "设置");
    lv_label_set_long_mode(ui->scrSetting_label_text, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrSetting_label_text, 135, 27);
    lv_obj_set_size(ui->scrSetting_label_text, 210, 37);

    //Write style for scrSetting_label_text, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrSetting_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrSetting_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrSetting_label_text, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrSetting_label_text, &lv_font_st_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrSetting_label_text, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrSetting_label_text, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrSetting_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrSetting_label_text, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrSetting_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrSetting_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrSetting_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrSetting_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrSetting_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrSetting_label_text, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrSetting_label_x_pos
    ui->scrSetting_label_x_pos = lv_spangroup_create(ui->scrSetting);
    lv_spangroup_set_align(ui->scrSetting_label_x_pos, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->scrSetting_label_x_pos, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->scrSetting_label_x_pos, LV_SPAN_MODE_BREAK);
    //create span
    ui->scrSetting_label_x_pos_span = lv_spangroup_new_span(ui->scrSetting_label_x_pos);
    lv_span_set_text(ui->scrSetting_label_x_pos_span, "X_current_position: undetect");
    lv_style_set_text_color(&ui->scrSetting_label_x_pos_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&ui->scrSetting_label_x_pos_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->scrSetting_label_x_pos_span->style, &lv_font_montserratMedium_14);
    lv_obj_set_pos(ui->scrSetting_label_x_pos, 53, 175);
    lv_obj_set_size(ui->scrSetting_label_x_pos, 211, 13);

    //Write style state: LV_STATE_DEFAULT for &style_scrSetting_label_x_pos_main_main_default
    static lv_style_t style_scrSetting_label_x_pos_main_main_default;
    ui_init_style(&style_scrSetting_label_x_pos_main_main_default);

    lv_style_set_border_width(&style_scrSetting_label_x_pos_main_main_default, 0);
    lv_style_set_radius(&style_scrSetting_label_x_pos_main_main_default, 0);
    lv_style_set_bg_opa(&style_scrSetting_label_x_pos_main_main_default, 0);
    lv_style_set_pad_top(&style_scrSetting_label_x_pos_main_main_default, 0);
    lv_style_set_pad_right(&style_scrSetting_label_x_pos_main_main_default, 0);
    lv_style_set_pad_bottom(&style_scrSetting_label_x_pos_main_main_default, 0);
    lv_style_set_pad_left(&style_scrSetting_label_x_pos_main_main_default, 0);
    lv_style_set_shadow_width(&style_scrSetting_label_x_pos_main_main_default, 0);
    lv_obj_add_style(ui->scrSetting_label_x_pos, &style_scrSetting_label_x_pos_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->scrSetting_label_x_pos);

    //Write codes scrSetting_label_y_pos
    ui->scrSetting_label_y_pos = lv_spangroup_create(ui->scrSetting);
    lv_spangroup_set_align(ui->scrSetting_label_y_pos, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->scrSetting_label_y_pos, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->scrSetting_label_y_pos, LV_SPAN_MODE_BREAK);
    //create span
    ui->scrSetting_label_y_pos_span = lv_spangroup_new_span(ui->scrSetting_label_y_pos);
    lv_span_set_text(ui->scrSetting_label_y_pos_span, "Y_current_position: undetect");
    lv_style_set_text_color(&ui->scrSetting_label_y_pos_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&ui->scrSetting_label_y_pos_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->scrSetting_label_y_pos_span->style, &lv_font_montserratMedium_14);
    lv_obj_set_pos(ui->scrSetting_label_y_pos, 53, 219);
    lv_obj_set_size(ui->scrSetting_label_y_pos, 211, 13);

    //Write style state: LV_STATE_DEFAULT for &style_scrSetting_label_y_pos_main_main_default
    static lv_style_t style_scrSetting_label_y_pos_main_main_default;
    ui_init_style(&style_scrSetting_label_y_pos_main_main_default);

    lv_style_set_border_width(&style_scrSetting_label_y_pos_main_main_default, 0);
    lv_style_set_radius(&style_scrSetting_label_y_pos_main_main_default, 0);
    lv_style_set_bg_opa(&style_scrSetting_label_y_pos_main_main_default, 0);
    lv_style_set_pad_top(&style_scrSetting_label_y_pos_main_main_default, 0);
    lv_style_set_pad_right(&style_scrSetting_label_y_pos_main_main_default, 0);
    lv_style_set_pad_bottom(&style_scrSetting_label_y_pos_main_main_default, 0);
    lv_style_set_pad_left(&style_scrSetting_label_y_pos_main_main_default, 0);
    lv_style_set_shadow_width(&style_scrSetting_label_y_pos_main_main_default, 0);
    lv_obj_add_style(ui->scrSetting_label_y_pos, &style_scrSetting_label_y_pos_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->scrSetting_label_y_pos);

    //The custom code of scrSetting.


    //Update current screen layout.
    lv_obj_update_layout(ui->scrSetting);

    //Init events for screen.
    events_init_scrSetting(ui);
}
