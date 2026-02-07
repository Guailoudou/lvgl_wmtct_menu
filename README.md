# 万民堂点菜系统
## 技术概览

万民堂点菜系统（Wanmin Hall Ordering System）是基于 LVGL 8.3.11 的嵌入式点菜应用，面向 Android/ARM64 信息亭设备，采用 4 层架构（UI/事件/业务/数据），支持匿名/顾客/管理员三种角色，实现菜单浏览、购物车、结账、用户管理与库存补货功能。

设计灵感来源于游戏原神

---

## 1. 系统架构

- **UI 层**：由 SquareLine Studio 1.4.2 生成的 LVGL 屏幕（HelloView、LoginView、MenuView、AdminView），初始化函数为 `ui_*_screen_init()`，事件通过 `lv_obj_add_event_cb` 绑定。
- **事件层**：`login_view_event.c`、`meun_view_event.c`、`admin_view_event.c` 负责提取 UI 输入并调用业务 API，例如 `viewAddChopp` 调用 `addChoppBoard`。
- **业务层**：`LoginApi.c` 与 `OrderDishesApi.c` 实现认证、菜单过滤、购物车与库存逻辑，操作全局链表并持久化到文本文件 。
- **数据层**：基于 Linux 内核 `list_head` 的双向循环链表（`userhead`、`dishesHead`），文件存储为 `userInfo.txt` 与 `dishesInfo.txt` 。


---

### 2. 核心数据模型

- `userInfo`：uid、name、password、type（权限等级）。
- `dishesItem`：uid、imgPath、name、peice、type、inventory 。
- `ChoppBoard`：购物车，最多 1024 条 `ChoppItem`（dishesUids + num）。
- 全局变量：`loginUser`（当前会话）、`board`（购物车）、`menuData[8]`（分页缓冲）、`inventoryBoard[1024]`（库存缓存）。

---

### 3. 权限与访问控制

- 角色分级：封禁（-1）、匿名（0）、普通（1）、VIP（2）、管理员（3+）。
- 菜单可见性：`getMenuList` 仅返回 `dish.type <= loginUser.type` 的菜品 。
- 库存约束：普通用户受 `inventoryBoard` 限制，管理员可补货 。
- UI 可控性：管理员按钮仅在 `loginUser.type >= 3` 时显示。

---

### 4. UI 与事件流程

- 启动：`ui_HelloView`（8.6s 动画）→ `ui_LoginView` 。
- 登录/注册：`login_ac_ev`/`reg_ac_ev` 调用 `loginMenu`/`regMenu`，成功后跳转 `ui_MenuView` 。
- 菜单页：`viewMenuInit` 调用 `getMenuList` 填充 `menuData[8]`，`initMeun` 渲染 8 个菜品项；
    点击商品触发 `viewAddChopp` 修改购物车并刷新账单面板。
    长按商品触发 `viewAddInfo` 修改详细信息页数据并展示。

- 结账：`checkoutChopp` 调用 `checkout` 扣库存并生成收据消息框 。
- 管理页：`viewAdminInit` 加载用户列表，支持修改用户类型与删除。

---

### 5. 数据持久化

- 文件格式：`userInfo.txt`（uid name password type）；`dishesInfo.txt`（uid imgPath name price type inventory description）。
- 读写封装：`openfile`/`closefile` 包装 `fopen`/`fclose` 。
- 预加载：`readtxt` 在播放启动加载时从文件加载；`writetxt` 在变更后立即序列化。

---

### 6. 关键业务逻辑示例

- 菜单分页过滤：`getMenuList` 计算总页数，按权限过滤并填充 `menuData[8]` 与 `inventoryBoard`。
- 购物车增减：`addChoppBoard` 检查库存（普通用户）并更新 `board`；`rmChoppBoard` 从数组中移除条目。
- 结账扣库存：`checkout` 遍历 `board`，在 `dishesHead` 链表中扣减对应 `inventory` 并调用 `writetxt` 持久化。

---

### Notes

- 全局状态（如 `loginUser`、`board`）为单线程设计，不支持并发访问。
- 购物车与库存缓存上限为 1024 条；菜单分页固定为 8 项/页。
- 文件 I/O 为同步操作，大数据量时可能影响 UI 流畅性。
- 管理员功能（补货、用户管理）仅对 type≥3 开放，普通用户不可见。
- 运行需要放入lvgl，本仓库不包含lvgl内容
- 运行前，需要先放入数据文件，`exampleData`为样例，同时需要根据配置修改部分头文件中的路径





## lvgl部分

### LVGL for frame buffer device

LVGL configured to work with `/dev/fb0` on Linux, however it can be changed in [`lv_drv_conf.h`](https://github.com/lvgl/lv_port_linux_frame_buffer/blob/master/lv_drv_conf.h) by `FBDEV_PATH`.

When cloning this repository, also make sure to download submodules (`git submodule update --init --recursive`) otherwise you will be missing key components.

Check out this blog post for a step by step tutorial:
https://blog.lvgl.io/2018-01-03/linux_fb

#### Clone the project

Clone the LVGL Framebuffer Demo project and its related sub modules:

```
git clone https://github.com/lvgl/lv_port_linux_frame_buffer.git
cd lv_port_linux_frame_buffer/
git submodule update --init --recursive
```

#### Build the project

```
make
sudo make install
```

#### Run the demo application

```
demo
```
