#
# Makefile
#
CC 				= aarch64-linux-gcc
LVGL_DIR_NAME 	?= lvgl
LVGL_DIR 		?= .

# WARNINGS		:= -Wall -Wshadow -Wundef -Wmissing-prototypes -Wno-discarded-qualifiers -Wall -Wextra -Wno-unused-function -Wno-error=strict-prototypes -Wpointer-arith \
# 					-fno-strict-aliasing -Wno-error=cpp -Wuninitialized -Wmaybe-uninitialized -Wno-unused-parameter -Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess \
# 					-Wno-format-nonliteral -Wno-cast-qual -Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar -Wformat-security -Wno-ignored-qualifiers -Wno-error=pedantic \
# 					-Wno-sign-compare -Wno-error=missing-prototypes -Wdouble-promotion -Wclobbered -Wdeprecated -Wempty-body -Wtype-limits -Wshift-negative-value -Wstack-usage=2048 \
# 					-Wno-unused-value -Wno-unused-parameter -Wno-missing-field-initializers -Wuninitialized -Wmaybe-uninitialized -Wall -Wextra -Wno-unused-parameter \
# 					-Wno-missing-field-initializers -Wtype-limits -Wsizeof-pointer-memaccess -Wno-format-nonliteral -Wpointer-arith -Wno-cast-qual -Wmissing-prototypes \
# 					-Wunreachable-code -Wno-switch-default -Wreturn-type -Wmultichar -Wno-discarded-qualifiers -Wformat-security -Wno-ignored-qualifiers -Wno-sign-compare -std=c99
WARNINGS		:= -Wall -std=c99 -std=gnu99
CFLAGS 			?= -O3 -g0 -I$(LVGL_DIR)/ $(WARNINGS)
LDFLAGS 		?= -lm
BIN 			= demo
SOBIN			= liblvgl.so
NFILEBIN		= libnfile.so
BUILD_DIR 		= ./build
BUILD_OBJ_DIR 	= $(BUILD_DIR)/obj
BUILD_OBJ_DIR_SO = $(BUILD_DIR)/obj
BUILD_BIN_DIR 	= $(BUILD_DIR)/bin

prefix 			?= /usr
bindir 			?= $(prefix)/bin
# 要动态编译的文件
#Collect the files to compile
MAINSRC = 		./main.c #./mywin.c
# MAINSRC += 		./work/login.c ./work/common.c ./work/loginapi.c ./work/reg.c
MAINSRC += 		$(LVGL_DIR)/UI/ui.c $(LVGL_DIR)/UI/ui_helpers.c $(LVGL_DIR)/UI/ui_events.c
MAINSRC += 		$(shell find $(LVGL_DIR)/UI/screens -name "*.c")
MAINSRC += 		$(shell find $(LVGL_DIR)/UI/components -name "*.c")
MAINSRC += 		$(shell find $(LVGL_DIR)/UI/images -name "*.c")
MAINSRC += 		$(shell find $(LVGL_DIR)/ui_events -name "*.c")

# nfileso 我的文件动态库 大的自定义文件  fileso
NSRCS 	+= 		$(shell find $(LVGL_DIR)/UI/fonts -name "*.c")
# NSRCS 	+= 		./ylnimg.c ./hmosfont.c
# lvglso lvgl动态库  lvglso
include $(LVGL_DIR)/lvgl/lvgl.mk
include $(LVGL_DIR)/lv_drivers/lv_drivers.mk
CSRCS 			+=$(LVGL_DIR)/mouse_cursor_icon.c 
# CSRCS 			+=./ylnimg.c ./hmosfont.c

OBJEXT 			?= .o

AOBJS 			= $(ASRCS:.S=$(OBJEXT))
COBJS 			= $(CSRCS:.c=$(OBJEXT))
NOBJS			= $(NSRCS:.c=$(OBJEXT))

MAINOBJ 		= $(MAINSRC:.c=$(OBJEXT))

SRCS 			= $(ASRCS) $(CSRCS) $(MAINSRC)
OBJS 			= $(ASRCS) $(CSRCS) $(MAINOBJ)
SRCSSO			= $(ASRCS) $(CSRCS)
OBJSSO			= $(AOBJS) $(COBJS) 
NOBJSSO			= $(AOBJS) $(NOBJS) 
TARGET 			= $(addprefix $(BUILD_OBJ_DIR)/, $(patsubst ./%, %, $(MAINOBJ))) # ./build/obj/ylnimg.o  ./build/obj/hmosfont.o

NTARGET_SO 		= $(addprefix $(BUILD_OBJ_DIR_SO)/, $(patsubst ./%, %, $(NOBJSSO)))
TARGET_SO 		= $(addprefix $(BUILD_OBJ_DIR_SO)/, $(patsubst ./%, %, $(OBJSSO)))
## MAINOBJ -> OBJFILES

all: default

$(BUILD_OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC)  $(CFLAGS) -c $< -o $@
	@echo "CC $<"

$(BUILD_OBJ_DIR_SO)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC)  $(CFLAGS) -c -fPIC $< -o $@
	@echo "CC $<"
    
default:$(TARGET)
	@mkdir -p $(dir $(BUILD_BIN_DIR)/)
	$(CC) -o $(BUILD_BIN_DIR)/$(BIN) $(TARGET) $(LDFLAGS) -L ./  -llvgl -lnfile
	cp $(BUILD_BIN_DIR)/$(BIN) ../../out/

lvglso: $(TARGET_SO)
	@mkdir -p $(dir $(BUILD_BIN_DIR)/)
	$(CC) -o $(BUILD_BIN_DIR)/$(SOBIN) $(TARGET_SO) $(LDFLAGS) -shared
	cp $(BUILD_BIN_DIR)/$(SOBIN) ../../out/
	cp $(BUILD_BIN_DIR)/$(SOBIN) .
	adb shell rm -f /lib/$(SOBIN)
	adb push /home/loudou/file/yue/out/$(SOBIN) /lib
fileso: $(NTARGET_SO)
	@mkdir -p $(dir $(BUILD_BIN_DIR)/)
	$(CC) -o $(BUILD_BIN_DIR)/$(NFILEBIN) $(NTARGET_SO) $(LDFLAGS) -shared
	cp $(BUILD_BIN_DIR)/$(NFILEBIN) ../../out/
	cp $(BUILD_BIN_DIR)/$(NFILEBIN) .
	adb shell rm -f /lib/$(NFILEBIN)
	adb push /home/loudou/file/yue/out/$(NFILEBIN) /lib
sendfile:
	adb push /home/loudou/file/yue/in/files /userdata/files
getUI:
	rm -rf UI
	cp -r /mnt/UI UI
run:
	adb shell rm -f /userdata/$(BIN)
	adb push /home/loudou/file/yue/out/$(BIN) /userdata
	adb shell chmod 766 /userdata/$(BIN)
	adb shell /userdata/$(BIN)
clean: 
	rm -rf $(BUILD_DIR)

install:
	install -d $(DESTDIR)$(bindir)
	install $(BUILD_BIN_DIR)/$(BIN) $(DESTDIR)$(bindir)

uninstall:
	$(RM) -r $(addprefix $(DESTDIR)$(bindir)/,$(BIN))
