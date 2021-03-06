# Git使用
[官方教程](https://www.git-scm.com/book/en/v2)
# 导航
- [x] [安装 Git](#安装-Git)
  - [x] [为 Windows 安装Git](#为-Windows-安装Git)
  - [x] [为 Linux/Unix 安装Git](#为-Linux/Unix-安装Git)
  - [x] [为 MacOS 安装Git](#为-MacOS-安装Git)
- [x] [Create a new repository](#Create-a-new-repository)
- [x] [Push an existing repository](#Push-an-existing-repository)
- [x] [Git 基础](#Git-基础)



# 安装 Git
## 为 Windows 安装Git
Git的 [下载链接](https://git-scm.com/downloads)

- 选择`VScode`作为默认代码编辑器：`USe Visual Studio Code as Git's default editor`
![choose default editor](./img/choose_default_editor.png)

检查`Git`的版本号
```bash
$ git --version
git version 2.29.2.windows.2
```
出现上述结果则Git安装成功

## 为 Linux/Unix 安装Git
### Debian/Ubuntu
对于`Debian/Ubuntu`的发行版本，可以利用apt包管理进行安装
```bash
$ apt-get install git-all
```
如果使用的是`Ubuntu`，还需要添加PPA软件源到Ubuntu系统当中，添加了PPA之后，软件可以直接在软件中心进行安装并会自动提示升级
```bash
$ add-apt-repository ppa:git-core/ppa 
$ apt update
$ apt install git-all
```
### 其他Linux的发行版本
其他Linux发行版本遵照[链接的步骤](https://git-scm.com/download/linux)进行安装

## 为 MacOS 安装Git
[https://git-scm.com/download/mac](https://git-scm.com/download/mac)

>:stuck_out_tongue_closed_eyes: 返回[目录](#目录)浏览其他内容



# Create a new repository
## Set your account's default identity
configrate your identity
```bash
git config --global user.email "you@example.com"
git config --global user.name "Your Name"
```
check your configration
```bash
$ git config user.name
Your Name
$ git config user.email
you@example.com
```

# 初次运行 Git 前的配置: git config
### 位置
Git 自带一个 git config 的工具来帮助设置控制 Git 外观和行为的配置变量。 
你可以通过以下命令查看所有的配置以及它们所在的文件：
```bash
git config --list --show-origin
```

### Linux/Unix
这些变量存储在三个不同的位置：
- /etc/gitconfig 文件: 包含系统上每一个用户及他们仓库的通用配置。 如果在执行 git config 时带上 --system 选项，那么它就会读写该文件中的配置变量。 （由于它是系统配置文件，因此你需要管理员或超级用户权限来修改它。）
- ~/.gitconfig 或 ~/.config/git/config 文件：只针对当前用户。 你可以传递 --global 选项让 Git 读写此文件，这会对你系统上 所有 的仓库生效。
- 当前使用仓库的 Git 目录中的 config 文件（即 .git/config）：针对该仓库。 你可以传递 --local 选项让 Git 强制读写此文件，虽然默认情况下用的就是它。。 （当然，你需要进入某个 Git 仓库中才能让该选项生效。）

每一个级别会覆盖上一级别的配置，所以 .git/config 的配置变量会覆盖 /etc/gitconfig 中的配置变量。
### Windows
在 Windows 系统中，Git 会查找 $HOME 目录下（一般情况下是 C:\Users\$USER ）的 .gitconfig 文件。 Git 同样也会寻找 /etc/gitconfig 文件，但只限于 MSys 的根目录下，即安装 Git 时所选的目标位置。 如果你在 Windows 上使用 Git 2.x 以后的版本，那么还有一个系统级的配置文件，Windows XP 上在 C:\Documents and Settings\All Users\Application Data\Git\config ，Windows Vista 及更新的版本在 C:\ProgramData\Git\config 。此文件只能以管理员权限通过 git config -f <file> 来修改。



## 用户信息
安装完 Git 之后，要做的第一件事就是设置你的用户名和邮件地址。 这一点很重要，因为每一个 Git 提交都会使用这些信息，它们会写入到你的每一次提交中，不可更改：
```bash
git config --global user.name "John Doe"
git config --global user.email johndoe@example.com
```
再次强调，如果使用了 --global 选项，那么该命令只需要运行一次，因为之后无论你在该系统上做任何事情， Git 都会使用那些信息。 当你想针对特定项目使用不同的用户名称与邮件地址时，可以在那个项目目录下运行没有 --global 选项的命令来配置。

很多 GUI 工具都会在第一次运行时帮助你配置这些信息。


## 检查配置信息
如果想要检查你的配置，可以使用 ```git config --list``` 命令来列出所有 Git 当时能找到的配置。
```bash
git config --list
```

你可能会看到重复的变量名，因为 Git 会从不同的文件中读取同一个配置（例如：/etc/gitconfig 与 ~/.gitconfig）。 这种情况下，Git 会使用它找到的每一个变量的最后一个配置。

你可以通过输入 git config <key>： 来检查 Git 的某一项配置，例如；
```bash
git config user.name
```

# 获取帮助
若你使用 Git 时需要获取帮助，有三种等价的方法可以找到 Git 命令的综合手册（manpage）：
```bash
git help <verb>
git <verb> --help
man git-<verb>
```

例如，要想获得 git config 命令的手册，执行
```bash
git help config
```

此外，如果你不需要全面的手册，只需要可用选项的快速参考，那么可以用 -h 选项获得更简明的 “help” 输出：
```bash
git add -h
```
```bash
usage: git add [<options>] [--] <pathspec>...

    -n, --dry-run         dry run
    -v, --verbose         be verbose

    -i, --interactive     interactive picking
    -p, --patch           select hunks interactively
    -e, --edit            edit current diff and apply
    -f, --force           allow adding otherwise ignored files
    -u, --update          update tracked files
    --renormalize         renormalize EOL of tracked files (implies -u)
    -N, --intent-to-add   record only the fact that the path will be added later
    -A, --all             add changes from all tracked and untracked files
    --ignore-removal      ignore paths removed in the working tree (same as --no-all)
    --refresh             don't add, only refresh the index
    --ignore-errors       just skip files which cannot be added because of errors
    --ignore-missing      check if - even missing - files are ignored in dry run
    --chmod (+|-)x        override the executable bit of the listed files
```


# Git 基础
## 获取 Git 仓库

>Git 的各种基本命令：配置并初始化一个仓库（repository）、开始或停止跟踪（track）文件、暂存（stage）或提交（commit）更改,如何配置 Git 来忽略指定的文件和文件模式、如何迅速而简单地撤销错误操作、如何浏览你的项目的历史版本以及不同提交（commits）之间的差异、如何向你的远程仓库推送（push）以及如何从你的远程仓库拉取（pull）文件。

通常有两种获取 Git 项目仓库的方式：
- 将尚未进行版本控制的本地目录转换为 Git 仓库
- 从其它服务器**克隆**(**clone**)一个已存在的 Git 仓库

### 在已存在目录中初始化仓库
如果你有一个尚未进行版本控制的项目目录，想要用 Git 来控制它，那么首先需要进入该项目目录中。
```bash
cd {PATH}/my_project

# 初始化仓库
git init
```

该命令将创建一个名为 `.git` 的子目录，这个子目录含有你初始化的 Git 仓库中所有的必须文件，这些文件是 Git 仓库的骨干。


如果在一个已存在文件的文件夹（而非空文件夹）中进行版本控制，你应该开始追踪这些文件并进行初始提交。 可以通过 `git add` 命令来指定所需的文件来进行追踪，然后执行 `git commit` ：
```bash
git add *.c
git add LICENSE
git commit -m 'initial project version'
```


### 克隆现有的仓库
克隆仓库的命令是 
```bash
git clone <url>
```
当你执行 `git clone` 命令的时候，默认配置下远程 Git 仓库中的每一个文件的每一个版本都将被拉取下来。

比如，要克隆 `microsoft/vscode` 源码，可以用下面的命令：
```bash
git clone https://github.com/microsoft/vscode.git
```
当前目录下会出现一个 `vscode` 目录，初始化一个 `.git` 文件夹，从远程仓库拉取下所有数据放入 `.git` 文件夹，然后从中读取最新版本的文件的拷贝。

如果你想在克隆远程仓库的时候，自定义本地仓库的名字，你可以通过额外的参数指定新的目录名：
```bash
git clone https://github.com/microsoft/vscode.git vscode-source
```
这会执行与上一条命令相同的操作，但目标目录名变为了 `vscode-source`


## 记录每次更新到仓库

工作目录下的每一个文件都不外乎这两种状态：**已跟踪** 或 **未跟踪**。

- **已跟踪的文件**是指那些被纳入了版本控制的文件，在上一次快照中有它们的记录，在工作一段时间后， 它们的状态可能是未修改，已修改或已放入暂存区。
简而言之，已跟踪的文件就是 Git 已经知道的文件。

- 工作目录中除已跟踪文件外的其它所有文件都属于**未跟踪文件**，它们既不存在于上次快照的记录中，也没有被放入暂存区。 初次克隆某个仓库的时候，工作目录中的所有文件都属于已跟踪文件，并处于未修改状态，因为 Git 刚刚检出了它们， 而你尚未编辑过它们。

- 编辑过某些文件之后，由于自上次提交后你对它们做了修改，Git 将它们标记为**已修改文件**。 在工作时，你可以选择性地将这些修改过的文件放入暂存区，然后提交所有已暂存的修改，如此反复。

![文件的状态变化周期](./img/lifecycle.png)

### 检查当前文件状态
可以用 `git status` 命令查看哪些文件处于什么状态。 如果在克隆仓库后立即使用此命令，会看到类似这样的输出：
```bash
git status
```

```bash
On branch main
Your branch is up to date with 'origin/main'.
```
该输出还显示了当前所在分支，并告诉你这个分支同远程服务器上对应的分支没有偏离，其余附加输出如下：
```bash
nothing to commit, working directory clean
```
上面的结果表面，你现在的工作目录相当干净。换句话说，所有已跟踪文件在上次提交后都未被更改过。 此外，上面的信息还表明，当前目录下没有出现任何处于未跟踪状态的新文件，否则 Git 会在这里列出来。

```bash
Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   README.md
```
只要在 `Changes to be committed` 这行下面的，就说明是**已暂存状态**。 

```bash
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   docs/git/git_cn.md
        modified:   docs/linux/wsl2.md
```
`Changes not staged for commit`下的文件是**已跟踪文件**，已跟踪文件的内容发生了变化，但还没有放到暂存区。 要暂存这次更新，需要运行 git add 命令。 

```bash
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        docs/git/img/lifecycle.png
```
**Untracked files**的**未跟踪文件**意味着 Git 在之前的快照（提交）中没有这些文件；Git 不会自动将之纳入跟踪范围

```bash
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)
    new file:   README.md

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)
    modified:   README.md
```
`README.md` 文件同时出现在暂存区和非暂存区。

实际上 Git 只不过暂存了你运行 git add 命令时的版本。
<br>如果你现在提交，`README.md` 的版本是你最后一次运行 git add 命令时的那个版本，而不是你运行 git commit 时，在工作目录中的当前版本。 

所以，运行了 git add 之后又作了修订的文件，需要重新运行 git add 把最新版本重新暂存起来

### 状态简览
``git status`` 命令的输出十分详细，但其用语有些繁琐。 Git 有一个选项可以帮你缩短状态命令的输出，这样可以以简洁的方式查看更改。 如果你使用 ``git status -s`` 命令或 ``git status --short`` 命令，你将得到一种格式更为紧凑的输出。
```bash
$ git status -s
 M README.md
MM Rakefile
A  lib/git.rb
M  lib/simplegit.rb
?? LICENSE.txt
```
新添加的未跟踪文件前面有 ?? 标记，新添加到暂存区中的文件前面有 A 标记，修改过的文件前面有 M 标记。 

输出中有两栏，左栏指明了暂存区的状态，右栏指明了工作区的状态。

例如，上面的状态报告显示： 
- `README.md` 文件在工作区已修改但尚未暂存
- `Rakefile` 文件已修，暂存后又作了修改，因此该文件的修改中既有已暂存的部分，又有未暂存的部分。
- `lib/git.rb` 文件新添加到暂存区中
- `lib/simplegit.rb` 文件已修改且已暂存
- `LICENSE.txt` 是新添加的未跟踪文件



### 跟踪新文件
开始跟踪一个文件或目录的命令：
```bash
git add <file>/<dir>
```

所以，要跟踪 `README.md` 文件，运行：
```bash
git add README.md
```

### 暂存已修改的文件
现在我们来修改一个已被跟踪的文件。 如果你修改了一个名为 CONTRIBUTING.md 的已被跟踪的文件，然后运行 git status 命令，会看到下面内容：
```bash
git status
```
```bash
On branch master
Your branch is up-to-date with 'origin/master'.
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

    new file:   README.md

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

    modified:   CONTRIBUTING.md
```

### 忽略文件
`.gitignore`文件里面包含了忽略文件的规则

文件 .gitignore 的格式规范如下：
- 所有空行或者以 # 开头的行都会被 Git 忽略。
- 可以使用标准的 glob 模式匹配，它会递归地应用在整个工作区中。
- 匹配模式可以以（/）开头防止递归。
- 匹配模式可以以（/）结尾指定目录。
- 要忽略指定模式以外的文件或目录，可以在模式前加上叹号（!）取反。

```bash
# 忽略所有的 .a 文件
*.a

# 但跟踪所有的 lib.a，即便你在前面忽略了 .a 文件
!lib.a

# 只忽略当前目录下的 TODO 文件，而不忽略 subdir/TODO
/TODO

# 忽略任何目录下名为 build 的文件夹
build/

# 忽略 doc/notes.txt，但不忽略 doc/server/arch.txt
doc/*.txt

# 忽略 doc/ 目录及其所有子目录下的 .pdf 文件
doc/**/*.pdf
```


### 查看已暂存和未暂存的修改


https://www.git-scm.com/book/zh/v2/Git-%E5%9F%BA%E7%A1%80-%E8%AE%B0%E5%BD%95%E6%AF%8F%E6%AC%A1%E6%9B%B4%E6%96%B0%E5%88%B0%E4%BB%93%E5%BA%93