set(base_SRCS
    Condition.cc
    CountDownLatch.cc
    CurrentThread.cc
)

add_library(sth_base ${base_SRCS})
target_link_libraries(sth_base pthread rt)

install(TARGETS sth_base DESTINATION lib)

file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/sth/base)


