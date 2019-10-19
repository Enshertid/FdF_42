cmake_minimum_required(VERSION 3.14)
project(FdF C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(FdF
        sources/fdf.c sources/one_line.c ft_printf/libft/ft_mod_num.c sources/parsing.c sources/list_functions.c)
target_link_libraries(FdF ${CMAKE_SOURCE_DIR}/ft_printf/libftprintf.a ${CMAKE_SOURCE_DIR}/mlx/libmlx.a)

target_link_libraries(FdF "libmlx.a")
target_link_libraries(FdF "-framework AppKit")
target_link_libraries(FdF "-framework OpenGL")