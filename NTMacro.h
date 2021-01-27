#ifndef __NT_MACRO_H__
#define __NT_MACRO_H__

#define NT_NAMESPACE_BEGIN          namespace NT {
#define NT_NAMESPACE_END            }
#define NT_USING_NAMESPACE          using namespace NT;

#define NT_PROPERTY_RW(varType, varName, funcName)\
protected:varType varName;\
public:virtual void set##funcName(varType var){varName = var;}\
public:virtual varType get##funcName(){return varName;}

#define NT_PROPERTY_RDONLY(varType, varName, funcName)\
protected:varType varName;\
public:virtual varType get##funcName(){return varName;}

#define NT_PROPERTY_WRONLY(varType, varName, funcName)\
protected:varType varName;\
public:virtual void set##funcName(varType var){varName = var;}

#endif