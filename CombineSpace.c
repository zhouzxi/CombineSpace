/**********************************************************************
* 版权所有 (C)2015, Zhou Zhaoxiong。
*
* 文件名称：CombineSpace.c
* 文件标识：无
* 内容摘要：多空格合并
* 其它说明：无
* 当前版本：V1.0
* 作   者：Zhou Zhaoxiong
* 完成日期：20150331
*
**********************************************************************/
#include <stdio.h>
#include <string.h>


// 重定义数据类型
typedef unsigned char UINT8;
typedef unsigned int  UINT32;
typedef signed   int  INT32;

// 函数声明
void CombineSpace(UINT8 *pszOldStr, UINT8 *pszNewStr);

/**********************************************************************
* 功能描述：主函数
* 输入参数：无
* 输出参数：无
* 返 回 值：无
* 其它说明：无
* 修改日期       版本号        修改人           修改内容
* -------------------------------------------------------------------
* 20150331       V1.0      Zhou Zhaoxiong        创建
***********************************************************************/
INT32 main()
{
       UINT8 szOldStr[100] = {0};
       UINT8 szNewStr[100] = {0};

       // 第一次处理
       memcpy(szOldStr, " Hello,   everyone! ", sizeof(szOldStr)-1);
       CombineSpace(szOldStr, szNewStr);
       printf("The first case: OldStr=%s, NewStr=%s.\n", szOldStr, szNewStr);

       // 第二次处理
       memset(szOldStr, 0x00, sizeof(szOldStr));
       memset(szNewStr, 0x00, sizeof(szNewStr));
       memcpy(szOldStr, " My name   is   ZhouZhaoxiong! ", sizeof(szOldStr)-1);
       CombineSpace(szOldStr, szNewStr);
       printf("The second case: OldStr=%s, NewStr=%s.\n", szOldStr, szNewStr);

       return 0;
}


/**********************************************************************
* 功能描述：合并多个连续空格为一个, 并去掉首位的空格
* 输入参数：pszOldStr-合并空格之前的字符串
* 输出参数：pszNewStr-合并空格之后的字符串
* 返 回 值：无
* 其它说明：无
* 修改日期       版本号        修改人          修改内容
* -------------------------------------------------------------------
* 20150331       V1.0     Zhou Zhaoxiong        创建
***********************************************************************/
void CombineSpace(UINT8 *pszOldStr, UINT8 *pszNewStr)
{
    UINT32 iOldIndex        = 0;
    UINT32 iNewIndex        = 0;
    UINT8  chSingleChar     = '\0';
    UINT8  iIsSpace         = 0;
    UINT8  szTmpNewStr[100] = {0};

    if ((NULL == pszOldStr) || (NULL == pszNewStr))
    {
        printf("CombineSpace: input parameter(s) is NULL!");
        return;
    }

    while ('\0' != (chSingleChar = pszOldStr[iOldIndex++]))
    {
        if (chSingleChar == ' ')   // 多个连续空格只保留一个
        {
            if (iIsSpace == 0)
            {
                iIsSpace = 1;
                szTmpNewStr[iNewIndex++] = chSingleChar;
            }
        }
        else
        {
            iIsSpace = 0;
            szTmpNewStr[iNewIndex++] = chSingleChar;
        }
    }

    // 如果最后一个字符是空格, 则将其去掉
    if (szTmpNewStr[strlen(szTmpNewStr)-1] == ' ')
    {
        szTmpNewStr[strlen(szTmpNewStr)-1] = '\0';
    }

    // 如果第一个字符是空格, 则将其去掉
    if (szTmpNewStr[0] == ' ')
    {
        memcpy(pszNewStr, szTmpNewStr+1, strlen(szTmpNewStr)-1);
    }
    else
    {
        memcpy(pszNewStr, szTmpNewStr, strlen(szTmpNewStr));
    }

    return;
}
