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

update biblia set nvg = 'Hlas m�jho mil�ho! / H�a, on prich�dza, / po hor�ch sk��e, / po v��koch hupk�.' where spis = 'Pies' and vers = 1 and k = 2 and v = 8
update biblia set nvg = 'Mil� m�j je s�a srna, / ako jelen��a. / H�a, ve� u� stoj� / pred na��m m�rom; / obl��kom h�ad�, / cez mrie�ku sa d�va.' where spis = 'Pies' and vers = 1 and k = 2 and v = 9
update biblia set nvg = 'M�j mil� mi hovor�: / �Hor� sa, priate�ka moja, / holubica moja, kr�sava moja, a po�!' where spis = 'Pies' and vers = 1 and k = 2 and v = 10
update biblia set nvg = 'Ve� u� je po zime, / d�� prestal, pominul.' where spis = 'Pies' and vers = 1 and k = 2 and v = 11
update biblia set nvg = 'Na zemi sa zjavili kvety, / pri�iel �as vesel�ho spevu, / hrk�tanie hrdli�ky po�u� / v_na�om kraji,' where spis = 'Pies' and vers = 1 and k = 2 and v = 12
update biblia set nvg = 'figovn�k vyd�va svoje plody, / vini� rozn�a v��u v_rozkvete. // Nu�, hor� sa, priate�ka moja, / kr�sava moja, a po�!' where spis = 'Pies' and vers = 1 and k = 2 and v = 13
update biblia set nvg = 'Holubica moja v_rozsadlin�ch sk�l, / v_�kryte na bral�ch! / Daj zrie� mi svoju tv�r, / daj po�u� mi svoj hlas; / ve� sladk� je tvoj hlas / a prekr�sna je tvoja tv�r.�' where spis = 'Pies' and vers = 1 and k = 2 and v = 14
go
update biblia set nvg = 'Pritisni si ma na srdce s�a prste�, / ako pe�a� na svoje rameno, / lebo l�ska je mocn� ako smr� / a v�e� tvrd� ako podsvetie. / Jej p�a � to oh�a pl�poly / a bo�sk� plamene.' where spis = 'Pies' and vers = 1 and k = 8 and v = 6
update biblia set nvg = 'Ani ve�k� vody l�sku neuhasia / a rieky ju neodplavia. / A keby niekto za l�sku pon�kol v�etko, �o m� v_dome, / len by sa opovrhlo n�m.' where spis = 'Pies' and vers = 1 and k = 8 and v = 7
go

-- 1539	Pies 3, 1-4a
update biblia set lc_id = 1539 where spis = 'Pies' and vers = 1 and k = 3 and v between 1 and 4
go
update biblia set nvg = 'Sn�benica vrav�: Na svojom l��ku po nociach h�adala som toho, ktor�ho moja du�a miluje; h�adala som ho, ale nena�la. ' where spis = 'Pies' and vers = 1 and k = 3 and v = 1
update biblia set nvg = '"Vstanem a mesto pochod�m: po uliciach a n�mestiach budem h�ada� toho, ktor�ho miluje moja du�a."' where spis = 'Pies' and vers = 1 and k = 3 and v = 2
update biblia set nvg = 'H�adala som ho, ale nena�la. Stretli ma str�covia, �o boli na obch�dzke po meste. "Nevideli ste toho, ktor�ho moja du�a miluje?"' where spis = 'Pies' and vers = 1 and k = 3 and v = 3
update biblia set nvg = 'A ke� som trochu od nich poodi�la, na�la som, koho moja du�a miluje. [...]' where spis = 'Pies' and vers = 1 and k = 3 and v = 4
go

-- OCR14PIc_CIT1 resp.	Pies 3, 11	
update biblia set lh_id = 'OCR14PIc_CIT1 resp.' where spis = 'Pies' and vers = 1 and k = 3 and v = 11
go
update biblia set nvg = 'Vyjdite a pozrite, dc�ry sionsk�, na kr�a �alam�na s_korunou, ktorou ho korunovala jeho matka v_de�, ke� sa radovalo jeho srdce.' where spis = 'Pies' and vers = 1 and k = 3 and v = 11
go

-- 08SEP_9CIT	Pies 6, 10
update biblia set lh_id = '08SEP_9CIT' where spis = 'Pies' and vers = 1 and k = 6 and v = 10
go
update biblia set nvg = 'Kto je t�, �o vych�dza ako rann� zora, kr�sna ako mesiac, �ist� ako slnko, hrozn� ako usporiadan� ��k bojovn�kov?' where spis = 'Pies' and vers = 1 and k = 6 and v = 10
go

