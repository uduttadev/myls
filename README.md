# `myls`: A Simple (Re)creation of `ls`
`myls` is my personal attempt at recreating the UNIX `ls` command, which lists files and directories. This project is solely for learning purposes and helps me further my understanding of how the core functionality of `ls` might be implemented. 

## Installation
1. **Clone or download** this repository
2. **Compile the C program**

    ```bash
    gcc -o myls myls.c
    ```
3. **Add the directory** containing `myls` to your `PATH`. 
    ```bash
    export PATH="SHOME{PATH_TO_DIRECTORY}:$PATH"
    ```

## Usage
Once you have completed installation, and the directory is in your `PATH`, simply run 
```bash
myls
```
