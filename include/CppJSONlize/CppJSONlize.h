#include "nlohmann/json.hpp"

// Macros to simplify conversion from/to types

#define CPPJSONLIZE_JSON_EXPAND(x) x
#define CPPJSONLIZE_JSON_GET_MACRO(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18,    \
                                   _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34,     \
                                   _35, _36, _37, _38, _39, _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50,     \
                                   _51, _52, _53, _54, _55, _56, _57, _58, _59, _60, _61, _62, _63, _64, NAME, ...)    \
    NAME
#define CPPJSONLIZE_JSON_PASTE(...)                                                                                    \
    CPPJSONLIZE_JSON_EXPAND(CPPJSONLIZE_JSON_GET_MACRO(                                                                \
        __VA_ARGS__, CPPJSONLIZE_JSON_PASTE64, CPPJSONLIZE_JSON_PASTE63, CPPJSONLIZE_JSON_PASTE62,                     \
        CPPJSONLIZE_JSON_PASTE61, CPPJSONLIZE_JSON_PASTE60, CPPJSONLIZE_JSON_PASTE59, CPPJSONLIZE_JSON_PASTE58,        \
        CPPJSONLIZE_JSON_PASTE57, CPPJSONLIZE_JSON_PASTE56, CPPJSONLIZE_JSON_PASTE55, CPPJSONLIZE_JSON_PASTE54,        \
        CPPJSONLIZE_JSON_PASTE53, CPPJSONLIZE_JSON_PASTE52, CPPJSONLIZE_JSON_PASTE51, CPPJSONLIZE_JSON_PASTE50,        \
        CPPJSONLIZE_JSON_PASTE49, CPPJSONLIZE_JSON_PASTE48, CPPJSONLIZE_JSON_PASTE47, CPPJSONLIZE_JSON_PASTE46,        \
        CPPJSONLIZE_JSON_PASTE45, CPPJSONLIZE_JSON_PASTE44, CPPJSONLIZE_JSON_PASTE43, CPPJSONLIZE_JSON_PASTE42,        \
        CPPJSONLIZE_JSON_PASTE41, CPPJSONLIZE_JSON_PASTE40, CPPJSONLIZE_JSON_PASTE39, CPPJSONLIZE_JSON_PASTE38,        \
        CPPJSONLIZE_JSON_PASTE37, CPPJSONLIZE_JSON_PASTE36, CPPJSONLIZE_JSON_PASTE35, CPPJSONLIZE_JSON_PASTE34,        \
        CPPJSONLIZE_JSON_PASTE33, CPPJSONLIZE_JSON_PASTE32, CPPJSONLIZE_JSON_PASTE31, CPPJSONLIZE_JSON_PASTE30,        \
        CPPJSONLIZE_JSON_PASTE29, CPPJSONLIZE_JSON_PASTE28, CPPJSONLIZE_JSON_PASTE27, CPPJSONLIZE_JSON_PASTE26,        \
        CPPJSONLIZE_JSON_PASTE25, CPPJSONLIZE_JSON_PASTE24, CPPJSONLIZE_JSON_PASTE23, CPPJSONLIZE_JSON_PASTE22,        \
        CPPJSONLIZE_JSON_PASTE21, CPPJSONLIZE_JSON_PASTE20, CPPJSONLIZE_JSON_PASTE19, CPPJSONLIZE_JSON_PASTE18,        \
        CPPJSONLIZE_JSON_PASTE17, CPPJSONLIZE_JSON_PASTE16, CPPJSONLIZE_JSON_PASTE15, CPPJSONLIZE_JSON_PASTE14,        \
        CPPJSONLIZE_JSON_PASTE13, CPPJSONLIZE_JSON_PASTE12, CPPJSONLIZE_JSON_PASTE11, CPPJSONLIZE_JSON_PASTE10,        \
        CPPJSONLIZE_JSON_PASTE9, CPPJSONLIZE_JSON_PASTE8, CPPJSONLIZE_JSON_PASTE7, CPPJSONLIZE_JSON_PASTE6,            \
        CPPJSONLIZE_JSON_PASTE5, CPPJSONLIZE_JSON_PASTE4, CPPJSONLIZE_JSON_PASTE3, CPPJSONLIZE_JSON_PASTE2,            \
        CPPJSONLIZE_JSON_PASTE1)(__VA_ARGS__))
#define CPPJSONLIZE_JSON_PASTE2(func, v1) func(v1)
#define CPPJSONLIZE_JSON_PASTE3(func, v1, v2) CPPJSONLIZE_JSON_PASTE2(func, v1) CPPJSONLIZE_JSON_PASTE2(func, v2)
#define CPPJSONLIZE_JSON_PASTE4(func, v1, v2, v3)                                                                      \
    CPPJSONLIZE_JSON_PASTE2(func, v1) CPPJSONLIZE_JSON_PASTE3(func, v2, v3)
#define CPPJSONLIZE_JSON_PASTE5(func, v1, v2, v3, v4)                                                                  \
    CPPJSONLIZE_JSON_PASTE2(func, v1) CPPJSONLIZE_JSON_PASTE4(func, v2, v3, v4)
#define CPPJSONLIZE_JSON_PASTE6(func, v1, v2, v3, v4, v5)                                                              \
    CPPJSONLIZE_JSON_PASTE2(func, v1) CPPJSONLIZE_JSON_PASTE5(func, v2, v3, v4, v5)
#define CPPJSONLIZE_JSON_PASTE7(func, v1, v2, v3, v4, v5, v6)                                                          \
    CPPJSONLIZE_JSON_PASTE2(func, v1) CPPJSONLIZE_JSON_PASTE6(func, v2, v3, v4, v5, v6)
#define CPPJSONLIZE_JSON_PASTE8(func, v1, v2, v3, v4, v5, v6, v7)                                                      \
    CPPJSONLIZE_JSON_PASTE2(func, v1) CPPJSONLIZE_JSON_PASTE7(func, v2, v3, v4, v5, v6, v7)
#define CPPJSONLIZE_JSON_PASTE9(func, v1, v2, v3, v4, v5, v6, v7, v8)                                                  \
    CPPJSONLIZE_JSON_PASTE2(func, v1) CPPJSONLIZE_JSON_PASTE8(func, v2, v3, v4, v5, v6, v7, v8)
#define CPPJSONLIZE_JSON_PASTE10(func, v1, v2, v3, v4, v5, v6, v7, v8, v9)                                             \
    CPPJSONLIZE_JSON_PASTE2(func, v1) CPPJSONLIZE_JSON_PASTE9(func, v2, v3, v4, v5, v6, v7, v8, v9)
#define CPPJSONLIZE_JSON_PASTE11(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10)                                        \
    CPPJSONLIZE_JSON_PASTE2(func, v1) CPPJSONLIZE_JSON_PASTE10(func, v2, v3, v4, v5, v6, v7, v8, v9, v10)
#define CPPJSONLIZE_JSON_PASTE12(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)                                   \
    CPPJSONLIZE_JSON_PASTE2(func, v1) CPPJSONLIZE_JSON_PASTE11(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11)
#define CPPJSONLIZE_JSON_PASTE13(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)                              \
    CPPJSONLIZE_JSON_PASTE2(func, v1) CPPJSONLIZE_JSON_PASTE12(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12)
#define CPPJSONLIZE_JSON_PASTE14(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)                         \
    CPPJSONLIZE_JSON_PASTE2(func, v1) CPPJSONLIZE_JSON_PASTE13(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13)
#define CPPJSONLIZE_JSON_PASTE15(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)                    \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE14(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14)
#define CPPJSONLIZE_JSON_PASTE16(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)               \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE15(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15)
#define CPPJSONLIZE_JSON_PASTE17(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)          \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE16(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16)
#define CPPJSONLIZE_JSON_PASTE18(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)     \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE17(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17)
#define CPPJSONLIZE_JSON_PASTE19(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18)                                                                                  \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE18(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18)
#define CPPJSONLIZE_JSON_PASTE20(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19)                                                                             \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE19(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19)
#define CPPJSONLIZE_JSON_PASTE21(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20)                                                                        \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE20(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20)
#define CPPJSONLIZE_JSON_PASTE22(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21)                                                                   \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE21(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21)
#define CPPJSONLIZE_JSON_PASTE23(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22)                                                              \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE22(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22)
#define CPPJSONLIZE_JSON_PASTE24(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23)                                                         \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE23(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23)
#define CPPJSONLIZE_JSON_PASTE25(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24)                                                    \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE24(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24)
#define CPPJSONLIZE_JSON_PASTE26(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25)                                               \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE25(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25)
#define CPPJSONLIZE_JSON_PASTE27(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26)                                          \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE26(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26)
#define CPPJSONLIZE_JSON_PASTE28(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27)                                     \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE27(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27)
#define CPPJSONLIZE_JSON_PASTE29(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28)                                \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE28(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28)
#define CPPJSONLIZE_JSON_PASTE30(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29)                           \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE29(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29)
#define CPPJSONLIZE_JSON_PASTE31(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30)                      \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE30(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30)
#define CPPJSONLIZE_JSON_PASTE32(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31)                 \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE31(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31)
#define CPPJSONLIZE_JSON_PASTE33(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32)            \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE32(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32)
#define CPPJSONLIZE_JSON_PASTE34(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33)       \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE33(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33)
#define CPPJSONLIZE_JSON_PASTE35(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34)  \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE34(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34)
#define CPPJSONLIZE_JSON_PASTE36(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35)                                                                                  \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE35(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35)
#define CPPJSONLIZE_JSON_PASTE37(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36)                                                                             \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE36(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36)
#define CPPJSONLIZE_JSON_PASTE38(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37)                                                                        \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE37(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37)
#define CPPJSONLIZE_JSON_PASTE39(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38)                                                                   \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE38(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38)
#define CPPJSONLIZE_JSON_PASTE40(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39)                                                              \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE39(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39)
#define CPPJSONLIZE_JSON_PASTE41(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40)                                                         \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE40(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40)
#define CPPJSONLIZE_JSON_PASTE42(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41)                                                    \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE41(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41)
#define CPPJSONLIZE_JSON_PASTE43(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42)                                               \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE42(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42)
#define CPPJSONLIZE_JSON_PASTE44(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43)                                          \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE43(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43)
#define CPPJSONLIZE_JSON_PASTE45(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44)                                     \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE44(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44)
#define CPPJSONLIZE_JSON_PASTE46(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45)                                \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE45(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45)
#define CPPJSONLIZE_JSON_PASTE47(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46)                           \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE46(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46)
#define CPPJSONLIZE_JSON_PASTE48(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47)                      \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE47(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47)
#define CPPJSONLIZE_JSON_PASTE49(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48)                 \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE48(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48)
#define CPPJSONLIZE_JSON_PASTE50(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49)            \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE49(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49)
#define CPPJSONLIZE_JSON_PASTE51(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50)       \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE50(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50)
#define CPPJSONLIZE_JSON_PASTE52(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51)  \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE51(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51)
#define CPPJSONLIZE_JSON_PASTE53(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51,  \
                                 v52)                                                                                  \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE52(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52)
#define CPPJSONLIZE_JSON_PASTE54(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51,  \
                                 v52, v53)                                                                             \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE53(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53)
#define CPPJSONLIZE_JSON_PASTE55(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51,  \
                                 v52, v53, v54)                                                                        \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE54(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54)
#define CPPJSONLIZE_JSON_PASTE56(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51,  \
                                 v52, v53, v54, v55)                                                                   \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE55(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55)
#define CPPJSONLIZE_JSON_PASTE57(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51,  \
                                 v52, v53, v54, v55, v56)                                                              \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE56(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, \
                             v56)
#define CPPJSONLIZE_JSON_PASTE58(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51,  \
                                 v52, v53, v54, v55, v56, v57)                                                         \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE57(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, \
                             v56, v57)
#define CPPJSONLIZE_JSON_PASTE59(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51,  \
                                 v52, v53, v54, v55, v56, v57, v58)                                                    \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE58(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, \
                             v56, v57, v58)
#define CPPJSONLIZE_JSON_PASTE60(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51,  \
                                 v52, v53, v54, v55, v56, v57, v58, v59)                                               \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE59(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, \
                             v56, v57, v58, v59)
#define CPPJSONLIZE_JSON_PASTE61(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51,  \
                                 v52, v53, v54, v55, v56, v57, v58, v59, v60)                                          \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE60(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, \
                             v56, v57, v58, v59, v60)
#define CPPJSONLIZE_JSON_PASTE62(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51,  \
                                 v52, v53, v54, v55, v56, v57, v58, v59, v60, v61)                                     \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE61(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, \
                             v56, v57, v58, v59, v60, v61)
#define CPPJSONLIZE_JSON_PASTE63(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51,  \
                                 v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62)                                \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE62(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, \
                             v56, v57, v58, v59, v60, v61, v62)
#define CPPJSONLIZE_JSON_PASTE64(func, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17,     \
                                 v18, v19, v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34,  \
                                 v35, v36, v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51,  \
                                 v52, v53, v54, v55, v56, v57, v58, v59, v60, v61, v62, v63)                           \
    CPPJSONLIZE_JSON_PASTE2(func, v1)                                                                                  \
    CPPJSONLIZE_JSON_PASTE63(func, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15, v16, v17, v18, v19,   \
                             v20, v21, v22, v23, v24, v25, v26, v27, v28, v29, v30, v31, v32, v33, v34, v35, v36, v37, \
                             v38, v39, v40, v41, v42, v43, v44, v45, v46, v47, v48, v49, v50, v51, v52, v53, v54, v55, \
                             v56, v57, v58, v59, v60, v61, v62, v63)

#define CPPJSONLIZE_JSON_TO(v1) nlohmann_json_j[#v1] = nlohmann_json_t.v1;
#define CPPJSONLIZE_JSON_FROM(v1) nlohmann_json_j.at(#v1).get_to(nlohmann_json_t.v1);
#define CPPJSONLIZE_JSON_FROM_WITH_DEFAULT(v1)                                                                         \
    nlohmann_json_t.v1 = nlohmann_json_j.value(#v1, nlohmann_json_default_obj.v1);

#define CPPJSONLIZE_DEFINE_TYPE_INTRUSIVE(name, seq)                                                                   \
    friend void to_json(nlohmann::json &nlohmann_json_j, const Type &nlohmann_json_t)                                  \
    {                                                                                                                  \
        CPPJSONLIZE_JSON_EXPAND(CPPJSONLIZE_JSON_PASTE(CPPJSONLIZE_JSON_TO, __VA_ARGS__))                              \
    }                                                                                                                  \

#define CPPJSONLIZE_JSON_FROM_impl_end(...) CURVE_REGISTRY_impl_end_(__VA_ARGS__)
#define CPPJSONLIZE_JSON_FROM_impl_end_(...) __VA_ARGS__##_end

#define CPPJSONLIZE_JSON_FROM_impl_decl_loop(type, name, dftvalue) .Regist(name, type(dftvalue))
#define CPPJSONLIZE_JSON_FROM_impl_decl_loop_a(...)                                                                    \
    CPPJSONLIZE_JSON_FROM_impl_decl_loop(__VA_ARGS__) CPPJSONLIZE_JSON_FROM_impl_decl_loop_b
#define CPPJSONLIZE_JSON_FROM_impl_decl_loop_b(...)                                                                    \
    CPPJSONLIZE_JSON_FROM_impl_decl_loop(__VA_ARGS__) CPPJSONLIZE_JSON_FROM_impl_decl_loop_a
#define CPPJSONLIZE_JSON_FROM_impl_decl_loop_a_end
#define CPPJSONLIZE_JSON_FROM_impl_decl_loop_b_end
