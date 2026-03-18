/*
* Copyright 2026 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include "custom.h"

static void scrHome_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.scrHome_contBG, 100, 0, lv_obj_get_width(guider_ui.scrHome_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrHome_contBG, 100, 0, lv_obj_get_height(guider_ui.scrHome_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);

        break;
    }
    default:
        break;
    }
}

static void scrHome_contSetup_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrSetup, guider_ui.scrSetup_del, &guider_ui.scrHome_del, setup_scr_scrSetup, LV_SCR_LOAD_ANIM_FADE_ON, 100, 200, false, true);
        lv_obj_set_style_bg_color(guider_ui.scrHome_contBG, lv_color_hex(0xe12e2e), LV_PART_MAIN);
        ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_width(guider_ui.scrHome_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_height(guider_ui.scrHome_contBG), 272, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrHome_contPrint_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrPrintMenu, guider_ui.scrPrintMenu_del, &guider_ui.scrHome_del, setup_scr_scrPrintMenu, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_width(guider_ui.scrHome_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_height(guider_ui.scrHome_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrHome_contCopy_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrCopy, guider_ui.scrCopy_del, &guider_ui.scrHome_del, setup_scr_scrCopy, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_width(guider_ui.scrHome_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_height(guider_ui.scrHome_contBG), 60, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrHome_contScan_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrScan, guider_ui.scrScan_del, &guider_ui.scrHome_del, setup_scr_scrScan, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_width(guider_ui.scrHome_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrHome_contBG, 200, 0, lv_obj_get_height(guider_ui.scrHome_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

void events_init_scrHome (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrHome, scrHome_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrHome_contSetup, scrHome_contSetup_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrHome_contPrint, scrHome_contPrint_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrHome_contCopy, scrHome_contCopy_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrHome_contScan, scrHome_contScan_event_handler, LV_EVENT_ALL, ui);
}

static void scrCopy_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.scrCopy_contBG, 100, 0, lv_obj_get_width(guider_ui.scrCopy_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrCopy_contBG, 100, 0, lv_obj_get_height(guider_ui.scrCopy_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrCopy_btnNext_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrCopy2, guider_ui.scrCopy2_del, &guider_ui.scrCopy_del, setup_scr_scrCopy2, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        ui_animation(guider_ui.scrCopy_contBG, 100, 0, lv_obj_get_width(guider_ui.scrCopy_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrCopy_contBG, 100, 0, lv_obj_get_height(guider_ui.scrCopy_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrCopy_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrCopy_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        ui_animation(guider_ui.scrCopy_contBG, 100, 0, lv_obj_get_width(guider_ui.scrCopy_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrCopy_contBG, 100, 0, lv_obj_get_height(guider_ui.scrCopy_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

void events_init_scrCopy (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrCopy, scrCopy_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrCopy_btnNext, scrCopy_btnNext_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrCopy_btnBack, scrCopy_btnBack_event_handler, LV_EVENT_ALL, ui);
}

static void scrCopy2_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.scrCopy2_contBG, 100, 0, lv_obj_get_width(guider_ui.scrCopy2_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrCopy2_contBG, 100, 0, lv_obj_get_height(guider_ui.scrCopy2_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrCopy2_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrCopy2_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        ui_animation(guider_ui.scrCopy2_contBG, 100, 0, lv_obj_get_width(guider_ui.scrCopy2_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrCopy2_contBG, 100, 0, lv_obj_get_height(guider_ui.scrCopy2_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

void events_init_scrCopy2 (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrCopy2, scrCopy2_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrCopy2_btnBack, scrCopy2_btnBack_event_handler, LV_EVENT_ALL, ui);
}

static void scrScan_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.scrScan_contBG, 100, 0, lv_obj_get_width(guider_ui.scrScan_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrScan_contBG, 100, 0, lv_obj_get_height(guider_ui.scrScan_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrScan_sliderBright_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        slider_adjust_img_cb(guider_ui.scrScan_imgScanned, lv_slider_get_value(guider_ui.scrScan_sliderBright), lv_slider_get_value(guider_ui.scrScan_sliderHue));
        break;
    }
    default:
        break;
    }
}

static void scrScan_sliderHue_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        slider_adjust_img_cb(guider_ui.scrScan_imgScanned, lv_slider_get_value(guider_ui.scrScan_sliderBright), lv_slider_get_value(guider_ui.scrScan_sliderHue));
        break;
    }
    default:
        break;
    }
}

static void scrScan_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrScan_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_NONE, 400, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_scrScan (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrScan, scrScan_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrScan_sliderBright, scrScan_sliderBright_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrScan_sliderHue, scrScan_sliderHue_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrScan_btnBack, scrScan_btnBack_event_handler, LV_EVENT_ALL, ui);
}

static void scrPrintMenu_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.scrPrintMenu_contBG, 100, 0, lv_obj_get_width(guider_ui.scrPrintMenu_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrPrintMenu_contBG, 100, 0, lv_obj_get_height(guider_ui.scrPrintMenu_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrPrintMenu_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrPrintMenu_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        ui_animation(guider_ui.scrPrintMenu_contBG, 100, 0, lv_obj_get_width(guider_ui.scrPrintMenu_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrPrintMenu_contBG, 100, 0, lv_obj_get_height(guider_ui.scrPrintMenu_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrPrintMenu_btnleft_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void scrPrintMenu_btndown_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void scrPrintMenu_btnup_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

static void scrPrintMenu_btnright_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {

        break;
    }
    default:
        break;
    }
}

void events_init_scrPrintMenu (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrPrintMenu, scrPrintMenu_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrPrintMenu_btnBack, scrPrintMenu_btnBack_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrPrintMenu_btnleft, scrPrintMenu_btnleft_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrPrintMenu_btndown, scrPrintMenu_btndown_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrPrintMenu_btnup, scrPrintMenu_btnup_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrPrintMenu_btnright, scrPrintMenu_btnright_event_handler, LV_EVENT_ALL, ui);
}

static void scrSetup_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrSetup_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 100, 200, false, true);
        lv_obj_set_style_bg_color(guider_ui.scrSetup_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN);
        ui_animation(guider_ui.scrSetup_contBG, 200, 0, lv_obj_get_width(guider_ui.scrSetup_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrSetup_contBG, 200, 0, lv_obj_get_height(guider_ui.scrSetup_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

void events_init_scrSetup (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrSetup_btnBack, scrSetup_btnBack_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
