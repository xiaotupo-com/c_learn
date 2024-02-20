

project(DEMOS)

include_directories(AFTER ${PROJECT_SOURCE_DIR}/inc)
aux_source_directory(src src_dir)

add_executable(${PROJECT_NAME} ${src_dir})