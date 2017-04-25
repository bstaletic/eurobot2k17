#ifndef REVOLVER_EXECUTOR
#define REVOLVER_EXECUTOR

#include <stdint.h>

#include "../drivers/actuators/ax12/ax12.h"

#define AX12_NEXT_POSITION_INC 60
#define REVOLVER_AX12_ID 1

int16_t revolver_position = 0;

/**
 * \fn void init(void)
 * \brief Set the executor in initial state
 */
void revolver_init(void);

/**
 * \fn void go_to_position(uint8_t)
 * \brief Go to specified tube
 *
 * @param tube_number [in] the number of the tube
 *
 * Rotates the revolver until it reaches the desired tube
 *
 * Number of tubes - 8
 */
void revolver_go_to_position(uint16_t tube_number);

/**
 * \fn void next(void)
 * \brief Rotate to the next tube
 */
void revolver_next(void);

/**
 * \fn void previous(void)
 * \brief Rotate to the previous tube
 */
void revolver_previous(void);

#endif /* ifndef REVOLVER_EXECUTOR */
