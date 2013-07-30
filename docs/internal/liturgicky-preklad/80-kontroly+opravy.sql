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
-- update biblia set nvg = 'Vdove a_sirote neubl�ite! ' where spis = 'Ex' and vers = 1 and k = 22 and v = 21
-- update biblia set nvg = 'Ak ich budete tr�pi�, bud� vola� ku mne a_ja budem po�u� ich n�rek; ' where spis = 'Ex' and vers = 1 and k = 22 and v = 22
-- update biblia set nvg = 'Moj�i� [...] v�asr�no vstal a vyst�pil na vrch Sinaj, ako mu prik�zal P�n; v ruk�ch mal dve kamenn� tabule.' where spis = 'Ex' and vers = 1 and k = 34 and v = 4
-- update biblia set lh_id = 'POST1_cCIT1_1UT' where spis = 'Ex' and vers = 1 and k = 7 and v between 1 and 25
-- update biblia set lh_id = 'POST1_cCIT1_2PI' where spis = 'Ex' and vers = 1 and k = 20 and v between 18 and 21
-- update biblia set nvg = null where id in (4502, 4503, 4504) -- Lv 8,22-23
-- update biblia set nvg = 'Potom �ron zdvihol ruky smerom k_�udu a_po�ehnal ho. Tak zakon�il obetu za hriech, z�paln� a_pokojn� obetu, a_zost�pil dolu. ' where spis = 'Lv' and vers = 1 and k = 9 and v = 22
-- update biblia set nvg = 'Moj�i� a_�ron vo�li do st�nku stretnutia a_ke� potom vy�li, po�ehnali �ud. Vtom sa zjavila v�etk�mu �udu P�nova veleba: ' where spis = 'Lv' and vers = 1 and k = 9 and v = 23
-- update biblia set nvg = 'vy��ahol ohe� od P�na a_str�vil z�paln� obetu i_tuk, �o boli na olt�ri. Ke� to z�stupy videli, jasali a_vrhali sa na tv�r. ' where spis = 'Lv' and vers = 1 and k = 9 and v = 24
-- update biblia set lc_id = 1523 where spis = 'Nm' and vers = 1 and k = 14 and v between 26 and 30 -- hoci je uveden� len po v. 29, predsa je tam aj NVg v. 30
-- update biblia set lh_id = '_1STRr_CIT' where spis = 'Tob' and vers = 1 and k = 4 and v = 14
-- update biblia set nvg = '[...] (NVg 4,15) Daj pozor na to, �o rob�, bu� rozumn� vo v�etk�ch svojich re�iach. [...]' where spis = 'Tob' and vers = 1 and k = 4 and v = 14
-- update biblia set nvg = '�o sa nep��i tebe, nerob in�mu. [...]' where spis = 'Tob' and vers = 1 and k = 4 and v = 15
-- update biblia set nvg = 'O_svoj chlieb sa de� s_hladn�m a_o_svoje �aty s_nah�m. Z_toho, �oho m� hojnos�, daj n�dznym. [...]' where spis = 'Tob' and vers = 1 and k = 4 and v = 16
-- update biblia set nvg = 'Dobrore� Bohu v_ka�dom �ase a_pros ho, aby riadil tvoje kroky a_usmer�oval tvoje z�mery. [...]' where spis = 'Tob' and vers = 1 and k = 4 and v = 19
-- update biblia set nvg = null where spis = 'Iz' and vers = 1 and k = 16 and v = 6
-- update biblia set lh_id = null where spis = 'Iz' and vers = 1 and k = 44 and v = 20
-- update biblia set lh_id = 'POST1_2SOCIT' where spis = 'Iz' and vers = 1 and k = 44 and v between 21 and 22
-- update biblia set lh_id = 'VIAN1_3CIT31' where spis = 'Iz' and vers = 1 and k = 65 and v = 1
-- update biblia set nvg = 'Tr�va uschne a kvet odpadne,_* / ke� ho ovanie P�nov dych. / Naozaj je �ud ako tr�va:_� ' where spis = 'Iz' and vers = 1 and k = 40 and v = 7
-- update biblia set nvg = 'Tr�va uschne, kvet odpadne,_* / ale slovo n�ho Boha trv� naveky.' where spis = 'Iz' and vers = 1 and k = 40 and v = 8
-- update biblia set nvg = 'Vyst�p na vysok� vrch, ty, �o hl�sa� radostn� zves� Sionu! Zodvihni mocne svoj hlas, ty, �o hl�sa� radostn� zves� Jeruzalemu! Zodvihni, neboj sa, povedz judejsk�m mest�m: H�a, v� Boh! ' where spis = 'Iz' and vers = 1 and k = 40 and v = 9
-- update biblia set nvg = null where spis = 'Mud' and vers = 1 and k = 18 and v = 5
-- update biblia set nvg = 'O tej noci na�i otcovia u� vopred vedeli, aby s istotou poznali, ak�m pr�s�ubom uverili, a boli dobrej mysle. ' where spis = 'Mud' and vers = 1 and k = 18 and v = 6
-- update biblia set nvg = 'tvoje v�emoh�ce slovo zosko�ilo z neba, z kr�ovsk�ho tr�nu, ako tvrd� bojovn�k doprostred zeme ods�denej na skazu. ' where spis = 'Mud' and vers = 1 and k = 18 and v = 15
-- update biblia set nvg = 'Nieslo tvoj nezvratn� rozkaz ako ostr� me�, zastalo a v�etko naplnilo smr�ou; st�lo na zemi a siahalo a� po nebo.' where spis = 'Mud' and vers = 1 and k = 18 and v = 16
-- update biblia set lh_id = null where spis = 'Tob' and vers = 1 and k = 13 and v between 17 and 18
-- update biblia set nvg = 'Ke� si sa modlil ty a S�ra, ja som predn�al slov� va�ej modlitby pred jasnos� P�novej tv�re. A ke� si pochov�val m�tvych, takisto. ' where spis = 'Tob' and vers = 1 and k = 12 and v = 12
-- update biblia set nvg = 'A preto�e si nev�hal vsta� a zanecha� jedlo a �iel si pochova� m�tveho, bol som poslan� k tebe sk��a� �a. ' where spis = 'Tob' and vers = 1 and k = 12 and v = 13
-- update biblia set lh_id = 'OCR9SOc_CIT1' where spis = 'Job' and vers = 1 and k = 42 and v between 7 and 17 -- 16
-- update biblia set nvg = 'D�vid vstal a �iel na miesto, kde bol Saul. Ke� uvidel miesto, kde spal Saul a velite� jeho vojska Nerov syn Abner � Saul spal vo vozovej hradbe a ostatn� �ud okolo neho �, ' where spis = '1Sam' and vers = 1 and k = 26 and v = 5
-- update biblia set nvg = 'Saul odpovedal D�vidovi: �Bu� po�ehnan�, syn m�j D�vid. �o bude� robi�, urob�, a �o bude� chcie�, dok�e�.� D�vid odi�iel svojou cestou a Saul sa vr�til na svoje miesto.' where spis = '1Sam' and vers = 1 and k = 26 and v = 25
-- update biblia set nvg = 'A Joab odovzdal kr�ovi v�sledky s��tania �udu; v Izraeli napo��tali osemstotis�c bojaschopn�ch mu�ov, ktor� nar�baj� me�om, a u J�du p�stotis�c bojovn�kov.' where spis = '2Sam' and vers = 1 and k = 24 and v = 9
-- update biblia set nvg = 'Tento Bo�� dom dohotovili v tret� de� mesiaca Adar v �iestom roku panovania kr�a D�ria.' where spis = 'Ezd' and vers = 1 and k = 6 and v = 15
-- update biblia set nvg = 'Potom Izraeliti, k�azi, leviti a ostatn�, �o pri�li zo zajatia, nate�en� sl�vili posviacku tohto Bo�ieho domu. ', juv = 'tohoto -> tohto' where spis = 'Ezd' and vers = 1 and k = 6 and v = 16
-- update biblia set lc_id = null where lc_id in (934,937) and spis = 'Pris'-- ma to byt 'Kaz'

-- update biblia set nvg = null, lc_id = null, lh_id = null where spis = 'Dt' and k in (4, 6) -- 4. a 6. kapitola Dt treba nanovo
-- + potom treba spusti� nanovo cel� Dt rad�ej

