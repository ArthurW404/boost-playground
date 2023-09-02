cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":libxml2json"]
)

cc_binary(
    name = "server",
    srcs = ["server.cpp"],
    deps = [
        ":libxml2json", 
        "@boost//:asio"
    ]
)

cc_library(
    name = "libxml2json",
    srcs  = ["xml2json.cpp"],
    hdrs = ["xml2json.h"],
    visibility = ["//visibility:public"],
    deps = ["@boost//:property_tree"]
)
