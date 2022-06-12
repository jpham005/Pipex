#include "wait_all.h"

#include <sys/wait.h>

#include "utils.h"

const static int	g_signal_code = 128;

static int	get_exit_status(int status)
{
	const int	w_status = status & 0177;
	const int	w_stopped = 0177;
	const int	sig_stop = 17;
	const int	sig_cont = 19;

	if (w_status == 0)
		return ((status >> 8) & 0x000000ff);
	if ((w_status != w_stopped) && (w_status != 0))
		return (g_signal_code + w_status);
	if ((w_status == 0177) && ((w_status >> 8) != 0x13))
		return (g_signal_code + sig_stop);
	return (g_signal_code + sig_cont);
}

static pid_t	get_last_pid(t_pid_list *head)
{
	if (!head)
		return (-1);
	while (head->next)
		head = head->next;
	return (head->pid);
}

int	wait_all(t_pid_list *head)
{
	const pid_t	last = get_last_pid(head);
	int			status;
	int			ret;

	if (last == -1)
		return (-1);
	status = 0;
	while (head)
	{
		if (last == wait(&status))
			ret = status;
		head = head->next;
	}
	return (get_exit_status(ret));
}

void	wait_exit_failure(const char *str, t_pid_list *head)
{
	wait_all(head);
	exit_with_status(str, FAILURE);
}
