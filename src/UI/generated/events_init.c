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
#include "events_init.h"
#include "ZDT_app.h"

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
        ui_load_scr_animation(&guider_ui, &guider_ui.scrSetting, guider_ui.scrSetting_del, &guider_ui.scrHome_del, setup_scr_scrSetting, LV_SCR_LOAD_ANIM_FADE_ON, 100, 200, false, true);
        lv_obj_set_style_bg_color(guider_ui.scrHome_contBG, lv_color_hex(0x27d3ff), LV_PART_MAIN);
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
        ui_load_scr_animation(&guider_ui, &guider_ui.scrcontrol, guider_ui.scrcontrol_del, &guider_ui.scrHome_del, setup_scr_scrcontrol, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
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
        ui_load_scr_animation(&guider_ui, &guider_ui.scrsecurity, guider_ui.scrsecurity_del, &guider_ui.scrHome_del, setup_scr_scrsecurity, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
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
        ui_load_scr_animation(&guider_ui, &guider_ui.scrstore, guider_ui.scrstore_del, &guider_ui.scrHome_del, setup_scr_scrstore, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
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

static void scrsecurity_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.scrsecurity_contBG, 100, 0, lv_obj_get_width(guider_ui.scrsecurity_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrsecurity_contBG, 100, 0, lv_obj_get_height(guider_ui.scrsecurity_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrsecurity_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrsecurity_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        ui_animation(guider_ui.scrsecurity_contBG, 100, 0, lv_obj_get_width(guider_ui.scrsecurity_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrsecurity_contBG, 100, 0, lv_obj_get_height(guider_ui.scrsecurity_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrsecurity_btnNext_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrscan, guider_ui.scrscan_del, &guider_ui.scrsecurity_del, setup_scr_scrscan, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        ui_animation(guider_ui.scrsecurity_contBG, 100, 0, lv_obj_get_width(guider_ui.scrsecurity_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrsecurity_contBG, 100, 0, lv_obj_get_height(guider_ui.scrsecurity_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

void events_init_scrsecurity (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrsecurity, scrsecurity_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrsecurity_btnBack, scrsecurity_btnBack_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrsecurity_btnNext, scrsecurity_btnNext_event_handler, LV_EVENT_ALL, ui);
}

static void scrscan_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.scrscan_contBG, 100, 0, lv_obj_get_width(guider_ui.scrscan_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrscan_contBG, 100, 0, lv_obj_get_height(guider_ui.scrscan_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        MotorMsg_t msg;
        msg.cmd = CMD_SCAN;
        if (g_motor_queue != NULL) {
            xQueueSend(g_motor_queue, &msg, 0);
        }

        break;
    }
    default:
        break;
    }
}

static void scrscan_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrscan_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        ui_animation(guider_ui.scrscan_contBG, 100, 0, lv_obj_get_width(guider_ui.scrscan_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrscan_contBG, 100, 0, lv_obj_get_height(guider_ui.scrscan_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

void events_init_scrscan (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrscan, scrscan_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrscan_btnBack, scrscan_btnBack_event_handler, LV_EVENT_ALL, ui);
}

static void scrstore_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        break;
    }
    default:
        break;
    }
}

static void scrstore_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrstore_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void scrstore_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrstore_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_NONE, 400, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_scrstore (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrstore, scrstore_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrstore_btn_1, scrstore_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrstore_btnBack, scrstore_btnBack_event_handler, LV_EVENT_ALL, ui);
}

static void scrcontrol_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        ui_animation(guider_ui.scrcontrol_contBG, 100, 0, lv_obj_get_width(guider_ui.scrcontrol_contBG), 480, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrcontrol_contBG, 100, 0, lv_obj_get_height(guider_ui.scrcontrol_contBG), 100, &lv_anim_path_ease_out, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrcontrol_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrcontrol_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        ui_animation(guider_ui.scrcontrol_contBG, 100, 0, lv_obj_get_width(guider_ui.scrcontrol_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrcontrol_contBG, 100, 0, lv_obj_get_height(guider_ui.scrcontrol_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrcontrol_btnleft_event_handler (lv_event_t *e)
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

static void scrcontrol_btndown_event_handler (lv_event_t *e)
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

static void scrcontrol_btnup_event_handler (lv_event_t *e)
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

static void scrcontrol_btnright_event_handler (lv_event_t *e)
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

void events_init_scrcontrol (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrcontrol, scrcontrol_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrcontrol_btnBack, scrcontrol_btnBack_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrcontrol_btnleft, scrcontrol_btnleft_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrcontrol_btndown, scrcontrol_btndown_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrcontrol_btnup, scrcontrol_btnup_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrcontrol_btnright, scrcontrol_btnright_event_handler, LV_EVENT_ALL, ui);
}

static void scrSetting_btnBack_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.scrHome, guider_ui.scrHome_del, &guider_ui.scrSetting_del, setup_scr_scrHome, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, false, true);
        lv_obj_set_style_bg_color(guider_ui.scrSetting_contBG, lv_color_hex(0x2f3243), LV_PART_MAIN);
        ui_animation(guider_ui.scrSetting_contBG, 200, 0, lv_obj_get_width(guider_ui.scrSetting_contBG), 480, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_width, NULL, NULL, NULL);
        ui_animation(guider_ui.scrSetting_contBG, 200, 0, lv_obj_get_height(guider_ui.scrSetting_contBG), 60, &lv_anim_path_ease_in, 0, 0, 0, 0, (lv_anim_exec_xcb_t)lv_obj_set_height, NULL, NULL, NULL);
        break;
    }
    default:
        break;
    }
}

static void scrSetting_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_PRESSED:
    {

        if (code == LV_EVENT_PRESSED)
        {
            MotorMsg_t msg;
            msg.cmd = CMD_ZERO_ALL;
            if (g_motor_queue != NULL) {
                xQueueSend(g_motor_queue, &msg, 0);
            }
        }
        break;
    }
    default:
        break;
    }
}

void events_init_scrSetting (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->scrSetting_btnBack, scrSetting_btnBack_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->scrSetting_btn_1, scrSetting_btn_1_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
