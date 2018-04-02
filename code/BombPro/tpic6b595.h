#define  SER_OUT 52
#define  SRCK 53
#define  RCK  51

unsigned char ledValues[2];  // number of shift registers
// tpic0 is red
// tpic1 is blue
#define  RED_LED0_ON  ledValues[0] = ledValues[0] | 0x01; TPIC6B959N_write();
#define  RED_LED0_OFF  ledValues[0] = ledValues[0] & 0xfe; TPIC6B959N_write();
#define  RED_LED1_ON  ledValues[0] = ledValues[0] | 0x02; TPIC6B959N_write();
#define  RED_LED1_OFF  ledValues[0] = ledValues[0] & 0xfd; TPIC6B959N_write();
#define  RED_LED2_ON  ledValues[0] = ledValues[0] | 0x04; TPIC6B959N_write();
#define  RED_LED2_OFF  ledValues[0] = ledValues[0] & 0xfb; TPIC6B959N_write();
#define  RED_LED3_ON  ledValues[0] = ledValues[0] | 0x08; TPIC6B959N_write();
#define  RED_LED3_OFF  ledValues[0] = ledValues[0] & 0xf7; TPIC6B959N_write();
#define  RED_LED4_ON  ledValues[0] = ledValues[0] | 0x10; TPIC6B959N_write();
#define  RED_LED4_OFF  ledValues[0] = ledValues[0] & 0xef; TPIC6B959N_write();
#define  RED_LED5_ON  ledValues[0] = ledValues[0] | 0x20; TPIC6B959N_write();
#define  RED_LED5_OFF  ledValues[0] = ledValues[0] & 0xdf; TPIC6B959N_write();
#define  RED_LED6_ON  ledValues[0] = ledValues[0] | 0x40; TPIC6B959N_write();
#define  RED_LED6_OFF  ledValues[0] = ledValues[0] & 0xbf; TPIC6B959N_write();
#define  RED_LED7_ON  ledValues[0] = ledValues[0] | 0x80; TPIC6B959N_write();
#define  RED_LED7_OFF  ledValues[0] = ledValues[0] & 0x7f; TPIC6B959N_write();
#define  BLUE_LED0_ON  ledValues[1] = ledValues[1] | 0x01; TPIC6B959N_write();
#define  BLUE_LED0_OFF  ledValues[1] = ledValues[1] & 0xfe; TPIC6B959N_write();
#define  BLUE_LED1_ON  ledValues[1] = ledValues[1] | 0x02; TPIC6B959N_write();
#define  BLUE_LED1_OFF  ledValues[1] = ledValues[1] & 0xfd; TPIC6B959N_write();
#define  BLUE_LED2_ON  ledValues[1] = ledValues[1] | 0x04; TPIC6B959N_write();
#define  BLUE_LED2_OFF  ledValues[1] = ledValues[1] & 0xfb; TPIC6B959N_write();
#define  BLUE_LED3_ON  ledValues[1] = ledValues[1] | 0x08; TPIC6B959N_write();
#define  BLUE_LED3_OFF  ledValues[1] = ledValues[1] & 0xf7; TPIC6B959N_write();
#define  BLUE_LED4_ON  ledValues[1] = ledValues[1] | 0x10; TPIC6B959N_write();
#define  BLUE_LED4_OFF  ledValues[1] = ledValues[1] & 0xef; TPIC6B959N_write();
#define  BLUE_LED5_ON  ledValues[1] = ledValues[1] | 0x20; TPIC6B959N_write();
#define  BLUE_LED5_OFF  ledValues[1] = ledValues[1] & 0xdf; TPIC6B959N_write();
#define  BLUE_LED6_ON  ledValues[1] = ledValues[1] | 0x40; TPIC6B959N_write();
#define  BLUE_LED6_OFF  ledValues[1] = ledValues[1] & 0xbf; TPIC6B959N_write();
#define  BLUE_LED7_ON  ledValues[1] = ledValues[1] | 0x80; TPIC6B959N_write();
#define  BLUE_LED7_OFF  ledValues[1] = ledValues[1] & 0x7f; TPIC6B959N_write();
#define  LED_OFF RED_LED0_OFF; RED_LED1_OFF; RED_LED2_OFF; RED_LED3_OFF; RED_LED4_OFF; RED_LED5_OFF; RED_LED6_OFF; RED_LED7_OFF; BLUE_LED0_OFF; BLUE_LED1_OFF; BLUE_LED2_OFF; BLUE_LED3_OFF; BLUE_LED4_OFF; BLUE_LED5_OFF; BLUE_LED6_OFF; BLUE_LED7_OFF;
#define  RED_LED_OFF RED_LED0_OFF; RED_LED1_OFF; RED_LED2_OFF; RED_LED3_OFF; RED_LED4_OFF; RED_LED5_OFF; RED_LED6_OFF; RED_LED7_OFF;
#define  BLUE_LED_OFF BLUE_LED0_OFF; BLUE_LED1_OFF; BLUE_LED2_OFF; BLUE_LED3_OFF; BLUE_LED4_OFF; BLUE_LED5_OFF; BLUE_LED6_OFF; BLUE_LED7_OFF;
