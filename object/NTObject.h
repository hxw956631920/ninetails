#ifndef __NT_OBJECT_H__
#define __NT_OBJECT_H__

#include "../NTMacro.h"

NT_NAMESPACE_BEGIN
class NTObject
{
protected:
    NTObject();
    ~NTObject();
public:
    void retain();
    void release();

protected:
    // 引用计数
    unsigned int refCount;
};

NT_NAMESPACE_END

#endif