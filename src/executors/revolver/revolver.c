#include "revolver.h"

void revolver_init(void)
{
	ax12_move(REVOLVER_AX12_ID, revolver_position);
}

void revolver_go_to_position(uint16_t tube_number)
{
	ax12_move(REVOLVER_AX12_ID,
                     revolver_position = tube_number * AX12_NEXT_POSITION_INC);
}

void revolver_next(void)
{
	ax12_move(REVOLVER_AX12_ID, revolver_position += AX12_NEXT_POSITION_INC);
}

void revolver_previous(void)
{
	ax12_move(REVOLVER_AX12_ID, revolver_position -= AX12_NEXT_POSITION_INC);
}
