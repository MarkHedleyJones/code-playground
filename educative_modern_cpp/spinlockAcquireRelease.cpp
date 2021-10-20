// spinlockAcquireRelease.cpp

#include <iostream>
#include <atomic>
#include <thread>

class Spinlock
{
  std::atomic_flag flag;

public:
  Spinlock()
    : flag(ATOMIC_FLAG_INIT)
  {
  }

  void lock()
  {
    while (flag.test_and_set(std::memory_order_acquire))
      ;
  }

  void unlock()
  {
    flag.clear(std::memory_order_release);
  }
};

Spinlock spin;

void workOnResource()
{
  spin.lock();
  std::cout << "Lock acqired, running task ... " << std::endl;
  spin.unlock();
  std::cout << "Work done" << std::endl;
}

int main()
{
  std::cout << "Main starting ..." << std::endl;
  std::thread t(workOnResource);
  std::thread t2(workOnResource);

  t.join();
  t2.join();
}

// Notice that, when compared to the spinLockSleep example, that there is
// no sleep in this code. The ordering is controlled by the memory model
// arguments std::memory_order_acquire and std::memory_order_release.
