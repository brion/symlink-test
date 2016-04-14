# Test for symlinks on Win10 Linux subsystem

(Testing on Win10 insider build 14316)

Note that symlinks in /mnt/c don't work at all under lxss!
Check out the source under /home or /root.

```
# Make sure we have gcc etc
apt-get update && apt-get install build-essential

# Clone the source repo and build
git clone https://github.com/brion/symlink-test.git
cd symlink-test
make

# Test fstatat, readlinkat, readlink syscalls on a symlink
./test

# Test GNU tar on a symlink
bash test.sh
```

On real Linux, the readlinkat and readlink calls should both dereference
the symlink correctly as pointing to "hello.txt". Under Win10's lxss subsystem,
the readlink call works but readlinkat does not.

GNU tar uses readlinkat to deref symlinks, so fails to read them when creating
a tar from the local filesystem. It also fails to create them, possibly due to
a validity check also using readlinkat.

Note the difference between readlink and readlinkat syscalls is that readlinkat
allows you to specify the directory against which relative paths are dereferenced
for the filename parameter.
