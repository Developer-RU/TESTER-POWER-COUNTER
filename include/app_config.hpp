#ifndef APP_CONFIG
#define APP_CONFIG


//--------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------ Общие настройки приложения ----------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------//

#define FIRMWARE_NAME               "TESTER-POWER-COUNTER"                               // Название прошивки 

#define HOST_NAME                   FIRMWARE_NAME
#define APP_NAME                    "POWER-COUNTER"
#define MANUFACTURE                 "MSVM.RU"
#define MODEL                       APP_NAME

#define VERSION_FIRMWARE            "1.0.0"

//--------------------------------------------------------------------------------------------------------------------------//
//---------------------------------------- Настройка интерфейсов связи -----------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------//

#define UART                        Serial
#define UART_BAUNDRATE              115200

#define RS485                       Serial2
#define RS485_BAUNDRATE             9600
#define RS485_RX                    34
#define RS485_TX                    4
#define RS485_RXTX                  17

#define RS485_WRITE                 1
#define RS485_READ                  0



#endif