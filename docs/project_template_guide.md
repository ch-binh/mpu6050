## 1. Useful GIT commands

| Fields    | cmds                                    | Explain                        |
| --------- | --------------------------------------- | ------------------------------ |
| Repo      | git clone <repo_url>                    | Clone the main repository      |
| Repo      | git pull                                | Update local repo with remote  |
| Repo      | git fetch                               | Fetch changes from remote      |
| Submodule | git submodule add <git_url> <path>      | Add a submodule to the project |
| Submodule | git submodule update --init --recursive | Init & update all submodules   |
| Submodule | git submodule status                    | Show submodule status          |
| Submodule | git submodule sync                      | Sync submodule URLs            |
| Submodule | git submodule foreach 'git pull'        | Update all submodules          |

### 1.1. Update submodules

In the project root directory, you will find [submodules list](../.gitmodules), I have included many useful repos:

| Submodules    | Functions                                                                 |
| ------------- | ------------------------------------------------------------------------- |
| advanced_math | An advanced math modules, including algorithm and controllers like PID... |
| file_template | Template files for c, python, etc.                                        |
| unity         | Unity unit test repo                                                      |

### 1.2. Git message


```console
git config commit.template ./.gitmessage
```