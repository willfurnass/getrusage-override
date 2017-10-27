# Overriding functions in shared libraries

This can be done using `LD_PRELOAD`.

As an example, first run:

```sh
make all
```

then

```
./test
```

then

```
LD_PRELOAD=$PWD/liboverride.so ./test
```
