#ifndef GLOBALS_H
#define GLOBALS_H
#include <stdint.h>
extern unsigned char _img[34992];
extern unsigned char paper_sort_area[0x1000];

extern unsigned char _matrix300_Graphics[1024];
extern unsigned char _matrix300_Text[1024];
extern unsigned char _matrix600_Graphics[1024];
extern unsigned char _matrix600_Text[1024];
extern unsigned char _matrixHQ1200_Graphics[1024];
extern unsigned char _matrixHQ1200_Text[1024];
extern unsigned char _white_table[512];
extern unsigned char _white_tablee[512];
extern unsigned char _black_table[512];
extern unsigned char _black_tablee[512];
extern unsigned char _tblRoman8[96];
extern unsigned char _tblISO88592[128];
extern unsigned char _tblISO88595[128];
extern unsigned char _paperName[1200];
extern unsigned char _paperArray[4352];
extern unsigned char _lutfolderpath[1024];
extern unsigned char _lutModelfolderpath[1024];
extern unsigned char _gLowLevel[20];
extern uint64_t _send_buf;
extern uint64_t _compData;
extern uint64_t _Planes;
extern uint64_t _pMatrixRow;
extern uint64_t _fun_table;
extern uint64_t _thisPPD;
extern uint64_t _options;
extern uint64_t _blankPagePtr;
extern uint64_t _oddPagePtr;
extern uint64_t _evenPagePtr;
extern uint64_t _gLoginUserName;
extern uint64_t _gLogJobName;
extern uint64_t _gStatus;
extern uint64_t _lFAXDataCnt;
extern int _lMatrixRow;
/* _margins and __margins overlap in the original binary (both @0x100016a50) */
#define _margins (*(short *)&__margins)
extern short _lCount;
extern int _model_language;
extern int _gModelInfo;
extern int _num_options;
extern short _gOnePageByte;
extern int _gloopCnt;
extern int _gGetStatusMode;
extern int _gEncodingNum;
extern unsigned char _model_index;
extern int DAT_100016a54;
extern int DAT_100016a70;
extern int DAT_100016a78;
extern int DAT_100016a80;
extern int DAT_100016a88;
extern int DAT_100016a98;
extern int DAT_100016aa8;
extern int DAT_100016ab8;
extern int DAT_100016f38;
extern int DAT_100016f30;
extern int DAT_100015084;
extern int DAT_1000145f8;
extern int DAT_100014744;
extern int DAT_100014938;
extern short DAT_100013f62;
extern short DAT_100016a52;
extern int DAT_100016b00;
extern int DAT_100016b08;
extern int DAT_100016b10;
extern int DAT_100016b18;
extern int DAT_100016b20;
extern int DAT_100016b30;
extern void * DAT_100016200;
extern void * DAT_100016208;
extern void * DAT_100016210;
extern void * DAT_100016218;
extern void * DAT_100016220;
extern int DAT_1000104b8;
extern int DAT_1000104c8;
extern int DAT_1000104d0;
extern int DAT_1000104d8;
extern int DAT_1000104e0;
extern int DAT_1000104e8;
extern int DAT_1000104f0;
extern void *DAT_100016aa0;
extern void *DAT_100016ab0;
extern void *DAT_100016ac0;
extern uint64_t __margins;
extern short __gOnePageByte;
extern short __lCount;
extern int __gGetStatusMode;
extern int __gEncodingNum;
extern short DAT_100016a50;
extern uint64_t DAT_100016a60;
extern uint64_t DAT_100016a90;
extern char *PTR_s_Sun_100012320[7];
extern char *PTR_s_Jan_100012360[12];

/* CFString-like struct for cf_* constants (only used by stubbed CF calls) */
typedef struct {
    unsigned char b0[8];
    unsigned char field1_0x8[8];
    unsigned char b2[8];
    unsigned char field3_0x18[8];
} cfstringStruct;

#define s__10000f7d6 (_img + 0xac6)
/* img-based macros for referenced data symbols */
#define DAT_1000104a0 (*(int *)(_img + 0x1790))
#define DAT_1000104b0 (*(int *)(_img + 0x17a0))
#define DAT_1000104c0 (*(int *)(_img + 0x17b0))
#define DAT_100010508 (*(int *)(_img + 0x17f8))
#define DAT_100010510 (*(int *)(_img + 0x1800))
#define DAT_100010520 (*(int *)(_img + 0x1810))
#define DAT_100010540 (*(int *)(_img + 0x1830))
#define DAT_100010560 (*(int *)(_img + 0x1850))
#define DAT_100014fe0 (*(int *)(_img + 0x62d0))
#define DAT_100014fe8 (*(int *)(_img + 0x62d8))
#define DAT_100014fec (*(int *)(_img + 0x62dc))
#define DAT_100014ff0 (*(int *)(_img + 0x62e0))
#define DAT_100014ff8 (*(int *)(_img + 0x62e8))
#define DAT_100015000 (*(int *)(_img + 0x62f0))
#define DAT_100015008 (*(int *)(_img + 0x62f8))
#define DAT_100015010 (*(int *)(_img + 0x6300))
#define DAT_100015018 (*(int *)(_img + 0x6308))
#define DAT_100015028 (*(int *)(_img + 0x6318))
#define DAT_100015058 (*(int *)(_img + 0x6348))
#define DAT_100015060 (*(int *)(_img + 0x6350))
#define DAT_100015074 (*(int *)(_img + 0x6364))
#define DAT_100015078 (*(int *)(_img + 0x6368))
#define DAT_10001507c (*(int *)(_img + 0x636c))
#define DAT_100016244 (*(int *)(_img + 0x7534))
#define DAT_100016248 (*(int *)(_img + 0x7538))
#define DAT_100016250 (*(int *)(_img + 0x7540))
#define DAT_100016252 (*(int *)(_img + 0x7542))
#define DAT_100016644 (*(int *)(_img + 0x7934))
#define DAT_100016648 (*(int *)(_img + 0x7938))
#define DAT_100016650 (*(int *)(_img + 0x7940))
#define DAT_100016f40 (*(int *)(_img + 0x8230))
#define DAT_100017140 (*(int *)(_img + 0x8430))
#define DAT_100017340 (*(int *)(_img + 0x8630))
#define DAT_100017540 (*(int *)(_img + 0x8830))
#define PTR__CFArrayCreate_100012068 (*(uint64_t *)(_img + 0x3358))
#define PTR__CFArrayGetCount_100012070 (*(uint64_t *)(_img + 0x3360))
#define PTR__CFArrayGetTypeID_100012078 (*(uint64_t *)(_img + 0x3368))
#define PTR__CFArrayGetValueAtIndex_100012080 (*(uint64_t *)(_img + 0x3370))
#define PTR__CFBundleCopyLocalizedString_100012088 (*(uint64_t *)(_img + 0x3378))
#define PTR__CFBundleCopyResourceURL_100012090 (*(uint64_t *)(_img + 0x3380))
#define PTR__CFBundleCreate_100012098 (*(uint64_t *)(_img + 0x3388))
#define PTR__CFBundleGetIdentifier_1000120a0 (*(uint64_t *)(_img + 0x3390))
#define PTR__CFBundleGetInfoDictionary_1000120a8 (*(uint64_t *)(_img + 0x3398))
#define PTR__CFBundleGetMainBundle_1000120b0 (*(uint64_t *)(_img + 0x33a0))
#define PTR__CFDictionaryCreateCopy_1000120b8 (*(uint64_t *)(_img + 0x33a8))
#define PTR__CFDictionaryGetValue_1000120c0 (*(uint64_t *)(_img + 0x33b0))
#define PTR__CFEqual_1000120c8 (*(uint64_t *)(_img + 0x33b8))
#define PTR__CFGetTypeID_1000120d0 (*(uint64_t *)(_img + 0x33c0))
#define PTR__CFPreferencesSetAppValue_1000120d8 (*(uint64_t *)(_img + 0x33c8))
#define PTR__CFPropertyListCreateFromXMLData_1000120e0 (*(uint64_t *)(_img + 0x33d0))
#define PTR__CFRelease_1000120e8 (*(uint64_t *)(_img + 0x33d8))
#define PTR__CFStringCreateMutableCopy_1000120f0 (*(uint64_t *)(_img + 0x33e0))
#define PTR__CFStringCreateWithCString_1000120f8 (*(uint64_t *)(_img + 0x33e8))
#define PTR__CFStringCreateWithFormat_100012100 (*(uint64_t *)(_img + 0x33f0))
#define PTR__CFStringDelete_100012108 (*(uint64_t *)(_img + 0x33f8))
#define PTR__CFStringFindAndReplace_100012118 (*(uint64_t *)(_img + 0x3408))
#define PTR__CFStringFind_100012110 (*(uint64_t *)(_img + 0x3400))
#define PTR__CFStringGetCString_100012120 (*(uint64_t *)(_img + 0x3410))
#define PTR__CFStringGetLength_100012128 (*(uint64_t *)(_img + 0x3418))
#define PTR__CFStringGetTypeID_100012130 (*(uint64_t *)(_img + 0x3420))
#define PTR__CFStringHasSuffix_100012138 (*(uint64_t *)(_img + 0x3428))
#define PTR__CFURLCreateDataAndPropertiesFromResource_100012148 (*(uint64_t *)(_img + 0x3438))
#define PTR__CFURLCreateData_100012140 (*(uint64_t *)(_img + 0x3430))
#define PTR__CFURLCreateWithFileSystemPath_100012150 (*(uint64_t *)(_img + 0x3440))
#define PTR____bzero_1000121e0 (*(uint64_t *)(_img + 0x34d0))
#define PTR____error_1000121e8 (*(uint64_t *)(_img + 0x34d8))
#define PTR____sprintf_chk_1000121f0 (*(uint64_t *)(_img + 0x34e0))
#define PTR____stack_chk_fail_1000121f8 (*(uint64_t *)(_img + 0x34e8))
#define PTR__atoi_100012200 (*(uint64_t *)(_img + 0x34f0))
#define PTR__atol_100012208 (*(uint64_t *)(_img + 0x34f8))
#define PTR__close_100012210 (*(uint64_t *)(_img + 0x3500))
#define PTR__cupsBackChannelRead_100012158 (*(uint64_t *)(_img + 0x3448))
#define PTR__cupsFreeOptions_100012160 (*(uint64_t *)(_img + 0x3450))
#define PTR__cupsGetOption_100012168 (*(uint64_t *)(_img + 0x3458))
#define PTR__cupsParseOptions_100012170 (*(uint64_t *)(_img + 0x3460))
#define PTR__cupsRasterClose_1000121c0 (*(uint64_t *)(_img + 0x34b0))
#define PTR__cupsRasterOpen_1000121c8 (*(uint64_t *)(_img + 0x34b8))
#define PTR__cupsRasterReadHeader2_1000121d0 (*(uint64_t *)(_img + 0x34c0))
#define PTR__cupsRasterReadPixels_1000121d8 (*(uint64_t *)(_img + 0x34c8))
#define PTR__cupsSideChannelDoRequest_100012178 (*(uint64_t *)(_img + 0x3468))
#define PTR__cupsSideChannelSNMPGet_100012180 (*(uint64_t *)(_img + 0x3470))
#define PTR__exit_100012218 (*(uint64_t *)(_img + 0x3508))
#define PTR__fflush_100012220 (*(uint64_t *)(_img + 0x3510))
#define PTR__fprintf_100012228 (*(uint64_t *)(_img + 0x3518))
#define PTR__free_100012230 (*(uint64_t *)(_img + 0x3520))
#define PTR__fwrite_100012238 (*(uint64_t *)(_img + 0x3528))
#define PTR__getenv_100012240 (*(uint64_t *)(_img + 0x3530))
#define PTR__gmtime_100012248 (*(uint64_t *)(_img + 0x3538))
#define PTR__kCFAllocatorDefault_100012040 (*(uint64_t *)(_img + 0x3330))
#define PTR__kCFPreferencesCurrentApplication_100012048 (*(uint64_t *)(_img + 0x3338))
#define PTR__kCFTypeArrayCallBacks_100012050 (*(uint64_t *)(_img + 0x3340))
#define PTR__localtime_100012250 (*(uint64_t *)(_img + 0x3540))
#define PTR__malloc_100012258 (*(uint64_t *)(_img + 0x3548))
#define PTR__memcpy_100012260 (*(uint64_t *)(_img + 0x3550))
#define PTR__memset_100012268 (*(uint64_t *)(_img + 0x3558))
#define PTR__memset_pattern16_100012270 (*(uint64_t *)(_img + 0x3560))
#define PTR__open_100012278 (*(uint64_t *)(_img + 0x3568))
#define PTR__perror_100012280 (*(uint64_t *)(_img + 0x3570))
#define PTR__ppdClose_100012188 (*(uint64_t *)(_img + 0x3478))
#define PTR__ppdFindAttr_100012190 (*(uint64_t *)(_img + 0x3480))
#define PTR__ppdFindChoice_100012198 (*(uint64_t *)(_img + 0x3488))
#define PTR__ppdFindCustomOption_1000121a0 (*(uint64_t *)(_img + 0x3490))
#define PTR__ppdFindCustomParam_1000121a8 (*(uint64_t *)(_img + 0x3498))
#define PTR__ppdFindOption_1000121b0 (*(uint64_t *)(_img + 0x34a0))
#define PTR__ppdOpenFile_1000121b8 (*(uint64_t *)(_img + 0x34a8))
#define PTR__printf_100012288 (*(uint64_t *)(_img + 0x3578))
#define PTR__putchar_100012290 (*(uint64_t *)(_img + 0x3580))
#define PTR__puts_100012298 (*(uint64_t *)(_img + 0x3588))
#define PTR__read_1000122a0 (*(uint64_t *)(_img + 0x3590))
#define PTR__setbuf_1000122a8 (*(uint64_t *)(_img + 0x3598))
#define PTR__setitimer_1000122b0 (*(uint64_t *)(_img + 0x35a0))
#define PTR__setlocale_1000122b8 (*(uint64_t *)(_img + 0x35a8))
#define PTR__signal_1000122c0 (*(uint64_t *)(_img + 0x35b0))
#define PTR__sleep_1000122c8 (*(uint64_t *)(_img + 0x35b8))
#define PTR__snprintf_1000122d0 (*(uint64_t *)(_img + 0x35c0))
#define PTR__sprintf_1000122d8 (*(uint64_t *)(_img + 0x35c8))
#define PTR__sscanf_1000122e0 (*(uint64_t *)(_img + 0x35d0))
#define PTR__strcat_1000122e8 (*(uint64_t *)(_img + 0x35d8))
#define PTR__strcmp_1000122f0 (*(uint64_t *)(_img + 0x35e0))
#define PTR__strcpy_1000122f8 (*(uint64_t *)(_img + 0x35e8))
#define PTR__strlen_100012300 (*(uint64_t *)(_img + 0x35f0))
#define PTR__strncmp_100012308 (*(uint64_t *)(_img + 0x35f8))
#define PTR__strstr_100012310 (*(uint64_t *)(_img + 0x3600))
#define PTR__time_100012318 (*(uint64_t *)(_img + 0x3608))
#define _kA1JamMsg (*(uint64_t *)(_img + 0x5e88))
#define _kA2JamMsg (*(uint64_t *)(_img + 0x5e90))
#define _kAutoSizeMsg (*(uint64_t *)(_img + 0x5ff0))
#define _kBJamMsg (*(uint64_t *)(_img + 0x5e98))
#define _kBackCoverMsg (*(uint64_t *)(_img + 0x6050))
#define _kBeltMissMsg (*(uint64_t *)(_img + 0x5f38))
#define _kBeltOutMsg (*(uint64_t *)(_img + 0x5da0))
#define _kBeltUnitLowMsg (*(uint64_t *)(_img + 0x5e50))
#define _kBeltUnitMissMsg (*(uint64_t *)(_img + 0x5f50))
#define _kBeltUnitOut2Msg (*(uint64_t *)(_img + 0x5f58))
#define _kBeltUnitOutMsg (*(uint64_t *)(_img + 0x5e58))
#define _kBlackPrintID (*(uint64_t *)(_img + 0x61b0))
#define _kBlackPrintMsg (*(uint64_t *)(_img + 0x5e60))
#define _kCJamMsg (*(uint64_t *)(_img + 0x5ea0))
#define _kCartridge2Msg (*(uint64_t *)(_img + 0x5ef8))
#define _kCartridge3Msg (*(uint64_t *)(_img + 0x5f00))
#define _kCartridgeColorMsg (*(uint64_t *)(_img + 0x5f10))
#define _kCartridgeMsg (*(uint64_t *)(_img + 0x5ef0))
#define _kCartridgeOldMsg (*(uint64_t *)(_img + 0x5f08))
#define _kCartridgeStrMsg (*(uint64_t *)(_img + 0x5f18))
#define _kCharCodeID (*(uint64_t *)(_img + 0x62b8))
#define _kCharCodeIndexID (*(uint64_t *)(_img + 0x62b0))
#define _kCommErrorMsg (*(uint64_t *)(_img + 0x6188))
#define _kCondensationMsg (*(uint64_t *)(_img + 0x60e0))
#define _kCoverOpenMsg (*(uint64_t *)(_img + 0x5d80))
#define _kDeviceMsg (*(uint64_t *)(_img + 0x5df0))
#define _kDiscGuideMsg (*(uint64_t *)(_img + 0x6060))
#define _kDocumentJamMsg (*(uint64_t *)(_img + 0x6160))
#define _kDrumDustMsg (*(uint64_t *)(_img + 0x5ec8))
#define _kDrumLowMsg (*(uint64_t *)(_img + 0x5de0))
#define _kDrumMissMsg (*(uint64_t *)(_img + 0x5f68))
#define _kDrumMsg (*(uint64_t *)(_img + 0x5ec0))
#define _kDrumOut2Msg (*(uint64_t *)(_img + 0x5ed0))
#define _kDrumOutMsg (*(uint64_t *)(_img + 0x5f70))
#define _kDuplexJamMsg (*(uint64_t *)(_img + 0x60a0))
#define _kDuplexLeverMsg (*(uint64_t *)(_img + 0x60a8))
#define _kDuplexMsg (*(uint64_t *)(_img + 0x5f80))
#define _kE49Msg (*(uint64_t *)(_img + 0x6100))
#define _kE51Msg (*(uint64_t *)(_img + 0x6110))
#define _kE52Msg (*(uint64_t *)(_img + 0x6118))
#define _kE54Msg (*(uint64_t *)(_img + 0x6120))
#define _kELMsg (*(uint64_t *)(_img + 0x6040))
#define _kFrontCoverMsg (*(uint64_t *)(_img + 0x6058))
#define _kGenericMsg (*(uint64_t *)(_img + 0x5dc8))
#define _kHighTemperMsg (*(uint64_t *)(_img + 0x60e8))
#define _kInitUnableMsg (*(uint64_t *)(_img + 0x60c8))
#define _kInsideHotMsg (*(uint64_t *)(_img + 0x5e00))
#define _kInsideJamMsg (*(uint64_t *)(_img + 0x6090))
#define _kInterfaceID (*(uint64_t *)(_img + 0x61b8))
#define _kJournalFullMsg (*(uint64_t *)(_img + 0x6158))
#define _kKit1OutMsg (*(uint64_t *)(_img + 0x5e28))
#define _kKit2OutMsg (*(uint64_t *)(_img + 0x5e30))
#define _kKit3OutMsg (*(uint64_t *)(_img + 0x5e38))
#define _kKit4OutMsg (*(uint64_t *)(_img + 0x5e40))
#define _kKitMPOutMsg (*(uint64_t *)(_img + 0x5e48))
#define _kKitOutMsg (*(uint64_t *)(_img + 0x5e20))
#define _kLanguageID (*(uint64_t *)(_img + 0x62c0))
#define _kLogAccessMsg (*(uint64_t *)(_img + 0x6148))
#define _kLowTemperMsg (*(uint64_t *)(_img + 0x60f0))
#define _kLserUnitOutMsg (*(uint64_t *)(_img + 0x5e10))
#define _kMPJamMsg (*(uint64_t *)(_img + 0x6068))
#define _kMPSizeMsg (*(uint64_t *)(_img + 0x5fa0))
#define _kMachineHotMsg (*(uint64_t *)(_img + 0x60b8))
#define _kManualSizeMsg (*(uint64_t *)(_img + 0x5fa8))
#define _kMarkerColor (*(uint64_t *)(_img + 0x61c0))
#define _kMarkerLevel (*(uint64_t *)(_img + 0x61c8))
#define _kMarkerLowLevel (*(uint64_t *)(_img + 0x61d0))
#define _kMarkerName (*(uint64_t *)(_img + 0x61d8))
#define _kMarkerType (*(uint64_t *)(_img + 0x61e0))
#define _kMediaLowMsg (*(uint64_t *)(_img + 0x5d88))
#define _kMemoryOutMsg (*(uint64_t *)(_img + 0x5e78))
#define _kNoBlackPrintMsg (*(uint64_t *)(_img + 0x5e68))
#define _kNoDXTrayMsg (*(uint64_t *)(_img + 0x5e70))
#define _kNoTrayMsg (*(uint64_t *)(_img + 0x5da8))
#define _kOptionJamMsg (*(uint64_t *)(_img + 0x60b0))
#define _kOptionalOutputFullMsg (*(uint64_t *)(_img + 0x5fe8))
#define _kOutputBinFullMsg (*(uint64_t *)(_img + 0x5db0))
#define _kOutputTrayMsg (*(uint64_t *)(_img + 0x5f78))
#define _kOverrunMsg (*(uint64_t *)(_img + 0x5e80))
#define _kPaperJamMsg (*(uint64_t *)(_img + 0x5d98))
#define _kPaperOutMsg (*(uint64_t *)(_img + 0x5d90))
#define _kPrintMsg (*(uint64_t *)(_img + 0x5f28))
#define _kPrintUnableMsg (*(uint64_t *)(_img + 0x60c0))
#define _kPrinterLockMsg (*(uint64_t *)(_img + 0x6190))
#define _kRearJamMsg (*(uint64_t *)(_img + 0x6098))
#define _kRegistMsg (*(uint64_t *)(_img + 0x6048))
#define _kResolutionMsg (*(uint64_t *)(_img + 0x5df8))
#define _kRollerMissMsg (*(uint64_t *)(_img + 0x5f60))
#define _kScanCoverOpenMsg (*(uint64_t *)(_img + 0x6170))
#define _kScanLockMsg (*(uint64_t *)(_img + 0x6178))
#define _kScanUnableMsg (*(uint64_t *)(_img + 0x6180))
#define _kServiceCallMsg (*(uint64_t *)(_img + 0x5dc0))
#define _kShortPaperMsg (*(uint64_t *)(_img + 0x60d0))
#define _kSizeMsg (*(uint64_t *)(_img + 0x5f88))
#define _kSmallPaperMsg (*(uint64_t *)(_img + 0x60d8))
#define _kStatusID (*(uint64_t *)(_img + 0x6198))
#define _kStatusMsgID (*(uint64_t *)(_img + 0x61a0))
#define _kStorageFullMsg (*(uint64_t *)(_img + 0x60f8))
#define _kStorageMsg (*(uint64_t *)(_img + 0x6150))
#define _kSupplyLevelID (*(uint64_t *)(_img + 0x61a8))
#define _kT1SizeMsg (*(uint64_t *)(_img + 0x5f90))
#define _kT2SizeMsg (*(uint64_t *)(_img + 0x5f98))
#define _kTonerEnd2Msg (*(uint64_t *)(_img + 0x5ee8))
#define _kTonerEndMsg (*(uint64_t *)(_img + 0x5ee0))
#define _kTonerLowMsg (*(uint64_t *)(_img + 0x5dd0))
#define _kTonerMissMsg (*(uint64_t *)(_img + 0x5ff8))
#define _kTonerMsg (*(uint64_t *)(_img + 0x5ed8))
#define _kTonerOutMsg (*(uint64_t *)(_img + 0x5dd8))
#define _kTray1JamMsg (*(uint64_t *)(_img + 0x6070))
#define _kTray1MissMsg (*(uint64_t *)(_img + 0x6000))
#define _kTray1SizeMsg (*(uint64_t *)(_img + 0x5fb0))
#define _kTray2JamMsg (*(uint64_t *)(_img + 0x6078))
#define _kTray2MissMsg (*(uint64_t *)(_img + 0x6008))
#define _kTray2SizeMsg (*(uint64_t *)(_img + 0x5fb8))
#define _kTray3JamMsg (*(uint64_t *)(_img + 0x6080))
#define _kTray3MissMsg (*(uint64_t *)(_img + 0x6010))
#define _kTray3SizeMsg (*(uint64_t *)(_img + 0x5fc0))
#define _kTray4JamMsg (*(uint64_t *)(_img + 0x6088))
#define _kTray4MissMsg (*(uint64_t *)(_img + 0x6018))
#define _kTray4SizeMsg (*(uint64_t *)(_img + 0x5fc8))
#define _kTrayID1MissMsg (*(uint64_t *)(_img + 0x6020))
#define _kTrayID2MissMsg (*(uint64_t *)(_img + 0x6028))
#define _kTrayID3MissMsg (*(uint64_t *)(_img + 0x6030))
#define _kTrayID4MissMsg (*(uint64_t *)(_img + 0x6038))
#define _kTrayManyMsg (*(uint64_t *)(_img + 0x5eb8))
#define _kUnitHotMsg (*(uint64_t *)(_img + 0x5e08))
#define _kUnitMissMsg (*(uint64_t *)(_img + 0x5f40))
#define _kUnitMsg (*(uint64_t *)(_img + 0x5f48))
#define _kUnitOutMsg (*(uint64_t *)(_img + 0x5e18))
#define _kVersionMsg (*(uint64_t *)(_img + 0x5f20))
#define _kWaitMsg (*(uint64_t *)(_img + 0x5de8))
#define _kWasteFullMsg (*(uint64_t *)(_img + 0x5d70))
#define _kWasteMissMsg (*(uint64_t *)(_img + 0x5f30))
#define _kWasteNearFullMsg (*(uint64_t *)(_img + 0x5d78))
#define _kWrongPaperMsg (*(uint64_t *)(_img + 0x6168))
#define _kWrongSizeMsg (*(uint64_t *)(_img + 0x5fd0))
#define _supplyName (*(uint64_t *)(_img + 0x61f0))
#define _supplyType (*(uint64_t *)(_img + 0x6250))

/* CFString-like struct for cf_* constants (used only by stubbed CF calls) */



#define cf_AppleLanguages (*(cfstringStruct *)(_img + 0x36f8))
#define cf__d (*(cfstringStruct *)(_img + 0x3718))
#define cf__d__d (*(cfstringStruct *)(_img + 0x3738))
#define cf_StatusMessage (*(cfstringStruct *)(_img + 0x3758))
#define cf_model (*(cfstringStruct *)(_img + 0x3778))
#define cf_StandardStatus (*(cfstringStruct *)(_img + 0x37b8))
#define cf_raster (*(cfstringStruct *)(_img + 0x37d8))
#define cf__Library (*(cfstringStruct *)(_img + 0x37f8))
#define cf__Contents (*(cfstringStruct *)(_img + 0x3818))
#define cf_plist (*(cfstringStruct *)(_img + 0x3838))
#define cf__report (*(cfstringStruct *)(_img + 0x3898))
#define cf__warning (*(cfstringStruct *)(_img + 0x38b8))
#define cf__ (*(cfstringStruct *)(_img + 0x3878))
#define cf___ (*(cfstringStruct *)(_img + 0x3858))
#define cf_____ (*(cfstringStruct *)(_img + 0x3798))
#define uRam0000000100017548 (*(uint64_t *)(_img + 0x8838))
#define uRam0000000100017550 (*(uint64_t *)(_img + 0x8840))
#define uRam0000000100017558 (*(uint64_t *)(_img + 0x8848))
#define uRam0000000100017560 (*(uint64_t *)(_img + 0x8850))
#define uRam0000000100017568 (*(uint64_t *)(_img + 0x8858))
#define uRam0000000100017570 (*(uint64_t *)(_img + 0x8860))
#define uRam0000000100017578 (*(uint64_t *)(_img + 0x8868))
#define uRam0000000100017580 (*(uint64_t *)(_img + 0x8870))
#define uRam0000000100017548 (*(uint64_t *)(_img + 0x8838))
#define uRam0000000100017558 (*(uint64_t *)(_img + 0x8848))
#define uRam0000000100017568 (*(uint64_t *)(_img + 0x8858))
#define uRam0000000100017578 (*(uint64_t *)(_img + 0x8868))
#define uRam0000000100017588 (*(uint64_t *)(_img + 0x8878))
#define uRam0000000100017598 (*(uint64_t *)(_img + 0x8888))
#define uRam00000001000175a8 (*(uint64_t *)(_img + 0x8898))
#define uRam00000001000175b8 (*(uint64_t *)(_img + 0x88a8))
#define _DAT_100017540 (*(uint64_t *)(_img + 0x8830))
#define _DAT_100017550 (*(uint64_t *)(_img + 0x8840))
#define _DAT_100017560 (*(uint64_t *)(_img + 0x8850))
#define _DAT_100017570 (*(uint64_t *)(_img + 0x8860))
#define _DAT_100017580 (*(uint64_t *)(_img + 0x8870))
#define _DAT_100017590 (*(uint64_t *)(_img + 0x8880))
#define _DAT_1000175a0 (*(uint64_t *)(_img + 0x8890))
#define _DAT_1000175b0 (*(uint64_t *)(_img + 0x88a0))
#define _DAT_100010500 (*(double *)(_img + 0x17f0))
#define _DAT_100015020 (*(uint64_t *)(_img + 0x6310))
#define _DAT_100015028 (*(uint64_t *)(_img + 0x6318))
#define _DAT_100015030 (*(uint64_t *)(_img + 0x6320))
#define _DAT_100015038 (*(uint64_t *)(_img + 0x6328))
#define _DAT_100015040 (*(uint64_t *)(_img + 0x6330))
#define _DAT_100015048 (*(uint64_t *)(_img + 0x6338))
#define _DAT_100015050 (*(uint64_t *)(_img + 0x6340))
#define _DAT_100015058 (*(uint64_t *)(_img + 0x6348))
#define _DAT_100015060 (*(uint64_t *)(_img + 0x6350))
#define _DAT_100015068 (*(uint64_t *)(_img + 0x6358))
/* these overlap _paperArray in the original binary (paperArray@0x1000150f0);
   sortPaperResult fills paperArray[].name/size and the sort keys
   (DAT_100015130/132 = paperArray+0x40/0x42) alias the same memory. */
#define DAT_1000150f4 (*(int *)(_paperArray + 0x04))
#define DAT_100015130 (*(short *)(_paperArray + 0x40))
#define DAT_100015132 (*(short *)(_paperArray + 0x42))
#define DAT_100015134 (*(short *)(_paperArray + 0x44))
#define DAT_100015138 (*(short *)(_paperArray + 0x48))
#define DAT_100015174 (*(short *)(_paperArray + 0x84))
#define DAT_100015176 (*(short *)(_paperArray + 0x86))
#define DAT_1000151b8 (*(short *)(_paperArray + 0xc8))
#define DAT_1000151ba (*(short *)(_paperArray + 0xca))
#define DAT_1000151fc (*(short *)(_paperArray + 0x10c))
#define DAT_1000151fe (*(short *)(_paperArray + 0x10e))
#endif
