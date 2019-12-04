cmake_minimum_required(VERSION 3.14)
project(fdf C)

set(CMAKE_C_STANDARD 11)


include_directories(mlx)
include_directories(sources)


add_executable(fdf
        sources/fdf.c
        sources/fdf.h
        sources/point_functions.c
        sources/parsing.c
        sources/drawing_lines.c
        sources/drawing_matrix.c
        sources/drawing_matrix.c sources/treatment_of_signals.c sources/work_with_angles.c sources/work_with_angle_consistent.c sources/keyboard.c sources/point_list_functions.c ft_printf/libft/ft_is_hex.c)

target_link_libraries(fdf ${CMAKE_SOURCE_DIR}/ft_printf/libftprintf.a)
target_link_libraries(fdf  ${CMAKE_SOURCE_DIR}/mlx/libmlx.a)
target_link_libraries(fdf "-framework AppKit")
target_link_libraries(fdf "-framework OpenGL")