#ifndef REVOLVER_EXECUTOR
#define REVOLVER_EXECUTOR

#include <stdint.h>

#include "../drivers/actuators/ax12/ax12.h"

#define AX12_NEXT_POSITION_INC 200
#define REVOLVER_AX12_ID 3

extern int16_t revolver_position;
int16_t position;

/**
 * \fn int8_t init(void)
 * \brief Set the executor in initial state
 */
int8_t revolver_init(void);

/**
 * \fn int8_t go_to_position(uint8_t)
 * \brief Go to specified tube
 *
 * @param tube_number [in] the number of the tube
 *
 * Rotates the revolver until it reaches the desired tube
 *
 * Number of tubes - 8
 */
int8_t revolver_go_to_position(uint16_t tube_number);

/**
 * \fn int8_t next(void)
 * \brief Rotate to the next tube
 */
int8_t revolver_next(void);

/**
 * \fn int8_t previous(void)
 * \brief Rotate to the previous tube
 */
int8_t revolver_previous(void);

#endif /* ifndef REVOLVER_EXECUTOR */
