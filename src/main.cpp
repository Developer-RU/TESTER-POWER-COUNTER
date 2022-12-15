#include <Arduino.h>


#define UART                        Serial
#define UART_BAUNDRATE              115200

#define RS485                       Serial2
#define RS485_BAUNDRATE             9600
#define RS485_RX                    34
#define RS485_TX                    4
#define RS485_RXTX                  17

#define RS485_WRITE                 1
#define RS485_READ                  0


long Previous = 0; 

int val = 0;

int Time_1 = 1;         
int Time_2 = 2;          
int Time_3 = 3;
int Time_4 = 4;
int Time_5 = 15; 


// открываем сессию
byte cmd1[] = {0xaF,0x3F,0x21,0x8D,0x0A};

// читаем тип счетчика
byte cmd2[] = {0x06,0x30,0x35,0xb1,0x8d,0x0a};

// снимаем показания
byte cmd3[] = {0x81,0xd2,0xb1,0x82,0xc5,0xd4,0x30,0x50,0xc5,0x28,0xa9,0x03,0xb7};

// напряжения на фазах
byte cmd4[] = {0x81,0xd2,0xb1,0x82,0x56,0xcf,0xcc,0xd4,0x41,0x28,0xa9,0x03,0x5f};


void setup()
{
    UART.begin(115200);


    pinMode(RS485_RXTX, OUTPUT);
    digitalWrite(RS485_RXTX, RS485_WRITE);

    RS485.begin(RS485_BAUNDRATE, SERIAL_8N1, RS485_RX, RS485_TX);
    RS485.flush();

    digitalWrite(RS485_RXTX, RS485_READ);


}
void loop()
{ 
    if (RS485.available())
    {
        char response = RS485.read();
        response &= 0x7F;// convert 8N1 to 7E1

        UART.print(response);
    }
    
    if (millis() - Previous > 1000)
    {
        Previous = millis();        
        val ++;
              
        if (val == Time_1)
        {
            digitalWrite(RS485_RXTX, HIGH);
            RS485.write (cmd1,5);
            digitalWrite(RS485_RXTX, LOW);
        }

        if (val == Time_2)
        {
            digitalWrite(RS485_RXTX, HIGH);
            RS485.write (cmd2,6);
            digitalWrite(RS485_RXTX, LOW); 
        }
        
        if (val == Time_3)
        {
            digitalWrite(RS485_RXTX, HIGH);
            RS485.write (cmd3,13);
            digitalWrite(RS485_RXTX, LOW);
        }

        if (val == Time_4)
        {
            digitalWrite(RS485_RXTX, HIGH);
            RS485.write (cmd4,13);
            digitalWrite(RS485_RXTX, LOW);
        }
        
        if (val == Time_5)
        {
            val = 0;            
        }
    }
}
   