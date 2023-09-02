
cc_binary(
    name = "mytinyurl",
    srcs = ["main.cpp"],
    deps=[
        "@boost//:lambda",
        "@boost//:date_time",
    ]
)

cc_binary(
    name = "http_server_test",
    srcs = ["server_main.cpp"],
    deps = [
        "//lib/http/server:http_server",
    ]
)

cc_binary(
    name = "beast_server",
    srcs = ["beast_server.cpp"],
    deps=[
        "@boost//:beast",
        "@boost//:asio",
    ]
)
