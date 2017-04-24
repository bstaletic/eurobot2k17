#include "ax12.h"

uint8_t ax12_move(uint8_t id, uint16_t position)
{
	uint8_t out_data[9], checksum;

	// Calculate checksum
	checksum = ~(id + AX12_GOAL_LENGTH + AX12_WRITE_DATA + AX12_GOAL_POSITION_L
			+ (position&0xff) + (position>>8));

	// Construct the data to be sent
	out_data[0] = out_data[1] = AX12_START;
	out_data[2] = id;
	out_data[3] = AX12_GOAL_LENGTH;
	out_data[4] = AX12_WRITE_DATA;
	out_data[5] = AX12_GOAL_POSITION_L;
	out_data[6] = position&0xff;
	out_data[7] = position>>8;
	out_data[8] = checksum;

	// Send data to AX12
	do{
		HAL_UART_Transmit(AX12_UART, out_data, 9, 18);

	}while(ax12_read_response());
}

uint8_t ax12_move_speed(uint8_t id, uint16_t position, uint16_t speed)
{
	uint8_t out_data[11], checksum;

	// Calculate checksum
	checksum = ~(id + AX12_GOAL_SP_LENGTH + AX12_WRITE_DATA + AX12_GOAL_POSITION_L
			+ (position&0xff) + (position>>8)
			+ (speed&0xff) + (speed>>8));

	// Construct the data to be sent
	out_data[0] = out_data[1] = AX12_START;
	out_data[2] = id;
	out_data[3] = AX12_GOAL_SP_LENGTH;
	out_data[4] = AX12_WRITE_DATA;
	out_data[5] = AX12_GOAL_POSITION_L;
	out_data[6] = position&0xff;
	out_data[7] = position>>8;
	out_data[8] = speed*0xff;
	out_data[9] = speed>>8;
	out_data[10] = checksum;

	// Send data to AX12
	HAL_UART_Transmit(AX12_UART, out_data, 11, 11);
	return ax12_read_response();
}

uint8_t ax12_set_speed(uint8_t id, uint16_t speed)
{
	uint8_t out_data[9];

	uint8_t checksum = ~(id + AX12_GOAL_SPEED_LENGTH + AX12_WRITE_DATA + AX12_GOAL_SPEED_L
			+ (speed&0xff) + (speed>>8));

	out_data[0] = out_data[1] = AX12_START;
	out_data[2] = id;
	out_data[3] = AX12_GOAL_SPEED_LENGTH;
	out_data[4] = AX12_WRITE_DATA;
	out_data[5] = AX12_GOAL_SPEED_L;
	out_data[6] = speed&0xff;
	out_data[7] = speed>>8;
	out_data[8] = checksum;

	HAL_UART_Transmit(AX12_UART, out_data, 9, 0);
	return ax12_read_response();
}

uint8_t ax12_factory_reset(uint8_t id)
{
	uint8_t out_data[6], checksum = ~(id + AX12_RESET_LENGTH + AX12_RESET);

	out_data[0] = out_data[1] = AX12_START;
	out_data[2] = id;
	out_data[3] = AX12_RESET_LENGTH;
	out_data[4] = AX12_RESET;
	out_data[5] = checksum;

	HAL_UART_Transmit(AX12_UART, out_data, 6, 6);
	return ax12_read_response();
}

uint8_t ax12_set_baudrate(uint8_t id, uint32_t baudrate)
{
	uint8_t out_data[8], checksum = ~(id + AX12_BAUDRATE_LENGTH + AX12_WRITE_DATA
				+ AX12_BAUDRATE + ((2000000/baudrate)-1));

	out_data[0] = out_data[1] = AX12_START;
	out_data[2] = id;
	out_data[3] = AX12_BAUDRATE_LENGTH;
	out_data[4] = AX12_WRITE_DATA;
	out_data[5] = AX12_BAUDRATE;
	out_data[6] = (2000000/baudrate)-1;
	out_data[7] = checksum;

	HAL_UART_Transmit(AX12_UART, out_data, 8, 8);
	return ax12_read_response();
}

uint8_t ax12_set_id(uint8_t id, uint8_t new_id)
{
	uint8_t out_data[8], checksum = ~(id + AX12_ID_LENGTH + AX12_WRITE_DATA
                                         + AX12_ID + new_id);

	out_data[0] = out_data[1] = AX12_START;
	out_data[2] = id;
	out_data[3] = AX12_ID_LENGTH;
	out_data[4] = AX12_WRITE_DATA;
	out_data[5] = AX12_ID;
	out_data[6] = new_id;
	out_data[7] = checksum;

	HAL_UART_Transmit(AX12_UART, out_data, 8, 8);
	return ax12_read_response();
}

uint8_t ax12_set_angle_limit(uint8_t id, uint16_t cw_limit, uint16_t ccw_limit)
{
	uint8_t out_data[11], checksum = ~(id + AX12_AL_LENGTH + AX12_WRITE_DATA
                                          + AX12_ANGLE_LIMIT + (cw_limit&0xff)
                                          + (ccw_limit>>8) + (ccw_limit&0xff)
                                          + (ccw_limit>>8));

	out_data[0]  = out_data[1] = AX12_START;
	out_data[2]  = id;
	out_data[3]  = AX12_AL_LENGTH;
	out_data[4]  = AX12_WRITE_DATA;
	out_data[5]  = AX12_ANGLE_LIMIT;
	out_data[6]  = cw_limit&0xff;
	out_data[7]  = cw_limit>>8;
	out_data[8]  = ccw_limit&0xff;
	out_data[9]  = ccw_limit>>8;
	out_data[10] = checksum;

	HAL_UART_Transmit(AX12_UART, out_data, 11, 11);
	return ax12_read_response();
}

uint8_t ax12_read_moving_status(uint8_t id)
{
	uint8_t out_data[8], checksum = ~(id + AX12_MOVING_LENGTH + AX12_READ_DATA
			                             + AX12_MOVING + AX12_BYTE_READ);

	out_data[0] = out_data[1] = AX12_START;
	out_data[2] = id;
	out_data[3] = AX12_MOVING_LENGTH;
	out_data[4] = AX12_READ_DATA;
	out_data[5] = AX12_MOVING;
	out_data[6] = AX12_BYTE_READ;
	out_data[7] = checksum;

	HAL_UART_Transmit(AX12_UART, out_data, 8, 8);
	return ax12_read_response();
}

uint8_t ax12_read_response(void)
{
	uint8_t data[4];
	uint8_t error, length;

	HAL_UART_Receive(AX12_UART, data, 4, 4);

	if (data[0] != 0xff)
		return 0;

	length = data[3];

	HAL_UART_Receive(AX12_UART, &error, 1, 1);
	unsigned char temp;
	for (uint8_t i = 0; i < length - 1; ++i) {
		HAL_UART_Receive(AX12_UART, &temp, 1, 1);
	}

	return error;
}
