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



void setup_scr_scrcontrol(lv_ui *ui)
{
    //Write codes scrcontrol
    ui->scrcontrol = lv_obj_create(NULL);
    lv_obj_set_size(ui->scrcontrol, 480, 320);
    lv_obj_set_scrollbar_mode(ui->scrcontrol, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrcontrol, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrcontrol, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrcontrol, lv_color_hex(0xF3F8FE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrcontrol, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrcontrol_contBG
    ui->scrcontrol_contBG = lv_obj_create(ui->scrcontrol);
    lv_obj_set_pos(ui->scrcontrol_contBG, 0, 0);
    lv_obj_set_size(ui->scrcontrol_contBG, 480, 70);
    lv_obj_set_scrollbar_mode(ui->scrcontrol_contBG, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrcontrol_contBG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrcontrol_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrcontrol_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrcontrol_contBG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrcontrol_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrcontrol_contBG, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrcontrol_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrcontrol_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrcontrol_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrcontrol_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrcontrol_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrcontrol_labelTitle
    ui->scrcontrol_labelTitle = lv_label_create(ui->scrcontrol);
    lv_label_set_text(ui->scrcontrol_labelTitle, "校准操作");
    lv_label_set_long_mode(ui->scrcontrol_labelTitle, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrcontrol_labelTitle, 135, 27);
    lv_obj_set_size(ui->scrcontrol_labelTitle, 210, 37);

    //Write style for scrcontrol_labelTitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrcontrol_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrcontrol_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrcontrol_labelTitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrcontrol_labelTitle, &lv_font_st_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrcontrol_labelTitle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrcontrol_labelTitle, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrcontrol_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrcontrol_labelTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrcontrol_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrcontrol_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrcontrol_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrcontrol_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrcontrol_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrcontrol_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrcontrol_btnBack
    ui->scrcontrol_btnBack = lv_btn_create(ui->scrcontrol);
    ui->scrcontrol_btnBack_label = lv_label_create(ui->scrcontrol_btnBack);
    lv_label_set_text(ui->scrcontrol_btnBack_label, "<");
    lv_label_set_long_mode(ui->scrcontrol_btnBack_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrcontrol_btnBack_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrcontrol_btnBack, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrcontrol_btnBack_label, LV_PCT(100));
    lv_obj_set_pos(ui->scrcontrol_btnBack, 25, 20);
    lv_obj_set_size(ui->scrcontrol_btnBack, 35, 37);

    //Write style for scrcontrol_btnBack, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrcontrol_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrcontrol_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrcontrol_btnBack, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrcontrol_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrcontrol_btnBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrcontrol_btnBack, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrcontrol_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrcontrol_btnBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrcontrol_contMain
    ui->scrcontrol_contMain = lv_obj_create(ui->scrcontrol);
    lv_obj_set_pos(ui->scrcontrol_contMain, 35, 74);
    lv_obj_set_size(ui->scrcontrol_contMain, 409, 244);
    lv_obj_set_scrollbar_mode(ui->scrcontrol_contMain, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrcontrol_contMain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrcontrol_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrcontrol_contMain, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrcontrol_contMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrcontrol_contMain, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrcontrol_contMain, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrcontrol_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrcontrol_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrcontrol_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrcontrol_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrcontrol_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrcontrol_btnleft
    ui->scrcontrol_btnleft = lv_obj_create(ui->scrcontrol_contMain);
    lv_obj_set_pos(ui->scrcontrol_btnleft, 235, 100);
    lv_obj_set_size(ui->scrcontrol_btnleft, 100, 70);
    lv_obj_set_scrollbar_mode(ui->scrcontrol_btnleft, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrcontrol_btnleft, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrcontrol_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrcontrol_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrcontrol_btnleft, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrcontrol_btnleft, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrcontrol_btnleft, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrcontrol_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrcontrol_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrcontrol_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrcontrol_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->scrcontrol_btnleft, &_btn_bg_4_100x70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->scrcontrol_btnleft, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->scrcontrol_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrcontrol_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrcontrol_imgInternet
    ui->scrcontrol_imgInternet = lv_img_create(ui->scrcontrol_btnleft);
    lv_obj_add_flag(ui->scrcontrol_imgInternet, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrcontrol_imgInternet, &_right_alpha_40x40);
    lv_img_set_pivot(ui->scrcontrol_imgInternet, 50,50);
    lv_img_set_angle(ui->scrcontrol_imgInternet, 0);
    lv_obj_set_pos(ui->scrcontrol_imgInternet, 38, 15);
    lv_obj_set_size(ui->scrcontrol_imgInternet, 40, 40);
    lv_obj_add_flag(ui->scrcontrol_imgInternet, LV_OBJ_FLAG_EVENT_BUBBLE);

    //Write style for scrcontrol_imgInternet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrcontrol_imgInternet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrcontrol_imgInternet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrcontrol_imgInternet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrcontrol_imgInternet, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrcontrol_btndown
    ui->scrcontrol_btndown = lv_obj_create(ui->scrcontrol_contMain);
    lv_obj_set_pos(ui->scrcontrol_btndown, 165, 135);
    lv_obj_set_size(ui->scrcontrol_btndown, 75, 100);
    lv_obj_set_scrollbar_mode(ui->scrcontrol_btndown, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrcontrol_btndown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrcontrol_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrcontrol_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrcontrol_btndown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrcontrol_btndown, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrcontrol_btndown, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrcontrol_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrcontrol_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrcontrol_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrcontrol_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->scrcontrol_btndown, &_btn_bg_3_75x100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->scrcontrol_btndown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->scrcontrol_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrcontrol_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrcontrol_imgMobile
    ui->scrcontrol_imgMobile = lv_img_create(ui->scrcontrol_btndown);
    lv_obj_add_flag(ui->scrcontrol_imgMobile, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrcontrol_imgMobile, &_down_alpha_40x40);
    lv_img_set_pivot(ui->scrcontrol_imgMobile, 50,50);
    lv_img_set_angle(ui->scrcontrol_imgMobile, 0);
    lv_obj_set_pos(ui->scrcontrol_imgMobile, 19, 23);
    lv_obj_set_size(ui->scrcontrol_imgMobile, 40, 40);
    lv_obj_add_flag(ui->scrcontrol_imgMobile, LV_OBJ_FLAG_EVENT_BUBBLE);

    //Write style for scrcontrol_imgMobile, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrcontrol_imgMobile, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrcontrol_imgMobile, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrcontrol_imgMobile, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrcontrol_imgMobile, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrcontrol_btnup
    ui->scrcontrol_btnup = lv_obj_create(ui->scrcontrol_contMain);
    lv_obj_set_pos(ui->scrcontrol_btnup, 165, 30);
    lv_obj_set_size(ui->scrcontrol_btnup, 75, 100);
    lv_obj_set_scrollbar_mode(ui->scrcontrol_btnup, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrcontrol_btnup, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrcontrol_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrcontrol_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrcontrol_btnup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrcontrol_btnup, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrcontrol_btnup, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrcontrol_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrcontrol_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrcontrol_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrcontrol_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->scrcontrol_btnup, &_btn_bg_2_75x100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->scrcontrol_btnup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->scrcontrol_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrcontrol_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrcontrol_imgUSB
    ui->scrcontrol_imgUSB = lv_img_create(ui->scrcontrol_btnup);
    lv_obj_add_flag(ui->scrcontrol_imgUSB, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrcontrol_imgUSB, &_up2_alpha_40x40);
    lv_img_set_pivot(ui->scrcontrol_imgUSB, 50,50);
    lv_img_set_angle(ui->scrcontrol_imgUSB, 0);
    lv_obj_set_pos(ui->scrcontrol_imgUSB, 19, 28);
    lv_obj_set_size(ui->scrcontrol_imgUSB, 40, 40);
    lv_obj_add_flag(ui->scrcontrol_imgUSB, LV_OBJ_FLAG_EVENT_BUBBLE);

    //Write style for scrcontrol_imgUSB, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrcontrol_imgUSB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrcontrol_imgUSB, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrcontrol_imgUSB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrcontrol_imgUSB, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrcontrol_btnright
    ui->scrcontrol_btnright = lv_obj_create(ui->scrcontrol_contMain);
    lv_obj_set_pos(ui->scrcontrol_btnright, 70, 100);
    lv_obj_set_size(ui->scrcontrol_btnright, 100, 70);
    lv_obj_set_scrollbar_mode(ui->scrcontrol_btnright, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrcontrol_btnright, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrcontrol_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrcontrol_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrcontrol_btnright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrcontrol_btnright, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrcontrol_btnright, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrcontrol_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrcontrol_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrcontrol_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrcontrol_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->scrcontrol_btnright, &_btn_bg_1_100x70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->scrcontrol_btnright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->scrcontrol_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrcontrol_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrcontrol_img_1
    ui->scrcontrol_img_1 = lv_img_create(ui->scrcontrol_btnright);
    lv_obj_add_flag(ui->scrcontrol_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrcontrol_img_1, &_left_alpha_40x40);
    lv_img_set_pivot(ui->scrcontrol_img_1, 50,50);
    lv_img_set_angle(ui->scrcontrol_img_1, 0);
    lv_obj_set_pos(ui->scrcontrol_img_1, 28, 15);
    lv_obj_set_size(ui->scrcontrol_img_1, 40, 40);
    lv_obj_add_flag(ui->scrcontrol_img_1, LV_OBJ_FLAG_EVENT_BUBBLE);

    //Write style for scrcontrol_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrcontrol_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrcontrol_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrcontrol_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrcontrol_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scrcontrol.


    //Update current screen layout.
    lv_obj_update_layout(ui->scrcontrol);

    //Init events for screen.
    events_init_scrcontrol(ui);
}
