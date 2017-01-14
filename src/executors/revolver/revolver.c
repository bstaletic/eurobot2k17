#include <executors/revolver/revolver.h>

int8_t init(void)
{
	return move(REVOLVER_AX12_ID, revolver_position);
}

int8_t go_to_position(uint16_t tube_number)
{
	return move(REVOLVER_AX12_ID, revolver_position = tube_number*60);
}

int8_t next(void)
{
	return move(REVOLVER_AX12_ID, revolver_position += 60);
}

int8_t previous(void)
{
	return move(REVOLVER_AX12_ID, revolver_position -= 60);
}
