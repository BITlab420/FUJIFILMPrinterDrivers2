// copyData  entry=100003a2b

/* copyData(unsigned char*, unsigned char*, short) -- copy param_3 bytes */

void copyData(uchar *param_1, uchar *param_2, short param_3)

{
  if (param_3 > 0) {
    memcpy(param_2, param_1, (size_t)param_3);
  }
}
