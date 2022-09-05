#include <mcp_can.h>
#include <SPI.h>

#define CANO_INT 28
MCP_CAN CAN0(17);

long unsigned int rxId;
unsigned char len = 0;
unsigned char can_data[8];
byte py_can_data[8];

void setup()
{
    Serial.begin(115200);

    if (CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK)
        Serial.println("MCP2515 Initialized Successfully!");
    else
        Serial.println("Error Initializing MCP2515...");

    CAN0.setMode(MCP_NORMAL);
}

void loop()
{
    if (!digitalRead(CANO_INT))
    {
        CAN0.readMsgBuf(&rxId, &len, can_data);
        for (byte i = 0; i < len; i++)
        {
            Serial.write(can_data[i]);
        }
    }
    if (Serial.available() > 0)
    {
        Serial.readBytesUntil('\n', py_can_data, 8);
        byte sndStat = CAN0.sendMsgBuf(0x100, 0, 8, py_can_data);
    }
}
