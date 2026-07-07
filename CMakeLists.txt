cmake_minimum_required(VERSION 4.2)
project(graphics_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(graphics_project main.cpp
        vec3.h
        color.h
        ray.h
        hittable.h
        sphere.h
        hittable_list.h
        rtweekend.h
        interval.h
        camera.h
        material.h)
