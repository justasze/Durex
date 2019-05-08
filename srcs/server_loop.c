#include "durex.h"

static void	prepare_fds(t_server_data *data)
{
	FD_ZERO(&data->fd_read);
	FD_ZERO(&data->fd_write);
	FD_SET(data->server_fd, &data->fd_read);
	data->highest_fd = data->server_fd;
	for (size_t i = 0; i < MAX_CLIENTS; i++)
	{
		if (data->clients[i].fd >= 0)
		{
			FD_SET(data->clients[i].fd, &data->fd_read);
			if (data->clients[i].wbuffer_pos > 0)
				FD_SET(data->clients[i].fd, &data->fd_write);
			if (data->highest_fd < data->clients[i].fd)
				data->highest_fd = data->clients[i].fd;
		}
	}
}

static void	client_write(t_server_data *data, size_t client_id)
{
	t_client_data	*client;

	client = &data->clients[client_id];
	send(client->fd, client->write_buffer, client->wbuffer_pos, 0);
	client->wbuffer_pos = 0;
}

static void	server_accept(t_server_data *data)
{
	int					free_client = -1;
	struct sockaddr_in	sock_addr;
	socklen_t			sock_len;

	for(size_t i = 0; i < MAX_CLIENTS; i++)
	{
		if (data->clients[i].fd == -1)
		{
			free_client = i;
			break ;
		}
	}
	if (free_client == -1)
	{
		close(accept(data->server_fd, (struct sockaddr*)&sock_addr, &sock_len));
		return;
	}

	sock_len = sizeof(sock_addr);
	data->clients[free_client].fd = accept(data->server_fd, (struct sockaddr*)&sock_addr, &sock_len);
	data->clients[free_client].read_function = client_read;
	data->clients[free_client].write_function = client_write;
	send(data->clients[free_client].fd, CONNEXION_PROMPT,
		ft_strlen(CONNEXION_PROMPT), 0);
}

static void	check_fds(t_server_data *data)
{

	if (FD_ISSET(data->server_fd, &data->fd_read))
	{
		server_accept(data);
		data->nb_ready_fds--;
	}
	for (size_t i = 0; i <= MAX_CLIENTS && data->nb_ready_fds > 0; i++)
	{
		if (FD_ISSET(data->clients[i].fd, &data->fd_read))
		{
			data->clients[i].read_function(data, i);
			data->nb_ready_fds--;
		}
		if (FD_ISSET(data->clients[i].fd, &data->fd_write))
		{
			data->clients[i].write_function(data, i);
			data->nb_ready_fds--;
		}
	}
}

void		server_loop(t_server_data *data)
{
	while (1)
	{
		prepare_fds(data);
		data->nb_ready_fds = select((int)data->highest_fd + 1, &data->fd_read,
											&data->fd_write, NULL, NULL);
		check_fds(data);
	}
}