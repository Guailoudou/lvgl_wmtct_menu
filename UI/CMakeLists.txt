SET(SOURCES screens/ui_Screen1.c
    screens/ui_Screen2.c
    screens/ui_Screen3.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_ylnimg_png.c
    fonts/ui_font_harmonyOS.c
    fonts/ui_font_harmonyOSTitle.c)

add_library(ui ${SOURCES})
