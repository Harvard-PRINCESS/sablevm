/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_THREAD_H
#define SVM_THREAD_H

#define _svmm_mutex_init(mutex)			\
pthread_mutex_init (&mutex, NULL)

#define _svmm_mutex_destroy(mutex)		\
pthread_mutex_destroy (&mutex)

#define _svmm_mutex_lock(mutex)			\
{						\
  pthread_mutex_t *_svmx_pmutex = &mutex;	\
  pthread_mutex_lock (_svmx_pmutex)

#define _svmm_mutex_unlock()			\
  pthread_mutex_unlock (_svmx_pmutex);		\
}

#define _svmm_mutex_trylock(mutex)		\
pthread_mutex_trylock(&mutex)

#define _svmm_mutex_unlock_after_try(mutex)	\
pthread_mutex_unlock(&mutex)


#define _svmm_cond_init(cond) \
pthread_cond_init (&cond, NULL)

#define _svmm_cond_destroy(cond) \
pthread_cond_destroy (&cond)

#define _svmm_cond_wait(cond, mutex) \
pthread_cond_wait (&cond, &mutex)

#define _svmm_cond_timedwait(cond, mutex, abstime) \
pthread_cond_timedwait (&cond, &mutex, &abstime)

#define _svmm_cond_signal(cond) \
pthread_cond_signal (&cond)

#define _svmm_cond_broadcast(cond) \
pthread_cond_broadcast (&cond)

#define _svmm_cond_broadcast_ptr(cond) \
pthread_cond_broadcast (cond)

#define _svmm_kill(thread, signal) \
pthread_kill (thread, signal)

#define _svmm_enter_object_monitor_non_blocking(env, instance, succeeded) \
_svmh_enter_object_monitor_non_blocking (env, instance, &succeeded)

static _svmt_JNIEnv *_svmf_get_current_env (void);

#endif /* not SVM_THREAD_H */
