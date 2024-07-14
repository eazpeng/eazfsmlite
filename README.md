# eazfsmlite

1. 提供一个单片机可用的、轻量级无OS裸奔的 ***`事件驱动型状态机`*** 方案，通过回调的方式，将同一状态机的不同状态分离到各自独立的文件中去，支持多个状态机，耦合相对较小，且支持状态列表重排。
2. 支持多种按键事件：按下、抬起、单击（抬起响应）、长按、计时长按、长按抬起、连击等。
3. 提供一个模拟计时器。