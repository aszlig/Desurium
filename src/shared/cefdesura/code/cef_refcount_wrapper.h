#ifndef DESURA_CEF_REFCOUNT_WRAPPER_H
#define DESURA_CEF_REFCOUNT_WRAPPER_H
#ifdef _WIN32
#pragma once
#endif

#include "include/cef_base.h"

// XXX: MAKE THIS OBSOLETE ASAP!

template <typename T>
class CefRefCountWrapper : public T
{
public:
  CefRefCountWrapper() : refct_(0) {}

  ///
  // Atomic reference increment.
  ///
  int AddRef() {
    return CefAtomicIncrement(&refct_);
  }

  ///
  // Atomic reference decrement. Delete the object when no references remain.
  ///
  int Release() {
    return CefAtomicDecrement(&refct_);
  }

  ///
  // Return the current number of references.
  ///
  int GetRefCt() { return refct_; }

private:
  long refct_;  // NOLINT(runtime/int)
};

#endif //DESURA_CEF_REFCOUNT_WRAPPER_H
