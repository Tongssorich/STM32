#ifndef __FAN_H
#define __FAN_H

#include "sys.h"

#define FANAIN1 PCout(6)
#define FANAIN2 PCout(7)
 
#define FANBIN1 PCout(8)
#define FANBIN2 PCout(9)

void Fan_Init(void);
void Fan_start(void);
void Fan_shut(void);

#endif
