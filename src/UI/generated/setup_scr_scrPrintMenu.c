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



void setup_scr_scrPrintMenu(lv_ui *ui)
{
    //Write codes scrPrintMenu
    ui->scrPrintMenu = lv_obj_create(NULL);
    lv_obj_set_size(ui->scrPrintMenu, 480, 320);
    lv_obj_set_scrollbar_mode(ui->scrPrintMenu, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrPrintMenu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrPrintMenu, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrPrintMenu, lv_color_hex(0xF3F8FE), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrPrintMenu, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrPrintMenu_contBG
    ui->scrPrintMenu_contBG = lv_obj_create(ui->scrPrintMenu);
    lv_obj_set_pos(ui->scrPrintMenu_contBG, 0, 0);
    lv_obj_set_size(ui->scrPrintMenu_contBG, 480, 70);
    lv_obj_set_scrollbar_mode(ui->scrPrintMenu_contBG, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrPrintMenu_contBG, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrPrintMenu_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrPrintMenu_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrPrintMenu_contBG, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrPrintMenu_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrPrintMenu_contBG, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrPrintMenu_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrPrintMenu_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrPrintMenu_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrPrintMenu_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrPrintMenu_contBG, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrPrintMenu_labelTitle
    ui->scrPrintMenu_labelTitle = lv_label_create(ui->scrPrintMenu);
    lv_label_set_text(ui->scrPrintMenu_labelTitle, "校准操作");
    lv_label_set_long_mode(ui->scrPrintMenu_labelTitle, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->scrPrintMenu_labelTitle, 135, 27);
    lv_obj_set_size(ui->scrPrintMenu_labelTitle, 210, 37);

    //Write style for scrPrintMenu_labelTitle, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrPrintMenu_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrPrintMenu_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrPrintMenu_labelTitle, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrPrintMenu_labelTitle, &lv_font_st_20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrPrintMenu_labelTitle, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->scrPrintMenu_labelTitle, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->scrPrintMenu_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrPrintMenu_labelTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrPrintMenu_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrPrintMenu_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrPrintMenu_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrPrintMenu_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrPrintMenu_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrPrintMenu_labelTitle, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrPrintMenu_btnBack
    ui->scrPrintMenu_btnBack = lv_btn_create(ui->scrPrintMenu);
    ui->scrPrintMenu_btnBack_label = lv_label_create(ui->scrPrintMenu_btnBack);
    lv_label_set_text(ui->scrPrintMenu_btnBack_label, "<");
    lv_label_set_long_mode(ui->scrPrintMenu_btnBack_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->scrPrintMenu_btnBack_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->scrPrintMenu_btnBack, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->scrPrintMenu_btnBack_label, LV_PCT(100));
    lv_obj_set_pos(ui->scrPrintMenu_btnBack, 25, 20);
    lv_obj_set_size(ui->scrPrintMenu_btnBack, 35, 37);

    //Write style for scrPrintMenu_btnBack, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->scrPrintMenu_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->scrPrintMenu_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrPrintMenu_btnBack, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrPrintMenu_btnBack, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->scrPrintMenu_btnBack, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->scrPrintMenu_btnBack, &lv_font_montserratMedium_25, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->scrPrintMenu_btnBack, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->scrPrintMenu_btnBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrPrintMenu_contMain
    ui->scrPrintMenu_contMain = lv_obj_create(ui->scrPrintMenu);
    lv_obj_set_pos(ui->scrPrintMenu_contMain, 35, 74);
    lv_obj_set_size(ui->scrPrintMenu_contMain, 409, 244);
    lv_obj_set_scrollbar_mode(ui->scrPrintMenu_contMain, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrPrintMenu_contMain, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrPrintMenu_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrPrintMenu_contMain, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrPrintMenu_contMain, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrPrintMenu_contMain, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrPrintMenu_contMain, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrPrintMenu_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrPrintMenu_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrPrintMenu_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrPrintMenu_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrPrintMenu_contMain, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrPrintMenu_btnleft
    ui->scrPrintMenu_btnleft = lv_obj_create(ui->scrPrintMenu_contMain);
    lv_obj_set_pos(ui->scrPrintMenu_btnleft, 235, 100);
    lv_obj_set_size(ui->scrPrintMenu_btnleft, 100, 70);
    lv_obj_set_scrollbar_mode(ui->scrPrintMenu_btnleft, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrPrintMenu_btnleft, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrPrintMenu_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrPrintMenu_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrPrintMenu_btnleft, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrPrintMenu_btnleft, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrPrintMenu_btnleft, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrPrintMenu_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrPrintMenu_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrPrintMenu_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrPrintMenu_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->scrPrintMenu_btnleft, &_btn_bg_4_100x70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->scrPrintMenu_btnleft, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->scrPrintMenu_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrPrintMenu_btnleft, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrPrintMenu_imgInternet
    ui->scrPrintMenu_imgInternet = lv_img_create(ui->scrPrintMenu_btnleft);
    lv_obj_add_flag(ui->scrPrintMenu_imgInternet, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrPrintMenu_imgInternet, &_right_alpha_40x40);
    lv_img_set_pivot(ui->scrPrintMenu_imgInternet, 50,50);
    lv_img_set_angle(ui->scrPrintMenu_imgInternet, 0);
    lv_obj_set_pos(ui->scrPrintMenu_imgInternet, 38, 15);
    lv_obj_set_size(ui->scrPrintMenu_imgInternet, 40, 40);
    lv_obj_add_flag(ui->scrPrintMenu_imgInternet, LV_OBJ_FLAG_EVENT_BUBBLE);

    //Write style for scrPrintMenu_imgInternet, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrPrintMenu_imgInternet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrPrintMenu_imgInternet, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrPrintMenu_imgInternet, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrPrintMenu_imgInternet, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrPrintMenu_btndown
    ui->scrPrintMenu_btndown = lv_obj_create(ui->scrPrintMenu_contMain);
    lv_obj_set_pos(ui->scrPrintMenu_btndown, 165, 135);
    lv_obj_set_size(ui->scrPrintMenu_btndown, 75, 100);
    lv_obj_set_scrollbar_mode(ui->scrPrintMenu_btndown, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrPrintMenu_btndown, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrPrintMenu_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrPrintMenu_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrPrintMenu_btndown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrPrintMenu_btndown, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrPrintMenu_btndown, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrPrintMenu_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrPrintMenu_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrPrintMenu_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrPrintMenu_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->scrPrintMenu_btndown, &_btn_bg_3_75x100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->scrPrintMenu_btndown, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->scrPrintMenu_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrPrintMenu_btndown, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrPrintMenu_imgMobile
    ui->scrPrintMenu_imgMobile = lv_img_create(ui->scrPrintMenu_btndown);
    lv_obj_add_flag(ui->scrPrintMenu_imgMobile, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrPrintMenu_imgMobile, &_down_alpha_40x40);
    lv_img_set_pivot(ui->scrPrintMenu_imgMobile, 50,50);
    lv_img_set_angle(ui->scrPrintMenu_imgMobile, 0);
    lv_obj_set_pos(ui->scrPrintMenu_imgMobile, 19, 23);
    lv_obj_set_size(ui->scrPrintMenu_imgMobile, 40, 40);
    lv_obj_add_flag(ui->scrPrintMenu_imgMobile, LV_OBJ_FLAG_EVENT_BUBBLE);

    //Write style for scrPrintMenu_imgMobile, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrPrintMenu_imgMobile, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrPrintMenu_imgMobile, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrPrintMenu_imgMobile, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrPrintMenu_imgMobile, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrPrintMenu_btnup
    ui->scrPrintMenu_btnup = lv_obj_create(ui->scrPrintMenu_contMain);
    lv_obj_set_pos(ui->scrPrintMenu_btnup, 165, 30);
    lv_obj_set_size(ui->scrPrintMenu_btnup, 75, 100);
    lv_obj_set_scrollbar_mode(ui->scrPrintMenu_btnup, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrPrintMenu_btnup, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrPrintMenu_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrPrintMenu_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrPrintMenu_btnup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrPrintMenu_btnup, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrPrintMenu_btnup, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrPrintMenu_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrPrintMenu_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrPrintMenu_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrPrintMenu_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->scrPrintMenu_btnup, &_btn_bg_2_75x100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->scrPrintMenu_btnup, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->scrPrintMenu_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrPrintMenu_btnup, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrPrintMenu_imgUSB
    ui->scrPrintMenu_imgUSB = lv_img_create(ui->scrPrintMenu_btnup);
    lv_obj_add_flag(ui->scrPrintMenu_imgUSB, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrPrintMenu_imgUSB, &_up2_alpha_40x40);
    lv_img_set_pivot(ui->scrPrintMenu_imgUSB, 50,50);
    lv_img_set_angle(ui->scrPrintMenu_imgUSB, 0);
    lv_obj_set_pos(ui->scrPrintMenu_imgUSB, 19, 28);
    lv_obj_set_size(ui->scrPrintMenu_imgUSB, 40, 40);
    lv_obj_add_flag(ui->scrPrintMenu_imgUSB, LV_OBJ_FLAG_EVENT_BUBBLE);

    //Write style for scrPrintMenu_imgUSB, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrPrintMenu_imgUSB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrPrintMenu_imgUSB, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrPrintMenu_imgUSB, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrPrintMenu_imgUSB, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrPrintMenu_btnright
    ui->scrPrintMenu_btnright = lv_obj_create(ui->scrPrintMenu_contMain);
    lv_obj_set_pos(ui->scrPrintMenu_btnright, 70, 100);
    lv_obj_set_size(ui->scrPrintMenu_btnright, 100, 70);
    lv_obj_set_scrollbar_mode(ui->scrPrintMenu_btnright, LV_SCROLLBAR_MODE_OFF);

    //Write style for scrPrintMenu_btnright, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->scrPrintMenu_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrPrintMenu_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->scrPrintMenu_btnright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->scrPrintMenu_btnright, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->scrPrintMenu_btnright, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->scrPrintMenu_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->scrPrintMenu_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->scrPrintMenu_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->scrPrintMenu_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->scrPrintMenu_btnright, &_btn_bg_1_100x70, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->scrPrintMenu_btnright, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->scrPrintMenu_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->scrPrintMenu_btnright, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes scrPrintMenu_img_1
    ui->scrPrintMenu_img_1 = lv_img_create(ui->scrPrintMenu_btnright);
    lv_obj_add_flag(ui->scrPrintMenu_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->scrPrintMenu_img_1, &_left_alpha_40x40);
    lv_img_set_pivot(ui->scrPrintMenu_img_1, 50,50);
    lv_img_set_angle(ui->scrPrintMenu_img_1, 0);
    lv_obj_set_pos(ui->scrPrintMenu_img_1, 28, 15);
    lv_obj_set_size(ui->scrPrintMenu_img_1, 40, 40);
    lv_obj_add_flag(ui->scrPrintMenu_img_1, LV_OBJ_FLAG_EVENT_BUBBLE);

    //Write style for scrPrintMenu_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->scrPrintMenu_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->scrPrintMenu_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->scrPrintMenu_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->scrPrintMenu_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of scrPrintMenu.


    //Update current screen layout.
    lv_obj_update_layout(ui->scrPrintMenu);

    //Init events for screen.
    events_init_scrPrintMenu(ui);
}
