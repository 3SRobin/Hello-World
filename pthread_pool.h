
#ifndef __PTHREAD_POOL_H__
 
#define __PTHREAD_POOL_H__
 
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <errno.h>
 
#define THREAD_MAX_NUM	100     
#define THREAD_DEF_NUM	20     
#define THREAD_MIN_NUM	5      
#define LISNUM<span style="white-space:pre">	</span>5
#define PORT	9001
#define MAXBUF	1024

typedef struct task_node
{
	void *arg;                             
	void *(*fun)(void *);                   
	pthread_t		tid;           
	int			work_id;        
	int			flag;          
	struct task_node	*next;
	pthread_mutex_t		mutex;        
} TASK_NODE;

typedef struct task_queue
{
	pthread_mutex_t		mutex;
	pthread_cond_t		cond;   
	struct task_node	*head; 
	int			number; 
} TASK_QUEUE_T;

typedef struct pthread_node
{
	pthread_t		tid;    
	int			flag;  
	struct task_node	*work;  
	struct pthread_node	*next;
	struct pthread_node	*prev;
	pthread_cond_t		cond;  
	pthread_mutex_t		mutex;
} THREAD_NODE;

typedef struct pthread_queue
{
	int			number; 
	struct pthread_node	*head;
	struct pthread_node	*rear;
	pthread_cond_t		cond;   
	pthread_mutex_t		mutex;
} PTHREAD_QUEUE_T;
 
extern PTHREAD_QUEUE_T	*pthread_queue_idle;  
extern PTHREAD_QUEUE_T	*pthread_queue_busy;    
extern TASK_QUEUE_T	*task_queue_head;       
 
void *child_work( void *ptr );
 
void create_pthread_pool( void );
 
void init_system( void );
 
void *thread_manager( void *ptr );
 
void *prcoess_client( void *ptr );
 
void *task_manager( void *ptr );
 
void *monitor( void *ptr );
 
void sys_clean( void );
 
#endif
