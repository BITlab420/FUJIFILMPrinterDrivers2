// _determineStatus  entry=10000b828

/* WARNING: Type propagation algorithm not settling */

char * _determineStatus(ulong param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined **ppuVar4;
  ulong uVar5;
  char *pcVar6;
  
  pcVar6 = (char *)0x0;
  if ((long)param_1 < 0x9c4a) {
    if ((long)param_1 < 40000) {
      if ((long)param_1 < 0x7553) {
        if ((long)param_1 < 0x7540) {
          if ((long)param_1 < 0x2fa9) {
            if ((long)param_1 < 0x2727) {
              pcVar6 = (char *)0x0;
              if (((param_1 != 0x2711) && (pcVar6 = _kWaitMsg, param_1 != 0x2713)) &&
                 (pcVar6 = _kTonerLowMsg, param_1 != 0x2716)) {
LAB_10000b8fe:
                pcVar6 = _kTonerMissMsg;
                if (3 < param_1 - 0x9dd9) {
                  pcVar6 = _kPrinterLockMsg;
                  if ((long)param_1 < 0x114f4) {
                    if ((long)param_1 < 0x11364) {
                      if ((long)param_1 < 0x11314) {
                        if ((long)param_1 < 0x11300) {
                          if ((long)param_1 < 0x1129c) {
                            if ((long)param_1 < 0x11238) {
                              if ((long)param_1 < 0x111d4) {
                                if ((long)param_1 < 0x111a2) {
                                  if ((long)param_1 < 0x11171) {
                                    if ((long)param_1 < 0xfe28) {
                                      if ((long)param_1 < 0xfe08) {
                                        if (0x1b65 < (long)param_1) {
                                          if ((long)param_1 < 0xfdf8) {
                                            if ((long)param_1 < 0xfde9) {
                                              if ((long)param_1 < 0xfa02) {
                                                if ((long)param_1 < 0xeb0a) {
                                                  if ((long)param_1 < 0xeaee) {
                                                    if ((long)param_1 < 0xea7e) {
                                                      if ((long)param_1 < 0xea64) {
                                                        if ((long)param_1 < 0xc36e) {
                                                          if ((long)param_1 < 0xafee) {
                                                            if ((long)param_1 < 0xa154) {
                                                              if ((long)param_1 < 0xa0f0) {
                                                                if ((long)param_1 < 41000) {
                                                                  if ((long)param_1 < 0x9d75) {
                                                                    if ((long)param_1 < 0x9cb9) {
                                                                      if ((long)param_1 < 0x9c79) {
                                                                        if ((long)param_1 < 0x9c66)
                                                                        {
                                                                          if ((long)param_1 < 0x9c55
                                                                             ) {
                                                                            if ((long)param_1 <
                                                                                0x1edc) {
                                                                              if ((long)param_1 <
                                                                                  0x1d4c) {
                                                                                if ((long)param_1 <
                                                                                    0x1cfc) {
                                                                                  if ((long)param_1
                                                                                      < 0x1ce8) {
                                                                                    if ((long)
                                                  param_1 < 0x1c84) {
                                                    if ((long)param_1 < 0x1c20) {
                                                      pcVar6 = _kScanCoverOpenMsg;
                                                      if (((param_1 != 0x1b66) &&
                                                          (pcVar6 = _kMachineHotMsg,
                                                          param_1 != 0x1b6c)) &&
                                                         (pcVar6 = _kScanLockMsg, param_1 != 0x1bbc)
                                                         ) goto switchD_10000bdf8_caseD_eaf5;
                                                    }
                                                    else {
                                                      pcVar6 = _kCommErrorMsg;
                                                      if (param_1 != 0x1c20)
                                                      goto switchD_10000bdf8_caseD_eaf5;
                                                    }
                                                  }
                                                  else {
                                                    pcVar6 = _kPrintUnableMsg;
                                                    if (param_1 != 0x1c84)
                                                    goto switchD_10000bdf8_caseD_eaf5;
                                                  }
                                                  goto LAB_10000bfe9;
                                                  }
                                                  if (param_1 == 0x1ce8)
                                                  goto switchD_10000b9f6_caseD_11368;
                                                  }
                                                  else if (param_1 == 0x1cfc)
                                                  goto switchD_10000b9f6_caseD_11368;
                                                  }
                                                  else if (param_1 == 0x1d4c)
                                                  goto switchD_10000b9f6_caseD_11364;
                                                  }
                                                  else if (param_1 == 0x1edc) goto LAB_10000bfe9;
                                                  }
                                                  else {
                                                    pcVar6 = _kFrontCoverMsg;
                                                    if ((param_1 == 0x9c55) ||
                                                       (pcVar6 = _kPaperJamMsg, param_1 == 0x9c56))
                                                    goto LAB_10000bfe9;
                                                  }
                                                  }
                                                  else {
                                                    pcVar6 = _kTonerOutMsg;
                                                    if (param_1 == 0x9c66) goto LAB_10000bfe9;
                                                  }
                                                  }
                                                  else {
                                                    pcVar6 = _kServiceCallMsg;
                                                    if (param_1 == 0x9c79) goto LAB_10000bfe9;
                                                  }
                                                  }
                                                  else {
                                                    pcVar6 = _kDuplexMsg;
                                                    if (param_1 == 0x9cb9) goto LAB_10000bfe9;
                                                  }
                                                  }
                                                  else {
                                                    pcVar6 = _kTonerOutMsg;
                                                    if (param_1 - 0x9d75 < 4) goto LAB_10000bfe9;
                                                  }
                                                  }
                                                  else if (param_1 == 41000)
                                                  goto switchD_10000bdf8_caseD_eaf4;
                                                  }
                                                  else {
                                                    if (param_1 == 0xa0f0)
                                                    goto switchD_10000bdf8_caseD_eaf4;
                                                    pcVar6 = _kNoTrayMsg;
                                                    if (param_1 == 0xa0f1) goto LAB_10000bfe9;
                                                  }
                                                  goto switchD_10000bdf8_caseD_eaf5;
                                                  }
                                                  if (param_1 == 0xa154) {
switchD_10000bdf8_caseD_eaf4:
                                                    pcVar6 = _kPaperOutMsg;
                                                  }
                                                  else {
                                                    pcVar6 = _kNoTrayMsg;
                                                    if (param_1 != 0xa155)
                                                    goto switchD_10000bdf8_caseD_eaf5;
                                                  }
                                                  }
                                                  else {
                                                    pcVar6 = _kTonerOutMsg;
                                                    if (param_1 != 0xafee)
                                                    goto switchD_10000bdf8_caseD_eaf5;
                                                  }
                                                  }
                                                  else {
                                                    pcVar6 = _kServiceCallMsg;
                                                    if (param_1 != 0xc36e)
                                                    goto switchD_10000bdf8_caseD_eaf5;
                                                  }
                                                  }
                                                  else {
                                                    pcVar6 = _kServiceCallMsg;
                                                    if (param_1 != 0xea64)
                                                    goto switchD_10000bdf8_caseD_eaf5;
                                                  }
                                                  }
                                                  else {
                                                    pcVar6 = _kPrintMsg;
                                                    if (param_1 != 0xea7e)
                                                    goto switchD_10000bdf8_caseD_eaf5;
                                                  }
                                                  }
                                                  else {
                                                    if ((long)param_1 < 0xeaf4) {
                                                      if (param_1 == 0xeaee)
                                                      goto switchD_10000bad4_caseD_11175;
                                                      goto switchD_10000bdf8_caseD_eaf5;
                                                    }
                                                    switch(param_1) {
                                                    case 0xeaf4:
                                                      goto switchD_10000bdf8_caseD_eaf4;
                                                    default:
                                                      goto switchD_10000bdf8_caseD_eaf5;
                                                    case 0xeaf8:
                                                      pcVar6 = _kDeviceMsg;
                                                      break;
                                                    case 0xeaf9:
                                                      pcVar6 = _kRegistMsg;
                                                      break;
                                                    case 0xeafd:
                                                      pcVar6 = _kShortPaperMsg;
                                                      break;
                                                    case 0xeafe:
                                                      pcVar6 = _kSmallPaperMsg;
                                                      break;
                                                    case 0xeaff:
                                                      pcVar6 = _kCondensationMsg;
                                                    }
                                                  }
                                                }
                                                else {
                                                  pcVar6 = _kStorageMsg;
                                                  if (param_1 != 0xeb0a)
                                                  goto switchD_10000bdf8_caseD_eaf5;
                                                }
                                              }
                                              else {
                                                if (param_1 != 0xfa02) {
                                                  if (param_1 != 0xfa04)
                                                  goto switchD_10000bdf8_caseD_eaf5;
                                                  pcVar6 = _kBackCoverMsg;
                                                  if (_gModelInfo == 2) goto LAB_10000bfe9;
                                                }
                                                pcVar6 = _kCoverOpenMsg;
                                              }
                                            }
                                            else if ((7 < param_1 - 0xfde9) ||
                                                    (pcVar6 = _kPaperJamMsg,
                                                    (0x8bUL >> (param_1 - 0xfde9 & 0x3f) & 1) == 0))
                                            goto switchD_10000bdf8_caseD_eaf5;
                                          }
                                          else {
                                            pcVar6 = _kPaperJamMsg;
                                            if (param_1 != 0xfdf8)
                                            goto switchD_10000bdf8_caseD_eaf5;
                                          }
                                          goto LAB_10000bfe9;
                                        }
                                        if (param_1 == 0x1b5c) goto switchD_10000bad4_caseD_11174;
                                      }
                                      else {
                                        pcVar6 = _kPaperJamMsg;
                                        if (param_1 == 0xfe08) goto LAB_10000bfe9;
                                      }
                                    }
                                    else {
                                      pcVar6 = _kPaperJamMsg;
                                      if (param_1 == 0xfe28) goto LAB_10000bfe9;
                                    }
                                    goto switchD_10000bdf8_caseD_eaf5;
                                  }
                                  if ((long)param_1 < 0x11184) {
                                    if ((long)param_1 < 0x1117e) {
                                      switch(param_1) {
                                      case 0x11171:
                                        pcVar6 = _kJournalFullMsg;
                                        break;
                                      default:
                                        goto switchD_10000bdf8_caseD_eaf5;
                                      case 0x11174:
switchD_10000bad4_caseD_11174:
                                        pcVar6 = _kDocumentJamMsg;
                                        break;
                                      case 0x11175:
switchD_10000bad4_caseD_11175:
                                        pcVar6 = _kSizeMsg;
                                        break;
                                      case 0x11177:
                                        pcVar6 = _kWrongPaperMsg;
                                      }
                                    }
                                    else {
                                      pcVar6 = _kScanCoverOpenMsg;
                                      if (param_1 != 0x1117e) goto switchD_10000bdf8_caseD_eaf5;
                                    }
                                  }
                                  else {
                                    pcVar6 = _kMachineHotMsg;
                                    if (param_1 != 0x11184) goto switchD_10000bdf8_caseD_eaf5;
                                  }
                                }
                                else {
                                  switch(param_1) {
                                  case 0x111a2:
                                    pcVar6 = _kWasteNearFullMsg;
                                    break;
                                  case 0x111a3:
                                    pcVar6 = _kHighTemperMsg;
                                    break;
                                  case 0x111a4:
                                    pcVar6 = _kLowTemperMsg;
                                    break;
                                  case 0x111a5:
                                    pcVar6 = _kCartridgeMsg;
                                    break;
                                  case 0x111a6:
                                    pcVar6 = _kDiscGuideMsg;
                                    break;
                                  case 0x111a7:
                                  case 0x111ac:
                                    pcVar6 = _kCartridge2Msg;
                                    break;
                                  case 0x111a8:
                                    pcVar6 = _kVersionMsg;
                                    break;
                                  case 0x111a9:
                                    pcVar6 = _kCartridge3Msg;
                                    break;
                                  case 0x111aa:
                                    pcVar6 = _kCartridgeColorMsg;
                                    break;
                                  case 0x111ab:
                                    pcVar6 = _kCartridgeStrMsg;
                                    break;
                                  case 0x111ad:
                                    pcVar6 = _kCartridgeOldMsg;
                                    break;
                                  default:
                                    goto switchD_10000bdf8_caseD_eaf5;
                                  }
                                }
                              }
                              else {
                                pcVar6 = _kScanLockMsg;
                                if (param_1 != 0x111d4) goto switchD_10000bdf8_caseD_eaf5;
                              }
                            }
                            else {
                              pcVar6 = _kCommErrorMsg;
                              if (param_1 != 0x11238) goto switchD_10000bdf8_caseD_eaf5;
                            }
                          }
                          else {
                            pcVar6 = _kPrintUnableMsg;
                            if (param_1 != 0x1129c) goto switchD_10000bdf8_caseD_eaf5;
                          }
                          goto LAB_10000bfe9;
                        }
                        if (param_1 == 0x11300) goto switchD_10000b9f6_caseD_11368;
                      }
                      else if (param_1 == 0x11314) goto switchD_10000b9f6_caseD_11368;
switchD_10000bdf8_caseD_eaf5:
                      cVar2 = _isMessageAvailable(_kGenericMsg);
                      pcVar6 = (char *)0x0;
                      if (cVar2 != '\0') {
                        pcVar6 = _kGenericMsg;
                      }
                    }
                    else {
                      switch(param_1) {
                      case 0x11364:
switchD_10000b9f6_caseD_11364:
                        pcVar6 = _kInitUnableMsg;
                        if (_gModelInfo == 3) {
                          pcVar6 = _kWasteFullMsg;
                        }
                        break;
                      case 0x11365:
                        pcVar6 = _kE51Msg;
                        break;
                      case 0x11366:
                        pcVar6 = _kE52Msg;
                        break;
                      case 0x11367:
                        pcVar6 = _kE54Msg;
                        break;
                      case 0x11368:
switchD_10000b9f6_caseD_11368:
                        pcVar6 = _kScanUnableMsg;
                        break;
                      default:
                        goto switchD_10000bdf8_caseD_eaf5;
                      }
                    }
                  }
                  else if (param_1 != 0x114f4) goto switchD_10000bdf8_caseD_eaf5;
                }
              }
            }
            else if (param_1 != 0x2727) goto LAB_10000b8fe;
          }
          else {
            pcVar6 = _kNoTrayMsg;
            if (param_1 != 0x2fa9) goto LAB_10000b8fe;
          }
        }
        else {
          pcVar6 = _kMemoryOutMsg;
          if (param_1 != 0x7540) goto LAB_10000b8fe;
        }
      }
      else {
        pcVar6 = _kServiceCallMsg;
        if (param_1 != 0x7553) goto LAB_10000b8fe;
      }
    }
    else if (param_1 != 40000) goto LAB_10000b8fe;
  }
  else {
    pcVar6 = _kTonerMissMsg;
    if (param_1 != 0x9c4a) goto LAB_10000b8fe;
  }
LAB_10000bfe9:
  iVar1 = _gModelInfo;
  if (_gModelInfo == 0) {
    return pcVar6;
  }
  if (((pcVar6 != (char *)0x0) && (iVar3 = _strcmp(pcVar6,_kGenericMsg), iVar3 != 0)) &&
     ((iVar3 = _strcmp(pcVar6,_kPaperJamMsg), iVar3 != 0 &&
      ((iVar3 = _strcmp(pcVar6,_kPaperOutMsg), iVar3 != 0 &&
       (iVar3 = _strcmp(pcVar6,_kNoTrayMsg), iVar3 != 0)))))) {
    return pcVar6;
  }
  if (param_1 == 0x2711) {
    return pcVar6;
  }
  if (param_1 == 0x2727) {
    return pcVar6;
  }
  if (param_1 - 0x27dd < 4) {
    return _kDrumLowMsg;
  }
  if (param_1 - 0x27e1 < 4) {
    return _kTonerLowMsg;
  }
  if (param_1 == 0x27e7) {
    return _kBeltUnitLowMsg;
  }
  if (param_1 - 0x2841 < 4) {
    return _kDrumOutMsg;
  }
  if ((long)param_1 < 0x7541) {
    if ((long)param_1 < 0x2fa9) {
      if (param_1 == 0x284b) {
        return _kBeltUnitOutMsg;
      }
      if (param_1 == 0x284c) {
        return _kUnitOutMsg;
      }
    }
    else if ((long)param_1 < 0x3a99) {
      if (param_1 == 0x2fa9) {
        return _kNoTrayMsg;
      }
    }
    else if ((long)param_1 < 0x3aa3) {
      if (param_1 == 0x3a99) {
        return _kOutputBinFullMsg;
      }
    }
    else {
      if (param_1 == 0x3aa3) {
        return _kOutputBinFullMsg;
      }
      if (param_1 == 0x3aad) {
        return _kOutputBinFullMsg;
      }
      if (param_1 == 0x3aae) {
        return _kOptionalOutputFullMsg;
      }
    }
  }
  else if (param_1 == 0x7541) {
    return _kOverrunMsg;
  }
  if (param_1 - 0x88e0 < 10) {
    return _kResolutionMsg;
  }
  if ((long)param_1 < 0x9c5a) {
    if (param_1 == 40000) {
      return pcVar6;
    }
LAB_10000c254:
    if (param_1 - 0xa029 < 9) {
      return _kMPSizeMsg;
    }
    if (param_1 - 0xa08c < 100) {
      return _kManualSizeMsg;
    }
    if (param_1 == 0xa0f0) {
      cVar2 = _isMessageAvailable(_kScanUnableMsg);
      pcVar6 = _kTray1SizeMsg;
    }
    else {
      if (param_1 - 0xa0f1 < 99) {
        return _kTray1SizeMsg;
      }
      if (param_1 != 0xa154) {
        if (param_1 - 0xa155 < 99) {
          return _kTray2SizeMsg;
        }
        if (param_1 - 0xa1b8 < 100) {
          return _kTray3SizeMsg;
        }
        if (param_1 - 0xa21c < 100) {
          return _kTray4SizeMsg;
        }
        if ((long)param_1 < 0xac45) {
          switch(param_1) {
          case 0xa475:
            pcVar6 = _kA1JamMsg;
            break;
          case 0xa476:
            pcVar6 = _kA2JamMsg;
            break;
          case 0xa477:
            pcVar6 = _kBJamMsg;
            break;
          case 0xa478:
switchD_10000c34c_caseD_a478:
            pcVar6 = _kCJamMsg;
            break;
          default:
            goto switchD_10000c34c_caseD_a479;
          case 0xa47b:
switchD_10000c34c_caseD_a47b:
            pcVar6 = _kDuplexJamMsg;
          }
        }
        else {
          if ((long)param_1 < 0xac52) {
            if (param_1 == 0xac45) {
              return _kMPJamMsg;
            }
            if (param_1 == 0xac46) {
              return _kRearJamMsg;
            }
          }
          else {
            if (param_1 == 0xac52) {
              return _kTray1JamMsg;
            }
            if (param_1 == 0xac53) {
              return _kInsideJamMsg;
            }
            if (param_1 == 0xac54) goto switchD_10000c34c_caseD_a47b;
          }
switchD_10000c34c_caseD_a479:
          if (param_1 - 50000 < 10) {
            if (param_1 - 50000 < 9) {
              ppuVar4 = *(undefined ***)(param_1 * 8 + 0xfffb0940);
            }
            else {
              ppuVar4 = &_kServiceCallMsg;
            }
            pcVar6 = *ppuVar4;
            cVar2 = _isMessageAvailable(pcVar6);
            if (cVar2 == '\0') {
              return _kServiceCallMsg;
            }
            return pcVar6;
          }
          if ((long)param_1 < 0xc39c) {
            if (param_1 == 0xc35a) {
              if (iVar1 == 2) {
                return _kUnitHotMsg;
              }
              cVar2 = _isMessageAvailable(_kScanUnableMsg);
              if (cVar2 != '\0') {
                return _kUnitHotMsg;
              }
              cVar2 = _isMessageAvailable(_kE49Msg);
              if (cVar2 != '\0') {
                return _kE49Msg;
              }
switchD_10000c47b_caseD_ea64:
              return _kServiceCallMsg;
            }
          }
          else if ((long)param_1 < 60000) {
            if (param_1 == 0xc39c) {
              return _kUnitMsg;
            }
          }
          else if ((long)param_1 < 0xeac7) {
            if ((long)param_1 < 0xea75) {
              switch(param_1) {
              case 60000:
                cVar2 = _isMessageAvailable(_kStorageFullMsg);
                if (cVar2 == '\0') {
                  return _kTrayManyMsg;
                }
                return _kStorageFullMsg;
              case 0xea63:
                return _kInsideHotMsg;
              case 0xea64:
                goto switchD_10000c47b_caseD_ea64;
              case 0xea65:
                cVar2 = _isMessageAvailable(_kDrumDustMsg);
                if (cVar2 != '\0') {
                  return _kDrumDustMsg;
                }
                return _kDrumMsg;
              case 0xea69:
LAB_10000c810:
                return _kTonerMsg;
              }
            }
            else {
              switch(param_1) {
              case 0xea75:
              case 0xea7d:
                return _kBackCoverMsg;
              case 0xea77:
                return _kAutoSizeMsg;
              case 0xea7a:
                return _kNoDXTrayMsg;
              case 0xea7b:
                return _kDuplexLeverMsg;
              }
            }
          }
          else if ((long)param_1 < 0xead0) {
            if (param_1 == 0xeac7) {
              return _kBeltMissMsg;
            }
            if (param_1 == 0xeac8) {
              return _kUnitMissMsg;
            }
          }
          else if ((long)param_1 < 0xeb00) {
            if ((long)param_1 < 0xeaf0) {
              if ((long)param_1 < 0xeae3) {
                if ((long)param_1 < 0xead8) {
                  if (param_1 == 0xead0) {
                    return _kRollerMissMsg;
                  }
                  if (param_1 == 0xead2) {
                    return _kOutputTrayMsg;
                  }
                }
                else {
                  if (param_1 == 0xead8) {
                    return _kDuplexMsg;
                  }
                  if (param_1 == 0xeada) {
                    return _kDrumMissMsg;
                  }
                }
              }
              else {
                if (param_1 == 0xeae3) {
                  return _kT1SizeMsg;
                }
                if (param_1 == 0xeae4) {
                  return _kT2SizeMsg;
                }
              }
            }
            else {
              switch(param_1) {
              case 0xeaf0:
                return _kCartridgeMsg;
              case 0xeaf2:
                return _kTray1MissMsg;
              case 0xeaf3:
                return _kTray2MissMsg;
              case 0xeaf4:
                goto switchD_10000c5da_caseD_eaf4;
              case 0xeaf6:
                return _kELMsg;
              case 0xeaf7:
                goto LAB_10000c810;
              }
            }
          }
          else {
            switch(param_1) {
            case 0xeb00:
              return _kDrumOut2Msg;
            case 0xeb01:
              return _kBeltUnitOut2Msg;
            case 0xeb02:
              if (iVar1 == 2) {
                return _kHighTemperMsg;
              }
              return pcVar6;
            case 0xeb03:
              return _kTonerEnd2Msg;
            }
          }
          if ((param_1 & 0xfffffffffffffffc) == 0xeb04) {
            return _kLogAccessMsg;
          }
          switch(param_1) {
          case 0xeb08:
            pcVar6 = _kTray3MissMsg;
            break;
          case 0xeb09:
            pcVar6 = _kTray4MissMsg;
            break;
          default:
            if (param_1 - 0xeb0f < 4) {
              return _kWrongSizeMsg;
            }
            if ((long)param_1 < 0xf232) {
              if (param_1 == 0xeb13) {
                return _kTrayManyMsg;
              }
            }
            else if ((long)param_1 < 0xf296) {
              if (param_1 == 0xf232) {
                return _kLserUnitOutMsg;
              }
              if (param_1 == 0xf233) {
                return _kDrumLowMsg;
              }
            }
            else {
              switch(param_1) {
              case 0xf296:
                return _kWasteNearFullMsg;
              case 0xf297:
                return _kBeltOutMsg;
              case 0xf298:
                return _kUnitOutMsg;
              case 0xf299:
                return _kKitOutMsg;
              case 0xf29d:
                return _kKit1OutMsg;
              case 0xf29e:
                return _kKit2OutMsg;
              case 0xf29f:
                return _kKit3OutMsg;
              case 0xf2a0:
                return _kKit4OutMsg;
              case 0xf2a4:
                return _kKitMPOutMsg;
              case 0xf2a5:
                return _kBeltUnitOutMsg;
              case 0xf2a7:
                return _kDrumOutMsg;
              case 0xf2a8:
                return _kBeltUnitLowMsg;
              case 0xf2a9:
                return _kTonerEndMsg;
              }
            }
            if (param_1 - 0xf2aa < 4) {
              return _kMediaLowMsg;
            }
            if (param_1 == 0xfde9) {
              return _kMPJamMsg;
            }
            uVar5 = param_1 & 0xfffffffffffffffe;
            if ((long)uVar5 < 0xfdf0) {
              if (uVar5 == 0xfdea) {
                return _kTray1JamMsg;
              }
              if (uVar5 == 0xfdec) {
                return _kTray2JamMsg;
              }
            }
            else {
              if (uVar5 == 0xfdf0) {
                return _kTray3JamMsg;
              }
              if (uVar5 == 0xfdf4) {
                return _kTray4JamMsg;
              }
              if (uVar5 == 0xfdf6) {
                return _kInsideJamMsg;
              }
            }
            if ((long)param_1 < 0xfe08) {
              if (param_1 == 0xfdf8) goto switchD_10000c34c_caseD_a478;
            }
            else {
              if (param_1 == 0xfe08) {
                return _kRearJamMsg;
              }
              if (param_1 == 0xfe18) {
                return _kOptionJamMsg;
              }
              if (param_1 == 0xfe28) goto switchD_10000c34c_caseD_a47b;
            }
            cVar2 = _isMessageAvailable(_kGenericMsg);
            if (cVar2 != '\0') {
              pcVar6 = _kGenericMsg;
            }
            break;
          case 0xeb0b:
            pcVar6 = _kTrayID1MissMsg;
            break;
          case 0xeb0c:
            pcVar6 = _kTrayID2MissMsg;
            break;
          case 0xeb0d:
            pcVar6 = _kTrayID3MissMsg;
            break;
          case 0xeb0e:
            pcVar6 = _kTrayID4MissMsg;
          }
        }
        return pcVar6;
      }
      cVar2 = _isMessageAvailable(_kScanUnableMsg);
      pcVar6 = _kTray2SizeMsg;
    }
  }
  else {
    if ((long)param_1 < 0x9ccd) {
      if (param_1 == 0x9c5a) {
        return _kWasteMissMsg;
      }
      goto LAB_10000c254;
    }
    if ((long)param_1 < 0x9d71) {
      if (param_1 == 0x9ccd) {
        return _kWasteFullMsg;
      }
      goto LAB_10000c254;
    }
    if ((long)param_1 < 0x9ddf) {
      if (param_1 - 0x9d71 < 4) {
        return _kDrumMsg;
      }
      goto LAB_10000c254;
    }
    if ((long)param_1 < 41000) {
      if (param_1 == 0x9ddf) {
        return _kBeltUnitMissMsg;
      }
      goto LAB_10000c254;
    }
    if (0xeac5 < (long)param_1) {
      if (param_1 == 0xeac6) {
        return _kWasteFullMsg;
      }
      if (param_1 == 0xeaf5) {
        return _kBeltUnitMissMsg;
      }
      if (param_1 == 0xeafc) {
        return _kDrumMsg;
      }
      goto LAB_10000c254;
    }
    if (param_1 != 41000) goto LAB_10000c254;
    cVar2 = _isMessageAvailable(_kScanUnableMsg);
    pcVar6 = _kMPSizeMsg;
  }
  if (cVar2 == '\0') {
    return pcVar6;
  }
switchD_10000c5da_caseD_eaf4:
  return _kPaperOutMsg;
}

