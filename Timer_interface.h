/*
 * Timer_interface.h
 *
 *  Created on: Sep 14, 2019
 *      Author: Mariam
 */

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void vidTimerInt(void);
void Timer_vidInitctcMode(u8 copy_u8ctcValue);
void Timer_vidIntFastPWMmode(void);
void Timer_vidIntTimer1ctcMode(u16 copy_u8ctcValue);
void vidSetTimer1Value (u16 u16CopyTimer1_OCR);

#endif /* TIMER_INTERFACE_H_ */
