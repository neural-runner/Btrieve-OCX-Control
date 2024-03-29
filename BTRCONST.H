#ifndef _BTRCONST_H_INCLUDED
/*************************************************************************
**
**  Copyright 1982-1995 Btrieve Technologies, Inc. All Rights Reserved
**
*************************************************************************/
/***************************************************************************
   BTRCONST.H - Btrieve Constants
      This file contains various Btrieve constants for use by Btrieve 6.x
      C/C++ applications.

***************************************************************************/
/***************************************************************************
                               Size Constants
***************************************************************************/
#define ACS_SIZE          265        /* Alternate Collating Sequence size */
#define ACS_FILLER_SIZE   260
#define ACS_BYTE_MAP_SIZE 256
#define ACS_NAME_SIZE     8

#define BLOB_HEADER_LEN   0x0014     /* record chunk offset */

#if defined (BTI_DOS) || defined (BTI_WIN) || defined (BTI_WIN_32) \
  || defined (BTI_DOS_32R) || defined (BTI_DOS_32P) || defined (BTI_DOS_32B)
#define MAX_DATABUF_SIZE  57000L
#endif

#if defined (BTI_OS2) || defined (BTI_NLM) || defined (BTI_OS2_32)
#define MAX_DATABUF_SIZE  65000L
#endif

#define MIN_PAGE              512
#define MAX_PAGE              4096
#define MAX_KEY_SIZE          255
#define MAX_KEY_SEG           119
#define OWNER_NAME_SIZE       8+1        /* 8 characters + binary 0 */
#define POS_BLOCK_SIZE        128
#define PHYSICAL_POS_BUF_LEN  4          /* data buf size for Get Position */
#define MAX_FIXED_RECORD_LEN  4088       /* maximum fixed record length */
#define MAX_STATBUF_SIZE      33455L     /* B_STAT maximum data buffer size */

/***************************************************************************
                          'Chunk' API Constatnts
***************************************************************************/
#define GET_SIGNATURE_INDEX         4L
#define GET_NUM_CHUNKS_INDEX        8L
#define GET_CHUNK_OFFSET_INDEX      12L
#define GET_CHUNK_LEN_INDEX         16L
#define GET_USER_DATA_PTR_INDEX     20L

#define UPDATE_SIGNATURE_INDEX       0L
#define UPDATE_NUM_CHUNKS_INDEX      4L
#define UPDATE_CHUNK_OFFSET_INDEX    8L
#define UPDATE_CHUNK_LEN_INDEX       12L
#define UPDATE_USER_DATA_PTR_INDEX   16L

#define RECTANGLE_DIRECT_SIGN    0x80000002L
#define RECTANGLE_INDIRECT_SIGN  0x80000003L
#define APPEND_TO_BLOB           0x20000000L
#define GET_DRTC_XTRACTOR_KEY    0xFE
#define NEXT_IN_BLOB             0x40000000L
#define XTRACTR_INDIRECT_SIGN    0x80000001L
#define XTRACTR_DIRECT_SIGN      0x80000000L
#define TRUNC_SIGN               0x80000004L
#define NEXT_IN_BLOB             0x40000000L
#define PARTS_OF_KEY             0x00800000L   
#define TRUNC_AFTER_UPDATE       0x00400000L
#define CHUNK_NOBIAS_MASK ~(NEXT_IN_BLOB     |\
                            APPEND_TO_BLOB   |\
                            PARTS_OF_KEY     |\
                            TRUNC_AFTER_UPDATE)

#define CHUNK_NO_INTERNAL_CURRENCY 0x0001
#define MUST_READ_DATA_PAGE        0x0002
#define NO_INTERNAL_CURRENCY       0

/***************************************************************************
                               Operation Codes
***************************************************************************/
#define B_OPEN               0
#define B_CLOSE              1
#define B_INSERT             2
#define B_UPDATE             3
#define B_DELETE             4
#define B_GET_EQUAL          5
#define B_GET_NEXT           6
#define B_GET_PREVIOUS       7
#define B_GET_GT             8
#define B_GET_GE             9
#define B_GET_LT            10
#define B_GET_LE            11
#define B_GET_FIRST         12
#define B_GET_LAST          13
#define B_CREATE            14
#define B_STAT              15
#define B_EXTEND            16
#define B_SET_DIR           17
#define B_GET_DIR           18
#define B_BEGIN_TRAN        19
#define B_END_TRAN          20
#define B_ABORT_TRAN        21
#define B_GET_POSITION      22
#define B_GET_DIRECT        23
#define B_STEP_NEXT         24
#define B_STOP              25
#define B_VERSION           26
#define B_UNLOCK            27
#define B_RESET             28
#define B_SET_OWNER         29
#define B_CLEAR_OWNER       30
#define B_BUILD_INDEX       31
#define B_DROP_INDEX        32
#define B_STEP_FIRST        33
#define B_STEP_LAST         34
#define B_STEP_PREVIOUS     35
#define B_GET_NEXT_EXTENDED 36
#define B_GET_PREV_EXTENDED 37
#define B_STEP_NEXT_EXT     38
#define B_STEP_PREVIOUS_EXT 39
#define B_EXT_INSERT        40
#define B_MISC_DATA         41
#define B_CONTINUOUS        42
#define B_SEEK_PERCENT      44
#define B_GET_PERCENT       45
#define B_CHUNK_UPDATE      53

/***************************************************************************
                           Operation Bias Codes
***************************************************************************/
#define S_WAIT_LOCK    100 
#define S_NOWAIT_LOCK  200    /* function code bias for lock                */
#define M_WAIT_LOCK    300    /* function code bias for multiple loop lock  */
#define M_NOWAIT_LOCK  400    /* function code bias for multiple lock       */

#define WAIT_T         119    /* begin transaction with wait (same as 19)   */
#define NOWAIT_T       219    /* begin transaction with nowait              */
#define WAIT3_T        319    /* begin transaction with wait (same as 19)   */
#define NOWAIT4_T      419    /* begin transaction with nowait              */
#define CCURR_T_BIAS  1000    /* function code bias for consurrent trans    */
#define NOWRITE_WAIT   500    /* function code bias when ins/del/upd should */

/***************************************************************************
                   Key Number Bias Codes & Special Key Codes
               The hexadecimal values below are unsigned values.
***************************************************************************/
#define KEY_BIAS                            50
#define DROP_BUT_NO_RENUMBER                0x80  /* key num bias for Drop  */
                                                  /* Preserves key #s       */
#define CREATE_SUPPLEMENTAL_AS_THIS_KEY_NUM 0x80  /* key bias for Create SI */
#define CREATE_NEW_FILE                     0xFF
#define DONT_CREATE_WITH_TTS                0xFE
#define CREATE_NEW_FILE_NO_TTS              0xFD
#define IGNORE_KEY                        0xFFFF   /* ignore the key number */
#define ALTERNATE_STAT_BUF                0xFFFF         /* use with B_STAT */

/***************************************************************************
                           Btrieve File Open Modes
             The hexadecimal values below are unsigned values.
***************************************************************************/
#define B_NORMAL           0x00   /* normal mode        */
#define ACCELERATED        0xFF   /* accelerated mode   */
#define EXCLUSIVE          0xFC   /* exclusive mode     */
#define MINUSONE           0xFF   /* byte value for -1  */
#define READONLY           0xFE   /* read only mode     */


/***************************************************************************
                            Btrieve Return Codes
***************************************************************************/
#define B_NO_ERROR                          0
#define B_INVALID_FUNCTION                  1
#define B_IO_ERROR                          2
#define B_FILE_NOT_OPEN                     3
#define B_KEY_VALUE_NOT_FOUND               4
#define B_DUPLICATE_KEY_VALUE               5
#define B_INVALID_KEYNUMBER                 6
#define B_DIFFERENT_KEYNUMBER               7
#define B_POSITION_NOT_SET                  8
#define B_END_OF_FILE                       9
#define B_MODIFIABLE_KEYVALUE_ERROR         10
#define B_FILENAME_BAD                      11
#define B_FILE_NOT_FOUND                    12
#define B_EXTENDED_FILE_ERROR               13
#define B_PREIMAGE_OPEN_ERROR               14
#define B_PREIMAGE_IO_ERROR                 15
#define B_EXPANSION_ERROR                   16
#define B_CLOSE_ERROR                       17
#define B_DISKFULL                          18
#define B_UNRECOVERABLE_ERROR               19
#define B_RECORD_MANAGER_INACTIVE           20
#define B_KEYBUFFER_TOO_SHORT               21
#define B_DATALENGTH_ERROR                  22
#define B_POSITIONBLOCK_LENGTH              23
#define B_PAGE_SIZE_ERROR                   24
#define B_CREATE_IO_ERROR                   25
#define B_NUMBER_OF_KEYS                    26
#define B_INVALID_KEY_POSITION              27
#define B_INVALID_RECORD_LENGTH             28
#define B_INVALID_KEYLENGTH                 29
#define B_NOT_A_BTRIEVE_FILE                30
#define B_FILE_ALREADY_EXTENDED             31
#define B_EXTEND_IO_ERROR                   32
#define B_BTR_CANNOT_UNLOAD                 33
#define B_INVALID_EXTENSION_NAME            34
#define B_DIRECTORY_ERROR                   35
#define B_TRANSACTION_ERROR                 36
#define B_TRANSACTION_IS_ACTIVE             37
#define B_TRANSACTION_FILE_IO_ERROR         38
#define B_END_TRANSACTION_ERROR             39
#define B_TRANSACTION_MAX_FILES             40
#define B_OPERATION_NOT_ALLOWED             41
#define B_INCOMPLETE_ACCEL_ACCESS           42
#define B_INVALID_RECORD_ADDRESS            43
#define B_NULL_KEYPATH                      44
#define B_INCONSISTENT_KEY_FLAGS            45
#define B_ACCESS_TO_FILE_DENIED             46
#define B_MAXIMUM_OPEN_FILES                47
#define B_INVALID_ALT_SEQUENCE_DEF          48
#define B_KEY_TYPE_ERROR                    49
#define B_OWNER_ALREADY_SET                 50
#define B_INVALID_OWNER                     51
#define B_ERROR_WRITING_CACHE               52
#define B_INVALID_INTERFACE                 53
#define B_VARIABLE_PAGE_ERROR               54
#define B_AUTOINCREMENT_ERROR               55
#define B_INCOMPLETE_INDEX                  56
#define B_EXPANED_MEM_ERROR                 57
#define B_COMPRESS_BUFFER_TOO_SHORT         58
#define B_FILE_ALREADY_EXISTS               59
#define B_REJECT_COUNT_REACHED              60
#define B_SMALL_EX_GET_BUFFER_ERROR         61
#define B_INVALID_GET_EXPRESSION            62
#define B_INVALID_EXT_INSERT_BUFF           63
#define B_OPTIMIZE_LIMIT_REACHED            64
#define B_INVALID_EXTRACTOR                 65
#define B_RI_TOO_MANY_DATABASES             66
#define B_RIDDF_CANNOT_OPEN                 67
#define B_RI_CASCADE_TOO_DEEP               68
#define B_RI_CASCADE_ERROR                  69
#define B_RI_VIOLATION                      71
#define B_RI_REFERENCED_FILE_CANNOT_OPEN    72
#define B_RI_OUT_OF_SYNC                    73
#define B_END_CHANGED_TO_ABORT              74
#define B_RI_CONFLICT                       76
#define B_CANT_LOOP_IN_SERVER               77
#define B_DEAD_LOCK                         78
#define B_PROGRAMMING_ERROR                 79                           
#define B_CONFLICT                          80
#define B_LOCKERROR                         81
#define B_LOST_POSITION                     82
#define B_READ_OUTSIDE_TRANSACTION          83
#define B_RECORD_INUSE                      84
#define B_FILE_INUSE                        85
#define B_FILE_TABLE_FULL                   86
#define B_NOHANDLES_AVAILABLE               87
#define B_INCOMPATIBLE_MODE_ERROR           88

#define B_DEVICE_TABLE_FULL                 90
#define B_SERVER_ERROR                      91
#define B_TRANSACTION_TABLE_FULL            92
#define B_INCOMPATIBLE_LOCK_TYPE            93
#define B_PERMISSION_ERROR                  94
#define B_SESSION_NO_LONGER_VALID           95
#define B_COMMUNICATIONS_ERROR              96
#define B_DATA_MESSAGE_TOO_SMALL            97
#define B_INTERNAL_TRANSACTION_ERROR        98
#define B_REQUESTER_CANT_ACCESS_RUNTIME     99
#define B_NO_CACHE_BUFFERS_AVAIL            100
#define B_NO_OS_MEMORY_AVAIL                101
#define B_NO_STACK_AVAIL                    102
#define B_CHUNK_OFFSET_TOO_LONG             103
#define B_LOCALE_ERROR                      104
#define B_CANNOT_CREATE_WITH_BAT            105
#define B_CHUNK_CANNOT_GET_NEXT             106
#define B_CHUNK_INCOMPATIBLE_FILE           107

#define B_TRANSACTION_TOO_COMPLEX           109
#define B_NO_SYSTEM_LOCKS_AVAILABLE         130
#define B_MORE_THAN_5_CONCURRENT_USERS      133

/* Btrieve requestor status codes */
#define B_INSUFFICIENT_MEM_ALLOC    2001
#define B_INVALID_OPTION            2002
#define B_NO_LOCAL_ACCESS_ALLOWED   2003
#define B_SPX_NOT_INSTALLED         2004
#define B_INCORRECT_SPX_VERSION     2005
#define B_NO_AVAIL_SPX_CONNECTION   2006
#define B_INVALID_PTR_PARM          2007

/* Windows Client Return codes */
#define B_LOCK_PARM_OUTOFRANGE            1001
#define B_MEM_ALLOCATION_ERR              1002
#define B_MEM_PARM_TOO_SMALL              1003
#define B_PAGE_SIZE_PARM_OUTOFRANGE       1004                      
#define B_INVALID_PREIMAGE_PARM           1005
#define B_PREIMAGE_BUF_PARM_OUTOFRANGE    1006
#define B_FILES_PARM_OUTOFRANGE           1007                 
#define B_INVALID_INIT_PARM               1008             
#define B_INVALID_TRANS_PARM              1009              
#define B_ERROR_ACC_TRANS_CONTROL_FILE    1010                        
#define B_COMPRESSION_BUF_PARM_OUTOFRANGE 1011                           
#define B_TASK_LIST_FULL                  1013
#define B_STOP_WARNING                    1014
#define B_POINTER_PARM_INVALID            1015
#define B_ALREADY_INITIALIZED             1016
#define B_REQ_CANT_FIND_RES_DLL           1017
#define B_ALREADY_INSIDE_BTR_FUNCTION     1018
#define B_CALLBACK_ABORT                  1019

/***************************************************************************
                      File flag definitions
      The hexadecimal values below are unsigned values.
***************************************************************************/
#define VAR_RECS          0x0001
#define BLANK_TRUNC       0x0002
#define PRE_ALLOC         0x0004
#define DATA_COMP         0x0008
#define KEY_ONLY          0x0010
#define BALANCED_KEYS     0x0020
#define FREE_10           0x0040
#define FREE_20           0x0080
#define FREE_30           ( FREE_10 | FREE_20 )
#define DUP_PTRS          0x0100
#define SPECIFY_KEY_NUMS  0x0400
#define VATS_SUPPORT      0x0800

/***************************************************************************
                      Key Flag Definitions
     The hexadecimal values below are unsigned values.
***************************************************************************/
#define DUP             0x0001                   /* Duplicates allowed mask */
#define MOD             0x0002                       /* Modifiable key mask */
#define BIN             0x0004          /* Binary or extended key type mask */
#define NUL             0x0008                             /* Null key mask */
#define SEG             0x0010                        /* Segmented key mask */
#define ALT             0x0020         /* Alternate collating sequence mask */
#define DESC_KEY        0x0040                /* Key stored descending mask */
#define REPEAT_DUPS_KEY 0x0080            /* Dupes handled w/ unique suffix */
#define EXTTYPE_KEY     0x0100          /* Extended key types are specified */
#define MANUAL_KEY      0x0200   /* Manual key which can be optionally null */
                                        /* (then key is not inc. in B-tree) */
#define NOCASE_KEY      0x0400                      /* Case insensitive key */
#define KEYONLY_FILE    0x4000                        /* key only type file */
#define PENDING_KEY     0x8000         /* Set during a create or drop index */
#define ALLOWABLE_KFLAG_PRE6 0x037F          /* (before ver 6.0, no nocase. */


/***************************************************************************
                      Extended Key Types
***************************************************************************/
#define STRING_TYPE           0
#define INTEGER_TYPE          1
#define IEEE_TYPE             2
#define DATE_TYPE             3
#define TIME_TYPE             4
#define DECIMAL_TYPE          5
#define MONEY_TYPE            6
#define LOGICAL_TYPE          7
#define NUMERIC_TYPE          8
#define BFLOAT_TYPE           9
#define LSTRING_TYPE         10
#define ZSTRING_TYPE         11
#define UNSIGNED_BINARY_TYPE 14
#define AUTOINCREMENT_TYPE   15
#define STS                  17  
#define NUMERIC_SA           18

/***************************************************************************
                      ACS Signature Types
***************************************************************************/
#define ALT_ID               0xAC
#define COUNTRY_CODE_PAGE_ID 0xAD

#define _BTRCONST_H_INCLUDED
#endif
