/****************************************************************/
/*      MIDI��̬�����    HugeSoft������    1999��7������       */
/*                                ����:MMX                      */
/*      �����װ���ڲ���MIDI�ļ���windows API,�ɷ����          */
/*      ����MIDI�ļ�.                                           */
/*      ���粥��MIDI�ļ���WM_CREATE:�в������¸�ʽ:             */
/*          ��MIDI�ļ���MID_Open(FileName);                   */
/*          ����MIDI�ļ���MID_Play();���ɲ���                   */
/*      ����Project��Setting��Linkѡ���м���midi.lib            */
/*      vfw32.lib winmm.lib ������                              */
/*      ������Win95/Win98/WinNT4.0,VC 5.0��VC 6.0���.          */
/*      �������⣬��e-mail:mmx_hugesoft@163.net                 */
/****************************************************************/

#include <windows.h>
#include <windowsx.h>
#include <vfw.h>

#ifdef __cplusplus
/* Assume C declarations for C++ */
extern "C" { 
#endif

/*    ��������MID_GetDevices                        */
/*    ���ã�����ϵͳ���õ�֧��MIDI�����������Ŀ    */
/*    ��������                                      */
/*    ��ֵ��ϵͳ���õ�֧��MIDI�����������Ŀ        */
	extern int MID_GetDevices (void);
	
/*    ��������MID_Open                              */
/*    ���ã����豸                                */
/*    ��������                                      */
/*    ��ֵ���ɹ�ΪTRUE��ʧ��ΪFALSE                 */
	extern BOOL MID_Open (char *);
	
/*    ��������MID_Close                             */
/*    ���ã��ر��ļ����ر�MCI�豸                   */
/*    ��������                                      */
/*    ��ֵ����                                      */
	extern void MID_Close (void);
	
/*    ��������MID_Play                              */
/*    ���ã��ӵ�ǰλ�ò����ļ�                      */
/*    ��������                                      */
/*    ��ֵ���ɹ�ΪTRUE��ʧ��ΪFALSE                 */
	extern BOOL MID_Play (void);
	
/*    ��������MID_Stop                              */
/*    ���ã�ֹͣ�����ļ�                            */
/*    ��������                                      */
/*    ��ֵ����                                      */
	extern void MID_Stop (void);
	
/*    ��������MID_Pause                             */
/*    ���ã���ͣ�����ļ�                            */
/*    ��������                                      */
/*    ��ֵ����                                      */
	extern void MID_Pause (void);
	
/*    ��������MID_GetTotalLength                    */
/*    ���ã�ָ��MIDI�ļ����ܳ���                    */
/*    ������int* pnMinutes,����ʧ��Ϊ-1             */
/*          int* pnSeconds,����ʧ��Ϊ-1             */
/*    ��ֵ����                                      */
	extern void MID_GetTotalLength (int *, int*);
	
/*    ��������MID_GetMinutes                        */
/*    ���ã������÷��ӱ�ʾ��MIDI�ļ���ǰλ��        */
/*    ��������                                      */
/*    ��ֵ��ʧ��Ϊ-1                                */
	extern int MID_GetMinutes (void);
	
/*    ��������MID_GetSeconds                        */
/*    ���ã����������ʾ��MIDI�ļ���ǰλ��          */
/*    ��������                                      */
/*    ��ֵ��ʧ��Ϊ-1                                */
	extern int MID_GetSeconds (void);
	
/*    ��������MID_IsPlaying                         */
/*    ���ã��������򲥷�״̬���ṩ��ͣ״̬          */
/*    �ļ���ͣʱIsPlaying()����TRUE                 */
/*    ������BOOl* bPaused                           */
/*	��ֵ���ļ���ͣʱIsPlaying()����TRUE         */
/*            ����ΪFALSE                           */
	extern BOOL MID_IsPlaying (BOOL *);
	
/*    ��������MID_SeekTo                            */
/*    ���ã�ѡ��MIDI�ļ��ڵ��ض�λ�ã�              */
/*          ���ļ����ڲ��ţ�������                  */
/*    ������int nMinute,int nSecond                 */
/*    ��ֵ���ɹ�ΪTRUE��ʧ��ΪFALSE                 */
	extern BOOL MID_SeekTo (int, int);
	
/*    ��������MID_SkipForWard                       */
/*    ���ã�ʹ�ļ���ǰ��n�룬���ļ�����             */
/*          ���ţ�������                            */
/*    ������int nSecond                             */
/*    ��ֵ����                                      */
	extern void MID_SkipForward (int);
	
/*    ��������MID_SKipBack                          */
/*    ���ã�ʹ�ļ������n�룬���ļ�����             */
/*          ���ţ�������                            */
/*    ������int nSecond                             */
/*    ��ֵ����                                      */
	extern void MID_SkipBack (int);
	
/*    ��������MID_GetDivisionTpe                    */
/*    ���ã��ж�MIDI�ļ�������                      */
/*    ��������                                      */
/*    ��ֵ������ΪMCI_SEQ_DIV_PPQN,����0��          */
/*          ����Ϊ-1                                */
	extern int MID_GetDivisionType (void);
	
/*    ��������MID_GetTempo                          */
/*    ���ã�����MIDI�ļ��Ĳ����ٶ�                  */
/*    ��������                                      */
/*    ��ֵ��int nTempo                              */
	extern int MID_GetTempo (void);
	
/*    ��������MID_GetTempo                          */
/*    ���ã��ı�MIDI�ļ��Ĳ����ٶ�                  */
/*    ������int nTempo                              */
/*    ��ֵ����                                      */
	extern void MID_SetTempo (int);
	
	extern BOOL m_bOpened, m_bPaused, m_bPlaying;
	extern WORD m_wDeviceID;
#ifdef __cplusplus
}
#endif