-- 02JUL_cCIT1	2, 8-14; 8, 6-7
-- _4NE3_CIT	Pies 8, 6b-7a
-- SCPNV_rCIT/SCPN_rCIT	Pies 8, 7
-- OCR18STVc_CIT2 resp.	Pies 8, 6b-c. 7a
-- 1538	Pies 2, 8-14
-- 1540	Pies 8, 6-7
update biblia set lh_id = '02JUL_cCIT1' where spis = 'Pies' and vers = 1 and k = 2 and v between 8 and 14
update biblia set lh_id = '02JUL_cCIT1' where spis = 'Pies' and vers = 1 and k = 8 and v between 6 and 7
go
update biblia set lc_id = 1538 where spis = 'Pies' and vers = 1 and k = 2 and v between 8 and 14
update biblia set lc_id = 1540 where spis = 'Pies' and vers = 1 and k = 8 and v between 6 and 7
go

update biblia set nvg = 'Hlas môjho milého! / H¾a, on prichádza, / po horách skáèe, / po vàškoch hupká.' where spis = 'Pies' and vers = 1 and k = 2 and v = 8
update biblia set nvg = 'Milı môj je sa srna, / ako jeleníèa. / H¾a, veï u stojí / pred naším múrom; / oblôèkom h¾adí, / cez mrieku sa díva.' where spis = 'Pies' and vers = 1 and k = 2 and v = 9
update biblia set nvg = 'Môj milı mi hovorí: / „Hor’ sa, priate¾ka moja, / holubica moja, krásava moja, a poï!' where spis = 'Pies' and vers = 1 and k = 2 and v = 10
update biblia set nvg = 'Veï u je po zime, / dáï prestal, pominul.' where spis = 'Pies' and vers = 1 and k = 2 and v = 11
update biblia set nvg = 'Na zemi sa zjavili kvety, / prišiel èas veselého spevu, / hrkútanie hrdlièky poèu / v_našom kraji,' where spis = 'Pies' and vers = 1 and k = 2 and v = 12
update biblia set nvg = 'figovník vydáva svoje plody, / viniè roznáša vôòu v_rozkvete. // Nu, hor’ sa, priate¾ka moja, / krásava moja, a poï!' where spis = 'Pies' and vers = 1 and k = 2 and v = 13
update biblia set nvg = 'Holubica moja v_rozsadlinách skál, / v_úkryte na bralách! / Daj zrie mi svoju tvár, / daj poèu mi svoj hlas; / veï sladkı je tvoj hlas / a prekrásna je tvoja tvár.“' where spis = 'Pies' and vers = 1 and k = 2 and v = 14
go
update biblia set nvg = 'Pritisni si ma na srdce sa prsteò, / ako peèa na svoje rameno, / lebo láska je mocná ako smr / a vášeò tvrdá ako podsvetie. / Jej pá¾a – to ohòa plápoly / a boské plamene.' where spis = 'Pies' and vers = 1 and k = 8 and v = 6
update biblia set nvg = 'Ani ve¾ké vody lásku neuhasia / a rieky ju neodplavia. / A keby niekto za lásku ponúkol všetko, èo má v_dome, / len by sa opovrhlo ním.' where spis = 'Pies' and vers = 1 and k = 8 and v = 7
go

-- 1539	Pies 3, 1-4a
update biblia set lc_id = 1539 where spis = 'Pies' and vers = 1 and k = 3 and v between 1 and 4
go
update biblia set nvg = 'Snúbenica vraví: Na svojom lôku po nociach h¾adala som toho, ktorého moja duša miluje; h¾adala som ho, ale nenašla. ' where spis = 'Pies' and vers = 1 and k = 3 and v = 1
update biblia set nvg = '"Vstanem a mesto pochodím: po uliciach a námestiach budem h¾ada toho, ktorého miluje moja duša."' where spis = 'Pies' and vers = 1 and k = 3 and v = 2
update biblia set nvg = 'H¾adala som ho, ale nenašla. Stretli ma strácovia, èo boli na obchôdzke po meste. "Nevideli ste toho, ktorého moja duša miluje?"' where spis = 'Pies' and vers = 1 and k = 3 and v = 3
update biblia set nvg = 'A keï som trochu od nich poodišla, našla som, koho moja duša miluje. [...]' where spis = 'Pies' and vers = 1 and k = 3 and v = 4
go

-- OCR14PIc_CIT1 resp.	Pies 3, 11	
update biblia set lh_id = 'OCR14PIc_CIT1 resp.' where spis = 'Pies' and vers = 1 and k = 3 and v = 11
go
update biblia set nvg = 'Vyjdite a pozrite, dcéry sionské, na krá¾a Šalamúna s_korunou, ktorou ho korunovala jeho matka v_deò, keï sa radovalo jeho srdce.' where spis = 'Pies' and vers = 1 and k = 3 and v = 11
go

-- 08SEP_9CIT	Pies 6, 10
update biblia set lh_id = '08SEP_9CIT' where spis = 'Pies' and vers = 1 and k = 6 and v = 10
go
update biblia set nvg = 'Kto je tá, èo vychádza ako ranná zora, krásna ako mesiac, èistá ako slnko, hrozná ako usporiadanı šík bojovníkov?' where spis = 'Pies' and vers = 1 and k = 6 and v = 10
go

