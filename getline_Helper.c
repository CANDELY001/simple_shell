#include "shell.h"
/**
 * _realloc  - same as C realloc
 * @old_ptr: the old one
 * @size: curr size
 * Return: void
 */
/*BY CHARIFA MASBAHI & NORA JEOUT*/
void *_realloc(void *old_ptr, size_t size)
{
	void *new_ptr;

	if (size == 0)
	{
		free(old_ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	if (old_ptr != NULL)
	{
		_memcpy(new_ptr, old_ptr, size);
		free(old_ptr);
	}
	return (new_ptr);
}

/**
 * edit_buff  - updates the storage buffer
 * @buff_ptr: pointer
 * @buff_size: the size of buff
 * @buffer: storage
 * @idx: current position of buffer
 * Return: void
 */
void edit_buff(char **buff_ptr, size_t *buff_size, char *buffer, size_t idx)
{
	if (*buff_ptr == NULL || *buff_size < idx)
	{
		*buff_size = (idx > STORAGE_SIZE) ? idx : STORAGE_SIZE;
		*buff_ptr = buffer;
	}
	else
	{
		_strcpy(*buff_ptr, buffer);
		free(buffer);
	}
}
