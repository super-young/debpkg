#ifndef __dbg_h__
#define __dbg_h__
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#ifdef NODEBUG
#define debug(M,...)
#else
#define debug(m,...) fprintf("Debug:%s,%d" M "\n",__FILE,__LINE__,##VA__ARGS__)
#define clean_errno() (errno==0?"None":strerror(errno))
#define log_err(M,...) fprintf("[ERROR] (%s:%d: errno:%s)" M "\n",__FILE__,__LINE__,clean_errno())
#define log_info(M,...) fprintf("[INFO] (%s:%d:)" M "\n",__FILE__,__LINE__,##VA__ARGS__)
#define log_warn(M,...) fprintf("[WARN] (%s:%d: errno:%s)" M "\n",__FILE__,__LINE__,clean_errno(),##VA__ARGS__)
#define check(A,M,...) if(!(A)) {log_err(M, ##VA__ARGS__);errno=0;goto error;}
#define sentinel(M, ...)  {log_err(M, ##VA__ARGS__);errno=0;goto error;}
#define check_mem(A) check(A, "out of memory")
#define check_debug(A,M,...) if(!(A)) {debug(M,##VA__ARGS__;errno=0;goto error;)}
#endif
#endif