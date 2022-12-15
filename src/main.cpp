#include "main.hpp"


long Previous = 0; 
int val = 0;


byte cmd1[] = {0xaF,0x3F,0x21,0x8D,0x0A};                                           // открываем сессию
byte cmd2[] = {0x06,0x30,0x35,0xb1,0x8d,0x0a};                                      // читаем тип счетчика
byte cmd3[] = {0x81,0xd2,0xb1,0x82,0xc5,0xd4,0x30,0x50,0xc5,0x28,0xa9,0x03,0xb7};   // снимаем показания
byte cmd4[] = {0x81,0xd2,0xb1,0x82,0x56,0xcf,0xcc,0xd4,0x41,0x28,0xa9,0x03,0x5f};   // напряжения на фазах


/**
 * @brief 
 * 
 */
void setup()
{
    UART.begin(115200);

    pinMode(RS485_RXTX, OUTPUT);
    digitalWrite(RS485_RXTX, RS485_WRITE);

    RS485.begin(RS485_BAUNDRATE, SERIAL_7E1, RS485_RX, RS485_TX);
    RS485.flush();

    digitalWrite(RS485_RXTX, RS485_READ);
}

/**
 * @brief 
 * 
 */
void loop()
{ 
    if (RS485.available())
    {
        char response = RS485.read();
        // response &= 0x7F;// convert 8N1 to 7E1
        UART.print(response);
    }
    
    if (millis() - Previous >= 1000)
    {
        Previous = millis();        
        val ++;

        switch (val)
        {
            case 1:
                digitalWrite(RS485_RXTX, HIGH);
                RS485.write (cmd1,5);
                digitalWrite(RS485_RXTX, LOW);
                
                break;

            case 2:
                digitalWrite(RS485_RXTX, HIGH);
                RS485.write (cmd2,6);
                digitalWrite(RS485_RXTX, LOW);
                
                break;

            case 3:
                digitalWrite(RS485_RXTX, HIGH);
                RS485.write (cmd3,13);
                digitalWrite(RS485_RXTX, LOW);
                
                break;

            case 4:
                digitalWrite(RS485_RXTX, HIGH);
                RS485.write (cmd4,13);
                digitalWrite(RS485_RXTX, LOW);
                
                break;

            default:

                val = 0;

                break;
        }
    }
}
   