#include <drivers/actuators/ax12/ax12.h>

// TODO: Convert postion to degrees?
void move(uint8_t id, uint16_t position)
{
	uint8_t out_data[9], checksum;

	// Calculate checksum
	checksum = ~(id + GOAL_LENGTH + WRITE_DATA + GOAL_POSITION_L
			+ (position&0xff) + (position>>8));

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
	for (uint8_t i = 0; i < 9; ++i)
		usart_send_blocking(AX12, out_data[i]);
}

void move_speed(uint8_t id, uint16_t position, uint16_t speed)
{
	uint8_t out_data[11], checksum;

	// Calculate checksum
	checksum = ~(id + GOAL_SP_LENGTH + WRITE_DATA + GOAL_POSITION_L
			+ (position&0xff) + (position>>8)
			+ (speed&0xff) + (speed>>8));

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
	for (uint8_t i = 0; i < 11; ++i)
		usart_send_blocking(AX12, out_data[i]);
}

void set_speed(uint8_t id, uint16_t speed)
{
	uint8_t out_data[9];

	uint8_t checksum = ~(id + GOAL_SPEED_LENGTH + WRITE_DATA + GOAL_SPEED_L
			+ (speed&0xff) + (speed>>8));

	out_data[0] = out_data[1] = START;
	out_data[2] = id;
	out_data[3] = GOAL_SPEED_LENGTH;
	out_data[4] = WRITE_DATA;
	out_data[5] = GOAL_SPEED_L;
	out_data[6] = speed&0xff;
	out_data[7] = speed>>8;
	out_data[8] = checksum;

	for (uint8_t i = 0; i < 9; ++i)
		usart_send_blocking(AX12, out_data[i]);
}

void factory_reset(uint8_t id)
{
	uint8_t out_data[6], checksum = ~(id + RESET_LENGTH + RESET);

	out_data[0] = out_data[1] = START;
	out_data[2] = id;
	out_data[3] = RESET_LENGTH;
	out_data[4] = RESET;
	out_data[5] = checksum;

	for (uint8_t i = 0; i < 6; ++i)
		usart_send_blocking(AX12, out_data[i]);
}

void set_baudrate(uint8_t id, uint32_t baudrate)
{
	uint8_t out_data[8], checksum = ~(id + BAUDRATE_LENGTH + WRITE_DATA
				+ BAUDRATE + ((2000000/baudrate)-1));

	out_data[0] = out_data[1] = START;
	out_data[2] = id;
	out_data[3] = BAUDRATE_LENGTH;
	out_data[4] = WRITE_DATA;
	out_data[5] = BAUDRATE;
	out_data[6] = (2000000/baudrate)-1;
	out_data[7] = checksum;

	for (uint8_t i = 0; i < 8; ++i)
		usart_send_blocking(AX12, out_data[i]);
}

void set_id(uint8_t id, uint8_t new_id)
{
	uint8_t out_data[8], checksum = ~(id + ID_LENGTH + WRITE_DATA + ID + new_id);

	out_data[0] = out_data[1] = START;
	out_data[2] = id;
	out_data[3] = ID_LENGTH;
	out_data[4] = WRITE_DATA;
	out_data[5] = ID;
	out_data[6] = new_id;
	out_data[7] = checksum;

	for (uint8_t i = 0; i < 8; ++i)
		usart_send_blocking(AX12, out_data[i]);
}

void set_angle_limit(uint8_t id, uint16_t cw_limit, uint16_t ccw_limit)
{
	uint8_t out_data[11], checksum = ~(id + AL_LENGTH + WRITE_DATA
		       		+ ANGLE_LIMIT + (cw_limit&0xff) + (ccw_limit>>8)
				+ (ccw_limit&0xff) + (ccw_limit>>8));

	out_data[0]  = out_data[1] = START;
	out_data[2]  = id;
	out_data[3]  = AL_LENGTH;
	out_data[4]  = WRITE_DATA;
	out_data[5]  = ANGLE_LIMIT;
	out_data[6]  = cw_limit&0xff;
	out_data[7]  = cw_limit>>8;
	out_data[8]  = ccw_limit&0xff;
	out_data[9]  = ccw_limit>>8;
	out_data[10] = checksum;

	for (uint8_t i = 0; i < 11; ++i)
		usart_send_blocking(AX12, out_data[i]);
}
