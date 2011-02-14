/************************************************************************/
/*                                                                      */
/* dbzaltar.cpp                                                         */
/* (c)1999-2008 | Juraj Videky | videky@breviar.sk                      */
/*                                                                      */
/* description | program tvoriaci stranky pre liturgiu hodin            */
/* document history                                                     */
/*   09/02/2000A.D. | urobene .cpp kvoli dvojakosti funkcie             */
/*                    sviatky_svatych(); a inym veciam                  */
/*   23/02/2000A.D. | ponechal som tu "stare", zle pokusy,              */
/*                    oznacene WRONG_23_02_2000                         */
/*   05/04/2000A.D. | uz su dokoncene vsetky sviatky svatych.           */
/*                    odstranil som label_... pre slavnosti             */
/*                    obdobia cez rok, lebo tam nevadi, ze              */
/*                    slavnost padne na nedelu, lebo ma vyssiu prioritu */
/*   29/03/2000A.D. | ukoncene vsetky mesiace MES_JAN - MES_DEC         */
/*   06/09/2001A.D. | tento popis                                       */
/*   07/09/2001A.D. | opravene: sv. Brigity (sviatok)                   */
/*   26/09/2001A.D. | opravene: sv. Terezie Benedikty (sviatok)         */
/*   2003-06-30a.D. | zmeny pre spomienku neposkvrn.srdca PM            */
/*   2003-08-11a.D. | -Wall upozornila na / * within comments           */
/*   2003-08-13a.D. | odstranene DEBUG_MODLITBA_CEZ_DEN                 */
/*                  - zaltar() doplnena o modlitbu cez den              */
/*                  - nastavovanie doplnkovej psalmodie                 */
/*                  - #define presunute do header-u dbzaltar.h          */
/*   2003-08-21a.D. | pokusy s posvatnymi citaniami (zalmy)             */
/*   2003-10-07a.D. | zmena v _SET_SPOLOCNE_VECI_NEDELA                 */
/*   2003-11-20a.D. | zmeny pre posvatne citanie (adv1)                 */
/*   2003-12-07a.D. | posvatne citanie (adv2)                           */
/*   2004-04-28a.D. | posvatne citanie (cez rok)                        */
/*                  - rozsafne strcpy zmenene na mystrcpy               */
/*   2004-08-14a.D. | Sviatok Sv. Jany Frantiöky de Chantal             */
/*                    presunuty z 12. decembra na 12. augusta           */
/*                  - Sviatok Bl. Zdenky Schelingovej,                  */
/*                    panny a muËenice, ako 2. moznost 30.jula          */
/*   2004-08-31a.D. | nastavenie modlitby pre posv.cit.o.c.r.           */
/*   2004-09-03a.D. | zmena v modlitbe (na nedelnu kolektu)             */
/*   2004-09-23a.D. | pridany sv. pater Pio                             */
/*   2005-03-26a.D. | pridane posvatne citania (Trencin)                */
/*   2005-03-27a.D. | CHAR_MODL_* z funkcie pismenko_modlitby           */
/*                    do liturgia.h                                     */
/*                  - upravy v psalmodii pre posvatne citanie           */
/*   2005-07-22a.D. | pokus o doplnenie udajov k posv.cit.svsv          */
/*   2005-07-27a.D. | posv. ËÌtania pre vlastnÈ Ëasti sv‰t˝ch           */
/*   2005-08-05a.D. | 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloË.          */
/*                    Ëasti sviatkov sv‰t˝ch nasledovne:                */
/*                    - I. zv.(advent, vianoce) a II. zv.(pÙst)         */
/*                    - II. zv‰zok (veæk· noc)                          */
/*                    - III. a IV. zv‰zok (obdobie cez rok)             */
/*   2005-08-08a.D. | dokonËenÈ vlastnÈ Ëasti augusta                   */
/*   2005-10-13a.D. | dokonË. vlastnÈ Ëasti sept-okt (len kÛd)          */
/*   2005-11-20a.D. | zaË. modlitba cez deÚ, adv1                       */
/*   2005-11-24a.D. | skorektnenÈ: su_zalmy_nedela1tyzden               */
/*   2006-01-19a.D. | dokonËen˝ janu·r a febru·r, sv.muûov              */
/*   2006-01-19a.D. | nedokonËenÈ: "2006-01-19_LABEL"                   */
/*   2006-01-24a.D. | pridanÈ zaltar_zvazok()                           */
/*   2006-01-25a.D. | dokonËenÈ pÙstne obdobie (mcd+posv.ËÌt.)          */
/*   2006-01-25a.D. | su_zalmy_nedela1tyzden > ZALMY1NE_FIX             */
/*   2006-02-02a.D. | pridanÈ posv. ËÌtania pre æs PM v sobotu          */
/*   2006-02-04a.D. | su_zalmy_vlastne > ZALMY_ZO_SVIATKU               */          
/*   2006-02-05a.D. | dokonËenÈ vianoËnÈ obdobie I (ËÌt.+mcd)           */
/*   2006-02-07a.D. | ZALTAR_... pre funkciu zaltar_zvazok();           */
/*                  - doplnenÈ modl.cez deÚ - sviatky sv‰t˝ch           */
/*   2006-08-07a.D. | pridanÈ sv. muûov/ûien, Ëo ûili v manû.           */
/*   2006-08-08a.D. | skutky mil., rehoænÌkov, vychov·vateæov           */
/*   2006-08-18a.D. | zmena int na short int (staËÌ 32tis.)             */
/*   2006-08-19a.D. | pridanie liturgickej farby                        */
/*   2006-09-07a.D. | dokonËen· lokaliz·cia mesiacov JAN-AUG            */
/*   2006-09-12a.D. | dokonËen· lokaliz·cia mesiaca SEP+opravy          */
/*   2006-09-13a.D. | dokonËen· lokaliz·cia mesiacov OKT+NOV            */
/*   2006-12-04a.D. | oprava hymnu pre Ëesk˝ komplet·¯                  */
/*   2007-07-17a.D. | oprava hymnu mcd pre niektorÈ sl·vnosti           */
/*   2007-08-31a.D. | oprava 30.AUG na sviatok                          */
/*   2007-10-02a.D. | dokonËenie zohæadnenia smernÌc pre sviatky sv‰t˝ch*/
/*                    (rozlÌöenie sl·v+sviat/ostat.)                    */
/*   2007-10-23a.D. | dokonËenie zohæadnenia smernÌc pre                */
/*                    sviatky sv‰t˝ch (kresp, prosby pre rch/v)         */
/*   2007-11-14a.D. | zjednoduöenie define-ov pre sviatky P·na          */
/*                    zadefinovanÈ "_vlastne_slavenie_"                 */
/*                  - dokonËenie invitatÛria pre liturgickÈ obdobia     */
/*   2007-11-20a.D. | dokonËenie invitatÛria pre spoloËnÈ Ëasti sv‰t˝ch */
/*   2007-12-03a.D. | antifÛna na magnifikat pre 4. adventn˙ nedeæu-opr.*/
/*   2007-12-04a.D. | ant.na magn.+modl.posv.ËÌt. pre 3. adv.nedeæu-opr.*/
/*   2008-01-18a.D. | oprava: pri volanÌ file_name_kompletorium()       */
/*                    treba uchovaù a potom obnoviù pÙvodnÈ _file       */
/*   2008-01-23a.D. | opravenÈ zvazok_breviara[] a zaltar_zvazok()      */
/*   2008-02-22a.D. | doplnenÈ modlitby cez deÚ (sv‰tci) pre III.zv‰zok */
/*   2008-02-27a.D. | oprava liturgicke_obdobie() pre nanebovzatie PM   */
/*   2008-03-12a.D. | ökaredÈ nadr·tovanÈ rieöenie (prekladanie 2008),  */
/*                    bude potrebnÈ naimplementovaù krajöie             */
/*   2008-03-30a.D. | upravenÈ antifÛny pre mcd, _vtroj_antifony()      */
/*   2008-04-04a.D. | opravenÈ kompletÛrium pre veæk.trojdnie+zel.ötvrt.*/
/*                  - oprava ûalmov a chv·l. pre 1. veöp. 2.veæk.nedele */
/*   2008-05-14a.D. | opravenÈ modlitby cez deÚ pre 3. a 14. m·ja       */
/*   2008-05-16a.D. | pre prvÈ veöpery narodenia p·na in˝ hymnus (cz)   */
/*                                                                      */
/*                                                                      */
/* notes |                                                              */
/*   * povodne islo o dva fajly, dbzaltar.c a dbsvaty.c                 */
/*                                                                      */
/************************************************************************/

//#define DETAIL_LOG_SVATY /* 22/02/2000A.D. */
//#define DETAIL_LOG_GLOBAL_DEN /* 22/02/2000A.D. */

#include "vstudio.h"

#include "dbzaltar.h" /* 22/02/2000A.D. -- rozdelene na .h a .cpp subor */

char _anchor_head[SMALL];

#include "liturgia.h"

#include "myexpt.h" /* export do suboru alebo na konzolu printf */
/* povodne tu bolo aj include "sets.c", ale to je nizsie */
#include "mylog.h"
#include <string.h>
#include "mystring.h" /* pridane 2003-08-11 kvoli _INIT_DM */
#include "breviar.h"  /* pridane 2003-08-13 kvoli _global_opt5 */

#define LOG_ciara_sv Log("  -------------------------\n");

/* 2007-09-27: kvÙli debugovaniu pod Ruby zruöenÈ koment·re vo v˝pisoch*/
/* 2005-03-26: Presunute na zaciatok */
/* 2003-06-30 pre lahsie debugovanie obohateny vypis */
//#define set_LOG_litobd Log("   set(litobd): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file, _anchor)
#define set_LOG_litobd Log("   set(litobd): %s: s˙bor `%s', kotva `%s'\n", nazov_modlitby(modlitba), _file, _anchor)
/* 2004-04-28 pre lahsie debugovanie obohateny vypis pre pc */
//#define set_LOG_litobd_pc Log("   set(litobd): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file_pc, _anchor)
#define set_LOG_litobd_pc Log("   set(litobd): %s: s˙bor `%s', kotva `%s'\n", nazov_modlitby(modlitba), _file_pc, _anchor)
/* 2004-04-28 pre lahsie debugovanie obohateny vypis pre pc-tyzden */
//#define set_LOG_litobd_pc_tyzden Log("   set(litobd): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file_pc_tyzden, _anchor)
#define set_LOG_litobd_pc_tyzden Log("   set(litobd): %s: s˙bor `%s', kotva `%s'\n", nazov_modlitby(modlitba), _file_pc_tyzden, _anchor)

/* #define (stringove konstanty) presunute do header-u dbzaltar.h, 2003-08-15 */
/* globalne premenne prehodene do liturgia.h, 17/02/2000A.D. */
/* ------------------------------------------------------------------- */

/*
 * 2007-11-07, doplnenÈ: öpeci·lne spr·vanie pre 2. november: VäETK›CH VERN›CH ZOSNUL›CH, spomienka
 */
#define su_zalmy_vlastne ((_global_den.denvt == DEN_NEDELA) || (_global_den.typslav == SLAV_SLAVNOST) || (_global_den.typslav == SLAV_SVIATOK) || ((_global_den.den == 2) && (_global_den.mesiac - 1 == MES_NOV)))
#define su_zalmy_prve_vespery_vlastne ((_global_den.denvt == DEN_NEDELA) || (_global_den.typslav == SLAV_SLAVNOST) || ((_global_den.den == 2) && (_global_den.mesiac - 1 == MES_NOV)))
#define su_kcit_kresp_1cit_prosby_vlastne ((_global_den.typslav == SLAV_SLAVNOST) || (_global_den.typslav == SLAV_SVIATOK) || ((_global_den.den == 2) && (_global_den.mesiac - 1 == MES_NOV))) // rovnakÈ kritÈrium pre kr·tke ËÌtanie (rch, v) a 1. ËÌtanie (posv. ËÌtania); moûno pouûiù aj na 2. ËÌtanie posv. ËÌt.; 2007-10-23: pouûiù aj pre kr·tke responzÛrium (rch, v) a prosby (rch, v)
#define su_antifony_vlastne(m) ((_global_den.typslav == SLAV_SLAVNOST) || ((_global_den.typslav == SLAV_SVIATOK) && ((m == MODL_RANNE_CHVALY) || (m == MODL_POSV_CITANIE) || (m == MODL_VESPERY))) || ((_global_den.den == 2) && (_global_den.mesiac - 1 == MES_NOV)))

/* 2007-09-28: upravenÈ priraÔovanie spoloËnej Ëasti; berie sa iba v prÌpade sl·vnostÌ resp. sviatkov,
 * pre spomienky a æubovoænÈ spomienky by malo ostaù to, Ëo je zo dÚa (2007-10-02, 2007-10-22)
 * porov. vöeobecnÈ smernice, body 
 * o posv‰tnom ËÌtanÌ:
 *		62. Nasleduje psalmÛdia skladaj˙ca sa z troch ûalmov (alebo z ich ËastÌ, ak prÌsluönÈ ûalmy s˙ dlhöie). Vo VeækonoËnom trojdnÌ, v dÚoch VeækonoËnej okt·vy a vo VianoËnej okt·ve, ako aj na sl·vnosti a sviatky s˙ ûalmy vlastnÈ s vlastn˝mi antifÛnami.
 *		66. Spravidla treba ËÌtaù biblickÈ ËÌtanie, ktorÈ je z vlastnej Ëasti liturgickÈho obdobia, a to podæa SmernÌc Ë. 140-155.
 *		    No na sl·vnosti a sviatky sa berie biblickÈ ËÌtanie z vlastnej Ëasti alebo zo spoloËnej Ëasti.
 *		67. DruhÈ ËÌtanie s responzÛriom sa berie buÔ z knihy liturgie hodÌn, alebo z osobitnÈho lekcion·ra, ktor˝ poskytuje v‰ËöÌ v˝ber t˝chto ËÌtanÌ (o Úom je reË v Ë. 161). ZvyËajne to b˝va ËÌtanie, ktorÈ sa nach·dza vo vlastnej Ëasti liturgickÈho obdobia.
 *		    Na sl·vnosti a sviatky sv‰t˝ch sa berie vlastnÈ hagiografickÈ ËÌtanie, ak takÈ nie je, ËÌta sa druhÈ ËÌtanie z prÌsluönej spoloËnej Ëasti na sviatky sv‰t˝ch. Na spomienky sv‰t˝ch, keÔ ich sl·veniu niË neprek·ûa, berie sa druhÈ ËÌtanie hagiografickÈ, a to namiesto druhÈho ËÌtania, ktorÈ na ten deÚ pripad· (porov. Ë. 166, 235).
 *		154. Sl·vnosti a sviatky maj˙ vlastnÈ ËÌtania; ak ich niet, ber˙ sa zo spoloËnej Ëasti na sviatky sv‰t˝ch.
 * o antifÛnach:
 *		117. Na sl·vnosti s˙ vlastnÈ antifÛny na posv‰tnÈ ËÌtanie, na rannÈ chv·ly, na terciu, sextu a nÛnu a na veöpery; ak nie s˙, ber˙ sa zo spoloËnej Ëasti. To istÈ platÌ pre sviatky na posv‰tnÈ ËÌtanie, na rannÈ chv·ly a na veöpery.
 *		119. AntifÛny na Benediktus a Magnifikat v ofÌciu urËitÈho liturgickÈho obdobia sa ber˙ z vlastnej Ëasti liturgickÈho obdobia, ak s˙; in·Ë z beûnÈho ûalt·ra. Na sl·vnosti a sviatky sa ber˙ z vlastnej Ëasti, ak s˙; in·Ë zo spoloËnej Ëasti. Na spomienky, ktorÈ nemaj˙ vlastn˙ antifÛnu, berie sa antifÛna zo spoloËnej Ëasti alebo z beûnÈho vöednÈho dÚa.
 * o ûalmoch:
 *		134. Na sl·vnosti a sviatky, vo VeækonoËnom trojdnÌ a v dÚoch VeækonoËnej a VianoËnej okt·vy s˙ pre posv‰tnÈ ËÌtanie urËenÈ vlastnÈ ûalmy v s˙lade s tradÌciou; ich vhodnosù osvetæuje zvyËajne antifÛna. 
 *		     Tak je to aj pri modlitbe cez deÚ na niektorÈ sl·vnosti P·na a vo VeækonoËnej okt·ve.
 *		     Na rannÈ chv·ly sa ber˙ ûalmy a chv·lospev z nedele prvÈho t˝ûdÚa v ûalt·ri.
 *		     Na prvÈ veöpery sl·vnostÌ sa ber˙ ûalmy podæa starod·vneho zvyku zo sÈrie Laud·te.
 *		     DruhÈ veöpery sl·vnostÌ a veöpery sviatkov maj˙ ûalmy i chv·lospev vlastnÈ.
 *		     Na modlitbu cez deÚ sl·vnostÌ, okrem t˝ch, o ktor˝ch sa uû hovorilo, a ak nepripadn˙ na nedeæu, ber˙ sa ûalmy z doplnkovÈho cyklu (gradu·lne).
 *		     Na sviatky sa na modlitbu cez deÚ ber˙ ûalmy z prÌsluönÈho dÚa v t˝ûdni.
 *		135. V ostatn˝ch prÌpadoch sa ber˙ ûalmy z beûnÈho ûalt·ra, ibaûe by boli urËenÈ vlastnÈ antifÛny alebo vlastnÈ ûalmy.
 * o kr·tkom ËÌtanÌ:
 *		157. ZostavenÈ s˙ teda ötyri t˝ûdennÈ sÈrie kr·tkych ËÌtanÌ v ObdobÌ Ñcez rokì, ktorÈ s˙ vloûenÈ do ûalt·ra, takûe sa ËÌtanie poËas ötyroch t˝ûdÚov denne menÌ. Okrem toho s˙ t˝ûdennÈ sÈrie pre AdventnÈ, VianoËnÈ, PÙstne a VeækonoËnÈ obdobie.
 *		     OsobitnÈ vlastnÈ ËÌtania s˙ na sl·vnosti a sviatky a pre niektorÈ spomienky.
 *		     Pre kompletÛrium je sÈria ËÌtanÌ na jeden t˝ûdeÚ.
 * na kr·tke ËÌtanie nadv‰zuje kr·tke responzÛrium; treba sa k nemu zrejme spr·vaù rovnako ako ku kr·tkemu ËÌtaniu
 * o prosb·ch (Ë. 179-193): -- doplnenÈ 2007-10-23
 *		182. V˝razom Ñprosbyì sa oznaËuj˙ jednak prÌhovory vo veöper·ch a jednak vz˝vania na zasv‰tenie dÚa Bohu pri rann˝ch chv·lach.
 *		183. Pre v‰Ëöiu pestrosù, ale najm‰ preto, aby sa lepöie vyjadrili mnohorakÈ potreby Cirkvi aj æudÌ podæa rozliËn˝ch stavov, skupÌn, osÙb, okolnostÌ a Ëias, uv·dzaj˙ sa rozliËnÈ formuly prosieb na jednotlivÈ dni ûalt·rovÈho cyklu v ObdobÌ Ñcez rokì, na ostatnÈ posv‰tnÈ obdobia liturgickÈho roka a na niektorÈ sviatoËnÈ prÌleûitosti.
 *			 
 * o z·vereËnej modlitbe:
 *		199. Na rannÈ chv·ly a veöpery sa t·to modlitba berie z prÛpria v nedele, v adventnÈ, vianoËnÈ, pÙstne a veækonoËnÈ vöednÈ dni, Ôalej na sl·vnosti, sviatky a spomienky. Vo vöednÈ dni v ObdobÌ Ñcez rokì sa t·to modlitba berie zo ûalt·ra, aby vyjadrila vlastn˙ povahu t˝chto posv‰tn˝ch hodÌn.
 *		200. V modlitbe cez deÚ (predpoludnÌm, napoludnie a popoludnÌ) sa t·to modlitba berie z prÛpria v nedele, v adventnÈ, vianoËnÈ, pÙstne a veækonoËnÈ vöednÈ dni, Ôalej na sl·vnosti a sviatky. V ostatnÈ dni sa pouûÌvaj˙ modlitby, ktorÈ vystihuj˙ povahu kaûdej z t˝chto posv‰tn˝ch hodÌn a s˙ uvedenÈ v ûalt·ri.
 * a napokon cel· Ëasù v z·vere smernÌc, body 218-240
 *			 
 * sl·venie sl·vnostÌ, sviatkov a spomienok resp. æubovoæn˝ch spomienok
 * --- sl·vnosti ---
 *		225. Sl·vnosti maj˙ prvÈ veöpery veËer predch·dzaj˙ceho dÚa.
 *		226. Pri prv˝ch i druh˝ch veöper·ch je vlastn˝ hymnus, antifÛny, kr·tke ËÌtanie s responzÛriom a z·vereËn· modlitba; ak nie s˙ vlastnÈ, ber˙ sa zo spoloËnej Ëasti. 
 *			 Obidva ûalmy v prv˝ch veöper·ch sa ber˙ zvyËajne zo sÈrie ûalmov Laud·te (t. j. ûalmy 113, 117, 135, 146, 147, 1-11, 147, 12-20), podæa starod·vnej tradÌcie; chv·lospev z NovÈho z·kona je vyznaËen˝ na prÌsluönom mieste. Pri druh˝ch veöper·ch s˙ ûalmy a chv·lospev vlastnÈ. Prosby s˙ vlastnÈ alebo zo spoloËnej Ëasti.
 *		227. V rann˝ch chv·lach je vlastn˝ hymnus, antifÛna, kr·tke ËÌtanie s responzÛriom a z·vereËn· modlitba. Ak nie s˙ vlastnÈ, ber˙ sa zo spoloËnej Ëasti. éalmy vöak treba vziaù z nedele prvÈho t˝ûdÚa zo ûalt·ra. Prosby s˙ vlastnÈ alebo zo spoloËnej Ëasti.
 *		228. V posv‰tnom ËÌtanÌ je vöetko vlastnÈ: hymnus, antimÛny a ûalmy, ËÌtania i responzÛri·. PrvÈ ËÌtanie je biblickÈ, druhÈ hagiografickÈ. Ak ide o sv‰tÈho, ktor˝ m· iba lok·lnu ˙ctu a nem· v prÛpriu osobitnÈ Ëasti, vöetko sa berie zo spoloËnej Ëasti.
 *			 Na konci posv‰tnÈho ËÌtania je hymnus Teba, Boûe, chv·lime a vlastn· modlitba.
 *		229. V modlitbe cez deÚ, Ëiûe predpoludnÌm, napoludnie a popoludnÌ (tercia, sexta a nÛna), sa berie, ak nie je uvedenÈ inak, hymnus dÚa. éalmy s˙ z doplnkovÈho cyklu s vlastnou antifÛnou; v nedeæu sa vöak ber˙ ûalmy z nedele prvÈho t˝ûdÚa zo ûalt·ra; kr·tke ËÌtanie a z·vereËn· modlitba s˙ vlastnÈ.
 *			 Na niektorÈ sl·vnosti P·na sa uv·dzaj˙ osobitnÈ ûalmy.
 *		230. V kompletÛriu je vöetko z nedele, a to po prv˝ch i druh˝ch veöper·ch. 
 * --- sviatky ---
 *		231. Sviatky nemaj˙ prvÈ veöpery, ak nejde o sviatky P·na, ktorÈ pripadn˙ na nedeæu. V posv‰tnom ËÌtanÌ, v rann˝ch chv·lach a vo veöper·ch je vöetko ako na sl·vnosti.
 *		232. V modlitbe cez deÚ, Ëiûe predpoludnÌm, napoludnie a popoludnÌ (tercia, sexta a nÛna), sa berie hymnus dÚa; ûalmy s antifÛnami sa ber˙ z fÈrie, ak si osobitn˝ dÙvod alebo tradÌcia nevyûaduje v modlitbe cez deÚ vlastn˙ antifÛnu, Ëo sa uvedie na prÌsluönom mieste. Kr·tke ËÌtanie a z·vereËn· modlitba s˙ vlastnÈ.
 *		233. KompletÛrium sa recituje ako v obyËajnÈ dni. 
 * --- spomienky a æubovoænÈ spomienky ---
 *		234.    Medzi spomienkami z·v‰zn˝mi a æubovoæn˝mi, ak sa sl·via, nie je nijak˝ rozdiel, pokiaæ ide o usporiadanie ofÌcia; net˝ka sa to æubovoæn˝ch spomienok, ktorÈ sa prÌpadne vyskytn˙ v privilegovan˝ch obdobiach. 
 *	--- a) Spomienky pripadaj˙ce na obyËajnÈ dni ---
 *		235. V posv‰tnom ËÌtanÌ, v rann˝ch chv·lach a vo veöper·ch: 
 *				* ûalmy s antifÛnami sa ber˙ z beûnÈho vöednÈho dÚa, ak nie s˙ antifÛny a ûalmy vlastnÈ, uvedenÈ na prÌsluön˝ch miestach; 
 *				* antifÛna na invitatÛrium, hymnus, kr·tke ËÌtanie, antifÛny na Benediktus a Magnifikat a prosby, ak s˙ vlastnÈ, musia sa recitovaù o prÌsluönom sv‰tcovi, in·Ë sa ber˙ buÔ zo spoloËnej Ëasti, alebo z beûnÈho vöednÈho dÚa; 
 *				* z·vereËn· modlitba je vûdy o sv‰tcovi; 
 *				* v posv‰tnom ËÌtanÌ je biblickÈ ËÌtanie s responzÛriom z PÌsma, pripadaj˙ce na beûn˝ deÚ. DruhÈ ËÌtanie je hagiografickÈ s vlastn˝m responzÛriom alebo zo spoloËnej Ëasti. Ak nie je vlastnÈ ËÌtanie, berie sa z textu Otcov z prÌsluönÈho dÚa. 
 *		Vynech·va sa hymnus Teba, Boûe, chv·lime.
 *		236. V modlitbe cez deÚ, Ëiûe predpoludnÌm, napoludnie a popoludnÌ, a v kompletÛriu sa neberie niË z ofÌcia o sv‰tom, vöetko je zo vöednÈho dÚa.
 *	--- b) Spomienky pripadaj˙ce na privilegovanÈ dni ---
 *		237. V nedele, na sl·vnosti a na sviatky, Ôalej na Popolcov˙ stredu, vo Veækom t˝ûdni a vo VeækonoËnej okt·ve sa vynech·vaj˙ vöetky spomienky, ak by pripadli na tieto dni.
 *		238. Vo vöedn˝ch dÚoch od 17. do 24. decembra, vo VianoËnej okt·ve a vo vöedn˝ch dÚoch v PÙstnom obdobÌ sa nesl·vi nijak· z·v‰zn· spomienka, a to ani v partikul·rnych kalend·roch. Tie spomienky, ktorÈ azda na PÙstne obdobie pripadaj˙, sa v tom roku povaûuj˙ za æubovoænÈ spomienky.
 *		239. Ak by niekto chcel v t˝ch obdobiach osl·viù sv‰tÈho, ktorÈho spomienka pripad· na ten deÚ: 
 *				* v posv‰tnom ËÌtanÌ po ËÌtanÌ z Otcov a po responzÛriu z vlastnej Ëasti liturgickÈho obdobia pripojÌ vlastnÈ hagiografickÈ ËÌtanie s responzÛriom a uzavrie modlitbou o sv‰tom; 
 *				* okrem toho mÙûe v rann˝ch chv·lach a vo veöper·ch po z·vereËnej modlitbe ó jej konkl˙zia sa vynech· ó pripojiù antifÛnu (vlastn˙ alebo zo spoloËnej Ëasti) a modlitbu o sv‰tom. 
 *	--- c) Sobotn· spomienka o Panne M·rii ---
 *		240. V soboty v ObdobÌ Ñcez rokì, keÔ s˙ dovolenÈ æubovoænÈ spomienky, mÙûe sa t˝m ist˝m spÙsobom sl·viù æubovoæn· spomienka o Panne M·rii s vlastn˝m ËÌtanÌm. 
 * 
 * teda treba upraviù, aby kr·tke responzÛrium (rch, v) bolo vûdy rovnako prid·vanÈ ako kr·tke ËÌtanie,
 * napokon aby prosby boli na sl·vnosti a sviatky vlastnÈ resp. zo spoloËnej Ëasti a na (æub.) spomienky prim·rne zo dÚa
 * 
 * jedin· vec nie je dorieöen·: ak smernice umoûÚuj˙ vziaù pre (æubovoænÈ) spomienky Ëasti buÔ zo spoloËnej Ëasti, alebo zo dÚa - my vöetko berieme zo dÚa
 * 2007-10-23a.D.
 */

/* ------------------------------------------------------------------- */
/* nasledujuca pasaz bola kedysi fajl sets.c */

void _set_popis(short int modlitba, const char *file, const char *anchor){ /* pridana 05/04/2000A.D. */
	switch(modlitba){
		/* 2006-10-13: Pridan˝ popis aj pre invitatÛrium a kompletÛrium */
		case MODL_INVITATORIUM:
			mystrcpy(_global_modl_invitatorium.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_invitatorium.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_KOMPLETORIUM:
			mystrcpy(_global_modl_prve_kompletorium.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_kompletorium.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_KOMPLETORIUM:
			mystrcpy(_global_modl_kompletorium.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_kompletorium.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* 2005-07-22: Pridan˝ popis aj pre posv‰tnÈ ËÌtanie a modlitbu cez deÚ */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.popis.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.popis.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_hymnus(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		/* 2006-10-13: Pridan˝ hymnus aj pre kompletÛrium */
		case MODL_PRVE_KOMPLETORIUM:
			mystrcpy(_global_modl_prve_kompletorium.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_kompletorium.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_KOMPLETORIUM:
			mystrcpy(_global_modl_kompletorium.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_kompletorium.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.hymnus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.hymnus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_antifona1(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		/* 2006-10-13: Pridan· antifÛna aj pre invitatÛrium a kompletÛrium */
		case MODL_INVITATORIUM:
			mystrcpy(_global_modl_invitatorium.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_invitatorium.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_KOMPLETORIUM:
			mystrcpy(_global_modl_prve_kompletorium.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_kompletorium.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_KOMPLETORIUM:
			mystrcpy(_global_modl_kompletorium.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_kompletorium.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* pridane 2003-11-20 */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.antifona1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.antifona1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_antifona2(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		/* 2006-10-17: Pridan· antifÛna aj pre kompletÛrium (niektorÈ pouûÌvaj˙ 2) */
		case MODL_PRVE_KOMPLETORIUM:
			mystrcpy(_global_modl_prve_kompletorium.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_kompletorium.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_KOMPLETORIUM:
			mystrcpy(_global_modl_kompletorium.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_kompletorium.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* pridane 2003-11-20 */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.antifona2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.antifona2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_antifona3(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* pridane 2003-11-20 */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.antifona3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.antifona3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_zalm1(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		/* 2006-10-13: Pridan˝ ûalm aj pre invitatÛrium a kompletÛrium */
		case MODL_INVITATORIUM:
			mystrcpy(_global_modl_invitatorium.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_invitatorium.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_KOMPLETORIUM:
			mystrcpy(_global_modl_prve_kompletorium.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_kompletorium.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_KOMPLETORIUM:
			mystrcpy(_global_modl_kompletorium.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_kompletorium.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* modlitby cez den maju spolocnu psalmodiu, 
		 * pokial si pouzivatel nevyziada doplnkovu psalmodiu (seria 1-3),
		 * preto nastavujem aj spolocne pre vsetky modlitby
		 * 2003-08-13
		 */
		case MODL_CEZ_DEN_VSETKY:
		case MODL_PREDPOLUDNIM:
			/* predpoludnim */
			mystrcpy(_global_modl_cez_den_9.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			if(modlitba == MODL_PREDPOLUDNIM) break;
		case MODL_NAPOLUDNIE:
			/* napoludnie */
			mystrcpy(_global_modl_cez_den_12.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			if(modlitba == MODL_NAPOLUDNIE) break;
		case MODL_POPOLUDNI:
			/* popoludni */
			mystrcpy(_global_modl_cez_den_3.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.zalm1.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.zalm1.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

#define _set_rchvalospev _set_zalm2
void _set_zalm2(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		/* 2006-10-17: Pridan˝ ûalm aj pre kompletÛrium (niektorÈ pouûÌvaj˙ 2) */
		case MODL_PRVE_KOMPLETORIUM:
			mystrcpy(_global_modl_prve_kompletorium.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_kompletorium.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_KOMPLETORIUM:
			mystrcpy(_global_modl_kompletorium.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_kompletorium.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* modlitby cez den maju spolocnu psalmodiu, 
		 * pokial si pouzivatel nevyziada doplnkovu psalmodiu (seria 1-3),
		 * preto nastavujem aj spolocne pre vsetky modlitby
		 * 2003-08-13
		 */
		case MODL_CEZ_DEN_VSETKY:
		case MODL_PREDPOLUDNIM:
			/* predpoludnim */
			mystrcpy(_global_modl_cez_den_9.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			if(modlitba == MODL_PREDPOLUDNIM) break;
		case MODL_NAPOLUDNIE:
			/* napoludnie */
			mystrcpy(_global_modl_cez_den_12.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			if(modlitba == MODL_NAPOLUDNIE) break;
		case MODL_POPOLUDNI:
			/* popoludni */
			mystrcpy(_global_modl_cez_den_3.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.zalm2.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.zalm2.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

#define _set_vchvalospev _set_zalm3
void _set_zalm3(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* modlitby cez den maju spolocnu psalmodiu, 
		 * pokial si pouzivatel nevyziada doplnkovu psalmodiu (seria 1-3),
		 * preto nastavujem aj spolocne pre vsetky modlitby
		 * 2003-08-13
		 */
		case MODL_CEZ_DEN_VSETKY:
		case MODL_PREDPOLUDNIM:
			/* predpoludnim */
			mystrcpy(_global_modl_cez_den_9.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			if(modlitba == MODL_PREDPOLUDNIM) break;
		case MODL_NAPOLUDNIE:
			/* napoludnie */
			mystrcpy(_global_modl_cez_den_12.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			if(modlitba == MODL_NAPOLUDNIE) break;
		case MODL_POPOLUDNI:
			/* popoludni */
			mystrcpy(_global_modl_cez_den_3.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.zalm3.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.zalm3.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

/* pri posvatnom citani plati pre 1. citanie */
#define _set_citanie1 _set_kcitanie
/* pridane 2003-11-20 */

void _set_kcitanie(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		/* 2006-10-13: PridanÈ kr·tke ËÌtanie aj pre kompletÛrium */
		case MODL_PRVE_KOMPLETORIUM:
			mystrcpy(_global_modl_prve_kompletorium.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_kompletorium.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_KOMPLETORIUM:
			mystrcpy(_global_modl_kompletorium.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_kompletorium.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* pridane 2003-11-20 */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.kcitanie.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.kcitanie.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

/* pri posvatnom citani plati pre responz _pred_ citaniami */
void _set_kresponz(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		/* 2006-10-13: Pridan˝ kr·tky responz aj pre kompletÛrium */
		case MODL_PRVE_KOMPLETORIUM:
			mystrcpy(_global_modl_prve_kompletorium.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_kompletorium.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_KOMPLETORIUM:
			mystrcpy(_global_modl_kompletorium.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_kompletorium.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* pridane 2003-11-20 */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.kresponz.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.kresponz.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

/* pri posvatnom citani plati magn/ben pre 2. citanie */
#define _set_citanie2 _set_benediktus
/* pridane 2003-11-20 */

#define _set_magnifikat _set_benediktus
void _set_benediktus(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.benediktus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.benediktus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.benediktus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.benediktus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.benediktus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.benediktus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* pridane 2003-11-20 */
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.benediktus.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.benediktus.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_prosby(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.prosby.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.prosby.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.prosby.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.prosby.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.prosby.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.prosby.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}

void _set_modlitba(short int modlitba, const char *file, const char *anchor){
	switch(modlitba){
		case MODL_RANNE_CHVALY:
			mystrcpy(_global_modl_ranne_chvaly.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_ranne_chvaly.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_POSV_CITANIE:
			mystrcpy(_global_modl_posv_citanie.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_posv_citanie.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_9:
			mystrcpy(_global_modl_cez_den_9.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_9.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_12:
			mystrcpy(_global_modl_cez_den_12.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_12.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_CEZ_DEN_3:
			mystrcpy(_global_modl_cez_den_3.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_cez_den_3.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_VESPERY:
			mystrcpy(_global_modl_vespery.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_vespery.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_PRVE_VESPERY:
			mystrcpy(_global_modl_prve_vespery.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_vespery.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		/* 2006-10-24: pridanÈ kompletÛrium; tieû m· svoju z·vereËn˙ modlitbu */
		case MODL_PRVE_KOMPLETORIUM:
			mystrcpy(_global_modl_prve_kompletorium.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_prve_kompletorium.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
		case MODL_KOMPLETORIUM:
			mystrcpy(_global_modl_kompletorium.modlitba.file, file, MAX_STR_AF_FILE);
			mystrcpy(_global_modl_kompletorium.modlitba.anchor, anchor, MAX_STR_AF_ANCHOR);
			break;
	}/* switch(modlitba) */
}
/* koniec pasaze, co bola kedysi sets.c -- 22/02/2000A.D. */
/* ------------------------------------------------------------------- */

/* files - nazvy suborov pre zaltar styroch tyzdnov */
char _file[SMALL]; /* nazov s˙boru, napr. _1ne.htm */
char _file_pc[SMALL]; /* nazov fajlu pre posvatne citania; pridane 2003-11-20 */
char _file_pc_tyzden[SMALL]; /* nazov fajlu pre posvatne citania v zavislosti od tyzdna (obdobie cez rok); pridane 2004-04-28 */
char _file_orig[SMALL]; /* nazov s˙boru, do ktorÈho sa v prÌpade kompletÛria doËasne odloûÌ pÙvodn˝ s˙bor; 2008-01-18 */
/* 2008-01-18: doplnenÈ "funkcie" na store/restore pÙvodnÈho filename */
#define file_name_zapamataj()	sprintf(_file_orig, _file);
#define file_name_obnov()		sprintf(_file, _file_orig);

/* tyzzal == 1 .. 4,
 * den == 0 (DEN_NEDELA) .. 6 (DEN_SOBOTA) */
void file_name_zaltar(short int den, short int tyzzal){
	sprintf(_file, "_%d%s.htm", tyzzal, nazov_dn_asci[den]);
}
void file_name_litobd(short int litobd){
	sprintf(_file, "%s", nazov_obd_htm[litobd]);
}
/* pridane 2003-11-20 - iny subor pre posvatne citania */
void file_name_litobd_pc(short int litobd){
	sprintf(_file_pc, "%s", nazov_obd_htm_pc[litobd]);
}
/* pridanÈ 2006-10-24 - eöte in˝ s˙bor pre kompletÛrium
 * 2007-12-06: rozöÌren˝ s˙bor pre cezroËnÈ obdobie (vhodn˝ pre v‰Ëöinu ostatn˝ch) a niektorÈ obdobia so öpeci·lnymi "potrebami"
 */
void file_name_kompletorium(short int litobd){
	if(litobd == OBD_CEZ_ROK){
		sprintf(_file, "%s", nazov_obd_KOMPLETORIUM);
	}
	else{
		sprintf(_file, "%s", nazov_obd_htm[litobd]);
	}
}
/* pridane 2004-04-28 - iny subor pre posvatne citania v obdobi cez rok (pre kazdy tyzden iny) */
void file_name_litobd_pc_tyzden(short int litobd, short int tyzden){
	sprintf(_file_pc_tyzden, "%02d%s", tyzden, nazov_obd_htm_pc[litobd]);
}

/* anchors - nazvy kotiev pre zaltar styroch tyzdnov */
char _anchor[SMALL];
/* tyzzal == 1 .. 4,
 * den == 0 (DEN_NEDELA) .. 6 (DEN_SOBOTA),
 * modlitba == MODL_...,
 * anchor == ANCHOR_... */
char pismenko_modlitby(short int modlitba){
	/* 2005-03-27: Upravene na konstanty, presunute do liturgia.h */
	switch(modlitba){
		case MODL_INVITATORIUM       : return CHAR_MODL_INVITATORIUM;
		case MODL_RANNE_CHVALY       : return CHAR_MODL_RANNE_CHVALY;
		case MODL_POSV_CITANIE       : return CHAR_MODL_POSV_CITANIE;
		case MODL_CEZ_DEN_9          : return CHAR_MODL_CEZ_DEN_9;
		case MODL_CEZ_DEN_12         : return CHAR_MODL_CEZ_DEN_12;
		case MODL_CEZ_DEN_3          : return CHAR_MODL_CEZ_DEN_3;
		case MODL_VESPERY            : return CHAR_MODL_VESPERY;
		case MODL_KOMPLETORIUM       : return CHAR_MODL_KOMPLETORIUM;
		case MODL_NEURCENA           : return CHAR_MODL_NEURCENA; /* toto by sa nemalo */
		case MODL_PRVE_VESPERY       : return CHAR_MODL_PRVE_VESPERY;
		case MODL_PRVE_KOMPLETORIUM  : return CHAR_MODL_PRVE_KOMPLETORIUM;
		case MODL_DRUHE_VESPERY      : return CHAR_MODL_DRUHE_VESPERY; /* toto by sa nemalo */
		case MODL_DRUHE_KOMPLETORIUM : return CHAR_MODL_DRUHE_KOMPLETORIUM; /* toto by sa nemalo */
	}/* switch(modlitba) */
	return 0;
}/* pismenko_modlitby(); */

void anchor_name_zaltar(short int den, short int tyzzal, short int modlitba, char *anchor){
	sprintf(_anchor, "_%d%s%c_%s",
		tyzzal, nazov_DN_asci[den], pismenko_modlitby(modlitba), anchor);
}

/* 2007-09-27: kvÙli debugovaniu pod Ruby zruöenÈ koment·re vo v˝pisoch*/
//#define set_LOG_zaltar	Log("   set(zaltar): %s: `%s', <!--{...:%s}-->\n", nazov_modlitby(modlitba), _file, _anchor)
#define set_LOG_zaltar	Log("   set(zaltar): %s: s˙bor `%s', kotva `%s'\n", nazov_modlitby(modlitba), _file, _anchor)

/* nasledovnÈ funkcie pouûÌvanÈ pre ûalt·r (cezroËnÈ obdobie); 2007-12-06 */

void set_hymnus(short int den, short int tyzzal, short int modlitba){
	/* pridanÈ Ëasti pre kompletÛrium, 2006-10-13 */
	/* hymnus pre kompletÛrium je v Ëeskej verzii pre kaûd˝ deÚ in˝, 2006-12-04 */
	if((modlitba == MODL_KOMPLETORIUM) || (modlitba == MODL_PRVE_KOMPLETORIUM)){
		file_name_zapamataj();
		file_name_kompletorium(OBD_CEZ_ROK);
		if(_global_jazyk == JAZYK_CZ){
			sprintf(_anchor, "%c_%s_%s", 
				pismenko_modlitby(modlitba), ANCHOR_HYMNUS, nazov_DN_asci[den]);
		}
		else{
			sprintf(_anchor, "%c_%s_%d", 
				pismenko_modlitby(modlitba), ANCHOR_HYMNUS, (den + tyzzal) % 2);
		}
		_set_hymnus(modlitba, _file, _anchor);
		set_LOG_zaltar;
		file_name_obnov();
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		/* 2003-08-15: pridana modlitba cez den, ma hymny rovnake pre cele obdobie cez rok 
		 * 2008-04-08: pre mcd v Ëeskom brevi·ri je pre cezroËnÈ obdobie moûnÈ braù buÔ hymnus zo ûalt·ra,
		 *             alebo pre 1./3. (1) resp. 2./4. (2) t˝ûdeÚ ûalt·ra z "vlastnej Ëasti" pre 
		 */
			file_name_litobd(OBD_CEZ_ROK);
		if(_global_jazyk == JAZYK_CZ){
			sprintf(_anchor, "%c_%s_%d_%s", 
				pismenko_modlitby(modlitba), ANCHOR_HYMNUS, (2 - (tyzzal % 2)), nazov_DN_asci[den]);
		}
		else{
			sprintf(_anchor, "%c_%s_%d", 
				pismenko_modlitby(modlitba), ANCHOR_HYMNUS, (den + tyzzal) % 2);
		}
		_set_hymnus(modlitba, _file, _anchor);
		set_LOG_zaltar;
	}
	else{ /* nie modlitba cez den */
		/* prvy a treti, resp. druhy a stvrty tyzden maju rovnake */
		if(tyzzal == 3)
			tyzzal = 1;
		else if(tyzzal == 4)
			tyzzal = 2;
		/* 2005-03-26: Pridane odvetvenie pre posvatne citania */
		if(modlitba == MODL_POSV_CITANIE){
			file_name_litobd_pc(OBD_CEZ_ROK);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_HYMNUS);
			_set_hymnus(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
		}
		else{
			file_name_zaltar(den, tyzzal);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_HYMNUS);
			_set_hymnus(modlitba, _file, _anchor);
			set_LOG_zaltar;
		}
	}
}

#define _set_antifony_velk_pc(den, tyzzal, modlitba) {\
		/* 1. antifona */\
		file_name_litobd_pc(OBD_CEZ_ROK);\
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA1V);\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
		/* 2. antifona */\
		file_name_litobd_pc(OBD_CEZ_ROK);\
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA2V);\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
		/* 3. antifona */\
		file_name_litobd_pc(OBD_CEZ_ROK);\
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA3V);\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
}

/* 2007-12-20: doplnen· podmienka pre niektorÈ öpeciality v ûalt·ri: doteraz bolo "zvazok != 2" resp. "zvazok == 2"
 * pouûÌva sa v set_antifony() a eöte v zaltar_zvazok()
 * doplnenÈ po upozornenÌ ötudenta teolÛgie Standu <brozkas@post.cz>, preposlal p. Franta
 */
#define je_odlisny_zaltar ((zvazok == 1) || (zvazok == 2))

void set_antifony(short int den, short int tyzzal, short int zvazok, short int modlitba){
	/* 2006-01-24: pÙvodn· podmienka zosilnen·, keÔûe pre obyËajnÈ dni veækonoËnÈho 
	 * obdobia (2.-7. t˝ûdeÚ) moûno braù antifÛny pre posv‰tnÈ ËÌtania z cezroËnÈho obdobia
	 * 
	 * 2006-01-24: taktieû pridan˝ ÔalöÌ parameter; pre niektorÈ dni v II. zv‰zku s˙ 
	 * inÈ ûalmy aj antifÛny
	 * 
	 * 2006-02-09: podmienka zmenen·: 
	 * aj pre nedeænÈ posv. ËÌtanie s˙ antifÛny v file_name_litobd_pc(OBD_CEZ_ROK);
	 * 
	 */
	short int povodny_tyzzal;
	povodny_tyzzal = tyzzal; /* 2006-01-24: uloûÌme pÙvodn˙ hodnotu */

	/* pridanÈ Ëasti pre kompletÛrium, 2006-10-24; nepotrebujeme ûiadne ostatnÈ kroky */
	if((modlitba == MODL_KOMPLETORIUM) || (modlitba == MODL_PRVE_KOMPLETORIUM)){
		file_name_zapamataj();
		file_name_kompletorium(OBD_CEZ_ROK);
		sprintf(_anchor, "_%s%c_%s", nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);
		_set_antifona1(modlitba, _file, _anchor);
		set_LOG_zaltar;
		if( 
			((modlitba == MODL_KOMPLETORIUM) && (_global_modl_kompletorium.pocet_zalmov == 2))
		||	((modlitba == MODL_PRVE_KOMPLETORIUM) && (_global_modl_prve_kompletorium.pocet_zalmov == 2))
		){
			sprintf(_anchor, "_%s%c_%s", nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);
			_set_antifona2(modlitba, _file, _anchor);
			set_LOG_zaltar;
		}
		file_name_obnov();
	}
	else if(
			((_global_den.litobd == OBD_VELKONOCNE_I) ||
			(_global_den.litobd == OBD_VELKONOCNE_II))
		&& 
			(modlitba != MODL_POSV_CITANIE)
	){
		/* velkonocne obdobie */
		file_name_zaltar(den, tyzzal);
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA1V);
		_set_antifona1(modlitba, _file, _anchor);
		set_LOG_zaltar;
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA2V);
		_set_antifona2(modlitba, _file, _anchor);
		set_LOG_zaltar;
		/* antifona na vecerny hymnus je rovnaka pre prvy a treti,
		 * resp. druhy a stvrty tyzden zaltara */
		if((modlitba == MODL_VESPERY) || (modlitba == MODL_PRVE_VESPERY)){
			if(tyzzal == 3)
				tyzzal = 1;
			else if(tyzzal == 4)
				tyzzal = 2;
		}
		file_name_zaltar(den, tyzzal);
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA3V);
		_set_antifona3(modlitba, _file, _anchor);
		set_LOG_zaltar;
	}
	/* 2006-02-09: Pre posv. ËÌtania nedieæ veækonoËnÈho obdobia samostatne nastavÌme,
	 *             hoci sme si vedomÌ, ûe pre 5., 6. a 7. veækonoËn˙ nedeæu to bude potrebnÈ zmeniù
	 */
	else if(
			((_global_den.litobd == OBD_VELKONOCNE_I) ||
			(_global_den.litobd == OBD_VELKONOCNE_II))
		&& 
			(modlitba = MODL_POSV_CITANIE)
		&& 
			(_global_den.den = DEN_NEDELA)
	){
		_set_antifony_velk_pc(den, tyzzal, modlitba);
	}
	else{
		/* 2006-10-24: PridanÈ odvetvenie pre invitatÛrium
		 * 2005-03-26: Pridane odvetvenie pre posvatne citania */

		/* 1. antifona */
		if(modlitba == MODL_POSV_CITANIE){
			file_name_litobd_pc(OBD_CEZ_ROK);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA1);
			_set_antifona1(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
		}
		else if(modlitba == MODL_INVITATORIUM){
			/* antifÛna pre invitatÛrium je rovnak· pre prv˝ a tretÌ,
			 * resp. druh˝ a ötvrt˝ t˝ûdeÚ ûalt·ra */
			if(tyzzal == 3)
				tyzzal = 1;
			else if(tyzzal == 4)
				tyzzal = 2;
			file_name_zaltar(den, tyzzal);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA1);
			_set_antifona1(modlitba, _file, _anchor);
			set_LOG_zaltar;
		}
		else{
			file_name_zaltar(den, tyzzal);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA1);
			_set_antifona1(modlitba, _file, _anchor);
			set_LOG_zaltar;
		}

		/* 2. antifona */
		if(modlitba == MODL_POSV_CITANIE){
			file_name_litobd_pc(OBD_CEZ_ROK);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA2);
			_set_antifona2(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
		}
		else if(modlitba != MODL_INVITATORIUM){
			file_name_zaltar(den, tyzzal);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA2);
			_set_antifona2(modlitba, _file, _anchor);
			set_LOG_zaltar;
		}

	/* 3. antifona */
		/* antifona na vecerny hymnus je rovnaka pre prvy a treti,
		 * resp. druhy a stvrty tyzden zaltara */
		if((modlitba == MODL_VESPERY) || (modlitba == MODL_PRVE_VESPERY)){
			if(tyzzal == 3)
				tyzzal = 1;
			else if(tyzzal == 4)
				tyzzal = 2;
		}
		if(modlitba == MODL_POSV_CITANIE){
			file_name_litobd_pc(OBD_CEZ_ROK);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA3);
			_set_antifona3(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
		}
		else if(modlitba != MODL_INVITATORIUM){
			file_name_zaltar(den, tyzzal);
			anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_ANTIFONA3);
			_set_antifona3(modlitba, _file, _anchor);
			set_LOG_zaltar;
		}
	}
	/* 2006-01-24: napokon upravÌme niektorÈ antifÛny pre II. zv‰zok, posv‰tnÈ ËÌtanie */
	if((je_odlisny_zaltar) && (modlitba == MODL_POSV_CITANIE)){
		/* jedn· sa o nasledovnÈ:
		 * 1. t˝ûdeÚ: sobota
		 * 2. t˝ûdeÚ: sobota
		 * 4. t˝ûdeÚ: piatok (asi chceli, aby to bola vûdy sobota, ale tento ûalm nadv‰zuje)
		 * 4. t˝ûdeÚ: sobota
		 */
		if(
			((den == DEN_SOBOTA) && ((povodny_tyzzal == 1) || (povodny_tyzzal == 2) || (povodny_tyzzal == 4)))
		||
			((den == DEN_PIATOK) && (povodny_tyzzal == 4))
		){
			Log("-- upravujeme antifÛny (t˝ûdeÚ + 4), lebo v II. zv‰zku brevi·ra s˙ pre tento deÚ inÈ...\n");
			file_name_litobd_pc(OBD_CEZ_ROK);
			anchor_name_zaltar(den, 4 + tyzzal, modlitba, ANCHOR_ANTIFONA1);
			_set_antifona1(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
			anchor_name_zaltar(den, 4 + tyzzal, modlitba, ANCHOR_ANTIFONA2);
			_set_antifona2(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
			anchor_name_zaltar(den, 4 + tyzzal, modlitba, ANCHOR_ANTIFONA3);
			_set_antifona3(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;
		}
	}
}

void set_kcitanie(short int den, short int tyzzal, short int modlitba){
	/* pridanÈ Ëasti pre kompletÛrium, 2006-10-24 */
	if((modlitba == MODL_KOMPLETORIUM) || (modlitba == MODL_PRVE_KOMPLETORIUM)){
		file_name_zapamataj();
		file_name_kompletorium(OBD_CEZ_ROK);
		if((_global_den.typslav == SLAV_SLAVNOST) && ((den != DEN_NEDELA) && (den != DEN_SOBOTA))){
			den = DEN_UNKNOWN; /* 2008-05-08: ide o sl·vnosù mimo nedieæ */
		}
		sprintf(_anchor, "_%s%c_%s", nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_KCITANIE);
		_set_kcitanie(modlitba, _file, _anchor);
		set_LOG_zaltar;
		file_name_obnov();
	}
	else{
		file_name_zaltar(den, tyzzal);
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_KCITANIE);
		_set_kcitanie(modlitba, _file, _anchor);
		set_LOG_zaltar;
	}
}

void set_kresponz(short int den, short int tyzzal, short int modlitba){
	/* pridanÈ Ëasti pre kompletÛrium, 2006-10-24 */
	if((modlitba == MODL_KOMPLETORIUM) || (modlitba == MODL_PRVE_KOMPLETORIUM)){
		file_name_zapamataj();
		file_name_kompletorium(OBD_CEZ_ROK);
		sprintf(_anchor, "_%c_%s", pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);
		_set_kresponz(modlitba, _file, _anchor);
		set_LOG_zaltar;
		file_name_obnov();
	}
	else
	/* 2005-03-26: Pridane odvetvenie pre posvatne citania */
	if(modlitba == MODL_POSV_CITANIE){
		file_name_litobd_pc(OBD_CEZ_ROK);
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_KRESPONZ);
		_set_kresponz(modlitba, _file_pc, _anchor);
		set_LOG_litobd_pc;
	}
	else{
		if((modlitba != MODL_PREDPOLUDNIM) && (modlitba != MODL_NAPOLUDNIE) && (modlitba != MODL_POPOLUDNI)){
			/* 2005-03-27: pre modlitbu cez den to neplati:
			 * prvy a treti, resp. druhy a stvrty tyzden maju rovnake */
			if(tyzzal == 3)
				tyzzal = 1;
			else if(tyzzal == 4)
				tyzzal = 2;
		}
		file_name_zaltar(den, tyzzal);
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_KRESPONZ);
		_set_kresponz(modlitba, _file, _anchor);
		set_LOG_zaltar;
	}
}

void set_prosby(short int den, short int tyzzal, short int modlitba){
	file_name_zaltar(den, tyzzal);
	anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_PROSBY);
	_set_prosby(modlitba, _file, _anchor);
	set_LOG_zaltar;
}

void set_modlitba(short int den, short int tyzzal, short int modlitba){
	/* pridanÈ Ëasti pre kompletÛrium, 2006-10-24 */
	if((modlitba == MODL_KOMPLETORIUM) || (modlitba == MODL_PRVE_KOMPLETORIUM)){
		file_name_zapamataj();
		file_name_kompletorium(OBD_CEZ_ROK);
		if((_global_den.typslav == SLAV_SLAVNOST) && ((den != DEN_NEDELA) && (den != DEN_SOBOTA))){
			den = DEN_UNKNOWN; /* 2008-05-08: ide o sl·vnosù mimo nedieæ */
		}
		sprintf(_anchor, "_%s%c_%s", nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_MODLITBA);
		_set_modlitba(modlitba, _file, _anchor);
		set_LOG_zaltar;
		file_name_obnov();
	}
	else{
		if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
			/* 2005-03-27: pre modlitbu cez den:
			 * prvy a treti, resp. druhy a stvrty tyzden maju rovnake */
			if(tyzzal == 3)
				tyzzal = 1;
			else if(tyzzal == 4)
				tyzzal = 2;
		}
		file_name_zaltar(den, tyzzal);
		anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_MODLITBA);
		_set_modlitba(modlitba, _file, _anchor);
		set_LOG_zaltar;
	}
}

void set_benediktus(short int den, short int tyzzal, short int modlitba){
	/* prvy a treti, resp. druhy a stvrty tyzden maju rovnake */
	if(tyzzal == 3)
		tyzzal = 1;
	else if(tyzzal == 4)
		tyzzal = 2;
	file_name_zaltar(den, tyzzal);
	anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_BENEDIKTUS);
	_set_benediktus(modlitba, _file, _anchor);
	set_LOG_zaltar;
}

void set_magnifikat(short int den, short int tyzzal, short int modlitba){
	/* prvy a treti, resp. druhy a stvrty tyzden maju rovnake */
	if(tyzzal == 3)
		tyzzal = 1;
	else if(tyzzal == 4)
		tyzzal = 2;
	file_name_zaltar(den, tyzzal);
	anchor_name_zaltar(den, tyzzal, modlitba, ANCHOR_MAGNIFIKAT);
	_set_magnifikat(modlitba, _file, _anchor);
	set_LOG_zaltar;
}

void set_popis(short int modlitba, char *file, char *anchor){
	_set_popis(modlitba, file, anchor);
	/* 2007-09-27: kvÙli debugovaniu pod Ruby zruöenÈ koment·re vo v˝pisoch*/
	//	Log("   set(popis): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file, _anchor);
	Log("   set(popis): %s: s˙bor `%s', kotva `%s'\n", nazov_modlitby(modlitba), _file, _anchor);
}

void set_popis_dummy(void){
/* pridane 05/04/2000A.D. */
	Log("  teraz nastavujem POPIS (dummy)...\n");
	mystrcpy(_file, "dummy", MAX_STR_AF_FILE);
	mystrcpy(_anchor, "dummy", MAX_STR_AF_ANCHOR);
	set_popis(MODL_RANNE_CHVALY, _file, _anchor); 
	/* 2005-07-22: PridanÈ popisy pre posv‰tnÈ ËÌtania */
	set_popis(MODL_POSV_CITANIE, _file, _anchor);
	set_popis(MODL_VESPERY, _file, _anchor);
	set_popis(MODL_PRVE_VESPERY, _file, _anchor);
	/* 2006-01-27: PridanÈ popisy pre modlitby cez deÚ */
	set_popis(MODL_PREDPOLUDNIM, _file, _anchor);
	set_popis(MODL_NAPOLUDNIE, _file, _anchor);
	set_popis(MODL_POPOLUDNI, _file, _anchor);
	/* 2006-10-13: PridanÈ popisy pre invitatÛrium a kompletÛrium */
	set_popis(MODL_INVITATORIUM, _file, _anchor);
	set_popis(MODL_KOMPLETORIUM, _file, _anchor);
	/* 2006-10-18: Pridan˝ popis pre prvÈ kompletÛrium */
	set_popis(MODL_PRVE_KOMPLETORIUM, _file, _anchor);
}

/* nasledovnÈ funkcie pouûÌvanÈ pre kompletÛrium podæa liturgick˝ch obdobÌ; 2007-12-06 */

/* 2007-12-05: pridan· funkcia kvÙli kompletÛriu napr. v pÙstnom obdobÌ */
void set_hymnus_kompletorium_obd(short int den, short int tyzzal, short int modlitba, short int litobd){
	/* hymnusy s˙ rovnakÈ v pÙstnom obdobÌ ako pre cezroËnÈ obdobie;
	 * hymnus pre veækonoËnÈ obdobie je jedin˝, odliön˝
	 */
	short int pom_litobd = litobd;
	file_name_zapamataj();
	if((litobd == OBD_VELKONOCNE_II) || (litobd == OBD_VELKONOCNA_OKTAVA) || (litobd == OBD_VELKONOCNE_TROJDNIE)){
		pom_litobd = OBD_VELKONOCNE_I;
	}
	else if(litobd == OBD_POSTNE_I){
		pom_litobd = OBD_CEZ_ROK;
	}
	file_name_kompletorium(pom_litobd);

	short int dva_hymny = 1; /* urËuje, Ëi v danom obdobÌ s˙ dva hymny (1) alebo nie (0); ak je len jedin˝, m· index 0 */
	if(pom_litobd == OBD_VELKONOCNE_I){
		dva_hymny = 0;
	}
	if(_global_jazyk == JAZYK_CZ){
		sprintf(_anchor, "%c_%s_%s", 
			pismenko_modlitby(modlitba), ANCHOR_HYMNUS, nazov_DN_asci[den]);
	}
	else{
		sprintf(_anchor, "%c_%s_%d", 
			pismenko_modlitby(modlitba), ANCHOR_HYMNUS, ((tyzzal + 1) % 2) * dva_hymny);
	}
	_set_hymnus(modlitba, _file, _anchor);
	set_LOG_zaltar;
	file_name_obnov();
}/* set_hymnus_kompletorium_obd() */

/* 2007-12-06: odliönÈ pre veækonoËnÈ obdobie:
 * Vo VeækonoËnom obdobÌ: PsalmÛdia m· jedin˙ antifÛnu: Aleluja, aleluja, aleluja.
 * 2008-03-30: reöpektovan· rovnak· antifÛna pre veækonoËnÈ obdobie
 */
void set_antifony_kompletorium_obd(short int den, short int tyzzal, short int modlitba, short int litobd){
	/* rovnakÈ responzÛrium pre vöetky Ëasti veækonoËnÈho obdobia */
	if((_global_den.typslav == SLAV_SLAVNOST) && ((den != DEN_NEDELA) && (den != DEN_SOBOTA))){
		den = DEN_UNKNOWN; /* 2008-05-08: ide o sl·vnosù mimo nedieæ */
	}
	file_name_zapamataj();
	file_name_kompletorium((litobd == OBD_VELKONOCNA_OKTAVA || litobd == OBD_VELKONOCNE_II)? OBD_VELKONOCNE_I : litobd);
	sprintf(_anchor, "_%s%c_%s", nazov_DN_asci[den], pismenko_modlitby(modlitba), 
		((litobd == OBD_VELKONOCNA_OKTAVA) || (litobd == OBD_VELKONOCNE_II) || (litobd == OBD_VELKONOCNE_I)) ? ANCHOR_ANTIFONY : ANCHOR_ANTIFONA1);
	_set_antifona1(modlitba, _file, _anchor);
	set_LOG_zaltar;
	if((_global_modl_kompletorium.pocet_zalmov == 2) || (_global_modl_prve_kompletorium.pocet_zalmov == 2)){
		sprintf(_anchor, "_%s%c_%s", nazov_DN_asci[den], pismenko_modlitby(modlitba),
			((litobd == OBD_VELKONOCNA_OKTAVA) || (litobd == OBD_VELKONOCNE_II) || (litobd == OBD_VELKONOCNE_I)) ? ANCHOR_ANTIFONY : ANCHOR_ANTIFONA2);
		_set_antifona2(modlitba, _file, _anchor);
		set_LOG_zaltar;
	}
	file_name_obnov();
}/* set_antifony_kompletorium_obd() */

/* 2007-12-06: odliönÈ pre pÙst a veækonoËnÈ obdobie:
 * Vo VeækonoËnej okt·ve namiesto responzÛria sa hovorÌ antifÛna: Toto je deÚ
 * Vo VeækonoËnom obdobÌ: R. Do tvojich r˙k, Pane, por˙Ëam svojho ducha, * Aleluja, aleluja. Do tvojich. atÔ.
 */
void set_kresponz_kompletorium_obd(short int den, short int tyzzal, short int modlitba, short int litobd){
	/* rovnakÈ responzÛrium pre vöetky Ëasti veækonoËnÈho obdobia */
	file_name_zapamataj();
	file_name_kompletorium((litobd == OBD_VELKONOCNA_OKTAVA || litobd == OBD_VELKONOCNE_II)? OBD_VELKONOCNE_I : litobd);
	if(litobd == OBD_VELKONOCNE_TROJDNIE){
		sprintf(_anchor, "_%s%c_%s", nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);
	}
	else{
		sprintf(_anchor, "_%c_%s", pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);
	}
	_set_kresponz(modlitba, _file, _anchor);
	set_LOG_zaltar;
	file_name_obnov();
}/* set_kresponz_kompletorium_obd() */

/* nasledovnÈ funkcie pouûÌvame pre öpeci·lne nastavenia (ktorÈ sa Ëasto pouûÌvaj˙), 2007-12-06 */

void _set_zalm_cez_den_doplnkova_psalmodia(void){
	/* modlitba predpoludnim, 1. seria doplnkovej psalmodie */
		_set_zalm1(MODL_PREDPOLUDNIM, "z120.htm", "ZALM120");
		_set_zalm2(MODL_PREDPOLUDNIM, "z121.htm", "ZALM121");
		_set_zalm3(MODL_PREDPOLUDNIM, "z122.htm", "ZALM122");
	/* modlitba napoludnie, 2. seria doplnkovej psalmodie */
		_set_zalm1(MODL_NAPOLUDNIE, "z123.htm", "ZALM123");
		_set_zalm2(MODL_NAPOLUDNIE, "z124.htm", "ZALM124");
		_set_zalm3(MODL_NAPOLUDNIE, "z125.htm", "ZALM125");
	/* modlitba popoludni, 3. seria doplnkovej psalmodie */
		_set_zalm1(MODL_POPOLUDNI, "z126.htm", "ZALM126");
		_set_zalm2(MODL_POPOLUDNI, "z127.htm", "ZALM127");
		_set_zalm3(MODL_POPOLUDNI, "z128.htm", "ZALM128");
}

/* 2006-01-24: pridanÈ ûalmy nedele 1. t˝ûdÚa kvÙli modlitbe cez deÚ */
void _set_zalmy_1nedele_mcd(void){/* modlitba cez deÚ; rovnakÈ ûalmy s˙ pre nedeæu 3. t˝ûdÚa; 2007-01-11 */
	Log("_set_zalmy_1nedele_mcd() -- begin\n");
	/* modlitba cez den */
	_set_zalm1(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_I");
	_set_zalm2(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_II");
	_set_zalm3(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_III");
	Log("_set_zalmy_1nedele_mcd() -- end\n");
}

/* 2007-01-11: pridanÈ ûalmy nedele 2. t˝ûdÚa kvÙli modlitbe cez deÚ */
void _set_zalmy_2nedele_mcd(void){/* modlitba cez deÚ; rovnakÈ ûalmy s˙ pre nedeæu 4. t˝ûdÚa; 2007-01-11 */
	Log("_set_zalmy_2nedele_mcd() -- begin\n");
	/* modlitba cez den */
	_set_zalm1(MODL_CEZ_DEN_VSETKY, "z23.htm", "ZALM23");
	_set_zalm2(MODL_CEZ_DEN_VSETKY, "z76.htm", "ZALM76_I");
	_set_zalm3(MODL_CEZ_DEN_VSETKY, "z76.htm", "ZALM76_II");
	Log("_set_zalmy_2nedele_mcd() -- end\n");
}

/* 2007-12-06: doplnenÈ pre spoloËnÈ Ëasti nedeænÈho kompletÛria, ktorÈ sa pouûÌvaj˙ aj pre sl·vnosti 
 * 2008-05-08: prerobenÈ, aby vstupom bol parameter "modlitba" (nie ako doteraz, "short int ktore (1, 2)"
 */
void _set_kompletorium_nedela_spolocne(short int modlitba){
	Log("_set_kompletorium_nedela_spolocne(%d - %s) -- begin\n", modlitba, nazov_modlitby(modlitba));
	if(modlitba == MODL_PRVE_KOMPLETORIUM){ /* ktore == 1 */
		_global_modl_prve_kompletorium.pocet_zalmov = 2; /* 2008-05-08: opravenÈ */
		_set_zalm1(modlitba, "z4.htm", "ZALM4");
		_set_zalm2(modlitba, "z134.htm", "ZALM134");
		// _global_modl_kompletorium.pocet_zalmov = 2;
		// _set_zalm1(MODL_KOMPLETORIUM, "z4.htm", "ZALM4");
		// _set_zalm2(MODL_KOMPLETORIUM, "z134.htm", "ZALM134");
	}
	else{ /* modlitba == MODL_KOMPLETORIUM t.j. ktore == 2 */
		_global_modl_kompletorium.pocet_zalmov = 1;
		_set_zalm1(modlitba, "z91.htm", "ZALM91");
	}
	set_hymnus(DEN_NEDELA /* den */, _global_den.tyzzal, modlitba);
	set_antifony(DEN_NEDELA, _global_den.tyzzal, 2 /* zvazok - pre kompletÛrium sa nepouûÌva, len kvÙli posv. ËÌtaniu */, modlitba);
	Log("_set_kompletorium_nedela_spolocne(%d) -- end\n", modlitba);
}/* _set_kompletorium_nedela_spolocne() */

/* 2007-12-05: doplnenÈ pre nedeænÈ kompletÛrium (pouûÌva sa aj pre öpeci·lne dni, napr. zelen˝ ötvrtok) */
void _set_kompletorium_nedela(short int modlitba){
	/* popis parametrov:
	 *	- "ktore" -		urËuje, Ëi sa jedn· o kompletÛrium po prv˝ch nedeæn˝ch veöper·ch (1) alebo po druh˝ch veöper·ch (2) 
	 *  2008-05-08: prerobenÈ, aby vstupom bol parameter "modlitba" (nie ako doteraz, "short int ktore (1, 2)"
	 */
	Log("_set_kompletorium_nedela(%d - %s) -- begin\n", modlitba, nazov_modlitby(modlitba));
	_set_kompletorium_nedela_spolocne(modlitba);
	set_kcitanie(DEN_NEDELA, _global_den.tyzzal, modlitba);
	set_kresponz(DEN_NEDELA, _global_den.tyzzal, modlitba);
	set_modlitba(DEN_NEDELA, _global_den.tyzzal, modlitba);
	Log("_set_kompletorium_nedela(%d) -- end\n", modlitba);
}/* _set_kompletorium_nedela() */

/* 2007-12-06: ak je sl·vnosù, berie sa in· modlitba ako na nedeænÈ kompletÛrium.
 * podæa liturgickÈho obdobia sa nastavuje n·zov s˙boru.
 * 2008-05-08: prerobenÈ, aby vstupom bol parameter "modlitba" (nie ako doteraz, "short int ktore (1, 2)"
 */
void _set_kompletorium_slavnost(short int modlitba, short int litobd){
	/* popis parametrov:
	 *	- "ktore" -		urËuje, Ëi sa jedn· o kompletÛrium po prv˝ch veöper·ch sl·vnosti (1) alebo po druh˝ch veöper·ch (2) 
	 *  2008-05-08: prerobenÈ, aby vstupom bol parameter "modlitba" (nie ako doteraz, "short int ktore (1, 2)"
	 */
	Log("_set_kompletorium_slavnost(%d - %s) -- begin\n", modlitba, nazov_modlitby(modlitba));
	_set_kompletorium_nedela_spolocne(modlitba);
	set_modlitba(DEN_UNKNOWN, _global_den.tyzzal, modlitba); /* je to jeden konkrÈtny deÚ mimo nedele */
	/* nasleduj˙Ëe z·visia od liturgickÈho obdobia, preto nastavÌme in˙ kotvu (pevne z nedele) */
	set_kcitanie(DEN_NEDELA, _global_den.tyzzal, modlitba);
	set_kresponz(DEN_NEDELA, _global_den.tyzzal, modlitba);
	Log("_set_kompletorium_slavnost(%d) -- end\n", modlitba);
}/* _set_kompletorium_slavnost() */

/* zaltar();
 *
 * vstup: den == 0 (DEN_NEDELA) .. 6 (DEN_SOBOTA)
 *        tyzzal == 1 .. 4 (prvy az stvrty tyzzal zaltar
 *
 * nastavi do _global_modl_... (podla _global_modlitba) udaje potrebne
 * k modlitbe
 * 2003-08-13: nakoniec pridane porovnanie s _global_opt5 
 *             (ci brat zalmy z doplnkovej psalmodie pre modlitbu cez den)
 *
 * 2006-01-24: ûalmy pre posv‰tnÈ ËÌtanie s˙ v II. zv‰zku ûalt·ra (pÙst, veæk· noc)
 *             pre niektorÈ dni odliönÈ, preto sme vytvorili aj ÔalöÌ parameter,
 *             ktor˝ sa pouûÌva len pri volanÌ za ˙Ëelom konkrÈtnej modlitby
 *             (pre voæbu posv. ËÌtania len pre deÚ a t˝ûdeÚ ûalt·ra sa pouûije default)
 *
 */
#define _SET_SPOLOCNE_VECI_NEDELA(m) {\
	if((m == MODL_RANNE_CHVALY) || (m == MODL_VESPERY)){ \
		set_hymnus  (den, tyzzal, m); \
		set_antifony(den, tyzzal, zvazok, m); \
		set_kcitanie(den, tyzzal, m); \
		set_kresponz(den, tyzzal, m); \
		set_prosby  (den, tyzzal, m); \
		/* set_magnifikat(den, tyzzal, m); -- vlastna (pre vespery a 1. vespery) */ \
		/* set_benediktus(den, tyzzal, m); -- vlastna (pre ranne chvaly) */ \
		/* set_modlitba(den, tyzzal, m); -- vlastna */ \
	} \
	else{ \
		set_hymnus  (den, tyzzal, m); \
		set_antifony(den, tyzzal, zvazok, m); \
		set_kcitanie(den, tyzzal, m); \
		set_kresponz(den, tyzzal, m); \
		set_prosby  (den, tyzzal, m); /* 2003-10-07: pridane */\
		/* set_modlitba(den, tyzzal, m); -- vlastna */ \
	} \
}
#define _SET_SPOLOCNE_VECI_NIE_NEDELA(m) {\
	if((m == MODL_RANNE_CHVALY) || (m == MODL_VESPERY)){ \
		set_hymnus  (den, tyzzal, m); \
		set_antifony(den, tyzzal, zvazok, m); \
		set_kcitanie(den, tyzzal, m); \
		set_kresponz(den, tyzzal, m); \
		set_prosby  (den, tyzzal, m); \
		/* set_magnifikat(den, tyzzal, m); -- nastavene samostatne */ \
		/* set_benediktus(den, tyzzal, m); -- nastavene samostatne */ \
		set_modlitba(den, tyzzal, m); \
	} \
	else{ \
		set_hymnus  (den, tyzzal, m); \
		set_antifony(den, tyzzal, zvazok, m); \
		set_kcitanie(den, tyzzal, m); \
		set_kresponz(den, tyzzal, m); \
		set_modlitba(den, tyzzal, m); \
	} \
}
void zaltar_zvazok(short int den, short int tyzzal, short int obdobie, short int specialne){
	/* 2006-01-24: pÙvodn· funkcia mala 2 parametre 
	 *             pridan˝ parameter obdobie
	 * 2006-02-07: dodefinovanÈ rÙzne spr·vanie funkcie zaltar_zvazok();
	 *             podæa pridanÈho parametra ZALTAR_VSETKO alebo ZALTAR_IBA_ZALMY
	 * 2007-12-20: dodefinovanÈ "je_odlisny_zaltar" - doteraz bolo "zvazok != 2" resp. "zvazok == 2"
	 */
	Log("-- zaltar_zvazok(%d, %d, %d, %d) -- zaciatok\n", den, tyzzal, obdobie, specialne);
	short int zvazok = zvazok_breviara[obdobie];
	/* 2007-12-20: definovanÈ pole, ktorÈ urËuje, v ktorom zv‰zku brevi·ra sa danÈ obdobie nach·dza;
	 * kedysi tu bolo toto:
		if((obdobie == OBD_VELKONOCNA_OKTAVA) 
		|| (obdobie == OBD_VELKONOCNE_TROJDNIE) 
		|| (obdobie == OBD_VELKONOCNE_I) 
		|| (obdobie == OBD_VELKONOCNE_II) 
		|| (obdobie == OBD_POSTNE_I) 
		|| (obdobie == OBD_POSTNE_II_VELKY_TYZDEN) 
		){
			zvazok = 2;
		}
		else{
			zvazok = 0;
		}
	*/
	Log("liturgickÈ obdobie: `%s'...\n", nazov_obdobia_[obdobie]);
	Log("toto liturgickÈ obdobie sa nach·dza v zv‰zku %d brevi·ra (cezroËnÈ obdobie evidujeme ako jeden, 3. zv‰zok)...\n", zvazok);
	/* 2006-10-17: DoplnenÈ kvÙli rÙznemu poËtu ûalmov pre kompletÛrium; upravenÈ 2006-10-18 */
	if(den == DEN_STREDA){
		_global_modl_kompletorium.pocet_zalmov = 2;
	}
	else if(den == DEN_NEDELA){
		_global_modl_prve_kompletorium.pocet_zalmov = 2;
		_global_modl_kompletorium.pocet_zalmov = 1;
	}
	else{
		_global_modl_kompletorium.pocet_zalmov = 1;
	}

	if(specialne == ZALTAR_VSETKO){
		Log("ZALTAR_VSETKO -- takûe nastavujem vöetko zo ûalt·ra...\n");
		/* cast vseobecna pre vsetky 4 tyzdne zaltara
		 * upravena 2003-08-13. veci dane do dvoch makier
		 */

		/* pridanÈ Ëasti pre kompletÛrium, 2006-10-13 */
		set_hymnus(den, tyzzal, MODL_KOMPLETORIUM);
		set_hymnus(den, tyzzal, MODL_PRVE_KOMPLETORIUM);
		/* pridanÈ Ôalöie Ëasti pre kompletÛrium, 2006-10-13 */
		set_antifony(den, tyzzal, zvazok, MODL_KOMPLETORIUM);
		set_antifony(den, tyzzal, zvazok, MODL_PRVE_KOMPLETORIUM);
		set_kcitanie(den, tyzzal, MODL_KOMPLETORIUM);
		set_kcitanie(den, tyzzal, MODL_PRVE_KOMPLETORIUM);
		set_kresponz(den, tyzzal, MODL_KOMPLETORIUM);
		set_kresponz(den, tyzzal, MODL_PRVE_KOMPLETORIUM);
		set_modlitba(den, tyzzal, MODL_KOMPLETORIUM);
		set_modlitba(den, tyzzal, MODL_PRVE_KOMPLETORIUM);

		/* pridan· antifÛna pre invitatÛrium, 2006-10-24; cel· pas·û presunut· len pre ZALTAR_VSETKO */
		set_antifony(den, tyzzal, zvazok, MODL_INVITATORIUM);

		if(den == DEN_NEDELA){
			/* pridane casti pre modlitbu cez den a posvatne citanie, 2003-08-13 */
			_SET_SPOLOCNE_VECI_NEDELA(MODL_PRVE_VESPERY);
			_SET_SPOLOCNE_VECI_NEDELA(MODL_RANNE_CHVALY);
			_SET_SPOLOCNE_VECI_NEDELA(MODL_POSV_CITANIE);
			_SET_SPOLOCNE_VECI_NEDELA(MODL_PREDPOLUDNIM);
			_SET_SPOLOCNE_VECI_NEDELA(MODL_NAPOLUDNIE);
			_SET_SPOLOCNE_VECI_NEDELA(MODL_POPOLUDNI);
			_SET_SPOLOCNE_VECI_NEDELA(MODL_VESPERY);
		}/* den == DEN_NEDELA */
		else{/* nie nedela */
			_SET_SPOLOCNE_VECI_NIE_NEDELA(MODL_RANNE_CHVALY);
			_SET_SPOLOCNE_VECI_NIE_NEDELA(MODL_VESPERY);
			_SET_SPOLOCNE_VECI_NIE_NEDELA(MODL_POSV_CITANIE);
			_SET_SPOLOCNE_VECI_NIE_NEDELA(MODL_PREDPOLUDNIM);
			_SET_SPOLOCNE_VECI_NIE_NEDELA(MODL_NAPOLUDNIE);
			_SET_SPOLOCNE_VECI_NIE_NEDELA(MODL_POPOLUDNI);
			set_benediktus(den, tyzzal, MODL_RANNE_CHVALY);
			set_magnifikat(den, tyzzal, MODL_VESPERY);
		}/* den != DEN_NEDELA */
	}/* len ak if(specialne == ZALTAR_VSETKO) */
	else if(specialne == ZALTAR_IBA_ZALMY_HYMNUS_MCD){
		Log("ZALTAR_IBA_ZALMY_HYMNUS_MCD -- takûe nastavujem len hymny pre mcd...\n");
		set_hymnus(den, tyzzal, MODL_PREDPOLUDNIM);
		set_hymnus(den, tyzzal, MODL_NAPOLUDNIE);
		set_hymnus(den, tyzzal, MODL_POPOLUDNI);
	}/* len ak if(specialne == ZALTAR_IBA_ZALMY_HYMNUS_MCD) */
	else{
		Log("nebolo ZALTAR_VSETKO ani ZALTAR_IBA_ZALMY_HYMNUS_MCD -- takûe nastavujem len ûalmy...\n");
	}

	Log("Ôalej nastavujem ûalmy (öpecialitky spoloËnÈ pre niektorÈ t˝ûdne ûalt·ra)...\n");
	/* cast rovnaka pre kazdy tyzden zaltara */
	switch(den){
		case DEN_NEDELA:
			/* 2006-10-17: pridanÈ kompletÛrium */
			_set_zalm1(MODL_PRVE_KOMPLETORIUM, "z4.htm", "ZALM4");
			_set_zalm2(MODL_PRVE_KOMPLETORIUM, "z134.htm", "ZALM134");
			_set_zalm1(MODL_KOMPLETORIUM, "z91.htm", "ZALM91");
			/* druhe vespery maju vzdy prvy zalm 110, 1-5.7 */
			_set_zalm1(MODL_VESPERY, "z110.htm", "ZALM110");
			/* nedelny ranny hymnus je rovnaky v prvom a tretom,
			 * resp. druhom a stvrtom tyzdni */
			if((tyzzal == 1) || (tyzzal == 3)){
				_set_zalm2(MODL_RANNE_CHVALY, "dan3_57.htm", "DAN3,57-88.56");
				/* modlitba cez den */
				_set_zalmy_1nedele_mcd(); // 2007-01-11 nahradenÈ volanÌm funkcie
				/*
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_I");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_II");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_III");
				*/
			}
			else{ /* if((tyzzal == 2) || (tyzzal == 4)) */
				_set_zalm1(MODL_RANNE_CHVALY, "z118.htm", "ZALM118");
				_set_zalm2(MODL_RANNE_CHVALY, "dan3_52.htm", "DAN3,52-57");
				_set_zalm3(MODL_RANNE_CHVALY, "z150.htm", "ZALM150");
				/* modlitba cez den */
				_set_zalmy_2nedele_mcd(); // 2007-01-11 nahradenÈ volanÌm funkcie; 2007-03-29 opravenÈ
				/*
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z23.htm", "ZALM23");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z76.htm", "ZALM76_I");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z76.htm", "ZALM76_II");
				*/
			}
			/* vecerne nedelne hymny su rovnake v kazdom tyzdni */
			_set_zalm3(MODL_PRVE_VESPERY, "flp2.htm", "CHVAL_FLP2");
			if((_global_den.litobd != OBD_POSTNE_I) &&
				(_global_den.litobd != OBD_POSTNE_II_VELKY_TYZDEN)){
					_set_zalm3(MODL_VESPERY, "zjv19.htm", "CHVAL_ZJV19");
			}
			else{
				_set_zalm3(MODL_VESPERY, "1pt2.htm", "CHVAL_1PT2");
			}
			break;
		/* vecerny hymnus vsedneho dna je rovnaky v kazdom tyzdni */
		case DEN_PONDELOK:
			_set_zalm3(MODL_VESPERY, "ef1.htm", "CHVAL_EF1");
			/* 2006-10-17: pridanÈ kompletÛrium */
			_set_zalm1(MODL_KOMPLETORIUM, "z86.htm", "ZALM86");
			break;
		case DEN_UTOROK:
			_set_zalm3(MODL_VESPERY, "zjv4_5.htm", "CHVAL_ZJV45");
			/* 2006-10-17: pridanÈ kompletÛrium */
			_set_zalm1(MODL_KOMPLETORIUM, "z143.htm", "ZALM143");
			break;
		case DEN_STREDA:
			_set_zalm3(MODL_VESPERY, "kol1.htm", "CHVAL_KOL1");
			/* 2006-10-17: pridanÈ kompletÛrium */
			_set_zalm1(MODL_KOMPLETORIUM, "z31.htm", "ZALM31_1_6");
			_set_zalm2(MODL_KOMPLETORIUM, "z130.htm", "ZALM130");
			break;
		case DEN_STVRTOK:
			_set_zalm3(MODL_VESPERY, "zjv11.htm", "CHVAL_ZJV11");
			/* 2006-10-17: pridanÈ kompletÛrium */
			_set_zalm1(MODL_KOMPLETORIUM, "z16.htm", "ZALM16");
			break;
		case DEN_PIATOK:
			/* kazdy piatok, ranne chvaly je zalm 51 */
			_set_zalm1(MODL_RANNE_CHVALY, "z51.htm", "ZALM51");
			_set_zalm3(MODL_VESPERY, "zjv15.htm", "CHVAL_ZJV15");
			/* 2006-10-17: pridanÈ kompletÛrium */
			_set_zalm1(MODL_KOMPLETORIUM, "z88.htm", "ZALM88");
			break;
		case DEN_SOBOTA:
			/* sobota v 1. a 3. tyzdni je zalm 34 */
			if((tyzzal == 1) || (tyzzal == 3)){
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z34.htm", "ZALM34_I");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z34.htm", "ZALM34_II");
			}
			break;
	}/* switch(den) */

	Log("Ôalej nastavujem ûalmy (pre jednotliv˝ t˝ûdeÚ ûalt·ra)...\n");
	/* cast specificka pre kazdy tyzden zaltara */
	switch(tyzzal){
		case 1: /* prvy tyzden zaltara */
			switch(den){
				case DEN_NEDELA:
				/* prve vespery */
					_set_zalm1(MODL_PRVE_VESPERY, "z141.htm", "ZALM141");
					_set_zalm2(MODL_PRVE_VESPERY, "z142.htm", "ZALM142");
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z63.htm", "ZALM63");
					_set_zalm3(MODL_RANNE_CHVALY, "z149.htm", "ZALM149");
				/* modlitba cez den */
				/* druhe vespery */
					_set_zalm2(MODL_VESPERY, "z114.htm", "ZALM114");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z1.htm", "ZALM1");
					_set_zalm2(MODL_POSV_CITANIE, "z2.htm", "ZALM2");
					_set_zalm3(MODL_POSV_CITANIE, "z3.htm", "ZALM3");
					break;

				case DEN_PONDELOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z5.htm", "ZALM5");
					_set_zalm2(MODL_RANNE_CHVALY, "1krn29.htm", "CHVAL_1KRN29");
					_set_zalm3(MODL_RANNE_CHVALY, "z29.htm", "ZALM29");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z19.htm", "ZALM19,8-15");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z7.htm", "ZALM7_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z7.htm", "ZALM7_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z11.htm", "ZALM11");
					_set_zalm2(MODL_VESPERY, "z15.htm", "ZALM15");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z6.htm", "ZALM6");
					_set_zalm2(MODL_POSV_CITANIE, "z9.htm", "ZALM9_I");
					_set_zalm3(MODL_POSV_CITANIE, "z9.htm", "ZALM9_II");
					break;

				case DEN_UTOROK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z24.htm", "ZALM24");
					_set_zalm2(MODL_RANNE_CHVALY, "tob13.htm", "CHVAL_TOB13,2-8");
					_set_zalm3(MODL_RANNE_CHVALY, "z33.htm", "ZALM33");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_ALEF");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z13.htm", "ZALM13");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z14.htm", "ZALM14");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z20.htm", "ZALM20");
					_set_zalm2(MODL_VESPERY, "z21.htm", "ZALM21");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z10.htm", "ZALM10_I");
					_set_zalm2(MODL_POSV_CITANIE, "z10.htm", "ZALM10_II");
					_set_zalm3(MODL_POSV_CITANIE, "z12.htm", "ZALM12");
					break;

				case DEN_STREDA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z36.htm", "ZALM36");
					_set_zalm2(MODL_RANNE_CHVALY, "jdt16.htm", "CHVAL_JDT16");
					_set_zalm3(MODL_RANNE_CHVALY, "z47.htm", "ZALM47");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_BET");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z17.htm", "ZALM17_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z17.htm", "ZALM17_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z27.htm", "ZALM27_I");
					_set_zalm2(MODL_VESPERY, "z27.htm", "ZALM27_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z18.htm", "ZALM18_I");
					_set_zalm2(MODL_POSV_CITANIE, "z18.htm", "ZALM18_II");
					_set_zalm3(MODL_POSV_CITANIE, "z18.htm", "ZALM18_III");
					break;

				case DEN_STVRTOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z57.htm", "ZALM57");
					_set_zalm2(MODL_RANNE_CHVALY, "jer31.htm", "CHVAL_JER31");
					_set_zalm3(MODL_RANNE_CHVALY, "z48.htm", "ZALM48");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_GIMEL");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z25.htm", "ZALM25_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z25.htm", "ZALM25_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z30.htm", "ZALM30");
					_set_zalm2(MODL_VESPERY, "z32.htm", "ZALM32");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z18.htm", "ZALM18_IV");
					_set_zalm2(MODL_POSV_CITANIE, "z18.htm", "ZALM18_V");
					_set_zalm3(MODL_POSV_CITANIE, "z18.htm", "ZALM18_VI");
					break;

				case DEN_PIATOK:
				/* ranne chvaly */
					_set_zalm2(MODL_RANNE_CHVALY, "iz45.htm", "CHVAL_IZ45");
					_set_zalm3(MODL_RANNE_CHVALY, "z100.htm", "ZALM100");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_DALET");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z26.htm", "ZALM26");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z28.htm", "ZALM28,1-3.6-9");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z41.htm", "ZALM41");
					_set_zalm2(MODL_VESPERY, "z46.htm", "ZALM46");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z35.htm", "ZALM35_I");
					_set_zalm2(MODL_POSV_CITANIE, "z35.htm", "ZALM35_II");
					_set_zalm3(MODL_POSV_CITANIE, "z35.htm", "ZALM35_III");
					break;

				case DEN_SOBOTA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z119.htm", "ZALM119_KOF");
					_set_zalm2(MODL_RANNE_CHVALY, "ex15.htm", "CHVAL_EX15");
					_set_zalm3(MODL_RANNE_CHVALY, "z117.htm", "ZALM117");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_HE");
				/* posvatne citanie */
					if(je_odlisny_zaltar){
						_set_zalm1(MODL_POSV_CITANIE, "z105.htm", "ZALM105_I");
						_set_zalm2(MODL_POSV_CITANIE, "z105.htm", "ZALM105_II");
						_set_zalm3(MODL_POSV_CITANIE, "z105.htm", "ZALM105_III");
					}
					else {
						_set_zalm1(MODL_POSV_CITANIE, "z131.htm", "ZALM131");
						_set_zalm2(MODL_POSV_CITANIE, "z132.htm", "ZALM132_I");
						_set_zalm3(MODL_POSV_CITANIE, "z132.htm", "ZALM132_II");
					}
					/* 2005-03-27:
					 * Neviem preco tu bolo "z105.htm", "ZALM105_I" az "ZALM105_III"
					 * Mozno z nejakeho ineho obdobia zaltara.
					 * Opravene pre OCR na Z131 a Z132 I-II.
					 *
					 * 2006-01-24:
					 * OdpoveÔ je jednoduch·: II. zv‰zok brevi·ra m· odliönÈ ûalmy.
					 *
					 */
					break;

				default: break;
			}; break; /* case 1 */

		case 2: /* druhy tyzden zaltara */
			switch(den){
				case DEN_NEDELA:
				/* prve vespery */
					_set_zalm1(MODL_PRVE_VESPERY, "z119.htm", "ZALM119_NUN");
					_set_zalm2(MODL_PRVE_VESPERY, "z16.htm", "ZALM16");
				/* ranne chvaly */
				/* modlitba cez den */
				/* druhe vespery */
					_set_zalm2(MODL_VESPERY, "z115.htm", "ZALM115");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z104.htm", "ZALM104_I");
					_set_zalm2(MODL_POSV_CITANIE, "z104.htm", "ZALM104_II");
					_set_zalm3(MODL_POSV_CITANIE, "z104.htm", "ZALM104_III");
					break;

				case DEN_PONDELOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z42.htm", "ZALM42");
					_set_zalm2(MODL_RANNE_CHVALY, "sir36.htm", "CHVAL_SIR36");
					_set_zalm3(MODL_RANNE_CHVALY, "z19.htm", "ZALM19,2-7");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_VAU");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z40.htm", "ZALM40_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z40.htm", "ZALM40_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z45.htm", "ZALM45_I");
					_set_zalm2(MODL_VESPERY, "z45.htm", "ZALM45_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z31.htm", "ZALM31_I");
					_set_zalm2(MODL_POSV_CITANIE, "z31.htm", "ZALM31_II");
					_set_zalm3(MODL_POSV_CITANIE, "z31.htm", "ZALM31_III");
					break;

				case DEN_UTOROK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z43.htm", "ZALM43");
					_set_zalm2(MODL_RANNE_CHVALY, "iz38.htm", "CHVAL_IZ38");
					_set_zalm3(MODL_RANNE_CHVALY, "z65.htm", "ZALM65");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_ZAJIN");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z53.htm", "ZALM53");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z54.htm", "ZALM54");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z49.htm", "ZALM49_I");
					_set_zalm2(MODL_VESPERY, "z49.htm", "ZALM49_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z37.htm", "ZALM37_I");
					_set_zalm2(MODL_POSV_CITANIE, "z37.htm", "ZALM37_II");
					_set_zalm3(MODL_POSV_CITANIE, "z37.htm", "ZALM37_III");
					break;

				case DEN_STREDA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z77.htm", "ZALM77");
					_set_zalm2(MODL_RANNE_CHVALY, "1sam2.htm", "CHVAL_1SAM2");
					_set_zalm3(MODL_RANNE_CHVALY, "z97.htm", "ZALM97");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_CHET");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z55.htm", "ZALM55_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z55.htm", "ZALM55_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z62.htm", "ZALM62");
					_set_zalm2(MODL_VESPERY, "z67.htm", "ZALM67");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z39.htm", "ZALM39_I");
					_set_zalm2(MODL_POSV_CITANIE, "z39.htm", "ZALM39_II");
					_set_zalm3(MODL_POSV_CITANIE, "z52.htm", "ZALM52");
					break;

				case DEN_STVRTOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z80.htm", "ZALM80");
					_set_zalm2(MODL_RANNE_CHVALY, "iz12.htm", "CHVAL_IZ12");
					_set_zalm3(MODL_RANNE_CHVALY, "z81.htm", "ZALM81");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_TET");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z56.htm", "ZALM56");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z57.htm", "ZALM57");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z72.htm", "ZALM72_I");
					_set_zalm2(MODL_VESPERY, "z72.htm", "ZALM72_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z44.htm", "ZALM44_I");
					_set_zalm2(MODL_POSV_CITANIE, "z44.htm", "ZALM44_II");
					_set_zalm3(MODL_POSV_CITANIE, "z44.htm", "ZALM44_III");
					break;

				case DEN_PIATOK:
				/* ranne chvaly */
					_set_zalm2(MODL_RANNE_CHVALY, "hab3.htm", "CHVAL_HAB3");
					_set_zalm3(MODL_RANNE_CHVALY, "z147.htm", "ZALM147,12-20");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_JOD");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z59.htm", "ZALM59");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z60.htm", "ZALM60");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z116.htm", "ZALM116,1-9");
					_set_zalm2(MODL_VESPERY, "z121.htm", "ZALM121");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z38.htm", "ZALM38_I");
					_set_zalm2(MODL_POSV_CITANIE, "z38.htm", "ZALM38_II");
					_set_zalm3(MODL_POSV_CITANIE, "z38.htm", "ZALM38_III");
					break;

				case DEN_SOBOTA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z92.htm", "ZALM92");
					_set_zalm2(MODL_RANNE_CHVALY, "dt32.htm", "CHVAL_DT32");
					_set_zalm3(MODL_RANNE_CHVALY, "z8.htm", "ZALM8");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_KAF");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z61.htm", "ZALM61");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z64.htm", "ZALM64");
				/* posvatne citanie */
					if(je_odlisny_zaltar){
						_set_zalm1(MODL_POSV_CITANIE, "z106.htm", "ZALM106_I");
						_set_zalm2(MODL_POSV_CITANIE, "z106.htm", "ZALM106_II");
						_set_zalm3(MODL_POSV_CITANIE, "z106.htm", "ZALM106_III");
					}
					else {
						_set_zalm1(MODL_POSV_CITANIE, "z136.htm", "ZALM136_I");
						_set_zalm2(MODL_POSV_CITANIE, "z136.htm", "ZALM136_II_PC");
						_set_zalm3(MODL_POSV_CITANIE, "z136.htm", "ZALM136_III_PC"); /* inak je 136 cleneny pre pondelok 4. tyzdna, vespery */
					}
					/* 2005-03-27:
					 * Neviem preco tu bolo "z106.htm", "ZALM106_I" az "ZALM106_III"
					 * Mozno z nejakeho ineho obdobia zaltara (podobne sobota v 1. tyzdni).
					 * Opravene pre OCR na Z136 I-III.
					 *
					 * 2006-01-24:
					 * OdpoveÔ je jednoduch·: II. zv‰zok brevi·ra m· odliönÈ ûalmy.
					 *
					 */
					break;

				default: break;
			}; break; /* case 2 */

		case 3: /* treti tyzden zaltara */
			switch(den){
				case DEN_NEDELA:
				/* prve vespery */
					_set_zalm1(MODL_PRVE_VESPERY, "z113.htm", "ZALM113");
					_set_zalm2(MODL_PRVE_VESPERY, "z116.htm", "ZALM116,10-19");
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z93.htm", "ZALM93");
					_set_zalm3(MODL_RANNE_CHVALY, "z148.htm", "ZALM148");
				/* modlitba cez den */
				/* druhe vespery */
					_set_zalm2(MODL_VESPERY, "z111.htm", "ZALM111");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z145.htm", "ZALM145pc_I");
					_set_zalm2(MODL_POSV_CITANIE, "z145.htm", "ZALM145pc_II");
					_set_zalm3(MODL_POSV_CITANIE, "z145.htm", "ZALM145pc_III");
					break;

				case DEN_PONDELOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z84.htm", "ZALM84");
					_set_zalm2(MODL_RANNE_CHVALY, "iz2.htm", "CHVAL_IZ2");
					_set_zalm3(MODL_RANNE_CHVALY, "z96.htm", "ZALM96");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_LAMED");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z71.htm", "ZALM71_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z71.htm", "ZALM71_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z123.htm", "ZALM123");
					_set_zalm2(MODL_VESPERY, "z124.htm", "ZALM124");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z50.htm", "ZALM50_I");
					_set_zalm2(MODL_POSV_CITANIE, "z50.htm", "ZALM50_II");
					_set_zalm3(MODL_POSV_CITANIE, "z50.htm", "ZALM50_III");
					break;

				case DEN_UTOROK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z85.htm", "ZALM85");
					_set_zalm2(MODL_RANNE_CHVALY, "iz26.htm", "CHVAL_IZ26");
					_set_zalm3(MODL_RANNE_CHVALY, "z67.htm", "ZALM67");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_MEM");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z74.htm", "ZALM74_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z74.htm", "ZALM74_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z125.htm", "ZALM125");
					_set_zalm2(MODL_VESPERY, "z131.htm", "ZALM131");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z68.htm", "ZALM68_I");
					_set_zalm2(MODL_POSV_CITANIE, "z68.htm", "ZALM68_II");
					_set_zalm3(MODL_POSV_CITANIE, "z68.htm", "ZALM68_III");
					break;

				case DEN_STREDA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z86.htm", "ZALM86");
					_set_zalm2(MODL_RANNE_CHVALY, "iz33.htm", "CHVAL_IZ33");
					_set_zalm3(MODL_RANNE_CHVALY, "z98.htm", "ZALM98");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_NUN");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z70.htm", "ZALM70");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z75.htm", "ZALM75");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z126.htm", "ZALM126");
					_set_zalm2(MODL_VESPERY, "z127.htm", "ZALM127");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z89.htm", "ZALM89_I");
					_set_zalm2(MODL_POSV_CITANIE, "z89.htm", "ZALM89_II");
					_set_zalm3(MODL_POSV_CITANIE, "z89.htm", "ZALM89_III");
					break;

				case DEN_STVRTOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z87.htm", "ZALM87");
					_set_zalm2(MODL_RANNE_CHVALY, "iz40.htm", "CHVAL_IZ40");
					_set_zalm3(MODL_RANNE_CHVALY, "z99.htm", "ZALM99");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_SAMECH");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z79.htm", "ZALM79");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z80.htm", "ZALM80");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z132.htm", "ZALM132_I");
					_set_zalm2(MODL_VESPERY, "z132.htm", "ZALM132_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z89.htm", "ZALM89_IV");
					_set_zalm2(MODL_POSV_CITANIE, "z89.htm", "ZALM89_V");
					_set_zalm3(MODL_POSV_CITANIE, "z90.htm", "ZALM90");
					break;

				case DEN_PIATOK:
				/* ranne chvaly */
					_set_zalm2(MODL_RANNE_CHVALY, "jer14.htm", "CHVAL_JER14");
					_set_zalm3(MODL_RANNE_CHVALY, "z100.htm", "ZALM100");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z22.htm", "ZALM22_I");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z22.htm", "ZALM22_II");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z22.htm", "ZALM22_III");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z135.htm", "ZALM135_I");
					_set_zalm2(MODL_VESPERY, "z135.htm", "ZALM135_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z69.htm", "ZALM69_I");
					_set_zalm2(MODL_POSV_CITANIE, "z69.htm", "ZALM69_II");
					_set_zalm3(MODL_POSV_CITANIE, "z69.htm", "ZALM69_III");
					break;

				case DEN_SOBOTA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z119.htm", "ZALM119_KOF");
					_set_zalm2(MODL_RANNE_CHVALY, "mud9.htm", "CHVAL_MUD9");
					_set_zalm3(MODL_RANNE_CHVALY, "z117.htm", "ZALM117");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_AIN");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z107.htm", "ZALM107_I");
					_set_zalm2(MODL_POSV_CITANIE, "z107.htm", "ZALM107_II");
					_set_zalm3(MODL_POSV_CITANIE, "z107.htm", "ZALM107_III");
					break;

				default: break;
			}; break; /* case 3 */

		case 4: /* stvrty tyzden zaltara */
			switch(den){
				case DEN_NEDELA:
				/* prve vespery */
					_set_zalm1(MODL_PRVE_VESPERY, "z122.htm", "ZALM122");
					_set_zalm2(MODL_PRVE_VESPERY, "z130.htm", "ZALM130");
				/* ranne chvaly */
				/* modlitba cez den */
				/* druhe vespery */
					_set_zalm2(MODL_VESPERY, "z112.htm", "ZALM112");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z24.htm", "ZALM24");
					_set_zalm2(MODL_POSV_CITANIE, "z66.htm", "ZALM66_I");
					_set_zalm3(MODL_POSV_CITANIE, "z66.htm", "ZALM66_II");
					break;

				case DEN_PONDELOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z90.htm", "ZALM90");
					_set_zalm2(MODL_RANNE_CHVALY, "iz42.htm", "CHVAL_IZ42");
					_set_zalm3(MODL_RANNE_CHVALY, "z135.htm", "ZALM135,1-12");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_PE");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z82.htm", "ZALM82");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z120.htm", "ZALM120");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z136.htm", "ZALM136_I");
					_set_zalm2(MODL_VESPERY, "z136.htm", "ZALM136_II"); /* inak je 136 cleneny pre sobotu 2. tyzdna, posvatne citanie */
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z73.htm", "ZALM73_I");
					_set_zalm2(MODL_POSV_CITANIE, "z73.htm", "ZALM73_II");
					_set_zalm3(MODL_POSV_CITANIE, "z73.htm", "ZALM73_III");
					break;

				case DEN_UTOROK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z101.htm", "ZALM101");
					_set_zalm2(MODL_RANNE_CHVALY, "dan3_26.htm", "CHVAL_DAN3,26");
					_set_zalm3(MODL_RANNE_CHVALY, "z144.htm", "ZALM144,1-10");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_SADE");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z88.htm", "ZALM88_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z88.htm", "ZALM88_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z137.htm", "ZALM137");
					_set_zalm2(MODL_VESPERY, "z138.htm", "ZALM138");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z102.htm", "ZALM102_I");
					_set_zalm2(MODL_POSV_CITANIE, "z102.htm", "ZALM102_II");
					_set_zalm3(MODL_POSV_CITANIE, "z102.htm", "ZALM102_III");
					break;

				case DEN_STREDA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z108.htm", "ZALM108");
					_set_zalm2(MODL_RANNE_CHVALY, "iz61.htm", "CHVAL_IZ61");
					_set_zalm3(MODL_RANNE_CHVALY, "z146.htm", "ZALM146");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_KOF");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z94.htm", "ZALM94_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z94.htm", "ZALM94_II");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z139.htm", "ZALM139_I");
					_set_zalm2(MODL_VESPERY, "z139.htm", "ZALM139_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z103.htm", "ZALM103_I");
					_set_zalm2(MODL_POSV_CITANIE, "z103.htm", "ZALM103_II");
					_set_zalm3(MODL_POSV_CITANIE, "z103.htm", "ZALM103_III");
					break;

				case DEN_STVRTOK:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z143.htm", "ZALM143");
					_set_zalm2(MODL_RANNE_CHVALY, "iz66.htm", "CHVAL_IZ66");
					_set_zalm3(MODL_RANNE_CHVALY, "z147.htm", "ZALM147,1-11");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_RES");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z128.htm", "ZALM128");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z129.htm", "ZALM129");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z144.htm", "ZALM144_I");
					_set_zalm2(MODL_VESPERY, "z144.htm", "ZALM144_II");
				/* posvatne citanie */
					_set_zalm1(MODL_POSV_CITANIE, "z44.htm", "ZALM44_I");
					_set_zalm2(MODL_POSV_CITANIE, "z44.htm", "ZALM44_II");
					_set_zalm3(MODL_POSV_CITANIE, "z44.htm", "ZALM44_III");
					break;

				case DEN_PIATOK:
				/* ranne chvaly */
					_set_zalm2(MODL_RANNE_CHVALY, "tob13.htm", "CHVAL_TOB13,8-11");
					_set_zalm3(MODL_RANNE_CHVALY, "z147.htm", "ZALM147,12-20");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_SIN");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z133.htm", "ZALM133");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z140.htm", "ZALM140");
				/* vespery */
					_set_zalm1(MODL_VESPERY, "z145.htm", "ZALM145_I");
					_set_zalm2(MODL_VESPERY, "z145.htm", "ZALM145_II");
				/* posvatne citanie */
					if(je_odlisny_zaltar){
						_set_zalm1(MODL_POSV_CITANIE, "z78.htm", "ZALM78_I");
						_set_zalm2(MODL_POSV_CITANIE, "z78.htm", "ZALM78_II");
						_set_zalm3(MODL_POSV_CITANIE, "z78.htm", "ZALM78_III");
					}
					else {
						_set_zalm1(MODL_POSV_CITANIE, "z55.htm", "ZALM55_I_PC");
						_set_zalm2(MODL_POSV_CITANIE, "z55.htm", "ZALM55_II_PC");
						_set_zalm3(MODL_POSV_CITANIE, "z55.htm", "ZALM55_III_PC"); /* inak clenene pre modlitbu cez den, streda v 2. tyzdni */ 
					}
					/* 2005-03-27:
					 * Neviem preco tu bolo "z78.htm", "ZALM78_I" az "ZALM78_III"
					 * Mozno z nejakeho ineho obdobia zaltara (podobne sobota v 1. a 2. tyzdni).
					 * Opravene pre OCR na Z55 I-III.
					 *
					 * 2006-01-24:
					 * OdpoveÔ je jednoduch·: II. zv‰zok brevi·ra m· odliönÈ ûalmy.
					 *
					 */
					break;

				case DEN_SOBOTA:
				/* ranne chvaly */
					_set_zalm1(MODL_RANNE_CHVALY, "z92.htm", "ZALM92");
					_set_zalm2(MODL_RANNE_CHVALY, "ez36.htm", "CHVAL_EZ36");
					_set_zalm3(MODL_RANNE_CHVALY, "z8.htm", "ZALM8");
				/* modlitba cez den */
					_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_TAU");
					_set_zalm2(MODL_CEZ_DEN_VSETKY, "z45.htm", "ZALM45_I");
					_set_zalm3(MODL_CEZ_DEN_VSETKY, "z45.htm", "ZALM45_II");
				/* posvatne citanie */
					if(je_odlisny_zaltar){
						_set_zalm1(MODL_POSV_CITANIE, "z78.htm", "ZALM78_IV");
						_set_zalm2(MODL_POSV_CITANIE, "z78.htm", "ZALM78_V");
						_set_zalm3(MODL_POSV_CITANIE, "z78.htm", "ZALM78_VI");
					}
					else {
						_set_zalm1(MODL_POSV_CITANIE, "z50.htm", "ZALM50_I");
						_set_zalm2(MODL_POSV_CITANIE, "z50.htm", "ZALM50_II");
						_set_zalm3(MODL_POSV_CITANIE, "z50.htm", "ZALM50_III");
					}
					/* 2005-03-27:
					 * Neviem preco tu bolo "z78.htm", "ZALM78_IV" az "ZALM78_VI"
					 * Mozno z nejakeho ineho obdobia zaltara (podobne sobota v 1. a 2. tyzdni a piatok vo 4. tyzdni, posv. citanie).
					 * Opravene pre OCR na Z55 I-III.
					 *
					 * 2006-01-24:
					 * OdpoveÔ je jednoduch·: II. zv‰zok brevi·ra m· odliönÈ ûalmy.
					 *
					 */
					break;

				default: break;
			}; break; /* case 4 */

	}/* switch(tyzzal) */

	/* nasledujuca pasaz pridana 2003-08-13 */
	Log("napokon idem pre modlitbu cez deÚ skontrolovaù, Ëi netreba braù doplnkov˙ psalmÛdiu...\n");
	if(_global_opt5 == MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA){
		Log("\t·no, beriem doplnkov˙ psalmÛdiu.\n");
		_set_zalm_cez_den_doplnkova_psalmodia();
		/* 2006-01-24: vyÚatÈ do samostatnej funkcie */
	}/* _global_opt5 == MODL_CEZ_DEN_DOPLNKOVA_PSALMODIA */
	else{
		/* 2006-02-07: doplnenÈ */
		Log("\tnie, doplnkov˙ psalmÛdiu neberiem.\n");
	}
	Log("-- zaltar_zvazok(%d, %d, %d, %d) -- koniec\n", den, tyzzal, obdobie, specialne);
}/* zaltar_zvazok(); */

void zaltar(short int den, short int tyzzal){
	/* 2006-01-24: kvÙli sp‰tnej kompatibilite ponechan· aj funkcia s 2 parametrami */
	Log("-- zaltar(%d, %d) -- zaciatok\n", den, tyzzal);
	zaltar_zvazok(den, tyzzal, OBD_CEZ_ROK, ZALTAR_VSETKO);
	Log("-- zaltar(%d, %d) -- koniec\n", den, tyzzal);
}/* zaltar(); */

/* 2006-01-26: pridanÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_velky_piatok(short int modlitba){
	Log("_set_zalmy_velky_piatok(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm2(modlitba, "z143.htm", "ZALM143");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		/* zalmy z piatka 2. tyzdna zaltara */
		Log("zalmy su z piatka 2. tyzdna zaltara...\n");
	}
	/* 2006-01-26: doplnenÈ ûalmy pre posv. ËÌtanie */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z2.htm", "ZALM2");
		_set_zalm2(modlitba, "z22.htm", "ZALM22_CELY");
		_set_zalm3(modlitba, "z38.htm", "ZALM38_CELY");
	}
	/* 2006-01-26: doplnenÈ ûalmy pre modlitbu cez deÚ */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm1(modlitba, "z40.htm", "ZALM40");
		_set_zalm2(modlitba, "z54.htm", "ZALM54");
		_set_zalm3(modlitba, "z88.htm", "ZALM88");
	}
	Log("_set_zalmy_velky_piatok(%s) -- end\n", nazov_modlitby(modlitba));
}
/* 2006-01-26: pridanÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_biela_sobota(short int modlitba){
	Log("_set_zalmy_biela_sobota(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm2(modlitba, "z143.htm", "ZALM143");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalm1(modlitba, "z64.htm", "ZALM64");
		_set_zalm2(modlitba, "iz38.htm", "CHVAL_IZ38");
		_set_zalm3(modlitba, "z150.htm", "ZALM150");
	}
	/* 2006-01-26: doplnenÈ ûalmy pre posv. ËÌtanie */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z4.htm", "ZALM4");
		_set_zalm2(modlitba, "z16.htm", "ZALM16");
		_set_zalm3(modlitba, "z24.htm", "ZALM24");
	}
	/* 2006-01-26: doplnenÈ ûalmy pre modlitbu cez deÚ */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm1(modlitba, "z27.htm", "ZALM27");
		_set_zalm2(modlitba, "z30.htm", "ZALM30");
		_set_zalm3(modlitba, "z76.htm", "ZALM76");
	}
	Log("_set_zalmy_biela_sobota(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_za_zosnulych(short int modlitba){
	Log("_set_zalmy_za_zosnulych(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z121.htm", "ZALM121");
		_set_zalm2(modlitba, "z130.htm", "ZALM130");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalm1(modlitba, "z51.htm", "ZALM51");
		_set_zalm2(modlitba, "iz38.htm", "CHVAL_IZ38");
		if(_global_den.tyzden MOD 2 == 0)
			_set_zalm3(modlitba, "z146.htm", "ZALM146");
		else
			_set_zalm3(modlitba, "z150.htm", "ZALM150");
	}
	/* 2006-02-04: doplnenÈ ûalmy pre posv. ËÌtanie a pre modlitbu cez deÚ */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z40.htm", "ZALM40_I");
		_set_zalm2(modlitba, "z40.htm", "ZALM40_II");
		_set_zalm3(modlitba, "z42.htm", "ZALM42");
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm1(modlitba, "z70.htm", "ZALM70");
		_set_zalm2(modlitba, "z85.htm", "ZALM85");
		_set_zalm3(modlitba, "z86.htm", "ZALM86");
	}
	Log("_set_zalmy_za_zosnulych(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_1nedele_rch(void){/* ranne chvaly */
	Log("_set_zalmy_1nedele_rch() -- begin\n");
	_set_zalm1(MODL_RANNE_CHVALY, "z63.htm", "ZALM63");
	_set_zalm2(MODL_RANNE_CHVALY, "dan3_57.htm", "DAN3,57-88.56");
	_set_zalm3(MODL_RANNE_CHVALY, "z149.htm", "ZALM149");
	Log("_set_zalmy_1nedele_rch() -- end\n");
}

void _set_zalmy_1nedele_v(void){/* vespery */
	Log("_set_zalmy_1nedele_v() -- begin\n");
	_set_zalm1(MODL_VESPERY, "z110.htm", "ZALM110");
	_set_zalm2(MODL_VESPERY, "z114.htm", "ZALM114");
	_set_zalm3(MODL_VESPERY, "zjv19.htm", "CHVAL_ZJV19");
	Log("_set_zalmy_1nedele_v() -- end\n");
}

/*
void _set_zalmy_1nedele_1v(void){ // prve vespery -- nepouûÌva sa; 2008-04-04
	Log("_set_zalmy_1nedele_1v() -- begin\n");
	_set_zalm1(MODL_PRVE_VESPERY, "z141.htm", "ZALM141");
	_set_zalm2(MODL_PRVE_VESPERY, "z142.htm", "ZALM142");
	_set_zalm3(MODL_PRVE_VESPERY, "flp2.htm", "CHVAL_FLP2");
	Log("_set_zalmy_1nedele_1v() -- end\n");
}
*/

void _set_zalmy_1nedele_v_pre_1v(void){/* ûalmy a chv·lospev z veöpier pre prvÈ veöpery -- kvÙli druhej veækonoËnej nedeli; 2008-04-04 */
	Log("_set_zalmy_1nedele_v_pre_1v() -- begin\n");
	_set_zalm1(MODL_PRVE_VESPERY, "z110.htm", "ZALM110");
	_set_zalm2(MODL_PRVE_VESPERY, "z114.htm", "ZALM114");
	_set_zalm3(MODL_PRVE_VESPERY, "zjv19.htm", "CHVAL_ZJV19");
	Log("_set_zalmy_1nedele_v_pre_1v() -- end\n");
}

/* 2007-01-11: presunutÈ funkcie vyööie 
	- void _set_zalmy_1nedele_mcd(void)
	- void _set_zalmy_2nedele_mcd(void)
 */

/* 2006-01-26: pridanÈ ûalmy nedele 1. t˝ûdÚa kvÙli posv. ËÌtaniam (napr. druh· nedeæa vo veæk. okt·ve) */
void _set_zalmy_1nedele_pc(void){/* prve vespery */
	Log("_set_zalmy_1nedele_pc() -- begin\n");
	/* modlitba cez den */
	_set_zalm1(MODL_POSV_CITANIE, "z1.htm", "ZALM1");
	_set_zalm2(MODL_POSV_CITANIE, "z2.htm", "ZALM2");
	_set_zalm3(MODL_POSV_CITANIE, "z3.htm", "ZALM3");
	Log("_set_zalmy_1nedele_pc() -- end\n");
}

/* 2006-01-26: pridanÈ ûalmy pre posv‰tnÈ ËÌtania veækonoËnÈho t˝ûdÚa */
void _set_zalmy_velk_oktava(short int den, short int modlitba){
	Log("_set_zalmy_velk_oktava(%d, %s) -- begin\n", den, nazov_modlitby(modlitba));
	if(modlitba == MODL_POSV_CITANIE){
		/* posv‰tnÈ ËÌtanie */
		switch(den){
			case DEN_NEDELA: /* 2006-01-26: v podstate len pre druh˙ nedeæu vo veækonoËnej okt·ve */
			case DEN_PONDELOK:
				_set_zalm1(modlitba, "z1.htm", "ZALM1");
				_set_zalm2(modlitba, "z2.htm", "ZALM2");
				_set_zalm3(modlitba, "z3.htm", "ZALM3");
				break;
			case DEN_UTOROK:
				_set_zalm1(modlitba, "z24.htm", "ZALM24");
				_set_zalm2(modlitba, "z66.htm", "ZALM66_I");
				_set_zalm3(modlitba, "z66.htm", "ZALM66_II");
				break;
			case DEN_STREDA:
				_set_zalm1(modlitba, "z104.htm", "ZALM104_I");
				_set_zalm2(modlitba, "z104.htm", "ZALM104_II");
				_set_zalm3(modlitba, "z104.htm", "ZALM104_III");
				break;
			case DEN_STVRTOK:
				_set_zalm1(modlitba, "z118.htm", "ZALM118_I");
				_set_zalm2(modlitba, "z118.htm", "ZALM118_II");
				_set_zalm3(modlitba, "z118.htm", "ZALM118_III");
				break;
			case DEN_PIATOK:
				_set_zalm1(modlitba, "z136.htm", "ZALM136_I");
				_set_zalm2(modlitba, "z136.htm", "ZALM136_II_PC");
				_set_zalm3(modlitba, "z136.htm", "ZALM136_III_PC");
				break;
			case DEN_SOBOTA:
				_set_zalm1(modlitba, "z145.htm", "ZALM145pc_I");
				_set_zalm2(modlitba, "z145.htm", "ZALM145pc_II");
				_set_zalm3(modlitba, "z145.htm", "ZALM145pc_III");
				break;
		}/* switch(den) */
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		/* modlitba cez deÚ */
		switch(den){
			case DEN_NEDELA:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_I");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_II");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z118.htm", "ZALM118_III");
				break;
			case DEN_PONDELOK:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z8.htm", "ZALM8");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z19.htm", "ZALM19_I");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z19.htm", "ZALM19_II");
				break;
			case DEN_UTOROK:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_ALEF");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z16.htm", "ZALM16");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z23.htm", "ZALM23");
				break;
			case DEN_STREDA:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_BET");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z28.htm", "ZALM28,1-3.6-9");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z116.htm", "ZALM116,10-19");
				break;
			case DEN_STVRTOK:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_GIMEL");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z30.htm", "ZALM30_I");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z30.htm", "ZALM30_II");
				break;
			case DEN_PIATOK:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_DALET");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z76.htm", "ZALM76_I");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z76.htm", "ZALM76_II");
				break;
			case DEN_SOBOTA:
				_set_zalm1(MODL_CEZ_DEN_VSETKY, "z119.htm", "ZALM119_HE");
				_set_zalm2(MODL_CEZ_DEN_VSETKY, "z96.htm", "ZALM96_I");
				_set_zalm3(MODL_CEZ_DEN_VSETKY, "z96.htm", "ZALM96_II");
				break;
		}/* switch(den) */
	}
	Log("_set_zalmy_velk_oktava(%d, %s) -- end\n", den, nazov_modlitby(modlitba));
}/* _set_zalmy_velk_oktava */

/* 2006-02-04: pridanÈ ûalmy pre posv‰tnÈ ËÌtania vianoËnej okt·vy okrem narodenia P·na */
void _set_zalmy_vian_oktava(short int den, short int modlitba){
	Log("_set_zalmy_vian_oktava(%d, %s) -- begin\n", den, nazov_modlitby(modlitba));
	if(modlitba == MODL_POSV_CITANIE){
		/* posv‰tnÈ ËÌtanie */
		switch(den){
			case 25:
				_set_zalm1(modlitba, "z2.htm", "ZALM2");
				_set_zalm2(modlitba, "z19.htm", "ZALM19,2-7");
				_set_zalm3(modlitba, "z45.htm", "ZALM45");
				break;
			case 29:
				_set_zalm1(modlitba, "z46.htm", "ZALM46");
				_set_zalm2(modlitba, "z72.htm", "ZALM72_I");
				_set_zalm3(modlitba, "z72.htm", "ZALM72_II");
				break;
			case 30:
				_set_zalm1(modlitba, "z85.htm", "ZALM85");
				_set_zalm2(modlitba, "z89.htm", "ZALM89_I_30DEC");
				_set_zalm3(modlitba, "z89.htm", "ZALM89_II_30DEC");
				break;
			case 31:
				_set_zalm1(modlitba, "z96.htm", "ZALM96");
				_set_zalm2(modlitba, "z97.htm", "ZALM97");
				_set_zalm3(modlitba, "z98.htm", "ZALM98");
				break;
			case 1:
				_set_zalm1(modlitba, "z24.htm", "ZALM24");
				_set_zalm2(modlitba, "z87.htm", "ZALM87");
				_set_zalm3(modlitba, "z99.htm", "ZALM99");
				break;
		}/* switch(den) */
	}
	Log("_set_zalmy_vian_oktava(%d, %s) -- end\n", den, nazov_modlitby(modlitba));
}/* _set_zalmy_vian_oktava */

void _set_zalmy_posviacka_chramu(short int modlitba){
	Log("_set_zalmy_posviacka_chramu(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z46.htm", "ZALM46");
		_set_zalm2(modlitba, "z122.htm", "ZALM122");
		if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN))
			_set_zalm3(modlitba, "zjv15.htm", "CHVAL_ZJV15");
		else
			_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z147.htm", "ZALM147,1-11");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN))
			_set_zalm3(modlitba, "kol1.htm", "CHVAL_KOL1");
		else
			_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	/* 2006-02-04: doplnenÈ ûalmy pre posv. ËÌtanie a pre modlitbu cez deÚ */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z24.htm", "ZALM24");
		_set_zalm2(modlitba, "z84.htm", "ZALM84");
		_set_zalm3(modlitba, "z87.htm", "ZALM87");
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm_cez_den_doplnkova_psalmodia();
	}
	Log("_set_zalmy_posviacka_chramu(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_velkonocna_nedela(short int modlitba){
	Log("_set_zalmy_velkonocna_nedela(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalmy_1nedele_v();
	}
	/* 2008-04-04: upravenÈ, aj na prvÈ veöpery druhej veækonoËnej nedele 
	 *             s˙ ûalmy z (druh˝ch) veöpier veækonoËnej nedele; (prv·) veækonoËn· nedeæa nem· prvÈ veöpery
	 *             (biela sobota m· svoje veöpery); pÙvodne tu bolo: _set_zalmy_1nedele_1v();
	 */
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalmy_1nedele_v_pre_1v();
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-26: pridanÈ posv‰tnÈ ËÌtanie a modlitba cez deÚ */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalmy_1nedele_pc();
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalmy_1nedele_mcd();
	}
	Log("_set_zalmy_velkonocna_nedela(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-27: doplnenÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_nanebovstupenie(short int modlitba){
	Log("_set_zalmy_nanebovstupenie(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z47.htm", "ZALM47");
		_set_zalm3(modlitba, "zjv11.htm", "CHVAL_ZJV11");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z117.htm", "ZALM117");
		_set_zalm3(modlitba, "zjv11.htm", "CHVAL_ZJV11");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-27: pridanÈ posv‰tnÈ ËÌtanie a modlitba cez deÚ */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z68.htm", "ZALM68_I");
		_set_zalm2(modlitba, "z68.htm", "ZALM68_II");
		_set_zalm3(modlitba, "z68.htm", "ZALM68_III");
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm1(modlitba, "z8.htm", "ZALM8");
		_set_zalm2(modlitba, "z19.htm", "ZALM19_I");
		_set_zalm3(modlitba, "z19.htm", "ZALM19_II");
	}
	Log("_set_zalmy_nanebovstupenie(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-27: doplnenÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_zoslanie_ducha_sv(short int modlitba){
	Log("_set_zalmy_zoslanie_ducha_sv(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z114.htm", "ZALM114");
		_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,1-11");
		_set_zalm3(modlitba, "zjv15.htm", "CHVAL_ZJV15");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-27: pridanÈ posv‰tnÈ ËÌtanie a modlitba cez deÚ */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z104.htm", "ZALM104_I");
		_set_zalm2(modlitba, "z104.htm", "ZALM104_II");
		_set_zalm3(modlitba, "z104.htm", "ZALM104_III");
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalmy_1nedele_mcd();
	}
	Log("_set_zalmy_zoslanie_ducha_sv(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-24: pridanÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_najsv_trojice(short int modlitba){
	Log("_set_zalmy_najsv_trojice(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z114.htm", "ZALM114");
		_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z8.htm", "ZALM8");
		_set_zalm2(modlitba, "z33.htm", "ZALM33_I");
		_set_zalm3(modlitba, "z33.htm", "ZALM33_II");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-24: doplnenÈ ûalmy pre modlitbu cez deÚ */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalmy_1nedele_mcd();
	}
	Log("_set_zalmy_najsv_trojice(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-24: pridan· modlitba cez deÚ */
void _set_zalmy_krista_krala(short int modlitba){
	Log("_set_zalmy_krista_krala(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z145.htm", "ZALM145,1-13");
		_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z117.htm", "ZALM117");
		_set_zalm3(modlitba, "zjv4_5.htm", "CHVAL_ZJV45");
	}
	/* 2005-08-12: doplnenÈ ûalmy na posv‰tnÈ ËÌtanie */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z2.htm", "ZALM2");
		_set_zalm2(modlitba, "z72.htm", "ZALM72_I");
		_set_zalm3(modlitba, "z72.htm", "ZALM72_II");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-24: doplnenÈ ûalmy pre modlitbu cez deÚ */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalmy_1nedele_mcd();
	}
	Log("_set_zalmy_krista_krala(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-24: pridanÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_telakrvi(short int modlitba){
	Log("_set_zalmy_telakrvi(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z111.htm", "ZALM111");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "zjv11.htm", "CHVAL_ZJV11");
	}
	/* 2006-01-24: doplnenÈ ûalmy na posv‰tnÈ ËÌtanie */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z23.htm", "ZALM23");
		_set_zalm2(modlitba, "z42.htm", "ZALM42");
		_set_zalm3(modlitba, "z81.htm", "ZALM81");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-24: doplnenÈ ûalmy pre modlitbu cez deÚ */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm_cez_den_doplnkova_psalmodia();
	}
	Log("_set_zalmy_telakrvi(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-24: pridanÈ posv. ËÌtanie a modlitba cez deÚ */
void _set_zalmy_srdca(short int modlitba){
	Log("_set_zalmy_srdca(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z111.htm", "ZALM111");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z146.htm", "ZALM146");
		_set_zalm3(modlitba, "zjv4_5.htm", "CHVAL_ZJV45");
	}
	/* 2006-01-24: doplnenÈ ûalmy na posv‰tnÈ ËÌtanie */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z36.htm", "ZALM36");
		_set_zalm2(modlitba, "z61.htm", "ZALM61");
		_set_zalm3(modlitba, "z98.htm", "ZALM98");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-24: doplnenÈ ûalmy pre modlitbu cez deÚ */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm_cez_den_doplnkova_psalmodia();
	}
	Log("_set_zalmy_srdca(%s) -- end\n", nazov_modlitby(modlitba));
}
/* 2006-02-04: pridanÈ posv‰tnÈ ËÌtanie a mcd */
void _set_zalmy_narodenie(short int modlitba){
	Log("_set_zalmy_narodenie(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z130.htm", "ZALM130");
		_set_zalm3(modlitba, "kol1.htm", "CHVAL_KOL1");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z2.htm", "ZALM2");
		_set_zalm2(modlitba, "z19.htm", "ZALM19,2-7");
		_set_zalm3(modlitba, "z45.htm", "ZALM45");
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm1(modlitba, "z19.htm", "ZALM19,8-15");
		_set_zalm2(modlitba, "z47.htm", "ZALM47");
		_set_zalm3(modlitba, "z48.htm", "ZALM48");
	}
	Log("_set_zalmy_narodenie(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-24: pridanÈ posv. ËÌtania (2006-02-04 doplnenÈ naozajstnÈ ˙daje) */
void _set_zalmy_zjv(short int modlitba){
	Log("_set_zalmy_zjv(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z112.htm", "ZALM112");
		_set_zalm3(modlitba, "zjv15.htm", "CHVAL_ZJV15");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z135.htm", "ZALM135_I");
		_set_zalm2(modlitba, "z135.htm", "ZALM135_II");
		_set_zalm3(modlitba, "1tim3.htm", "CHVAL_1TIM3");
	}
/* 2006-02-04: pridanÈ ûalmy na posv‰tnÈ ËÌtania a modlitbu cez deÚ */
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z72.htm", "ZALM72");
		_set_zalm2(modlitba, "z96.htm", "ZALM96");
		_set_zalm3(modlitba, "z97.htm", "ZALM97");
	}
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		_set_zalm1(modlitba, "z47.htm", "ZALM47");
		_set_zalm2(modlitba, "z86.htm", "ZALM86,1-10");
		_set_zalm3(modlitba, "z98.htm", "ZALM98");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	Log("_set_zalmy_zjv(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_premenenie(short int modlitba){
	Log("_set_zalmy_premenenie(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z121.htm", "ZALM121");
		_set_zalm3(modlitba, "1tim3.htm", "CHVAL_1TIM3");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z117.htm", "ZALM117");
		_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		/* 2005-08-02: pridanÈ posv‰tnÈ ËÌtanie */
		_set_zalm1(modlitba, "z84.htm", "ZALM84");
		_set_zalm2(modlitba, "z97.htm", "ZALM97");
		_set_zalm3(modlitba, "z99.htm", "ZALM99");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	/* 2006-01-24: modlitba cez deÚ: ûalmy s˙ z beûnÈho dÚa */
	Log("_set_zalmy_premenenie(%s) -- end\n", nazov_modlitby(modlitba));
}

/* vespery a posv. citanie */
void _set_zalmy_sviatok_apostolov(short int modlitba){
	Log("_set_zalmy_sviatok_apostolov(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm2(modlitba, "z126.htm", "ZALM126");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z117.htm", "ZALM117");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z19.htm", "ZALM19,2-7");
		_set_zalm2(modlitba, "z64.htm", "ZALM64");
		_set_zalm3(modlitba, "z97.htm", "ZALM97");
	}
	Log("_set_zalmy_sviatok_apostolov(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_sviatok_duch_past(short int modlitba){
	Log("_set_zalmy_sviatok_duch_past(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z15.htm", "ZALM15");
		_set_zalm2(modlitba, "z112.htm", "ZALM112");
		_set_zalm3(modlitba, "zjv15.htm", "CHVAL_ZJV15");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z146.htm", "ZALM146");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z21.htm", "ZALM21");
		_set_zalm2(modlitba, "z92.htm", "ZALM92_I");
		_set_zalm3(modlitba, "z92.htm", "ZALM92_II");
	}
	Log("_set_zalmy_sviatok_duch_past(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_sviatok_panien(short int modlitba){
	Log("_set_zalmy_sviatok_panien(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z122.htm", "ZALM122");
		_set_zalm2(modlitba, "z127.htm", "ZALM127");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z19.htm", "ZALM19,2-7");
		_set_zalm2(modlitba, "z45.htm", "ZALM45_I");
		_set_zalm3(modlitba, "z45.htm", "ZALM45_II");
	}
	Log("_set_zalmy_sviatok_panien(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2005-07-22: Sviatky Panny M·rie maj˙ pre rannÈ chv·ly a veöpery rovnakÈ ûalmy ako 
 * sviatky panien, ale pre posv‰tnÈ ËÌtania s˙ inÈ ûalmy.
 */
void _set_zalmy_sviatok_marie(short int modlitba){
	Log("_set_zalmy_sviatok_marie(%s) -- begin\n", nazov_modlitby(modlitba));
	if((modlitba == MODL_VESPERY) || (modlitba == MODL_PRVE_VESPERY)){
		_set_zalmy_sviatok_panien(modlitba);
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z24.htm", "ZALM24");
		_set_zalm2(modlitba, "z46.htm", "ZALM46");
		_set_zalm3(modlitba, "z87.htm", "ZALM87");
	}
	Log("_set_zalmy_sviatok_marie(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-02-04: Sviatok sv. J·na apoötola-evanjelistu m· pre posv‰tnÈ ËÌtania s˙ inÈ ûalmy
 *             (namiesto 3. ûalmu 97 m· é 99)
 */
void _set_zalmy_sviatok_jana_ap(short int modlitba){
	Log("_set_zalmy_sviatok_jana_ap(%s) -- begin\n", nazov_modlitby(modlitba));
	/* 2006-02-04: nem· ani prvÈ veöpery ani "norm·lne" veöpery */
	if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z19.htm", "ZALM19,2-7");
		_set_zalm2(modlitba, "z64.htm", "ZALM64");
		_set_zalm3(modlitba, "z99.htm", "ZALM99");
	}
	Log("_set_zalmy_sviatok_jana_ap(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_sviatok_muc(short int modlitba){
	Log("_set_zalmy_sviatok_muc(%s) (pre jednÈho muËenÌka resp. spoloËnÈ) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z116.htm", "ZALM116,1-9");
		_set_zalm2(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm3(modlitba, "zjv4_5.htm", "CHVAL_ZJV45");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		/* 2003-08-13, nebolo v z118.htm anchor ZALM118_I resp. II;
		 * je tam ine rozdelenie ako pre ucely modlitby cez den
		 * (napr. nedela 1. tyzdna zaltara), preto som to prerobil
		 */
		_set_zalm1(modlitba, "z118.htm", "ZALM118_muc_I");
		_set_zalm2(modlitba, "z118.htm", "ZALM118_muc_II");
		_set_zalm3(modlitba, "1pt2.htm", "CHVAL_1PT2");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z2.htm", "ZALM2");
		/* viacero muË.:  ZALM33_I, ZALM33_2 - rieöenÌ osobitne
		 * jeden muËenÌk: ZALM11, ZALM17
		 */
		_set_zalm2(modlitba, "z11.htm", "ZALM11");
		_set_zalm3(modlitba, "z17.htm", "ZALM17");
	}
	Log("_set_zalmy_sviatok_muc(%s) (pre jednÈho muËenÌka resp. spoloËnÈ) -- end\n", nazov_modlitby(modlitba));
}

/* 2005-07-22: Doroben· funkËnosù pre odliönÈ ûalmy pre jednÈho resp. viacer˝ch muËenÌkov */
void _set_zalmy_sviatok_muc(short int modlitba, short int su_viaceri){
	Log("_set_zalmy_sviatok_muc(%s) (pre viacer˝ch muËenÌkov) -- begin\n", nazov_modlitby(modlitba));
	_set_zalmy_sviatok_muc(modlitba);
	if((su_viaceri > 0) && (modlitba == MODL_POSV_CITANIE)){
		/* viacero muË.:  ZALM33_I, ZALM33_2
		 * jeden muËenÌk: ZALM11, ZALM17 - rieöen˝ vyööie
		 */
		_set_zalm2(modlitba, "z33.htm", "ZALM33_I");
		_set_zalm3(modlitba, "z33.htm", "ZALM33_II");
	}
	Log("_set_zalmy_sviatok_muc(%s) (pre viacer˝ch muËenÌkov) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_sviatok_krstu(short int modlitba){
	Log("_set_zalmy_sviatok_krstu(%s) -- begin\n", nazov_modlitby(modlitba));
	/* 2007-01-11, prvÈ veöpery a veöpery s˙ rovnakÈ ako na sviatok Zjavenia P·na */
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z112.htm", "ZALM112");
		_set_zalm3(modlitba, "zjv15.htm", "CHVAL_ZJV15");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z135.htm", "ZALM135_I");
		_set_zalm2(modlitba, "z135.htm", "ZALM135_II");
		_set_zalm3(modlitba, "1tim3.htm", "CHVAL_1TIM3");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		/* 2006-01-20: pridanÈ */
		_set_zalm1(modlitba, "z29.htm", "ZALM29");
		_set_zalm2(modlitba, "z66.htm", "ZALM66_I");
		_set_zalm3(modlitba, "z66.htm", "ZALM66_II");
	}
	/* 2006-01-24: doplnenÈ ûalmy pre modlitbu cez deÚ - overiù, Ëi s˙ naozaj z nedele 1. t˝ûdÚa */
	/* 2007-01-11: pre mcd ûalmy z nedele 2. t˝ûdÚa (7.1.) alebo z nedele 3. t˝ûdÚa podæa roka */
	else if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){
		if(_global_den.denvr == 7){
			// ak je to 7.1.
			_set_zalmy_2nedele_mcd();
		}
		else{
			// inak: z nedele 3. t˝ûdÚa - rovnakÈ ako z nedele 1. t˝ûdÚa
			_set_zalmy_1nedele_mcd();
		}
	}
	Log("_set_zalmy_sviatok_krstu(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2006-01-19: pridanÈ, vytvorenÈ pre Obetovanie P·na */
void _set_zalmy_sviatok_obetovania(short int modlitba){
	Log("_set_zalmy_sviatok_obetovania(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z130.htm", "ZALM130");
		_set_zalm3(modlitba, "kol1.htm", "CHVAL_KOL1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z2.htm", "ZALM2");
		_set_zalm2(modlitba, "z19.htm", "ZALM19,2-7");
		_set_zalm3(modlitba, "z45.htm", "ZALM45");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	Log("_set_zalmy_sviatok_obetovania(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2005-08-04: PridanÈ posv‰tnÈ ËÌtania */
void _set_zalmy_slavnost_Cyrila_a_Metoda(short int modlitba){
	Log("_set_zalmy_slavnost_Cyrila_a_Metoda(%s) -- begin\n", nazov_modlitby(modlitba));
	if((modlitba == MODL_VESPERY) || (modlitba == MODL_PRVE_VESPERY)){
		_set_zalm1(modlitba, "z117.htm", "ZALM117");
		_set_zalm2(modlitba, "z146.htm", "ZALM146");
		_set_zalm3(modlitba, "ef1.htm", "CHVAL_EF1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		_set_zalm1(modlitba, "z19.htm", "ZALM19,2-7");
		_set_zalm2(modlitba, "z33.htm", "ZALM33_I");
		_set_zalm3(modlitba, "z33.htm", "ZALM33_II");
	}
	Log("_set_zalmy_slavnost_Cyrila_a_Metoda(%s) -- end\n", nazov_modlitby(modlitba));
}
void _set_zalmy_sv_kriz(short int modlitba){
	Log("_set_zalmy_sv_kriz(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm3(modlitba, "zjv4_5.htm", "CHVAL_ZJV45");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z147.htm", "ZALM147_I");
		_set_zalm2(modlitba, "z147.htm", "ZALM147_II");
		_set_zalm3(modlitba, "flp2.htm", "CHVAL_FLP2");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		/* 2005-08-24: PridanÈ */
		_set_zalm1(modlitba, "z2.htm", "ZALM2");
		_set_zalm2(modlitba, "z8.htm", "ZALM8");
		_set_zalm3(modlitba, "z96.htm", "ZALM96");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	Log("_set_zalmy_sv_kriz(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_archanjelov(short int modlitba){
	Log("_set_zalmy_archanjelov(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z8.htm", "ZALM8");
		_set_zalm2(modlitba, "z138.htm", "ZALM138");
		_set_zalm3(modlitba, "kol1.htm", "CHVAL_KOL1");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		/* 2005-10-13: PridanÈ */
		_set_zalm1(modlitba, "z97.htm", "ZALM97");
		_set_zalm2(modlitba, "z103.htm", "ZALM103_I_ANJ");
		_set_zalm3(modlitba, "z103.htm", "ZALM103_II_ANJ");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	Log("_set_zalmy_archanjelov(%s) -- end\n", nazov_modlitby(modlitba));
}

void _set_zalmy_anjelov_strazcov(short int modlitba){
	Log("_set_zalmy_anjelov_strazcov(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z34.htm", "ZALM34_I");
		_set_zalm2(modlitba, "z34.htm", "ZALM34_II");
		_set_zalm3(modlitba, "zjv11.htm", "CHVAL_ZJV11");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	Log("_set_zalmy_anjelov_strazcov(%s) -- end\n", nazov_modlitby(modlitba));
}
void _set_zalmy_vsetkych_svatych(short int modlitba){
	Log("_set_zalmy_vsetkych_svatych(%s) -- begin\n", nazov_modlitby(modlitba));
	if(modlitba == MODL_VESPERY){
		_set_zalm1(modlitba, "z110.htm", "ZALM110");
		_set_zalm2(modlitba, "z116.htm", "ZALM116,10-19");
		_set_zalm3(modlitba, "zjv4_5.htm", "CHVAL_ZJV45");
	}
	else if(modlitba == MODL_PRVE_VESPERY){
		_set_zalm1(modlitba, "z113.htm", "ZALM113");
		_set_zalm2(modlitba, "z147.htm", "ZALM147,12-20");
		_set_zalm3(modlitba, "zjv19.htm", "CHVAL_ZJV19");
	}
	else if(modlitba == MODL_POSV_CITANIE){
		/* 2005-10-24: PridanÈ */
		_set_zalm1(modlitba, "z8.htm", "ZALM8");
		_set_zalm2(modlitba, "z15.htm", "ZALM15");
		_set_zalm3(modlitba, "z16.htm", "ZALM16");
	}
	else if(modlitba == MODL_RANNE_CHVALY){
		_set_zalmy_1nedele_rch();
	}
	Log("_set_zalmy_vsetkych_svatych(%s) -- end\n", nazov_modlitby(modlitba));
}

/* 2007-11-14: doplnenÈ invitatÛrium; pouûiteænÈ pre _bohorod, _krkrala, _krst... a pod. */
#define _vlastne_slavenie_invitat(anchor) {\
	sprintf(_anchor, "%s_%c%s", anchor, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* 2007-11-14: zjednotenÈ definy pre pÙvodnÈ: 
 * 	_troj_hymnus     , _troj_kresponz     , _troj_ne_antifony     
 * 	_krkrala_hymnus  , _krkrala_kresponz  , _krkrala_ne_antifony 
 * 	_telakrvi_hymnus , _telakrvi_kresponz , _telakrvi_ne_antifony
 * 	_srdca_hymnus    , _srdca_kresponz    , _srdca_ne_antifony   
 * 	_krst_hymnus     , _krst_kresponz     , _krst_ne_antifony    
 * 	_zds_hymnus      , _zds_kresponz      , _zds_antifony        
 * samostatne ostali jedine: _bohorod_hymnus a _sv_rodiny_hymnus
 * resp. _bohorod_kresponz a _sv_rodiny_kresponz
 */
#define _vlastne_slavenie_hymnus(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vlastne_slavenie_kresponz(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2007-10-02: upravenÈ antifÛny pre modlitbu cez deÚ - s˙ rovnakÈ, pouûit˝ anchor ANCHOR_ANTIFONY */
#define _vlastne_slavenie_ne_antifony(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI))? ANCHOR_ANTIFONY : ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI))? ANCHOR_ANTIFONY : ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI))? ANCHOR_ANTIFONY : ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* 2007-11-14: zjednotenÈ definy pre pÙvodnÈ: 
 * 	_sv_rodiny_modlitba 
 * 	_troj_modlitba 
 * 	_krkrala_modlitba 
 * 	_telakrvi_modlitba 
 * 	_srdca_modlitba 
 * 	_krst_modlitba 
 * 	_srdca_pm_modlitba
 * samostatne ostali jedine: _bohorod_modlitba a _zds_modlitba
 */
#define _vlastne_slavenie_modlitba(vlastny_anchor) {\
	sprintf(_anchor, "%s_%s", vlastny_anchor, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* 2007-11-14: zjednotenÈ definy pre pÙvodnÈ: 
 * 	_troj_kcitanie 
 * 	_krkrala_kcitanie 
 * 	_telakrvi_kcitanie 
 * 	_srdca_kcitanie 
 * 	_krst_kcitanie 
 * 	_zds_kcitanie 
 * 	_sv_rodiny_kcitanie
 * samostatne ostali jedine: _bohorod_kcitanie
 */
#define _vlastne_slavenie_kcitanie(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* 2007-11-14: zjednotenÈ definy pre pÙvodnÈ: 
 * 	_troj_citanie1 a _troj_citanie2
 * 	_krkrala_citanie1 a _krkrala_citanie2
 * 	_telakrvi_citanie1 a _telakrvi_citanie2
 * 	_srdca_citanie1 a _srdca_citanie2
 * 	_krst_citanie1 a _krst_citanie2
 * ostatnÈ tri s˙ troöku inak:
 * 	_bohorod_citanie1 a _bohorod_citanie2
 * 	_sv_rodiny_citanie1 a _sv_rodiny_citanie2
 * 	_zds_citanie1 a _zds_citanie2
 */
#define _vlastne_slavenie_citanie1(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vlastne_slavenie_citanie2(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vlastne_slavenie_ine_citanie1(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _vlastne_slavenie_ine_citanie2(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}

/* 2007-11-14: zjednotenÈ definy pre pÙvodnÈ: 
 * 	_bohorod_magnifikat  , _bohorod_prosby  , _bohorod_benediktus 
 * 	_troj_magnifikat     , _troj_prosby     , _troj_benediktus    
 * 	_krkrala_magnifikat  , _krkrala_prosby  , _krkrala_benediktus 
 * 	_telakrvi_magnifikat , _telakrvi_prosby , _telakrvi_benediktus
 * 	_srdca_magnifikat    , _srdca_prosby    , _srdca_benediktus   
 * 	_krst_magnifikat     , _krst_prosby     , _krst_benediktus    
 * 	_zds_magnifikat      , _zds_prosby      , _zds_benediktus     
 * samostatne ostali jedine: _sv_rodiny_magnifikat, _sv_rodiny_prosby, _sv_rodiny_benediktus
 * pridanÈ tieû _srdca_pm_benediktus
 */
#define _vlastne_slavenie_magnifikat(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vlastne_slavenie_prosby(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vlastne_slavenie_benediktus(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

void liturgicke_obdobie(short int litobd, short int tyzden, short int den, short int tyzzal, short int poradie_svateho){
	short int modlitba, t;
	char _anchor_vlastne_slavenie[SMALL]; /* 2007-11-14: pridanÈ */

	Log("-- liturgicke_obdobie(%d, %d, %d, %d: svaty: %d) -- zaciatok\n",
		litobd, tyzden, den, tyzzal, poradie_svateho);


	/* 02/03/2000A.D. -- kedysi tu bolo niekedy nespustenie zaltara, ale to mozeme */
	/* if((_global_den.smer > 5) || (_global_den.smer == 2)) */
		/* najprv spustime zaltar(); */
		/* >5 -- to su [6] nedele vianocneho obdobia a nedele cez rok,
		 *             [7] sviatky panny marie a svatych,
		 *             [8] miestne sviatky,
		 *             [9] adventne vsedne dni od 17. do 24. dec. vratane, 
		 *                 dni v oktave narodenia pana, 
		 *                 vsedne dni v poste,
		 *             [10] povinne spomienky,
		 *             [11] miestne povinne spomienky,
		 *             [12] lubovolne spomienky,
		 *             [13] vsedne dni adventne do 16. decembra vratane,
		 *                  vsedne dni vianocneho obdobia 2. januarom pocnuc a sobotou po zjaveni pana konciac,
		 *                  vsedne dni cez rok.
		 */
		/* == 2:       [2] nedele adventne, postne a velkonocne,
		 *                 vsedne dni velkeho tyzdna od pondelka do stvrtka vcitane
		 */

	 /* najprv treba skontrolovat, ci nejde o nedelu, na ktoru pripadol 
	  * sviatok Premenenia Pana (6. augusta)
	  * resp. sviatok Povysenia sv. Kriza (14. septembra);
	  * ak ano, tak nenastavuj nic, lebo
	  * vsetko sa nastavilo vo funkcii sviatky_svatych()
	  * 28/03/2000A.D.
	  * rovnako tak slavnost vsetkych svatych (1. novembra) - bez ohladu na to, ci ide o nedelu,
	  * 29/03/2000A.D.
	  *
	  * 2003-06-30a.D.: rovnako tak pre slavnost sv. Petra a sv. Pavla (29. juna)
	  *
	  * 2006-02-07: pravdupovediac, vöetko sa nenastavilo (modlitba cez deÚ, ûalmy) - musÌm to fixn˙ù
	  * 
	  * 2007-07-17: vyzer· to tak, ûe asi je potrebnÈ zbehn˙ù aj v t˝chto prÌpadoch nastavenia 
	  *		kvÙli modlitbe cez deÚ tak, ako to bolo len pre sviatok pov˝öenia sv. krÌûa
	  *
	  * 2008-02-27: doplnen˝ aj prÌpad, keÔ na nedeæu padne sl·vnosù nanebovzatia PM (15. augusta)
	  *
	  */
	Log("najprv treba skontrolovaù, Ëi nejde o nedeæu, na ktor˙ pripadol sviatok premenenia p·na a podobnÈ... (ak ·no, nenastavuj niË)\n");
	if(
		((_global_den.denvt == DEN_NEDELA) && (_global_den.den == 6) && (_global_den.mesiac - 1 == MES_AUG)) ||
		((_global_den.denvt == DEN_NEDELA) && (_global_den.den == 15) && (_global_den.mesiac - 1 == MES_AUG)) ||
		((_global_den.denvt == DEN_NEDELA) && (_global_den.den == 29) && (_global_den.mesiac - 1 == MES_JUN)) ||
		((_global_den.denvt == DEN_NEDELA) && (_global_den.den == 14) && (_global_den.mesiac - 1 == MES_SEP) ) ||
		((_global_den.den == 1) && (_global_den.mesiac - 1 == MES_NOV))
		){
			Log("premenenie p·na || petra a pavla || pov˝öenie sv. krÌûa || vöetk˝ch sv‰t˝ch || nanebovzatia PM...\n");
			if((_global_modlitba != MODL_PREDPOLUDNIM) && (_global_modlitba != MODL_NAPOLUDNIE) && (_global_modlitba != MODL_POPOLUDNI)){
				Log("keÔûe sa nejedn· o modlitbu cez deÚ, preskakujeme nastavenia (vöetky boli nastavenÈ z vlastnej Ëasti)...\n");
				return;
			}
			else{
				Log("keÔûe sa jedn· o modlitbu cez deÚ, nastavujeme len hymnus pre MCD a preskakujeme ostatnÈ nastavenia (vöetky ostatnÈ boli nastavenÈ z vlastnej Ëasti)...\n");
				zaltar_zvazok(den, tyzzal, _global_den.litobd, ZALTAR_IBA_ZALMY_HYMNUS_MCD);
				return;
			}
	}
	else{
		Log("NEjedn· sa o: premenenie p·na || petra a pavla || pov˝öenie sv. krÌûa || vöetk˝ch sv‰t˝ch...\n");
	}

	Log("teraz spustÌme zaltar_zvazok(); - pÙvodne sa p˙öùala s dvoma parametrami, pridan˝ parameter pre zv‰zok brevi·ra (vol·me s hodnotou ZALTAR_VSETKO)\n");
	/* 2006-01-24: pÙvodne sa p˙öùala fnkcia s 2 parametrami; pridan˝ ÔalöÌ parameter pre zv‰zok brevi·ra */
	zaltar_zvazok(den, tyzzal, _global_den.litobd, ZALTAR_VSETKO);

	Log("n·sledne odliön˝ s˙bor pre posv‰tnÈ ËÌtania...\n");
	file_name_litobd(litobd);
	Log("  _file == %s\n", _file);

	/* Log(_global_modl_posv_citanie); 2005-03-26: Pridany vypis */

	/* file pre posvatne citania; pridane 2003-11-20 */
	file_name_litobd_pc(litobd);
	Log("  _file_pc == %s\n", _file_pc);

	/* 2004-04-28, pridane _file_pc_tyzden */
	mystrcpy(_file_pc_tyzden, STR_EMPTY, SMALL);
	Log("  _file_pc_tyzden bude nastavene na prislusnom mieste (teraz == `%s').\n", _file_pc_tyzden);

	char c;
	/* char c sa pouziva vo vynimocnych pripadoch: napr. druha velkonocna nedela; 09/03/2000A.D. */

/* 2007-11-13: invitatÛrium */
	/* pouûiteænÈ pre adventnÈ obdobie, vianoËnÈ... */
#define _obd_invitat {\
	sprintf(_anchor, "%s%c_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv_invitat_24DEC {\
	sprintf(_anchor, "%s%c_24_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _obd_invitat_viac(kolko) {\
	sprintf(_anchor, "%s%c_%s%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1, (_global_den.den MOD kolko) + 1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* 2006-01-27: preklopenÈ spoloËnÈ kusy kÛdu pre adventnÈ obdobia do define-ov */
#define _adv_hymnus {\
	sprintf(_anchor, "%s%c_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _adv1_kresponz {\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[DEN_UNKNOWN], /* '??' */ 	pismenko_modlitby(modlitba), /* 'v' */ ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* 2007-10-02: upravenÈ antifÛny pre modlitbu cez deÚ - s˙ rovnakÈ, pouûit˝ anchor ANCHOR_ANTIFONY */
#define _adv_antifony_mcd {\
	/* 1. antifÛna */\
	sprintf(_anchor, "%s%c_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	/* 2. antifÛna */\
	sprintf(_anchor, "%s%c_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	/* 3. antifÛna */\
	sprintf(_anchor, "%s%c_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv1_kcitanie {\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv1_kresp_mcd {\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv1_modlitba {\
	sprintf(_anchor, "%s%d%s_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv1_prosby {\
	sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], t, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv1_antifony {\
	sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}

	/* velky switch(litobd), podla ktoreho sa priradia zakladne udaje */
	LOG_ciara_sv;
	Log("Teraz nasleduje veæk˝ switch() podæa liturgick˝ch obdobÌ...\n");
	switch(litobd){
/* switch(litobd), case OBD_ADVENTNE_I -- begin ----------------------------------------------- */
		case OBD_ADVENTNE_I :/* do 16. decembra */
			Log("OBD_ADVENTNE_I\n");

			/* spoloËnÈ Ëasti bez ohæadu na to, Ëi je alebo nie je nedeæa */

			/* invitatÛrium */
			modlitba = MODL_INVITATORIUM;
			if(_global_jazyk == JAZYK_CZ){
				_obd_invitat_viac(2); /* 2007-12-04: pÙvodne tu bolo "_obd_invitat;", ale Ëesk˝ brevi·r m· na v˝ber 2 */
			}
			else{
				_obd_invitat;
			}
		
			/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_adv_hymnus; /* hymnus */
			_adv1_kresponz; /* kratke responzorium - rovnake pre vsetky dni okrem nedele */
			
			/* vespery */
			modlitba = MODL_VESPERY;
			_adv_hymnus; /* hymnus - rovnaky pre vsetky dni */
			_adv1_kresponz; /* kratke responzorium - rovnake pre vsetky dni okrem nedele */
		
			/* modlitba cez deÚ, pridanÈ 2005-11-20 */
			modlitba = MODL_PREDPOLUDNIM;
			_adv_hymnus; /* hymnus */
			_adv_antifony_mcd; /* antifÛny */
			_adv1_kcitanie; /* kr·tke ËÌtanie - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv1_kresp_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv1_modlitba; /* modlitba ako na rannÈ chv·ly */

			modlitba = MODL_NAPOLUDNIE;
			_adv_hymnus; /* hymnus */
			_adv_antifony_mcd; /* antifÛny */
			_adv1_kcitanie; /* kr·tke ËÌtanie - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv1_kresp_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv1_modlitba; /* modlitba ako na rannÈ chv·ly */

			modlitba = MODL_POPOLUDNI;
			_adv_hymnus; /* hymnus */
			_adv_antifony_mcd; /* antifÛny */
			_adv1_kcitanie; /* kr·tke ËÌtanie - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv1_kresp_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv1_modlitba; /* modlitba ako na rannÈ chv·ly */

			/* posvatne citanie, pridane 2003-11-19 */
			modlitba = MODL_POSV_CITANIE;
			_adv_hymnus; /* hymnus */
			_adv1_modlitba;  /* modlitba - rovnaka ako cez den */

			/* 1. citanie */
			sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_CITANIE1);
			_set_citanie1(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;

			/* 2. citanie */
			sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_CITANIE2);
			_set_citanie2(modlitba, _file_pc, _anchor);
			set_LOG_litobd_pc;

			if(tyzden == 3)
				t = 1;
			else if(tyzden == 4) /* nema efekt, lebo to uz je OBD_ADVENTNE_II */
				t = 2;
			else
				t = tyzden;

			if(den == DEN_NEDELA){ /* nedeæa: 1.-3. adventn· nedeæa */
				/* prve vespery */
				/* 2007-12-04: bola tu dlho t·to pozn·mka: "!!! sem treba zadratovat, ze 16. decembra, 1. vespery,
				 *                                              uz maju mnohe veci z OBD_ADVENTNE_II"
				 * to je vöak zabezpeËenÈ t˝m, ûe pre vöepery 16. decembra (ak je to sobota, ako napr. v roku 2006)
				 * sa jednak vezme vöedn˝ deÚ (sobota), jednak nasleduj˙ci deÚ, teda 17. decembra, a prvÈ veöpery 
				 * s˙ uû z adventnÈho obdobia II., v‰Ëöina vecÌ z 3. adventnej nedele je podæa OBD_ADVENTNE_II, 
				 * niektorÈ z OBD_ADVENTNE_I - pr·ve to bolo potrebnÈ opraviù, dokonËenÈ 2007-12-04.
				 */
				/* hymnus - rovnaky pre prve a druhe vespery */
				modlitba = MODL_PRVE_VESPERY;
				sprintf(_anchor, "%s%c_%s",
					nazov_OBD[litobd],
					pismenko_modlitby(MODL_VESPERY),
					ANCHOR_HYMNUS);
				_set_hymnus(MODL_PRVE_VESPERY, _file, _anchor);
				set_LOG_litobd;
				/* kratke responzorium - rovnaka pre prve a druhe vespery a pre vsetky nedele */
				sprintf(_anchor, "%s%s%c_%s",
					nazov_OBD[litobd],
					nazov_DN_asci[den], /* 'NE' */
					pismenko_modlitby(MODL_VESPERY), /* 'v' */
					ANCHOR_KRESPONZ);
				_set_kresponz(modlitba, _file, _anchor);
				_set_kresponz(MODL_VESPERY, _file, _anchor);
				set_LOG_litobd;

				modlitba = MODL_PRVE_VESPERY;
				_adv1_antifony; /* antifony */
				_adv1_kcitanie; /* kratke citanie - rovnake pre vsetky tyzdne */
				/* magnifikat */
				sprintf(_anchor, "%s%d%s%c_%s%c",
					nazov_OBD[litobd],
					tyzden,
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_MAGNIFIKAT,
					_global_den.litrok);
				_set_magnifikat(modlitba, _file, _anchor);
				set_LOG_litobd;
				_adv1_prosby; /* prosby - rovnake pre prvu a tretiu, resp. druhu a stvrtu adventnu nedelu */
				_adv1_modlitba; /* modlitba */

				/* posvatne citanie */
				/* pridane 2003-11-20 */
				modlitba = MODL_POSV_CITANIE;
				/* hymnus - rovnaky pre vsetky nedele */
				/* kratke responzorium  */
				sprintf(_anchor, "%s%s%c_%s",
					nazov_OBD[litobd],
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_KRESPONZ);
				_set_kresponz(modlitba, _file_pc, _anchor);
				set_LOG_litobd;
				_adv1_antifony; /* antifony */

				/* ranne chvaly */
				/* hymnus - rovnaky pre vsetky dni */
				/* kratke responzorium - rovnake pre vsetky nedele */
				modlitba = MODL_RANNE_CHVALY;
				sprintf(_anchor, "%s%s%c_%s",
					nazov_OBD[litobd],
					nazov_DN_asci[den], /* 'NE' */
					pismenko_modlitby(modlitba), /* 'r' */
					ANCHOR_KRESPONZ);
				_set_kresponz(modlitba, _file, _anchor);
				set_LOG_litobd;
				_adv1_antifony; /* antifony */
				_adv1_kcitanie; /* kratke citanie - rovnake pre vsetky tyzdne */
				/* benediktus */
				sprintf(_anchor, "%s%d%s%c_%s%c",
					nazov_OBD[litobd],
					tyzden,
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_BENEDIKTUS,
					_global_den.litrok);
				_set_benediktus(modlitba, _file, _anchor);
				set_LOG_litobd;
				_adv1_prosby; /* prosby - rovnake pre prvu a tretiu, resp. druhu a stvrtu adventnu nedelu */
				_adv1_modlitba; /* modlitba */

				/* druhe vespery */
				modlitba = MODL_VESPERY;
				_adv1_antifony; /* antifony */
				_adv1_kcitanie; /* kratke citanie - rovnake pre vsetky tyzdne */
				/* magnifikat */
				sprintf(_anchor, "%s%d%s%c_%s%c",
					nazov_OBD[litobd],
					tyzden,
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_MAGNIFIKAT,
					_global_den.litrok);
				_set_magnifikat(modlitba, _file, _anchor);
				set_LOG_litobd;
				_adv1_prosby; /* prosby - rovnake pre prvu a tretiu, resp. druhu a stvrtu adventnu nedelu */
				_adv1_modlitba; /* modlitba */
				/* modlitbu cez deÚ nie je potrebnÈ öpeci·lne rieöiù, pozn·mka 2005-12-17 */
			}/* nedeæa: 1.-3. adventn· nedeæa */
			else{ /* nie nedeæa, teda obyËajn˝ deÚ adventnÈho obdobia I. */
				/* posvatne citanie */
				/* pridane 2003-11-20 */
				modlitba = MODL_POSV_CITANIE;
				/* hymnus - rovnaky pre vsetky dni */
				/* kratke responzorium  */
				sprintf(_anchor, "%s%s%c_%s",
					nazov_OBD[litobd],
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_KRESPONZ);
				_set_kresponz(modlitba, _file_pc, _anchor);
				set_LOG_litobd;
				/* antifony - s˙ ako pre obdobie cez rok, z beûnÈho ûalt·ra; 2005-12-17 */

				/* ranne chvaly */
				/* hymnus - rovnaky pre vsetky dni */
				/* kratke responzorium - rovnake pre vsetky vsedne dni */
				modlitba = MODL_RANNE_CHVALY;
				sprintf(_anchor, "%s%s%c_%s",
					nazov_OBD[litobd],
					nazov_DN_asci[DEN_UNKNOWN], /* '??' */
					pismenko_modlitby(modlitba), /* 'r' */
					ANCHOR_KRESPONZ);
				_set_kresponz(modlitba, _file, _anchor);
				set_LOG_litobd;
				/* antifony - su zo vsedneho dna */
				_adv1_kcitanie; /* kratke citanie - rovnake pre vsetky tyzdne */
				/* benediktus */
				sprintf(_anchor, "%s%d%s%c_%s",
					nazov_OBD[litobd],
					tyzden,
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_BENEDIKTUS);
				_set_benediktus(modlitba, _file, _anchor);
				set_LOG_litobd;
				_adv1_prosby; /* prosby - rovnake pre prvu a tretiu, resp. druhu a stvrtu adventnu nedelu */
				_adv1_modlitba; /* modlitba - rovnaka pre ranne chvaly aj vespery */

				/* vespery */
				/* hymnus - rovnaky pre vsetky dni */
				/* kratke responzorium - rovnake pre vsetky vsedne dni */
				modlitba = MODL_VESPERY;
				sprintf(_anchor, "%s%s%c_%s",
					nazov_OBD[litobd],
					nazov_DN_asci[DEN_UNKNOWN], /* '??' */
					pismenko_modlitby(modlitba), /* 'r' */
					ANCHOR_KRESPONZ);
				_set_kresponz(modlitba, _file, _anchor);
				set_LOG_litobd;
				/* antifony - su zo vsedneho dna */
				_adv1_kcitanie; /* kratke citanie - rovnake pre vsetky tyzdne */
				/* magnifikat */
				sprintf(_anchor, "%s%d%s%c_%s",
					nazov_OBD[litobd],
					tyzden,
					nazov_DN_asci[den],
					pismenko_modlitby(modlitba),
					ANCHOR_MAGNIFIKAT);
				_set_magnifikat(modlitba, _file, _anchor);
				set_LOG_litobd;
				_adv1_prosby; /* prosby - rovnake pre prvu a tretiu, resp. druhu a stvrtu adventnu nedelu */
				_adv1_modlitba; /* modlitba - rovnaka pre ranne chvaly aj vespery */
			}/* nie nedela */
			break;
/* switch(litobd), case OBD_ADVENTNE_I -- end ------------------------------------------------- */

#define _adv2_kcitanie {\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], _global_den.den, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_kcitanie_ne {\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], (_global_den.den == 24) ? 24 : 18, /* len pre nedeæu 24. dec. berie sa 24. dec, inak (pre ostatnÈ nedele) ako keby bolo 18. dec. */ pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_kcitanie_adv1 {\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[OBD_ADVENTNE_I], nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, nazov_obd_htm[OBD_ADVENTNE_I], _anchor);\
	set_LOG_litobd;\
}
#define _adv2_kresponz {\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], (_global_den.den == 24) ? 24 : 18, /* len pre nedeæu 24. dec. berie sa 24. dec, inak (pre ostatnÈ nedele) ako keby bolo 18. dec. */ pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_kresponz_mcd {\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], _global_den.den, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_modlitba {\
	sprintf(_anchor, "%s%d_%s", nazov_OBD[litobd], _global_den.den, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_modlitba_ne {\
	sprintf(_anchor, "%s%d%s_%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_prosby {\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], _global_den.den, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_prosby_4advne {\
	sprintf(_anchor, "%s%d%s%c_%s", nazov_OBD[litobd], 4, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_antifony_vesp {\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[den], pismenko_modlitby(MODL_VESPERY), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[den], pismenko_modlitby(MODL_VESPERY), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[den], pismenko_modlitby(MODL_VESPERY), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _adv2_antifony {\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], _global_den.den, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], _global_den.den, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s%d%c_%s", nazov_OBD[litobd], _global_den.den, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}

/* switch(litobd), case OBD_ADVENTNE_II -- begin ---------------------------------------------- */
		case OBD_ADVENTNE_II:/* po 16. decembri */
			Log("OBD_ADVENTNE_II\n");

			file_name_litobd(OBD_ADVENTNE_II);

			/* invitatÛrium */
			modlitba = MODL_INVITATORIUM;
			if(_global_den.den != 24)
				{_obd_invitat;}
			else
				{_adv_invitat_24DEC;}
		
			/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			/* hymnus - rovnaky pre kazdy den */
			_adv_hymnus;
			/* antifony - zavisia od dna v tyzdni (PONDELOK -- SOBOTA) */
			/* kedze su rovnake na ranne chvaly aj na vespery, rozhodli sme sa
			 * dat tam 'v' */
			_adv2_antifony_vesp;
			/* kratke responzorium - rovnake pre vsetky dni */
			sprintf(_anchor, "%s%s%c_%s",
				nazov_OBD[litobd],
				nazov_DN_asci[DEN_UNKNOWN],
				pismenko_modlitby(modlitba),
				ANCHOR_KRESPONZ);
			_set_kresponz(modlitba, _file, _anchor);
			set_LOG_litobd;
			/* dalsie zavisia od datumu (17. -- 24. december) */
			_adv2_kcitanie; /* kratke citanie */
			/* benediktus */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				_global_den.den,
				pismenko_modlitby(modlitba),
				ANCHOR_BENEDIKTUS);
			_set_benediktus(modlitba, _file, _anchor);
			set_LOG_litobd;
			_adv2_prosby; /* prosby */
			_adv2_modlitba; /* modlitba - rovnaka pre rano i vecer */

			/* vespery */
			/* antifony */
			modlitba = MODL_VESPERY;
			/* hymnus - rovnaky pre kazdy den */
			_adv_hymnus;
			/* antifony - zavisia od dna v tyzdni (PONDELOK -- SOBOTA) */
			_adv2_antifony_vesp;
			/* dalsie zavisia od datumu (17. -- 24. december) */
			/* kratke responzorium - rovnake pre 17. a 18., resp.
			 * pre vsetky ostatne dni (19.-23.) */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				(_global_den.den > 18? 19: 17),
				pismenko_modlitby(modlitba),
				ANCHOR_KRESPONZ);
			_set_kresponz(modlitba, _file, _anchor);
			set_LOG_litobd;
			_adv2_kcitanie; /* kratke citanie */
			/* magnifikat */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				_global_den.den,
				pismenko_modlitby(modlitba),
				ANCHOR_MAGNIFIKAT);
			_set_benediktus(modlitba, _file, _anchor);
			set_LOG_litobd;
			_adv2_prosby; /* prosby */
			_adv2_modlitba; /* modlitba - rovnaka pre rano i vecer */

			/* modlitba cez deÚ, pridanÈ 2005-12-17 trochu podæa ADV.I. */
			modlitba = MODL_PREDPOLUDNIM;
			_adv_hymnus; /* hymnus */
			_adv_antifony_mcd; /* antifÛny */
			/* Ôalöie z·visia od d·tumu (17. -- 24. december) */
			_adv2_kcitanie; /* kratke citanie */
			_adv2_kresponz_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv2_modlitba; /* modlitba ako na rannÈ chv·ly aj veöpery */
			
			modlitba = MODL_NAPOLUDNIE;
			_adv_hymnus; /* hymnus */
			_adv_antifony_mcd; /* antifÛny */
			/* Ôalöie z·visia od d·tumu (17. -- 24. december) */
			_adv2_kcitanie; /* kratke citanie */
			_adv2_kresponz_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv2_modlitba; /* modlitba ako na rannÈ chv·ly aj veöpery */

			modlitba = MODL_POPOLUDNI;
			_adv_hymnus; /* hymnus */
			_adv_antifony_mcd; /* antifÛny */
			/* Ôalöie z·visia od d·tumu (17. -- 24. december) */
			_adv2_kcitanie; /* kratke citanie */
			_adv2_kresponz_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
			_adv2_modlitba; /* modlitba ako na rannÈ chv·ly aj veöpery */

			/* posvatne citanie, pridane 2003-11-19, modifikovane 2003-12-07 */
			modlitba = MODL_POSV_CITANIE;
			_adv_hymnus; /* hymnus */
			_adv2_antifony; /* antifony */

			/* dalsie zavisia od datumu (17. -- 24. december) */
			/* 1. citanie */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				_global_den.den,
				pismenko_modlitby(modlitba),
				ANCHOR_CITANIE1);
			_set_citanie1(modlitba, _file_pc, _anchor);
			set_LOG_litobd;

			/* 2. citanie */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				_global_den.den,
				pismenko_modlitby(modlitba),
				ANCHOR_CITANIE2);
			_set_citanie2(modlitba, _file_pc, _anchor);
			set_LOG_litobd;

			/* kratke responzorium  */
			sprintf(_anchor, "%s%d%c_%s",
				nazov_OBD[litobd],
				_global_den.den,
				pismenko_modlitby(modlitba),
				ANCHOR_KRESPONZ);
			_set_kresponz(modlitba, _file_pc, _anchor);
			set_LOG_litobd;

			_adv2_modlitba; /* modlitba - rovnaka pre rano i vecer */

			/* nedeæa: 3. adventn· nedeæa (len 17. decembra, ako napr. v roku 2006), inak 4. adventn· nedeæa */

			/* pozor! ak tretia adventna nedela padne na 17. decembra, beru sa
			 * antifony na magnifikat, benediktus, prosby a hymny z tejto casti,
			 * avsak ostatne sa berie akoby z OBD_ADVENTNE_I, teda
			 * _file == nazov_obd_htm[OBD_ADVENTNE_I]
			 * _anchor == napr. ADV13NEr_ANT1 
			 * 2007-12-04: doplnenÈ: antifÛna na magnifikat pre prvÈ veöpery 16. decembra (napr. rok 2006)
			 * sa vezme z 3. adventnej nedele
			 */
			if(den == DEN_NEDELA){
				/* prvÈ veöpery - presunutÈ len pre nedeæu, 2007-12-03 */
				modlitba = MODL_PRVE_VESPERY;
				/* hymnus */
				sprintf(_anchor, "%s%c_%s",
					nazov_OBD[litobd],
					pismenko_modlitby(MODL_VESPERY),
					ANCHOR_HYMNUS);
				_set_hymnus(modlitba, _file, _anchor);
				set_LOG_litobd;
				/* antifÛna na magnifikat a prosby z·visia od toho, Ëi je 3. alebo 4. adventn· nedeæa, preto presunutÈ niûöie */

				if((tyzden == 3) && (_global_den.den == 17)){/* jedine 17. decembra, preto doplnenÈ aj o d·tum; 2007-12-04 */
					litobd = OBD_ADVENTNE_I;
					file_name_litobd(litobd);
				
					/* prvÈ veöpery */
					modlitba = MODL_PRVE_VESPERY;
					/* hymnus pre obdobie OBD_ADVENTNE_II, teda tak, ako bol nastaven˝ vyööie */
					_adv1_antifony; /* antifÛny - z tretej adventnej nedele, OBD_ADVENTNE_I; 2007-12-04 */
					_adv1_kcitanie; /* pozor, pouûÌvame z adv. obdobia I. - 2006-01-27 */
					_adv1_modlitba; /* modlitba */
					/* kr·tke responzÛrium - z tretej adventnej nedele, OBD_ADVENTNE_I; 2007-12-04 */
					sprintf(_anchor, "%s%s%c_%s",
						nazov_OBD[litobd],
						nazov_DN_asci[den], /* 'NE' */
						pismenko_modlitby(MODL_VESPERY), /* 'v' */
						ANCHOR_KRESPONZ);
					_set_kresponz(modlitba, _file, _anchor);
					_set_kresponz(MODL_VESPERY, _file, _anchor);
					set_LOG_litobd;
					/* magnifikat */
					sprintf(_anchor, "%s%d%s%c_%s%c",
						nazov_OBD[litobd],
						tyzden,
						nazov_DN_asci[den],
						pismenko_modlitby(modlitba),
						ANCHOR_MAGNIFIKAT,
						_global_den.litrok);
					_set_magnifikat(modlitba, _file, _anchor);
					set_LOG_litobd;
					/* 2007-12-04: kvÙli prosb·m je potrebnÈ nastaviù parameter t */
					if(tyzden == 3)
						t = 1;
					else if(tyzden == 4) /* nema efekt, lebo to uz je OBD_ADVENTNE_II */
						t = 2;
					else
						t = tyzden;
					_adv1_prosby; /* prosby - rovnake pre prvu a tretiu, resp. druhu a stvrtu adventnu nedelu */

					/* posv‰tnÈ ËÌtanie - modlitba m· byù z 3. adventnej nedele, doplnenÈ 2007-12-04 */
					modlitba = MODL_POSV_CITANIE;
					_adv1_modlitba; /* modlitba */

					/* ranne chvaly */
					/* kratke responzorium - rovnake pre vsetky nedele */
					modlitba = MODL_RANNE_CHVALY;
					sprintf(_anchor, "%s%s%c_%s", nazov_OBD[litobd], nazov_DN_asci[den], /* 'NE' */ pismenko_modlitby(modlitba), /* 'r' */ ANCHOR_KRESPONZ);
					_set_kresponz(modlitba, _file, _anchor);
					set_LOG_litobd;
					_adv1_antifony; /* antifony */
					/* kratke citanie - rovnake pre vsetky adventne nedele */
					_adv1_kcitanie; /* pozor, pouûÌvame z adv. obdobia I. - 2006-01-27 */
					_adv1_modlitba; /* modlitba */
				
					/* druhe vespery */
					modlitba = MODL_VESPERY;
					_adv1_antifony; /* antifÛny */
					/* kratke citanie - rovnake pre vsetky adventne nedele */
					_adv1_kcitanie; /* pozor, pouûÌvame z adv. obdobia I. - 2006-01-27 */
					_adv1_modlitba; /* modlitba */
					/* antifÛna na magnifikat pre druhÈ veöpery nastaven· vyööie, podæa d·tumu, ako pre beûn˝ deÚ */

					/* modlitba cez deÚ, pridanÈ 2005-12-17 podæa 2005-11-20 (ADV.I.) okrem hymnov */
					modlitba = MODL_PREDPOLUDNIM;
					_adv_antifony_mcd; /* antifÛny */
					_adv1_kcitanie; /* kr·tke ËÌtanie - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					_adv1_kresp_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					_adv1_modlitba; /* modlitba ako na rannÈ chv·ly */

					modlitba = MODL_NAPOLUDNIE;
					_adv_antifony_mcd; /* antifÛny */
					_adv1_kcitanie; /* kr·tke ËÌtanie - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					_adv1_kresp_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					_adv1_modlitba; /* modlitba ako na rannÈ chv·ly */

					modlitba = MODL_POPOLUDNI;
					_adv_antifony_mcd; /* antifÛny */
					_adv1_kcitanie; /* kr·tke ËÌtanie - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					_adv1_kresp_mcd; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					_adv1_modlitba; /* modlitba ako na rannÈ chv·ly */

				}/* tretia adventna nedela */
				else{/* tyzden == 4, stvrta adventna nedela */

					/* prvÈ veöpery */
					modlitba = MODL_PRVE_VESPERY;
					/* magnifikat - 2007-12-03: upraven· tak, aby pre 18.-24. decembra pre prvÈ veöpery bola vûdy 
					 * z predoölÈho dÚa; v˝nimka je 17. decembra, kedy sa pouûije na prvÈ veöpery antifÛna 
					 * z 3. adventnej nedele, Ëo je zabezpeËenÈ vyööie
					 */

					/* tieto zavisia od datumu (17. -- 24. december) */
					/* antifÛna na magnifikat */
					sprintf(_anchor, "%s%d%c_%s",
						nazov_OBD[litobd],
						_global_den.den - 1,
						pismenko_modlitby(MODL_VESPERY),
						ANCHOR_MAGNIFIKAT);
					_set_benediktus(modlitba, _file, _anchor);
					set_LOG_litobd;
					/* prosby */
					sprintf(_anchor, "%s%d%c_%s",
						nazov_OBD[litobd],
						_global_den.den,
						pismenko_modlitby(MODL_VESPERY),
						ANCHOR_PROSBY);
					_set_prosby(modlitba, _file, _anchor);
					set_LOG_litobd;

					file_name_litobd(OBD_ADVENTNE_I);

					/* kratke responzorium - rovnaka pre prve a druhe vespery a pre vsetky nedele */
					sprintf(_anchor, "%s%s%c_%s",
						nazov_OBD[OBD_ADVENTNE_I],
						nazov_DN_asci[den], /* 'NE' */
						pismenko_modlitby(MODL_VESPERY), /* 'v' */
						ANCHOR_KRESPONZ);
					_set_kresponz(modlitba, nazov_obd_htm[OBD_ADVENTNE_I], _anchor);
					_set_kresponz(MODL_VESPERY, _file, _anchor);
					set_LOG_litobd;

					modlitba = MODL_PRVE_VESPERY;
					_adv1_antifony; /* antifony */
					_adv2_kcitanie_adv1; /* kratke citanie - rovnake pre vsetky adventne nedele */
					_adv2_prosby_4advne; /* prosby */
					_adv2_modlitba_ne; /* modlitba */

					/* ak je 24. dec., vsetko pre ranne chvaly sa berie zo dna 24. */
					if(_global_den.den == 24){
						mystrcpy(_file, nazov_obd_htm[OBD_ADVENTNE_II], MAX_STR_AF_FILE);
						/* benediktus */
						sprintf(_anchor, "%s%d%c_%s",
							nazov_OBD[litobd],
							_global_den.den,
							pismenko_modlitby(MODL_RANNE_CHVALY),
							ANCHOR_BENEDIKTUS);
						_set_benediktus(MODL_RANNE_CHVALY, _file, _anchor);
						set_LOG_litobd;
						goto label_24_DEC;
					}

					/* ranne chvaly */
					/* kratke responzorium - rovnake pre vsetky nedele */
					modlitba = MODL_RANNE_CHVALY;
					sprintf(_anchor, "%s%s%c_%s",
						nazov_OBD[OBD_ADVENTNE_I],
						nazov_DN_asci[den], /* 'NE' */
						pismenko_modlitby(modlitba), /* 'r' */
						ANCHOR_KRESPONZ);
					_set_kresponz(modlitba, nazov_obd_htm[OBD_ADVENTNE_I], _anchor);
					set_LOG_litobd;
					_adv1_antifony; /* antifony */
					_adv2_kcitanie_adv1; /* kratke citanie - rovnake pre vsetky adventne nedele */
					/* benediktus */
					if((_global_den.den == 21) || (_global_den.den == 23)){
						/* treba brat Nebojte sa resp. Hla, splnilo sa */
					}
					else{
					  sprintf(_anchor, "%s%d%s%c_%s%c",
						  nazov_OBD[litobd],
						  tyzden,
						  nazov_DN_asci[den],
						  pismenko_modlitby(modlitba),
						  ANCHOR_BENEDIKTUS,
						  _global_den.litrok);
					  _set_benediktus(modlitba, _file, _anchor);
					}
					set_LOG_litobd;
					_adv2_prosby_4advne; /* prosby */
					_adv2_modlitba_ne; /* modlitba */

					/* druhe vespery */
					modlitba = MODL_VESPERY;
					_adv1_antifony; /* antifony */
					_adv2_kcitanie_adv1; /* kratke citanie - rovnake pre vsetky adventne nedele */
					_adv2_prosby_4advne; /* prosby */
					_adv2_modlitba_ne; /* modlitba */

					/* modlitba cez deÚ, pridanÈ 2005-12-17 trochu podæa 2005-11-20 (ADV.I.) okrem hymnov a antifÛn */
					modlitba = MODL_PREDPOLUDNIM;
					_adv2_modlitba_ne; /* modlitba */

					modlitba = MODL_NAPOLUDNIE;
					_adv2_modlitba_ne; /* modlitba */

					modlitba = MODL_POPOLUDNI;
					_adv2_modlitba_ne; /* modlitba */

					file_name_litobd(OBD_ADVENTNE_II);

					modlitba = MODL_PREDPOLUDNIM;
					/* Ôalöie z·visia od d·tumu (18. dec. pre nedele okrem 24. decembra) */
					_adv2_kcitanie_ne; /* kr·tke ËÌtanie */
					_adv2_kresponz; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */
					modlitba = MODL_NAPOLUDNIE;
					/* Ôalöie z·visia od d·tumu (18. dec. pre nedele okrem 24. decembra) */
					_adv2_kcitanie_ne; /* kr·tke ËÌtanie */
					_adv2_kresponz; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */

					modlitba = MODL_POPOLUDNI;
					/* Ôalöie z·visia od d·tumu (18. dec. pre nedele okrem 24. decembra) */
					_adv2_kcitanie_ne; /* kr·tke ËÌtanie */
					_adv2_kresponz; /* kr·tke responzÛrium - rovnakÈ pre vöetky adventnÈ t˝ûdne */

				}/* stvrta adventna nedela */
			}/* nedela */
			else{
				/* upravime veci pre 24. dec. */
				if(_global_den.den == 24){
label_24_DEC:
					/* iba ranne chvaly */
					modlitba = MODL_RANNE_CHVALY;
					/* hymnus - rovnaky pre kazdy den */
					_adv2_antifony; /* antifony - vlastne */
					/* kratke responzorium - vlastne */
					sprintf(_anchor, "%s%d%c_%s",
						nazov_OBD[litobd],
						_global_den.den,
						pismenko_modlitby(modlitba),
						ANCHOR_KRESPONZ);
					_set_kresponz(modlitba, _file, _anchor);
					set_LOG_litobd;

				}
			}/* nie nedela -- upravenie pre 24. dec. */

			/* Vo vöednÈ dni od 17. do 23. decembra sa ber˙:
			 * invitatÛrium, hymny, ËÌtania a responzÛri·, veröe, modlitba,
			 * antifÛny a prosby na rannÈ chv·ly a veöpery, ako s˙ na
			 * strane 71n. Tieto Ëasti sa potom z tretieho t˝ûdÚa vynech·vaj˙.
			 * ostatne veci sa beru z predosleho */

			break;
/* switch(litobd), case OBD_ADVENTNE_II -- end ------------------------------------------------ */

/* panny marie bohorodicky */
#define _bohorod_hymnus(vlastny_anchor) {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, c, ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _bohorod_kcitanie(vlastny_anchor) {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, c, ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _bohorod_kresponz(vlastny_anchor) {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, c, ANCHOR_KRESPONZ);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
/* 2006-02-05: doplnenÈ posv‰tnÈ ËÌtanie - modlitba ako na rannÈ chv·ly 
 * 2006-02-16: doplnen· modlitba cez deÚ - modlitba ako na rannÈ chv·ly 
 */
#define _bohorod_modlitba {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI) || (modlitba == MODL_POSV_CITANIE))\
		c = pismenko_modlitby(MODL_RANNE_CHVALY);\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, c, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _bohorod_antifony {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, c, ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, c, ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", ANCHOR_PM_BOHOROD, c, ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* sviatok svatej rodiny; 2006-02-05: doplnenÈ posv. ËÌtania a modlitba cez deÚ */
#define _sv_rodiny_hymnus(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _sv_rodiny_kresponz(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _sv_rodiny_prosby(vlastny_anchor) {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, c, ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _sv_rodiny_benediktus(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s%c", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, _global_den.litrok);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _sv_rodiny_magnifikat(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s%c", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, _global_den.litrok);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _sv_rodiny_antifony(vlastny_anchor) {\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", vlastny_anchor, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* vianocne obdobie I */

/* 2006-02-04: doplnenÈ posv‰tnÈ ËÌtania a mcd */
/* 2008-05-16: upravenÈ, aby pre Ëesk˝ brevi·r a prvÈ veöpery narodenia p·na bol in˝ hymnus */
#define _vian1_hymnus {\
	c = pismenko_modlitby(modlitba);\
	if((modlitba == MODL_PRVE_VESPERY) && (_global_den.den != 25))\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_I], c, ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _vian1_kcitanie {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_KCITANIE, _global_den.den);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_2ne_kcitanie {\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* 2006-02-04: doplnenÈ posv‰tnÈ ËÌtania a mcd */
/* 2008-05-16: upravenÈ, aby pre Ëesk˝ brevi·r a prvÈ veöpery narodenia p·na bol in˝ zpÏv po kr·tkÈm ËtenÌ */
#define _vian1_kresponz {\
	c = pismenko_modlitby(modlitba);\
	if((modlitba == MODL_PRVE_VESPERY) && (_global_den.den != 25))\
		c = pismenko_modlitby(MODL_VESPERY);\
	if((den == DEN_NEDELA) && (_global_den.den != 25 /* narodenie Pana */)\
		&& (modlitba != MODL_POSV_CITANIE)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[OBD_VIANOCNE_I], c, ANCHOR_KRESPONZ, nazov_DN_asci[den]);\
	}\
	else if(modlitba != MODL_POSV_CITANIE){\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_I], c, ANCHOR_KRESPONZ);\
	}\
	else {\
		sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[OBD_VIANOCNE_I], c, ANCHOR_KRESPONZ, _global_den.den);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _vian1_prosby {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_PROSBY, _global_den.den);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_2ne_prosby {\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_2ne_benediktus {\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_2ne_magnifikat {\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_benediktus {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, _global_den.den);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_magnifikat {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, _global_den.den);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_2ne_modlitba {\
	sprintf(_anchor, "%s_%s%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_2ne_antifony {\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_2NE_PO_NAR, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian1_modlitba {\
	if(_global_den.den == 25/* narodenie Pana */){\
		sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_MODLITBA, _global_den.den);\
	}\
	else{\
		sprintf(_anchor, "%s_%s%d", nazov_OBD[OBD_VIANOCNE_I], ANCHOR_MODLITBA, _global_den.den);\
	}\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _narodenie_antifony {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_OKTAVA_NARODENIA], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_OKTAVA_NARODENIA], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_OKTAVA_NARODENIA], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-02-04: doplnenÈ posv‰tnÈ ËÌtanie */
#define _vian1_citanie1 {\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE1, _global_den.den);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _vian1_citanie2 {\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE2, _global_den.den);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _vian_okt_antifony_pc {\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1, _global_den.den);\
	_set_antifona1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2, _global_den.den);\
	_set_antifona2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3, _global_den.den);\
	_set_antifona3(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}

/* 2006-02-05: vytvorenÈ pre modlitbu cez deÚ podæa _post1_mcd_antifony; porov. _adv_antifony_mcd */
/* 2007-10-02: upravenÈ antifÛny pre modlitbu cez deÚ - s˙ rovnakÈ, pouûit˝ anchor ANCHOR_ANTIFONY */
#define _vian1_mcd_antifony {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_I], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* switch(litobd), case OBD_OKTAVA_NARODENIA -- begin ----------------------------------------- */
		case OBD_OKTAVA_NARODENIA :/* narodenie Pana -- 1. jan. */
			Log("OBD_OKTAVA_NARODENIA - pokraËujeme ako vianoËnÈ obdobie I...\n");
			/* a pokracujeme ako vianocne obdobie I; 14/03/2000A.D. */
/* switch(litobd), case OBD_VIANOCNE_I -- begin ----------------------------------------------- */
		case OBD_VIANOCNE_I :/* do slavnosti zjavenia pana */
			Log("OBD_VIANOCNE_I\n");

		/* 2006-01-24: tu zaËÌna VIANO»N… OBDOBIE I. */

			if((_global_den.den == 26) || (_global_den.den == 27) || (_global_den.den == 28)){
				/* maju vlastnu cast zo sv. jana apostola, sv. stefana a sv. neviniatok */
			}
			else{
				/* invitatÛrium; 2007-11-13 */
				modlitba = MODL_INVITATORIUM;
				_obd_invitat;

				/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_vian1_hymnus;
				_vian1_kcitanie;
				_vian1_kresponz;
				_vian1_benediktus;
				_vian1_prosby;
				_vian1_modlitba;

				/* posv‰tnÈ ËÌtanie; 2006-02-04 */
				modlitba = MODL_POSV_CITANIE;
				_vian1_hymnus;
				_set_zalmy_vian_oktava(_global_den.den, modlitba);
				if(_global_den.den >= 25){
					/* 2006-02-05: antifÛny s˙ samostatnÈ len pre vianoËn˙ okt·vu; inak zo ûalt·ra */
					_vian_okt_antifony_pc;
				}
				_vian1_kresponz;
				_vian1_citanie1;
				_vian1_citanie2;
				_vian1_modlitba;

				/* modlitba cez deÚ, pridanÈ 2006-02-05 */
				modlitba = MODL_PREDPOLUDNIM;
				_vian1_hymnus; /* hymnus */
				_vian1_mcd_antifony; /* antifÛny */
				_vian1_kcitanie; /* kr·tke ËÌtanie */
				_vian1_kresponz; /* kr·tke responzÛrium */
				_vian1_modlitba; /* modlitba ako na rannÈ chv·ly */

				modlitba = MODL_NAPOLUDNIE;
				_vian1_hymnus; /* hymnus */
				_vian1_mcd_antifony; /* antifÛny */
				_vian1_kcitanie; /* kr·tke ËÌtanie */
				_vian1_kresponz; /* kr·tke responzÛrium */
				_vian1_modlitba; /* modlitba ako na rannÈ chv·ly */

				modlitba = MODL_POPOLUDNI;
				_vian1_hymnus; /* hymnus */
				_vian1_mcd_antifony; /* antifÛny */
				_vian1_kcitanie; /* kr·tke ËÌtanie */
				_vian1_kresponz; /* kr·tke responzÛrium */
				_vian1_modlitba; /* modlitba ako na rannÈ chv·ly */

			}

			/* vespery */
			modlitba = MODL_VESPERY;
			_vian1_hymnus;
			_vian1_kcitanie;
			_vian1_kresponz;
			_vian1_magnifikat;
			_vian1_prosby;
			_vian1_modlitba;

			if(litobd == OBD_OKTAVA_NARODENIA){
				if(_global_den.den == 25){  /* narodenie Pana */
					/* prve vespery */
					modlitba = MODL_PRVE_VESPERY;
					_vian1_hymnus;
					_narodenie_antifony;
					_vian1_kcitanie;
					_vian1_kresponz;
					_vian1_magnifikat;
					_vian1_prosby;
					_vian1_modlitba;
					_set_zalmy_narodenie(modlitba);
					/* modlitba cez deÚ, pridanÈ 2006-02-05 */
					modlitba = MODL_PREDPOLUDNIM;
					_set_zalmy_narodenie(modlitba);
					modlitba = MODL_NAPOLUDNIE;
					_set_zalmy_narodenie(modlitba);
					modlitba = MODL_POPOLUDNI;
					_set_zalmy_narodenie(modlitba);
				}

				/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_narodenie(modlitba);
				_narodenie_antifony;
	
				/* druhe vespery */
				modlitba = MODL_VESPERY;
				_set_zalmy_narodenie(modlitba);
				_narodenie_antifony;
			}

			if((_global_den.den == 1) && (_global_den.mesiac == 1)){ /* Panny Marie Bohorodicky */
				/* panny marie bohorodicky; 14/03/2000A.D. */
				mystrcpy(_file, FILE_PM_BOHOROD, MAX_STR_AF_FILE);
				mystrcpy(_file_pc, FILE_PM_BOHOROD, MAX_STR_AF_FILE); /* 2006-02-05: doplnenÈ */
				mystrcpy(_anchor, ANCHOR_PM_BOHOROD, MAX_STR_AF_ANCHOR);
				mystrcpy(_anchor_vlastne_slavenie, ANCHOR_PM_BOHOROD, MAX_STR_AF_ANCHOR); /* 2007-11-14: pridanÈ */
				Log("  ide o slavnost panny marie bohorodicky: _file = `%s', _anchor = %s...\n", _file, _anchor);

				modlitba = MODL_PRVE_VESPERY;
				_set_zalmy_sviatok_panien(modlitba);
				_bohorod_hymnus(_anchor_vlastne_slavenie);
				_bohorod_kcitanie(_anchor_vlastne_slavenie);
				_bohorod_kresponz(_anchor_vlastne_slavenie);
				_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
				_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
				_bohorod_modlitba;
				_bohorod_antifony;

				/* invitatÛrium; 2007-11-13 */
				modlitba = MODL_INVITATORIUM;
				_vlastne_slavenie_invitat(_anchor_vlastne_slavenie);

				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_1nedele_rch();
				_bohorod_hymnus(_anchor_vlastne_slavenie);
				_bohorod_kcitanie(_anchor_vlastne_slavenie);
				_bohorod_kresponz(_anchor_vlastne_slavenie);
				_vlastne_slavenie_benediktus(_anchor_vlastne_slavenie);
				_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
				_bohorod_modlitba;
				_bohorod_antifony;

				modlitba = MODL_VESPERY;
				_set_zalmy_sviatok_panien(modlitba);
				_bohorod_hymnus(_anchor_vlastne_slavenie);
				_bohorod_kcitanie(_anchor_vlastne_slavenie);
				_bohorod_kresponz(_anchor_vlastne_slavenie);
				_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
				_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
				_bohorod_modlitba;
				_bohorod_antifony;

				/* posv‰tnÈ ËÌtanie; 2006-02-05 */
				modlitba = MODL_POSV_CITANIE;
				_bohorod_hymnus(_anchor_vlastne_slavenie);
				_set_zalmy_sviatok_marie(modlitba);
				_bohorod_antifony;
				_bohorod_kresponz(_anchor_vlastne_slavenie);
				_vlastne_slavenie_ine_citanie1(_anchor_vlastne_slavenie);
				_vlastne_slavenie_ine_citanie2(_anchor_vlastne_slavenie);
				_bohorod_modlitba;

				/* 2006-02-16: doplnenÈ modlitby cez deÚ */
				modlitba = MODL_PREDPOLUDNIM;
				_bohorod_kcitanie(_anchor_vlastne_slavenie);
				_bohorod_modlitba;
				modlitba = MODL_NAPOLUDNIE;
				_bohorod_kcitanie(_anchor_vlastne_slavenie);
				_bohorod_modlitba;
				modlitba = MODL_POPOLUDNI;
				_bohorod_kcitanie(_anchor_vlastne_slavenie);
				_bohorod_modlitba;
			}
			else if((_global_den.denvt == DEN_NEDELA) && (_global_den.mesiac - 1 == MES_JAN)){ /* druha nedela po narodeni pana */
				/* prve vespery */
				modlitba = MODL_PRVE_VESPERY;
				_vian1_hymnus;
				_vian1_2ne_kcitanie;
				_vian1_kresponz;
				_vian1_2ne_magnifikat;
				_vian1_2ne_prosby;
				_vian1_2ne_modlitba;
				_vian1_2ne_antifony;
				/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_vian1_2ne_kcitanie;
				_vian1_2ne_benediktus;
				_vian1_2ne_prosby;
				_vian1_2ne_antifony;
				_vian1_2ne_modlitba;
				/* druhe vespery */
				modlitba = MODL_VESPERY;
				_vian1_2ne_kcitanie;
				_vian1_2ne_magnifikat;
				_vian1_2ne_prosby;
				_vian1_2ne_antifony;
				_vian1_2ne_modlitba;
			
				/* modlitba cez deÚ, pridanÈ 2006-02-05 (posv‰tnÈ ËÌtanie je zo dÚa podæa d·tumu ) */
				modlitba = MODL_PREDPOLUDNIM;
				_vian1_2ne_kcitanie;
				_vian1_kresponz;
				_vian1_2ne_modlitba;
				modlitba = MODL_NAPOLUDNIE;
				_vian1_2ne_kcitanie;
				_vian1_kresponz;
				_vian1_2ne_modlitba;
				modlitba = MODL_POPOLUDNI;
				_vian1_2ne_kcitanie;
				_vian1_kresponz;
				_vian1_2ne_modlitba;
			}
			else if(_global_den.denvr == _global_r._SVATEJ_RODINY.denvr){
				/* sviatok svatej rodiny; 14/03/2000A.D. */
				mystrcpy(_file, FILE_SV_RODINY, MAX_STR_AF_FILE);
				mystrcpy(_file_pc, FILE_SV_RODINY, MAX_STR_AF_FILE); /* 2006-02-05: doplnenÈ */
				mystrcpy(_anchor, ANCHOR_SV_RODINY, MAX_STR_AF_ANCHOR);
				mystrcpy(_anchor_vlastne_slavenie, ANCHOR_SV_RODINY, MAX_STR_AF_ANCHOR); /* 2007-11-14: pridanÈ */
				Log("  ide o sviatok svatej rodiny: _file = `%s', _anchor = %s...\n", _file, _anchor);

				modlitba = MODL_PRVE_VESPERY;
				_set_zalmy_sviatok_panien(modlitba);
				_sv_rodiny_hymnus(_anchor_vlastne_slavenie);
				_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
				_sv_rodiny_kresponz(_anchor_vlastne_slavenie);
				_sv_rodiny_magnifikat(_anchor_vlastne_slavenie);
				_sv_rodiny_prosby(_anchor_vlastne_slavenie);
				_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
				_sv_rodiny_antifony(_anchor_vlastne_slavenie);

				/* invitatÛrium; 2007-11-13 */
				modlitba = MODL_INVITATORIUM;
				_vlastne_slavenie_invitat(_anchor_vlastne_slavenie);

				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_1nedele_rch();
				_sv_rodiny_hymnus(_anchor_vlastne_slavenie);
				_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
				_sv_rodiny_kresponz(_anchor_vlastne_slavenie);
				_sv_rodiny_benediktus(_anchor_vlastne_slavenie);
				_sv_rodiny_prosby(_anchor_vlastne_slavenie);
				_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
				_sv_rodiny_antifony(_anchor_vlastne_slavenie);

				modlitba = MODL_VESPERY;
				_set_zalmy_sviatok_panien(modlitba);
				_sv_rodiny_hymnus(_anchor_vlastne_slavenie);
				_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
				_sv_rodiny_kresponz(_anchor_vlastne_slavenie);
				_sv_rodiny_magnifikat(_anchor_vlastne_slavenie);
				_sv_rodiny_prosby(_anchor_vlastne_slavenie);
				_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
				_sv_rodiny_antifony(_anchor_vlastne_slavenie);

				/* posv‰tnÈ ËÌtanie; 2006-02-05 */
				modlitba = MODL_POSV_CITANIE;
				_sv_rodiny_hymnus(_anchor_vlastne_slavenie);
				_set_zalmy_sviatok_marie(modlitba);
				_sv_rodiny_antifony(_anchor_vlastne_slavenie);
				_sv_rodiny_kresponz(_anchor_vlastne_slavenie);
				_vlastne_slavenie_ine_citanie1(_anchor_vlastne_slavenie);
				_vlastne_slavenie_ine_citanie2(_anchor_vlastne_slavenie);
				_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);

				/* modlitba cez deÚ, pridanÈ 2006-02-05 */
				modlitba = MODL_PREDPOLUDNIM;
				_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
				_sv_rodiny_kresponz(_anchor_vlastne_slavenie);
				_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
				/* ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
				if(_global_den.denvt != DEN_NEDELA) {
					_set_zalm_cez_den_doplnkova_psalmodia();
				}
				else {
					_set_zalmy_1nedele_mcd();
				}

				modlitba = MODL_NAPOLUDNIE;
				_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
				_sv_rodiny_kresponz(_anchor_vlastne_slavenie);
				_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
				/* ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
				if(_global_den.denvt != DEN_NEDELA) {
					_set_zalm_cez_den_doplnkova_psalmodia();
				}
				else {
					_set_zalmy_1nedele_mcd();
				}

				modlitba = MODL_POPOLUDNI;
				_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
				_sv_rodiny_kresponz(_anchor_vlastne_slavenie);
				_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
				/* ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
				if(_global_den.denvt != DEN_NEDELA) {
					_set_zalm_cez_den_doplnkova_psalmodia();
				}
				else {
					_set_zalmy_1nedele_mcd();
				}

			}
			break;
/* switch(litobd), case OBD_OKTAVA_NARODENIA -- end ------------------------------------------- */
/* switch(litobd), case OBD_VIANOCNE_I -- end ------------------------------------------------- */

/* switch(litobd), case OBD_VIANOCNE_II -- begin ---------------------------------------------- */
		case OBD_VIANOCNE_II: {/* po slavnosti zjavenia pana */
			Log("OBD_VIANOCNE_II\n");
/* vianocne obdobie II */
/* 2006-02-07: doplnenÈ posv‰tnÈ ËÌtania a mcd */
#define _vian2_hymnus {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _zjv_kcitanie {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_KCITANIE, _global_den.den);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-02-07: doplnenÈ posv‰tnÈ ËÌtania */
#define _vian2_kresponz {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	if(modlitba != MODL_POSV_CITANIE){\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_II], c, ANCHOR_KRESPONZ);\
	}\
	else {\
		sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[OBD_VIANOCNE_II], c, ANCHOR_KRESPONZ, _global_den.den);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _vian2_prosby {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_II], c, ANCHOR_PROSBY, _global_den.den);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian2_benediktus {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, _global_den.den);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian2_magnifikat {\
	sprintf(_anchor, "%s_%c%s%d", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, _global_den.den);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vian2_modlitba {\
	sprintf(_anchor, "%s_%s%d", nazov_OBD[OBD_VIANOCNE_II], ANCHOR_MODLITBA, _global_den.den);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-02-07: pridanÈ posv‰tnÈ ËÌtanie */
#define _zjv_antifony {\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_II], ANCHOR_ZJAVENIE_PANA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_II], ANCHOR_ZJAVENIE_PANA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VIANOCNE_II], ANCHOR_ZJAVENIE_PANA, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
/* 2006-02-07: doplnenÈ posv‰tnÈ ËÌtanie */
#define _vian2_citanie1 {\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE1, _global_den.den);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _vian2_citanie2 {\
	sprintf(_anchor, "%s_%c%s_%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE2, _global_den.den);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}

/* 2006-02-07: vytvorenÈ pre modlitbu cez deÚ podæa _vian1_mcd_antifony (to podæa _post1_mcd_antifony; porov. _adv_antifony_mcd) */
/* 2007-10-02: upravenÈ antifÛny pre modlitbu cez deÚ - s˙ rovnakÈ, pouûit˝ anchor ANCHOR_ANTIFONY */
#define _vian2_mcd_antifony {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[OBD_VIANOCNE_II], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
									 
		/* 2006-01-24: tu v skutoËnosti zaËÌna VIANO»N… OBDOBIE II. */

			/* invitatÛrium; 2007-11-13 */
			modlitba = MODL_INVITATORIUM;
			_obd_invitat;

			/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_vian2_hymnus;
			_vian2_kresponz;
			_vian2_benediktus;
			_vian2_prosby;
			_vian2_modlitba;

			/* vespery */
			modlitba = MODL_VESPERY;
			_vian2_hymnus;
			_vian2_kresponz;
			_vian2_magnifikat;
			_vian2_prosby;
			_vian2_modlitba;

			/* posv‰tnÈ ËÌtanie; 2006-02-07 */
			modlitba = MODL_POSV_CITANIE;
			_vian2_hymnus;
			_vian2_kresponz;
			_vian2_citanie1;
			_vian2_citanie2;
			_vian2_modlitba;

			/* modlitba cez deÚ, pridanÈ 2006-02-05 */
			modlitba = MODL_PREDPOLUDNIM;
			_vian2_hymnus; /* hymnus */
			_vian2_mcd_antifony; /* antifÛny */
			/* kr·tke ËÌtanie nastavenÈ neskÙr podæa vian1 */
			_vian2_kresponz; /* kr·tke responzÛrium */
			_vian2_modlitba; /* modlitba ako na rannÈ chv·ly */

			modlitba = MODL_NAPOLUDNIE;
			_vian2_hymnus; /* hymnus */
			_vian2_mcd_antifony; /* antifÛny */
			/* kr·tke ËÌtanie nastavenÈ neskÙr podæa vian1 */
			_vian2_kresponz; /* kr·tke responzÛrium */
			_vian2_modlitba; /* modlitba ako na rannÈ chv·ly */

			modlitba = MODL_POPOLUDNI;
			_vian2_hymnus; /* hymnus */
			_vian2_mcd_antifony; /* antifÛny */
			/* kr·tke ËÌtanie nastavenÈ neskÙr podæa vian1 */
			_vian2_kresponz; /* kr·tke responzÛrium */
			_vian2_modlitba; /* modlitba ako na rannÈ chv·ly */

			if((_global_den.den == 6) && (_global_den.mesiac == 1)){ /* zjavenie pana */
				/* prve vespery */
				modlitba = MODL_PRVE_VESPERY;
				_vian2_hymnus;
				_zjv_antifony;
				_zjv_kcitanie;
				_vian2_kresponz;
				_vian2_magnifikat;
				_vian2_prosby;
				_vian2_modlitba;
				_set_zalmy_zjv(modlitba);

				/* invitatÛrium; 2007-11-14: netreba, nakoæko antifÛna je rovnak· pre celÈ obdobie po zjavenÌ p·na */

				/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_zjv(modlitba);
				_zjv_kcitanie;
				_zjv_antifony;
				
				/* druhe vespery */
				modlitba = MODL_VESPERY;
				_set_zalmy_zjv(modlitba);
				_zjv_kcitanie;
				_zjv_antifony;
				/* posv‰tnÈ ËÌtanie; 2006-02-07 */
				modlitba = MODL_POSV_CITANIE;
				_set_zalmy_zjv(modlitba);
				_zjv_antifony;
				/* modlitby cez deÚ, pridanÈ 2006-02-05 */
				modlitba = MODL_PREDPOLUDNIM;
				_set_zalmy_zjv(modlitba);
				_zjv_kcitanie;
				modlitba = MODL_NAPOLUDNIE;
				_set_zalmy_zjv(modlitba);
				_zjv_kcitanie;
				modlitba = MODL_POPOLUDNI;
				_set_zalmy_zjv(modlitba);
				_zjv_kcitanie;

			}/* zjavenie pana */
			else{
				/* vsedny den vianocneho obdobia II -- citania podla vian.obd.I 
				 * 2006-02-07: presne takto isto sa spr·vaj˙ aj kr·tke ËÌtania pre modlitbu cez deÚ
				 *             (ako pre kr·tk ËÌtanie na rannÈ chv·ly)
				 */
				mystrcpy(_file, nazov_obd_htm[OBD_VIANOCNE_I], MAX_STR_AF_FILE);
				if(_global_den.den == 8){
					modlitba = MODL_RANNE_CHVALY;
					_global_den.den = 31;
					_vian1_kcitanie;
					modlitba = MODL_PREDPOLUDNIM;
					_vian1_kcitanie;
					modlitba = MODL_NAPOLUDNIE;
					_vian1_kcitanie;
					modlitba = MODL_POPOLUDNI;
					_vian1_kcitanie;
					modlitba = MODL_VESPERY;
					_global_den.den = 28;
					_vian1_kcitanie;
				}
				else{
					if(_global_den.den == 7){
						_global_den.den = 30;
						modlitba = MODL_RANNE_CHVALY;
						_vian1_kcitanie;
						modlitba = MODL_PREDPOLUDNIM;
						_vian1_kcitanie;
						modlitba = MODL_NAPOLUDNIE;
						_vian1_kcitanie;
						modlitba = MODL_POPOLUDNI;
						_vian1_kcitanie;
						modlitba = MODL_VESPERY;
						_vian1_kcitanie;
					}
					else{/* den == 9, 10, 11, 12 */
						_global_den.den = _global_den.den - 7; /* den == 2, 3, 4, 5 */
						modlitba = MODL_RANNE_CHVALY;
						_vian1_kcitanie;
						modlitba = MODL_PREDPOLUDNIM;
						_vian1_kcitanie;
						modlitba = MODL_NAPOLUDNIE;
						_vian1_kcitanie;
						modlitba = MODL_POPOLUDNI;
						_vian1_kcitanie;
						modlitba = MODL_VESPERY;
						_vian1_kcitanie;					
					}
				}
			}/* obycajny den vian.obd. II -- priradenie citania */

			}
			break;
/* switch(litobd), case OBD_VIANOCNE_II -- end ------------------------------------------------ */

/* switch(litobd), case OBD_CEZ_ROK -- begin -------------------------------------------------- */
		case OBD_CEZ_ROK:{
			Log("OBD_CEZ_ROK\n");

	/* 2006-01-24: tu v skutoËnosti zaËÌna CEZRO»N… OBDOBIE */

				/* najprv treba skontrolovat, ci nejde o nedelu, na ktoru pripadol 
				 * sviatok Premenenia Pana (6. augusta); ak ano, tak nenastavuj nic, lebo
				 * vsetko sa nastavilo vo funkcii sviatky_svatych()
				 * 28/03/2000A.D.
				 */
				if((_global_den.denvt == DEN_NEDELA) && (_global_den.den == 6) && (_global_den.mesiac - 1 == MES_AUG)){
					Log("premenenie pana, so break...\n");
					break;
				}
				if(_global_den.denvt == DEN_NEDELA){
					Log("--- nedela OCR, nastavujem modlitbu dna...\n");
					/* ak je specialna, tak _file sa nastavi v dalsom, 10/03/2000A.D. */
					file_name_litobd(OBD_CEZ_ROK);
					/* benediktus */
					modlitba = MODL_RANNE_CHVALY;
					sprintf(_anchor, "_%d%s%c_%s%c", tyzden, nazov_DN_asci[den], /* 'NE', nedela */ pismenko_modlitby(MODL_RANNE_CHVALY), ANCHOR_BENEDIKTUS, _global_den.litrok);
					_set_benediktus(MODL_RANNE_CHVALY, _file, _anchor);
					set_LOG_litobd;
					/* magnifikat 1 */
					modlitba = MODL_PRVE_VESPERY;
					sprintf(_anchor, "_%d%s%c_%s%c", tyzden, nazov_DN_asci[den], /* 'NE', nedela */ pismenko_modlitby(MODL_PRVE_VESPERY), ANCHOR_MAGNIFIKAT, _global_den.litrok);
					_set_magnifikat(MODL_PRVE_VESPERY, _file, _anchor);
					set_LOG_litobd;
					/* magnifikat v */
					modlitba = MODL_VESPERY;
					sprintf(_anchor, "_%d%s%c_%s%c", tyzden, nazov_DN_asci[den], /* 'NE', nedela */ pismenko_modlitby(MODL_VESPERY), ANCHOR_MAGNIFIKAT, _global_den.litrok);
					_set_magnifikat(MODL_VESPERY, _file, _anchor);
					set_LOG_litobd;
					/* modlitba */
					sprintf(_anchor, "_%d%s_%s", tyzden, nazov_DN_asci[den], /* 'NE', nedela */ ANCHOR_MODLITBA); 
					modlitba = MODL_RANNE_CHVALY;
					_set_modlitba(MODL_RANNE_CHVALY, _file, _anchor);
					set_LOG_litobd;
					modlitba = MODL_PRVE_VESPERY;
					_set_modlitba(MODL_PRVE_VESPERY, _file, _anchor);
					set_LOG_litobd;
					modlitba = MODL_VESPERY;
					_set_modlitba(MODL_VESPERY, _file, _anchor);
					set_LOG_litobd;
					/* modlitba pre posvatne citania a modlitbu cez den, 2005-03-27 */
					modlitba = MODL_PREDPOLUDNIM;
					_set_modlitba(MODL_PREDPOLUDNIM, _file, _anchor);
					set_LOG_litobd;
					modlitba = MODL_NAPOLUDNIE;
					_set_modlitba(MODL_NAPOLUDNIE, _file, _anchor);
					set_LOG_litobd;
					modlitba = MODL_POPOLUDNI;
					_set_modlitba(MODL_POPOLUDNI, _file, _anchor);
					set_LOG_litobd;
					modlitba = MODL_POSV_CITANIE;
					_set_modlitba(MODL_POSV_CITANIE, _file, _anchor);
					set_LOG_litobd;

				/* posvatne citanie, pridane 2004-04-28; presunutÈ 2006-01-24 sem a do Ëasti "nie nedeæa" kvÙli napr. Najsv. Trojici */
					Log("posvatne citanie, pridane 2004-04-28...\n");

					/* idem nastavit _file_pc_tyzden podla tyzdna */
					file_name_litobd_pc_tyzden(litobd, tyzden);
					Log("  _file_pc_tyzden == %s\n", _file_pc_tyzden);

					modlitba = MODL_POSV_CITANIE;

					/* 1. citanie */
					sprintf(_anchor, "%s%d%s%c_%s",
						nazov_OBD[litobd],
						tyzden,
						nazov_DN_asci[den],
						pismenko_modlitby(modlitba),
						ANCHOR_CITANIE1);
					_set_citanie1(modlitba, _file_pc_tyzden, _anchor);
					set_LOG_litobd_pc_tyzden;
					/* Log(_global_modl_posv_citanie); */

					/* 2. citanie */
					sprintf(_anchor, "%s%d%s%c_%s",
						nazov_OBD[litobd],
						tyzden,
						nazov_DN_asci[den],
						pismenko_modlitby(modlitba),
						ANCHOR_CITANIE2);
					/*
						Log("docasne - %s\n", _file_pc_tyzden);
						Log("docasne - %s\n", _anchor);
					*/
					_set_citanie2(modlitba, _file_pc_tyzden, _anchor);
					set_LOG_litobd_pc_tyzden;
					/* Log(_global_modl_posv_citanie); */


					/* 10/03/2000A.D. */
					if(_global_den.denvr == (_global_r._ZOSLANIE_DUCHA_SV.denvr + 7)){
						/* najsv. trojice; 10/03/2000A.D. */
						mystrcpy(_file, FILE_NAJSV_TROJICE, MAX_STR_AF_FILE);
						mystrcpy(_anchor, ANCHOR_NAJSV_TROJICE, MAX_STR_AF_ANCHOR);
						mystrcpy(_anchor_vlastne_slavenie, ANCHOR_NAJSV_TROJICE, MAX_STR_AF_ANCHOR); /* 2007-11-14: pridanÈ */
						Log("  ide o slavnost najsv. trojice: _file = `%s', _anchor = %s...\n", _file, _anchor);

						modlitba = MODL_PRVE_VESPERY;
						_set_zalmy_najsv_trojice(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						/* invitatÛrium; 2007-11-14 */
						modlitba = MODL_INVITATORIUM;
						_vlastne_slavenie_invitat(_anchor_vlastne_slavenie);

						modlitba = MODL_RANNE_CHVALY;
						_set_zalmy_najsv_trojice(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_benediktus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						modlitba = MODL_VESPERY;
						_set_zalmy_najsv_trojice(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						/* 2006-01-24: doplnenÈ posv‰tnÈ ËÌtania */
						modlitba = MODL_POSV_CITANIE;
						_set_zalmy_najsv_trojice(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_citanie1(_anchor_vlastne_slavenie);
						_vlastne_slavenie_citanie2(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_set_zalmy_najsv_trojice(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						modlitba = MODL_NAPOLUDNIE;
						_set_zalmy_najsv_trojice(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						modlitba = MODL_POPOLUDNI;
						_set_zalmy_najsv_trojice(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
					}/* najsv. trojice */
					else if(tyzden == 34){
						/* krista krala -- 34. nedela obdobia `cez rok'; 10/03/2000A.D. */
						mystrcpy(_file, FILE_KRISTA_KRALA, MAX_STR_AF_FILE);
						mystrcpy(_anchor, ANCHOR_KRISTA_KRALA, MAX_STR_AF_ANCHOR);
						mystrcpy(_anchor_vlastne_slavenie, ANCHOR_KRISTA_KRALA, MAX_STR_AF_ANCHOR); /* 2007-11-14: pridanÈ */
						Log("  ide o slavnost krista krala: _file = `%s', _anchor = %s...\n", _file, _anchor);

						modlitba = MODL_PRVE_VESPERY;
						_set_zalmy_krista_krala(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						/* invitatÛrium; 2007-11-14 */
						modlitba = MODL_INVITATORIUM;
						_vlastne_slavenie_invitat(_anchor_vlastne_slavenie);

						modlitba = MODL_RANNE_CHVALY;
						_set_zalmy_krista_krala(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_benediktus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						/* 2005-08-12: pridanÈ posv‰tnÈ ËÌtanie; opravenÈ 2006-01-24 */
						modlitba = MODL_POSV_CITANIE;
						_set_zalmy_krista_krala(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						/* s˙ nastavenÈ ako 34. nedeæa cezroËnÈho obdobia vyööie
						_vlastne_slavenie_citanie1(_anchor_vlastne_slavenie);
						_vlastne_slavenie_citanie2(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						*/
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						modlitba = MODL_VESPERY;
						_set_zalmy_krista_krala(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_set_zalmy_krista_krala(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						modlitba = MODL_NAPOLUDNIE;
						_set_zalmy_krista_krala(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						modlitba = MODL_POPOLUDNI;
						_set_zalmy_krista_krala(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
					}/* krista krala */
					else if((tyzden == 1) && (_global_den.denvr == _global_r._KRST_KRISTA_PANA.denvr)){
						/* krst krista pana -- 1. nedela obdobia `cez rok'; 14/03/2000A.D. */
						mystrcpy(_file, FILE_KRST_PANA, MAX_STR_AF_FILE);
						mystrcpy(_anchor, ANCHOR_KRST_PANA, MAX_STR_AF_ANCHOR);
						mystrcpy(_anchor_vlastne_slavenie, ANCHOR_KRST_PANA, MAX_STR_AF_ANCHOR); /* 2007-11-14: pridanÈ */
						Log("  ide o slavnost najsv. trojice.: _file = `%s', _anchor = %s...\n", _file, _anchor);

						modlitba = MODL_PRVE_VESPERY;
						_set_zalmy_sviatok_krstu(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						/* invitatÛrium; 2007-11-14 */
						modlitba = MODL_INVITATORIUM;
						_vlastne_slavenie_invitat(_anchor_vlastne_slavenie);

						modlitba = MODL_RANNE_CHVALY;
						_set_zalmy_sviatok_krstu(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_benediktus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						modlitba = MODL_VESPERY;
						_set_zalmy_sviatok_krstu(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						/* 2006-01-24: doplnenÈ posv‰tnÈ ËÌtania */
						modlitba = MODL_POSV_CITANIE;
						_set_zalmy_sviatok_krstu(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						/* hoci by mohli byù nastavenÈ ako 1. nedeæa cezroËnÈho obdobia vyööie,
						 * predsa pouûijeme samostatn˝ s˙bor a samostatne ich nastavÌme; 2006-02-07
						 */
						_vlastne_slavenie_citanie1(_anchor_vlastne_slavenie);
						_vlastne_slavenie_citanie2(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_set_zalmy_sviatok_krstu(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						modlitba = MODL_NAPOLUDNIE;
						_set_zalmy_sviatok_krstu(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						modlitba = MODL_POPOLUDNI;
						_set_zalmy_sviatok_krstu(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
					}/* krst krista pana */
				}/* nedela v obdobi cez rok */
				else{
					Log("--- obdobie cez rok, nie nedela...\n");
					/* nie je nedela, ale len bezny den - feria - v obdobi cez rok */

				/* posvatne citanie, pridane 2004-04-28; presunutÈ sem (aj do nedele) 2006-01-24 */
					Log("posvatne citanie, pridane 2004-04-28...\n");

					/* idem nastavit _file_pc_tyzden podla tyzdna */
					file_name_litobd_pc_tyzden(litobd, tyzden);
					Log("  _file_pc_tyzden == %s\n", _file_pc_tyzden);

					modlitba = MODL_POSV_CITANIE;

					/* 1. citanie */
					sprintf(_anchor, "%s%d%s%c_%s",
						nazov_OBD[litobd],
						tyzden,
						nazov_DN_asci[den],
						pismenko_modlitby(modlitba),
						ANCHOR_CITANIE1);
					_set_citanie1(modlitba, _file_pc_tyzden, _anchor);
					set_LOG_litobd_pc_tyzden;
					/* Log(_global_modl_posv_citanie); */

					/* 2. citanie */
					sprintf(_anchor, "%s%d%s%c_%s",
						nazov_OBD[litobd],
						tyzden,
						nazov_DN_asci[den],
						pismenko_modlitby(modlitba),
						ANCHOR_CITANIE2);
					/*
						Log("docasne - %s\n", _file_pc_tyzden);
						Log("docasne - %s\n", _anchor);
					*/
					_set_citanie2(modlitba, _file_pc_tyzden, _anchor);
					set_LOG_litobd_pc_tyzden;
					/* Log(_global_modl_posv_citanie); */

					if(_global_den.denvr == (_global_r._ZOSLANIE_DUCHA_SV.denvr + 11)){ /* 2008-05-08: v breviar.cpp sa pouûÌva define TELAKRVI */
						/* najsv. kristovho tela a krvi; 10/03/2000A.D. */
						mystrcpy(_file, FILE_TELA_A_KRVI, MAX_STR_AF_FILE);
						mystrcpy(_anchor, ANCHOR_TELA_A_KRVI, MAX_STR_AF_ANCHOR);
						mystrcpy(_anchor_vlastne_slavenie, ANCHOR_TELA_A_KRVI, MAX_STR_AF_ANCHOR); /* 2007-11-14: pridanÈ */
						Log("  ide o slavnost najsv. kristovho tela a krvi: _file = `%s', _anchor = %s...\n", _file, _anchor);

						/* 2008-05-08: doplnenÈ kompletÛrium */
						modlitba = MODL_PRVE_KOMPLETORIUM;
						_set_kompletorium_slavnost(modlitba, litobd);

						modlitba = MODL_KOMPLETORIUM;
						_set_kompletorium_slavnost(modlitba, litobd);

						modlitba = MODL_PRVE_VESPERY;
						_set_zalmy_telakrvi(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						/* invitatÛrium; 2007-11-14 */
						modlitba = MODL_INVITATORIUM;
						_vlastne_slavenie_invitat(_anchor_vlastne_slavenie);

						modlitba = MODL_RANNE_CHVALY;
						_set_zalmy_telakrvi(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_benediktus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						modlitba = MODL_VESPERY;
						_set_zalmy_telakrvi(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						/* 2006-01-24: doplnenÈ posv‰tnÈ ËÌtania */
						modlitba = MODL_POSV_CITANIE;
						_set_zalmy_telakrvi(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_citanie1(_anchor_vlastne_slavenie);
						_vlastne_slavenie_citanie2(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_set_zalmy_telakrvi(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						modlitba = MODL_NAPOLUDNIE;
						_set_zalmy_telakrvi(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						modlitba = MODL_POPOLUDNI;
						_set_zalmy_telakrvi(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
					}/* tela a krvi */
					else if(_global_den.denvr == (_global_r._ZOSLANIE_DUCHA_SV.denvr + 19)){ /* 2008-05-08: v breviar.cpp sa pouûÌva define SRDCA */
						/* najsv. srdca jezisovho; 10/03/2000A.D. */
						mystrcpy(_file, FILE_SRDCA, MAX_STR_AF_FILE);
						mystrcpy(_anchor, ANCHOR_SRDCA, MAX_STR_AF_ANCHOR);
						mystrcpy(_anchor_vlastne_slavenie, ANCHOR_SRDCA, MAX_STR_AF_ANCHOR); /* 2007-11-14: pridanÈ */
						Log("  ide o slavnost najsv. srdca jezisovho: _file = `%s', _anchor = %s...\n", _file, _anchor);

						/* 2008-05-08: doplnenÈ kompletÛrium */
						modlitba = MODL_PRVE_KOMPLETORIUM;
						_set_kompletorium_slavnost(modlitba, litobd);

						modlitba = MODL_KOMPLETORIUM;
						_set_kompletorium_slavnost(modlitba, litobd);

						modlitba = MODL_PRVE_VESPERY;
						_set_zalmy_srdca(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						/* invitatÛrium; 2007-11-14 */
						modlitba = MODL_INVITATORIUM;
						_vlastne_slavenie_invitat(_anchor_vlastne_slavenie);

						modlitba = MODL_RANNE_CHVALY;
						_set_zalmy_srdca(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_benediktus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						modlitba = MODL_VESPERY;
						_set_zalmy_srdca(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
						_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

						/* 2006-01-24: doplnenÈ posv‰tnÈ ËÌtania */
						modlitba = MODL_POSV_CITANIE;
						_set_zalmy_srdca(modlitba);
						_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_citanie1(_anchor_vlastne_slavenie);
						_vlastne_slavenie_citanie2(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						modlitba = MODL_PREDPOLUDNIM;
						_set_zalmy_srdca(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						modlitba = MODL_NAPOLUDNIE;
						_set_zalmy_srdca(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
						modlitba = MODL_POPOLUDNI;
						_set_zalmy_srdca(modlitba);
						_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
						_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
						_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
					}/* srdca */
					else if(_global_den.denvr == (_global_r._ZOSLANIE_DUCHA_SV.denvr + 20)){ /* 2008-05-08: v breviar.cpp sa pouûÌva define SRDPM */
						/* neposkvrneneho srdca prebl. panny marie; 04/07/2000A.D. */
						Log("  (hoci tu nic nenastavujem) ide o spomienku neposkvrneneho srdca prebl. panny marie\n");
					}
					else {
						/* 2005-03-27: posvatne citania doplnena modlitba - je z prislusnej nedele OCR */
						Log("--- modlitba dna pre bezne dni OCR je z prislusnej nedele...\n");
						modlitba = MODL_POSV_CITANIE;
						/* modlitba */
						sprintf(_anchor, "_%d%s_%s", tyzden, nazov_DN_asci[DEN_NEDELA], ANCHOR_MODLITBA); 
						modlitba = MODL_POSV_CITANIE;
						_set_modlitba(MODL_POSV_CITANIE, _file, _anchor);
						set_LOG_litobd;
					}
				}/* nie nedela */
				/* 2006-01-24: chv·la Bohu, dokonËenÈ cezroËnÈ obdobie 
				 *             vr·tane posv. ËÌtania a modlity cez deÚ :) 
				 * 2006-02-02: dokonËenÈ pre cezroËnÈ obdobie aj æs PM v sobotu :)
				 */
			}

			break;
/* switch(litobd), case OBD_CEZ_ROK -- end ---------------------------------------------------- */

/* switch(litobd), case OBD_POSTNE_I -- begin ------------------------------------------------- */
		case OBD_POSTNE_I:/* do soboty v piatom tyzdni */
			Log("OBD_POSTNE_I\n");
			/* 06/03/2000A.D. */
/* 2006-01-24: upravenÈ pre posv‰tnÈ ËÌtanie
 * 2006-01-25: pre modlitbu cez deÚ aj pre nedeæu hymnus ako pre vöedn˝ deÚ.
 */
#define _post1_hymnus {\
	if((den == DEN_NEDELA)\
		&& (modlitba != MODL_PREDPOLUDNIM) && (modlitba != MODL_NAPOLUDNIE) && (modlitba != MODL_POPOLUDNI)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_HYMNUS);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
/* 2006-01-24: doplnenÈ posv‰tnÈ ËÌtanie */
#define _post1_citanie1 {\
	sprintf(_anchor, "%s_%c%s_%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE1, tyzden, nazov_DN_asci[den]);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _post1_citanie2 {\
	sprintf(_anchor, "%s_%c%s_%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE2, tyzden, nazov_DN_asci[den]);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _post1_kcitanie {\
	if(tyzden != 5){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%s%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE, tyzden);\
	}\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-24: upravenÈ pre posv‰tnÈ ËÌtanie
 * 2006-01-25: pre modlitbu cez deÚ platÌ to istÈ Ëo pre beûn˝ deÚ, t.j. responz· s˙ rovnakÈ.
 *             jedin· zmena: aj pre nedeæu pre mcd platÌ to, Ëo pre vöedn˝ deÚ.
 */
#define _post1_kresponz {\
	if((den == DEN_NEDELA) && (modlitba == MODL_POSV_CITANIE)){\
		sprintf(_anchor, "%s_%c%s%s%d", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, nazov_DN_asci[den], tyzden);\
	}\
	else if(((den == DEN_NEDELA) || (modlitba == MODL_POSV_CITANIE))\
		&& (modlitba != MODL_PREDPOLUDNIM) && (modlitba != MODL_NAPOLUDNIE) && (modlitba != MODL_POPOLUDNI)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, nazov_DN_asci[den]);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _post1_prosby {\
	if((den == DEN_STREDA) && (tyzden == 0) && (modlitba == MODL_RANNE_CHVALY)){\
		sprintf(_anchor, "%s_%c%s%sPOPOL", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_PROSBY, nazov_DN_asci[den]);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_PROSBY, t, nazov_DN_asci[den]);\
	}\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _post1_benediktus {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den]);\
	}\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _post1_magnifikat {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den]);\
	}\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _post1_modlitba {\
	sprintf(_anchor, "%s_%s%d%s", nazov_OBD[litobd], ANCHOR_MODLITBA, tyzden, nazov_DN_asci[den]);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _post1_ne_antifony {\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

/* 2006-01-25: vytvorenÈ pre modlitbu cez deÚ */
/* 2007-10-02: upravenÈ antifÛny pre modlitbu cez deÚ - s˙ rovnakÈ, pouûit˝ anchor ANCHOR_ANTIFONY */
#define _post1_mcd_antifony {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

		/* 2006-01-24: tu v skutoËnosti zaËÌna POSTNE OBDOBIE I. */

			t = tyzden MOD 2;

			/* 2007-12-05: kompletÛrium v pÙstnom obdobÌ */
			modlitba = MODL_KOMPLETORIUM;
			set_hymnus_kompletorium_obd(den, tyzzal, modlitba, litobd);

			/* invitatÛrium; 2007-11-14 */
			modlitba = MODL_INVITATORIUM;
			_obd_invitat_viac(2);

			/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_post1_hymnus;
			_post1_kcitanie;
			_post1_kresponz;
			_post1_benediktus;
			_post1_prosby;
			_post1_modlitba;

			/* vespery */
			modlitba = MODL_VESPERY;
			_post1_hymnus;
			_post1_kcitanie;
			_post1_kresponz;
			_post1_magnifikat;
			_post1_prosby;
			_post1_modlitba;

			/* 2006-01-24: posv‰tnÈ ËÌtanie */
			modlitba = MODL_POSV_CITANIE;
			_post1_hymnus;
			_post1_citanie1;
			_post1_citanie2;
			_post1_kresponz;
			_post1_modlitba;

			/* 2006-01-25: modlitba cez deÚ MODL_PREDPOLUDNIM + MODL_NAPOLUDNIE + MODL_POPOLUDNI */
			modlitba = MODL_PREDPOLUDNIM;
			_post1_hymnus;
			_post1_mcd_antifony;
			_post1_kcitanie;
			_post1_kresponz;
			_post1_modlitba;
			modlitba = MODL_NAPOLUDNIE;
			_post1_hymnus;
			_post1_mcd_antifony;
			_post1_kcitanie;
			_post1_kresponz;
			_post1_modlitba;
			modlitba = MODL_POPOLUDNI;
			_post1_hymnus;
			_post1_mcd_antifony;
			_post1_kcitanie;
			_post1_kresponz;
			_post1_modlitba;

			if(den == DEN_NEDELA){

				/* prve vespery */
				modlitba = MODL_PRVE_VESPERY;
				_post1_hymnus;
				_post1_ne_antifony;
				_post1_kcitanie;
				_post1_kresponz;
				_post1_magnifikat;
				_post1_prosby;
				_post1_modlitba;
				/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_post1_ne_antifony;
				/* druhe vespery */
				modlitba = MODL_VESPERY;
				_post1_ne_antifony;
			}/* nedela */
			else{
			}/* nie nedela */
			break;
/* switch(litobd), case OBD_POSTNE_I -- end --------------------------------------------------- */

/* switch(litobd), case OBD_POSTNE_II -- begin ------------------------------------------------ */
		case OBD_POSTNE_II_VELKY_TYZDEN:/* velky tyzden */
			Log("OBD_POSTNE_II_VELKY_TYZDEN\n");
			/* 08/03/2000A.D. */
/* 2006-01-25: upravenÈ pre posv‰tnÈ ËÌtanie
 * 2006-01-25: pre modlitbu cez deÚ (okrem nedele) je hymnus ako pre pÙstne obdobie I.
 */
#define _post2_hymnus {\
	if(((den == DEN_STVRTOK) && (modlitba == MODL_VESPERY))\
	|| ((den == DEN_NEDELA) && ((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)))){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_HYMNUS);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _post2_kcitanie {\
	if((den == DEN_NEDELA) && (modlitba == MODL_RANNE_CHVALY)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE);\
		_set_kcitanie(modlitba, _file, _anchor);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%s%d", nazov_OBD[OBD_POSTNE_I], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE, 5);\
		_set_kcitanie(modlitba, nazov_obd_htm[OBD_POSTNE_I], _anchor);\
	}\
	set_LOG_litobd;\
}
/* 2006-01-25: doplnenÈ posv‰tnÈ ËÌtanie 
 * 2006-02-08: modlitba cez deÚ aj posv. ËÌtanie maj˙ responzÛrium rovnakÈ, Ëi je alebo nie je nedeæa
 */
#define _post2_kresponz {\
	if(((den == DEN_STVRTOK) && (modlitba == MODL_VESPERY)) || ((den == DEN_NEDELA) && (modlitba != MODL_PREDPOLUDNIM) && (modlitba != MODL_NAPOLUDNIE) && (modlitba != MODL_POPOLUDNI) && (modlitba != MODL_POSV_CITANIE))){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, nazov_DN_asci[den]);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _post2_prosby {\
	if(((den == DEN_STVRTOK) && (modlitba == MODL_VESPERY)) || (den == DEN_NEDELA)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_PROSBY, nazov_DN_asci[den]);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	}\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _post2_benediktus {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den]);\
	}\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _post2_magnifikat {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den]);\
	}\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-25: upravenÈ: odliön· modlitba je len pre veöpery na Zelen˝ ötvrtok */
#define _post2_modlitba {\
	if((den == DEN_STVRTOK) && (modlitba == MODL_VESPERY)){\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MODLITBA, tyzden, nazov_DN_asci[den]);\
	}\
	else{\
		sprintf(_anchor, "%s_%s%d%s", nazov_OBD[litobd], ANCHOR_MODLITBA, tyzden, nazov_DN_asci[den]);\
	}\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-25: doplnenÈ posv‰tnÈ ËÌtanie */
#define _post2_antifony {\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
/* 2006-01-25: doplnenÈ posv‰tnÈ ËÌtanie */
#define _post2_citanie1 {\
	sprintf(_anchor, "%s_%c%s_%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE1, tyzden, nazov_DN_asci[den]);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _post2_citanie2 {\
	sprintf(_anchor, "%s_%c%s_%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE2, tyzden, nazov_DN_asci[den]);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}

/* 2006-01-25: vytvorenÈ pre modlitbu cez deÚ */
/* 2007-10-02: upravenÈ antifÛny pre modlitbu cez deÚ - s˙ rovnakÈ, pouûit˝ anchor ANCHOR_ANTIFONY */
#define _post2_mcd_antifony {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-27: pridanÈ pre popis veöpier veækonoËnÈho trojdnia (vr·tane zelenÈho ötvrtka */
#define _vtroj_popis {\
	sprintf(_anchor, "%s_%c%s_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_POPIS, nazov_DN_asci[den]);\
	if(modlitba == MODL_POSV_CITANIE){\
		set_popis(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		set_popis(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}

		/* 2006-01-24: tu v skutoËnosti zaËÌna POSTNE OBDOBIE II. */

			/* 2007-12-05: kompletÛrium v pÙstnom obdobÌ */
			modlitba = MODL_KOMPLETORIUM;
			/* 2008-04-04: opravenÈ, aby zelen˝ ötvrtok mal spr·vnu modlitbu a kr·tky responz */
			if(den == DEN_STVRTOK){
				_vtroj_popis;
				_set_kompletorium_slavnost(modlitba, litobd);
				set_hymnus_kompletorium_obd(den, tyzzal, modlitba, litobd);
				set_kresponz_kompletorium_obd(den, tyzzal, modlitba, litobd);
			}
			else{
				set_hymnus_kompletorium_obd(den, tyzzal, modlitba, litobd);
			}

			/* invitatÛrium; 2007-11-14 */
			modlitba = MODL_INVITATORIUM;
			_obd_invitat;

			/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_post2_hymnus;
			_post2_antifony;
			_post2_kcitanie;
			_post2_kresponz;
			_post2_benediktus;
			_post2_prosby;
			_post2_modlitba;
			
			/* vespery */
			modlitba = MODL_VESPERY;
			_post2_hymnus;
			_post2_antifony;
			_post2_kcitanie;
			_post2_kresponz;
			_post2_magnifikat;
			_post2_prosby;
			_post2_modlitba;

			/* 2006-01-25: posv‰tnÈ ËÌtanie */
			modlitba = MODL_POSV_CITANIE;
			_post2_hymnus;
			_post2_citanie1;
			_post2_citanie2;
			_post2_kresponz;
			_post2_modlitba;

			/* 2006-01-25: modlitba cez deÚ MODL_PREDPOLUDNIM + MODL_NAPOLUDNIE + MODL_POPOLUDNI */
			modlitba = MODL_PREDPOLUDNIM;
			_post2_hymnus;
			_post2_mcd_antifony;
			_post2_kcitanie;
			_post2_kresponz;
			_post2_modlitba;
			modlitba = MODL_NAPOLUDNIE;
			_post2_hymnus;
			_post2_mcd_antifony;
			_post2_kcitanie;
			_post2_kresponz;
			_post2_modlitba;
			modlitba = MODL_POPOLUDNI;
			_post2_hymnus;
			_post2_mcd_antifony;
			_post2_kcitanie;
			_post2_kresponz;
			_post2_modlitba;

			if(den == DEN_NEDELA){
				/* Kvetn· nedeæa */

				/* prve vespery */
				modlitba = MODL_PRVE_VESPERY;
				_post2_hymnus;
				_post2_antifony;
				_post2_kcitanie;
				_post2_kresponz;
				_post2_magnifikat;
				_post2_prosby;
				_post2_modlitba;

				/* 2006-01-25: posv‰tnÈ ËÌtanie */
				modlitba = MODL_POSV_CITANIE;
				_post2_antifony;
			}/* nedela */
			else if(den == DEN_STVRTOK){
				/* 2006-01-27: pridan˝ popis k veöper·m zelenÈho ötvrtka */
				modlitba = MODL_VESPERY;
				_vtroj_popis;
				/* 2007-12-05: kompletÛrium je z nedele po druh˝ch veöper·ch; ale ako na sl·vnosti; 2008-04-04 presunutÈ vyööie */
			}/* nie nedela ale zelen˝ ötvrtok */
			break;
/* switch(litobd), case OBD_POSTNE_II -- end -------------------------------------------------- */

/* switch(litobd), case OBD_VELKONOCNE_TROJDNIE -- begin -------------------------------------- */
		case OBD_VELKONOCNE_TROJDNIE:/* umucenia a zmrtvychvstania Pana */
			Log("OBD_VELKONOCNE_TROJDNIE\n");
			/* 08/03/2000A.D. */
/* 2007-11-14: doplnenÈ antifÛny pre invitatÛrium */
#define _vtroj_invitat {\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-26: doplnenÈ posv‰tnÈ ËÌtanie */
#define _vtroj_hymnus {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[OBD_VELKONOCNE_TROJDNIE], c, nazov_DN_asci[den], ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _vtroj_kcitanie {\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-26: doplnenÈ posv‰tnÈ ËÌtanie */
#define _vtroj_kresponz {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[OBD_VELKONOCNE_TROJDNIE], c, ANCHOR_KRESPONZ, nazov_DN_asci[den]);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
#define _vtroj_prosby {\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_PROSBY, nazov_DN_asci[den]);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vtroj_benediktus {\
	sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den]);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vtroj_magnifikat {\
	sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den]);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vtroj_modlitba {\
	sprintf(_anchor, "%s_%s%d%s", nazov_OBD[litobd], ANCHOR_MODLITBA, tyzden, nazov_DN_asci[den]);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-26: doplnenÈ posv‰tnÈ ËÌtanie
 * 2008-03-30: upravenÈ antifÛny pre modlitbu cez deÚ - s˙ rovnakÈ, pouûit˝ anchor ANCHOR_ANTIFONY
 */
#define _vtroj_antifony {\
	c = pismenko_modlitby(modlitba);\
	if(modlitba == MODL_PRVE_VESPERY)\
		c = pismenko_modlitby(MODL_VESPERY);\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VELKONOCNE_TROJDNIE], nazov_DN_asci[den], c, ((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI))? ANCHOR_ANTIFONY : ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VELKONOCNE_TROJDNIE], nazov_DN_asci[den], c, ((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI))? ANCHOR_ANTIFONY : ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%s%c%s", nazov_OBD[OBD_VELKONOCNE_TROJDNIE], nazov_DN_asci[den], c, ((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI))? ANCHOR_ANTIFONY : ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
/* 2006-01-26: doplnenÈ posv‰tnÈ ËÌtanie */
#define _vtroj_citanie1 {\
	sprintf(_anchor, "%s_%c%s_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE1, nazov_DN_asci[den]);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _vtroj_citanie2 {\
	sprintf(_anchor, "%s_%c%s_%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE2, nazov_DN_asci[den]);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}

			/* 2007-12-06: kompletÛrium vo veækonoËnom trojdnÌ: aû na kr·tky responz je z nedele po druh˝ch veöper·ch */
			modlitba = MODL_KOMPLETORIUM;
			/* 2008-04-04: opravenÈ, aby veæk˝ piatok mal spr·vnu modlitbu */
			if(den == DEN_PIATOK){
				_set_kompletorium_slavnost(modlitba, litobd);
			}
			else{
				_set_kompletorium_nedela(modlitba);
			}
			set_kresponz_kompletorium_obd(den, tyzzal, modlitba, litobd);
			set_antifony_kompletorium_obd(den, tyzzal, modlitba, litobd);
			if(den != DEN_PIATOK){
				set_hymnus_kompletorium_obd(den, tyzzal, modlitba, litobd);
			}

			/* invitatÛrium; 2007-11-14 */
			modlitba = MODL_INVITATORIUM;
			_vtroj_invitat;

			/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kcitanie;
			_vtroj_kresponz;
			_vtroj_benediktus;
			_vtroj_prosby;
			_vtroj_modlitba;
		
			/* vespery */
			modlitba = MODL_VESPERY;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kcitanie;
			_vtroj_kresponz;
			_vtroj_magnifikat;
			_vtroj_prosby;
			_vtroj_modlitba;

			/* 2006-01-26: posv‰tnÈ ËÌtanie */
			modlitba = MODL_POSV_CITANIE;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_citanie1;
			_vtroj_citanie2;
			_vtroj_kresponz;
			_vtroj_modlitba;

			/* 2006-01-26: modlitba cez deÚ MODL_PREDPOLUDNIM + MODL_NAPOLUDNIE + MODL_POPOLUDNI */
			modlitba = MODL_PREDPOLUDNIM;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kcitanie;
			_vtroj_kresponz;
			_vtroj_modlitba;
			modlitba = MODL_NAPOLUDNIE;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kcitanie;
			_vtroj_kresponz;
			_vtroj_modlitba;
			modlitba = MODL_POPOLUDNI;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kcitanie;
			_vtroj_kresponz;
			_vtroj_modlitba;

			if(den == DEN_NEDELA){
				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_velkonocna_nedela(modlitba);
				modlitba = MODL_VESPERY;
				_set_zalmy_velkonocna_nedela(modlitba);
				modlitba = MODL_POSV_CITANIE;
				_set_zalmy_velkonocna_nedela(modlitba);
				/* 2006-01-27: pridan˝ popis k posv. ËÌtaniu veækonoËnej nedele */
				_vtroj_popis;
				modlitba = MODL_PREDPOLUDNIM;
				_set_zalmy_velkonocna_nedela(modlitba);
				modlitba = MODL_NAPOLUDNIE;
				_set_zalmy_velkonocna_nedela(modlitba);
				modlitba = MODL_POPOLUDNI;
				_set_zalmy_velkonocna_nedela(modlitba);
			}/* nedela */
			else if(den == DEN_SOBOTA){
				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_biela_sobota(modlitba);
				modlitba = MODL_VESPERY;
				_set_zalmy_biela_sobota(modlitba);
				modlitba = MODL_POSV_CITANIE;
				_set_zalmy_biela_sobota(modlitba);
				modlitba = MODL_PREDPOLUDNIM;
				_set_zalmy_biela_sobota(modlitba);
				modlitba = MODL_NAPOLUDNIE;
				_set_zalmy_biela_sobota(modlitba);
				modlitba = MODL_POPOLUDNI;
				_set_zalmy_biela_sobota(modlitba);
			}/* nie nedela, ale biela sobota */
			else if(den == DEN_PIATOK){
				modlitba = MODL_VESPERY;
				_set_zalmy_velky_piatok(modlitba);
				/* 2006-01-27: pridan˝ popis k veöper·m veækÈho piatka */
				_vtroj_popis;
				modlitba = MODL_POSV_CITANIE;
				_set_zalmy_velky_piatok(modlitba);
				modlitba = MODL_PREDPOLUDNIM;
				_set_zalmy_velky_piatok(modlitba);
				modlitba = MODL_NAPOLUDNIE;
				_set_zalmy_velky_piatok(modlitba);
				modlitba = MODL_POPOLUDNI;
				_set_zalmy_velky_piatok(modlitba);
			}/* nie nedela, ani sobota, ale veæk˝ piatok */
			break;
/* switch(litobd), case OBD_VELKONOCNE_TROJDNIE -- end ---------------------------------------- */

/* switch(litobd), case OBD_VELKONOCNE_I -- begin --------------------------------------------- */
		case OBD_VELKONOCNE_I:/* do nanebovstupenia pana */
			Log("OBD_VELKONOCNE_I\n");
			/* 09/03/2000A.D. */
/* zabezpecime nahodnost pri hymne vo feriu, kedy sa "podla lubovole" mozre brat nie nedelny hymnus */
/* ((_global_den.den MOD 3) == 0) */
/* 2006-01-27: pridan· modlitba posv‰tnÈ ËÌtanie 
 * 2006-02-08: pre modlitbu cez deÚ nem· nedeæa odliön˝ hymnus, preto "podæa æubovÙle" nie pre modlitbu cez deÚ
 * 2006-02-09: skorektnenÈ: rovnocenn˝ test: nie je MCD a (nedeæa alebo MOD 3); MOD aj vzhæadom k modlitbe
 */
#define _velk1_hymnus {\
	if(((den == DEN_NEDELA) || (((_global_den.den + modlitba) MOD 3) == 0))\
		&& ((modlitba != MODL_PREDPOLUDNIM) && (modlitba != MODL_NAPOLUDNIE) && (modlitba != MODL_POPOLUDNI))\
	){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_HYMNUS, nazov_DN_asci[DEN_NEDELA]);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}

#define _velk1_kcitanie {\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[OBD_VELKONOCNE_I], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-27: pridan· modlitba posv‰tnÈ ËÌtanie */
#define _velk1_kresponz {\
	if(((den == DEN_NEDELA) || (modlitba == MODL_POSV_CITANIE))\
		&& (modlitba != MODL_PREDPOLUDNIM) && (modlitba != MODL_NAPOLUDNIE) && (modlitba != MODL_POPOLUDNI)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, nazov_DN_asci[den]);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	}\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_kresponz(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
/* 2006-01-27: doplnenÈ posv‰tnÈ ËÌtanie */
#define _velk1_citanie1 {\
	sprintf(_anchor, "%s_%c%s_%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE1, tyzden, nazov_DN_asci[den]);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _velk1_citanie2 {\
	sprintf(_anchor, "%s_%c%s_%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_CITANIE2, tyzden, nazov_DN_asci[den]);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_litobd_pc;\
}
#define _velk1_prosby {\
	sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[OBD_VELKONOCNE_I], pismenko_modlitby(modlitba), ANCHOR_PROSBY, t, nazov_DN_asci[den]);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk1_benediktus {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den]);\
	}\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk1_magnifikat {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den]);\
	}\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk1_modlitba {\
	sprintf(_anchor, "%s_%s%d%s", nazov_OBD[litobd], ANCHOR_MODLITBA, tyzden, nazov_DN_asci[den]);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* 2006-01-28: doplnenÈ antifÛny pre posv‰tnÈ ËÌtania */
#define _velk1_ne_antifony {\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona1(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona2(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_antifona3(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}
/* 2006-01-28: doplnenÈ antifÛny pre modlitbu cez deÚ */
/* 2007-10-02: upravenÈ antifÛny pre modlitbu cez deÚ - s˙ rovnakÈ, pouûit˝ anchor ANCHOR_ANTIFONY */
#define _velk1_mcd_antifony {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

		/* 2006-01-24: tu v skutoËnosti zaËÌna VEºKONO»N… OBDOBIE I. */

			t = tyzden MOD 2;

			/* 2007-12-06: kompletÛrium vo veækonoËnom obdobÌ */
			modlitba = MODL_KOMPLETORIUM;
			set_hymnus_kompletorium_obd(den, tyzzal, modlitba, litobd);
			set_kresponz_kompletorium_obd(den, tyzzal, modlitba, litobd);
			set_antifony_kompletorium_obd(den, tyzzal, modlitba, litobd);

			if(_global_den.denvr == _global_r._NANEBOVSTUPENIE_PANA.denvr){
				/* nanebovstupenie sice ma rovnake kotvy, ale v inom fajli; 10/03/2000A.D. */
				/* 2006-02-09: odËlenenÈ samostatne, lebo sa tu ökaredo natvrdo pre rannÈ chv·ly 
				 *             a veöpety nastavuje den = DEN_NEDELA 
				 */
				mystrcpy(_file, FILE_NANEBOVSTUPENIE, MAX_STR_AF_FILE);
				mystrcpy(_file_pc, FILE_NANEBOVSTUPENIE, MAX_STR_AF_FILE); /* 2006-02-09: doplnenÈ */
				mystrcpy(_anchor_vlastne_slavenie, ANCHOR_NANEBOVSTUPENIE, MAX_STR_AF_ANCHOR); /* 2007-11-14: pridanÈ */
				Log("  ide o nanebovstupenie Pana: _file = `%s', den = %s...\n", _file, nazov_dna(den));

				/* 2008-05-08: pridanÈ kompletÛrium po prv˝ch aj druh˝ch veöper·ch (copy+paste kÛdu pre nedeæu, z 2007-12-06) */
				modlitba = MODL_PRVE_KOMPLETORIUM;
				_set_kompletorium_slavnost(modlitba, litobd);
				set_hymnus_kompletorium_obd(den, tyzzal, modlitba, litobd);
				set_antifony_kompletorium_obd(den, tyzzal, modlitba, litobd);
				set_kresponz_kompletorium_obd(den, tyzzal, modlitba, litobd);

				modlitba = MODL_KOMPLETORIUM;
				_set_kompletorium_slavnost(modlitba, litobd);
				set_hymnus_kompletorium_obd(den, tyzzal, modlitba, litobd);
				set_antifony_kompletorium_obd(den, tyzzal, modlitba, litobd);
				set_kresponz_kompletorium_obd(den, tyzzal, modlitba, litobd);

				den = DEN_NEDELA;

				/* invitatÛrium; 2007-11-14 */
				modlitba = MODL_INVITATORIUM;
				_vlastne_slavenie_invitat(_anchor_vlastne_slavenie);

				modlitba = MODL_PRVE_VESPERY;
				_set_zalmy_nanebovstupenie(modlitba);
				modlitba = MODL_RANNE_CHVALY;
				_set_zalmy_nanebovstupenie(modlitba);
				modlitba = MODL_VESPERY;
				_set_zalmy_nanebovstupenie(modlitba);

				/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_velk1_hymnus;
				_velk1_kcitanie;
				_velk1_kresponz;
				_velk1_benediktus;
				_velk1_prosby;
				_velk1_modlitba;

				/* vespery */
				modlitba = MODL_VESPERY;
				_velk1_hymnus;
				_velk1_kcitanie;
				_velk1_kresponz;
				_velk1_magnifikat;
				_velk1_prosby;
				_velk1_modlitba;

				/* 2006-01-27: pridanÈ posv. ËÌtania a modlitba cez deÚ */
				modlitba = MODL_POSV_CITANIE;
				_set_zalmy_nanebovstupenie(modlitba);
				modlitba = MODL_PREDPOLUDNIM;
				_set_zalmy_nanebovstupenie(modlitba);
				modlitba = MODL_NAPOLUDNIE;
				_set_zalmy_nanebovstupenie(modlitba);
				modlitba = MODL_POPOLUDNI;
				_set_zalmy_nanebovstupenie(modlitba);

				modlitba = MODL_PRVE_VESPERY;
				_velk1_hymnus;
				_velk1_kcitanie;
				_velk1_kresponz;
				_velk1_magnifikat;
				_velk1_prosby;
				_velk1_modlitba;
				_velk1_ne_antifony;
				modlitba = MODL_RANNE_CHVALY;
				_velk1_ne_antifony;
				modlitba = MODL_VESPERY;
				_velk1_ne_antifony;

				/* 2006-02-09: nasp‰ù pre posv. ËÌtanie a modlitbu cez deÚ */
				den = DEN_STVRTOK;
				modlitba = MODL_POSV_CITANIE;
				_velk1_hymnus;
				_velk1_ne_antifony;
				_velk1_citanie1;
				_velk1_citanie2;
				_velk1_kresponz;
				_velk1_modlitba;

				modlitba = MODL_PREDPOLUDNIM;
				_velk1_hymnus;
				_velk1_mcd_antifony;
				_velk1_kresponz;
				_velk1_kcitanie;
				_velk1_modlitba;
				modlitba = MODL_NAPOLUDNIE;
				_velk1_hymnus;
				_velk1_mcd_antifony;
				_velk1_kresponz;
				_velk1_kcitanie;
				_velk1_modlitba;
				modlitba = MODL_POPOLUDNI;
				_velk1_hymnus;
				_velk1_mcd_antifony;
				_velk1_kresponz;
				_velk1_kcitanie;
				_velk1_modlitba;

			}/* je nanebovst˙penie */
			else{
				
				/* invitatÛrium; 2007-11-14 */
				modlitba = MODL_INVITATORIUM;
				_obd_invitat;

				/* ranne chvaly */
				modlitba = MODL_RANNE_CHVALY;
				_velk1_hymnus;
				_velk1_kcitanie;
				_velk1_kresponz;
				_velk1_benediktus;
				_velk1_prosby;
				_velk1_modlitba;

				/* vespery */
				modlitba = MODL_VESPERY;
				_velk1_hymnus;
				_velk1_kcitanie;
				_velk1_kresponz;
				_velk1_magnifikat;
				_velk1_prosby;
				_velk1_modlitba;

				/* 2006-01-27: modlitba cez deÚ a posv‰tnÈ ËÌtania */
				modlitba = MODL_POSV_CITANIE;
				_velk1_hymnus;
				_velk1_citanie1;
				_velk1_citanie2;
				_velk1_kresponz;
				_velk1_modlitba;

				modlitba = MODL_PREDPOLUDNIM;
				_velk1_hymnus;
				_velk1_mcd_antifony;
				_velk1_kresponz;
				_velk1_kcitanie;
				_velk1_modlitba;
				modlitba = MODL_NAPOLUDNIE;
				_velk1_hymnus;
				_velk1_mcd_antifony;
				_velk1_kresponz;
				_velk1_kcitanie;
				_velk1_modlitba;
				modlitba = MODL_POPOLUDNI;
				_velk1_hymnus;
				_velk1_mcd_antifony;
				_velk1_kresponz;
				_velk1_kcitanie;
				_velk1_modlitba;

				if(den == DEN_NEDELA){
					/* 2007-12-06: pridanÈ kompletÛrium po prv˝ch veöper·ch */
					modlitba = MODL_PRVE_KOMPLETORIUM;
					set_hymnus_kompletorium_obd(den, tyzzal, modlitba, litobd); /* 2008-04-21: doplnenÈ */
					set_kresponz_kompletorium_obd(den, tyzzal, modlitba, litobd);
					set_antifony_kompletorium_obd(den, tyzzal, modlitba, litobd);
					/* prvÈ veöpery */
					modlitba = MODL_PRVE_VESPERY;
					_velk1_hymnus;
					_velk1_kcitanie;
					_velk1_kresponz;
					_velk1_magnifikat;
					_velk1_prosby;
					_velk1_modlitba;
					_velk1_ne_antifony;
					/* antifÛny pre rannÈ chv·ly */
					modlitba = MODL_RANNE_CHVALY;
					_velk1_ne_antifony;
					/* antifÛny pre veöpery */
					modlitba = MODL_VESPERY;
					_velk1_ne_antifony;
					/* 2006-02-09: doplnenÈ posv‰tnÈ ËÌtanie */
					modlitba = MODL_POSV_CITANIE;
					_set_antifony_velk_pc(den, tyzden, modlitba);
					/* toto sa musÌ urobiù nakoniec, lebo sa tam menÌ s˙bor _file_pc */

				}/* nedela */
			}/* nie je nanebovst˙penie */
			break;
/* switch(litobd), case OBD_VELKONOCNE_I -- end ----------------------------------------------- */

/* switch(litobd), case OBD_VELKONOCNE_II -- begin -------------------------------------------- */
		case OBD_VELKONOCNE_II:/* po nanebovstupeni pana */
			Log("OBD_VELKONOCNE_II\n");
			/* 10/03/2000A.D. */
/* 2006-02-11: doplnenÈ posv‰tnÈ ËÌtanie */
#define _velk2_hymnus {\
	sprintf(_anchor, "%s_%c%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){\
		_set_hymnus(modlitba, _file_pc, _anchor);\
		set_LOG_litobd_pc;\
	}\
	else{\
		_set_hymnus(modlitba, _file, _anchor);\
		set_LOG_litobd;\
	}\
}

/* citania ako v OBD_VELKONOCNE_I; 7. tyzden ma na vespery vlastne citanie 
 * 2006-02-11: oprava
 */
#define _velk2_kcitanie {\
	Log("\n\n _velk2_kcitanie \n\n");\
	if(((den == DEN_NEDELA) || (modlitba == MODL_RANNE_CHVALY) || (tyzden == 6))\
		/* 2006-02-11: modlitba cez deÚ */\
		|| (modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[OBD_VELKONOCNE_I], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE);\
		_set_kcitanie(modlitba, nazov_obd_htm[OBD_VELKONOCNE_I], _anchor);\
	}\
	else /* if((modlitba == MODL_VESPERY) && (tyzden == 7)) alebo posv. ËÌtanie mimo nedele */{\
		sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), nazov_DN_asci[den], ANCHOR_KCITANIE);\
		_set_kcitanie(modlitba, _file, _anchor);\
	}\
	set_LOG_litobd;\
}

#define _velk2_prosby {\
	sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[OBD_VELKONOCNE_I], pismenko_modlitby(modlitba), ANCHOR_PROSBY, t, nazov_DN_asci[den]);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk2_benediktus {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzden, nazov_DN_asci[den]);\
	}\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk2_magnifikat {\
	if(den == DEN_NEDELA){\
		sprintf(_anchor, "%s_%c%s%d%s%c", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den], _global_den.litrok);\
	}\
	else{\
		sprintf(_anchor, "%s_%c%s%d%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, tyzden, nazov_DN_asci[den]);\
	}\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk2_modlitba {\
	sprintf(_anchor, "%s_%s%d%s", nazov_OBD[litobd], ANCHOR_MODLITBA, tyzden, nazov_DN_asci[den]);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _velk2_ne_antifony {\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
	sprintf(_anchor, "%s_%d%s%c%s", nazov_OBD[litobd], tyzden, nazov_DN_asci[den], pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
/* zoslanie ducha sv. */
/* 2006-02-11: opravenÈ: prvÈ veöpery maj˙ in˙ modlitbu ako ostatnÈ hodinky;
 * in˙ modlitbu m· aj modlitba cez deÚ */
#define _zds_modlitba {\
	c = pismenko_modlitby(modlitba);\
	if((modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI)){\
		c = pismenko_modlitby(MODL_NAPOLUDNIE);\
	}\
	if((modlitba == MODL_PRVE_VESPERY) || (modlitba == MODL_PREDPOLUDNIM) || (modlitba == MODL_NAPOLUDNIE) || (modlitba == MODL_POPOLUDNI))\
		sprintf(_anchor, "%s_%c%s", ANCHOR_ZOSLANIE_DUCHA_SV, c, ANCHOR_MODLITBA);\
	else\
		sprintf(_anchor, "%s_%s", ANCHOR_ZOSLANIE_DUCHA_SV, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

		/* 2006-01-24: tu v skutoËnosti zaËÌna VEºKONO»N… OBDOBIE II. */

			t = tyzden MOD 2;

			/* 2007-12-06: kompletÛrium vo veækonoËnom obdobÌ */
			modlitba = MODL_KOMPLETORIUM;
			set_hymnus_kompletorium_obd(den, tyzzal, modlitba, litobd);
			set_kresponz_kompletorium_obd(den, tyzzal, modlitba, litobd);
			set_antifony_kompletorium_obd(den, tyzzal, modlitba, litobd);

			/* invitatÛrium; 2007-11-14 */
			modlitba = MODL_INVITATORIUM;
			_obd_invitat;

			/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_velk2_hymnus;
			_velk2_kcitanie;
			_velk1_kresponz;
			_velk2_benediktus;
			_velk2_prosby;
			_velk2_modlitba;

			/* vespery */
			modlitba = MODL_VESPERY;
			_velk2_hymnus;
			_velk2_kcitanie;
			_velk1_kresponz;
			_velk2_magnifikat;
			_velk2_prosby;
			_velk2_modlitba;

			/* 2006-02-09: modlitba cez deÚ a posv‰tnÈ ËÌtania */
			modlitba = MODL_POSV_CITANIE;
			_velk2_hymnus;
			_velk1_citanie1;
			_velk1_citanie2;
			_velk1_kresponz;
			_velk2_modlitba;

			modlitba = MODL_PREDPOLUDNIM;
			_velk1_hymnus;
			_velk1_mcd_antifony;
			_velk1_kresponz;
			_velk2_kcitanie;
			_velk2_modlitba;
			modlitba = MODL_NAPOLUDNIE;
			_velk1_hymnus;
			_velk1_mcd_antifony;
			_velk1_kresponz;
			_velk2_kcitanie;
			_velk2_modlitba;
			modlitba = MODL_POPOLUDNI;
			_velk1_hymnus;
			_velk1_mcd_antifony;
			_velk1_kresponz;
			_velk2_kcitanie;
			_velk2_modlitba;

			if(den == DEN_NEDELA){
				if(_global_den.denvr == _global_r._ZOSLANIE_DUCHA_SV.denvr){

					/* 2007-12-06: pridanÈ kompletÛrium po prv˝ch veöper·ch */
					modlitba = MODL_PRVE_KOMPLETORIUM;
					set_hymnus_kompletorium_obd(den, tyzzal, modlitba, litobd); /* 2008-04-21: doplnenÈ */
					set_kresponz_kompletorium_obd(den, tyzzal, modlitba, litobd);
					set_antifony_kompletorium_obd(den, tyzzal, modlitba, litobd);

					/* zoslanie ducha sv.; 10/03/2000A.D. */
					mystrcpy(_file, FILE_ZOSLANIE_DUCHA_SV, MAX_STR_AF_FILE);
					mystrcpy(_file_pc, FILE_ZOSLANIE_DUCHA_SV, MAX_STR_AF_FILE);
					mystrcpy(_anchor, ANCHOR_ZOSLANIE_DUCHA_SV, MAX_STR_AF_ANCHOR);
					mystrcpy(_anchor_vlastne_slavenie, ANCHOR_ZOSLANIE_DUCHA_SV, MAX_STR_AF_ANCHOR); /* 2007-11-14: pridanÈ */
					Log("  ide o zoslanie Ducha Sv.: _file = `%s', _anchor = %s...\n", _file, _anchor);

					/* prvÈ veöpery */
					modlitba = MODL_PRVE_VESPERY;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
					_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
					_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
					_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
					_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
					_zds_modlitba;
					_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

					/* invitatÛrium; 2007-11-14 */
					modlitba = MODL_INVITATORIUM;
					_vlastne_slavenie_invitat(_anchor_vlastne_slavenie);

					modlitba = MODL_RANNE_CHVALY;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
					_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
					_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
					_vlastne_slavenie_benediktus(_anchor_vlastne_slavenie);
					_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
					_zds_modlitba;
					_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

					modlitba = MODL_VESPERY;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
					_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
					_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
					_vlastne_slavenie_magnifikat(_anchor_vlastne_slavenie);
					_vlastne_slavenie_prosby(_anchor_vlastne_slavenie);
					_zds_modlitba;
					_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);

					/* 2006-01-27: pridanÈ posv. ËÌtania a modlitba cez deÚ, len ûalmy
					 * 2006-02-11: dokonËenÈ posv‰tnÈ ËÌtania a modlitba cez deÚ
					 */
					modlitba = MODL_POSV_CITANIE;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
					_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
					_vlastne_slavenie_ine_citanie1(_anchor_vlastne_slavenie);
					_vlastne_slavenie_ine_citanie2(_anchor_vlastne_slavenie);
					_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
					_zds_modlitba;

					modlitba = MODL_PREDPOLUDNIM;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
					_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
					_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
					_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
					_zds_modlitba;
					modlitba = MODL_NAPOLUDNIE;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
					_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
					_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
					_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
					_zds_modlitba;
					modlitba = MODL_POPOLUDNI;
					_set_zalmy_zoslanie_ducha_sv(modlitba);
					_vlastne_slavenie_ne_antifony(_anchor_vlastne_slavenie);
					_vlastne_slavenie_hymnus(_anchor_vlastne_slavenie);
					_vlastne_slavenie_kresponz(_anchor_vlastne_slavenie);
					_vlastne_slavenie_kcitanie(_anchor_vlastne_slavenie);
					_zds_modlitba;

				}/* nie zoslanie ducha sv. */
				else{
					/* 2007-12-06: pridanÈ kompletÛrium po prv˝ch veöper·ch */
					modlitba = MODL_PRVE_KOMPLETORIUM;
					set_hymnus_kompletorium_obd(den, tyzzal, modlitba, litobd); /* 2008-04-21: doplnenÈ */
					set_kresponz_kompletorium_obd(den, tyzzal, modlitba, litobd);
					set_antifony_kompletorium_obd(den, tyzzal, modlitba, litobd);
					/* prvÈ veöpery */
					modlitba = MODL_PRVE_VESPERY;
					_velk2_hymnus;
					_velk2_kcitanie;
					_velk1_kresponz;
					_velk2_magnifikat;
					_velk2_prosby;
					_velk2_modlitba;
					_velk2_ne_antifony;
					/* antifÛny pre rannÈ chv·ly */
					modlitba = MODL_RANNE_CHVALY;
					_velk2_ne_antifony;
					/* antifÛny pre veöpery */
					modlitba = MODL_VESPERY;
					_velk2_ne_antifony;
					/* 2006-02-09: doplnenÈ posv‰tnÈ ËÌtanie */
					modlitba = MODL_POSV_CITANIE;
					_set_antifony_velk_pc(den, tyzden, modlitba);
					/* toto sa musÌ urobiù nakoniec, lebo sa tam menÌ s˙bor _file_pc */

				}/* nie je zoslanie ds */
			}/* nedela */
			break;
/* switch(litobd), case OBD_VELKONOCNE_II -- end ---------------------------------------------- */

/* switch(litobd), case OBD_VELKONOCNA_OKTAVA -- begin ---------------------------------------- */
		case OBD_VELKONOCNA_OKTAVA:/* velkonocna nedela -- 2. velk. ne */
			Log("OBD_VELKONOCNA_OKTAVA\n");
			/* velkonocna oktava: 09/03/2000A.D.
			 *    - hymnus, antifony 1 -- 3, zalmy a chvalospev su z velkonocnej nedele;
			 *    - responzorium, 'Toto je den...' ako na velkonocnu nedelu;
			 *    - citanie,  prosby: z velkonocneho obdobia I,
			 *    - ant. na benediktus/magnifikat a modlitba: vlastne;
			 */
#define _vnokt_benediktus {\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, nazov_DN_asci[den]);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vnokt_magnifikat {\
	sprintf(_anchor, "%s_%c%s%s", nazov_OBD[litobd], pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, nazov_DN_asci[den]);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
#define _vnokt_modlitba {\
	sprintf(_anchor, "%s_%s%s", nazov_OBD[litobd], ANCHOR_MODLITBA, nazov_DN_asci[den]);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}

		/* 2006-01-24: tu v skutoËnosti zaËÌna VEºKONO»N¡ OKT¡VA */

			t = tyzden MOD 2;

			/* 2007-12-06: kompletÛrium vo veækonoËnej okt·ve je z nedele po prv˝ch resp. druh˝ch veöper·ch 
			 * 2008-05-08: d·vame natvrdo kompletÛrium po druh˝ch nedeæn˝ch veöper·ch; bolo by to komplikovanÈ po dneön˝ch zmen·ch...
			 */
			modlitba = MODL_KOMPLETORIUM;
			_set_kompletorium_nedela(modlitba);
			set_hymnus_kompletorium_obd(den, tyzzal, modlitba, litobd);
			set_kresponz_kompletorium_obd(den, tyzzal, modlitba, litobd);
			set_antifony_kompletorium_obd(DEN_NEDELA, tyzzal, modlitba, litobd); /* keÔûe sa berie nedeænÈ kompletÛrium; beztak je to pre kaûd˝ deÚ Aleluja, Aleluja, Aleluja */

			/* teda najprv nastavime vlastne ant. na benediktus/magnifikat a modlitbu */
			/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_vnokt_benediktus;
			_vnokt_modlitba;
		
			/* invitatÛrium; 2007-11-14 */
			modlitba = MODL_INVITATORIUM;
			_obd_invitat;

			/* vespery */
			modlitba = MODL_VESPERY;
			_vnokt_magnifikat;
			_vnokt_modlitba;
		
			/* teraz nastavime zalmy z velkonocnej nedele */
			modlitba = MODL_RANNE_CHVALY;
			_set_zalmy_velkonocna_nedela(modlitba);
			modlitba = MODL_VESPERY;
			_set_zalmy_velkonocna_nedela(modlitba);
		
			/* a veci pre prve vespery */
			if(den == DEN_NEDELA){ /* v skutoËnosti platÌ aj: (_global_den.denvr == VN2) */
				/* 2007-12-06: pridanÈ kompletÛrium po prv˝ch veöper·ch */
				modlitba = MODL_PRVE_KOMPLETORIUM;
				set_hymnus_kompletorium_obd(den, tyzzal, modlitba, litobd);
				set_kresponz_kompletorium_obd(den, tyzzal, modlitba, litobd);
				set_antifony_kompletorium_obd(den, tyzzal, modlitba, litobd);
				/* prvÈ veöpery */
				modlitba = MODL_PRVE_VESPERY;
				_vnokt_magnifikat;
				_vnokt_modlitba;
				_set_zalmy_velkonocna_nedela(modlitba);
			}/* nedela */

			/* 2006-01-27: ûalmy pre modlitbu cez deÚ a posv‰tnÈ ËÌtania (pË-antifÛny) */
			modlitba = MODL_POSV_CITANIE;
			_set_zalmy_velk_oktava(den, modlitba);
			_vnokt_modlitba;
			_velk1_ne_antifony;
			_velk1_kresponz;
			_velk1_citanie1;
			_velk1_citanie2;

			modlitba = MODL_PREDPOLUDNIM;
			_set_zalmy_velk_oktava(den, modlitba);
			_vnokt_modlitba;
			modlitba = MODL_NAPOLUDNIE;
			_set_zalmy_velk_oktava(den, modlitba);
			_vnokt_modlitba;
			modlitba = MODL_POPOLUDNI;
			_set_zalmy_velk_oktava(den, modlitba);
			_vnokt_modlitba;

			/* dalej nastavime citanie a prosby z velkonocneho obd. I */
			mystrcpy(_file, nazov_obd_htm[OBD_VELKONOCNE_I], MAX_STR_AF_FILE); /* aby bolo z velkonocneho obd. I */
			/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_velk1_kcitanie;
			_velk1_prosby;
			/* vespery */
			modlitba = MODL_VESPERY;
			_velk1_kcitanie;
			_velk1_prosby;
			/* a veci pre prve vespery */
			if(den == DEN_NEDELA){
				modlitba = MODL_PRVE_VESPERY;
				_velk1_kcitanie;
				_velk1_prosby;
			}/* nedela */

			/* 2006-01-27: kr·tke ËÌtanie pre modlitbu cez deÚ */
			modlitba = MODL_PREDPOLUDNIM;
			_velk1_kcitanie;
			modlitba = MODL_NAPOLUDNIE;
			_velk1_kcitanie;
			modlitba = MODL_POPOLUDNI;
			_velk1_kcitanie;

			/* napokon nastavime hymnus, antifony a kratke resp. z velkonocnej nedele */
			mystrcpy(_file, nazov_obd_htm[OBD_VELKONOCNE_TROJDNIE], MAX_STR_AF_FILE); /* aby bolo z velkonocnej nedele */
			mystrcpy(_file_pc, nazov_obd_htm_pc[OBD_VELKONOCNE_TROJDNIE], MAX_STR_AF_FILE); /* aby bolo z velkonocnej nedele */
			den = DEN_NEDELA;
			/* ranne chvaly */
			modlitba = MODL_RANNE_CHVALY;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kresponz;
			/* vespery */
			modlitba = MODL_VESPERY;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kresponz;
			/* 2006-01-27: modlitba cez deÚ a posv‰tnÈ ËÌtania */
			modlitba = MODL_POSV_CITANIE;
			_vtroj_hymnus;
			modlitba = MODL_PREDPOLUDNIM;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kresponz;
			modlitba = MODL_NAPOLUDNIE;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kresponz;
			modlitba = MODL_POPOLUDNI;
			_vtroj_hymnus;
			_vtroj_antifony;
			_vtroj_kresponz;
			/* a veci pre prve vespery */
			if(den == DEN_NEDELA){
				modlitba = MODL_PRVE_VESPERY;
				_vtroj_hymnus;
				_vtroj_antifony;
				_vtroj_kresponz;
			}/* nedela */

			break;
/* switch(litobd), case OBD_VELKONOCNA_OKTAVA -- end ------------------------------------------ */

	}/* switch(litobd) */
	Log("Koniec veækÈho switch()-u podæa liturgick˝ch obdobÌ.\n");
	LOG_ciara_sv;
	/* koniec velkeho switchu, podla ktoreho sa priradia zakladne udaje */

	Log("_global_den (nastavene v dbzaltar.cpp::liturgicke_obdobie() po velkom switchi, pred druhym spustanim sviatky_svatych()):\n");
#ifdef DETAIL_LOG_GLOBAL_DEN
	Log(_global_den);
#endif
	/* -------------------------------------------------------------------- */
	/* nasledujuca cast berie do uvahy, kedy sa ma `robit' svaty */
	/* je to cast prevzata z dnes.cpp::init_global_string(); */
	_struct_dm _local_den;
	_INIT_DM(_local_den); /* 2003-08-11 pridane */

	short int obyc = NIE;
	/* najprv priradime do _local_den to, co tam ma byt */
	if(poradie_svateho > 0){
		/* sviatky (spomienky, ls) svatych */
		switch(poradie_svateho){
			case 4:
				/* do _local_den priradim slavenie pm v sobotu v dalsom */
				_local_den = _global_pm_sobota;
				/* ale predsalen aspon _local_den = _global_pm_sobota; urobim tu; 04/07/2000A.D. */
				break; /* case 4: */
			case 1:
				/* do _local_den priradim dane slavenie */
				_local_den = _global_svaty1;
				Log("spustam druhykrat sviatky_svatych(), tentokrat pre %d. svateho\n", poradie_svateho);
				sviatky_svatych(_local_den.den, _local_den.mesiac, poradie_svateho, 2);
				break; /* case 1: */
			case 2:
				if(_global_pocet_svatych > 1){
					/* do _local_den priradim dane slavenie */
					_local_den = _global_svaty2;
					Log("spustam druhykrat sviatky_svatych(), tentokrat pre %d. svateho\n", poradie_svateho);
					sviatky_svatych(_local_den.den, _local_den.mesiac, poradie_svateho, 2);
				}
				else{
					/* sice chce svateho c. 2, ale mam len jedneho */
					Log("-- Error: _global_svaty2 not assigned\n");
					Export("%s\n", "Error: _global_svaty2 not assigned");
					ALERT;
				}
				break; /* case 2: */
			case 3:
				if(_global_pocet_svatych > 2){
					/* teraz do _local_den priradim dane slavenie */
					_local_den = _global_svaty3;
					Log("spustam druhykrat sviatky_svatych(), tentokrat pre %d. svateho\n", poradie_svateho);
					sviatky_svatych(_local_den.den, _local_den.mesiac, poradie_svateho, 2);
				}
				else{
					/* sice chce svateho c. 3, ale nemam troch */
					Log("-- Error: _global_svaty3 not assigned\n");
					Export("%s\n", "Error: _global_svaty3 not assigned");
					ALERT;
				}
				break; /* case 3: */
			case 5:
				Log("-- Error: poradie_svateho == 5\n");
				Export("Error: poradie_svateho == 5\n");
				ALERT;
				break;
			case 0:
				/* je smiesne, ze case 0 tu vobec je: ved toto je mrtvy kus kodu! 04/07/2000A.D. */
				/* bezny den */
				if(_global_svaty1.smer >= 12){
					/* ak je to iba lubovolna spomienka, tak vsedny den */
					obyc = ANO;
					_local_den = _global_den;
				}
				else{
					/* sice chce obycajny den, ale nemoze byt */
					Log("-- Error: _global_den not assigned\n");
					Export("%s\n", "Error: _global_den not assigned");
					ALERT;
				}
				break; /* case 0: */
		}/* switch(poradie_svateho) */
	}
	else if((_global_den.denvt == DEN_NEDELA) ||
		(_global_den.prik == PRIKAZANY_SVIATOK)){
		/* _local_den ostava _global_den */
		_local_den = _global_den;
	}
	else if((poradie_svateho > 0) && (_global_pocet_svatych > 0)){
	}/* if(_global_pocet_svatych > 0) */
	else{
		/* obycajny den */
		obyc = ANO;
		_local_den = _global_den;
	}
	/* este spomienka panny marie v sobotu, cl. 15 */
	/* najprv sa spytame tej soboty, ci nahodou nie je 
	   spomienka neposkvrneneho srdca panny marie;
	   ak je, tak uprednostnime tuto.
	   pridane 04/07/2000A.D. */
	/* 2006-02-02: pridanÈ posv. ËÌtania a upravenÈ; 
	 * keÔûe smer == 11 pouûÌvame pre lok·lne povinnÈ spomienky, 
	 * upravili sme kontrolu z 12 na 11
	 */
	if(_global_den.denvr == (_global_r._ZOSLANIE_DUCHA_SV.denvr + 20)){
		/* pri spusteni liturgicke_obdobie(); spomienka neposkvrneneho srdca panny marie */
		Log("/* pri spusteni liturgicke_obdobie(); spomienka neposkvrneneho srdca panny marie */\n");
		Log("spustam druhykrat sviatky_svatych(), tentokrat pre %d. svateho\n", poradie_svateho);
		_local_den = _global_den;
		sviatky_svatych(_local_den.den, _local_den.mesiac, poradie_svateho, 2);
	}
	if((_global_den.litobd == OBD_CEZ_ROK) &&
		(_global_den.denvt == DEN_SOBOTA) &&
		((_global_den.denvr != (_global_r._ZOSLANIE_DUCHA_SV.denvr + 20))) && /* pridane 04/07/2000A.D. */
		(
			((_global_den.smer >= 11) && (_global_pocet_svatych == 0)) ||
			((_global_svaty1.smer >= 11) && (_global_pocet_svatych > 0))) &&
		(poradie_svateho == 4)){
		/* teraz do _global_den priradim dane slavenie */
		_local_den = _global_pm_sobota;
		mystrcpy(_file, FILE_SPOM_PM_SOBOTA, MAX_STR_AF_FILE);

		/* rannÈ chv·ly */

		modlitba = MODL_RANNE_CHVALY;
		/* hymnus */
		/* su tri hymny, preto ich dame podla tyzzal MOD 3 (0, 1, 2) */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_HYMNUS, tyzzal MOD 3);
		_set_hymnus(modlitba, _file, _anchor);
		set_LOG_litobd;
		/* kratke citanie */
		/* su tri, preto ich dame podla tyzzal MOD 3 (0, 1, 2) */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_KCITANIE, tyzzal MOD 3);
		_set_kcitanie(modlitba, _file, _anchor);
		set_LOG_litobd;
		/* kratke responzorium  */
		/* su tri, preto ich dame podla tyzzal MOD 3 (0, 1, 2) */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, tyzzal MOD 3);
		_set_kresponz(modlitba, _file, _anchor);
		set_LOG_litobd;
		/* benediktus */
		/* je ich 6, takze tyzzal MOD 6 + 1 (1 -- 6) */
		/* preto "+ 1", aby sme dodrzali povodne cislovanie */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, tyzzal MOD 6);
		_set_benediktus(modlitba, _file, _anchor);
		set_LOG_litobd;
		/* prosby */
		/* su 2, takze tyzzal MOD 2 (0, 1) */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_PROSBY, tyzzal MOD 2);
		_set_prosby(modlitba, _file, _anchor);
		set_LOG_litobd;
		/* modlitba */
		/* je ich 6, takze tyzzal MOD 6 + 1 (1 -- 6) */
		/* preto "+ 1", aby sme dodrzali povodne cislovanie */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_MODLITBA, tyzzal MOD 6);
		_set_modlitba(modlitba, _file, _anchor);
		set_LOG_litobd;

		/* 2006-02-02: pridanÈ posv‰tnÈ ËÌtanie */

		modlitba = MODL_POSV_CITANIE;
		/* hymnus */
		/* su tri hymny, preto ich dame podla tyzzal MOD 3 (0, 1, 2) */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_HYMNUS, tyzzal MOD 3);
		_set_hymnus(modlitba, _file, _anchor);
		set_LOG_litobd;

		/* antifÛny, ûalmy, verö a prvÈ ËÌtanie s responzÛriom sa berie z prÌsluönej soboty */

		/* druhÈ ËÌtanie */
		/* s˙ ötyri hymny, preto ich d·me podæa tyzzal MOD 4 (0, 1, 2, 3) */
		sprintf(_anchor, "%s%c_%s%d", SPOM_PM_SOBOTA, pismenko_modlitby(modlitba), ANCHOR_CITANIE2, tyzzal MOD 4);
		_set_citanie2(modlitba, _file, _anchor);
		set_LOG_litobd;

	}

	_global_den = _local_den;
#ifdef DETAIL_LOG_GLOBAL_DEN
	Log("_global_den (nastavene v dbzaltar.cpp::liturgicke_obdobie() na konci):\n");
	Log(_global_den);
#endif
	/* koniec casti podla dnes.cpp::init_global_string(); */
	Log("-- liturgicke_obdobie(%d, %d, %d, %d) -- koniec\n",
		litobd, tyzden, den, tyzzal);
}/* liturgicke_obdobie(); */

/* --------------------------------------------------------------------- */

/* obsahuje udaje o spolocnej casti, MODL_SPOL_CAST...
 * kedze ju pouzivame len pri druhom volani sviatky_svatych(),
 * mame zarucene, ze _global_den obsahuje dobre udaje -- toho spravneho
 * svateho :-)
 */
short int modlitba;

/* nasleduje funkcia sviatky_svatych(); ktora bola povodne sama vo fajli
 * dbsvaty.c */

/* sviatky_svatych();
 *
 * nastavi do _global_svaty1 nasledovne udaje:
 *
 *	    typslav;    // typ slavenia (1--5): SLAV_...
 *     smer;       // poradove cislo z c.59 Vseobecnych smernic
 *                 // o liturgii hodin a kalendari
 *	    meno[MAX_MENO]; // nazov prip. sviatku
 *
 * az na konci nastavi .den a .mesiac, ostatne sa nastavia inde !!!
 *
 * 09/02/2000A.D.: tato funkcia default dostava vstup poradie_svaty == 0;
 * to sa rovna 'staremu pouzitiu'; v pripade, ze poradie_svaty != 0,
 * znamena to, ze chceme uz pri generovani modlitby nastavit konkretne
 * pre danu modlitbu (svateho) atributy.
 *
 */

/* 2007-09-27: kvÙli debugovaniu pod Ruby zruöenÈ koment·re vo v˝pisoch*/
/* 2003-06-30 pre lahsie debugovanie obohateny vypis */
//#define set_LOG_svsv Log("   set(svsv): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file, _anchor)
#define set_LOG_svsv Log("   set(svsv): %s: s˙bor `%s', kotva `%s'\n", nazov_modlitby(modlitba), _file, _anchor)

/* ked dostane strukturu sc, vrati
 * MODL_SPOL_CAST_DUCH_PAST_... resp.
 * MODL_SPOL_CAST_PANNA
 * alebo MODL_SPOL_CAST_REHOLNIK -- vtedy priradim MODL_SPOL_CAST_SV_MUZ; 03/03/2000A.D.
 * mozno je to diskriminujuce, ale napr. kvoli sv. Efremovi (9. juna), 
 * ak nematchuje, vrati MODL_SPOL_CAST_SV_MUZ; 03/03/2000A.D.
 * (predtym som vracal MODL_SPOL_CAST_NEURCENA)
 */
#define otazka_sedi_to {\
	if((a == MODL_SPOL_CAST_DUCH_PAST_KNAZ) || (a == MODL_SPOL_CAST_DUCH_PAST_BISKUP) || (a == MODL_SPOL_CAST_DUCH_PAST_PAPEZ) || (a == MODL_SPOL_CAST_PANNA)){\
		Log("matches (duchovny pastier || panna). returning %s (%d)\n", nazov_spolc(a), a);\
		return a;\
	}\
	else if((a == MODL_SPOL_CAST_SV_MUZ_REHOLNIK) || (a == MODL_SPOL_CAST_SV_MUZ)){\
		Log("matches (reholnik || muz). returning %s (%d)\n", nazov_spolc(MODL_SPOL_CAST_SV_MUZ), MODL_SPOL_CAST_SV_MUZ);\
		return MODL_SPOL_CAST_SV_MUZ;\
	}\
}	
short int _spol_cast_vyber_dp_pn(_struct_sc sc){
	Log("_spol_cast_vyber_dp_pn() -- skusam, co sedi...\n");
	short int a;
	a = sc.a1;
	Log("  sc.a1 == %s (%d)\n", nazov_spolc(a), a);
	otazka_sedi_to;
	a = sc.a2;
	Log("  sc.a2 == %s (%d)\n", nazov_spolc(sc.a2), sc.a2);
	otazka_sedi_to;
	a = sc.a3;
	Log("  sc.a3 == %s (%d)\n", nazov_spolc(sc.a3), sc.a3);
	otazka_sedi_to;
	Log("not matches. returning %s (%d)\n", nazov_spolc(MODL_SPOL_CAST_SV_MUZ), MODL_SPOL_CAST_SV_MUZ);
	return MODL_SPOL_CAST_SV_MUZ;
}/* _spol_cast_vyber_dp_pn(); */

#define otazka_sedi_to2 if(a == MODL_SPOL_CAST_PANNA){Log("matches. returning ANO\n");return ANO;}
short int _spol_cast_je_panna(_struct_sc sc){
	Log("_spol_cast_je_panna() -- skusam, ci v sc je panna...\n");
	short int a;
	a = sc.a1;
	Log("  sc.a1 == %s (%d)\n", nazov_spolc(sc.a1), sc.a1);
	otazka_sedi_to2;
	a = sc.a2;
	Log("  sc.a2 == %s (%d)\n", nazov_spolc(sc.a2), sc.a2);
	otazka_sedi_to2;
	a = sc.a3;
	Log("  sc.a3 == %s (%d)\n", nazov_spolc(sc.a3), sc.a3);
	otazka_sedi_to2;
	Log("  returning NIE\n");
	return NIE;
}/* _spol_cast_je_panna(); */

/* tu boli _set_zalmy_..., ale su inde; 14/03/2000A.D. */

/* nastavenie jednotlivych parametrov modlitby -- predpoklad je, ze premenna
 * modlitba ma spravne nastavenu konstantu MODL_... */

/* hymnus */
#define _vlastna_cast_hymnus {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	if(modlitba == MODL_POSV_CITANIE){_set_hymnus(modlitba, _file_pc, _anchor);}\
	else{_set_hymnus(modlitba, _file, _anchor);}\
	set_LOG_svsv;}
/* antifony */
/* kedysi tam pred celym blokom bolo if(_global_opt2 == MODL_ZALMY_ZO_SV) 
 * 2005-07-27: pre sviatky sv‰t˝ch posv‰tnÈ ËÌtania maj˙ antifÛny tam, kde ËÌtania
 */
#define _vlastna_cast_antifony {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){_set_antifona1(modlitba, _file_pc, _anchor);}\
	else{_set_antifona1(modlitba, _file, _anchor);}\
	set_LOG_svsv;\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
	if(modlitba == MODL_POSV_CITANIE){_set_antifona2(modlitba, _file_pc, _anchor);}\
	else{_set_antifona2(modlitba, _file, _anchor);}\
	set_LOG_svsv;\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
	if(modlitba == MODL_POSV_CITANIE){_set_antifona3(modlitba, _file_pc, _anchor);}\
	else{_set_antifona3(modlitba, _file, _anchor);}\
	set_LOG_svsv;}
/* 2007-11-13: doplnenÈ pre vlastn˙ antifÛnu pre invitatÛrium */
#define _vlastna_cast_antifona_inv {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
	if(modlitba == MODL_POSV_CITANIE){_set_antifona1(modlitba, _file_pc, _anchor);}\
	else{_set_antifona1(modlitba, _file, _anchor);}\
	set_LOG_svsv;}

/* 2007-10-02: 1., 2. a 3. antifÛna na mcd resp. posv. ËÌtanie s˙ rovnakÈ - d·me jedno pÌsmenko, aby sme ich nezobrazovali */
#define _vlastna_cast_antifony_rovnake {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	if(modlitba == MODL_POSV_CITANIE){_set_antifona1(modlitba, _file_pc, _anchor);}\
	else{_set_antifona1(modlitba, _file, _anchor);}\
	set_LOG_svsv;\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	if(modlitba == MODL_POSV_CITANIE){_set_antifona2(modlitba, _file_pc, _anchor);}\
	else{_set_antifona2(modlitba, _file, _anchor);}\
	set_LOG_svsv;\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONY);\
	if(modlitba == MODL_POSV_CITANIE){_set_antifona3(modlitba, _file_pc, _anchor);}\
	else{_set_antifona3(modlitba, _file, _anchor);}\
	set_LOG_svsv;}

/* kratke citanie */
#define _vlastna_cast_kcitanie {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KCITANIE);\
	_set_kcitanie(modlitba, _file, _anchor);\
	set_LOG_svsv;}
/* kratke responzorium */
#define _vlastna_cast_kresponz {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	if(modlitba == MODL_POSV_CITANIE){_set_kresponz(modlitba, _file_pc, _anchor);}\
	else{_set_kresponz(modlitba, _file, _anchor);}\
	set_LOG_svsv;}
/* bedediktus */
#define _vlastna_cast_benediktus {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_svsv;}
/* magnifikat */
#define _vlastna_cast_magnifikat {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_svsv;}
/* prosby */
#define _vlastna_cast_prosby {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_PROSBY);\
	_set_prosby(modlitba, _file, _anchor);\
	set_LOG_svsv;}
/* modlitba -- rovnaka rano i vecer */
#define _vlastna_cast_modlitba {\
	sprintf(_anchor, "%s%s", _anchor_head, ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_svsv;}
/* modlitba -- ina pre prve vespery ako rano i vecer dna */
#define _vlastna_cast_modlitba_prve_vesp {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_MODLITBA);\
	_set_modlitba(modlitba, _file, _anchor);\
	set_LOG_svsv;}

/* 2005-07-26: posv‰tnÈ ËÌtanie potrebuje 1. a 2. ËÌtanie */

/* 1. ËÌtanie */
#define _vlastna_cast_1citanie {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file_pc, _anchor);\
	set_LOG_svsv;\
}

/* 2. ËÌtanie */
#define _vlastna_cast_2citanie {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file_pc, _anchor);\
	set_LOG_svsv;\
}

/* full -- vsetko (hymnus, antifony, kcitanie, kresponz,
 * benediktus/magnifikat, prosby, modlitba */
#define _vlastna_cast_full(modl) {\
	_vlastna_cast_hymnus;\
	_vlastna_cast_antifony;\
	if(modl == MODL_POSV_CITANIE){_vlastna_cast_1citanie;}\
	else {_vlastna_cast_kcitanie;}\
	_vlastna_cast_kresponz;\
	if(modl == MODL_RANNE_CHVALY){_vlastna_cast_benediktus;}\
	else if((modl == MODL_VESPERY) || (modl == MODL_PRVE_VESPERY)){_vlastna_cast_magnifikat;}\
	else if(modl == MODL_POSV_CITANIE){_vlastna_cast_2citanie;}\
	_vlastna_cast_prosby;\
	_vlastna_cast_modlitba;\
}

#define _vlastna_cast_full_okrem_prosieb(modl) {\
	_vlastna_cast_hymnus;\
	_vlastna_cast_antifony;\
	if(modl == MODL_POSV_CITANIE){_vlastna_cast_1citanie;}\
	else {_vlastna_cast_kcitanie;}\
	_vlastna_cast_kresponz;\
	if(modl == MODL_RANNE_CHVALY){_vlastna_cast_benediktus;}\
	else if((modl == MODL_VESPERY) || (modl == MODL_PRVE_VESPERY)){_vlastna_cast_magnifikat;}\
	else if(modl == MODL_POSV_CITANIE){_vlastna_cast_2citanie;}\
	_vlastna_cast_modlitba;\
}
/* full -- vsetko (hymnus, antifony, kcitanie, kresponz,
 * benediktus/magnifikat, prosby, modlitba -- ina ako na rchv a vesp */
#define _vlastna_cast_antifony_ako_na_ranne_chvaly {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_RANNE_CHVALY), ANCHOR_ANTIFONA1);\
	_set_antifona1(modlitba, _file, _anchor);\
	set_LOG_svsv;\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_RANNE_CHVALY), ANCHOR_ANTIFONA2);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_svsv;\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_RANNE_CHVALY), ANCHOR_ANTIFONA3);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

/* rovnako tak pre spolocnu cast... */
/* #define _spolocna_cast_hymnus             _vlastna_cast_hymnus */
#define _spolocna_cast_kcitanie			_vlastna_cast_kcitanie
#define _spolocna_cast_benediktus		_vlastna_cast_benediktus
#define _spolocna_cast_magnifikat		_vlastna_cast_magnifikat
#define _spolocna_cast_prosby			_vlastna_cast_prosby
#define _spolocna_cast_modlitba			_vlastna_cast_modlitba
#define _spolocna_cast_modlitba_prve_vesp _vlastna_cast_modlitba_prve_vesp
/* #define _spolocna_cast_antifony		_vlastna_cast_antifony*/
/* ... az na antifony... */
#define _spolocna_cast_antifony {\
	if((_global_opt3 != MODL_SPOL_CAST_NEBRAT)){\
		Log("  antifony vlastnej casti zo sviatku...\n");\
		sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1);\
		_set_antifona1(modlitba, _file, _anchor);\
		set_LOG_svsv;\
		sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2);\
		_set_antifona2(modlitba, _file, _anchor);\
		set_LOG_svsv;\
		sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3);\
		_set_antifona3(modlitba, _file, _anchor);\
		set_LOG_svsv;\
	}\
}
/* 2007-11-14: pridanÈ pre invitatÛrium */
#define	_spolocna_cast_antifona_inv		_vlastna_cast_antifona_inv

/* 2007-11-19: pridanÈ pre invitatÛrium, ak je antifÛn viacero, napr. pre PM, ofÌcium na posviacku chr·mu a pod. */
#define _spolocna_cast_antifona_inv_viac(kolko) {\
	sprintf(_anchor, "%s%c%s%d", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1, (_global_den.den MOD kolko) + 1);\
	if(modlitba == MODL_POSV_CITANIE){_set_antifona1(modlitba, _file_pc, _anchor);}\
	else{_set_antifona1(modlitba, _file, _anchor);}\
	set_LOG_svsv;}

/* ... 2005-07-26: in· je tieû spoloËn· Ëasù pre 1. resp. 2. ËÌtanie ... */

/* 1. ËÌtanie */
#define _spolocna_cast_1citanie {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);\
	_set_citanie1(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

/* 2. ËÌtanie */
#define _spolocna_cast_2citanie {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

/* ... a spolocnu cast full 
 * 2005-07-27: upravenÈ / nahradenÈ _vlastna_cast_kresponz reùazcom _spolocna_cast_kresponz
 * kvÙli posv‰tn˝m ËÌtaniam, viÔ niûöie 
 * 2005-08-16: nahraden· "_vlastna_cast_hymnus" novou funkciou "_spolocna_cast_hymnus"
 */
#define _spolocna_cast_full(modl) {\
	_spolocna_cast_hymnus;\
	if(su_antifony_vlastne(modl)){\
		_spolocna_cast_antifony;\
	}\
	if(su_kcit_kresp_1cit_prosby_vlastne){\
		if(modl == MODL_POSV_CITANIE){\
			_spolocna_cast_1citanie;\
		}\
		else {\
			_vlastna_cast_kcitanie;\
		}\
	}\
	if(su_kcit_kresp_1cit_prosby_vlastne){\
		_spolocna_cast_kresponz;\
		_vlastna_cast_prosby;\
	}\
	if(modl == MODL_RANNE_CHVALY){\
		_vlastna_cast_benediktus;\
	}\
	else if((modl == MODL_VESPERY) || (modl == MODL_PRVE_VESPERY)){\
		_vlastna_cast_magnifikat;\
	}\
	else if(modl == MODL_POSV_CITANIE){\
		if(su_kcit_kresp_1cit_prosby_vlastne){\
			_spolocna_cast_2citanie;\
		}\
	}\
	_vlastna_cast_modlitba;\
}

/* 2005-07-27: kedysi bolo nasledovnÈ: #define _spolocna_cast_kresponz           _vlastna_cast_kresponz
 * ale potrebujeme, aby spoloËn· Ëasù mala zo spoloËnej Ëasti. preto nasledovn· definÌcia:
 * kratke responzorium */
#define _spolocna_cast_kresponz {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

/* 2005-08-08: potrebujeme individualny hymnus pre spolocnu cast - berie sa z ineho 
 * suboru ako vlastna cast
 */
#define _spolocna_cast_hymnus {\
	sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

#define _vlastna_cast_hymnus_po {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_HYMNUS, POSTNA_PRIPONA);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
#define _vlastna_cast_hymnus_ve {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_HYMNUS, VELKONOCNA_PRIPONA);\
	_set_hymnus(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
#define _spolocna_cast_benediktus_ve _vlastna_cast_benediktus_ve
#define _vlastna_cast_benediktus_ve {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, VELKONOCNA_PRIPONA);\
	_set_benediktus(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
#define _spolocna_cast_magnifikat_ve _vlastna_cast_magnifikat_ve
#define _vlastna_cast_magnifikat_ve {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, VELKONOCNA_PRIPONA);\
	_set_magnifikat(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
#define _spolocna_cast_kresponz_ve _vlastna_cast_kresponz_ve
#define _vlastna_cast_kresponz_ve {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, VELKONOCNA_PRIPONA);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
#define _vlastna_cast_kresponz_po {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, POSTNA_PRIPONA);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
#define _vlastna_cast_kresponz_cr {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, CEZROCNA_PRIPONA);\
	_set_kresponz(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

/* specialne veci pre sviatky duchovnych pastierov, jedneho mucenika... */
/* funguje to aj pre svatych muzov (jeden resp. viaceri -- podla toho, co je
 * v _anchor_pom); 29/02/2000A.D. */
void _spolocna_cast_hymnus_rozne(short int modlitba, char *_anchor_pom, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s", _anchor_pom, pismenko_modlitby(modlitba), ANCHOR_HYMNUS);
	_set_hymnus(modlitba, _file, _anchor);
	set_LOG_svsv;
}

void _spolocna_cast_benediktus_rozne(short int modlitba, char *_anchor_pom, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s", _anchor_pom, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS);
	_set_benediktus(modlitba, _file, _anchor);
	set_LOG_svsv;
}

void _spolocna_cast_magnifikat_rozne(short int modlitba, char *_anchor_pom, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s", _anchor_pom, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT);
	_set_magnifikat(modlitba, _file, _anchor);
	set_LOG_svsv;
}

void _spolocna_cast_kresponz_rozne(short int modlitba, char *_anchor_pom, char *_anchor, char *_file){
	if(su_kcit_kresp_1cit_prosby_vlastne){
		sprintf(_anchor, "%s%c%s", _anchor_pom, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);
		_set_kresponz(modlitba, _file, _anchor);
		set_LOG_svsv;
	}
}
/* 2005-08-27: kvÙli 2. ËÌtaniu pre duchovn˝ch pastierov; pouûÌvame aj pre odliönÈ ËÌtanie pre sv‰tÈ ûeny - Ëo ûili v manûelstve; 2006-08-08 */
void _spolocna_cast_2cit_rozne(short int modlitba, char *_anchor_pom, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s", _anchor_pom, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);
	_set_citanie2(modlitba, _file, _anchor);
	set_LOG_svsv;
}

/* specialne veci pre sviatky jedneho mucenika */
#define _spolocna_cast_kcit_kresp_chval_ve {\
	if(su_kcit_kresp_1cit_prosby_vlastne){\
		sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KCITANIE, VELKONOCNA_PRIPONA);\
		_set_kcitanie(modlitba, _file, _anchor);\
		set_LOG_svsv;\
		sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, VELKONOCNA_PRIPONA);\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_svsv;\
	}\
	if(modlitba == MODL_RANNE_CHVALY){\
		sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, VELKONOCNA_PRIPONA);\
		_set_benediktus(modlitba, _file, _anchor);\
		set_LOG_svsv;\
	}\
	else if((modlitba == MODL_VESPERY) || (modlitba == MODL_PRVE_VESPERY)){\
		sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, VELKONOCNA_PRIPONA);\
		_set_magnifikat(modlitba, _file, _anchor);\
		set_LOG_svsv;\
	}\
}

#define _spolocna_cast_ant1_3_po {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA1, POSTNA_PRIPONA);\
	_set_antifona1(modlitba, _file, _anchor);\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3, POSTNA_PRIPONA);\
	_set_antifona3(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}
/* specialne veci pre sviatky viacerych mucenikov */
#define _spolocna_cast_ant2_po {\
	sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA2, POSTNA_PRIPONA);\
	_set_antifona2(modlitba, _file, _anchor);\
	set_LOG_svsv;\
}

/* specialne veci pre sviatky panien */
#define _spolocna_cast_kresp_ve {\
	if(su_kcit_kresp_1cit_prosby_vlastne){\
		sprintf(_anchor, "%s%c%s%s", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, VELKONOCNA_PRIPONA);\
		_set_kresponz(modlitba, _file, _anchor);\
		set_LOG_svsv;\
	}\
}

/* ked je viac napevov, `kolko' uvadza, z kolkych je na vyber;
 * zvacsa sa vyberie napr. podla (_global_den.den MOD kolko) + 1
 * (aby bol z intervalu 1..kolko)
 * 23/02/2000A.D.
 */
void _spolocna_cast_magnifikat_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s%d", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_MAGNIFIKAT, (_global_den.den MOD kolko) + 1);
	_set_magnifikat(modlitba, _file, _anchor);
	set_LOG_svsv;
}
/* viac benediktus-ov - dorobene 01/03/2000A.D. */
void _spolocna_cast_benediktus_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s%d", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_BENEDIKTUS, (_global_den.den MOD kolko) + 1);
	_set_benediktus(modlitba, _file, _anchor);
	set_LOG_svsv;
}
/* viac prosieb -- dorobene 01/03/2000A.D., spol.casti panny marie */
void _spolocna_cast_prosby_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	if(su_kcit_kresp_1cit_prosby_vlastne){
		sprintf(_anchor, "%s%c%s%d", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_PROSBY, (_global_den.den MOD kolko) + 1);
		_set_prosby(modlitba, _file, _anchor);
		set_LOG_svsv;
	}
}
/* viac responzÛriÌ -- dorobene 29/03/2000A.D., oficium za zosnulych */
void _spolocna_cast_kresponz_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	if(su_kcit_kresp_1cit_prosby_vlastne){
		sprintf(_anchor, "%s%c%s%d", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ, (_global_den.den MOD kolko) + 1);
		_set_kresponz(modlitba, _file, _anchor);
		set_LOG_svsv;
	}
}
void _spolocna_cast_ant3_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s%d", _anchor_head, pismenko_modlitby(modlitba), ANCHOR_ANTIFONA3, (_global_den.den MOD kolko) + 1);
	_set_antifona3(modlitba, _file, _anchor);
	set_LOG_svsv;
}
/* 2005-08-05: posv‰tnÈ ËÌtania, 1. ËÌtanie 
// 2007-09-28: zapozn·mkovanÈ, lebo sa nepouûÌva
void _spolocna_cast_1cit_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	// 2007-09-28: pridanÈ
	if(su_kcit_kresp_1cit_prosby_vlastne){
		sprintf(_anchor, "%s%c%s%d",
			_anchor_head, pismenko_modlitby(modlitba), ANCHOR_CITANIE1,
			(_global_den.den MOD kolko) + 1);
		_set_citanie1(modlitba, _file, _anchor);
		set_LOG_svsv;
	}
	else{
		Log("podæa smernÌc nie je vlastnÈ ËÌtanie, nenastavujem.\n");
	}
}
*/
/* 2005-08-05: posv‰tnÈ ËÌtania, 2. ËÌtanie */
void _spolocna_cast_2cit_viac(short int kolko, char *_anchor_head, char *_anchor, char *_file){
	sprintf(_anchor, "%s%c%s%d",
		_anchor_head, pismenko_modlitby(modlitba), ANCHOR_CITANIE2,
		(_global_den.den MOD kolko) + 1);
	_set_citanie2(modlitba, _file, _anchor);
	set_LOG_svsv;
}
/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
 * - II. zv‰zok (veæk· noc),
 * - III. a IV. zv‰zok (obdobie cez rok).
 */
void _spolocna_cast_1cit_zvazok(short int modlitba, char *_anchor_pom, char *_anchor_zvazok, char *_anchor, char *_file){
	char _anchor_lokal[SMALL]; /* 2005-08-08: lok·lna premenn· */
	Log("_spolocna_cast_1cit_zvazok: zaËiatok\n");
	Log("\tmodlitba == %s\n", nazov_modlitby(modlitba));
	Log("\tanchor_pom == %s\n", _anchor_pom);
	Log("\tanchor_zvazok == %s\n", _anchor_zvazok);
	Log("\tanchor == %s\n", _anchor);
	Log("\tfile == %s\n", _file);
	/* 2007-09-28: pridanÈ */
	if(su_kcit_kresp_1cit_prosby_vlastne){
		if(!equals(_anchor_pom, STR_EMPTY)){
			sprintf(_anchor_lokal, "%s%s%s%c%s", _anchor, _anchor_pom, _anchor_zvazok, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);
		}
		else {
			sprintf(_anchor_lokal, "%s%s%c%s", _anchor, _anchor_zvazok, pismenko_modlitby(modlitba), ANCHOR_CITANIE1);
		}
		_set_citanie1(modlitba, _file, _anchor_lokal);

		/* 2007-09-27: kvÙli debugovaniu pod Ruby zruöenÈ koment·re vo v˝pisoch*/
		/* set_LOG_svsv; */
		// Log("   set(svsv): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file, _anchor_lokal);
		Log("   set(svsv): %s: `%s', kotva `%s'\n", nazov_modlitby(modlitba), _file, _anchor_lokal);
	}
	else{
		Log("podæa smernÌc nie je vlastnÈ ËÌtanie, nenastavujem.\n");
	}
	Log("_spolocna_cast_1cit_zvazok: koniec.\n");
}

/* 2005-08-27: kr·tke responzÛrium na posv‰tnÈ ËÌtanie pre vlastnÈ Ëasti je 
 * zv‰Ëöa rovnakÈ, ale pre sviatky prebl. panny m·rie je odliönÈ (porov. 1. ËÌtanie vyööie):
 * - I. zv‰zok (advent, vianoce),
 * - II. zv‰zok (pÙst), II. zv‰zok (veæk· noc), III. a IV. zv‰zok (obdobie cez rok).
 */
void _spolocna_cast_kresponz_zvazok(short int modlitba, char *_anchor_pom, char *_anchor_zvazok, char *_anchor, char *_file){
	char _anchor_lokal[SMALL]; /* 2005-08-08: lok·lna premenn· */
	Log("_spolocna_cast_kresp_zvazok: \n");
	Log("\tmodlitba == %s\n", nazov_modlitby(modlitba));
	Log("\tanchor_pom == %s\n", _anchor_pom);
	Log("\tanchor_zvazok == %s\n", _anchor_zvazok);
	Log("\tanchor == %s\n", _anchor);
	Log("\tfile == %s\n", _file);
	/* 2007-10-23 / 2007-09-28: pridanÈ */
	if(su_kcit_kresp_1cit_prosby_vlastne){
		if(!equals(_anchor_pom, STR_EMPTY)){
			sprintf(_anchor_lokal, "%s%s%s%c%s", _anchor, _anchor_pom, _anchor_zvazok, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);
		}
		else {
			sprintf(_anchor_lokal, "%s%s%c%s", _anchor, _anchor_zvazok, pismenko_modlitby(modlitba), ANCHOR_KRESPONZ);
		}
		_set_kresponz(modlitba, _file, _anchor_lokal);

		/* 2007-09-27: kvÙli debugovaniu pod Ruby zruöenÈ koment·re vo v˝pisoch*/
		/* set_LOG_svsv; */
		// Log("   set(svsv): %s: `%s', <!--{BEGIN:%s}-->\n", nazov_modlitby(modlitba), _file, _anchor_lokal);
		Log("   set(svsv): %s: `%s', kotva `%s'\n", nazov_modlitby(modlitba), _file, _anchor_lokal);
	}
	else{
		Log("podæa smernÌc nie je vlastnÈ ËÌtanie, nenastavujem.\n");
	}
	Log("_spolocna_cast_kresponz_zvazok: koniec.\n");
}

/* 2005-11-24: pridanÈ; podæa vöeobecn˝ch smernÌc, Ë. 134:

"Na sl·vnosti a sviatky, vo VeækonoËnom trojdnÌ a v dÚoch VeækonoËnej a VianoËnej okt·vy 
s˙ pre posv‰tnÈ ËÌtanie urËenÈ vlastnÈ ûalmy v s˙lade s tradÌciou; ich vhodnosù osvetæuje 
zvyËajne antifÛna. Tak je to aj pri modlitbe cez deÚ na niektorÈ sl·vnosti P·na 
a vo VeækonoËnej okt·ve. Na rannÈ chv·ly sa ber˙ ûalmy a chv·lospev z nedele prvÈho t˝ûdÚa 
v ûalt·ri. 

Na prvÈ veöpery sl·vnostÌ sa ber˙ ûalmy podæa starod·vneho zvyku zo sÈrie Laud·te. 

DruhÈ veöpery sl·vnostÌ a veöpery sviatkov maj˙ ûalmy i chv·lospev vlastnÈ. 

Na modlitbu cez deÚ sl·vnostÌ, okrem t˝ch, o ktor˝ch sa uû hovorilo, a ak nepripadn˙ na nedeæu, 
ber˙ sa ûalmy z doplnkovÈho cyklu (gradu·lne).

Na sviatky sa na modlitbu cez deÚ ber˙ ûalmy z prÌsluönÈho dÚa v t˝ûdni."
 * 2006-02-04: premenovanÈ z "su_zalmy_nedela1tyzden" na "su_zalmy_vlastne" 
 *             a pouûitÈ aj pre inÈ modlitby ako pre rannÈ chv·ly
 *             miesta v kÛde oznaËenÈ 2006-02-04_ZALMY_ZO_SVIATKU_FIX
 */

/* 2007-09-28: #define tu definovanÈ presunutÈ ˙plne na zaËiatok, nakoæko ich pouûÌvaj˙ aj _set... funkcie/definy */
void _set_spolocna_cast(short int a, _struct_sc sc){
	/* 2005-07-22: pokus o doplnenie udajov k posvatnym citaniam */

	/* anchors - nazvy kotiev pre zaltar styroch tyzdnov */
	char _anchor[SMALL];
	char _anchor_head[SMALL];
	char _anchor_pom[SMALL];
	/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
	char _anchor_zvazok[SMALL];
	/* files - nazvy suborov pre zaltar styroch tyzdnov */
	char _file[SMALL]; /* nazov fajlu, napr. _1ne.htm */
	short int b; /* pre ucitelov cirkvi, odkial sa maju brat ine casti */

	Log("_set_spolocna_cast(%s) -- begin\n", nazov_spolc(a));

	if(a != MODL_SPOL_CAST_NEBRAT){
		Log("/* nastavenie nazvu suboru, kotvy apod. (_set_spolocna_cast) */\n");
		/* nastavenie nazvu suboru, kotvy apod. */
		sprintf(_anchor_head, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_head == %s\n", _anchor_head);
		sprintf(_file, "%s", nazov_spolc_htm[a]);
		Log("  _file == %s\n", _file);
	}
	else{
		Log("   nebrat... takze nenastavujem kotvy ani nic\n");
	}

	/* spolocna cast na sviatky apostolov */
	if(a == MODL_SPOL_CAST_APOSTOL){

		Log("/* spolocna cast na sviatky apostolov */\n");

		/* invitatÛrium; 2007-11-20 */
		modlitba = MODL_INVITATORIUM;
		_spolocna_cast_antifona_inv;

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_prve_vespery_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_apostolov(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_apostolov(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_modlitba_prve_vesp;

		/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_pom, "%s", STR_EMPTY);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_apostolov(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_apostolov(modlitba);
		}
		_spolocna_cast_full(modlitba);
		/* 2005-07-22: ToDo: skontrolovaù, Ëi pre öpeci·lne obdobia nie s˙ öpeci·lne Ëasti z obdobia */

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, _anchor_pom, _anchor_zvazok, _anchor_head, _file);

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		/* 2006-01-25: PÙvodne tu bolo AND; upravenÈ kvÙli tomu, aby sa ûalmy z nedele 1. t˝ûdÚa
		 *             zobrazili aj v prÌpade, ak by podæa smernÌc nemali (nemuseli) byù,
		 *             ale pouûÌvateæ si to v detailoch vyberie.
		 *             Pritom default pre _global_opt2 sme zmenili na MODL_ZALMY_ZO_DNA.
		 *             Takto isto zmenenÈ na vöetk˝ch ostatn˝ch miestach - bez pozn·mky.
		 *             2006-01-25_ZALMY1NE_FIX
		 */
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_vlastna_cast_kresponz_ve;
		/* ranne chvaly na sviatky apostolov maju specialne hymny pre postne a velkonocne obdobie */
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			_vlastna_cast_hymnus_ve;
		}
		else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
			_vlastna_cast_hymnus_po;
		}

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_apostolov(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_apostolov(modlitba);
			}
			_spolocna_cast_full(modlitba);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_vlastna_cast_kresponz_ve;
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_vlastna_cast_hymnus_ve;
		}/* v OBD_OKTAVA_NARODENIA (sv. Jana, 27. dec) vespery su zo dna */

	}/* MODL_SPOL_CAST_APOSTOL */

	/* spolocna cast na sviatky duchovnych pastierov */
	else if((a == MODL_SPOL_CAST_DUCH_PAST_KNAZ) ||
		(a == MODL_SPOL_CAST_DUCH_PAST_BISKUP) ||
		(a == MODL_SPOL_CAST_DUCH_PAST_PAPEZ) ||
		(a == MODL_SPOL_CAST_DUCH_PAST_VIACERI)){

		Log("/* spolocna cast na sviatky duchovnych pastierov */\n");

		sprintf(_anchor_head, "%s_", ANCHOR_SPOL_CAST_DUCH_PAST);
		Log("  _anchor_head == %s\n", _anchor_head);
		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if(
			((a == MODL_SPOL_CAST_DUCH_PAST_BISKUP) || (a == MODL_SPOL_CAST_DUCH_PAST_PAPEZ))
			&& ((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
		){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* invitatÛrium; 2007-11-20 */
		modlitba = MODL_INVITATORIUM;
		_spolocna_cast_antifona_inv;

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_prve_vespery_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_duch_past(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_duch_past(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		_spolocna_cast_modlitba_prve_vesp;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_vlastna_cast_kresponz_ve;

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_duch_past(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_duch_past(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		/* 2005-07-22: ToDo: skontrolovaù, Ëi pre öpeci·lne obdobia nie s˙ öpeci·lne Ëasti z obdobia */

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, _anchor_pom, _anchor_zvazok, STR_EMPTY /* 2005-08-08: _anchor netreba*/, _file);
		/* 2005-08-27: doplnenÈ druhÈ ËÌtanie */
		_spolocna_cast_2cit_rozne(modlitba, _anchor_pom, _anchor, _file);

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_duch_past(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_duch_past(modlitba);
			}
			_spolocna_cast_full(modlitba);
			_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
			_spolocna_cast_magnifikat_viac(2, _anchor_head, _anchor, _file);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_vlastna_cast_kresponz_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_DUCH_PAST_... */

	/* spolocna cast na sviatky ucitelov cirkvi */
	else if(a == MODL_SPOL_CAST_UCITEL_CIRKVI){
		/* najprv nastavime podla spol. casti duchovnych pastierov resp.
		 * panien... */

		Log("/* spolocna cast na sviatky ucitelov cirkvi */\n");

		b = _spol_cast_vyber_dp_pn(sc);
		if(b != MODL_SPOL_CAST_NEURCENA){
			Log("spustam _set_spolocna_cast(%s) druhy raz (vnorene) -- \n  kvoli castiam, ktore pre ucitelov cirkvi nie su\n", nazov_spolc(b));
			_set_spolocna_cast(b, sc);
			Log("po vnorenom spusteni _set_spolocna_cast() -- navrat.\n");
			Log("pokracujem v nastaveni veci pre spol. cast MODL_SPOL_CAST_UCITEL_CIRKVI...\n");
		}
		/* ...a teraz vlastnu cast ucitelov cirkvi */

		/* invitatÛrium; 2007-11-20 */
		modlitba = MODL_INVITATORIUM;
		_spolocna_cast_antifona_inv;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		_spolocna_cast_hymnus;
		if(su_kcit_kresp_1cit_prosby_vlastne){
			_spolocna_cast_kcitanie;
			_spolocna_cast_kresponz;
		}
		_spolocna_cast_benediktus;
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_vlastna_cast_kresponz_ve; /* pridane 18/06/2000A.D. */

		/* vespery */
		modlitba = MODL_VESPERY;
		_spolocna_cast_hymnus;
		if(su_kcit_kresp_1cit_prosby_vlastne){
			_spolocna_cast_kcitanie;
			_spolocna_cast_kresponz;
		}
		_spolocna_cast_magnifikat;
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_vlastna_cast_kresponz_ve; /* pridane 18/06/2000A.D. */

		/* posv‰tnÈ ËÌtanie */
		modlitba = MODL_POSV_CITANIE;
		_spolocna_cast_hymnus;

		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, _anchor_pom, _anchor_zvazok, STR_EMPTY /* 2005-08-08: _anchor netreba*/, _file);
		if(su_kcit_kresp_1cit_prosby_vlastne){
			_spolocna_cast_2citanie;
		}

	}/* MODL_SPOL_CAST_UCITEL_CIRKVI */

	/* spolocna cast na sviatky jedneho mucenika */
	else if((a == MODL_SPOL_CAST_MUCENIK) ||
		(a == MODL_SPOL_CAST_MUCENICA)){

		Log("/* spolocna cast na sviatky jedneho mucenika */\n");

		sprintf(_anchor_head, "%s_", ANCHOR_SPOL_CAST_JEDEN_MUCENIK);
		Log("  _anchor_head == %s\n", _anchor_head);
		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		if(_spol_cast_je_panna(sc) == ANO){
			sprintf(_anchor_pom, "%s_", ANCHOR_SPOL_CAST_PANNA_MUCENICA);
		}
		Log("  _anchor_pom == %s\n", _anchor_pom);
		/* 2005-08-09: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* invitatÛrium; 2007-11-20 */
		modlitba = MODL_INVITATORIUM;
		_spolocna_cast_antifona_inv;

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_prve_vespery_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_muc(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_muc(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kcit_kresp_chval_ve;
		_spolocna_cast_modlitba_prve_vesp;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kcit_kresp_chval_ve;

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_muc(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_muc(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 *
		 * 2005-08-16: Zmenen˝ _anchor_pom na _anchor_head.
		 */
		_spolocna_cast_1cit_zvazok(modlitba, _anchor_head, _anchor_zvazok, STR_EMPTY /* 2005-08-08: _anchor netreba*/, _file);

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_muc(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_muc(modlitba);
			}
			_spolocna_cast_full(modlitba);
			_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_spolocna_cast_kcit_kresp_chval_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_MUCENIK/MUCENICA */

	/* spolocna cast na sviatky viacerych mucenikov */
	else if(a == MODL_SPOL_CAST_VIAC_MUCENIKOV){

		Log("/* spolocna cast na sviatky viacerych mucenikov */\n");

		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		/* 2005-08-16: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* invitatÛrium; 2007-11-20 */
		modlitba = MODL_INVITATORIUM;
		_spolocna_cast_antifona_inv;

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_prve_vespery_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_muc(%s, 2)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_muc(modlitba, 2);
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kcit_kresp_chval_ve;
		_spolocna_cast_modlitba_prve_vesp;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kcit_kresp_chval_ve;
		if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
			_spolocna_cast_ant2_po;
		}

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_muc(%s, 2)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_muc(modlitba, 2);
		}
		_spolocna_cast_full(modlitba);
		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, STR_EMPTY /* 2005-08-16: _anchor_pom netreba */, _anchor_zvazok, _anchor_pom, _file);

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_muc(%s, 2)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_muc(modlitba, 2);
			}
			_spolocna_cast_full(modlitba);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_spolocna_cast_kcit_kresp_chval_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_VIAC_MUCENIKOV */

	/* spoloËn· Ëasù na sviatky sv‰t˝ch muûov/ûien -- pre t˝ch, Ëo ûili v manûelstve */
	else if((a == MODL_SPOL_CAST_SV_MUZ_MANZ) || (a == MODL_SPOL_CAST_SV_ZENA_MANZ)){
		/* najprv nastavÌme podæa spol. Ëasti sv‰t˝ch muûov/ûien... */

		Log("/* spoloËn· Ëasù na sviatky sv‰t˝ch muûov/ûien -- pre t˝ch, Ëo ûili v manûelstve */\n");

		b = MODL_SPOL_CAST_NEURCENA;
		if(a == MODL_SPOL_CAST_SV_ZENA_MANZ)
			b = MODL_SPOL_CAST_SV_ZENA;
		else if(a == MODL_SPOL_CAST_SV_MUZ_MANZ)
			b = MODL_SPOL_CAST_SV_MUZ;

		if(b != MODL_SPOL_CAST_NEURCENA){
			Log("sp˙öùam _set_spolocna_cast(%s) druh˝ raz (vnorenÈ) -- \n   kvÙli Ëastiam, ktorÈ pre t˝ch, Ëo ûili v manûelstve nie s˙\n", nazov_spolc(b));
			_set_spolocna_cast(b, sc);
			Log("po vnorenom spustenÌ _set_spolocna_cast() -- navrat.\n");
			Log("pokraËujem v nastavenÌ vecÌ pre spol. Ëast MODL_SPOL_CAST_..._MANZ...\n");
		}
		/* ...a teraz vlastn· Ëasù pre t˝ch, Ëo ûili v manûelstve */

		/* posv‰tnÈ ËÌtanie */
		modlitba = MODL_POSV_CITANIE;

		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);

		/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, STR_EMPTY, _anchor_zvazok, _anchor_pom, _file);
		/* 2006-08-07: bude treba otestovaù, pretoûe zatiaæ to nem· asi ûiadny sv‰tec nastavenÈ */
		if(a == MODL_SPOL_CAST_SV_ZENA_MANZ){ /* 2006-08-08: odliönÈ druhÈ ËÌtanie */
			_spolocna_cast_2cit_rozne(modlitba, _anchor_pom, _anchor, _file);
		}

	}/* MODL_SPOL_CAST_SV_MUZ/ZENA_MANZ */

	/* spolocna cast na sviatky svatych muzov/zien -- pre vychovavatelov */
	else if((a == MODL_SPOL_CAST_SV_MUZ_VYCH) || (a == MODL_SPOL_CAST_SV_ZENA_VYCH)){
		/* najprv nastavime podla spol. casti svatych muzov/zien... */

		Log("/* spolocna cast na sviatky svatych muzov/zien -- pre vychovavatelov */\n");

		b = MODL_SPOL_CAST_NEURCENA;
		if(a == MODL_SPOL_CAST_SV_ZENA_VYCH)
			b = MODL_SPOL_CAST_SV_ZENA;
		else if(a == MODL_SPOL_CAST_SV_MUZ_VYCH)
			b = MODL_SPOL_CAST_SV_MUZ;

		if(b != MODL_SPOL_CAST_NEURCENA){
			Log("spustam _set_spolocna_cast(%s) druhy raz (vnorene) -- \n   kvoli castiam, ktore pre vychovavatelov nie su\n", nazov_spolc(b));
			_set_spolocna_cast(b, sc);
			Log("po vnorenom spusteni _set_spolocna_cast() -- navrat.\n");
			Log("pokracujem v nastaveni veci pre spol. cast MODL_SPOL_CAST_..._VYCH...\n");
		}
		/* ...a teraz vlastnu cast pre vychovavatelov */

		/* prve vespery */
		modlitba = MODL_PRVE_VESPERY;
		_spolocna_cast_magnifikat;
		_spolocna_cast_modlitba;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		_spolocna_cast_benediktus;
		_spolocna_cast_modlitba;

		/* vespery */
		modlitba = MODL_VESPERY;
		_spolocna_cast_magnifikat;
		_spolocna_cast_modlitba;

		/* posv‰tnÈ ËÌtanie */
		modlitba = MODL_POSV_CITANIE;

		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		/* 2006-08-08: tÌ Ëo konali skutky milosrdenstva nemaj˙ samostatnÈ 1. ËÌtanie */
		_spolocna_cast_2cit_rozne(modlitba, _anchor_pom, _anchor, _file);
		/* 2006-08-08: tÌ Ëo konali skutky milosrdenstva maj˙ rovnakÈ 2. ËÌtanie */

	}/* MODL_SPOL_CAST_SV_MUZ/ZENA_VYCH */

	/* spolocna cast na sviatky svatych muzov/zien -- pre tych, ktori konali skutky milosrdenstva */
	else if((a == MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL) || (a == MODL_SPOL_CAST_SV_ZENA_SKUTKYMIL)){
		/* najprv nastavime podla spol. casti svatych muzov/zien... */

		Log("/* spolocna cast na sviatky svatych muzov/zien -- pre tych, co konali skutky milosrdenstva */\n");

		b = MODL_SPOL_CAST_NEURCENA;
		if(a == MODL_SPOL_CAST_SV_ZENA_SKUTKYMIL)
			b = MODL_SPOL_CAST_SV_ZENA;
		else if(a == MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL)
			b = MODL_SPOL_CAST_SV_MUZ;

		if(b != MODL_SPOL_CAST_NEURCENA){
			Log("spustam _set_spolocna_cast(%s) druhy raz (vnorene) -- \n   kvoli castiam, ktore pre tych, co konali skutky milosrdenstva nie su\n", nazov_spolc(b));
			_set_spolocna_cast(b, sc);
			Log("po vnorenom spusteni _set_spolocna_cast() -- navrat.\n");
			Log("pokracujem v nastaveni veci pre spol. cast MODL_SPOL_CAST_..._SKUTKYMIL...\n");
		}
		/* ...a teraz vlastnu cast pre tych, co konali skutky milosrdenstva */

		/* prve vespery */
		modlitba = MODL_PRVE_VESPERY;
		_spolocna_cast_magnifikat;
		_spolocna_cast_modlitba;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		_spolocna_cast_benediktus;
		_spolocna_cast_modlitba;

		/* vespery */
		modlitba = MODL_VESPERY;
		_spolocna_cast_magnifikat;
		_spolocna_cast_modlitba;

		/* posv‰tnÈ ËÌtanie */
		modlitba = MODL_POSV_CITANIE;

		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		/* 2005-08-08: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, STR_EMPTY, _anchor_zvazok, _anchor_pom, _file);
		/* 2006-08-08: tÌ Ëo konali skutky milosrdenstva maj˙ v I. a II. zv‰zku rovnakÈ 1. ËÌtanie; v III. a IV. inÈ rovnakÈ 1. ËÌtanie */
		_spolocna_cast_2cit_rozne(modlitba, _anchor_pom, _anchor, _file);
		/* 2006-08-08: tÌ Ëo konali skutky milosrdenstva maj˙ rovnakÈ 2. ËÌtanie */

	}/* MODL_SPOL_CAST_SV_MUZ/ZENA_SKUTKYMIL */

	/* spolocna cast na sviatky svatych muzov/zien -- pre reholnikov */
	else if((a == MODL_SPOL_CAST_SV_MUZ_REHOLNIK) || (a == MODL_SPOL_CAST_SV_ZENA_REHOLNIK)){
		/* najprv nastavime podla spol. casti svatych muzov/zien... */

		Log("/* spolocna cast na sviatky svatych muzov/zien -- pre reholnikov */\n");

		b = MODL_SPOL_CAST_NEURCENA;
		if(a == MODL_SPOL_CAST_SV_ZENA_REHOLNIK)
			b = MODL_SPOL_CAST_SV_ZENA;
		else if(a == MODL_SPOL_CAST_SV_MUZ_REHOLNIK)
			b = MODL_SPOL_CAST_SV_MUZ;

		if(b != MODL_SPOL_CAST_NEURCENA){
			Log("spustam _set_spolocna_cast(%s) druhy raz (vnorene) -- \n   kvoli castiam, ktore pre reholnikov nie su\n", nazov_spolc(b));
			_set_spolocna_cast(b, sc);
			Log("po vnorenom spusteni _set_spolocna_cast() -- navrat.\n");
			Log("pokracujem v nastaveni veci pre spol. cast MODL_SPOL_CAST_..._REHOLNIK...\n");
		}
		/* ...a teraz vlastnu cast reholnikov */

		/* invitatÛrium; 2007-11-20 */
		modlitba = MODL_INVITATORIUM;
		_spolocna_cast_antifona_inv_viac(2);

		/* prve vespery */
		modlitba = MODL_PRVE_VESPERY;
		_spolocna_cast_hymnus;
		_spolocna_cast_magnifikat_viac(2, _anchor_head, _anchor, _file);
		_spolocna_cast_modlitba;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		_spolocna_cast_hymnus;
		_spolocna_cast_benediktus_viac(2, _anchor_head, _anchor, _file);
		_spolocna_cast_modlitba;

		/* vespery */
		modlitba = MODL_VESPERY;
		_spolocna_cast_hymnus;
		_spolocna_cast_magnifikat_viac(2, _anchor_head, _anchor, _file);
		_spolocna_cast_modlitba;

		/* posv‰tnÈ ËÌtanie */
		modlitba = MODL_POSV_CITANIE;

		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		/* 2005-08-08: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, STR_EMPTY, _anchor_zvazok, _anchor_pom, _file);
		/* 2006-08-08: rehoænÌci maj˙ v I. a II. zv‰zku rovnakÈ 1. ËÌtanie; v III. a IV. inÈ rovnakÈ 1. ËÌtanie */
		_spolocna_cast_2cit_rozne(modlitba, _anchor_pom, _anchor, _file);
		/* 2006-08-08: rehoænÌci maj˙ rovnakÈ 2. ËÌtanie */

	}/* MODL_SPOL_CAST_SV_MUZ/ZENA_REHOLNIK */

	/* spolocna cast na sviatky svatych muzov */
	else if((a == MODL_SPOL_CAST_SV_MUZ) ||
		(a == MODL_SPOL_CAST_SV_MUZ_VIACERI)){

		Log("/* spolocna cast na sviatky svatych muzov */\n");

		sprintf(_anchor_head, "%s_", nazov_spolc_ANCHOR[MODL_SPOL_CAST_SV_MUZ]);
		Log("  _anchor_head == %s\n", _anchor_head);
		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);

		/* invitatÛrium; 2007-11-20 */
		modlitba = MODL_INVITATORIUM;
		_spolocna_cast_antifona_inv_viac(2);

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_prve_vespery_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_duch_past(%s)... - pretoûe pre sv‰t˝ch muûov sa ber˙ tie istÈ ûalmy\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_duch_past(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		_spolocna_cast_benediktus_rozne(modlitba, _anchor_pom, _anchor, _file);
		_spolocna_cast_kresponz_rozne(modlitba, _anchor_pom, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_vlastna_cast_kresponz_ve;

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_duch_past(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_duch_past(modlitba);
		}

		/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		_spolocna_cast_full(modlitba);
		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, STR_EMPTY /* 2005-08-16: _anchor_pom netreba */, _anchor_zvazok, _anchor_pom, _file);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file); /* 2006-08-07: doplnenÈ */

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_duch_past(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_duch_past(modlitba);
			}
			_spolocna_cast_full(modlitba);
			_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
			_spolocna_cast_magnifikat_rozne(modlitba, _anchor_pom, _anchor, _file);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_vlastna_cast_kresponz_ve; /* pridane 18/06/2000A.D. */
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_SV_MUZ_[VIACERI]... */

	/* spolocna cast na sviatky svatych zien */
	else if((a == MODL_SPOL_CAST_SV_ZENA) ||
		(a == MODL_SPOL_CAST_SV_ZENA_VIACERE)){

		Log("/* spolocna cast na sviatky svatych zien */\n");

		sprintf(_anchor_head, "%s_", nazov_spolc_ANCHOR[MODL_SPOL_CAST_SV_ZENA]);
		Log("  _anchor_head == %s\n", _anchor_head);
		sprintf(_anchor_pom, "%s_", nazov_spolc_ANCHOR[a]);
		Log("  _anchor_pom == %s\n", _anchor_pom);

		/* invitatÛrium; 2007-11-20 */
		modlitba = MODL_INVITATORIUM;
		_spolocna_cast_antifona_inv_viac(2);

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_prve_vespery_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_panien(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_panien(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_vlastna_cast_kresponz_ve;

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_panien(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_panien(modlitba);
		}

		/* 2005-08-05: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		_spolocna_cast_full(modlitba);
		/* 2005-08-05: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, STR_EMPTY /* 2005-08-16: _anchor_pom netreba */, _anchor_zvazok, _anchor_pom, _file);
		_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file); /* 2006-08-07: doplnenÈ */

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_panien(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_panien(modlitba);
			}
			_spolocna_cast_full(modlitba);
			_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_SV_ZENA_[VIACERE]... */

	/* spolocna cast na sviatky panien */
	else if((a == MODL_SPOL_CAST_PANNA) ||
		(a == MODL_SPOL_CAST_PANNY_VIACERE)){

		Log("/* spolocna cast na sviatky panien */\n");

		/* invitatÛrium; 2007-11-20 */
		modlitba = MODL_INVITATORIUM;
		_spolocna_cast_antifona_inv_viac(2);

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_prve_vespery_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_panien(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_panien(modlitba);
		}
		_spolocna_cast_full(modlitba);
		//_spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kresp_ve;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kresp_ve;

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_panien(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_panien(modlitba);
		}
		_spolocna_cast_full(modlitba);
		/* 2005-07-22: ToDo: skontrolovaù, Ëi pre öpeci·lne obdobia nie s˙ öpeci·lne Ëasti z obdobia */
		/* _spolocna_cast_hymnus_rozne(modlitba, _anchor_pom, _anchor, _file); */
		/* 2005-08-27: 1. ËÌtanie je rovnakÈ pre vöetky obdobia a zv‰zky ûalt·ra :-) */

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_panien(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_panien(modlitba);
			}
			_spolocna_cast_full(modlitba);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_spolocna_cast_kresp_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_PANNA/viacere */

	/* spolocna cast na sviatky Panny Marie */
	else if(a == MODL_SPOL_CAST_PANNA_MARIA){ /* 2005-08-25: UpravenÈ */

		Log("/* spolocna cast na sviatky Panny Marie */\n");

		/* invitatÛrium; 2007-11-19 */
		modlitba = MODL_INVITATORIUM;
		_spolocna_cast_antifona_inv_viac(2);

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_prve_vespery_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_marie(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_marie(modlitba);
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_prosby_viac(2, _anchor_head, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kresp_ve;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-01-25_ZALMY1NE_FIX */
			_set_zalmy_1nedele_rch();
		}
		_spolocna_cast_full(modlitba);
		_spolocna_cast_prosby_viac(2, _anchor_head, _anchor, _file);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kresp_ve;

		/* 2005-08-25: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_pom, "%s", STR_EMPTY);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* posvatne citanie */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_sviatok_marie(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_sviatok_marie(modlitba);
		}
		_spolocna_cast_full(modlitba);
		/* 2005-08-25: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, _anchor_pom, _anchor_zvazok, _anchor_head, _file);
		_spolocna_cast_kresponz_zvazok(modlitba, _anchor_pom, _anchor_zvazok, _anchor_head, _file);

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_sviatok_marie(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_sviatok_marie(modlitba);
			}
			_spolocna_cast_full(modlitba);
			_spolocna_cast_prosby_viac(2, _anchor_head, _anchor, _file);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_spolocna_cast_kresp_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_PANNA_MARIA */

// 2006-01-19_LABEL // 2005-08-16: tu treba pokraËovaù

	/* spolocna cast na oficium za zosnulych */
	else if(a == MODL_SPOL_CAST_ZA_ZOSNULYCH){

		Log("/* spolocna cast na oficium za zosnulych */\n");

		/* invitatÛrium; 2007-11-14 */
		modlitba = MODL_INVITATORIUM;
		_spolocna_cast_antifona_inv;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_za_zosnulych(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_za_zosnulych(modlitba);
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_benediktus_ve;
		_spolocna_cast_ant3_viac(2, _anchor_head, _anchor, _file);

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_za_zosnulych(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_za_zosnulych(modlitba);
			}
			_spolocna_cast_full(modlitba);
			_spolocna_cast_kresponz_viac(2, _anchor_head, _anchor, _file);
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_spolocna_cast_magnifikat_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

		/* 2007-11-08 / 2005-08-25: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_pom, "%s", STR_EMPTY);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* 2007-11-08 / posv‰tnÈ ËÌtanie; 2006-02-11 */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_za_zosnulych(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_za_zosnulych(modlitba);
		}
		_spolocna_cast_full(modlitba);
		/* 2005-08-25: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, _anchor_pom, _anchor_zvazok, _anchor_head, _file);

	}/* MODL_SPOL_CAST_ZA_ZOSNULYCH */

	/* spolocna cast na sviatky posviacky chramu */
	else if(a == MODL_SPOL_CAST_POSVIACKA_CHRAMU){

		Log("/* spolocna cast na sviatky posviacky chramu */\n");

		/* invitatÛrium; 2007-11-19 */
		modlitba = MODL_INVITATORIUM;
		_spolocna_cast_antifona_inv_viac(2);

		/* prvÈ veöpery */
		modlitba = MODL_PRVE_VESPERY;
		if(su_zalmy_prve_vespery_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_posviacka_chramu(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_posviacka_chramu(modlitba);
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kresponz_ve;
		if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN))
			_spolocna_cast_ant1_3_po;

		/* ranne chvaly */
		modlitba = MODL_RANNE_CHVALY;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_posviacka_chramu(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_posviacka_chramu(modlitba);
		}
		_spolocna_cast_full(modlitba);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
			_spolocna_cast_kresponz_ve;

		/* 2005-08-25: pridan˝ ÔalöÌ pomocn˝ anchor, ktor˝ pojedn·va o zv‰zku brevi·ra kvÙli posv. ËÌtaniam */
		sprintf(_anchor_pom, "%s", STR_EMPTY);
		Log("  _anchor_pom == %s\n", _anchor_pom);
		sprintf(_anchor_zvazok, "%s_", zvazok_OBD[_global_den.litobd]);
		if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
			strcat(_anchor_zvazok, VELKONOCNA_PRIPONA);
		}
		Log("  _anchor_zvazok == %s\n", _anchor_zvazok);

		/* posv‰tnÈ ËÌtanie; 2006-02-11 */
		modlitba = MODL_POSV_CITANIE;
		if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
			Log("  _set_zalmy_posviacka_chramu(%s)...\n", nazov_modlitby(modlitba));
			_set_zalmy_posviacka_chramu(modlitba);
		}
		_spolocna_cast_full(modlitba);
		/* 2005-08-25: 1. ËÌtanie je zv‰Ëöa odliönÈ pre spoloËnÈ Ëasti sviatkov sv‰t˝ch nasledovne:
		 * - I. zv‰zok (advent, vianoce) a II. zv‰zok (pÙst),
		 * - II. zv‰zok (veæk· noc),
		 * - III. a IV. zv‰zok (obdobie cez rok).
		 */
		_spolocna_cast_1cit_zvazok(modlitba, _anchor_pom, _anchor_zvazok, _anchor_head, _file);

		/* vespery */
		if(_global_den.litobd != OBD_OKTAVA_NARODENIA){
			modlitba = MODL_VESPERY;
			if(su_zalmy_vlastne || (_global_opt2 == MODL_ZALMY_ZO_SV)){ /* 2006-02-04_ZALMY_ZO_SVIATKU_FIX */
				Log("  _set_zalmy_posviacka_chramu(%s)...\n", nazov_modlitby(modlitba));
				_set_zalmy_posviacka_chramu(modlitba);
			}
			_spolocna_cast_full(modlitba);
			if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN))
				_spolocna_cast_ant1_3_po;
			if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
				_spolocna_cast_kresponz_ve;
		}/* v OBD_OKTAVA_NARODENIA -- vespery su zo dna */

	}/* MODL_SPOL_CAST_POSVIACKA_CHRAMU */

	Log("_set_spolocna_cast(%s) -- end\n", nazov_spolc(a));
}/* _set_spolocna_cast(); -- dva argumenty */

#define _set_spolocna_cast(a) _set_spolocna_cast(a, sc)


#define set_LOG_sc Log("          sc == {%s (%d), %s (%d), %s (%d)}\n",	\
	nazov_spolc(sc.a1), sc.a1, \
	nazov_spolc(sc.a2), sc.a2, \
	nazov_spolc(sc.a3), sc.a3); Log

void set_spolocna_cast(_struct_sc sc, short int poradie_svaty){
	/* poradie_svaty je vstupom iba kvoli tomu, ze ak je 0,
	 * potom nas neznepokojuju vypisy typu Error: not assigned...
	 *
	 * 22/02/2000A.D.: ked nastavi vo formulari (detaily) zalmy zo `sviatku'
	 * a spolocnu cast `nebrat', predsa sa nevyvolaju zalmy zo sviatku,
	 * lebo sa nespusti _set_spolocna_cast(); !!! -- mozno by bolo dobre
	 * oddelit nastavenie pre spolocnu cast a potom inde dat samotne zalmy...
	 * !!!
	 */
	Log("set_spolocna_cast({%s, %s, %s}) -- begin\n",
		nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3));
	Log("          _global_opt3 == %s (%d)\n",
		nazov_spolc(_global_opt3), _global_opt3);

	Log("  teraz nastavujem POPIS (pre daneho svateho)...\n");
	mystrcpy(_anchor, _anchor_head, MAX_STR_AF_ANCHOR);
	strcat(_anchor, ANCHOR_POPIS);
	modlitba = MODL_RANNE_CHVALY;
	set_popis(modlitba, _file, _anchor); /* pridane 05/04/2000A.D. */
	modlitba = MODL_VESPERY;
	set_popis(modlitba, _file, _anchor); /* pridane 05/04/2000A.D. */
	modlitba = MODL_POSV_CITANIE;
	set_popis(modlitba, _file, _anchor); /* pridanÈ 2005-07-22 */
	modlitba = MODL_PRVE_VESPERY;
	set_popis(modlitba, _file, _anchor); /* pridane 05/04/2000A.D. */
	/* 2006-01-27: PridanÈ popisy pre modlitby cez deÚ */
	set_popis(MODL_PREDPOLUDNIM, _file, _anchor);
	set_popis(MODL_NAPOLUDNIE, _file, _anchor);
	set_popis(MODL_POPOLUDNI, _file, _anchor);
	/* 2003-06-30: tento POPIS nie je dobre nastaveny pre spomienku
	 * NepoökvrnenÈho Srdca prebl. Panny M·rie,
	 * preto je tam nastaveny este raz na dummy, vid ZNOVUNASTAVENIE_POPISU_NA_DUMMY */

	/* tu bola pasaz, nastavujuca _global_opt3 na sc.a1 v pripade,
	 * ze je neurcena;
	 * je teraz v sviatky_svatych() so styrmi vstupmi,
	 * pretoze sa musi vykonat iba pri druhom spusteni funkcie
	 * sviatky_svatych() -- 18/02/2000A.D.
	 */

	/* 2007-09-28: doplnenÈ */
	if(_global_den.typslav == SLAV_SLAVNOST){
		Log("	teraz nastavujem ûalmy pre modlitbu cez deÚ sl·vnostÌ...\n");
		if(_global_den.denvt != DEN_NEDELA){
			Log("  _set_zalm_cez_den_doplnkova_psalmodia()...\n");
			_set_zalm_cez_den_doplnkova_psalmodia();
		}
		else{
			// nedeæa - ûalmy pre modlitbu cez deÚ s˙ z nedele; nemenÌm ich, ibaûe by boli podæa bodu 135 smernÌc nastavenÈ vlastnÈ
			Log("  ûalmy ost·vaj˙ z nedele (nemenÌm ich)...\n");
		}
	}

	/* podla _global_opt3 urcime, ktoru spolocnu cast dat */
	if(sc.a1 != MODL_SPOL_CAST_NEURCENA){
		if(_global_opt3 == sc.a1){
			_set_spolocna_cast(_global_opt3);
		}
		else{
			if(sc.a2 != MODL_SPOL_CAST_NEURCENA){
				if(_global_opt3 == sc.a2){
					_set_spolocna_cast(_global_opt3);
				}
				else{
					if(sc.a3 != MODL_SPOL_CAST_NEURCENA){
						if(_global_opt3 == sc.a3){
							_set_spolocna_cast(_global_opt3);
						}
						else{
							if(_global_opt3 == MODL_SPOL_CAST_NEBRAT){
								set_LOG_sc("  neberiem spolocnu cast\n");
								Export("<!--neberiem spolocnu cast-->");
							}
							else
							/* sem by to nemalo prist */
							{
							set_LOG_sc("-- Error: sc (a1, a2, a3) su sice urcene, ale _global_opt3 sa nerovna ani jednej z nich!\n");
							Export("%s\n", "Error: _global_opt3 assigned incorectly (a1, a2, a3 -- ok)");
							ALERT;
							return;
							}
						}
					}/* sc.a3 je urcena */
					else{
						if(_global_opt3 == MODL_SPOL_CAST_NEBRAT){
							set_LOG_sc("  neberiem spolocnu cast\n");
							Export("<!--neberiem spolocnu cast-->");
						}
						else
						/* sem by to nemalo prist */
						if(poradie_svaty != 0){
							set_LOG_sc("-- Error: sc (a1, a2) su sice urcene, ale _global_opt3 sa nerovna ani jednej z nich!\n");
							Export("%s\n", "Error: _global_opt3 assigned incorectly (a1, a2 -- ok)");
							ALERT;
							return;
						}
					}
				}
			}/* sc.a2 je urcena */
			else{
				if(_global_opt3 == MODL_SPOL_CAST_NEBRAT){
					set_LOG_sc("  neberiem spolocnu cast\n");
					Export("<!--neberiem spolocnu cast-->");
				}
				else
				/* sem by to nemalo prist */
				if(poradie_svaty != 0){
					set_LOG_sc("-- Error: sc (a1) je sice urcena, ale _global_opt3 sa jej nerovna!\n");
					Export("%s\n", "Error: _global_opt3 assigned incorectly (a1 -- ok)");
					ALERT;
					return;
				}
			}
		}
	}/* sc.a1 je urcene */
	else{
		/* sem by to nemalo prist */
		if(poradie_svaty != 0){
			Log("-- Error: sc (a1) nie je urcene; _global_opt3 == %s\n", nazov_spolc(_global_opt3));
			Export("%s\n", "Error: a1 (member of sc) assigned incorectly");
			ALERT;
			return;
		}
	}
	Log("set_spolocna_cast(_global_opt3 == %s) -- end\n", nazov_spolc(_global_opt3));
}/* set_spolocna_cast(); */

/* 2007-10-02: vytvoren˝ nov˝ define, aby nebolo toæko copy-paste miest v kÛde */
#define _vlastna_cast_mcd_ant_kcitresp_modl {\
	modlitba = MODL_PREDPOLUDNIM;\
	_vlastna_cast_antifony_rovnake;\
	_vlastna_cast_kcitanie;\
	_vlastna_cast_kresponz;\
	_vlastna_cast_modlitba;\
	modlitba = MODL_NAPOLUDNIE;\
	_vlastna_cast_antifony_rovnake;\
	_vlastna_cast_kcitanie;\
	_vlastna_cast_kresponz;\
	_vlastna_cast_modlitba;\
	modlitba = MODL_POPOLUDNI;\
	_vlastna_cast_antifony_rovnake;\
	_vlastna_cast_kcitanie;\
	_vlastna_cast_kresponz;\
	_vlastna_cast_modlitba;\
}

#define _vlastna_cast_mcd_kcitresp_modl {\
	modlitba = MODL_PREDPOLUDNIM;\
	_vlastna_cast_kcitanie;\
	_vlastna_cast_kresponz;\
	_vlastna_cast_modlitba;\
	modlitba = MODL_NAPOLUDNIE;\
	_vlastna_cast_kcitanie;\
	_vlastna_cast_kresponz;\
	_vlastna_cast_modlitba;\
	modlitba = MODL_POPOLUDNI;\
	_vlastna_cast_kcitanie;\
	_vlastna_cast_kresponz;\
	_vlastna_cast_modlitba;\
}

/* 2008-02-22: vytvoren˝ nov˝ define, aby nebolo toæko copy-paste miest v kÛde */
#define _vlastna_cast_mcd_hymnus_kcitresp_modl {\
	modlitba = MODL_PREDPOLUDNIM;\
	_vlastna_cast_hymnus;\
	_vlastna_cast_kcitanie;\
	_vlastna_cast_kresponz;\
	_vlastna_cast_modlitba;\
	modlitba = MODL_NAPOLUDNIE;\
	_vlastna_cast_hymnus;\
	_vlastna_cast_kcitanie;\
	_vlastna_cast_kresponz;\
	_vlastna_cast_modlitba;\
	modlitba = MODL_POPOLUDNI;\
	_vlastna_cast_hymnus;\
	_vlastna_cast_kcitanie;\
	_vlastna_cast_kresponz;\
	_vlastna_cast_modlitba;\
}

/* ... a teraz samotna funkcia sviatky_svatych(): */
short int sviatky_svatych(short int den, short int mesiac, short int poradie_svaty){
	/* toto priradujeme preto, aby sme nemuseli pri kazdom svatom
	 * priradovat pocet = 1; */
	short int pocet = 1;
	char _anchor_vlastne_slavenie[SMALL]; /* 2007-11-14: pridanÈ */

	Log("-- sviatky_svatych(%d, %d) -- zaciatok\n", den, mesiac);

	/* nasledujuca pasaz v pripade, ze poradie_svaty nie je dane (t.j. nie je
	 * 1, 2 alebo 3) vycisti udaje;
	 * to je vtedy, ked je tato funkcia volana poprvykrat
	 */

	if((poradie_svaty < 1) || (poradie_svaty > 3)){
		/* den */
		_global_svaty1.den = _global_svaty2.den = _global_svaty3.den = den;
		/* mesiac */
		_global_svaty1.mesiac = _global_svaty2.mesiac = _global_svaty3.mesiac = mesiac;
		/* rok */
		_global_svaty1.rok = _global_svaty2.rok = _global_svaty3.rok = _global_den.rok;
		/* denvt */
		_global_svaty1.denvt = _global_svaty2.denvt = _global_svaty3.denvt = _global_den.denvt;
		/* denvr */
		_global_svaty1.denvr = _global_svaty2.denvr = _global_svaty3.denvr = _global_den.denvr;
		/* smer */
		_global_svaty1.smer = _global_svaty2.smer = _global_svaty3.smer = _global_den.smer;
		/* litobd */
		_global_svaty1.litobd = _global_svaty2.litobd = _global_svaty3.litobd = _global_den.litobd;
		/* litrok */
		_global_svaty1.litrok = _global_svaty2.litrok = _global_svaty3.litrok = _global_den.litrok;
		/* tyzden */
		_global_svaty1.tyzden = _global_svaty2.tyzden = _global_svaty3.tyzden = _global_den.tyzden;
		/* tyzzal */
		_global_svaty1.tyzzal = _global_svaty2.tyzzal = _global_svaty3.tyzzal = _global_den.tyzzal;
		/* typslav - neurcena */
		_global_svaty1.typslav = _global_svaty2.typslav = _global_svaty3.typslav = SLAV_NEURCENE;
		/* typ lok·lneho sl·venia - neurËenÈ; pridanÈ 2005-07-27 */
		_global_svaty1.typslav_lokal = _global_svaty2.typslav_lokal = _global_svaty3.typslav_lokal = LOKAL_SLAV_NEURCENE;
		/* prik - nie je prikazany */
		_global_svaty1.prik = _global_svaty2.prik = _global_svaty3.prik = NEPRIKAZANY_SVIATOK;
		/* meno - neurcene */
		mystrcpy(_global_svaty1.meno, STR_EMPTY, MENO_SVIATKU); /* prerobene na mystrcpy, 2003-08-13 */
		mystrcpy(_global_svaty2.meno, STR_EMPTY, MENO_SVIATKU);
		mystrcpy(_global_svaty3.meno, STR_EMPTY, MENO_SVIATKU);
		/* spolcast - neurcena */
		_global_svaty1.spolcast = _global_svaty2.spolcast = _global_svaty3.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA, MODL_SPOL_CAST_NEURCENA);
		Log("nastavil som _global_svaty[1,2,3] na default (bud neurcene alebo z _global_den)\n");
		_global_svaty1.farba = _global_svaty2.farba = _global_svaty3.farba = LIT_FARBA_NEURCENA; /* 2006-08-19: pridanÈ */
	}
	else{
		/* povodne tu bola pasaz, ktora podla poradie_svaty nastavila
		 * do _global_den = _global_svaty[1,2,3],
		 * tato pasaz je teraz na zaciatku sviatky_svatych() so styrmi
		 * vstupmi/argumentami
		 */
		Log("   (tu bola pasaz, co je teraz v sviakty_svatych() so 4 vstupmi)\n");
	}
	/* dalsia cast v zatvorkach {, } je sice len pre pripad, ze
	 * poradie_svaty == 1, 2, 3; avsak aj pre 0 je to
	 * preto, ze aj ked nie je svaty urceny, moze ist o slavnost,
	 * ktora ma takmer najvacsiu prioritu, a preto ma aj prve
	 * vespery - a vtedy by to normalne nefungovalo
	 */
	{/* pasaz kt. ma zmysel len pre poradie_svaty == 1, 2, 3, ale
	  * v pripade slavnosti aj pre == 0 */
		Log("/* nastavenie nazvu suboru, kotvy apod. (sviatky_svatych) */\n");
		/* nastavenie nazvu suboru, kotvy apod. */
		if(poradie_svaty > 1) /* pridame cislo svateho */
			sprintf(_anchor_head, "%02d%s%d_", den, nazov_MES[mesiac - 1], poradie_svaty);
		else
			sprintf(_anchor_head, "%02d%s_", den, nazov_MES[mesiac - 1]);
		Log("  _anchor_head == %s\n", _anchor_head);

		sprintf(_file, "sv_%s.htm", nazov_mes[mesiac - 1]);
		Log("  _file == %s\n", _file);

		/* 2005-07-26: s˙bor pre posv‰tnÈ ËÌtania */
		sprintf(_file_pc, "pc_sv_%s.htm", nazov_mes[mesiac - 1]);
		Log("  _file_pc == %s\n", _file_pc);
	}

	/* LOG_ciara_sv; Log("_global_den: \n"); Log(_global_den); */

	/* az teraz, ked je v _global_den (pri druhom volani fcie)
	 * spravna hodnota z _global_svaty[1,2,3], mozem urobit toto
	 * priradenie do sc
	 */
	_struct_sc sc = _decode_spol_cast(_global_den.spolcast);

	/* 2006-02-06: pridan˝ debug v˝pis */
	Log("\tDeklarujem ötrukt˙ru sc == ({%s, %s, %s}) -- begin\n",
		nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3));

	LOG_ciara_sv;
	Log("Teraz nasleduje veæk˝ switch() podæa mesiacov a dnÌ...\n");

	/* a teraz velky switch()... 'Velky inkvizitor'... ;-) */
	switch(mesiac - 1){
		case MES_JAN:
			switch(den){
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_02[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_VIACERI, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_07[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_13[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 17:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_17[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 18:
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla (vseobecneho) kalendara */
							mystrcpy(_global_svaty1.meno, text_JAN_18[_global_jazyk], MENO_SVIATKU);
							_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 20:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_20_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_JAN_20_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty2.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_21[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENICA, MODL_SPOL_CAST_PANNA);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 22:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_22[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 23:
					if(_global_jazyk == JAZYK_SK){
						/* 2005-10-24: pridanÈ, je to spomienka len v DÛme sv. Martina, BA */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_DOM_SV_MARTINA; /* 2005-07-27: pridanÈ */
						mystrcpy(_global_svaty1.meno, text_JAN_23[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 24:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_24[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 25:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);

						modlitba = MODL_VESPERY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						/* 2008-02-13: doplnenÈ mcd pre Ëesk˙ verziu; 2008-02-22 aj pre slovensk˙ */
						_vlastna_cast_mcd_ant_kcitresp_modl;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_JAN_25[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 26:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_26[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_27[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA, MODL_SPOL_CAST_SV_ZENA_VYCH);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_28[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_UCITEL_CIRKVI, MODL_SPOL_CAST_DUCH_PAST_KNAZ);
						/* ...KNAZ nie je vo vlastnej casti, avsak aby sme vedeli,
						 * co mame dat v tych castiach, ktore nie su v uciteloch
						 * cirkvi, kde sa odvolava na duchovnych pastierov; 23/02/2000A.D.
						 */
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 31:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JAN_31[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_VYCH);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				default: break;
			}; break; /* case MES_JAN */
		case MES_FEB:
			switch(den){
				case 1:
					break;
#ifdef WRONG_23_02_2000
					if(!((_global_den.denvt == DEN_SOBOTA) && (_global_modlitba == MODL_VESPERY)))
						break;
					else{
						den++;
						sprintf(_anchor_head, "%02d%s_", den, nazov_MES[mesiac - 1]);
						Log("  _anchor_head == %s\n", _anchor_head);
					}
#endif
					/* v opacnom pripade sa ide na case 2:
					 * treba vsak upravit kotvu _anchor
					 */
				case 2:
					//if(poradie_svaty == 1){
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* definovanie parametrov pre modlitbu */

						if((poradie_svaty == 1) &&
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_krstu(modlitba);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_1nedele_rch();

						/* modlitba cez deÚ, pridanÈ 2008-02-22 */
						if(_global_jazyk == JAZYK_CZ){
							_vlastna_cast_mcd_hymnus_kcitresp_modl;
						}
						else{
							_vlastna_cast_mcd_kcitresp_modl;
						}

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_obetovania(modlitba);

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_krstu(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 5; /* sviatky Pana uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_FEB_02[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_03_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_FEB_03_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 5:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}

					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_05[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENICA, MODL_SPOL_CAST_PANNA);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 6:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}

					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_06[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 8:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* 2006-08-19: pridanÈ */
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_08[_global_jazyk], MENO_SVIATKU);
					/* 2006-08-08: spoloËn· Ëasù pridan· podæa mailu don Val·bka z 19. augusta 2005 */
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_VYCH, MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_FEB_08_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 10:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_10[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 11:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_11[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 14:
					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_benediktus;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_magnifikat;
							_vlastna_cast_modlitba;

							break;
						}
						/* na Slovensku 5. jula, slavnost, v Europe sviatok */
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_14_FEB_CYRIL_METOD; /* 2006-02-03: pridanÈ */
						mystrcpy(_global_svaty1.meno, "Sv. Cyrila, mnÌcha, a sv. Metoda, biskupa", MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_VIACERI);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 17:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_17[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_21[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 22:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_modlitba;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						/* 2006-02-07: doplnenÈ mcd; */
						_vlastna_cast_mcd_kcitresp_modl;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_FEB_22[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_FEB_23[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				default:
					break;
			}; break; /* case MES_FEB */
		case MES_MAR:
			switch(den){
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					if(_global_jazyk == JAZYK_SK){
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					}
					else {
						/* v Ëeskom liturgickom kalend·ri "Nez·vazn· pam·tka" */
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					}
					mystrcpy(_global_svaty1.meno, text_MAR_04[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAR_07[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 8:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAR_08[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK, MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 9:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAR_09[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 10:
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_benediktus;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_magnifikat;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky */
						mystrcpy(_global_svaty1.meno, text_MAR_10[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_KNAZ);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 15:
					/* 2008-03-12: ökaredÈ nadr·tovanÈ rieöenie, bude potrebnÈ naimplementovaù krajöie */
					if((_global_den.denvt == DEN_SOBOTA) && (_global_den.rok == 2008)){
						/* t.j. sl·vnosù sv. Jozefa sa preklad· pred veæk˝ t˝ûdeÚ */
						sprintf(_anchor_head, "%02d%s_", 19, nazov_MES[mesiac - 1]);
						Log("  _anchor_head == %s\n", _anchor_head);
						Log("(rok 2008) jumping to label_19_MAR...\n");
						goto label_19_MAR;
					}
					break;
				case 17:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAR_17[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 18:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						/* nema modlitba = MODL_VESPERY, lebo su prve vespery slavnosti sv. Jozefa */
						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAR_18[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 19:
label_19_MAR:
					//if(poradie_svaty == 1){
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* definovanie parametrov pre modlitbu */

						if((poradie_svaty == 1) &&
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
							_vlastna_cast_kresponz_ve;
						}
						else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
							_vlastna_cast_kresponz_po;
						}
						_set_zalmy_sviatok_duch_past(modlitba);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
							_vlastna_cast_kresponz_ve;
						}
						else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
							_vlastna_cast_kresponz_po;
						}
						_set_zalmy_1nedele_rch();

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_modlitba;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						_vlastna_cast_mcd_ant_kcitresp_modl;

						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
							_vlastna_cast_kresponz_ve;
						}
						else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
							_vlastna_cast_kresponz_po;
						}
						_set_zalmy_sviatok_duch_past(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_MAR_19[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 20:
					if(_global_den.denvt == DEN_PONDELOK){
						/* t.j. slavnost sv. Jozefa padla na nedelu */
						sprintf(_anchor_head, "%02d%s_", den - 1, nazov_MES[mesiac - 1]);
						Log("  _anchor_head == %s\n", _anchor_head);
						Log("jumping to label_19_MAR...\n");
						goto label_19_MAR;
					}
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAR_23[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 25:
label_25_MAR:
					//if(poradie_svaty == 1){
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* definovanie parametrov pre modlitbu */

						if((poradie_svaty == 1) &&
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
							_vlastna_cast_kresponz_ve;
						}
						else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
							_vlastna_cast_kresponz_po;
						}
						_set_zalmy_sviatok_krstu(modlitba);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
							_vlastna_cast_kresponz_ve;
						}
						else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
							_vlastna_cast_kresponz_po;
						}
						_set_zalmy_1nedele_rch();

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_modlitba;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;
						_set_zalmy_sviatok_obetovania(modlitba);

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						_vlastna_cast_mcd_ant_kcitresp_modl;
						
						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II)){
							_vlastna_cast_kresponz_ve;
						}
						else if((_global_den.litobd == OBD_POSTNE_I) || (_global_den.litobd == OBD_POSTNE_II_VELKY_TYZDEN)){
							_vlastna_cast_kresponz_po;
						}
						_set_zalmy_sviatok_krstu(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_MAR_25[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 26:
					if(_global_den.denvt == DEN_PONDELOK){
						/* t.j. Zvestovanie Pana padlo na nedelu */
						sprintf(_anchor_head, "%02d%s_", den - 1, nazov_MES[mesiac - 1]);
						Log("  _anchor_head == %s\n", _anchor_head);
						Log("jumping to label_25_MAR...\n");
						goto label_25_MAR;
					}
					break;
				case 31:
					/* 2008-03-12: ökaredÈ nadr·tovanÈ rieöenie, bude potrebnÈ naimplementovaù krajöie */
					if((_global_den.denvt == DEN_PONDELOK) && (_global_den.rok == 2008)){
						/* t.j. Zvestovanie P·na sa preklad· za veækonoËn˙ okt·vu */
						sprintf(_anchor_head, "%02d%s_", 25, nazov_MES[mesiac - 1]);
						Log("  _anchor_head == %s\n", _anchor_head);
						Log("(rok 2008) jumping to label_25_MAR...\n");
						goto label_25_MAR;
					}
					break;
			}; break; /* case MES_MAR */
		case MES_APR:
			switch(den){
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_02[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_04[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 5:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_05[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_07[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_VYCH);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 11:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_11[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_13[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_21[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 23:
					/* 2007-04-23: vo vöeobecnom kalend·ri s˙ 23. aprÌla sv. Juraj a sv. Vojtech */
					if((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_CZ)){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_benediktus;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_magnifikat;
							_vlastna_cast_modlitba;

							break;
						}
						if(_global_jazyk == JAZYK_CZ){
							_global_svaty1.typslav = SLAV_SVIATOK;
							_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
							_global_svaty1.typslav_lokal = LOKAL_SLAV_PRAHA_PATRON; /* 2006-08-15: pridanÈ */
						}
						else{
							_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
							_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						}
						mystrcpy(_global_svaty1.meno, text_APR_23[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					else{
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_benediktus;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_magnifikat;
							_vlastna_cast_modlitba;

							break;
						}
						else if(poradie_svaty == 2){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_benediktus;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_magnifikat;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_APR_24_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
						_global_svaty1.farba = LIT_FARBA_CERVENA;
						pocet = 2;
						_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty2.meno, text_APR_23[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
						_global_svaty2.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 24:
					/* 2007-04-23: vo vöeobecnom kalend·ri s˙ 23. aprÌla sv. Juraj a sv. Vojtech */
					if((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_CZ)){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						else if(poradie_svaty == 2){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_APR_24_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
						pocet = 2;
						_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty2.meno, text_APR_24_2[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_KNAZ);
						_global_svaty2.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					else{
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_benediktus;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_magnifikat;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_APR_24_2[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_KNAZ);
						_global_svaty1.farba = LIT_FARBA_CERVENA;
					}
					break;
				case 25:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						_vlastna_cast_mcd_kcitresp_modl;
						
						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_APR_25[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_APR_28_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_APR_28_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 29:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					/* 2006-01-11: pÙvodne to bola spomienka, ale don Val·bek ma upozornil, ûe sa jedn· o sviatok; upraven˝ n·zov
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; - povinne spomienky podla vseobecneho kalendara 
					*/
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_APR_29[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 30:
					if((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_LA)){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_APR_30_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					else if(_global_jazyk == JAZYK_CZ){
						/* okrem Pia V. maj˙ aj sv. éigmunda */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						else if(poradie_svaty == 2){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_APR_30_2[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
						pocet = 2;
						_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty2.meno, text_APR_30_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
						_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
			}; break; /* case MES_APR */
		case MES_MAY:
			switch(den){
				case 1:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_benediktus;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_hymnus;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_magnifikat;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_01[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_02[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_antifony;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_hymnus;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_antifony;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						/* 2008-05-08: doplnenÈ */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie; /* zo spoloËnej Ëasti apoötolov */
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie; /* zo spoloËnej Ëasti apoötolov */
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_kcitanie; /* zo spoloËnej Ëasti apoötolov */
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_MAJ_03[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 6:
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla (vseobecneho) kalendara */
						mystrcpy(_global_svaty1.meno, text_MAJ_06[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_KNAZ);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 8:
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla (vseobecneho) kalendara */
						mystrcpy(_global_svaty1.meno, text_MAJ_08[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 12:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					/* 2006-08-16: pridanÈ */
					else if((_global_jazyk == JAZYK_CZ) && (poradie_svaty == 3)){
						/* definovanie parametrov pre modlitbu */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);
						/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_12_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					if(_global_jazyk == JAZYK_CZ)
						pocet = 3;
					else
						pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_MAJ_12_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty2.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					if(_global_jazyk == JAZYK_CZ){
						_global_svaty3.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty3.typslav_lokal = LOKAL_SLAV_PRAHA;
						_global_svaty3.typslav = SLAV_SVIATOK;
						mystrcpy(_global_svaty3.meno, text_MAJ_12_3[_global_jazyk], MENO_SVIATKU);
						_global_svaty3.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty3.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 14:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus; /* 2008-05-14: doplnenÈ - pre Ëesk˙ verziu vlastn˝, pre slovensk˙ rovnak˝ ako na posv. ËÌtanie */
						_vlastna_cast_modlitba;
						_vlastna_cast_benediktus;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_hymnus;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;
						_vlastna_cast_magnifikat;

						/* 2008-05-14: doplnenÈ podæa 3. m·ja */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie; /* zo spoloËnej Ëasti apoötolov */
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie; /* zo spoloËnej Ëasti apoötolov */
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_kcitanie; /* zo spoloËnej Ëasti apoötolov */
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_MAJ_14[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 16:
					if((_global_jazyk == JAZYK_SK) || (_global_jazyk == JAZYK_CZ)){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_full(modlitba);
							if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
								_vlastna_cast_kresponz_ve;
							/* inak zostane cezrocne, ale bez pripony */

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_hymnus;
							_vlastna_cast_kresponz;
							_vlastna_cast_1citanie;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_full(modlitba);
							if((_global_den.litobd == OBD_VELKONOCNE_I) || (_global_den.litobd == OBD_VELKONOCNE_II))
								_vlastna_cast_kresponz_ve;
							/* inak zostane cezrocne, ale bez pripony */

							break;
						}
						if(_global_jazyk == JAZYK_CZ){
							_global_svaty1.typslav = SLAV_SVIATOK;
							_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
						}
						else { /* na Slovensku */
							/* v roznavskej dieceze sviatok (hlavny patron) */
							_global_svaty1.typslav = SLAV_SPOMIENKA;
							_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
							_global_svaty1.typslav_lokal = LOKAL_SLAV_ROZNAVA_PATRON; /* 2006-02-03: pridanÈ */
						}
						mystrcpy(_global_svaty1.meno, text_MAJ_16[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_KNAZ);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 18:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_18[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 20:
					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_MAJ_20_2[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					else if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						/* 2006-09-12: pÙvodne bola æubovoæn· spomienka na Sv. Klementa Marie Hofbauera - od 29.8.1991 pam·tka
						else if(poradie_svaty == 2){
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						*/
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						/* _global_svaty1.typslav_lokal = LOKAL_SLAV_MORAVA_SPOMIENKA; */
						_global_svaty1.smer = 10;
						mystrcpy(_global_svaty1.meno, text_MAJ_20_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
						/*
						pocet = 2;
						_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty2.smer = 12;
						mystrcpy(_global_svaty2.meno, text_MAJ_20_2[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
						_global_svaty2.farba = LIT_FARBA_BIELA;
						*/
					}
					break;
				case 21: /* 2006-08-16: pridanÈ */
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_BRNO;
						_global_svaty1.typslav = SLAV_SVIATOK;
						mystrcpy(_global_svaty1.meno, text_MAJ_21[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 25:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 3){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_25_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_UCITEL_CIRKVI, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					pocet = 3;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_MAJ_25_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					_global_svaty3.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty3.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty3.meno, text_MAJ_25_3[_global_jazyk], MENO_SVIATKU);
					_global_svaty3.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA, MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					_global_svaty3.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 26:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_26[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_MAJ_27[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 31:
					/* na Slovensku sa sl·vi 2. j˙la */
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_full(modlitba);

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_hymnus;
							_vlastna_cast_1citanie;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_full(modlitba);

							break;
						}
						_global_svaty1.typslav = SLAV_SVIATOK;
						_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
						mystrcpy(_global_svaty1.meno, text_MAJ_31[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
			}; break; /* case MES_MAY */
		case MES_JUN:
			switch(den){
				case 1:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUN_01[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUN_02[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUN_03[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 5:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUN_05[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 6:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					if(_global_jazyk == JAZYK_CZ){
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						/* od 29.8.1991 pam·tka podæa ËeskÈho brevi·ra z r. 1995, ale novöie kalend·re uv·dzaj˙ nez·vazn˙ pam·tku */
					}
					else{
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10;
					}
					mystrcpy(_global_svaty1.meno, text_JUN_06[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 9:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUN_09[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 11:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */
						/* 2005-08-27: sviatok apoötola Barnab·öa - ûalmy a antifÛny zo dÚa - ale 
						 * len pre rannÈ chv·ly; preto vlastne to ignorujeme, nech sa napr. posv‰tnÈ ËÌtanie 
						 * alebo veöpery ber˙ z apoötolov - preto sme zapozn·mkovali nasledovnÈ priradenie:
						 * _global_opt2 = MODL_ZALMY_ZO_DNA; - ûalmy a antifÛny zo dÚa - ale len pre rannÈ chv·ly */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_benediktus;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_hymnus;
						_vlastna_cast_2citanie;

						/* 2008-02-22: doplnenÈ mcd; */
						_vlastna_cast_mcd_kcitresp_modl;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_magnifikat;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUN_11[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUN_13[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_UCITEL_CIRKVI, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 15:
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_PRAHA_KATEDRALA;
						mystrcpy(_global_svaty1.meno, text_JUN_15[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 16:
					if(_global_jazyk == JAZYK_SK){
						/* 2005-07-27: pridanÈ, je to spomienka len v roûÚavskej katedr·le */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_ROZNAVA_KATEDRALA; /* 2005-07-27: pridanÈ */
						mystrcpy(_global_svaty1.meno, text_JUN_16[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 19:
					if(_global_jazyk == JAZYK_SK){ /* 2006-09-12: odvetvenÈ */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_JUN_19[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					else if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10;
						/* pÙvodne to bolo ûe len v Ëb spomienka */
						mystrcpy(_global_svaty1.meno, text_JUN_19_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUN_21[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 22:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUN_22_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_JUN_22_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 24:
					//if(poradie_svaty == 1){
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* definovanie parametrov pre modlitbu */

						if((poradie_svaty == 1) &&
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_vlastna_cast_modlitba_prve_vesp;
						_set_zalmy_sviatok_duch_past(modlitba);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_1nedele_rch();

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						_vlastna_cast_mcd_ant_kcitresp_modl;
						
						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_duch_past(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					if(_global_jazyk == JAZYK_SK){
						_global_svaty1.typslav_lokal = LOKAL_SLAV_TRNAVA_PATRON; /* 2005-07-27: pridanÈ */
					}
					mystrcpy(_global_svaty1.meno, text_JUN_24[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 25:
					/* hoci slavnost narodenia sv. Jana Krstitela padla na nedelu, 
					 * slavi sa v nedelu, lebo ide o nedelu v obdobi cez rok, 
					 * ktora ma nizsiu prioritu,
					 * preto to, co tu bolo 
						if(_global_den.denvt == DEN_PONDELOK){
							sprintf(_anchor_head, "%02d%s_", den - 1, nazov_MES[mesiac - 1]);
							Log("  _anchor_head == %s\n", _anchor_head);
							Log("jumping to label_24_JUN...\n");
							goto label_24_JUN;
						}
					 * nema opodstatnenie; 
					 * 21/03/2000A.D.
					 */
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}

					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUN_27[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */

					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 2){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}

						pocet = 2;
						/* v trnavskej, banskobystrickej, roznavskej a nitrianskej dieceze */
						_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						_global_svaty2.typslav_lokal = LOKAL_SLAV_TT_BB_NR_RO; /* 2005-07-27: pridanÈ; 2006-02-03: opravenÈ, KE nie */
						mystrcpy(_global_svaty2.meno, text_JUN_27_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ);
						_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;
						/* nema vespery, lebo su 1. vespery zo sv. petra a pavla */

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUN_28[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 29:
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o slavnost,
						 * ktora ma takmer najvacsiu prioritu, a preto ma aj prve
						 * vespery - a vtedy by to normalne nefungovalo;
						 * nastavenie veci pre modlitbu by sa muselo diat
						 * v predoslom dni, co je neciste riesenie
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Peter a Pavol: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_vlastna_cast_modlitba_prve_vesp;
						_set_zalmy_sviatok_apostolov(modlitba);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						_vlastna_cast_mcd_ant_kcitresp_modl;
						
						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_apostolov(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					_global_svaty1.prik = PRIKAZANY_SVIATOK;
					mystrcpy(_global_svaty1.meno, text_JUN_29[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 30:
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUN_30[_global_jazyk], MENO_SVIATKU);
					/* hoci slavnost sv. Petra a Pavla padla na nedelu, 
					 * slavi sa v nedelu, lebo ide o nedelu v obdobi cez rok, 
					 * ktora ma nizsiu prioritu,
					 * preto to, co tu bolo 
					 * "if(_global_den.denvt == DEN_PONDELOK) goto label_29_JUN;"
					 * nema opodstatnenie; porov. r. 1997
					 * 21/03/2000A.D.
					 */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;
						_vlastna_cast_benediktus;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;
						_vlastna_cast_magnifikat;

						break;
					}
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */

					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 2){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						pocet = 2;
						_global_svaty2.typslav = SLAV_SVIATOK;
						_global_svaty2.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty2.typslav_lokal = LOKAL_SLAV_OLOMOUC;
						mystrcpy(_global_svaty2.meno, text_JUN_30_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ);
						_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
			}; break; /* case MES_JUN */
		case MES_JUL:
			switch(den){
				case 2:
					/* vo vöeobecnom kalend·ri sa sl·vi 31. m·ja */
					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							/* 2007-11-14: doplnenÈ invitatÛrium */
							modlitba = MODL_INVITATORIUM;
							_vlastna_cast_antifona_inv;

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_full(modlitba);

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_hymnus;
							_vlastna_cast_1citanie;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_full(modlitba);

							break;
						}
						_global_svaty1.typslav = SLAV_SVIATOK;
						_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
						mystrcpy(_global_svaty1.meno, text_MAJ_31[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_antifony_ako_na_ranne_chvaly;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_JUL_03[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						/* nema vespery, lebo su 1. vespery zo sv. cyrila a metoda */

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUL_04[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_SKUTKYMIL, MODL_SPOL_CAST_SV_ZENA_MANZ /* 2006-08-08: doplnenÈ */);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */

					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 2){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						pocet = 2;
						_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						_global_svaty2.typslav_lokal = LOKAL_SLAV_CECHY_SPOMIENKA;
						mystrcpy(_global_svaty2.meno, text_JUL_04_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
						_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 5:
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o slavnost,
						 * ktora ma takmer najvacsiu prioritu, a preto ma aj prve
						 * vespery - a vtedy by to normalne nefungovalo;
						 * nastavenie veci pre modlitbu by sa muselo diat
						 * v predoslom dni, co je neciste riesenie
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Cyril a Metod: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D. -- prevzate z Petra a Pavla, 23/03/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_slavnost_Cyrila_a_Metoda(modlitba);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						_set_zalmy_slavnost_Cyrila_a_Metoda(modlitba);
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						_vlastna_cast_mcd_ant_kcitresp_modl;
						
						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_slavnost_Cyrila_a_Metoda(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_JUL_05[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 6:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUL_06[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENICA, MODL_SPOL_CAST_PANNA);
						/* hoci slavnost sv. Cyrila a Metoda padla na nedelu, 
						 * slavi sa v nedelu, lebo ide o nedelu v obdobi cez rok, 
						 * ktora ma nizsiu prioritu,
						 * preto to, co tu bolo 
						 * "if(_global_den.denvt == DEN_PONDELOK) goto label_5_JUL;"
						 * nema opodstatnenie; porov. 1998; 21/03/2000A.D.
						 */
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 7:
					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_JUL_07[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_VYCH, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 11:
					/* kedysi bola iba spomienka, v EurÛpe sviatok; uû upravenÈ aj v CZ aj SK */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus; /* 2006-02-02: doplnenÈ; hymnus ako na veöpery */
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kresponz;
						_vlastna_cast_magnifikat;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_JUL_11[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUL_13[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 14:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUL_14[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL, MODL_SPOL_CAST_DUCH_PAST_KNAZ /* 2006-08-08: doplnenÈ */);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */

					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 2){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						pocet = 2;
						_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						_global_svaty2.typslav_lokal = LOKAL_SLAV_PLZEN_PATRON;
						mystrcpy(_global_svaty2.meno, text_JUL_14_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
						_global_svaty2.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 15:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUL_15[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 16:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUL_16[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */

					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 2){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						pocet = 2;
						_global_svaty2.typslav = SLAV_SVIATOK;
						_global_svaty2.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty2.typslav_lokal = LOKAL_SLAV_OSTRAVA_OPAVA;
						mystrcpy(_global_svaty2.meno, text_JUL_16_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ);
						_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 17:
					if(_global_jazyk == JAZYK_SK){
						/* v Nitrianskej dieceze sviatok - hlavni patroni */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_hymnus;
							_vlastna_cast_antifony;
							_vlastna_cast_kresponz;
							_vlastna_cast_benediktus;
							_vlastna_cast_prosby;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;
							_vlastna_cast_1citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_hymnus;
							_vlastna_cast_antifony;
							_vlastna_cast_magnifikat;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_NITRA_PATRON; /* 2005-08-04: pridanÈ */
						mystrcpy(_global_svaty1.meno, text_JUL_17_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_VIACERI);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					else if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_JUL_17_2[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_VIACERI);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUL_21[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 22:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUL_22[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_ZENA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					/* _global_svaty1.smer = 12; */
					/* zmena, na ktoru ma mailom zo dna Monday, July 23, 2001 11:40 AM upozornil 
					 * Marian Val·bek,SDB <marian.valabek@donbosco.sk>:
					 * "ProsÌm opravte Sv. Brigita je spolu so sv. KatarÌnou Sienskou a 
					 *  sv. TerÈziou Benediktou z KrÌza spolupatrÛnkou EurÛpy a teda je 
					 *  to v EurÛpe sviatok od 1999."
					 * 07/09/2001A.D.
					 *
					 * 2006-01-11: opravenÈ: do n·zvu pridanÈ ", spolupatrÛnky EurÛpy"
					 */
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUL_23[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 25:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_antifony;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_JUL_25[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 26:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUL_26[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_MANZ, MODL_SPOL_CAST_SV_ZENA_MANZ); 
						/* 2006-08-07: upravenÈ lebo ûili v manûelstve :) pridan· moûnosù aj pre sv. ûeny - 2006-08-19 */
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					/* kedysi pre CZ: _global_svaty1.typslav_lokal = LOKAL_SLAV_MORAVA_SPOMIENKA; */
					mystrcpy(_global_svaty1.meno, text_JUL_27[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_VIACERI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 29:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUL_29[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_ZENA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 30:
				/* 2004-08-14, duurko
				 * Sviatok Bl. Zdenky Schelingovej, panny a muËenice, ako 2. moznost.
				 * Upozornil Jan Kusenda <exonkuda@savba.sk>.
				 */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUL_30[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */

					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 2){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						pocet = 2;
						_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara - Slovensko */
						mystrcpy(_global_svaty2.meno, text_JUL_30_1[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENICA, MODL_SPOL_CAST_PANNA);
						_global_svaty2.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 31:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_JUL_31[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
			}; break; /* case MES_JUL */
		case MES_AUG:
			switch(den){
				case 1:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_01[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_02_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_AUG_02_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_04[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 5:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_05[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 6:
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o sviatok Pana,
						 * ktora ma velku prioritu, a preto ma aj - ak je nedela - prve
						 * vespery 
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Premenenie Pana: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D. -- prevzate z Petra a Pavla, 28/03/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_premenenie(modlitba);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_premenenie(modlitba); /* preto, lebo nespustame zaltar(); 28/03/2000A.D. */

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						_set_zalmy_premenenie(modlitba);

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_premenenie(modlitba);

						/* 2006-01-24: doplnenÈ modlitby cez deÚ */
						_vlastna_cast_mcd_ant_kcitresp_modl;
						
						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 5; /* sviatky Pana uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_AUG_06[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_07_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_AUG_07_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 8:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_08[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 9:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					/* _global_svaty1.smer = 12; */
					/* zmena, na ktoru ma mailom zo dna Monday, July 23, 2001 11:40 AM upozornil 
					 * Marian Val·bek,SDB <marian.valabek@donbosco.sk>:
					 * "ProsÌm opravte Sv. Brigita je spolu so sv. KatarÌnou Sienskou a 
					 *  sv. TerÈziou Benediktou z KrÌza spolupatrÛnkou EurÛpy a teda je 
					 *  to v EurÛpe sviatok od 1999."
					 * 26/09/2001A.D.
					 *
					 * 2006-01-11: opravenÈ, do n·zvu pridanÈ: ", spolupatrÛnky EurÛpy"
					 */
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_09[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_REHOLNIK, MODL_SPOL_CAST_MUCENICA);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 10:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_AUG_10[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 11:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_11[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA, MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;

				/* 2004-08-14, duurko
				 * Sviatok Sv. Jany Frantiöky de Chantal presunuty z 12. decembra na 12. augusta.
				 */
				case 12:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_12[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_REHOLNIK, MODL_SPOL_CAST_SV_ZENA_MANZ /* 2006-08-08: doplnenÈ */);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_13[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV, MODL_SPOL_CAST_DUCH_PAST_VIACERI);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 14:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						/* nema vespery, lebo su prve vespery nanebovzatia p. marie */
						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_14[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_MUCENIK);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 15:
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o sviatok Pana,
						 * ktora ma velku prioritu, a preto ma aj - ak je nedela - prve
						 * vespery 
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Premenenie Pana: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D. -- prevzate z Petra a Pavla, 28/03/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_vlastna_cast_modlitba_prve_vesp;
						_set_zalmy_sviatok_panien(modlitba);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_panien(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;

						/* 2006-02-07: doplnenÈ mcd */
						_vlastna_cast_mcd_ant_kcitresp_modl;
						
						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_panien(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					_global_svaty1.prik = PRIKAZANY_SVIATOK;
					mystrcpy(_global_svaty1.meno, text_AUG_15[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 16:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_16[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_MANZ); /* 2006-08-07: upravenÈ lebo ûil v manûelstve :) */
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 19:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_19[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 20:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_20[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_UCITEL_CIRKVI, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_21[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 22:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_22[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_23[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA, MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 24:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_AUG_24[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 25:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					/* 2006-09-11: pridanÈ */
					else if((_global_jazyk == JAZYK_CZ) && (poradie_svaty == 3)){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_25_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_VYCH, MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					if(_global_jazyk == JAZYK_CZ)
						pocet = 3;
					else
						pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_AUG_25_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_MANZ); /* 2006-08-07: upravenÈ lebo ûil v manûelstve :) */
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					if(_global_jazyk == JAZYK_CZ){
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						_global_svaty3.typslav = SLAV_LUB_SPOMIENKA;
						mystrcpy(_global_svaty3.meno, text_AUG_25_3[_global_jazyk], MENO_SVIATKU);
						_global_svaty3.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
						_global_svaty3.farba = LIT_FARBA_CERVENA;
					}
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_27[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_MANZ); /* 2006-08-19: upravenÈ, lebo ûila v manûelstve */
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_28[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 29:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_1nedele_rch(); /* 2006-09-05: doplnenÈ podæa brevi·ra, upozornil Medus */

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_AUG_29[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 30: /* 2005-10-17: pridanÈ */
					if(_global_jazyk == JAZYK_SK){ /* 2006-09-11: odvetvenÈ len pre Slovensko */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						_global_svaty1.smer = 11; /* hoci by malo byù 8 - mieste sviatky, dali sme 11, aby tam bol aj vöedn˝ deÚ - pre ostatnÈ diecÈzy */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_BA_TT; /* pÙvodne bolo LOKAL_SLAV_TRNAVA, upravenÈ 2007-08-31*/
						_global_svaty1.typslav = SLAV_SVIATOK; /* pÙvodne bolo SLAV_SPOMIENKA, upravenÈ 2007-08-31*/
						mystrcpy(_global_svaty1.meno, text_AUG_30[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				default:
					break;
			}; break; /* case MES_AUG */
		case MES_SEP:
			switch(den){
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_SEP_03[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 6:
					if(_global_jazyk == JAZYK_SK){ /* 2006-09-12: odvetvenÈ len pre Slovensko */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_KOSICE; /* 2005-08-22: pridanÈ */
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						mystrcpy(_global_svaty1.meno, text_SEP_06[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					if(_global_jazyk == JAZYK_SK){ /* 2006-09-12: odvetvenÈ pre Slovensko */
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					}
					else if(_global_jazyk == JAZYK_CZ){ /* 2006-09-12: odvetvenÈ pre »esko */
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					}
					mystrcpy(_global_svaty1.meno, text_SEP_07[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 8:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;
						_vlastna_cast_1citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);
						set_LOG_svsv;

						/* 2006-02-07: doplnenÈ mcd */
						_vlastna_cast_mcd_ant_kcitresp_modl;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_SEP_08[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 9:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_SEP_09[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 10:
					if(_global_jazyk == JAZYK_CZ){ /* 2006-09-12: odvetvenÈ len pre »esko */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_SEP_10[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_KNAZ);
						_global_svaty1.farba = LIT_FARBA_CERVENA;
					}
					break;
				case 12:
					if(_global_jazyk == JAZYK_SK){ /* 2006-09-12: odvetvenÈ len pre Slovensko */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_SEP_12[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_SEP_13[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 14:
					_global_svaty1.spolcast =
						_encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o sviatok Pana,
						 * ktora ma velku prioritu, a preto ma aj - ak je nedela - prve
						 * vespery 
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Povysenie sv. Kriza: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D. -- prevzate z Petra a Pavla, 28/03/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sv_kriz(modlitba);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sv_kriz(modlitba); /* preto, lebo nespustame zaltar(); 28/03/2000A.D. */

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sv_kriz(modlitba);

						/* 2006-02-07: doplnenÈ mcd;
						 *             ûalmy pre mcd s˙ zo dÚa, vyrieöenÈ pomocou ZALTAR_IBA_ZALMY_HYMNUS_MCD
						 */
						_vlastna_cast_mcd_ant_kcitresp_modl;
						
						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sv_kriz(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 5; /* sviatky Pana uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_SEP_14[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 15:
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					if(((poradie_svaty == 0) && (_global_jazyk == JAZYK_SK)) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o slavnost (2006-09-12: len na Slovensku),
						 * ktora ma takmer najvacsiu prioritu, a preto ma aj prve
						 * vespery - a vtedy by to normalne nefungovalo;
						 * nastavenie veci pre modlitbu by sa muselo diat
						 * v predoslom dni, co je neciste riesenie
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Sedembolestnej Panny Marie, patronky Slovenska: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D.; zobrate z 8.dec; 28/03/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_panien(modlitba);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);

						/* 2006-02-07: doplnenÈ mcd; */
						_vlastna_cast_mcd_ant_kcitresp_modl;
						
						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_panien(modlitba);

						if(poradie_svaty != 0) break;
					}
					if(_global_jazyk == JAZYK_SK){ /* 2006-09-12: odvetvenÈ pre Slovensko */
						_global_svaty1.typslav = SLAV_SLAVNOST;
						_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					}
					else if(_global_jazyk == JAZYK_CZ){ /* 2006-09-12: odvetvenÈ pre »esko */
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					}
					mystrcpy(_global_svaty1.meno, text_SEP_15[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-09-18: opravenÈ */
					break;
				case 16:
					if(_global_jazyk == JAZYK_SK){ /* 2006-09-12: odvetvenÈ len pre Slovensko */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_benediktus;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_magnifikat;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_SEP_16[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV, MODL_SPOL_CAST_DUCH_PAST_VIACERI);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					else if(_global_jazyk == JAZYK_CZ){ /* 2006-09-12: odvetvenÈ len pre »esko */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_benediktus;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_magnifikat;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_SEP_16_CZ[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENICA);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 17:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					if(_global_jazyk == JAZYK_SK){ /* 2006-09-12: odvetvenÈ len pre Slovensko */
						mystrcpy(_global_svaty1.meno, text_SEP_17[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					else if(_global_jazyk == JAZYK_CZ){ /* 2006-09-12: odvetvenÈ len pre »esko */
						if(poradie_svaty == 2){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						mystrcpy(_global_svaty1.meno, text_SEP_16[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV, MODL_SPOL_CAST_DUCH_PAST_VIACERI);
						_global_svaty1.farba = LIT_FARBA_CERVENA;

						pocet = 2;
						_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty2.meno, text_SEP_17[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
						_global_svaty2.farba = LIT_FARBA_BIELA;
					}
					break;
				case 19:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_SEP_19[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 20:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					/* 2006-09-12: pridanÈ */
					else if((_global_jazyk == JAZYK_CZ) && (poradie_svaty == 2)){
						/* definovanie parametrov pre modlitbu */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);
						/* 2005-08-22: Vöetko je zo spoloenej easti na v˝roeie posviacky chr·mu */
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_SEP_20[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */

					if(_global_jazyk == JAZYK_CZ){ /* 2006-09-12: pridanÈ */
						pocet = 2;
						_global_svaty2.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty2.typslav_lokal = LOKAL_SLAV_LITOMERICE;
						_global_svaty2.typslav = SLAV_SVIATOK;
						mystrcpy(_global_svaty2.meno, text_SEP_20_2[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty2.farba = LIT_FARBA_BIELA;
					}
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_SEP_21[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 22: /* 2005-10-13: pridanÈ */
					if(_global_jazyk == JAZYK_SK){ /* 2006-09-12: odvetvenÈ len pre Slovensko */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_NITRA;
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						mystrcpy(_global_svaty1.meno, text_SEP_22[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 23: /* 2004-09-23, pridane - pater Pio */
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						// _vlastna_cast_2citanie; // 2006-08-09: nem· zatiaæ vlastnÈ druhÈ ËÌtanie

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_SEP_23[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 24: /* 2005-10-13: pridanÈ */
					if(_global_jazyk == JAZYK_SK){ /* 2006-09-12: odvetvenÈ len pre Slovensko */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_BYSTRICA;
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						mystrcpy(_global_svaty1.meno, text_SEP_24[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 26:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_SEP_26[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_SEP_27[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					mystrcpy(_global_svaty1.meno, text_SEP_28[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */

					if(_global_jazyk == JAZYK_SK){ /* 2006-09-12: odvetvenÈ len pre Slovensko */
						/* na Slovensku len æubovoæn· spomienka */
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */

						if(poradie_svaty == 2){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						pocet = 2;
						_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty2.meno, text_SEP_28_2[_global_jazyk], MENO_SVIATKU);
						_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
						_global_svaty2.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					else if(_global_jazyk == JAZYK_CZ){ /* 2006-09-12: odvetvenÈ len pre »esko */
						/* v »ech·ch sl·vnosù */
						_global_svaty1.typslav = SLAV_SLAVNOST;
						_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					}
					break;
				case 29:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_archanjelov(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						_set_zalmy_archanjelov(modlitba);

						/* 2006-02-07: doplnenÈ mcd; */
						_vlastna_cast_mcd_ant_kcitresp_modl;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_archanjelov(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_SEP_29[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 30:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_SEP_30[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
			}; break; /* case MES_SEP */
		case MES_OCT:
			switch(den){
				case 1:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_OKT_01[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_anjelov_strazcov(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						/* 2006-02-07: doplnenÈ mcd; */
						_vlastna_cast_mcd_kcitresp_modl;
						
						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_anjelov_strazcov(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_OKT_02[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_OKT_04[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 6:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_OKT_06[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_OKT_07[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 9:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_OKT_09_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */

					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_OKT_09_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_SKUTKYMIL);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 12:
					if(_global_jazyk == JAZYK_CZ){ /* 2006-09-13: odvetvenÈ len pre »esko */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_benediktus;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_magnifikat;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA /* SLAV_SPOMIENKA opravenÈ 2006-10-12 */;
						_global_svaty1.smer = 12; /* 12 = lubovolne spomienky podla vseobecneho kalendara */ /* 10 = povinne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_OKT_12[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
						_global_svaty1.farba = LIT_FARBA_BIELA;
					}
					break;
				case 14:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_OKT_14[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 15:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_OKT_15[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 16:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_OKT_16_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA, MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */

					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_OKT_16_2[_global_jazyk], MENO_SVIATKU);
					if(_global_jazyk == JAZYK_CZ){ /* 2006-09-19: odvetvenÈ pre »esko */
						_global_svaty2.typslav_lokal = LOKAL_SLAV_SLEZSKO_SVATEK;
					}
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_SKUTKYMIL, MODL_SPOL_CAST_SV_ZENA_REHOLNIK, MODL_SPOL_CAST_SV_ZENA_MANZ /* 2006-08-07: doplnenÈ */);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 17:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_OKT_17[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 18:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						/* 2006-02-07: doplnenÈ mcd; */
						_vlastna_cast_mcd_kcitresp_modl;

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_OKT_18[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 19:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_OKT_19_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV, MODL_SPOL_CAST_DUCH_PAST_VIACERI);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */

					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_OKT_19_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_OKT_23[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 24:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_OKT_24[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 25: /* 2005-10-13: pridanÈ */
					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_SPIS;
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						mystrcpy(_global_svaty1.meno, text_OKT_25[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					else if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_KONSEKR_KOSTOLY_CZ;
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						mystrcpy(_global_svaty1.meno, text_OKT_26[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 26: /* 2006-02-03: pridanÈ */
					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_KONSEKR_KOSTOLY;
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						mystrcpy(_global_svaty1.meno, text_OKT_26[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 27: /* 2005-10-13: pridanÈ */
					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_ROZNAVA;
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						mystrcpy(_global_svaty1.meno, text_OKT_27[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_OKT_28[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 30: /* 2006-09-13: pridanÈ */
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_HRADEC_KRALOVE;
						_global_svaty1.typslav = SLAV_SVIATOK;
						mystrcpy(_global_svaty1.meno, text_OKT_30[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 31: /* 2006-09-19: pridanÈ */
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_benediktus;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_magnifikat;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_OKT_31[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
						_global_svaty1.farba = LIT_FARBA_BIELA;
					}
					break;
			}; break; /* case MES_OCT */
		case MES_NOV:
			switch(den){
				case 1:
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_NEBRAT);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o sviatok Pana,
						 * ktora ma velku prioritu, a preto ma aj - ak je nedela - prve
						 * vespery 
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Premenenie Pana: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D. -- prevzate z Petra a Pavla, 29/03/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_vsetkych_svatych(modlitba);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_vsetkych_svatych(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						_set_zalmy_vsetkych_svatych(modlitba);

						/* 2006-02-07: doplnenÈ mcd; */
						_vlastna_cast_mcd_ant_kcitresp_modl;
						
						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_vsetkych_svatych(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					_global_svaty1.prik = PRIKAZANY_SVIATOK;
					mystrcpy(_global_svaty1.meno, text_NOV_01[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 2:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 3; /* vsetkych vernych zosnulych */
					mystrcpy(_global_svaty1.meno, text_NOV_02[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_ZA_ZOSNULYCH);
					_global_svaty1.farba = LIT_FARBA_FIALOVA; /* 2006-08-19: pridanÈ */
					break;
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_NOV_03[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_NOV_04[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 5:
					if(_global_jazyk == JAZYK_SK){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_TT_BB_KE_NR_RO; /* 2006-02-03: pridanÈ */
						mystrcpy(_global_svaty1.meno, text_NOV_05[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_MUZ);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 9:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */
						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer =  5; /* sviatky Pana uvedene vo vseobecnom kalendari */
						/* povodne: 7; sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
						/* lenze 9. NOV 1997 mal tento sviatok prednost pred 32. nedelou v ocr, takze smer == 5 */
					mystrcpy(_global_svaty1.meno, text_NOV_09[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 10:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_NOV_10[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 11:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;
						/* hymnus ako na veöpery */
						sprintf(_anchor, "%s%c%s", _anchor_head, pismenko_modlitby(MODL_VESPERY), ANCHOR_HYMNUS);
						_set_hymnus(modlitba, _file, _anchor);

						modlitba = MODL_VESPERY;
						_vlastna_cast_full_okrem_prosieb(modlitba);

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_NOV_11[_global_jazyk], MENO_SVIATKU);
					if(_global_jazyk == JAZYK_SK){
						_global_svaty1.typslav_lokal = LOKAL_SLAV_SPIS_PATRON; /* 2005-10-28: pridanÈ */
					}
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 12:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_NOV_12[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 13:
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_NOV_13[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 15:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_NOV_15[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 16:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_NOV_16_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_MANZ /* 2006-08-07: doplnenÈ */, MODL_SPOL_CAST_SV_ZENA_SKUTKYMIL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */

					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_NOV_16_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA, MODL_SPOL_CAST_SV_ZENA_REHOLNIK);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 17:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_NOV_17[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_SV_ZENA_REHOLNIK, MODL_SPOL_CAST_SV_ZENA_MANZ /* 2006-08-08: doplnenÈ */, MODL_SPOL_CAST_SV_ZENA_SKUTKYMIL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 18:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_NOV_18[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 20: /* 2005-10-28: pridanÈ */
					if(_global_jazyk == JAZYK_SK){ /* 2006-09-13: odvetvenÈ pre Slovensko */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* 2005-08-22: Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_NITRA;
						_global_svaty1.typslav = SLAV_SPOMIENKA;
						mystrcpy(_global_svaty1.meno, text_NOV_20[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_NOV_21[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 22:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_NOV_22[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENICA, MODL_SPOL_CAST_PANNA);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					else if(poradie_svaty == 2){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_NOV_23_1[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */

					pocet = 2;
					_global_svaty2.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty2.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty2.meno, text_NOV_23_2[_global_jazyk], MENO_SVIATKU);
					_global_svaty2.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_SV_MUZ_REHOLNIK);
					_global_svaty2.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 24:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_NOV_24[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 25:
					if(_global_jazyk == JAZYK_SK){ /* 2006-09-13: odvetvenÈ pre Slovensko */
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */

							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_NOV_25[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA, MODL_SPOL_CAST_MUCENIK);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 30:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_NOV_30[_global_jazyk], MENO_SVIATKU);
					if(_global_jazyk == JAZYK_SK){
						_global_svaty1.typslav_lokal = LOKAL_SLAV_KOSICE_PATRON; /* 2006-02-03: pridanÈ */
					}
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
			}; break; /* case MES_NOV */
		case MES_DEC:;
			switch(den){
				case 1: /* 2006-09-14: pridanÈ */
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);

							modlitba = MODL_RANNE_CHVALY;
							_vlastna_cast_modlitba;

							modlitba = MODL_POSV_CITANIE;
							_vlastna_cast_modlitba;
							_vlastna_cast_2citanie;

							modlitba = MODL_VESPERY;
							_vlastna_cast_modlitba;

							break;
						}
						_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
						_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
						mystrcpy(_global_svaty1.meno, text_DEC_01[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK, MODL_SPOL_CAST_DUCH_PAST_KNAZ);
						_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 2: /* 2006-09-14: pridanÈ */
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_PLZEN;
						_global_svaty1.typslav = SLAV_SVIATOK;
						mystrcpy(_global_svaty1.meno, text_DEC_02[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 3:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_DEC_03[_global_jazyk], MENO_SVIATKU);
					if(_global_jazyk == JAZYK_SK){ /* 2006-09-19: odvetvenÈ len pre Slovensko */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_BYSTRICA_PATRON; /* 2006-02-03: pridanÈ */
					}
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 4:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_DEC_04[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 6:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_DEC_06[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 7:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_hymnus;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_DEC_07[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 8:
label_8_DEC:
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
					if((poradie_svaty == 0) || (poradie_svaty == 1)){
						/* preto 0, ze aj ked nie je svaty urceny, ide o slavnost,
						 * ktora ma takmer najvacsiu prioritu, a preto ma aj prve
						 * vespery - a vtedy by to normalne nefungovalo;
						 * nastavenie veci pre modlitbu by sa muselo diat
						 * v predoslom dni, co je neciste riesenie
						 */
						/* definovanie parametrov pre modlitbu */

						sc = _decode_spol_cast(_global_svaty1.spolcast);
						Log("Neposkvrnene pocatie Panny Marie: sc: {%s, %s, %s}, svaty == %d\n\n", nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3), poradie_svaty);

						if(/*(poradie_svaty == 1) && */ // 23/02/2000A.D.
						  (query_type != PRM_DETAILY))
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_PRVE_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_panien(modlitba);

						/* 2007-11-14: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_full(modlitba);

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_full(modlitba);
						/* 2005-10-24: moûno bude potrebnÈ nastaviù ûalmy? */
						_set_zalmy_sviatok_marie(modlitba);
						/* 2006-02-03: celkom dobr· intuÌcia :) ûalmy nastavenÈ */

						/* 2006-02-07: doplnenÈ mcd; */
						_vlastna_cast_mcd_ant_kcitresp_modl;
						
						/* 2006-02-04: ak je modlitba cez deÚ na sl·vnosù, tak by sa mali pouûiù ûalmy z doplnkovej psalmÛdie */
						if(_global_den.denvt != DEN_NEDELA) {
							_set_zalm_cez_den_doplnkova_psalmodia();
						}
						else {
							_set_zalmy_1nedele_mcd();
						}

						modlitba = MODL_VESPERY;
						_vlastna_cast_full(modlitba);
						_set_zalmy_sviatok_panien(modlitba);

						if(poradie_svaty != 0) break;
					}
					_global_svaty1.typslav = SLAV_SLAVNOST;
					_global_svaty1.smer = 3; /* slavnosti Pana, preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					_global_svaty1.prik = PRIKAZANY_SVIATOK;
					mystrcpy(_global_svaty1.meno, text_DEC_08[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 9:
					if(_global_den.denvt == DEN_PONDELOK){
						/* 05/04/2000A.D. -- bolo to tu zle */
						/* t.j. slavnost neposkvrneneho pocatia P. Marie padla na nedelu */
						sprintf(_anchor_head, "%02d%s_", den - 1, nazov_MES[mesiac - 1]);
						Log("  _anchor_head == %s\n", _anchor_head);
						Log("jumping to label_8_DEC...\n");
						goto label_8_DEC;
					}
					break;
				case 11:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_DEC_11[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;

				/* 2004-08-14, duurko
				 * Sviatok Sv. Jany Frantiöky de Chantal presunuty z 12. decembra na 12. augusta.
				 */

				case 13:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_DEC_13[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENICA, MODL_SPOL_CAST_PANNA);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 14:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_SPOMIENKA;
					_global_svaty1.smer = 10; /* povinne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_DEC_14[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 21:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_DEC_21[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ, MODL_SPOL_CAST_UCITEL_CIRKVI);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 22: /* 2006-09-14: pridanÈ */
					if(_global_jazyk == JAZYK_CZ){
						if(poradie_svaty == 1){
							/* definovanie parametrov pre modlitbu */
							if(query_type != PRM_DETAILY)
								set_spolocna_cast(sc, poradie_svaty);
							break;
							/* Vöetko je zo spoloËnej Ëasti na v˝roËie posviacky chr·mu */
						}
						_global_svaty1.smer = 11; /* mieste povinne spomienky podla vseobecneho kalendara */
						_global_svaty1.typslav_lokal = LOKAL_SLAV_CESKE_BUDEJOVICE;
						_global_svaty1.typslav = SLAV_SVIATOK;
						mystrcpy(_global_svaty1.meno, text_DEC_22[_global_jazyk], MENO_SVIATKU);
						_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_POSVIACKA_CHRAMU);
						_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					}
					break;
				case 23:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_DEC_23[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_KNAZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 26:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-13: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_benediktus;
						//_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE; /* 2006-02-04: doplnenÈ */
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;
						_vlastna_cast_modlitba;

						/* modlitba cez deÚ, pridanÈ 2006-02-05 */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* vespery -- vsetko je z oktavy narodenia Pana */
						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_DEC_26[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_MUCENIK);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 27:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-13: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_benediktus;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE; /* 2006-02-04: doplnenÈ */
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						/* _vlastna_cast_kresponz; - zo sviatkov apoötolov */
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;
						_vlastna_cast_modlitba;
						_set_zalmy_sviatok_jana_ap(modlitba);

						/* modlitba cez deÚ, pridanÈ 2006-02-05 */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* vespery -- vsetko je z oktavy narodenia Pana */
						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_DEC_27[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_APOSTOL);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
				case 28:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						/* 2007-11-13: doplnenÈ invitatÛrium */
						modlitba = MODL_INVITATORIUM;
						_vlastna_cast_antifona_inv;

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_benediktus;
						_vlastna_cast_prosby;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE; /* 2006-02-04: doplnenÈ */
						_vlastna_cast_hymnus;
						_vlastna_cast_antifony;
						_vlastna_cast_kresponz;
						_vlastna_cast_1citanie;
						_vlastna_cast_2citanie;
						_vlastna_cast_modlitba;

						/* modlitba cez deÚ, pridanÈ 2006-02-05 */
						modlitba = MODL_PREDPOLUDNIM;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_NAPOLUDNIE;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						modlitba = MODL_POPOLUDNI;
						_vlastna_cast_kcitanie;
						_vlastna_cast_kresponz;
						_vlastna_cast_modlitba;

						/* vespery -- vsetko je z oktavy narodenia Pana */
						break;
					}
					_global_svaty1.typslav = SLAV_SVIATOK;
					_global_svaty1.smer = 7; /* sviatky preblahoslavenej Panny Marie a svatych, uvedene vo vseobecnom kalendari */
					mystrcpy(_global_svaty1.meno, text_DEC_28[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_VIAC_MUCENIKOV);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 29:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						modlitba = MODL_VESPERY;
						_vlastna_cast_magnifikat;
						_vlastna_cast_modlitba;

						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_DEC_29[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_BISKUP, MODL_SPOL_CAST_MUCENIK);
					_global_svaty1.farba = LIT_FARBA_CERVENA; /* 2006-08-19: pridanÈ */
					break;
				case 31:
					if(poradie_svaty == 1){
						/* definovanie parametrov pre modlitbu */

						if(query_type != PRM_DETAILY)
							set_spolocna_cast(sc, poradie_svaty);

						modlitba = MODL_RANNE_CHVALY;
						_vlastna_cast_benediktus;
						_vlastna_cast_modlitba;

						modlitba = MODL_POSV_CITANIE;
						_vlastna_cast_modlitba;
						_vlastna_cast_2citanie;

						/* nema vespery, lebo uz su prve vespery slavnosti bohorodicky panny marie */
						break;
					}
					_global_svaty1.typslav = SLAV_LUB_SPOMIENKA;
					_global_svaty1.smer = 12; /* lubovolne spomienky podla vseobecneho kalendara */
					mystrcpy(_global_svaty1.meno, text_DEC_31[_global_jazyk], MENO_SVIATKU);
					_global_svaty1.spolcast = _encode_spol_cast(MODL_SPOL_CAST_DUCH_PAST_PAPEZ);
					_global_svaty1.farba = LIT_FARBA_BIELA; /* 2006-08-19: pridanÈ */
					break;
			}; break; /* case MES_DEC */
	}/* switch(mesiac - 1) */
	Log("Koniec veækÈho switch()-u podæa mesiacov a dnÌ.\n");
	LOG_ciara_sv;

	/* 10/03/2000A.D.: dorobena pasaz pre spomienku neposkvrneneho srdca panny marie */

/* 2005-08-25: PridanÈ vlastnÈ druhÈ ËÌtanie na posv‰tnÈ ËÌtanie */
#define _srdca_pm_2cit {\
	sprintf(_anchor, "%s_%c%s", ANCHOR_SRDCA_PM, pismenko_modlitby(modlitba), ANCHOR_CITANIE2);\
	_set_citanie2(modlitba, _file, _anchor);\
	set_LOG_litobd;\
}
	if((_global_den.denvr == (_global_r._ZOSLANIE_DUCHA_SV.denvr + 20)) && 
		(_global_svaty1.smer >= 10)){
		/* neposkvrneneho srdca panny marie; 10/03/2000A.D.;
		 * vtedy som aj napisal tuto vysvetlujucu poznamku:
		       "berie sa len v takom pripade, ked to nekoliduje 
		        s inou povinnou spomienkou alebo slavenim,
		        co ma vyssiu prioritu (smer <= 10)"
		 * kedze vsak som si uvedomil, ze bolo treba nastavit smer=10,
		 * tu treba dat opravenu poznamku:
		       "berie sa v takom pripade, ked nie je slavenie s vyssou prioritou,
			    teda smer < 10"
		 * 2003-06-30a.D.
		 */
		Log(" neposkvrneneho srdca panny marie: \n");
		Log(" ...berie sa len v takom pripade, ked to nekoliduje\n");
		Log(" ...so slavenim, co ma vyssiu prioritu (smer < 10)\n");
		/* 04/07/2000A.D.: vypisanie logu, uprava */
		poradie_svaty = 1;
		if(poradie_svaty == 1){
			/* definovanie parametrov pre modlitbu */

			if(query_type != PRM_DETAILY)
			set_spolocna_cast(sc, poradie_svaty);
			/* ZNOVUNASTAVENIE_POPISU_NA_DUMMY, 2003-06-30 */
			Log("vo funkcii sviatky_svatych() spustam set_popis_dummy(); - kvoli spomienke neposkvrneneho srdca panny marie...\n");
			set_popis_dummy();
			Log("set_popis_dummy() skoncila.\n");

			mystrcpy(_file, FILE_SRDCA_PM, MAX_STR_AF_FILE);
			mystrcpy(_anchor, ANCHOR_SRDCA_PM, MAX_STR_AF_ANCHOR);
			mystrcpy(_anchor_vlastne_slavenie, ANCHOR_SRDCA_PM, MAX_STR_AF_ANCHOR); /* 2007-11-14: pridanÈ */
			Log("  ide o spomienku srdca panny marie: _file = `%s', _anchor = %s...\n", _file, _anchor);

			modlitba = MODL_RANNE_CHVALY;
			_vlastne_slavenie_benediktus(_anchor_vlastne_slavenie);
			_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
			/* 2005-08-25: PridanÈ */
			modlitba = MODL_POSV_CITANIE;
			_srdca_pm_2cit;
			_vlastne_slavenie_modlitba(_anchor_vlastne_slavenie);
		}
		_global_svaty1.typslav = SLAV_SPOMIENKA;
		/* 2003-06-30: kedysi tu bolo 11: "miestne povinne spomienky podla vseobecneho kalendara"
		 * zmenil som to na 10 */
		_global_svaty1.smer = 10; 
		/* vysvetlujuca poznamka z r. 2000: "zrejme pre Slovensko je tato lubovolna 
		 * spomienka povinna; aby sa nebila s inou spomienkou, dal som tam 
		 * smer == 11; 10/03/2000A.D.;" -- zmenene 2003-06-30
		 * porov. pasaz venovanu srdcu pm vo funkcii breviar.cpp::_rozbor_dna()
		 */
		mystrcpy(_global_svaty1.meno, "NepoökvrnenÈho Srdca prebl. Panny M·rie", MENO_SVIATKU);
		_global_svaty1.spolcast =
			_encode_spol_cast(MODL_SPOL_CAST_PANNA_MARIA);
	}/* srdca panny marie */

	if(_global_svaty1.typslav == SLAV_NEURCENE){
		Log("neurcene slavenie, t.j. pocet = 0\n");
		pocet = 0;
	}
	else{
		/* 2006-02-06: obohaten˝ debug v˝pis */
		Log("sl·venie je urËenÈ, poËet == %d\n", pocet);
		Log("\tötrukt˙ra sc == ({%s, %s, %s}) -- begin\n",
			nazov_spolc(sc.a1), nazov_spolc(sc.a2), nazov_spolc(sc.a3));

		_global_svaty1.den = den;
		_global_svaty1.mesiac = mesiac;
		Log("  %d. %d: %s (typslav = %d) [smer = %d]\n", _global_svaty1.den,	_global_svaty1.mesiac, _global_svaty1.meno,	_global_svaty1.typslav, _global_svaty1.smer);
#ifdef DETAIL_LOG_SVATY
		Log(_global_svaty1);
#endif
		/* mozno je druha lubovolna spomienka */
		if(pocet > 1){
			_global_svaty2.den = den;
			_global_svaty2.mesiac = mesiac;
			Log("  %d. %d: %s (typslav = %d) [smer = %d]\n", _global_svaty2.den,	_global_svaty2.mesiac, _global_svaty2.meno, _global_svaty2.typslav, _global_svaty2.smer);
#ifdef DETAIL_LOG_SVATY
			Log(_global_svaty2);
#endif
			/* este dalsi */
			if(pocet > 2){
				_global_svaty3.den = den;
				_global_svaty3.mesiac = mesiac;
				Log("  %d. %d: %s (typslav = %d) [smer = %d]\n", _global_svaty3.den,	_global_svaty3.mesiac, _global_svaty3.meno,	_global_svaty3.typslav, _global_svaty3.smer);
#ifdef DETAIL_LOG_SVATY
				Log(_global_svaty3);
#endif
			}
		}
	}
	Log("-- sviatky_svatych(%d, %d) -- koniec (returning %d)\n",
		den, mesiac, pocet);
	return pocet;
}/* sviatky_svatych(); -- 3 vstupy */

short int sviatky_svatych(short int den, short int mesiac){
	short int ret;
	Log("-- sviatky_svatych(%d, %d) -- spustam bez tretieho parametra\n", den, mesiac);
	Log("   (poradie_svaty == 0)\n");
	ret = sviatky_svatych(den, mesiac, 0);
	Log("-- sviatky_svatych(%d, %d) -- spustene bez tretieho parametra, vysledok (pocet svatych) == %d\n", den, mesiac, ret);
	return ret;
}/* sviatky_svatych(); -- 2 vstupy */

short int sviatky_svatych(short int den, short int mesiac, short int poradie_svaty, short int druhykrat){
	short int ret;
	Log("-- sviatky_svatych(%d, %d, %d) -- spustam druhykrat\n", den, mesiac, poradie_svaty);
	if(druhykrat != 2){
		Log("   zle spustena, nie s 4. parametrom == 2\n");
		Log("-- sviatky_svatych(%d, %d) -- failure. Nespustila sa.\n");
		return 5;
	}

	Log("_global_svaty[1,2,3] som nemenil, lebo poradie_svaty == %d\n", poradie_svaty);
	Log("teraz priradim do _global_den vsetko z _global_svaty%d...\n", poradie_svaty);
	Log("    (tato cast bola povodne v sviatky_svatych s 3 vstupmi, ale teraz je tu)\n");
	switch(poradie_svaty){
		case 1: _global_den = _global_svaty1; break;
		case 2: _global_den = _global_svaty2; break;
		case 3: _global_den = _global_svaty3; break;
		default: /* sem by sa to nemalo dostat */
			Log("--Error: switch(poradie_svaty) nezabralo pre 1, 2, 3...\n"); break;
	}/* switch(); */
	Log("takze _global_den teraz:\n");
	Log(_global_den);
	/*
	LOG_ciara_sv; Log("_global_svaty1: \n"); Log(_global_svaty1);
	LOG_ciara_sv; Log("_global_svaty2: \n"); Log(_global_svaty2);
	LOG_ciara_sv; Log("_global_svaty3: \n"); Log(_global_svaty3);
	*/

	/* az teraz, ked je v _global_den (pri druhom volani fcie)
	 * spravna hodnota z _global_svaty[1,2,3], mozem urobit toto
	 * priradenie do sc
	 */
	_struct_sc sc = _decode_spol_cast(_global_den.spolcast);

	/* 2006-02-06: doplnen˝ debug v˝pis */
	Log("a hned nastavujem _global_opt3 (ak je neurËenÈ: je teraz %d) na sc.a1):\n", _global_opt3);
	/* ak opt3 je MODL_SPOL_CAST_NEURCENA, tak ju urcime podla
	 * 1. spolocnej casti */
	if(_global_opt3 == MODL_SPOL_CAST_NEURCENA){
		_global_opt3 = sc.a1;
		Log("\tsetting _global_opt3 to sc.a1 == %d\n", sc.a1);
	}
	else {
		Log("\tnie je potrebnÈ modifikovaù, lebo uû je nastaven· (hoci sc.a1 == %d)\n", sc.a1);
	}
	ret = sviatky_svatych(den, mesiac, poradie_svaty);
	Log("-- sviatky_svatych(%d, %d) -- spustene druhykrat, vysledok (pocet svatych) == %d\n", den, mesiac, ret);
	return ret;
}/* sviatky_svatych(); -- 4 vstupy; posledny == 2 */

