#ifndef _APUE_H_
#define _APUE_H_

#define _XOPEN_SOURCE 600

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/termios.h>

#ifndef TIOCGWINSZ
#include <sys/ioctl.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MAXLINE 4096
/*默认文件权限*/
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
/*默认目录权限*/
#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

typedef void sigfunc(int);

#if defined(SIG_IGN) && !defined(SIG_ERR)
    #define SIG_ERR ((sigfunc*) - 1)
#endif

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) < (b) ? (a) : (b))

char *path_alloc(int *);
long open_max(void);
void clr_fl(int, int);
void set_fl(int, int);
void pr_exit(int);
void pr_mask(const char*);
sigfunc *signal_intr(int, sigfunc*);


int tty_cbreak(int);
int tty_raw(int);
int tty_reset(int);
int tty_atexit(void);
#ifdef ECHO
struct termios
#endif // ECHO

void sleep_us(unsigned int);
ssize_t readn(int, void*, size_t);
ssize_t writen(int, const void *, size_t);
void deamonize(const char*);

int s_pipe(int *);
int recv_fd(int, ssize_t (*func)(int, const void*, size_t));
int send_fd(int, int);
int send_err(int, int, const char *);

int serv_listen(const char*);
int serv_accept(int, uid_t*);
int cli_conn(const char *);
int buf_args(char *, int (*func)(int, char**));

int ptym_open(char *, int);
int ptys_open(char *);

#ifdef TIOCGWINSZ
pid_t pty_fork(int *, char *, int , const struct termios *, const struct winsize *, sonst struct winsize *);
#endif

int lock_reg(int, int, int, off_t, int, off_t);
#define read_lock(fd, offset, whence, len)  \
        lock_reg((fd), F_SETLK, F_RDLCK, (offset), (whence), (len))
#define readw_lock(fd, offset, whence, len)  \
        lock_reg((fd), F_SETLKW, F_RDLCK, (offset), (whence), (len))
#define write_lock(fd, offset, whence, len)   \
        lock_reg((fd), F_SETLK, F_WRLCK, (offset), (whence), (len))
#define writew_lock(fd, offset, whence, len)  \
        lock_reg((fd), F_SETLKW, FWRLCK, (offset), (whence), (len))
#define un_lock(fd, offset, whence, len)   \
        lock_reg((fd), F_SETLK, FUNLCK, (offset), (whence), (len))
pid_t lock_test(int , int, off_t, int , off_t);

#define is_read_lockable(fd, offset, whence, len)   \
    (lock_test((fd), F_RDLCK, (offset), (whence), (len) == 0))
#define is_write_lockable(fd, offset, whence, len)  \
    (lock_test((fd), F_WRLCK, (offset), (whence), (len)) == 0)

void err_dump(const char*, ...);
void err_msg(const char *, ...);
void err_quit(const char *, ...);
void err_exit(int, const char *, ...);
void err_ret(const char*, ...);
void err_sys(const char*, ...);

void log_msg(const char*, ...);
void log_open(const char*, int, int);
void log_quit(const char*, ...);
void log_ret(const char*, ...);
void log_sys(const char*, ...);

void TELL_WAIT(void);
void TELL_PARENT(pid_t);
void Tell_child(pid_t);
void WAIT_PARENT(void);
void WAIT_CHILD(void);

#endif
