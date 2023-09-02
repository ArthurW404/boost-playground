cc_binary(
    name = "txtformat",
    srcs = ["main.cpp"],
    deps = [":libtxtformat"]
)

cc_library(
    name = "libtxtformat",
    srcs  = ["txtformat.cpp"],
    hdrs = ["txtformat.h"],
    visibility = ["//visibility:public"],
    deps = ["@boost//:property_tree"]
)
