#include "main.h"

static char buffer[BUF_SIZE];
static int buf_index;
int g_count_mode;      /* When set, buffered_putchar only counts characters */
int g_dummy_count;     /* Dummy counter when in count mode */

/**
 * buffered_putchar - Adds a character to the buffer and flushes it if full.
 * @c: The character to add.
 *
 * Return: 1 on success.
 */
int buffered_putchar(char c)
{
	if (g_count_mode)
	{
		g_dummy_count++;
		return (1);
	}
	buffer[buf_index++] = c;
	if (buf_index == BUF_SIZE)
	{
		write(1, buffer, BUF_SIZE);
		buf_index = 0;
	}
	return (1);
}

/**
 * flush_buffer - Flushes the remaining contents of the buffer.
 */
void flush_buffer(void)
{
	if (buf_index > 0)
	{
		write(1, buffer, buf_index);
		buf_index = 0;
	}
}
