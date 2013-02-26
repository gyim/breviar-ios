/***************************************************************/
/*                                                             */
/* vstudio.h                                                   */
/* (c)2007 | Juraj Vid�ky | videky@breviar.sk                  */
/*                                                             */
/* description | kv�li Visual Studio 2005 Express Edition      */
/*               systeme program pracuje; ovplyvnuje tvorbu    */
/*               linkov, DEBUG #define, veci pre loggovanie a  */
/*               export                                        */
/* document history                                            */
/*   2007-02-14a.D. | vytvoren�                                */
/*                                                             */
/***************************************************************/

#ifndef __VSTUDIO_H
#define __VSTUDIO_H

#if (_MSC_VER >= 1400)       // VC8+
#pragma warning(disable : 4996)
	#ifndef _CRT_SECURE_NO_DEPRECATE
	#define _CRT_SECURE_NO_DEPRECATE
	#endif /* _CRT_SECURE_NO_DEPRECATE */
	#ifndef _CRT_NONSTDC_NO_DEPRECATE
	#define _CRT_NONSTDC_NO_DEPRECATE
	#endif /* _CRT_NONSTDC_NO_DEPRECATE */
#endif   // VC8+

#endif // __VSTUDIO_H
