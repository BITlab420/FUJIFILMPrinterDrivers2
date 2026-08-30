// checkdriverduplexPage  entry=100007060

/* checkdriverduplexPage(sdata*) */

undefined2 checkdriverduplexPage(sdata *param_1)

{
  undefined2 uVar1;
  
  if ((((byte)param_1[0xb] & 1) == 0) || (uVar1 = 1, ((byte)param_1[0x12] & 1) == 0)) {
    uVar1 = 0;
  }
  return uVar1;
}

