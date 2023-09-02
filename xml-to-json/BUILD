cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    deps = [":xml2json"]
)

cc_binary(
    name = "server",
    srcs = ["server.cpp"],
    deps = [
        ":xml2json", 
        "@boost//:asio"
    ]
)


cc_library(
    name = "xml2json",
    srcs  = ["xml2json.cpp"],
    hdrs = ["xml2json.h"],
    deps = ["@boost//:property_tree"]
)
