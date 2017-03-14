

#include "stdafx.h"
#include "cpprest/asyncrt_mem.h"



namespace utility
{

namespace memory
{

std::function<void*(size_t size)> _new;
std::function<void(void *ptr)> _delete;

void *DefaultNew(size_t size)
{
    return malloc(size);
}

void DefaultDelete(void *ptr)
{
    free(ptr);
}

void SetNew(std::function<void*(size_t size)> new_fn)
{
    _new = new_fn;
}

void SetDelete(std::function<void(void *ptr)> del_fn)
{
    _delete = del_fn;
}

void Cleanup()
{
    _new = DefaultNew;
    _delete = DefaultDelete;
}

}

}


void *__cdecl operator new (size_t size)
{
    if (utility::memory::_new)
    {
        return utility::memory::_new(size);
    }
    return utility::memory::DefaultNew(size);
}

void __cdecl operator delete (void *ptr)
{
    if (utility::memory::_delete)
    {
        utility::memory::_delete(ptr);
    }
    else
    {
        utility::memory::DefaultDelete(ptr);
    }
}