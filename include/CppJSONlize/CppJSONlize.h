#include "nlohmann/json.hpp"

// Macros to simplify conversion from/to types

#define _CPPJSONLIZE_JSON_EXPAND(x) x
#define _CPPJSONLIZE_JSON_GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18,   \
                                    _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34,    \
                                    _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50,    \
                                    _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, NAME, ...)   \
    NAME
#define _CPPJSONLIZE_JSON_PASTE(...)                                                                                   \
    _CPPJSONLIZE_JSON_EXPAND(_CPPJSONLIZE_JSON_GET_MACRO(                                                              \
        __VA_ARGS__, _CPPJSONLIZE_JSON_PASTE64, _CPPJSONLIZE_JSON_PASTE63, _CPPJSONLIZE_JSON_PASTE62,                  \
        _CPPJSONLIZE_JSON_PASTE61, _CPPJSONLIZE_JSON_PASTE60, _CPPJSONLIZE_JSON_PASTE59, _CPPJSONLIZE_JSON_PASTE58,    \
        _CPPJSONLIZE_JSON_PASTE57, _CPPJSONLIZE_JSON_PASTE56, _CPPJSONLIZE_JSON_PASTE55, _CPPJSONLIZE_JSON_PASTE54,    \
        _CPPJSONLIZE_JSON_PASTE53, _CPPJSONLIZE_JSON_PASTE52, _CPPJSONLIZE_JSON_PASTE51, _CPPJSONLIZE_JSON_PASTE50,    \
        _CPPJSONLIZE_JSON_PASTE49, _CPPJSONLIZE_JSON_PASTE48, _CPPJSONLIZE_JSON_PASTE47, _CPPJSONLIZE_JSON_PASTE46,    \
        _CPPJSONLIZE_JSON_PASTE45, _CPPJSONLIZE_JSON_PASTE44, _CPPJSONLIZE_JSON_PASTE43, _CPPJSONLIZE_JSON_PASTE42,    \
        _CPPJSONLIZE_JSON_PASTE41, _CPPJSONLIZE_JSON_PASTE40, _CPPJSONLIZE_JSON_PASTE39, _CPPJSONLIZE_JSON_PASTE38,    \
        _CPPJSONLIZE_JSON_PASTE37, _CPPJSONLIZE_JSON_PASTE36, _CPPJSONLIZE_JSON_PASTE35, _CPPJSONLIZE_JSON_PASTE34,    \
        _CPPJSONLIZE_JSON_PASTE33, _CPPJSONLIZE_JSON_PASTE32, _CPPJSONLIZE_JSON_PASTE31, _CPPJSONLIZE_JSON_PASTE30,    \
        _CPPJSONLIZE_JSON_PASTE29, _CPPJSONLIZE_JSON_PASTE28, _CPPJSONLIZE_JSON_PASTE27, _CPPJSONLIZE_JSON_PASTE26,    \
        _CPPJSONLIZE_JSON_PASTE25, _CPPJSONLIZE_JSON_PASTE24, _CPPJSONLIZE_JSON_PASTE23, _CPPJSONLIZE_JSON_PASTE22,    \
        _CPPJSONLIZE_JSON_PASTE21, _CPPJSONLIZE_JSON_PASTE20, _CPPJSONLIZE_JSON_PASTE19, _CPPJSONLIZE_JSON_PASTE18,    \
        _CPPJSONLIZE_JSON_PASTE17, _CPPJSONLIZE_JSON_PASTE16, _CPPJSONLIZE_JSON_PASTE15, _CPPJSONLIZE_JSON_PASTE14,    \
        _CPPJSONLIZE_JSON_PASTE13, _CPPJSONLIZE_JSON_PASTE12, _CPPJSONLIZE_JSON_PASTE11, _CPPJSONLIZE_JSON_PASTE10,    \
        _CPPJSONLIZE_JSON_PASTE9, _CPPJSONLIZE_JSON_PASTE8, _CPPJSONLIZE_JSON_PASTE7, _CPPJSONLIZE_JSON_PASTE6,        \
        _CPPJSONLIZE_JSON_PASTE5, _CPPJSONLIZE_JSON_PASTE4, _CPPJSONLIZE_JSON_PASTE3, _CPPJSONLIZE_JSON_PASTE2,        \
        _CPPJSONLIZE_JSON_PASTE1)(__VA_ARGS__))
#define _CPPJSONLIZE_JSON_PASTE2(func, v1) func(v1)
#define _CPPJSONLIZE_JSON_PASTE3(func, v1, v2) _CPPJSONLIZE_JSON_PASTE2(func, v1) _CPPJSONLIZE_JSON_PASTE2(func, v2)
#define _CPPJSONLIZE_JSON_PASTE4(func, v1, v2, v3)                                                                     \
    _CPPJSONLIZE_JSON_PASTE2(func, v1) _CPPJSONLIZE_JSON_PASTE3(func, v2, v3)
#define _CPPJSONLIZE_JSON_PASTE5(func, v1, v2, v3, v4)                                                                 \
    _CPPJSONLIZE_JSON_PASTE2(func, v1) _CPPJSONLIZE_JSON_PASTE4(func, v2, v3, v4)
#define _CPPJSONLIZE_JSON_PASTE6(func, v1, v2, v3, v4, v5)                                                             \
    _CPPJSONLIZE_JSON_PASTE2(func, v1) _CPPJSONLIZE_JSON_PASTE5(func, v2, v3, v4, v5)
#define _CPPJSONLIZE_JSON_PASTE7(func, v1, v2, v3, v4, v5, v6)                                                         \
    _CPPJSONLIZE_JSON_PASTE2(func, v1) _CPPJSONLIZE_JSON_PASTE6(func, v2, v3, v4, v5, v6)
#define _CPPJSONLIZE_JSON_PASTE8(func, v1, v2, v3, v4, v5, v6, v7)                                                     \
    _CPPJSONLIZE_JSON_PASTE2(func, v1) _CPPJSONLIZE_JSON_PASTE7(func, v2, v3, v4, v5, v6, v7)
#define _CPPJSONLIZE_JSON_PASTE9(func, v1, v2, v3, v4, v5, v6, v7, v8)                                                 \
    _CPPJSONLIZE_JSON_PASTE2(func, v1) _CPPJSONLIZE_JSON_PASTE8(func, v2, v3, v4, v5, v6, v7, v8)
#define _CPPJSONLIZE_JSON_PASTE10(func, v1, v2, v3, v4, v5, v6, v7, v8, v9)                                            \
    _CPPJSONLIZE_JSON_PASTE2(func, v1) _CPPJSONLIZE_JSON_PASTE9(func, v2, v3, v4, v5, v6, v7, v8, v9)
#define _CPPJSONLIZE_JSON_PASTE11(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)                                       \
    _CPPJSONLIZE_JSON_PASTE2(func, v1) _CPPJSONLIZE_JSON_PASTE10(func, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#define _CPPJSONLIZE_JSON_PASTE12(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)                                  \
    _CPPJSONLIZE_JSON_PASTE2(func, v1) _CPPJSONLIZE_JSON_PASTE11(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#define _CPPJSONLIZE_JSON_PASTE13(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)                             \
    _CPPJSONLIZE_JSON_PASTE2(func, v1) _CPPJSONLIZE_JSON_PASTE12(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#define _CPPJSONLIZE_JSON_PASTE14(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)                        \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE13(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#define _CPPJSONLIZE_JSON_PASTE15(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)                   \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE14(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)
#define _CPPJSONLIZE_JSON_PASTE16(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)              \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE15(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#define _CPPJSONLIZE_JSON_PASTE17(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)         \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE16(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#define _CPPJSONLIZE_JSON_PASTE18(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)    \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE17(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#define _CPPJSONLIZE_JSON_PASTE19(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE18(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18)
#define _CPPJSONLIZE_JSON_PASTE20(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19)                                                                            \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE19(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19)
#define _CPPJSONLIZE_JSON_PASTE21(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20)                                                                       \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE20(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20)
#define _CPPJSONLIZE_JSON_PASTE22(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21)                                                                  \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE21(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21)
#define _CPPJSONLIZE_JSON_PASTE23(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22)                                                             \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE22(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22)
#define _CPPJSONLIZE_JSON_PASTE24(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23)                                                        \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE23(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23)
#define _CPPJSONLIZE_JSON_PASTE25(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24)                                                   \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE24(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24)
#define _CPPJSONLIZE_JSON_PASTE26(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25)                                              \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE25(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25)
#define _CPPJSONLIZE_JSON_PASTE27(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26)                                         \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE26(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26)
#define _CPPJSONLIZE_JSON_PASTE28(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27)                                    \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE27(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27)
#define _CPPJSONLIZE_JSON_PASTE29(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28)                               \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE28(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28)
#define _CPPJSONLIZE_JSON_PASTE30(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29)                          \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE29(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29)
#define _CPPJSONLIZE_JSON_PASTE31(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30)                     \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE30(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30)
#define _CPPJSONLIZE_JSON_PASTE32(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31)                \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE31(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31)
#define _CPPJSONLIZE_JSON_PASTE33(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32)           \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE32(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32)
#define _CPPJSONLIZE_JSON_PASTE34(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33)      \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE33(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33)
#define _CPPJSONLIZE_JSON_PASTE35(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34) \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE34(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34)
#define _CPPJSONLIZE_JSON_PASTE36(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE35(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35)
#define _CPPJSONLIZE_JSON_PASTE37(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36)                                                                            \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE36(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36)
#define _CPPJSONLIZE_JSON_PASTE38(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37)                                                                       \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE37(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37)
#define _CPPJSONLIZE_JSON_PASTE39(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38)                                                                  \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE38(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38)
#define _CPPJSONLIZE_JSON_PASTE40(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39)                                                             \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE39(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39)
#define _CPPJSONLIZE_JSON_PASTE41(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40)                                                        \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE40(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40)
#define _CPPJSONLIZE_JSON_PASTE42(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41)                                                   \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE41(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41)
#define _CPPJSONLIZE_JSON_PASTE43(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42)                                              \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE42(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42)
#define _CPPJSONLIZE_JSON_PASTE44(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43)                                         \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE43(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43)
#define _CPPJSONLIZE_JSON_PASTE45(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44)                                    \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE44(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44)
#define _CPPJSONLIZE_JSON_PASTE46(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45)                               \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE45(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45)
#define _CPPJSONLIZE_JSON_PASTE47(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46)                          \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE46(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46)
#define _CPPJSONLIZE_JSON_PASTE48(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47)                     \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE47(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47)
#define _CPPJSONLIZE_JSON_PASTE49(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48)                \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE48(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48)
#define _CPPJSONLIZE_JSON_PASTE50(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49)           \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE49(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49)
#define _CPPJSONLIZE_JSON_PASTE51(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50)      \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE50(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50)
#define _CPPJSONLIZE_JSON_PASTE52(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51) \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE51(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51)
#define _CPPJSONLIZE_JSON_PASTE53(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, \
                                  v52)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE52(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52)
#define _CPPJSONLIZE_JSON_PASTE54(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, \
                                  v52, v53)                                                                            \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE53(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53)
#define _CPPJSONLIZE_JSON_PASTE55(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, \
                                  v52, v53, v54)                                                                       \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE54(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53,     \
                              v54)
#define _CPPJSONLIZE_JSON_PASTE56(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, \
                                  v52, v53, v54, v55)                                                                  \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE55(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53,     \
                              v54, v55)
#define _CPPJSONLIZE_JSON_PASTE57(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, \
                                  v52, v53, v54, v55, v56)                                                             \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE56(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53,     \
                              v54, v55, v56)
#define _CPPJSONLIZE_JSON_PASTE58(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, \
                                  v52, v53, v54, v55, v56, v57)                                                        \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE57(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53,     \
                              v54, v55, v56, v57)
#define _CPPJSONLIZE_JSON_PASTE59(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, \
                                  v52, v53, v54, v55, v56, v57, v58)                                                   \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE58(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53,     \
                              v54, v55, v56, v57, v58)
#define _CPPJSONLIZE_JSON_PASTE60(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, \
                                  v52, v53, v54, v55, v56, v57, v58, v59)                                              \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE59(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53,     \
                              v54, v55, v56, v57, v58, v59)
#define _CPPJSONLIZE_JSON_PASTE61(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, \
                                  v52, v53, v54, v55, v56, v57, v58, v59, v60)                                         \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE60(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53,     \
                              v54, v55, v56, v57, v58, v59, v60)
#define _CPPJSONLIZE_JSON_PASTE62(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, \
                                  v52, v53, v54, v55, v56, v57, v58, v59, v60, v61)                                    \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE61(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53,     \
                              v54, v55, v56, v57, v58, v59, v60, v61)
#define _CPPJSONLIZE_JSON_PASTE63(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, \
                                  v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62)                               \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE62(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53,     \
                              v54, v55, v56, v57, v58, v59, v60, v61, v62)
#define _CPPJSONLIZE_JSON_PASTE64(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,    \
                                  v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, \
                                  v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, \
                                  v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63)                          \
    _CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                 \
    _CPPJSONLIZE_JSON_PASTE63(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,  \
                              v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36,     \
                              v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53,     \
                              v54, v55, v56, v57, v58, v59, v60, v61, v62, v63)

#define STRINGIFY(x) #x
// #define
#define CPPJSONLIZE_DEFINE_TYPE_INTRUSIVE(Type, ...)                                                                   \
    friend void to_json(nlohmann::json &nlohmann_json_j, const Type &nlohmann_json_t)                                  \
    {                                                                                                                  \
        _CPPJSONLIZE_JSON_EXPAND(_CPPJSONLIZE_JSON_PASTE(_CPPJSONLIZE_JSON_TO, __VA_ARGS__))                           \
    }                                                                                                                  \
    friend void from_json(const nlohmann::json &nlohmann_json_j, Type &nlohmann_json_t)                                \
    {                                                                                                                  \
        const Type nlohmann_json_default_obj{};                                                                        \
        _CPPJSONLIZE_JSON_EXPAND(_CPPJSONLIZE_JSON_PASTE(_CPPJSONLIZE_JSON_FROM, __VA_ARGS__))                         \
    }

#define CPPJSONLIZE_ARG_NOPE "_NOPE_CPPJSON__"
#define CPPJSONLIZE_FORCE_NEED "__FORCE_NEED_CPPJSONLIZE__"

#define GET_FIRST_PART(arg1, ...) arg1

#ifdef _MSC_VER
#define INDIRECT_EXPAND(m, args) m args
#define GET_SECOND_ARGS_SHIFT(first, N, ...) N
#define GET_SECOND_ARGS_SHIFT_(...) INDIRECT_EXPAND(GET_SECOND_ARGS_SHIFT, (__VA_ARGS__))
#define GET_SECOND_PART_IMPL(...) GET_SECOND_ARGS_SHIFT_(__VA_ARGS__, INSNN_PARAM_ARG_NOPE)
#define GET_SECOND_PART(...) GET_SECOND_PART_IMPL(__VA_ARGS__)

#define GET_THIRD_ARGS_SHIFT(first, N, ...) N
#define GET_THIRD_ARGS_SHIFT_(...) INDIRECT_EXPAND(GET_THIRD_ARGS_SHIFT, (__VA_ARGS__))
#define GET_THIRD_PART_IMPL(...) GET_THIRD_ARGS_SHIFT_(__VA_ARGS__, INSNN_PARAM_ARG_NOPE)
#define GET_THIRD_PART(...) GET_THIRD_PART_IMPL(__VA_ARGS__)
#else
#define GET_SECOND_PART(...) GET_SECOND_PART_IMPL(__VA_ARGS__)
#define GET_SECOND_ARGS_SHIFT(first, N, ...) N
#define GET_SECOND_PART_IMPL(...) GET_SECOND_ARGS_SHIFT(__VA_ARGS__, CPPJSONLIZE_ARG_NOPE)

#define GET_THIRD_PART(...) GET_THIRD_PART_IMPL(__VA_ARGS__)
#define GET_THIRD_ARGS_SHIFT(first, second, N, ...) N
#define GET_THIRD_PART_IMPL(...) GET_THIRD_ARGS_SHIFT(__VA_ARGS__, CPPJSONLIZE_ARG_NOPE, CPPJSONLIZE_ARG_NOPE)
#endif

#define _CPPJSONLIZE_JSON_TO(a1, ...)                                                                                  \
    _CPPJSONLIZE_JSON_TO_IMPL(GET_FIRST_PART a1, GET_SECOND_PART a1, GET_THIRD_PART a1);
#define _CPPJSONLIZE_JSON_TO_IMPL(name, forceNed, specName)                                                            \
    {                                                                                                                  \
        bool isforceNed = (strcmp(forceNed, CPPJSONLIZE_FORCE_NEED) == 0);                                             \
        std::string keyword = STRINGIFY(name);                                                                         \
        if (isforceNed && strcmp(specName, CPPJSONLIZE_ARG_NOPE) != 0)                                                 \
        {                                                                                                              \
            keyword = specName;                                                                                        \
        }                                                                                                              \
        else if (!isforceNed && strcmp(forceNed, CPPJSONLIZE_ARG_NOPE) != 0)                                           \
        {                                                                                                              \
            keyword = forceNed;                                                                                        \
        }                                                                                                              \
        nlohmann_json_j[keyword] = nlohmann_json_t.name;                                                               \
    }

#define _CPPJSONLIZE_JSON_FROM_IMPL(name, forceNed, specName)                                                          \
    {                                                                                                                  \
        bool isforceNed = (strcmp(forceNed, CPPJSONLIZE_FORCE_NEED) == 0);                                             \
        std::string keyword = STRINGIFY(name);                                                                         \
        if (isforceNed && strcmp(specName, CPPJSONLIZE_ARG_NOPE) != 0)                                                 \
        {                                                                                                              \
            keyword = specName;                                                                                        \
        }                                                                                                              \
        else if (!isforceNed && strcmp(forceNed, CPPJSONLIZE_ARG_NOPE) != 0)                                           \
        {                                                                                                              \
            keyword = forceNed;                                                                                        \
        }                                                                                                              \
        if (!isforceNed)                                                                                               \
        {                                                                                                              \
            nlohmann_json_t.name = nlohmann_json_j.value(keyword, nlohmann_json_default_obj.name);                     \
        }                                                                                                              \
        else                                                                                                           \
        {                                                                                                              \
            if (nlohmann_json_j.contains(keyword))                                                                     \
            {                                                                                                          \
                nlohmann_json_t.name = nlohmann_json_j.value(keyword, nlohmann_json_default_obj.name);                 \
            }                                                                                                          \
            else                                                                                                       \
            {                                                                                                          \
                std::cout << "read key for " << STRINGIFY(name) << " from " << keyword << "faild";                     \
                exit(1);                                                                                               \
            }                                                                                                          \
        }                                                                                                              \
    }

#define _CPPJSONLIZE_JSON_FROM(a1, ...)                                                                                \
    _CPPJSONLIZE_JSON_FROM_IMPL(GET_FIRST_PART a1, GET_SECOND_PART a1, GET_THIRD_PART a1);
