# Collaborative text editor

# План

1. Реализовать простое соединение клиент сервер;
2. Алгоритм;
3. Сделать интерфейс;

## Клиент-сервер

### Технологии

1. C++
2. gRPC
3. Cmake

### Материалы

TBD

### Что нужно продумать

1. Где и как хранить файлы?

### Текущее состояние

 Делаю UI

## Алгоритм 

### Технологии

1. C++
2. gRPC

### Материалы

1. [Статья про treeOPT](./notes/IgnatCEW02.pdf);
2. [Статья "Concurrency Control in Groupware Systems"](https://www.lri.fr/~mbl/ENS/CSCW/2012/papers/Ellis-SIGMOD89.pdf)

### Что нужно продумать 

### Текущее состояние

# Как собрать проект

1. На вашем компьютере должен быть установлен gRPC и Protobuf;
2. Далее надо выполнить следующие команды:
```console
mkdir -p cmake/build
cd cmake/build
cmake ../../service
make(-j)
```
3. Появятся файлы client и server которые можно запустить.
