
#ifndef _MMA_BASTET_INTERFACE_H_
#define _MMA_BASTET_INTERFACE_H_

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include  "vos.h"
#include  "PsTypeDef.h"


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 宏定义
*****************************************************************************/


/*****************************************************************************
  3 枚举定义
*****************************************************************************/

enum BST_RATMODE_ENUM
{
    BST_RATMODE_GSM                     = 0x00,
    BST_RATMODE_WCDMA                   = 0x01,
    BST_RATMODE_LTE                     = 0x02,
    BST_RATMODE_TDS                     = 0x03,
    BST_RATMODE_BUTT
};
typedef VOS_UINT8  BST_RATMODE_ENUM_UINT8;

/*****************************************************************************
  4 全局变量声明
*****************************************************************************/


/*****************************************************************************
  5 消息头定义
*****************************************************************************/


/*****************************************************************************
  6 消息定义
*****************************************************************************/

enum MMA_BASTET_MSG_ID_ENUM
{
    /* MMA发给Bastet的消息原语 */
    ID_MMA_BASTET_RAT_MODE_IND                  = 0,   /* _H2ASN_MsgChoice MMA_BASTET_RAT_MODE_IND_STRU */
    ID_MMA_BASTET_CS_SERVICE_IND,                      /* _H2ASN_MsgChoice MMA_BASTET_CS_SERVICE_IND_STRU */
    ID_MMA_BASTET_SERVICE_STATUE_IND,                  /* _H2ASN_MsgChoice MMA_BASTET_SERVICE_STATUS_IND_STRU */
    ID_MMA_BASTET_ID_ENUM_BUTT
};
typedef VOS_UINT32  MMA_BASTET_MSG_ID_ENUM_UINT32;

/*****************************************************************************
  7 STRUCT定义
*****************************************************************************/



typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;         /*_H2ASN_Skip*/
    BST_RATMODE_ENUM_UINT8              enRatMode;           /* 当前网络制式*/
    VOS_UINT8                           aucReserve1[3];     /* 字节对齐 */
}MMA_BASTET_RAT_MODE_IND_STRU;
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;        /*_H2ASN_Skip*/
    PS_BOOL_ENUM_UINT8                  bCSConnected;       /* 是否存在CS业务*/
    VOS_UINT8                           aucReserve1[3];     /* 字节对齐 */
}MMA_BASTET_CS_SERVICE_IND_STRU;
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;           /*_H2ASN_Skip*/
    PS_BOOL_ENUM_UINT8                  bCsInservice;           /*CS是否有服务*/
    PS_BOOL_ENUM_UINT8                  bPsInservice;           /*PS是否有服务*/
    VOS_UINT8                           aucReserve1[2];       /* 字节对齐 */
}MMA_BASTET_SERVICE_STATUS_IND_STRU;



/*****************************************************************************
  8 UNION定义
*****************************************************************************/


/*****************************************************************************
  9 OTHERS定义
*****************************************************************************/
/*****************************************************************************
  H2ASN顶级消息结构定义
*****************************************************************************/
typedef struct
{
    MMA_BASTET_MSG_ID_ENUM_UINT32       enMsgID;    /*_H2ASN_MsgChoice_Export MMA_BASTET_MSG_ID_ENUM_UINT32*/

    VOS_UINT8                           aucMsgBlock[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          MMA_BASTET_MSG_ID_ENUM_UINT32
    ****************************************************************************/
}MMA_BASTET_MSG_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    MMA_BASTET_MSG_DATA                 stMsgData;
}MmaBastetInterface_MSG;


/*****************************************************************************
  10 函数声明
*****************************************************************************/


#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif

