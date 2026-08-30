// _convertSupplyLevel  entry=10000ab48

undefined8 _convertSupplyLevel(double param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if ((((0.0 < param_1) && (uVar1 = 10, DAT_1000104c8 <= param_1)) &&
      (uVar1 = 0x19, DAT_1000104d0 <= param_1)) &&
     (((uVar1 = 0x28, DAT_1000104d8 <= param_1 && (uVar1 = 0x37, DAT_1000104e0 <= param_1)) &&
      ((uVar1 = 0x46, DAT_1000104e8 <= param_1 && (uVar1 = 100, param_1 < DAT_1000104f0)))))) {
    uVar1 = 0x55;
  }
  return uVar1;
}

