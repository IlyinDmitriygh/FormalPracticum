set(TARGET_NAME "prac_prog")
set(COVERAGE_NAME "cover")
set(COVERAGE_TARGET "cover-tests")
set(SOURCE_DIR_MAIN "${Prac1_SOURCE_DIR}")
set(SOURCES ${source-files})

message(INFO ${SOURCES})

set(TEST_SOURCES test.cpp)
run_coverage(
        "${TEST_SOURCES}"
        "${SOURCES}"
        "${COVERAGE_TARGET}"
        "${TARGET_NAME}"
        "${COVERAGE_NAME}"
)
