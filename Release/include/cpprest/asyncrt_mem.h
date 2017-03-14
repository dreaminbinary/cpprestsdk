
#pragma once
#include <functional>


namespace utility
{
    
namespace memory
{

_ASYNCRTIMP void __cdecl SetNew(std::function<void*(size_t size)>);
_ASYNCRTIMP void __cdecl SetDelete(std::function<void(void *ptr)>);
_ASYNCRTIMP void __cdecl Cleanup();

}

}
