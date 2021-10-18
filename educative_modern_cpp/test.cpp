#include <iostream>
#include <atomic>
#include <thread>

// int main()
// {
//   std::shared_ptr<int> ptr = std::make_shared<int>(2011);
//   std::cout << "initial: " << *(ptr) << std::endl;
//   for (auto i = 0; i < 10; i++)
//   {
//     std::thread([ptr]
//                 {
//                   std::shared_ptr<int> localPtr(ptr);
//                   std::cout << "pre: " << *(localPtr) << std::endl;
//                   localPtr = std::make_shared<int>(2014);
//                   std::cout << "post: " << *(localPtr) << std::endl;
//                 })
//         .detach();
//   }
//   std::cout << "final: " << *(ptr) << std::endl;
// }

// int main()
// {
//   std::shared_ptr<int> ptr = std::make_shared<int>(2011);
//   std::cout << "initial: " << *(ptr) << std::endl;
//   for (auto i = 0; i < 10; i++)
//   {
//     std::thread([&ptr]
//                 {
//                   std::cout << "pre: " << *(ptr) << std::endl;
//                   ptr = std::make_shared<int>(2014);
//                   std::cout << "post: " << *(ptr) << std::endl;
//                 })
//         .detach();
//   }
//   std::cout << "final: " << *(ptr) << std::endl;
// }

// This doesn't work as it often causes a memory segmentation fault.
int main()
{
  std::shared_ptr<int> ptr = std::make_shared<int>(2011);
  std::cout << "initial: " << *(ptr) << std::endl;
  for (auto i = 0; i < 10; i++)
  {
    std::thread([&ptr]
                {
                  auto localPtr = std::make_shared<int>(2014);
                  std::cout << "pre: " << *(ptr) << std::endl;
                  std::atomic_store(&ptr, localPtr);
                  std::cout << "post: " << *(ptr) << std::endl;
                })
        .detach();
  }
  std::cout << "final: " << *(ptr) << std::endl;
}
