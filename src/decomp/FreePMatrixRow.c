// FreePMatrixRow  entry=10000356e

/* FreePMatrixRow(short) */

undefined8 FreePMatrixRow(short param_1)

{
  if ((param_1 == 1) && (_pMatrixRow != (void *)0x0)) {
    _free(_pMatrixRow);
  }
  return 0;
}

