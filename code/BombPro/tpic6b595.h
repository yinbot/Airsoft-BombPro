#define  SER_OUT 52
#define  SRCK 53
#define  RCK  51

unsigned char ledValues[2];  // number of shift registers

#define  LED0_ON  ledValues[0] = ledValues[0] | 0x01; TPIC6B959N_write();
#define  LED0_OFF  ledValues[0] = ledValues[0] & 0xfe; TPIC6B959N_write();
#define  LED1_ON  ledValues[0] = ledValues[0] | 0x02; TPIC6B959N_write();
#define  LED1_OFF  ledValues[0] = ledValues[0] & 0xfd; TPIC6B959N_write();
#define  LED2_ON  ledValues[0] = ledValues[0] | 0x04; TPIC6B959N_write();
#define  LED2_OFF  ledValues[0] = ledValues[0] & 0xfb; TPIC6B959N_write();
#define  LED3_ON  ledValues[0] = ledValues[0] | 0x08; TPIC6B959N_write();
#define  LED3_OFF  ledValues[0] = ledValues[0] & 0xf7; TPIC6B959N_write();
#define  LED4_ON  ledValues[0] = ledValues[0] | 0x10; TPIC6B959N_write();
#define  LED4_OFF  ledValues[0] = ledValues[0] & 0xef; TPIC6B959N_write();
#define  LED5_ON  ledValues[0] = ledValues[0] | 0x20; TPIC6B959N_write();
#define  LED5_OFF  ledValues[0] = ledValues[0] & 0xdf; TPIC6B959N_write();
#define  LED6_ON  ledValues[0] = ledValues[0] | 0x40; TPIC6B959N_write();
#define  LED6_OFF  ledValues[0] = ledValues[0] & 0xbf; TPIC6B959N_write();
#define  LED7_ON  ledValues[0] = ledValues[0] | 0x80; TPIC6B959N_write();
#define  LED7_OFF  ledValues[0] = ledValues[0] & 0x7f; TPIC6B959N_write();
#define  LED8_ON  ledValues[1] = ledValues[1] | 0x01; TPIC6B959N_write();
#define  LED8_OFF  ledValues[1] = ledValues[1] & 0xfe; TPIC6B959N_write();
#define  LED9_ON  ledValues[1] = ledValues[1] | 0x02; TPIC6B959N_write();
#define  LED9_OFF  ledValues[1] = ledValues[1] & 0xfd; TPIC6B959N_write();
#define  LED10_ON  ledValues[1] = ledValues[1] | 0x04; TPIC6B959N_write();
#define  LED10_OFF  ledValues[1] = ledValues[1] & 0xfb; TPIC6B959N_write();
#define  LED11_ON  ledValues[1] = ledValues[1] | 0x08; TPIC6B959N_write();
#define  LED11_OFF  ledValues[1] = ledValues[1] & 0xf7; TPIC6B959N_write();
#define  LED12_ON  ledValues[1] = ledValues[1] | 0x10; TPIC6B959N_write();
#define  LED12_OFF  ledValues[1] = ledValues[1] & 0xef; TPIC6B959N_write();
#define  LED13_ON  ledValues[1] = ledValues[1] | 0x20; TPIC6B959N_write();
#define  LED13_OFF  ledValues[1] = ledValues[1] & 0xdf; TPIC6B959N_write();
#define  LED14_ON  ledValues[1] = ledValues[1] | 0x40; TPIC6B959N_write();
#define  LED14_OFF  ledValues[1] = ledValues[1] & 0xbf; TPIC6B959N_write();
#define  LED15_ON  ledValues[1] = ledValues[1] | 0x80; TPIC6B959N_write();
#define  LED15_OFF  ledValues[1] = ledValues[1] & 0x7f; TPIC6B959N_write();
#define  LED_OFF LED0_OFF; LED1_OFF; LED2_OFF; LED3_OFF; LED4_OFF; LED5_OFF; LED6_OFF; LED7_OFF; LED8_OFF; LED9_OFF; LED10_OFF; LED11_OFF; LED12_OFF; LED13_OFF; LED14_OFF; LED15_OFF; 
