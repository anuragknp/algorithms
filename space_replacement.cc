#include <stdio.h>
#include <string.h>

bool encode_space(char *str, int len, int true_len) {
  if (str == NULL || len == 0 || true_len == 0 || true_len > len) return false;
  int i = len - 1;
  int j = true_len - 1;
  while(j >= 0) {
    if (str[j] != ' ') {
      str[i--] = str[j--];
    } else {
      str[i--] = '0';
      str[i--] = '2';
      str[i--] = '%';
      j--;
    }
  }
}

int main() {
  char str[] = "Mr John Smith    ";
  encode_space(str, strlen(str), 13);
  printf("%s", str);
  return 1;
}
