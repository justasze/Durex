#include <stdio.h>
#include "durex.h"

static void	init_data(t_server_data *data)
{
	ft_bzero(data, sizeof(t_server_data));
	data->server_fd = -1;
	for (size_t i = 0; i < MAX_CLIENTS; i++)
		data->clients[i].fd = -1;
}

static int	init_server(t_server_data *data)
{
	struct sockaddr_in	server_addr;

	if ((data->server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		return 0;
	ft_bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PAYLOAD_PORT);
	server_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(data->server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
		goto error;
	if (listen(data->server_fd, MAX_CLIENTS) == -1)
		goto error;
	return 1;
error:
	close(data->server_fd);
	return 0;
}

static void	clean_and_close(t_server_data *data)
{
	for (size_t i = 0; i < MAX_CLIENTS; i++)
		if (data->clients[i].fd >= 0)
			close(data->clients[i].fd);
	close(data->server_fd);
}

int			main()
{
	t_server_data	data;

	if (daemon(0, 0) == -1)
		return 1;
	init_data(&data);
	if (init_server(&data) == 0)
		return 1;
	server_loop(&data);
	clean_and_close(&data);
	return 0;
}
