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
-- update biblia set nvg = 'Vdove a_sirote neublíite! ' where spis = 'Ex' and vers = 1 and k = 22 and v = 21
-- update biblia set nvg = 'Ak ich budete trápi, budú vola ku mne a_ja budem poèu ich nárek; ' where spis = 'Ex' and vers = 1 and k = 22 and v = 22
-- update biblia set nvg = 'Mojiš [...] vèasráno vstal a vystúpil na vrch Sinaj, ako mu prikázal Pán; v rukách mal dve kamenné tabule.' where spis = 'Ex' and vers = 1 and k = 34 and v = 4
-- update biblia set lh_id = 'POST1_cCIT1_1UT' where spis = 'Ex' and vers = 1 and k = 7 and v between 1 and 25
-- update biblia set lh_id = 'POST1_cCIT1_2PI' where spis = 'Ex' and vers = 1 and k = 20 and v between 18 and 21
-- update biblia set nvg = null where id in (4502, 4503, 4504) -- Lv 8,22-23
-- update biblia set nvg = 'Potom Áron zdvihol ruky smerom k_¾udu a_poehnal ho. Tak zakonèil obetu za hriech, zápalnú a_pokojnú obetu, a_zostúpil dolu. ' where spis = 'Lv' and vers = 1 and k = 9 and v = 22
-- update biblia set nvg = 'Mojiš a_Áron vošli do stánku stretnutia a_keï potom vyšli, poehnali ¾ud. Vtom sa zjavila všetkému ¾udu Pánova veleba: ' where spis = 'Lv' and vers = 1 and k = 9 and v = 23
-- update biblia set nvg = 'vyš¾ahol oheò od Pána a_strávil zápalnú obetu i_tuk, èo boli na oltári. Keï to zástupy videli, jasali a_vrhali sa na tvár. ' where spis = 'Lv' and vers = 1 and k = 9 and v = 24
-- update biblia set lc_id = 1523 where spis = 'Nm' and vers = 1 and k = 14 and v between 26 and 30 -- hoci je uvedené len po v. 29, predsa je tam aj NVg v. 30
-- update biblia set lh_id = '_1STRr_CIT' where spis = 'Tob' and vers = 1 and k = 4 and v = 14
-- update biblia set nvg = '[...] (NVg 4,15) Daj pozor na to, èo robíš, buï rozumnı vo všetkıch svojich reèiach. [...]' where spis = 'Tob' and vers = 1 and k = 4 and v = 14
-- update biblia set nvg = 'Èo sa nepáèi tebe, nerob inému. [...]' where spis = 'Tob' and vers = 1 and k = 4 and v = 15
-- update biblia set nvg = 'O_svoj chlieb sa de¾ s_hladnım a_o_svoje šaty s_nahım. Z_toho, èoho máš hojnos, daj núdznym. [...]' where spis = 'Tob' and vers = 1 and k = 4 and v = 16
-- update biblia set nvg = 'Dobroreè Bohu v_kadom èase a_pros ho, aby riadil tvoje kroky a_usmeròoval tvoje zámery. [...]' where spis = 'Tob' and vers = 1 and k = 4 and v = 19
-- update biblia set nvg = null where spis = 'Iz' and vers = 1 and k = 16 and v = 6
-- update biblia set lh_id = null where spis = 'Iz' and vers = 1 and k = 44 and v = 20
-- update biblia set lh_id = 'POST1_2SOCIT' where spis = 'Iz' and vers = 1 and k = 44 and v between 21 and 22
-- update biblia set lh_id = 'VIAN1_3CIT31' where spis = 'Iz' and vers = 1 and k = 65 and v = 1
-- update biblia set nvg = 'Tráva uschne a kvet odpadne,_* / keï ho ovanie Pánov dych. / Naozaj je ¾ud ako tráva:_† ' where spis = 'Iz' and vers = 1 and k = 40 and v = 7
-- update biblia set nvg = 'Tráva uschne, kvet odpadne,_* / ale slovo nášho Boha trvá naveky.' where spis = 'Iz' and vers = 1 and k = 40 and v = 8
-- update biblia set nvg = 'Vystúp na vysokı vrch, ty, èo hlásaš radostnú zves Sionu! Zodvihni mocne svoj hlas, ty, èo hlásaš radostnú zves Jeruzalemu! Zodvihni, neboj sa, povedz judejskım mestám: H¾a, váš Boh! ' where spis = 'Iz' and vers = 1 and k = 40 and v = 9
-- update biblia set nvg = null where spis = 'Mud' and vers = 1 and k = 18 and v = 5
-- update biblia set nvg = 'O tej noci naši otcovia u vopred vedeli, aby s istotou poznali, akım prís¾ubom uverili, a boli dobrej mysle. ' where spis = 'Mud' and vers = 1 and k = 18 and v = 6
-- update biblia set nvg = 'tvoje všemohúce slovo zoskoèilo z neba, z krá¾ovského trónu, ako tvrdı bojovník doprostred zeme odsúdenej na skazu. ' where spis = 'Mud' and vers = 1 and k = 18 and v = 15
-- update biblia set nvg = 'Nieslo tvoj nezvratnı rozkaz ako ostrı meè, zastalo a všetko naplnilo smrou; stálo na zemi a siahalo a po nebo.' where spis = 'Mud' and vers = 1 and k = 18 and v = 16
-- update biblia set lh_id = null where spis = 'Tob' and vers = 1 and k = 13 and v between 17 and 18
-- update biblia set nvg = 'Keï si sa modlil ty a Sára, ja som prednášal slová vašej modlitby pred jasnos Pánovej tváre. A keï si pochovával màtvych, takisto. ' where spis = 'Tob' and vers = 1 and k = 12 and v = 12
-- update biblia set nvg = 'A pretoe si neváhal vsta a zanecha jedlo a šiel si pochova màtveho, bol som poslanı k tebe skúša a. ' where spis = 'Tob' and vers = 1 and k = 12 and v = 13
-- update biblia set lh_id = 'OCR9SOc_CIT1' where spis = 'Job' and vers = 1 and k = 42 and v between 7 and 17 -- 16
-- update biblia set nvg = 'Dávid vstal a šiel na miesto, kde bol Saul. Keï uvidel miesto, kde spal Saul a velite¾ jeho vojska Nerov syn Abner – Saul spal vo vozovej hradbe a ostatnı ¾ud okolo neho –, ' where spis = '1Sam' and vers = 1 and k = 26 and v = 5
-- update biblia set nvg = 'Saul odpovedal Dávidovi: „Buï poehnanı, syn môj Dávid. Èo budeš robi, urobíš, a èo budeš chcie, dokáeš.“ Dávid odišiel svojou cestou a Saul sa vrátil na svoje miesto.' where spis = '1Sam' and vers = 1 and k = 26 and v = 25
-- update biblia set nvg = 'A Joab odovzdal krá¾ovi vısledky sèítania ¾udu; v Izraeli napoèítali osemstotisíc bojaschopnıch muov, ktorí narábajú meèom, a u Júdu pästotisíc bojovníkov.' where spis = '2Sam' and vers = 1 and k = 24 and v = 9
-- update biblia set nvg = 'Tento Boí dom dohotovili v tretí deò mesiaca Adar v šiestom roku panovania krá¾a Dária.' where spis = 'Ezd' and vers = 1 and k = 6 and v = 15
-- update biblia set nvg = 'Potom Izraeliti, kòazi, leviti a ostatní, èo prišli zo zajatia, natešení slávili posviacku tohto Boieho domu. ', juv = 'tohoto -> tohto' where spis = 'Ezd' and vers = 1 and k = 6 and v = 16
-- update biblia set lc_id = null where lc_id in (934,937) and spis = 'Pris'-- ma to byt 'Kaz'
-- update biblia set nvg = 'Pozdvihol som zo zeme svoju pokornú modlitbu / a_prosil som, aby ma minula smr.' where spis = 'Sir' and vers = 1 and k = 51 and v = 13
-- update biblia set nvg = 'v_kadom ¾ude a_v_kadom národe / som mala prvenstvo' where spis = 'Sir' and vers = 1 and k = 24 and v = 10
-- update biblia set nvg = 'Toto je teda, v_èom nie si spravodlivı; poviem ti to, / lebo Boh je väèší ako èlovek.' where spis = 'Job' and vers = 1 and k = 33 and v = 12
-- update biblia set nvg = 'Èujte, národy, slovo Pánovo,_* / ohlasujte ho na ostrovoch v_dia¾avách / a hovorte: „Zhromadí Izraela ten, èo ho rozptılil,_* / bude ho strái ako pastier svoje stádo.“' where spis = 'Jer' and vers = 1 and k = 31 and v = 10
-- update biblia set nvg = 'Pán je ako bojovník; / PÁN je jeho meno.' where spis = 'Ex' and vers = 1 and k = 15 and v = 3
-- update biblia set nvg = 'Mojiš postavil oltár a_dal mu meno PÁN Nissi (Pán je moja zástava), lebo ' where spis = 'Ex' and vers = 1 and k = 17 and v = 15
-- update biblia set nvg = 'a_budú rozpráva obyvate¾om tejto krajiny, ako poèuli, e ty, Pane, si uprostred tohto ¾udu a_zjavuješ sa z_tváre do tváre, e ich kryje tvoj oblak a_ideš pred nimi cez deò v_oblaènom ståpe a_v_noci v_ståpe ohnivom. ' where spis = 'Nm' and vers = 1 and k = 14 and v = 14
-- update biblia set nvg = 'Odpus, prosím, hriech tohto ¾udu pre svoje ve¾ké milosrdenstvo, ako si bol tomuto ¾udu milostivı od Egypta a po toto miesto.“' where spis = 'Nm' and vers = 1 and k = 14 and v = 19
-- update biblia set nvg = '„Levitskí kòazi, celı Léviho kmeò, nebudú ma podiel ani dedièstvo s_ostatnım Izraelom. Budú i z_obiet Pánovi a_z_jeho dedièstva. ' where spis = 'Dt' and vers = 1 and k = 18 and v = 1
-- update biblia set nvg = 'Vtedy Šalamún povedal: // „Pán povedal, e bude bıva v_oblaku. / ' where spis = '1Kr' and vers = 1 and k = 8 and v = 12
-- update biblia set nvg = 'Ja som postavil dom, aby si v_òom bıval, / najpevnejší trón pre teba naveky.“' where spis = '1Kr' and vers = 1 and k = 8 and v = 13
-- update biblia set nvg = 'On vravel: // „Videl som celı Izrael / rozptılenı po vrchoch / ako ovce, ktoré nemajú pastiera. // A_Pán povedal: ‚Títo nemajú pána. Nech sa kadı vráti v_pokoji domov.‘“' where spis = '1Kr' and vers = 1 and k = 22 and v = 17
-- update biblia set nvg = 'Kto nevie z_tohto všetkého, / e to urobila Pánova ruka?' where spis = 'Job' and vers = 1 and k = 12 and v = 9

-- update biblia set nvg = null, lc_id = null, lh_id = null where spis = 'Dt' and k in (4, 6) -- 4. a 6. kapitola Dt treba nanovo
-- + potom treba spusti nanovo celé Dt radšej

