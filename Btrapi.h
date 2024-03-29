#ifndef _BTRAPI_H_INCLUDED
/*************************************************************************
**
**  Copyright 1982-1995 Btrieve Technologies, Inc. All Rights Reserved
**
*************************************************************************/
/***************************************************************************
 BTRAPI.H
    This file contains prototypes for the DOS, Extended DOS, MS Windows,
    MS Windows NT, OS2, and NLM Btrieve call.   The calling application
    may be C or C++.

    You must define one of the following to your compiler in order to
    compile for a particular platform:

        BTI_DOS     - DOS                                     16-bit Apps
        BTI_WIN     - MS WINDOWS                              16-bit Apps
        BTI_OS2     - OS2                                     16-bit Apps
        BTI_NLM     - NetWare NLM                             32-bit Apps
        BTI_WIN_32  - Windows NT and Win32s                   32-bit Apps
        BTI_OS2_32  - OS2                                     32-bit Apps
        BTI_DOS_32R - Extended DOS with Rational + bstub.exe  32-bit Apps
        BTI_DOS_32P - Extended DOS with Phar Lap 6.0          32-bit Apps
        BTI_DOS_32B - Extended DOS with Borland PowerPack     32-bit Apps

    If you do not specify one of the above switches to your compiler,
    an error directive will halt the compilation.

    Modules are:
      btrapi.c     - compile and link with all apps except NLMs
      btrsamp.c    - sample program which can be compiled for any platform
      btitypes.h   - platform-independent data types
      blobhdr.h    - used by apps which use BTI_DOS_32B or BTI_DOS_32P
      btrapi.h     - included by all apps
      btrconst.h   - Btrieve constants
      bmemcopy.obj - used by apps which use BTI_DOS_32B or BTI_DOS_32P
      wbtrv32x.lib - used by Borland or WATCOM apps using BTI_WIN_32;
                     Microsoft Visual C++ apps use WBTRV32.LIB
                     ( see NT note below )

    Except for DOS or Extended DOS, the Btrieve application developer will
    also need either an import library or linker import statements to
    identify the imported Btrieve functions to the linker.  The imported
    functions are:

      MS Windows
      ----------
      WBTRCALL.LIB - WBTRVINIT, WBRQSHELLINIT, WBTRVSTOP, BTRCALL,
                     BTRCALLID, BTRCALLBACK, RQSHELLINIT
      NT and WIN32S
      -------------
      WBTRV32.LIB - WBTRVINIT, WBRQSHELLINIT, WBTRVSTOP, BTRCALL,
                    BTRCALLID, BTRCALLBACK, RQSHELLINIT ( see NT note below )
 
      OS2
      ---
      BTRCALLS.LIB - BTRVINIT,  BRQSHELLINIT,  BTRVSTOP,  BTRCALL

      NLM
      ---
      Use linker import statements - btrv, btrvID

    You will need to compile and link 'btrapi.c' if you call any of
    the following functions from the indicated platforms:
          BTRV .......... MS Windows, OS2, DOS
          BTRVID ........ MS Windows, OS2, DOS
          RQSHELLINIT ... MS Windows

    For 32-Bit DOS Rational Applications Using Bstub
    ------------------------------------------------
    If you are using the Rational Systems DOS Extender, DOS4G.EXE, along
    with BSTUB.EXE, you will need to define the plaform switch,
    BTI_DOS_32R to your compiler.  You also must link your application
    using the Rational linker, GLU.EXE.  You MUST have a '.def' file
    similar to the following which is used to create a 32-bit btrsamp.exe:

         btrsamp.def
         -----------
            LIBRARY btrsamp.dll
            DATA NONSHARED
            EXPORTS
               __ImportedFunctions_

    The module, btrapi.c, requires '__ImportedFunctions_' as shown in
    the above btrsamp.def.  This allows btrapi.c to call a function
    in Btrieve without using int386.

    Depending on your compiler's naming conventions, you may need to
    add a leading underscore to '_ImportedFunctions' at 3 locations in
    btrapi.c.  For example, when you compile with WATCOM using register-based
    parameter-passing, no change to '_ImportedFunctions' is needed.  But
    if you compile using stack-based parameter-passing, you will need to
    change '_ImportedFunctions' to '__ImportedFunctions' in btrapi.c.  We
    could have added compiler predefined macros to btrapi.c to handle
    this naming problem for you, except we were not assured of the
    predefined macros being present in all cases.
    
    The following is the GLU '.lnk' file for sqlsamp.exe using WATCOM
    libraries:

          btrsamp.lnk
          -----------
            btrsamp.obj                   
            btrapi.obj                   
            -format lin -stack 40000 -dbg -stub bstub.exe 
            e(btrsamp)                                 
            m(btrsamp)                                 
            dos32wc.lib                                
            clib3r.lib                                 
            math3r.lib                                 
            math387r.lib                               
            emu387.lib                                 

    You invoke GLU.EXE as follows:

            glu -deffile btrsamp.def @btrsamp.lnk


    For 32-Bit Borland PowerPack and Phar Lap DOS Applications
    -----------------------------------------------------------
    You must link 'bmemcopy.obj' with your application.

    For NT and Win32s Applications
    ------------------------------
    The WBTRV32.LIB import library containing 'WBTRV32.BTRCALL' and
    'WBTRV32.BTRCALLID' will only work with Microsoft Visual C++ v2.x.

    If you are using Borland or WATCOM, you will need to do one of the
    following:
    - create an import library from wbtrv32.dll using Borland or WATCOM
      tools
    - import WBTRV32.BTRCALL and WBTRV32.BTRCALLID with an import statement
      to the linker
    - use WBTRV32X.LIB, included with the interface modules

    Note that WBTRV32X.LIB is included with the interface modules and
    WBTRV32.LIB is included with the engine.

***************************************************************************/
#if !defined(BTI_WIN) && !defined(BTI_OS2) && !defined(BTI_DOS) \
&& !defined(BTI_NLM) && !defined(BTI_DOS_32R) && !defined(BTI_DOS_32P) \
&& !defined(BTI_DOS_32B) && !defined(BTI_WIN_32) &&  !defined(BTI_OS2_32)
#error You must define one of the following: BTI_WIN, BTI_OS2, BTI_DOS, BTI_NLM, BTI_DOS_32R, BTI_DOS_32P, BTI_DOS_32B, BTI_WIN_32, BTI_OS2_32
#endif

#include "btitypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************************
   PLATFORM-INDEPENDENT FUNCTIONS
     These APIs are the same on all platforms for which they have
     an implementation.  We recommend that you use only these two
     functions with Btrieve 6.x client components, and then issue the
     B_STOP operation prior to exiting your application.
****************************************************************************/
BTI_API BTRV(
           BTI_WORD     operation,
           BTI_VOID_PTR posBlock,
           BTI_VOID_PTR dataBuffer,
           BTI_WORD_PTR dataLength,
           BTI_VOID_PTR keyBuffer,
           BTI_SINT     keyNumber );

BTI_API BTRVID(
           BTI_WORD       operation,
           BTI_VOID_PTR   posBlock,
           BTI_VOID_PTR   dataBuffer,
           BTI_WORD_PTR   dataLength,
           BTI_VOID_PTR   keyBuffer,
           BTI_SINT       keyNumber,
           BTI_BUFFER_PTR clientID );

/***************************************************************************
   PLATFORM-SPECIFIC FUNCTIONS
      These APIs are specific to the indicated platform.  With the
      exception of BTRCALLBACK, we recommend that you use either
      BTRV or BTRVID, shown above.  Slight performance gains can be
      achieved by using BTRCALL or BTRCALLID.
****************************************************************************/
#if defined( BTI_NLM )
BTI_API btrv(
           BTI_WORD     operation,
           BTI_VOID_PTR posBlock,
           BTI_VOID_PTR dataBuffer,
           BTI_WORD_PTR dataLength,
           BTI_VOID_PTR keyBuffer,
           BTI_SINT     keyNumber );
#define BTRV( a, b, c, d, e, f )  btrv( a, b, c, d, e, f )

BTI_API btrvID(
           BTI_WORD       operation,
           BTI_VOID_PTR   posBlock,
           BTI_VOID_PTR   dataBuffer,
           BTI_WORD_PTR   dataLength,
           BTI_VOID_PTR   keyBuffer,
           BTI_SINT       keyNumber,
           BTI_BUFFER_PTR clientID );
#define BTRVID( a, b, c, d, e, f, g )  btrvID( a, b, c, d, e, f, g )
#endif

#if defined( BTI_WIN ) || defined( BTI_OS2 )
BTI_API BTRCALL(
           BTI_WORD     operation,
           BTI_VOID_PTR posBlock,
           BTI_VOID_PTR dataBuffer,
           BTI_WORD_PTR dataLength,
           BTI_VOID_PTR keyBuffer,
           BTI_BYTE     keyLength,
           BTI_CHAR     ckeynum );

BTI_API BTRCALLID(
           BTI_WORD       operation,
           BTI_VOID_PTR   posBlock,
           BTI_VOID_PTR   dataBuffer,
           BTI_WORD_PTR   dataLength,
           BTI_VOID_PTR   keyBuffer,
           BTI_BYTE       keyLength,
           BTI_CHAR       ckeynum,
           BTI_BUFFER_PTR clientID );
#endif

#if defined( BTI_WIN_32) || defined( BTI_OS2_32 )
#if defined( BTI_OS2_32 )
#define BTRCALL   BTRCALL32
#define BTRCALLID BTRCALLID32
#endif
BTI_API BTRCALL(
           BTI_WORD      operation,
           BTI_VOID_PTR  posBlock,
           BTI_VOID_PTR  dataBuffer,
           BTI_ULONG_PTR dataLength,
           BTI_VOID_PTR  keyBuffer,
           BTI_BYTE      keyLength,
           BTI_CHAR      ckeynum );

BTI_API BTRCALLID(
           BTI_WORD       operation,
           BTI_VOID_PTR   posBlock,
           BTI_VOID_PTR   dataBuffer,
           BTI_ULONG_PTR  dataLength,
           BTI_VOID_PTR   keyBuffer,
           BTI_BYTE       keyLength,
           BTI_CHAR       ckeynum,
           BTI_BUFFER_PTR clientID );
#endif

#if defined( BTI_WIN ) || defined( BTI_WIN_32 )
BTI_API BTRCallback(
           BTI_WORD                   iAction,
           BTI_WORD                   iOption,
           BTI_CB_FUNC_PTR_T          fCallBackFunction,
           BTI_CB_FUNC_PTR_T BTI_FAR *fPreviousCallBackFunction,
           BTI_VOID_PTR               bUserData,
           BTI_VOID_PTR BTI_FAR      *bPreviousUserData,
           BTI_BUFFER_PTR             bClientID );
#endif


/***************************************************************************
   HISTORICAL FUNCTIONS
      These APIs were needed prior to Btrieve 6.x client
      components.  Older applications may still call these functions,
      and the Btrieve 6.x client component will do the appropriate
      thing, depending on the platform.  New applications using the
      6.x client components do NOT have to call these functions.
****************************************************************************/
#if defined( BTI_WIN ) || defined( BTI_WIN_32 )
#define BTRVINIT WBTRVINIT
#define BTRVSTOP WBTRVSTOP
BTI_API WBTRVINIT( BTI_CHAR_PTR option );
BTI_API WBRQSHELLINIT( BTI_CHAR_PTR option );
BTI_API WBTRVSTOP( BTI_VOID );
BTI_API RQSHELLINIT( BTI_CHAR_PTR options );
#endif

#if defined( BTI_OS2 )
BTI_API BTRVINIT( BTI_CHAR_PTR options );
BTI_API BTRVSTOP( BTI_VOID );
BTI_API BRQSHELLINIT( BTI_VOID );
#endif

#if defined( BTI_OS2_32 )
BTI_API BTRVINIT32( BTI_CHAR_PTR options );
BTI_API BTRVSTOP32( BTI_VOID );
BTI_API BRQSHELLINIT32( BTI_VOID );
#endif

#ifdef __cplusplus
}
#endif

#define _BTRAPI_H_INCLUDED
#endif
