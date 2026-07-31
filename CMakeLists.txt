cmake_minimum_required(VERSION 3.16)
project(SigWatch)

# ============================================================
# C++17 STANDARDI
# ============================================================
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# ============================================================
# 🔥 MSVC ÖZEL AYARLARI (TÜMÜ)
# ============================================================
if(MSVC)
    # C++17 standardı
    add_compile_options(/std:c++17)
    # __cplusplus değerini düzelt
    add_compile_options(/Zc:__cplusplus)
    # Permissive- (C++ standartlarına uygun)
    add_compile_options(/permissive-)
    # Hata ayıklama bilgisi
    add_compile_options(/Zi)
    # Hata seviyesi
    add_compile_options(/W3)
    # Hataları engelleme
    add_compile_options(/wd4251)
    add_compile_options(/wd4275)
endif()

# ============================================================
# UI DOSYASININ ARANACAĞI KLASÖR
# ============================================================
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/forms)

# ============================================================
# QT6 BUL
# ============================================================
find_package(Qt6 REQUIRED COMPONENTS 
    Core 
    Widgets 
    Multimedia 
    MultimediaWidgets 
    Charts
)

# ============================================================
# KAYNAK DOSYALARI
# ============================================================
set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
)

set(HEADERS
    include/mainwindow.h
)

set(UI_FILES
    forms/mainwindow.ui
)

# ============================================================
# EXECUTABLE OLUŞTUR
# ============================================================
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UI_FILES}
)

# ============================================================
# INCLUDE PATH
# ============================================================
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/forms
)

# ============================================================
# QT KÜTÜPHANELERİNİ BAĞLA
# ============================================================
target_link_libraries(${PROJECT_NAME}
    Qt6::Core
    Qt6::Widgets
    Qt6::Multimedia
    Qt6::MultimediaWidgets
    Qt6::Charts
)

# ============================================================
# WINDOWS AYARLARI
# ============================================================
if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        WIN32_EXECUTABLE TRUE
    )
endif()

# ============================================================
# QT TANIMLAMALARI
# ============================================================
target_compile_definitions(${PROJECT_NAME} PRIVATE
    QT_DEPRECATED_WARNINGS
    QT_DISABLE_DEPRECATED_BEFORE=0x060000
    WIN32_LEAN_AND_MEAN
    NOMINMAX
)

message(STATUS "Qt6 version: ${Qt6_VERSION}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
