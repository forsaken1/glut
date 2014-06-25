## Установка

```
sudo apt-get install freeglut3 freeglut3-dev libglew1.5 libglew1.5-dev libglu1-mesa libglu1-mesa-dev libgl1-mesa-glx libgl1-mesa-dev mesa-common-dev
```

## Запуск

```
gcc source.cpp -lglut -lGL -lGLU -lGLEW
```

```
g++ test.cpp -std=c++11
```

## Assimp

```
git clone git://github.com/assimp/assimp.git assimp

sudo apt-get install libassimp-dev
```