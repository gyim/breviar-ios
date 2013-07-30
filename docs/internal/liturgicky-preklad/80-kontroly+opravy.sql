select *
from biblia
where vers = 1
and nvg is not null
and (lc_id is null and lh_id is null)
and spis not in ('Z')
and _0 < 60

select *
from biblia
where vers = 1
and nvg is null
and (lc_id is not null or lh_id is not null)

-- update biblia set lh_id = null where spis = 'Tob' and vers = 1 and k = 3 and v = 13
-- update biblia set lh_id = null where id in (2419, 2420) -- Ex 3,21-22
-- update biblia set lh_id = 'POST1_cCIT1_0SO' where spis = 'Ex' and vers = 1 and k = 3 and v between 1 and 20
-- update biblia set nvg = 'Vdove a_sirote neublÌûite! ' where spis = 'Ex' and vers = 1 and k = 22 and v = 21
-- update biblia set nvg = 'Ak ich budete tr·più, bud˙ volaù ku mne a_ja budem poËuù ich n·rek; ' where spis = 'Ex' and vers = 1 and k = 22 and v = 22
-- update biblia set nvg = 'Mojûiö [...] vËasr·no vstal a vyst˙pil na vrch Sinaj, ako mu prik·zal P·n; v ruk·ch mal dve kamennÈ tabule.' where spis = 'Ex' and vers = 1 and k = 34 and v = 4
-- update biblia set lh_id = 'POST1_cCIT1_1UT' where spis = 'Ex' and vers = 1 and k = 7 and v between 1 and 25
-- update biblia set lh_id = 'POST1_cCIT1_2PI' where spis = 'Ex' and vers = 1 and k = 20 and v between 18 and 21
-- update biblia set nvg = null where id in (4502, 4503, 4504) -- Lv 8,22-23
-- update biblia set nvg = 'Potom ¡ron zdvihol ruky smerom k_æudu a_poûehnal ho. Tak zakonËil obetu za hriech, z·paln˙ a_pokojn˙ obetu, a_zost˙pil dolu. ' where spis = 'Lv' and vers = 1 and k = 9 and v = 22
-- update biblia set nvg = 'Mojûiö a_¡ron voöli do st·nku stretnutia a_keÔ potom vyöli, poûehnali æud. Vtom sa zjavila vöetkÈmu æudu P·nova veleba: ' where spis = 'Lv' and vers = 1 and k = 9 and v = 23
-- update biblia set nvg = 'vyöæahol oheÚ od P·na a_str·vil z·paln˙ obetu i_tuk, Ëo boli na olt·ri. KeÔ to z·stupy videli, jasali a_vrhali sa na tv·r. ' where spis = 'Lv' and vers = 1 and k = 9 and v = 24
-- update biblia set lc_id = 1523 where spis = 'Nm' and vers = 1 and k = 14 and v between 26 and 30 -- hoci je uvedenÈ len po v. 29, predsa je tam aj NVg v. 30
-- update biblia set lh_id = '_1STRr_CIT' where spis = 'Tob' and vers = 1 and k = 4 and v = 14
-- update biblia set nvg = '[...] (NVg 4,15) Daj pozor na to, Ëo robÌö, buÔ rozumn˝ vo vöetk˝ch svojich reËiach. [...]' where spis = 'Tob' and vers = 1 and k = 4 and v = 14
-- update biblia set nvg = '»o sa nep·Ëi tebe, nerob inÈmu. [...]' where spis = 'Tob' and vers = 1 and k = 4 and v = 15
-- update biblia set nvg = 'O_svoj chlieb sa deæ s_hladn˝m a_o_svoje öaty s_nah˝m. Z_toho, Ëoho m·ö hojnosù, daj n˙dznym. [...]' where spis = 'Tob' and vers = 1 and k = 4 and v = 16
-- update biblia set nvg = 'DobroreË Bohu v_kaûdom Ëase a_pros ho, aby riadil tvoje kroky a_usmerÚoval tvoje z·mery. [...]' where spis = 'Tob' and vers = 1 and k = 4 and v = 19
-- update biblia set nvg = null where spis = 'Iz' and vers = 1 and k = 16 and v = 6
-- update biblia set lh_id = null where spis = 'Iz' and vers = 1 and k = 44 and v = 20
-- update biblia set lh_id = 'POST1_2SOCIT' where spis = 'Iz' and vers = 1 and k = 44 and v between 21 and 22
-- update biblia set lh_id = 'VIAN1_3CIT31' where spis = 'Iz' and vers = 1 and k = 65 and v = 1
-- update biblia set nvg = 'Tr·va uschne a kvet odpadne,_* / keÔ ho ovanie P·nov dych. / Naozaj je æud ako tr·va:_Ü ' where spis = 'Iz' and vers = 1 and k = 40 and v = 7
-- update biblia set nvg = 'Tr·va uschne, kvet odpadne,_* / ale slovo n·öho Boha trv· naveky.' where spis = 'Iz' and vers = 1 and k = 40 and v = 8
-- update biblia set nvg = 'Vyst˙p na vysok˝ vrch, ty, Ëo hl·saö radostn˙ zvesù Sionu! Zodvihni mocne svoj hlas, ty, Ëo hl·saö radostn˙ zvesù Jeruzalemu! Zodvihni, neboj sa, povedz judejsk˝m mest·m: Hæa, v·ö Boh! ' where spis = 'Iz' and vers = 1 and k = 40 and v = 9
-- update biblia set nvg = null where spis = 'Mud' and vers = 1 and k = 18 and v = 5
-- update biblia set nvg = 'O tej noci naöi otcovia uû vopred vedeli, aby s istotou poznali, ak˝m prÌsæubom uverili, a boli dobrej mysle. ' where spis = 'Mud' and vers = 1 and k = 18 and v = 6
-- update biblia set nvg = 'tvoje vöemoh˙ce slovo zoskoËilo z neba, z kr·æovskÈho trÛnu, ako tvrd˝ bojovnÌk doprostred zeme ods˙denej na skazu. ' where spis = 'Mud' and vers = 1 and k = 18 and v = 15
-- update biblia set nvg = 'Nieslo tvoj nezvratn˝ rozkaz ako ostr˝ meË, zastalo a vöetko naplnilo smrùou; st·lo na zemi a siahalo aû po nebo.' where spis = 'Mud' and vers = 1 and k = 18 and v = 16
-- update biblia set lh_id = null where spis = 'Tob' and vers = 1 and k = 13 and v between 17 and 18
-- update biblia set nvg = 'KeÔ si sa modlil ty a S·ra, ja som predn·öal slov· vaöej modlitby pred jasnosù P·novej tv·re. A keÔ si pochov·val m‡tvych, takisto. ' where spis = 'Tob' and vers = 1 and k = 12 and v = 12
-- update biblia set nvg = 'A pretoûe si nev·hal vstaù a zanechaù jedlo a öiel si pochovaù m‡tveho, bol som poslan˝ k tebe sk˙öaù ùa. ' where spis = 'Tob' and vers = 1 and k = 12 and v = 13
-- update biblia set lh_id = 'OCR9SOc_CIT1' where spis = 'Job' and vers = 1 and k = 42 and v between 7 and 17 -- 16
-- update biblia set nvg = 'D·vid vstal a öiel na miesto, kde bol Saul. KeÔ uvidel miesto, kde spal Saul a veliteæ jeho vojska Nerov syn Abner ñ Saul spal vo vozovej hradbe a ostatn˝ æud okolo neho ñ, ' where spis = '1Sam' and vers = 1 and k = 26 and v = 5
-- update biblia set nvg = 'Saul odpovedal D·vidovi: ÑBuÔ poûehnan˝, syn mÙj D·vid. »o budeö robiù, urobÌö, a Ëo budeö chcieù, dok·ûeö.ì D·vid odiöiel svojou cestou a Saul sa vr·til na svoje miesto.' where spis = '1Sam' and vers = 1 and k = 26 and v = 25
-- update biblia set nvg = 'A Joab odovzdal kr·æovi v˝sledky sËÌtania æudu; v Izraeli napoËÌtali osemstotisÌc bojaschopn˝ch muûov, ktorÌ nar·baj˙ meËom, a u J˙du p‰ùstotisÌc bojovnÌkov.' where spis = '2Sam' and vers = 1 and k = 24 and v = 9
-- update biblia set nvg = 'Tento BoûÌ dom dohotovili v tretÌ deÚ mesiaca Adar v öiestom roku panovania kr·æa D·ria.' where spis = 'Ezd' and vers = 1 and k = 6 and v = 15
-- update biblia set nvg = 'Potom Izraeliti, kÚazi, leviti a ostatnÌ, Ëo priöli zo zajatia, nateöenÌ sl·vili posviacku tohto Boûieho domu. ', juv = 'tohoto -> tohto' where spis = 'Ezd' and vers = 1 and k = 6 and v = 16
-- update biblia set lc_id = null where lc_id in (934,937) and spis = 'Pris'-- ma to byt 'Kaz'

-- update biblia set nvg = null, lc_id = null, lh_id = null where spis = 'Dt' and k in (4, 6) -- 4. a 6. kapitola Dt treba nanovo
-- + potom treba spustiù nanovo celÈ Dt radöej

