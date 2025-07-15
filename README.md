# HnuSec 2025 Summer ☀️ 夏季培训网站

海南大学网络空间安全协会2025年夏季CTF培训官方网站。

## 📚 项目简介

本项目使用 MkDocs Material 主题搭建，为HnuSec协会的CTF培训提供在线文档支持。包含WEB、PWN、REV、CRY、MISC五个方向的培训内容。

## 🚀 快速开始

### 环境要求
- Python 3.7+
- pip

### 安装依赖
```bash
pip install -r requirements.txt
```

### 本地开发
```bash
# 启动本地服务器
mkdocs serve

# 构建静态文件
mkdocs build
```

### 部署
```bash
# 部署到GitHub Pages
mkdocs gh-deploy
```

## 📁 项目结构

```
HnuSec-Training-Website/
├── docs/                    # 文档目录
│   ├── index.md            # 主页
│   ├── web/               # Web方向
│   ├── pwn/               # Pwn方向
│   ├── crypto/            # Crypto方向
│   ├── reverse/           # Reverse方向
│   ├── misc/              # Misc方向
│   ├── archives/          # 培训归档
│   └── others/            # 其他资料
├── theme/                  # 自定义主题
├── mkdocs.yml             # MkDocs配置
└── requirements.txt        # Python依赖
```

## 🎯 培训方向

- **💻 Web方向**: Web安全、PHP漏洞、SSTI等
- **🕹️ Pwn方向**: 二进制安全、栈溢出、ROP等
- **🔑 Crypto方向**: 密码学、古典密码、现代密码等
- **👾 Reverse方向**: 逆向工程、安卓逆向、花指令等
- **🧩 Misc方向**: 杂项、隐写术、取证等

## 📚 培训归档

- [2025冬季培训](docs/archives/2025-winter/index.md)
- [2024夏季培训](docs/archives/2024-Sum/index.md)

## 🔗 相关链接

- [在线网站](https://hnusec-training.natro92.fun)
- [海南大学官网](https://www.hnusec.com)
- [GitHub仓库](https://github.com/natro92/HnuSec-Training-Website)

## 🤝 贡献

欢迎提交Issue和Pull Request来改进项目！

## 📧 联系我们

如有任何问题或建议，请通过以下方式联系我们：
- 邮箱：HnuSec@163.com
- GitHub：[HnuSec-Training-Website](https://github.com/natro92/HnuSec-Training-Website)

## 📄 许可证

本项目采用 MIT 许可证。

---

*最后更新时间: 2025年1月*
