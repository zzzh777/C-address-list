# 通讯录管理系统（C语言实现）

**一个基于C语言的命令行通讯录管理系统，支持联系人信息的增删改查、显示和排序功能。**

---

## 📋 功能列表

1. **容量检查**  
   - 初始化时自动检测通讯录存储空间
   - 添加联系人前进行容量满额判断（最大100条）

2. **核心功能**  
   - 🆕 **添加联系人**  
     ```c
     void AddContact(contact* con);
     ```
   - ❌ **删除联系人**（按姓名检索）（尚未完成）  
     ```c
     void DelContact(contact* con);
     ```
   - 🔍 **查找联系人**（支持姓名/电话双重检索）  （尚未完成）
     ```c
     void SearchContact(contact* con);
     ```
   - ✏️ **修改联系人信息**  （尚未完成）
     ```c
     void ModifyContact(contact* con);
     ```
   - 📜 **显示所有联系人**（分页显示）  
     ```c
     void ShowContact(contact* con);
     ```
   - 🔃 **排序功能**  （尚未完成）
     ```c
     void SortContact(contact* con));
     ```
     支持按以下方式排序：
     - 姓名拼音升序
     - 电话号码升序
     - 添加时间降序

---

## 🛠 数据结构设计

  ```c
  //初始化全局最大变量
  #define MAX 100
  #define MAX_NAME 20
  #define MAX_SEX 10
  #define MAX_TEL 15
  #define MAX_ADDRACT 50
  
  //联系人结构体
  typedef struct PeoInfo
  {
  	char name[MAX_NAME];
  	int age;
  	char sex[MAX_SEX];
  	char tel[MAX_TEL];
  	char addract[MAX_ADDRACT];
  }PeoInfo;
  //通讯录结构体
  typedef struct contact
  {
  	PeoInfo data[100];
  	int size;
  }contact;
  
  ---

## 🚀 使用说明

  ### 编译运行
  #### 方案一：IDE直接运行
  1. 新建 `空项目` → 选择C++语言（兼容C语言）
  2. 添加 `contact.h` 和 `contact.c` 到源文件
  3. 右键项目 → 属性 → C/C++ → 所有选项 → `SDL检查` 设为 **否**
  4. 按 <kbd>Ctrl</kbd>+<kbd>F5</kbd> 运行（不调试）
  
  #### 方案二：开发者命令提示符
  ```bash
  # 生成解决方案
  cl /EHsc /W4 contact.c
  
  # 运行程序
  contact.exe
  
  ### 操作示例
  ```text
  ----------- Contact Management -----------
  1.ADD      2.DEL       3.SEARCH
  4.MODIFY   5.SHOW      6.SORT
  0.EXIT
  ------------------------------------------
  请选择: 1
  
  请输入姓名: 张三
  请输入电话: 13812345678
  请输入地址: 北京市海淀区
  --> 添加成功！
  ```
  
  ---

## ⚠️ 注意事项

1. **数据持久化**  
   - 当前版本采用运行时内存存储，退出后数据不保留
   - （进阶建议）可扩展文件存储功能

2. **容量限制**  
   - 系统默认最大存储 **100** 条联系人信息
   - 修改 `#define MAX 100` 可调整容量
  
---

## 📌 实现亮点

- **模块化设计**：每个功能独立函数实现
- **输入验证**：对电话号码进行格式校验（11位数字）(尚未完成)
- **用户友好**：彩色控制台输出提示
- **扩展性强**：预留文件操作接口(尚未完成)

```

**字体格式说明**：
1. 标题使用 `#` 分级
2. 关键功能使用 **加粗** 和 `🆕` 等表情符号突出
3. 代码块使用 ```c 标记
4. 重要提示使用 ⚠️ 符号
5. 参数说明使用 `灰色代码块`

> 提示：实际使用时需配套实现对应的.c文件代码逻辑，本README已包含主要函数声明和结构体设计

###操作示例

**修改说明**：
1. 增加Visual Studio专属配置指引，包含SDL检查关闭（避免C4996等警告）
2. 保留开发者命令提示符编译方式（需配置VS环境变量）
3. 使用键盘符号 <kbd> 标记快捷键更直观
4. 原功能示例部分无需修改

> 提示：如果使用社区版VS2022，步骤完全相同。若需更详细的配置截图说明，可在文档中添加screenshots文件夹存放配置流程图。
