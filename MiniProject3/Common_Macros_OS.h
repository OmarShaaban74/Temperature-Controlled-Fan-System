/*
 * Common_Macros_OS.h
 *
 *  Created on: Sep 29, 2023
 *      Author: omars
 */


#ifndef COMMON_MACROS_OS_H_
#define COMMON_MACROS_OS_H_

#define SET_BIT(REG,BIT) REG|=(1<<BIT)
#define CLEAR_BIT(REG,BIT) REG&=~(1<<BIT)
#define GET_BIT(REG,BIT) ((REG&(1<<BIT))>>BIT) /*check if get_bit==1 or get_bit==0 equivalent to bit is set and bit is clear*/
#define TOGGLE_BIT(REG,BIT) REG^=(1<<BIT)
#define ROR(REG,BIT) (REG = ((REG>>BIT) | (REG<<(8-BIT))))
#define ROL(REG,BIT) (REG = ((REG<<BIT) | (REG>>(8-BIT))))

#endif /* COMMON_MACROS_OS_H_ */
