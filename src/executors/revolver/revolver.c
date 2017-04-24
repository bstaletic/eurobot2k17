#include "revolver.h"

int16_t revolver_position  = 1023;

int8_t revolver_init(void)
{
	return ax12_move(REVOLVER_AX12_ID, revolver_position);
}

int8_t revolver_go_to_position(uint16_t position)
{
	return ax12_move(REVOLVER_AX12_ID, position);
}

int8_t revolver_next(void)
{
	return ax12_move(REVOLVER_AX12_ID,
                     revolver_position += AX12_NEXT_POSITION_INC);
}

int8_t revolver_previous(void)
{
	return ax12_move(REVOLVER_AX12_ID,
                     revolver_position -= AX12_NEXT_POSITION_INC);
}
