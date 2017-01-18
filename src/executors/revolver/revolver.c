#include <executors/revolver/revolver.h>

int8_t revolver_init(void)
{
	return ax12_move(REVOLVER_AX12_ID, revolver_position);
}

int8_t revolver_go_to_position(uint16_t tube_number)
{
	return ax12_move(REVOLVER_AX12_ID, revolver_position = tube_number*60);
}

int8_t revolver_next(void)
{
	return ax12_move(REVOLVER_AX12_ID, revolver_position += 60);
}

int8_t revolver_previous(void)
{
	return ax12_move(REVOLVER_AX12_ID, revolver_position -= 60);
}
