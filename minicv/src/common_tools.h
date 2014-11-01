#ifndef _COMMON_TOOLS_H_
#define _COMMON_TOOLS_H_

//代码在超出作用域后自动执行
template <class Lambda> class AtScopeExit {
	Lambda& m_lambda;
public:
	AtScopeExit(Lambda& action) : m_lambda(action) {}
	~AtScopeExit() { m_lambda(); }
};
#define TOKEN_PASTEx(x, y) x ## y
#define TOKEN_PASTE(x, y) TOKEN_PASTEx(x, y)
#define Auto_INTERNAL1(lname, aname, ...) \
    auto lname = [&]() { __VA_ARGS__; }; \
    AtScopeExit<decltype(lname)> aname(lname);
#define Auto_INTERNAL2(ctr, ...) \
    Auto_INTERNAL1(TOKEN_PASTE(Auto_func_, ctr), \
                   TOKEN_PASTE(Auto_instance_, ctr), __VA_ARGS__)
#define AUTO_EXECUTE(...) Auto_INTERNAL2(__COUNTER__, __VA_ARGS__)



#endif //_COMMON_TOOLS_H_