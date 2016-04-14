#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int cwd = open("testdir", O_RDONLY | O_DIRECTORY);
  struct stat st;
  int ret = fstatat(cwd, "symlink.txt", &st, AT_SYMLINK_NOFOLLOW);
  printf("fstat returned %d\n", ret);

  printf("st_dev %d\n", st.st_dev);
  printf("st_ino %d\n", st.st_ino);
  printf("st_mode %d\n", st.st_mode);
  printf("st_nlink %d\n", st.st_nlink);
  printf("st_uid %d\n", st.st_uid);
  printf("st_gid %d\n", st.st_gid);
  printf("st_rdev %d\n", st.st_rdev);
  printf("st_size %d\n", st.st_size);
  printf("st_blksize %d\n", st.st_blksize);
  printf("st_blocks %d\n", st.st_blocks);

  int bufmax = 1024;
  char *buf = (char *)malloc(bufmax);
  ssize_t len = readlinkat(cwd, "symlink.txt", buf, bufmax);
  printf("readlinkat returned len %d\n", (int)len);
  printf("readlinkat returned str %s\n", buf);

  return 0;
}
