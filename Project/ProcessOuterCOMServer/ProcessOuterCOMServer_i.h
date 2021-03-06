

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Dec 17 22:55:26 2015
 */
/* Compiler settings for ..\..\include\ProcessOuterCOMServer\ProcessOuterCOMServer.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ProcessOuterCOMServer_i_h__
#define __ProcessOuterCOMServer_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOuterCOMExport_FWD_DEFINED__
#define __IOuterCOMExport_FWD_DEFINED__
typedef interface IOuterCOMExport IOuterCOMExport;

#endif 	/* __IOuterCOMExport_FWD_DEFINED__ */


#ifndef __OuterCOMExport_FWD_DEFINED__
#define __OuterCOMExport_FWD_DEFINED__

#ifdef __cplusplus
typedef class OuterCOMExport OuterCOMExport;
#else
typedef struct OuterCOMExport OuterCOMExport;
#endif /* __cplusplus */

#endif 	/* __OuterCOMExport_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IOuterCOMExport_INTERFACE_DEFINED__
#define __IOuterCOMExport_INTERFACE_DEFINED__

/* interface IOuterCOMExport */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOuterCOMExport;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F57ABC48-EC7A-4EF5-9449-7572DB9D47A6")
    IOuterCOMExport : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetName( 
            /* [in] */ BSTR sName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetName( 
            /* [retval][out] */ BSTR *sName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOuterCOMExportVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOuterCOMExport * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOuterCOMExport * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOuterCOMExport * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOuterCOMExport * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOuterCOMExport * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOuterCOMExport * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOuterCOMExport * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IOuterCOMExport * This,
            /* [in] */ BSTR sName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IOuterCOMExport * This,
            /* [retval][out] */ BSTR *sName);
        
        END_INTERFACE
    } IOuterCOMExportVtbl;

    interface IOuterCOMExport
    {
        CONST_VTBL struct IOuterCOMExportVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOuterCOMExport_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOuterCOMExport_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOuterCOMExport_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOuterCOMExport_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOuterCOMExport_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOuterCOMExport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOuterCOMExport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOuterCOMExport_SetName(This,sName)	\
    ( (This)->lpVtbl -> SetName(This,sName) ) 

#define IOuterCOMExport_GetName(This,sName)	\
    ( (This)->lpVtbl -> GetName(This,sName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOuterCOMExport_INTERFACE_DEFINED__ */



#ifndef __ProcessOuterCOMServerLib_LIBRARY_DEFINED__
#define __ProcessOuterCOMServerLib_LIBRARY_DEFINED__

/* library ProcessOuterCOMServerLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ProcessOuterCOMServerLib;

EXTERN_C const CLSID CLSID_OuterCOMExport;

#ifdef __cplusplus

class DECLSPEC_UUID("C40205AC-280F-44FE-9F77-A542F2AD10E0")
OuterCOMExport;
#endif
#endif /* __ProcessOuterCOMServerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


