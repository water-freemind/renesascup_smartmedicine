# renesascup_smartmedicine

基于 Renesas RA6M5 的智能药品管理/搬运控制项目。工程使用 FreeRTOS 管理 GUI 与运动控制任务，使用 LVGL 提供触摸屏界面，并通过 CANFD 驱动 ZDT 步进电机完成 X/Y/Z/夹爪四轴动作。

> 当前仓库面向 Renesas RA 平台开发。硬件联调必须使用与工程配置匹配的目标板、显示屏、触摸控制器、电机及 CANFD 总线设备；仅完成 CMake 构建不代表已经通过整机测试。

## 项目概览

| 项目 | 配置 |
| --- | --- |
| MCU | Renesas RA6M5，`R7FA6M5BF2CBG`，Cortex-M33 |
| FSP | Renesas Flexible Software Package 6.3.0 |
| RTOS | AWS FreeRTOS Kernel 11.1.0（FSP 6.3.0 集成版本） |
| 图形界面 | LVGL（源码随仓库维护），480 × 320，RGB565 |
| 触摸输入 | FT6336U，I²C，7-bit 地址 `0x38` |
| 电机通信 | CANFD，ZDT X/Y/Z/夹爪四个节点，标准 ID `0x0100`～`0x0400` |
| 构建系统 | CMake + Ninja + GNU Arm Embedded Toolchain |

具体引脚、时钟、外设实例、FreeRTOS 参数和中间件版本以根目录 `configuration.xml` 为准。

## 软件架构

```text
FreeRTOS
├── GUI_Thread_entry
│   └── LVGL 初始化、显示刷新、触摸输入、界面事件
└── Motor_thread_entry
    └── CANFD 初始化、电机使能/回零、动作消息队列、取药/存药流程

src/drive/  ── 硬件驱动：UART、CANFD/ZDT、SPI 显示、I²C 触摸、GPT
src/app/    ── 应用逻辑：LVGL、取药/存药、运动流程
src/UI/     ── GUI Guider 生成界面与自定义界面代码
ra_gen/     ── RASC/FSP 生成代码
ra_cfg/     ── RASC/FSP 配置数据
```

启动后的主要流程：GUI 任务初始化 UART、GPT、LVGL、显示和触摸驱动，再加载界面与事件；电机任务初始化 CANFD，使能四轴并执行回零。GUI 或串口接收到动作后，通过 FreeRTOS 队列通知电机任务，应用层按到位回调依次执行取药、夹取、搬运、释放和复位流程。

## 目录说明

| 路径 | 作用 |
| --- | --- |
| `src/app/` | 应用流程、LVGL 入口、ZDT 电机动作编排 |
| `src/drive/` | UART、CANFD/ZDT、显示、触摸和定时器驱动 |
| `src/UI/` | LVGL 配置、界面生成代码、事件和自定义代码 |
| `configuration.xml` | RASC 工程配置源文件 |
| `ra_gen/`、`ra_cfg/` | RASC/FSP 生成内容 |
| `cmake/` | GNU Arm 工具链、生成配置和源码清单 |
| `build/` | CMake 构建目录及输出文件，不应手工修改 |

## 构建环境

安装以下工具并确保命令可用：

- CMake 3.16.4 或更高版本
- Ninja
- GNU Arm Embedded Toolchain，包含 `arm-none-eabi-gcc`
- Renesas FSP/e² studio（需要重新生成 RASC 配置时使用）

`cmake/gcc.cmake` 要求 `ARM_TOOLCHAIN_PATH` 指向工具链的 **bin 目录**，例如 Windows 下的 `C:/Program Files (x86)/GNU Arm Embedded Toolchain/版本/bin`。路径不要包含未处理的空格。

## 命令行构建

在仓库根目录执行：

```powershell
cmake -S . -B build/Debug -G Ninja `
  -DCMAKE_TOOLCHAIN_FILE=cmake/gcc.cmake `
  -DARM_TOOLCHAIN_PATH="C:/path/to/arm-none-eabi/bin" `
  -DCMAKE_BUILD_TYPE=Debug

cmake --build build/Debug --parallel
```

如需清理当前构建目录，可删除 `build/Debug` 后重新执行上述配置命令；该目录属于生成产物，不要手工编辑其中的 `.cmake`、`.ninja`、目标文件或依赖文件。

## e² studio / RASC

使用 e² studio 打开或导入本工程时，以 `configuration.xml` 作为外设和组件配置源。修改引脚、时钟、外设实例、RTOS 或 FSP 组件后，应通过 RASC/FSP 重新生成 `ra_gen/`、`ra_cfg/` 及相关 CMake 文件，再进行完整构建。

不要直接修改 RASC 生成的文件来长期保存配置变更；否则下次生成可能覆盖手工修改。应用代码请优先放在 `src/app/`、`src/drive/` 和 `src/UI/custom/`。

## 开发约定

- 先确认 `configuration.xml` 中的 FSP 实例名称，再在驱动代码中引用对应的 `g_*` 实例。
- 中断回调只做快速的状态记录或信号通知，耗时动作放在 FreeRTOS 任务中执行。
- 修改 CANFD ID、脉冲换算、行程限制或回零顺序后，必须在无负载和限位保护条件下逐项验证。
- `src/UI/generated/` 等 GUI 生成内容可能被 GUI 工具覆盖；稳定的业务逻辑和自定义事件应放在自定义目录。
- 提交前至少完成一次干净配置和构建，并确认没有把本地构建产物、调试日志或密钥提交到仓库。

## 已知限制

- 本 README 不替代硬件接线图、机械行程标定表和电机驱动器参数表。
- 工具链路径由本机环境决定，仓库不携带编译器和 FSP 安装包。
- 当前仓库包含部分 FSP/LVGL 生成或第三方源码；升级 FSP/LVGL 时应单独评估兼容性并记录版本。

## 许可证

仓库当前未提供独立许可证文件。对外发布或复用前，请确认项目代码、FSP、FreeRTOS 和 LVGL 的许可边界。
