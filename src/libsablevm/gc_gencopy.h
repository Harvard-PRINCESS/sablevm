#ifndef GC_GENCOPY_H
#define GC_GENCOPY_H

#if defined (_SABLEVM_GENCOPY_GC)

#define _SABLEVM_GC_WRITE_BARRIER 1

svm_static void _svmf_remember_set_add (_svmt_remember_set * remset,
					_svmt_object_instance **reference);

svm_static void (*_svmfp_remember_set_add)
  (_svmt_remember_set *, _svmt_object_instance **) = &_svmf_remember_set_add;

svm_static inline int
_svmf_in_mature_space (_svmt_JNIEnv *env, _svmt_object_instance *ref)
{
  return ((void *) ref >= env->vm->heap.start &&
	  (void *) ref < env->vm->heap.alloc);
}

svm_static inline int
_svmf_in_nursery (_svmt_JNIEnv *env, _svmt_object_instance *ref)
{
  return ((void *) ref < env->vm->heap.nursery_end &&
	  (void *) ref >= env->vm->heap.nursery_start);
}

svm_static inline int
_svmf_in_heap (_svmt_JNIEnv *env, _svmt_object_instance *ref)
{
  return (_svmf_in_mature_space (env, ref) || _svmf_in_nursery (env, ref));
}

svm_static inline void
_svmf_write_barrier (_svmt_JNIEnv *env, _svmt_object_instance **ref)
{
  if ((void *) *ref < env->vm->heap.nursery_end &&
      (void *) ref >= env->vm->heap.start)
    {
      (*_svmfp_remember_set_add) (&env->vm->heap.remember_set, ref);
    }
}

#endif /* _SABLEVM_GENCOPY_GC */

#endif /* GC_GENCOPY_H */
