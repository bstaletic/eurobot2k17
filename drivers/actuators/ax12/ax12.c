#include "ax12.h"

// TODO: Convert postion to degrees?
void move(int8_t id, int16_t position)
{
	int8_t out_data[9], checksum;

	// Calculate checksum
	checksum = ~(id + GOAL_LENGTH + WRITE_DATA + GOAL_POSITION_L
			+ position&0xff + position>>8);

	// Construct the data to be sent
	out_data[0] = out_data[1] = START;
	out_data[2] = id;
	out_data[3] = GOAL_LENGTH;
	out_data[4] = WRITE_DATA;
	out_data[5] = GOAL_POSITION_L;
	out_data[6] = position&0xff;
	out_data[7] = position>>8;
	out_data[8] = checksum;

	// Send data to AX12
	for (int8_t i = 0; int8_t i < 9; ++int8_t i)
		usart_send_blocking(AX12, out_data[i]);
}

void move_speed(int8_t id, int16_t position, int16_t speed)
{
	int8_t out_data[11], checksum;

	// Calculate checksum
	checksum = ~(id + GOAL_SP_LENGTH + WRITE_DATA + GOAL_POSITION_L
			+ position&0xff + position>>8
			+ speed&0xff + speed>>8);

	// Construct the data to be sent
	out_data[0] = out_data[1] = START;
	out_data[2] = id;
	out_data[3] = GOAL_SP_LENGTH;
	out_data[4] = WRITE_DATA;
	out_data[5] = GOAL_POSITION_L;
	out_data[6] = position&0xff;
	out_data[7] = position>>8;
	out_data[8] = speed*0xff;
	out_data[9] = speed>>8;
	out_data[10] = checksum;

	// Send data to AX12
	for (int8_t i = 0; int8_t i < 11; ++int8_t i)
		usart_send_blocking(AX12, out_data[i]);
}

void set_speed(int8_t id, int16_t speed)
{
	int8_t out_data[9];

	checksum = ~(id + SPEED_LENGTH + WRITE_DATA + GOAL_SPEED_L
			+ speed&0xff + speed>>8);

	out_data[0] = out_data[1] = START;
	out_data[2] = id;
	out_data[3] = GOAL_SPEED_LENGTH;
	out_data[4] = WRITE_DATA;
	out_data[5] = GOAL_SPEED_L;
	out_data[6] = speed&0xff;
	out_data[7] = speed>>8;
	out_data[8] = checksum;

	for (int8_t i = 0; int8_t i < 9; ++int8_t i)
		usart_send_blocking(AX12, out_data[i]);
}

void factory_reset(int8_t id)
{
	int8_t out_data[6], checksum = ~(id + RESET_LENGTH + RESET);

	out_data[0] = out_data[1] = START;
	out_data[2] = id;
	out_data[3] = RESET_LENGTH;
	out_data[4] = RESET;
	out_data[5] = checksum;

	for (int8_t i = 0; int8_t i < 6; ++int8_t i)
		usart_send_blocking(AX12, out_data[i]);
}

void set_baudrate(int8_t id, int32_t baudrate)
{
	int8_t out_data[8], checksum = ~(id + BAUDRATE_LENGTH + WRITE_DATA + BAUDRATE + ((2000000/baudrate)-1));

	out_data[0] = out_data[1] = START;
	out_data[2] = id;
	out_data[3] = BAUDRATE_LENGTH;
	out_data[4] = WRITE_DATA;
	out_data[5] = BAUDRATE;
	out_data[6] = (2000000/baudrate)-1;
	out_data[7] = checksum;

	for (int8_t i = 0; int8_t i < 8; ++int8_t i)
		usart_send_blocking(AX12, out_data[i]);
}

void set_id(int8_t id, int8_t new_id)
{
	int8_t out_data[8], checksum = ~(id + ID_LENGTH + WRITE_DATA + ID + new_id);

	out_data[0] = out_data[1] = START;
	out_data[2] = id;
	out_data[3] = ID_LENGTH;
	out_data[4] = WRITE_DATA;
	out_data[5] = ID;
	out_data[6] = new_id;
	out_data[7] = checksum;

	for (int8_t i = 0; int8_t i < 8; ++int8_t i)
		usart_send_blocking(AX12, out_data[i]);
}
