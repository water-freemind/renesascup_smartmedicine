#include "uart_app.h"
#include <stdint.h>
#include <string.h>
volatile uint16_t medata[data_length]={0};
volatile uint8_t is_receving=2;
void receve_data_from_uart(uint32_t data){
    static uint8_t datas[(data_length+1)*2]={0};
    static uint8_t status=0;
    static uint8_t index=0;
    switch (status) {
        case 0://等待帧头
            if(data==0x2c){
                status=1;
            }
            break;
        case 1://接收数据
            is_receving=1;
            if(data!=0x3c){
                datas[index++]=(uint8_t)data;
            }else{
                //收到帧尾，校验数据
                uint16_t act_data_len = ((uint16_t)datas[((data_length+1)*2)-1-1]) | (((uint16_t)datas[((data_length+1)*2)-1])<<8);
                if(act_data_len==data_length+1){
                    //校验成功
                    for(uint8_t i = data_length-1;i>0;i--){
                        medata[i]=((uint16_t)datas[2*i]) | (((uint16_t)datas[(2*i)+1])<<8);
                    }
                    medata[0]=((uint16_t)datas[0]) | (((uint16_t)datas[1])<<8);
                    is_receving=0;//接收成功，此时数据可用
                }else{
                    is_receving=2;//校验失败，此时数据不可用
                }
                status=0;
                index=0;
            }
            break;
        default:
            break;
    }
    
    
}