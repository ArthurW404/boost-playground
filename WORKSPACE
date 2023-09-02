
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip"],
  strip_prefix = "googletest-f8d7d77c06936315286eb55f8de22cd23c188571",
)

# Boost
# Famous C++ library that has given rise to many new additions to the C++ Standard Library
# Makes @boost available for use: For example, add `@boost//:algorithm` to your deps.
# For more, see https://github.com/nelhage/rules_boost and https://www.boost.org
http_archive(
    name = "com_github_nelhage_rules_boost",

    # Replace the commit hash in both places (below) with the latest, rather than using the stale one here.
    # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
    url = "https://github.com/nelhage/rules_boost/archive/ba0632447cf46e43a74c4a8cbba1104e7c819bdf.tar.gz",
    strip_prefix = "rules_boost-ba0632447cf46e43a74c4a8cbba1104e7c819bdf",
    # When you first run this tool, it'll recommend a sha256 hash to put here with a message like: "DEBUG: Rule 'com_github_nelhage_rules_boost' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = ..."
    sha256 = "d611bd1c598e53d6d7c11c3e426c958e9af9f12816e42c697f93ad7cc2e9b94b"
)
load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()
