//can_defines.h
#include "types.h"                    //TD1 CAN1_TX pin no alternate function,default
#define TD1_PIN                       //define p0.25 as RD1(i.e CAN1_RX)
#define PIN_FUNC2      1              // Alternate Function 2 selection
#define RD1_PIN_0_25   PIN_FUNC2       // Configure P0.25 as CAN1_RX (RD1)

#define PCLK          15000000      // Peripheral Clock Frequency (15 MHz)
#define BIT_RATE      125000        // Required CAN Bus Baud Rate 
#define QUANTA        15              // Total Time Quanta (TQ) per CAN bit
#define BRP           (PCLK/(BIT_RATE*QUANTA))       // Baud Rate Prescaler
                                                   // BRP = PCLK / (Bit Rate × Number of Time Quanta)
#define SAMPLE_POINT  (0.7 * QUANTA)               // Sample Point = 70% of one bit time
#define TSEG1        	((u32)SAMPLE_POINT-1)      // Time Segment 1   
#define TSEG2        	(QUANTA-(1+TSEG1))	        // Time Segment 2
#define SJW           ((TSEG2>=5)?4:(TSEG2-1))      // Synchronization Jump Width (SJW)
                                                   // Maximum allowed value is 4


#define SAM         0                      //0/1,sample bus 1/3 time(s)
#define BTR_LVAL 	(SAM<<23| \
                  ((TSEG2-1)<<20)| \
                  ((TSEG1-1)<<16)| \
                  ((SJW-1)<<14)|   \
									(BRP-1))   //cfg values for CxBTR sfr

//CxCMR sfr bit defines
#define TR_BIT   0      // Transmission Request
#define RRB_BIT  2        // Release Receive Buffer
#define STB1_BIT 5        // Select Transmit Buffer 1

//CxGSR sfr bit defines
#define RBS_BIT  0        // Receive Buffer Status
#define TBS1_BIT 2         // Transmit Buffer 1 Status
#define TCS1_BIT 3          // Transmission Complete Status

//CxTFI1/CxRFS sfr bit defines
#define FF_BIT   31            // Frame Format, 0 = Standard Frame, 1 = Extended Frame
#define RTR_BIT  30           // Remote Transmission Request, 0 = Data Frame, 1 = Remote Frame
#define DLC_BITS 16          // Data Length Code (0–8 bytes)

//CxMOD sfr bit defines
#define RM_BIT   0            // Reset Mode bit
                              // 1 = Reset Mode
                              // 0 = Operating Mode

//AFMR sfr bit defines
#define AccOFF_BIT 0         // Disable Acceptance Filter
#define AccBP_BIT  1          // All CAN messages are accepted
