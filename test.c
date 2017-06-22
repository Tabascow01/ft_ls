#include "ft_ls.h"

int		main(void)
{
	DIR				*directory;
	struct dirent	*dir_ent;
	struct stat		file_stat;
	struct passwd	*passwd;
	uid_t			uid;
	ssize_t			size;
	char			*buf;
	time_t			clock;
	char			*strtime;

	buf = NULL;
	directory = opendir(".");// FOR DIR
	dir_ent = readdir(directory);
	printf("[%s]\n",dir_ent->d_name);

	stat("./Makefile", &file_stat);// FOR FILES
	uid = file_stat.st_uid;
	printf("[%u]\n",uid);

	lstat("./Makefile", &file_stat);// FOR SYMB LINKS
	uid = file_stat.st_uid;
	printf("[%u]\n", uid);

	passwd = getpwuid(uid);
	printf("[%s]\n",passwd->pw_name);

	size = listxattr("./Makefile", buf, 32, XATTR_NOFOLLOW);
	printf("[%ld]\n",size);

	strtime = (char *)malloc(sizeof(char) * 26);
	clock = time(&clock);
	strtime = ctime(&clock);
	printf("[%s]\n", strtime);

	return (0);
}
