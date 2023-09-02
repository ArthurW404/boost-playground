
# cc_library(
#     name = "http_server",
#     srcs = ["hello-greet.cc"],
#     hdrs = ["hello-greet.h"],
# )


cc_library(
    name = "http_server",
    srcs = glob(["*.cpp"]),
    hdrs = glob(["*.hpp"]),
    deps=[
        "@boost//:asio",
    ],
    visibility = ["//my-tiny-url:__pkg__"],
)
