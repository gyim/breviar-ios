-- 522	Gn 1, 1-19
-- 521	Gn 1, 1 - 2, 2
-- 523	Gn 1, 1. 26-31a
-- 524	Gn 1, 20 - 2, 4a
-- 525	Gn 1, 26 - 2, 3
-- VTROJ_cCIT1_NE	1, 1 � 2, 2
-- 548	Gn 2, 4b-9. 15-17
-- 549	Gn 2, 7-9; 3, 1-7a
-- 546	Gn 2, 18-24
-- 547	Gn 2, 18-25
update biblia set lc_id = 521 where spis = 'Gn' and vers = 1 and k = 1 and v between 1 and 31
update biblia set lc_id = 524 where spis = 'Gn' and vers = 1 and k = 2 and v between 1 and 4
update biblia set lh_id = 'VTROJ_cCIT1_NE' where spis = 'Gn' and vers = 1 and k = 1 and v between 1 and 31
update biblia set lh_id = 'VTROJ_cCIT1_NE' where spis = 'Gn' and vers = 1 and k = 2 and v between 1 and 2
update biblia set lc_id = 548 where spis = 'Gn' and vers = 1 and k = 2 and v between 5 and 9
update biblia set lc_id = 548 where spis = 'Gn' and vers = 1 and k = 2 and v between 15 and 17
update biblia set lc_id = 547 where spis = 'Gn' and vers = 1 and k = 2 and v between 18 and 25
go

update biblia set nvg = 'Na po�iatku stvoril Boh nebo a zem. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 1
update biblia set nvg = 'Ale zem bola pust� a pr�zdna, tma bola nad priepas�ou a duch Bo�� sa vzn�al nad vodami.' where spis = 'Gn' and vers = 1 and k = 1 and v = 2
update biblia set nvg = 'Boh povedal: �Bu� svetlo!� A bolo svetlo. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 3
update biblia set nvg = 'Boh videl, �e svetlo je dobr�, a oddelil svetlo od tmy. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 4
update biblia set nvg = 'Svetlo nazval D�om a tmu nazval Nocou. A nastal ve�er a r�no, prv� de�.' where spis = 'Gn' and vers = 1 and k = 1 and v = 5
update biblia set nvg = 'Boh povedal: �Nech je obloha uprostred v�d a nech odde�uje vody od v�d.� ' where spis = 'Gn' and vers = 1 and k = 1 and v = 6
update biblia set nvg = 'Boh urobil oblohu a oddelil vody pod oblohou od v�d nad oblohou. A tak sa stalo. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 7
update biblia set nvg = 'A Boh nazval oblohu Nebom. A nastal ve�er a r�no, druh� de�.' where spis = 'Gn' and vers = 1 and k = 1 and v = 8
update biblia set nvg = 'Boh povedal: �Vody pod nebom nech sa zhroma�dia na jedno miesto a nech sa uk�e s��.� A tak sa stalo. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 9
update biblia set nvg = 'Boh nazval s�� Zemou a masy v�d nazval Morom. A Boh videl, �e je to dobr�.' where spis = 'Gn' and vers = 1 and k = 1 and v = 10
update biblia set nvg = '�alej Boh povedal: �Zem nech vy�enie zelen� rastliny: rastliny prin�aj�ce semeno a ovocn� stromy prin�aj�ce plody pod�a svojho druhu a v_nich nech je semeno na zemi.� A tak sa stalo. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 11
update biblia set nvg = 'Zem vyhnala zelen� rastliny, rastliny prin�aj�ce semeno pod�a svojho druhu i stromy prin�aj�ce plody a v_nich semen� pod�a svojho druhu. A Boh videl, �e je to dobr�. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 12
update biblia set nvg = 'A nastal ve�er a r�no, tret� de�.' where spis = 'Gn' and vers = 1 and k = 1 and v = 13
update biblia set nvg = 'Boh povedal: �Nech s� svetl� na nebeskej oblohe a nech odde�uj� de� od noci, nech s� znamen�m obdob�, dn� a rokov, ' where spis = 'Gn' and vers = 1 and k = 1 and v = 14
update biblia set nvg = 'nech svietia na nebeskej oblohe a nech osvet�uj� zem.� A tak sa stalo. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 15
update biblia set nvg = 'Boh urobil dvoje ve�k�ch svetiel: v��ie svetlo, �eby vl�dlo vo dne, a men�ie svetlo, �eby vl�dlo v_noci, a hviezdy. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 16
update biblia set nvg = 'Umiestnil ich na nebeskej oblohe, aby svietili na zem ' where spis = 'Gn' and vers = 1 and k = 1 and v = 17
update biblia set nvg = 'a vl�dli vo dne v_noci a odde�ovali svetlo od tmy. A Boh videl, �e je to dobr�. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 18
update biblia set nvg = 'A nastal ve�er a r�no, �tvrt� de�.' where spis = 'Gn' and vers = 1 and k = 1 and v = 19
update biblia set nvg = 'Boh povedal: �Nech sa vody hem�ia �iv�mi tvormi a vt�ky nech lietaj� ponad zem na nebeskej oblohe.� ' where spis = 'Gn' and vers = 1 and k = 1 and v = 20
update biblia set nvg = 'A Boh stvoril ve�ryby a v�etky �iv� tvory, ktor� sa h�bu a hem�ia vo vod�ch, pod�a svojho druhu, i_v�etky vt�ky pod�a svojho druhu. A Boh videl, �e je to dobr�. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 21
update biblia set nvg = 'Boh ich po�ehnal a povedal: �Vzrastajte, rozmno�ujte sa a napl�te morsk� vody;aj vt�ky nech sa rozmno�uj� na zemi.� ' where spis = 'Gn' and vers = 1 and k = 1 and v = 22
update biblia set nvg = 'A nastal ve�er a r�no, piaty de�.' where spis = 'Gn' and vers = 1 and k = 1 and v = 23
update biblia set nvg = 'Boh povedal: �Zem nech vyd� v�etky druhy �iv�ch bytost�: dobytok, plazy a div� zver pod�a svojho druhu.� A tak sa stalo.' where spis = 'Gn' and vers = 1 and k = 1 and v = 24
update biblia set nvg = 'Boh urobil div� zver pod�a svojho druhu, dobytok pod�a svojho druhu i_v�etky druhy zemsk�ch plazov. A Boh videl, �e je to dobr�.' where spis = 'Gn' and vers = 1 and k = 1 and v = 25
update biblia set nvg = 'Potom Boh povedal: �Urobme �loveka na n� obraz, na na�u podobu. Nech vl�dnu nad morsk�mi rybami a nad nebesk�m vt�ctvom, nad zverinou i_nad celou zemou; i_nad v�etk�mi plazmi, �o sa h�bu po zemi.�' where spis = 'Gn' and vers = 1 and k = 1 and v = 26
update biblia set nvg = 'A stvoril Boh �loveka na svoj obraz, / na Bo�� obraz ho stvoril, / mu�a a �enu ich stvoril.' where spis = 'Gn' and vers = 1 and k = 1 and v = 27
update biblia set nvg = 'Boh ich po�ehnal a povedal im: // �Vzrastajte a mno�te sa. / Napl�te zem a podma�te si ju. / Panujte nad morsk�mi rybami, / nad nebesk�m vt�ctvom / a nad v�etkou zverou, / �o sa h�be po zemi.�' where spis = 'Gn' and vers = 1 and k = 1 and v = 28
update biblia set nvg = 'Potom Boh povedal: �H�a, d�vam v�m v�etky semenn� rastliny na celej zemi a v�etky stromy s_ich ovoc�m, v_ktorom je semeno, aby v�m boli za pokrm. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 29
update biblia set nvg = 'A v�etk�m �ivo��chom zeme, v�etk�mu nebesk�mu vt�ctvu i_v�etk�mu, �o sa h�be na zemi a m� v_sebe �ivot, d�vam za pokrm v�etky zelen� rastliny. A tak sa stalo. ' where spis = 'Gn' and vers = 1 and k = 1 and v = 30
update biblia set nvg = 'A Boh videl v�etko, �o urobil; a bolo to ve�mi dobr�. A nastal ve�er a r�no, �iesty de�.' where spis = 'Gn' and vers = 1 and k = 1 and v = 31
go
update biblia set nvg = 'Takto boli ukon�en� nebo a zem a v�etka ich n�dhera. ' where spis = 'Gn' and vers = 1 and k = 2 and v = 1
update biblia set nvg = 'Siedmeho d�a Boh ukon�il dielo, ktor� konal, a v_siedmy de� si odpo�inul po v�etk�ch dielach, �o vytvoril.' where spis = 'Gn' and vers = 1 and k = 2 and v = 2
update biblia set nvg = 'A Boh po�ehnal siedmy de� a posv�til ho, lebo v ten de� Boh odpo��val po celom svojom diele, ktor� stvoren�m vytvoril.' where spis = 'Gn' and vers = 1 and k = 2 and v = 3
update biblia set nvg = 'Toto je p�vod neba a zeme, ke� boli stvoren�. // Ke� P�n, Boh, urobil zem a nebo, ' where spis = 'Gn' and vers = 1 and k = 2 and v = 4
update biblia set nvg = 'e�te nevzi�lo na zemi nijak� po�n� krovie a e�te ner�stla nijak� po�n� rastlina, lebo P�n, Boh, nedal d�� na zem a �loveka nebolo, �eby obr�bal zem; ' where spis = 'Gn' and vers = 1 and k = 2 and v = 5
update biblia set nvg = 'len prame� vyvieral zo zeme a zavla�oval cel� povrch zeme.' where spis = 'Gn' and vers = 1 and k = 2 and v = 6
update biblia set nvg = 'Vtedy P�n, Boh, stv�rnil �loveka z prachu zeme a vd�chol do jeho nozdier dych �ivota. Tak sa stal �lovek �ivou bytos�ou.' where spis = 'Gn' and vers = 1 and k = 2 and v = 7
update biblia set nvg = 'Potom P�n, Boh, vysadil v Edene, na v�chode, z�hradu a v nej umiestil �loveka, ktor�ho bol utvoril. ' where spis = 'Gn' and vers = 1 and k = 2 and v = 8
update biblia set nvg = 'P�n, Boh, dal vyr�s� zo zeme stromom v�etk�ch druhov, kr�snym na poh�ad a chutn�m na jedenie; uprostred z�hrady dal vyr�s� stromu �ivota a stromu poznania dobra a zla.' where spis = 'Gn' and vers = 1 and k = 2 and v = 9
go
update biblia set nvg = 'P�n, Boh, vzal �loveka a umiestil ho v z�hrade Edenu, aby ju obr�bal a str�il. ' where spis = 'Gn' and vers = 1 and k = 2 and v = 15
update biblia set nvg = 'A P�n, Boh, prik�zal �lovekovi: "M��e� jes� zo v�etk�ch stromov z�hrady, ' where spis = 'Gn' and vers = 1 and k = 2 and v = 16
update biblia set nvg = 'ale zo stromu poznania dobra a zla nejedz, lebo ke� bude� z neho jes�, zomrie�."' where spis = 'Gn' and vers = 1 and k = 2 and v = 17
update biblia set nvg = 'P�n, Boh, povedal: "Nie je dobre, �e je �lovek s�m. Urob�m mu pomocn�ka, ktor� mu bude podobn�."' where spis = 'Gn' and vers = 1 and k = 2 and v = 18
update biblia set nvg = 'Ke� P�n, Boh, utvoril z hliny v�etku po�n� zver a v�etky nebesk� vt�ky, priviedol ich k Adamovi, aby videl, ako ich pomenuje. Lebo ako Adam nazval ka�d� �iv� bytos�, tak sa ona vol�. ' where spis = 'Gn' and vers = 1 and k = 2 and v = 19
update biblia set nvg = 'A Adam dal men� v�etk�mu dobytku, v�etk�m nebesk�m vt�kom a v�etk�m po�n�m zvierat�m. Ale pomocn�k, ktor� by bol podobn� Adamovi, sa nena�iel.' where spis = 'Gn' and vers = 1 and k = 2 and v = 20
update biblia set nvg = 'P�n, Boh, teda dopustil na Adama hlbok� sp�nok. A ke� zaspal, vybral jedno z jeho rebier a jeho miesto zaplnil m�som. ' where spis = 'Gn' and vers = 1 and k = 2 and v = 21
update biblia set nvg = 'Z rebra, ktor� P�n, Boh, Adamovi vybral, utvoril �enu a priviedol ju k Adamovi.' where spis = 'Gn' and vers = 1 and k = 2 and v = 22
update biblia set nvg = 'A Adam zvolal: "Toto je kone�ne kos� z mojich kost� a telo z m�jho tela. Bude sa vola� Mu�ena, lebo z mu�a bola vzat�."' where spis = 'Gn' and vers = 1 and k = 2 and v = 23
update biblia set nvg = 'Preto mu� opust� svojho otca i matku a prip�ta sa k svojej man�elke a bud� jedno telo.' where spis = 'Gn' and vers = 1 and k = 2 and v = 24
update biblia set nvg = 'Obaja, Adam i jeho �ena, boli nah� a nehanbili sa.' where spis = 'Gn' and vers = 1 and k = 2 and v = 25
go

-- 558	Gn 3, 1-8
-- 559	Gn 3, 9-15
-- 560	Gn 3, 9-15. 20
-- 561	Gn 3, 9-15. 20
-- 562	Gn 3, 9-24
-- 08SEP_cCIT1	3, 9-20
update biblia set lc_id = 558 where spis = 'Gn' and vers = 1 and k = 3 and v between 1 and 8
update biblia set lc_id = 562 where spis = 'Gn' and vers = 1 and k = 3 and v between 9 and 24
update biblia set lh_id = '08SEP_cCIT1' where spis = 'Gn' and vers = 1 and k = 1 and v between 9 and 20
go

update biblia set nvg = 'Had bol �stivej�� ne� v�etky po�n� zvierat�, ktor� urobil P�n, Boh. I vravel �ene: "Naozaj v�m Boh zak�zal jes� zo v�etk�ch stromov z�hrady?"' where spis = 'Gn' and vers = 1 and k = 3 and v = 1
update biblia set nvg = '�ena mu odpovedala: "Jeme ovocie zo v�etk�ch stromov, �o s� v z�hrade. ' where spis = 'Gn' and vers = 1 and k = 3 and v = 2
update biblia set nvg = 'Len ovocie stromu, ktor� je uprostred z�hrady, n�m Boh zak�zal jes�, ba aj dotkn�� sa ho, aby sme nezomreli."' where spis = 'Gn' and vers = 1 and k = 3 and v = 3
update biblia set nvg = 'No had povedal �ene: "Nie, nezomriete. ' where spis = 'Gn' and vers = 1 and k = 3 and v = 4
update biblia set nvg = 'Ale Boh vie, �e v de�, ke� budete z neho jes�, otvoria sa v�m o�i a budete ako Boh, budete pozna� dobro i zlo."' where spis = 'Gn' and vers = 1 and k = 3 and v = 5
update biblia set nvg = '�ena videla, �e by bolo dobr� jes� zo stromu, �e strom je na poh�ad kr�sny a na z�skanie m�drosti v�biv�; vzala z jeho ovocia a jedla a dala aj svojmu mu�ovi, �o bol s �ou, a jedol aj on.' where spis = 'Gn' and vers = 1 and k = 3 and v = 6
update biblia set nvg = 'Obom sa otvorili o�i a ke� spoznali, �e s� nah�, zo�ili figov� listy a urobili si z�stery.' where spis = 'Gn' and vers = 1 and k = 3 and v = 7
update biblia set nvg = 'Ke� potom po�uli hlas P�na, Boha, ktor� sa za popolud�aj�ieho v�nku prech�dzal po z�hrade, skryl sa Adam i jeho �ena pred P�nom, Bohom, medzi stromy z�hrady.' where spis = 'Gn' and vers = 1 and k = 3 and v = 8
update biblia set nvg = 'P�n, Boh, zavolal �loveka a povedal mu: �Kde si?� ' where spis = 'Gn' and vers = 1 and k = 3 and v = 9
update biblia set nvg = 'On odpovedal: �Po�ul som tvoj hlas v_z�hrade, na�akal som sa, preto�e som nah�, a skryl som sa.� ' where spis = 'Gn' and vers = 1 and k = 3 and v = 10
update biblia set nvg = 'Op�tal sa ho: �Kto �a upozornil, �e si nah�, ak si nejedol zo stromu, z_ktor�ho som ti jes� zak�zal?� ' where spis = 'Gn' and vers = 1 and k = 3 and v = 11
update biblia set nvg = '�lovek odpovedal: ��ena, ktor� si mi dal za spolo�n��ku, dala mi zo stromu a jedol som.� ' where spis = 'Gn' and vers = 1 and k = 3 and v = 12
update biblia set nvg = 'P�n, Boh, povedal �ene: ��o si to urobila?� �ena odpovedala: �Had ma naviedol a jedla som.�' where spis = 'Gn' and vers = 1 and k = 3 and v = 13
update biblia set nvg = 'Tu povedal P�n, Boh, hadovi: // �Preto�e si to urobil, prekliaty bude� / medzi v�etk�mi krotk�mi / a div�mi zvieratami. / Po bruchu sa bude� plazi� / a prach hlta� po v�etky dni svojho �ivota. /' where spis = 'Gn' and vers = 1 and k = 3 and v = 14
update biblia set nvg = 'Nepriate�stvo ustanovujem medzi tebou a �enou, / medzi tvoj�m potomstvom a jej potomstvom; / ono ti roz�liape hlavu / a ty mu zran� p�tu.�' where spis = 'Gn' and vers = 1 and k = 3 and v = 15
update biblia set nvg = '�ene povedal: // �Rozmno��m tvoje tr�penie / a tvoju �archavos�: / v_bolesti bude� rodi� deti, / bude� t��i� po svojom mu�ovi, / ale on bude nad tebou vl�dnu�.�' where spis = 'Gn' and vers = 1 and k = 3 and v = 16
update biblia set nvg = 'A �lovekovi povedal: // �Preto�e si po��val hlas svojej �eny / a jedol si zo stromu, / z_ktor�ho som ti jes� zak�zal, / nech je prekliata zem pre teba: / s_n�mahou sa z_nej bude� �ivi� / po v�etky dni svojho �ivota;' where spis = 'Gn' and vers = 1 and k = 3 and v = 17
update biblia set nvg = 't�nie a bod�a� ti bude rodi� / a ty bude� jes� po�n� rastliny. / ' where spis = 'Gn' and vers = 1 and k = 3 and v = 18
update biblia set nvg = 'V_pote svojej tv�re bude� jes� chlieb, / k�m sa nevr�ti� do zeme, / z_ktorej si bol vzat�, / lebo prach si a do prachu sa vr�ti�.�' where spis = 'Gn' and vers = 1 and k = 3 and v = 19
update biblia set nvg = 'A nazval �lovek svoju �enu Eva, preto�e bola matkou v�etk�ch �ij�cich.' where spis = 'Gn' and vers = 1 and k = 3 and v = 20
update biblia set nvg = 'P�n, Boh, urobil Adamovi a jeho �ene ko�en� tuniky a obliekol ich. ' where spis = 'Gn' and vers = 1 and k = 3 and v = 21
update biblia set nvg = 'Potom P�n, Boh, povedal: "H�a, �lovek sa stal ako jeden z n�s. Pozn� dobro i zlo. Len aby teraz nesiahol svojou rukou na strom �ivota a nejedol z neho a ne�il naveky!"' where spis = 'Gn' and vers = 1 and k = 3 and v = 22
update biblia set nvg = 'A P�n, Boh, ho vyk�zal zo z�hrady Edenu, aby obr�bal zem, z ktorej bol vzat�. ' where spis = 'Gn' and vers = 1 and k = 3 and v = 23
update biblia set nvg = 'Vyhnal �loveka a na v�chod od z�hrady Edenu postavil cherubov a pohybliv� ohniv� me�, aby str�ili cestu k stromu �ivota.' where spis = 'Gn' and vers = 1 and k = 3 and v = 24
go

-- 565	Gn 4, 1-15. 25
update biblia set lc_id = 565 where spis = 'Gn' and vers = 1 and k = 4 and v between 1 and 15
update biblia set lc_id = 565 where spis = 'Gn' and vers = 1 and k = 4 and v = 25
go

update biblia set nvg = 'Adam poznal svoju �enu Evu, ona po�ala a porodila Kaina a povedala: "Dostala som mu�a od P�na." ' where spis = 'Gn' and vers = 1 and k = 4 and v = 1
update biblia set nvg = 'A op� porodila jeho brata �bela. �bel bol pastier oviec, Kain ro�n�k.' where spis = 'Gn' and vers = 1 and k = 4 and v = 2
update biblia set nvg = 'Po istom �ase priniesol Kain P�novi obetu z po�n�ch plod�n. ' where spis = 'Gn' and vers = 1 and k = 4 and v = 3
update biblia set nvg = 'Aj �bel obetoval z prvot�n svojho st�da, z t�ch najtu�nej��ch. A P�n zhliadol na �bela a na jeho obetu, ' where spis = 'Gn' and vers = 1 and k = 4 and v = 4
update biblia set nvg = 'ale na Kaina a na jeho obetu nezhliadol. Kain sa ve�mi nahneval a tv�r sa mu zamra�ila.' where spis = 'Gn' and vers = 1 and k = 4 and v = 5
update biblia set nvg = 'P�n mu povedal: "Pre�o sa hnev� a pre�o mra�� tv�r? ' where spis = 'Gn' and vers = 1 and k = 4 and v = 6
update biblia set nvg = 'Nemal by si zdvihn�� hlavu, ak rob� dobre? Ale ak zle rob�, hriech ��ha pri dver�ch a zachvacuje �a jeho �iadostivos�, len�e ty ju m� ovl�da�."' where spis = 'Gn' and vers = 1 and k = 4 and v = 7
update biblia set nvg = 'Kain povedal svojmu bratovi �belovi: "Po�, vyjdeme si von!" A ke� boli na poli, Kain napadol svojho brata �bela a zabil ho.' where spis = 'Gn' and vers = 1 and k = 4 and v = 8
update biblia set nvg = 'Tu P�n povedal Kainovi: "Kde je tvoj brat �bel?" On odvetil: "Neviem. �o som ja str�ca svojho brata?" ' where spis = 'Gn' and vers = 1 and k = 4 and v = 9
update biblia set nvg = 'P�n mu povedal: "�o si to urobil? Hlas krvi tvojho brata kri�� ku mne zo zeme. ' where spis = 'Gn' and vers = 1 and k = 4 and v = 10
update biblia set nvg = 'Teraz bude� prekliaty a �aleko od zeme, ktor� otvorila �sta, aby vypila krv tvojho brata z tvojej ruky. ' where spis = 'Gn' and vers = 1 and k = 4 and v = 11
update biblia set nvg = 'Ke� ju bude� obr�ba�, u� ti neprinesie �rodu. Bude� nespokojn� a bude� sa t�la� po zemi."' where spis = 'Gn' and vers = 1 and k = 4 and v = 12
update biblia set nvg = 'Kain povedal P�novi: "M�j trest je v���, ne� vl�dzem znies�. ' where spis = 'Gn' and vers = 1 and k = 4 and v = 13
update biblia set nvg = 'Ty ma dnes vyh��a� zo zeme a budem sa skr�va� pred tebou; budem nespokojn�, t�la� sa budem po zemi a kto ma stretne, zabije ma."' where spis = 'Gn' and vers = 1 and k = 4 and v = 14
update biblia set nvg = 'Ale P�n mu povedal: "Nie, to sa nestane. Lebo ka�d�, kto by zabil Kaina, sedemn�sobn� pomstu ponesie." A P�n Kaina ozna�il, aby ho nik nezabil, ke� ho stretne.' where spis = 'Gn' and vers = 1 and k = 4 and v = 15
update biblia set nvg = 'Adam op� poznal svoju �enu, ona porodila syna a dala mu meno Set, lebo povedala: "Boh mi dal in�ho potomka namiesto �bela, ktor�ho zabil Kain."' where spis = 'Gn' and vers = 1 and k = 4 and v = 25
go

-- 571	Gn 6, 5-8; 7, 1-5. 10
update biblia set lc_id = 571 where spis = 'Gn' and vers = 1 and k = 6 and v between 5 and 8
update biblia set lc_id = 571 where spis = 'Gn' and vers = 1 and k = 7 and v between 1 and 5
update biblia set lc_id = 571 where spis = 'Gn' and vers = 1 and k = 7 and v = 10
go

update biblia set nvg = 'Ke� P�n videl, �e zloba �ud� na zemi je ve�k� a �e v�etko zm���anie ich srdca je ustavi�ne naklonen� k zlu, ' where spis = 'Gn' and vers = 1 and k = 6 and v = 5
update biblia set nvg = 'o�utoval, �e urobil �loveka na zemi, a bolelo ho srdce. P�n povedal: ' where spis = 'Gn' and vers = 1 and k = 6 and v = 6
update biblia set nvg = '"Vyhub�m z povrchu zeme �loveka, ktor�ho som stvoril: �lovekom po�n�c a� po dobytok, plazy a nebesk� vt�ctvo, lebo �utujem, �e som ich urobil."' where spis = 'Gn' and vers = 1 and k = 6 and v = 7
update biblia set nvg = 'Ale Noe na�iel milos� u P�na.' where spis = 'Gn' and vers = 1 and k = 6 and v = 8
go
update biblia set nvg = 'Preto P�n povedal Noemovi: "Vojdi s celou svojou rodinou do kor�ba, lebo som videl, �e si spravodliv� predo mnou uprostred tohoto pokolenia. ' where spis = 'Gn' and vers = 1 and k = 7 and v = 1
update biblia set nvg = 'Zo v�etk�ch �ist�ch zvierat vezmi po sedem p�rov, samca a samicu; z ne�ist�ch zvierat po p�re, samca a samicu. ' where spis = 'Gn' and vers = 1 and k = 7 and v = 2
update biblia set nvg = 'Aj z nebesk�ho vt�ctva vezme� po sedem p�rov, samca a samicu, aby sa zachovalo potomstvo na celej zemi. ' where spis = 'Gn' and vers = 1 and k = 7 and v = 3
update biblia set nvg = 'Lebo e�te sedem dn� a potom d�m pr�a� na zem �tyridsa� dn� a �tyridsa� noc� a vyhub�m z povrchu zeme v�etky bytosti, ktor� som urobil."' where spis = 'Gn' and vers = 1 and k = 7 and v = 4
update biblia set nvg = 'Noe urobil v�etko, �o mu P�n rozk�zal. ' where spis = 'Gn' and vers = 1 and k = 7 and v = 5
go
update biblia set nvg = 'A ke� pre�lo sedem dn�, privalili sa na zem vody potopy.' where spis = 'Gn' and vers = 1 and k = 7 and v = 10
go

-- 572	Gn 8, 6-13. 20-22
update biblia set lc_id = 572 where spis = 'Gn' and vers = 1 and k = 8 and v between 6 and 13 -- je tam aj ver� 14 pod�a SSV; NVg m� v. 13
update biblia set lc_id = 572 where spis = 'Gn' and vers = 1 and k = 8 and v between 20 and 22
go

update biblia set nvg = 'Ke� uplynulo �tyridsa� dn�, Noe otvoril na kor�be okno, ktor� bol urobil, ' where spis = 'Gn' and vers = 1 and k = 8 and v = 6
update biblia set nvg = 'a vypustil krkavca. Ten odlietal a prilietal, k�m vody na zemi nevyschli.' where spis = 'Gn' and vers = 1 and k = 8 and v = 7
update biblia set nvg = 'Vypustil von aj holubicu, aby zvedel, �i u� vody stiekli z povrchu zeme. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 8
update biblia set nvg = 'Ale ke� nena�la miesto, kde by spo�inula jej noha, vr�tila sa k nemu do kor�ba; po celej zemi boli e�te vody. Noe vystrel ruku, chytil ju a vzal ju do kor�ba.' where spis = 'Gn' and vers = 1 and k = 8 and v = 9
update biblia set nvg = '�akal e�te sedem dn� a znova vypustil z kor�ba holubicu. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 10
update biblia set nvg = 'A ona k nemu priletela a� v podve�er a v zob�ku priniesla olivov� ratoles� so zelen�mi listami. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 11
update biblia set nvg = 'Tu Noe poznal, �e vody zo zeme zmizli. �akal e�te �al��ch sedem dn� a vypustil holubicu, ktor� sa u� k nemu nevr�tila.' where spis = 'Gn' and vers = 1 and k = 8 and v = 12
update biblia set nvg = 'V �es�stoprvom roku, v prvom mesiaci, v prv� de� mesiaca, vody na zemi vyschli. Noe otvoril strechu kor�ba, pozrel sa von a videl, �e povrch zeme je such�.' where spis = 'Gn' and vers = 1 and k = 8 and v = 13
-- update biblia set nvg = null where spis = 'Gn' and vers = 1 and k = 8 and v = 14
go
update biblia set nvg = 'Potom postavil olt�r P�novi, vzal zo v�etk�ho �ist�ho dobytka a z �ist�ch vt�kov a priniesol z�paln� obetu na olt�ri.' where spis = 'Gn' and vers = 1 and k = 8 and v = 20
update biblia set nvg = 'P�n zavo�al pr�jemn� v��u a povedal si: "U� nikdy neprek�ajem zem pre �loveka, lebo zm���anie �udsk�ho srdca je od mladosti n�klonn� na zl�. Preto u� nikdy nevyhub�m v�etky �iv� bytosti, ako som to urobil.' where spis = 'Gn' and vers = 1 and k = 8 and v = 21
update biblia set nvg = 'K�m potrv� zem, neprestane sejba a �atva, chlad a hor��os�, leto a zima, de� a noc."' where spis = 'Gn' and vers = 1 and k = 8 and v = 22
go

-- 573	Gn 9, 1-13
-- 574	Gn 9, 8-15
update biblia set lc_id = 573 where spis = 'Gn' and vers = 1 and k = 9 and v between 1 and 13
update biblia set lc_id = 574 where spis = 'Gn' and vers = 1 and k = 9 and v between 14 and 15
go

update biblia set nvg = 'Boh po�ehnal Noema a jeho synov a povedal im: "Vzrastajte, mno�te sa a napl�te zem! ' where spis = 'Gn' and vers = 1 and k = 9 and v = 1
update biblia set nvg = 'Nech maj� pred vami strach a hr�zu v�etky pozemsk� zvierat� i v�etko nebesk� vt�ctvo a v�etko, �o sa h�be na zemi! Vo va�ich ruk�ch s� v�etky morsk� ryby. ' where spis = 'Gn' and vers = 1 and k = 9 and v = 2
update biblia set nvg = 'V�etko, �o sa h�be a �ije, bude v�m sl��i� za pokrm; d�vam v�m v�etko, ako kedysi zelen� byliny.' where spis = 'Gn' and vers = 1 and k = 9 and v = 3
update biblia set nvg = 'Len m�so s du�ou, ktor� je v krvi, nebudete jes�. ' where spis = 'Gn' and vers = 1 and k = 9 and v = 4
update biblia set nvg = 'Lebo aj za va�u krv budem bra� na zodpovednos� ka�d� zviera. Za �ivot �loveka budem bra� na zodpovednos� �loveka, jeho brata. ' where spis = 'Gn' and vers = 1 and k = 9 and v = 5
update biblia set nvg = 'Ak niekto preleje krv �loveka, in� �lovek nech preleje jeho krv, lebo �lovek bol na Bo�� obraz stvoren�.' where spis = 'Gn' and vers = 1 and k = 9 and v = 6
update biblia set nvg = 'Vy v�ak vzrastajte, mno�te sa, roz��rte sa po zemi a ovl�dnite ju!"' where spis = 'Gn' and vers = 1 and k = 9 and v = 7
update biblia set nvg = 'Aj toto povedal Boh Noemovi a jeho synom: ' where spis = 'Gn' and vers = 1 and k = 9 and v = 8
update biblia set nvg = '"H�a, ja uzavriem zmluvu s vami a s va��m potomstvom ' where spis = 'Gn' and vers = 1 and k = 9 and v = 9
update biblia set nvg = 'i so v�etk�mi �iv�mi bytos�ami, �o s� s vami: s vt�kmi i s dobytkom a so v�etkou zverou zeme, �o je s vami, so v�etk�m, �o vy�lo z kor�ba; so v�etk�mi zvieratami na zemi. ' where spis = 'Gn' and vers = 1 and k = 9 and v = 10
update biblia set nvg = 'Uzavriem s vami zmluvu a u� nikdy nezahynie v�etko �iv� vo vod�ch potopy, u� nikdy nebude potopa, ktor� by spusto�ila zem."' where spis = 'Gn' and vers = 1 and k = 9 and v = 11
update biblia set nvg = 'A Boh povedal: "Toto je znak zmluvy, ktor� uzatv�ram medzi mnou a vami a medzi v�etk�mi �iv�mi bytos�ami, �o s� s vami, pre v�etky bud�ce pokolenia: ' where spis = 'Gn' and vers = 1 and k = 9 and v = 12
update biblia set nvg = 'Do oblakov vlo��m svoj obl�k a bude znamen�m zmluvy medzi mnou a zemou.' where spis = 'Gn' and vers = 1 and k = 9 and v = 13
update biblia set nvg = 'Ke� nahromad�m oblaky nad zemou a ke� sa v oblakoch zjav� d�ha, ' where spis = 'Gn' and vers = 1 and k = 9 and v = 14
update biblia set nvg = 'vtedy si spomeniem na svoju zmluvu s vami a s ka�dou �ivou bytos�ou, ktor� m� telo. Nebud� u� vody potopy a nezni�ia nijak� telo."' where spis = 'Gn' and vers = 1 and k = 9 and v = 15
go

-- 526	Gn 11, 1-9
-- 527	Gn 11, 1-9
update biblia set lc_id = 527 where spis = 'Gn' and vers = 1 and k = 11 and v between 1 and 9
go

update biblia set nvg = 'Na celej zemi bol jeden jazyk a rovnak� re�.' where spis = 'Gn' and vers = 1 and k = 11 and v = 1
update biblia set nvg = 'Ke� sa �udia pohli z v�chodu, na�li rovinu v krajine Sennaar a usadili sa na nej.' where spis = 'Gn' and vers = 1 and k = 11 and v = 2
update biblia set nvg = 'Povedali si: "Po�te, narob�me teh�l a vyp�lime ich v ohni." Tehlu pou��vali namiesto kame�a a namiesto malty asfalt. ' where spis = 'Gn' and vers = 1 and k = 11 and v = 3
update biblia set nvg = 'Potom povedali: "Po�te, postav�me si mesto a ve�u, ktorej vrchol bude siaha� do neba. A urob�me si meno, aby sme sa nerozpt�lili po celej zemi."' where spis = 'Gn' and vers = 1 and k = 11 and v = 4
update biblia set nvg = 'P�n v�ak zost�pil, aby sa pod�val na mesto a ve�u, ktor� stavali �udia, ' where spis = 'Gn' and vers = 1 and k = 11 and v = 5
update biblia set nvg = 'a povedal: "H�a, s� jeden n�rod a v�etci hovoria jedn�m jazykom. Toto je za�iatok ich �inov a u� im nebude �a�ko urobi�, �o si zaumienili. ' where spis = 'Gn' and vers = 1 and k = 11 and v = 6
update biblia set nvg = 'Po�te, zost�pime a pom�tieme tam ich re�, aby nik nerozumel re�i druh�ho."' where spis = 'Gn' and vers = 1 and k = 11 and v = 7
update biblia set nvg = 'Tak ich P�n odtia� rozpt�lil po celej zemi a mesto prestali stava�. ' where spis = 'Gn' and vers = 1 and k = 11 and v = 8
update biblia set nvg = 'Preto sa ono vol� B�bel. Lebo tam bola pom�ten� re� celej zeme a P�n ich odtia� rozpt�lil po celej zemi.' where spis = 'Gn' and vers = 1 and k = 11 and v = 9
go

-- 528	Gn 12, 1-4a
-- 529	Gn 12, 1-4a
-- 530	Gn 12, 1-7
-- 531	Gn 12, 1-9
update biblia set lc_id = 531 where spis = 'Gn' and vers = 1 and k = 12 and v between 1 and 9
go

update biblia set nvg = 'P�n povedal Abramovi: "Od�� zo svojej krajiny, od svojich pr�buzn�ch a z domu svojho otca do krajiny, ktor� ti uk�em.' where spis = 'Gn' and vers = 1 and k = 12 and v = 1
update biblia set nvg = 'Urob�m z teba ve�k� n�rod a po�ehn�m �a, osl�vim tvoje meno a bude� po�ehnan�m. ' where spis = 'Gn' and vers = 1 and k = 12 and v = 2
update biblia set nvg = 'Po�ehn�m t�ch, �o �a bud� �ehna�, a prek�ajem t�ch, �o �a bud� prekl�na�. V tebe bud� po�ehnan� v�etky pokolenia zeme."' where spis = 'Gn' and vers = 1 and k = 12 and v = 3
update biblia set nvg = 'A Abram odi�iel, ako mu rozk�zal P�n. // I�iel s n�m aj Lot. Abram mal sedemdesiatp� rokov, ke� odi�iel z Charranu. ' where spis = 'Gn' and vers = 1 and k = 12 and v = 4
update biblia set nvg = 'Vzal svoju �enu Sarai a svojho synovca Lota i cel� majetok, �o nadobudli, aj slu�obn�ctvo, ktor� z�skali v Charrane. Pohli sa a i�li do krajiny Kana�n.' where spis = 'Gn' and vers = 1 and k = 12 and v = 5
update biblia set nvg = 'Ke� do�li do krajiny Kana�n, Abram pre�iel krajinou a� k miestu Sichem, a� k dubu Moreho. Vtedy b�vali v krajine Kana�n�ania.' where spis = 'Gn' and vers = 1 and k = 12 and v = 6
update biblia set nvg = 'Abramovi sa zjavil P�n a povedal mu: "T�to krajinu d�m tvojmu potomstvu." A on tam P�novi, ktor� sa mu zjavil, postavil olt�r.' where spis = 'Gn' and vers = 1 and k = 12 and v = 7
update biblia set nvg = 'Odtia� odi�iel k vrchu, ktor� bol v�chodne od Betelu, a tam postavil svoj stan. Na z�pade mal Betel, na v�chode Hai. Aj tam postavil P�novi olt�r a vz�val P�novo meno. ' where spis = 'Gn' and vers = 1 and k = 12 and v = 8
update biblia set nvg = 'A Abram postupoval zo stanovi��a na stanovi�te a� k Negebu.' where spis = 'Gn' and vers = 1 and k = 12 and v = 9
go

-- 532	Gn 13, 2. 5-18
update biblia set lc_id = 532 where spis = 'Gn' and vers = 1 and k = 13 and v = 1
update biblia set lc_id = 532 where spis = 'Gn' and vers = 1 and k = 13 and v between 5 and 18
go

update biblia set nvg = 'Abram bol ve�mi bohat�: mal st�da, striebro a zlato. ' where spis = 'Gn' and vers = 1 and k = 13 and v = 1
update biblia set nvg = 'Ale aj Lot, ktor� �iel s Abramom, mal st�da oviec, dobytok a stany. ' where spis = 'Gn' and vers = 1 and k = 13 and v = 5
update biblia set nvg = 'Nesta�ila im krajina, ak mali b�va� vedno; mali to�ko majetku, �e nemohli zosta� spolu.' where spis = 'Gn' and vers = 1 and k = 13 and v = 6
update biblia set nvg = 'Medzi pastiermi Abramov�ch st�d a pastiermi Lotov�ch st�d vznikol spor. A v krajine b�vali vtedy Kana�n�ania a Ferezej�ania.' where spis = 'Gn' and vers = 1 and k = 13 and v = 7
update biblia set nvg = 'Preto povedal Abram Lotovi: "Nech nie s� rozbroje medzi mnou a tebou, medzi mojimi pastiermi a tvojimi pastiermi; sme predsa bratia! ' where spis = 'Gn' and vers = 1 and k = 13 and v = 8
update biblia set nvg = 'Nie je pred tebou cel� krajina? Preto, pros�m, odl�� sa odo m�a. Ke� p�jde� na�avo, ja p�jdem napravo; ke� si vyvol� prav� stranu, ja sa poberiem na �av�."' where spis = 'Gn' and vers = 1 and k = 13 and v = 9
update biblia set nvg = 'Lot zdvihol o�i a videl, �e cel� okolie Jord�na a� po Segor je zavla�en� ako P�nova z�hrada a ako Egypt; bolo to predt�m, ako P�n zni�il Sodomu a Gomoru. ' where spis = 'Gn' and vers = 1 and k = 13 and v = 10
update biblia set nvg = 'Preto si Lot vybral krajinu okolo Jord�na a odtiahol na v�chod. Takto sa bratia oddelili jeden od druh�ho. ' where spis = 'Gn' and vers = 1 and k = 13 and v = 11
update biblia set nvg = 'Abram b�val v krajine Kana�n, Lot sa zdr�oval v mest�ch okolo Jord�na a pren�al svoje stany a� po Sodomu.' where spis = 'Gn' and vers = 1 and k = 13 and v = 12
update biblia set nvg = 'No Sodom�ania boli zl� a ve�mi hre�ili proti P�novi.' where spis = 'Gn' and vers = 1 and k = 13 and v = 13
update biblia set nvg = 'P�n povedal Abramovi, ke� sa Lot od neho odl��il: "Zdvihni o�i a z miesta, na ktorom si, pozri na sever a na juh, na v�chod i na z�pad: ' where spis = 'Gn' and vers = 1 and k = 13 and v = 14
update biblia set nvg = 'cel� krajinu, ktor� vid�, d�m tebe a tvojmu potomstvu naveky.' where spis = 'Gn' and vers = 1 and k = 13 and v = 15
update biblia set nvg = 'Rozmno��m tvoje potomstvo a bude ho ako prachu na zemi; ak m��e niekto spo��ta� prach na zemi, bude m�c� aj tvoje potomstvo spo��ta�. ' where spis = 'Gn' and vers = 1 and k = 13 and v = 16
update biblia set nvg = 'Vsta� a prejdi krajinu po d�ke a po ��rke, lebo ju d�m tebe."' where spis = 'Gn' and vers = 1 and k = 13 and v = 17
update biblia set nvg = 'Abram vzal svoj stan a odi�iel b�va� k dubom Mambreho, ktor� s� v Hebrone, a postavil tam olt�r P�novi.' where spis = 'Gn' and vers = 1 and k = 13 and v = 18
go

-- 533	Gn 14, 18-20
update biblia set lc_id = 533 where spis = 'Gn' and vers = 1 and k = 14 and v between 18 and 20
go

update biblia set nvg = 'Melchizedech, kr� Salema, priniesol chlieb a v�no. Bol toti� k�azom najvy��ieho Boha. ' where spis = 'Gn' and vers = 1 and k = 14 and v = 18
update biblia set nvg = 'Po�ehnal Abrama slovami: "Nech Abrama po�ehn� najvy��� Boh, ktor� stvoril nebo i zem. ' where spis = 'Gn' and vers = 1 and k = 14 and v = 19
update biblia set nvg = 'Nech je zveleben� najvy��� Boh, ktor� ti vydal do r�k tvojich nepriate�ov." // Abram mu potom dal desiatok zo v�etk�ho.' where spis = 'Gn' and vers = 1 and k = 14 and v = 20
go

-- 534	Gn 15, 1-12. 17-18
-- 535	Gn 15, 1-6; 21, 1-3
-- 536	Gn 15, 5-12. 17-18
update biblia set lc_id = 534 where spis = 'Gn' and vers = 1 and k = 15 and v between 1 and 12
update biblia set lc_id = 534 where spis = 'Gn' and vers = 1 and k = 15 and v between 17 and 18
update biblia set lc_id = 535 where spis = 'Gn' and vers = 1 and k = 21 and v between 1 and 3
go

update biblia set nvg = 'P�n povedal Abramovi vo viden�: "Neboj sa, Abram! Ja som tvoj ochranca a tvoja odmena bude nesmierna." ' where spis = 'Gn' and vers = 1 and k = 15 and v = 1
update biblia set nvg = 'Abram povedal: "Pane, Bo�e, �o�e mi d�? Odch�dzam bezdetn� a dedi�om m�jho domu bude damask� Eliezer." ' where spis = 'Gn' and vers = 1 and k = 15 and v = 2
update biblia set nvg = 'A Abram dodal: "Ve� si mi nedal potomka a m�j dom�ci sluha bude moj�m dedi�om."' where spis = 'Gn' and vers = 1 and k = 15 and v = 3
update biblia set nvg = 'Ale P�n mu povedal: "Ten nebude tvoj�m dedi�om. Tvoj�m dedi�om bude ten, �o vz�de z tvojho lona."' where spis = 'Gn' and vers = 1 and k = 15 and v = 4
update biblia set nvg = 'Vyviedol ho von a povedal mu: "Pozri na nebo a spo��taj hviezdy, ak m��e�." A uistil ho: "Tak� bude tvoje potomstvo." ' where spis = 'Gn' and vers = 1 and k = 15 and v = 5
update biblia set nvg = 'On uveril P�novi a to sa mu po��talo za spravodlivos�.' where spis = 'Gn' and vers = 1 and k = 15 and v = 6
update biblia set nvg = 'Potom mu povedal: "Ja som P�n, ja som �a vyviedol z Uru Chaldejcov, aby som ti dal do vlastn�ctva t�to krajinu."' where spis = 'Gn' and vers = 1 and k = 15 and v = 7
update biblia set nvg = 'On sa op�tal: "Pane, Bo�e, pod�a �oho spozn�m, �e ju budem vlastni�?"' where spis = 'Gn' and vers = 1 and k = 15 and v = 8
update biblia set nvg = 'P�n odpovedal: "Prines mi trojro�n� jalovicu, trojro�n� kozu a trojro�n�ho barana, hrdli�ku a holubicu."' where spis = 'Gn' and vers = 1 and k = 15 and v = 9
update biblia set nvg = 'On vzal v�etky tieto zvierat�, rozpolil ich a obe polovice polo�il vz�jomne oproti sebe; vt�ky v�ak nerozpolil. ' where spis = 'Gn' and vers = 1 and k = 15 and v = 10
update biblia set nvg = 'Na m�tve tel� zlietali drav� vt�ky a Abram ich odh��al.' where spis = 'Gn' and vers = 1 and k = 15 and v = 11
update biblia set nvg = 'Ke� zapadalo slnko, na Abrama do�ahol tvrd� sp�nok a prenikla ho ve�k�, pr�ern� hr�za.' where spis = 'Gn' and vers = 1 and k = 15 and v = 12
go
update biblia set nvg = 'Ke� u� slnko zapadlo a nastala hust� tma, zjavila sa dymiaca pec a ohniv� pochode�, ktor� prech�dzala pomedzi rozpolen� zvierat�.' where spis = 'Gn' and vers = 1 and k = 15 and v = 17
update biblia set nvg = 'V ten de� P�n uzavrel s Abramom zmluvu slovami: "Tvojmu potomstvu d�m t�to krajinu od Egyptskej rieky a� po ve�k� rieku, Eufrat."' where spis = 'Gn' and vers = 1 and k = 15 and v = 18
go

update biblia set nvg = 'P�n nav�t�vil S�ru, ako pris��bil, a splnil S�re, �o povedal. ' where spis = 'Gn' and vers = 1 and k = 21 and v = 1
update biblia set nvg = 'I po�ala a porodila Abrah�movi syna v jeho starobe, v �ase, ktor� mu predpovedal Boh. ' where spis = 'Gn' and vers = 1 and k = 21 and v = 2
update biblia set nvg = 'A Abrah�m dal svojmu synovi, ktor�ho mu porodila S�ra, meno Iz�k.' where spis = 'Gn' and vers = 1 and k = 21 and v = 3
go

-- 537	Gn 16, 1-12. 15-16
-- 538	Gn 16, 6b-12. 15-16
update biblia set lc_id = 537 where spis = 'Gn' and vers = 1 and k = 16 and v between 1 and 12
update biblia set lc_id = 537 where spis = 'Gn' and vers = 1 and k = 16 and v between 15 and 16
go

update biblia set nvg = 'Abramova �ena Sarai neporodila Abramovi die�a. Mala v�ak sl��ku Egyp�anku menom Agar. ' where spis = 'Gn' and vers = 1 and k = 16 and v = 1
update biblia set nvg = 'I povedala svojmu man�elovi: "Pozri, P�n ma uzavrel, nem��em porodi�. Vojdi k mojej sl��ke. Azda aspo� z nej dostanem synov." On pristal na jej prosbu ' where spis = 'Gn' and vers = 1 and k = 16 and v = 2
update biblia set nvg = 'a ona po desiatich rokoch, ako za�ali b�va� v krajine Kana�n, vzala svoju sl��ku Egyp�anku Agar a dala ju svojmu mu�ovi za �enu. ' where spis = 'Gn' and vers = 1 and k = 16 and v = 3
update biblia set nvg = 'On k nej vo�iel a ke� spozorovala, �e po�ala, opovr�livo h�adela na svoju paniu.' where spis = 'Gn' and vers = 1 and k = 16 and v = 4
update biblia set nvg = 'Sarai povedala Abramovi: "Ubli�uje� mi. Ja som dala svoju sl��ku do tvojho lona a ona, ke� vid�, �e po�ala, mnou opovrhuje. Nech P�n s�di medzi mnou a tebou." ' where spis = 'Gn' and vers = 1 and k = 16 and v = 5
update biblia set nvg = 'Abram jej odvetil: "Ve� je tvoja sl��ka v tvojej moci. Urob s �ou, ako sa ti p��i." A Sarai k nej bola tvrd�, a� od nej u�la.' where spis = 'Gn' and vers = 1 and k = 16 and v = 6
update biblia set nvg = 'Ke� ju na�iel P�nov anjel na p��ti pri prameni na ceste do Suru, ' where spis = 'Gn' and vers = 1 and k = 16 and v = 7
update biblia set nvg = 'povedal jej: "Agar, Saraina sl��ka, odkia� ide� a kam sa uber�?" Ona odpovedala: "Utek�m od svojej panej Sarai."' where spis = 'Gn' and vers = 1 and k = 16 and v = 8
update biblia set nvg = 'P�nov anjel jej povedal: "Vr� sa k svojej panej a bu� jej poddan�." ' where spis = 'Gn' and vers = 1 and k = 16 and v = 9
update biblia set nvg = 'A P�nov anjel jej vravel �alej: "Tak rozmno��m tvoje potomstvo, �e ho pre mno�stvo nebude mo�no spo��ta�." ' where spis = 'Gn' and vers = 1 and k = 16 and v = 10
update biblia set nvg = 'A e�te jej P�nov anjel hovoril: "H�a, po�ala si a porod� syna; nazve� ho menom Izmael, lebo P�n po�ul o tvojom tr�pen�. ' where spis = 'Gn' and vers = 1 and k = 16 and v = 11
update biblia set nvg = 'Bude to �lovek ako div� osol, jeho ruka bude proti v�etk�m a ruky v�etk�ch bud� proti nemu a svoje stany postav� popri svojich bratoch."' where spis = 'Gn' and vers = 1 and k = 16 and v = 12
update biblia set nvg = 'Agar porodila Abramovi syna a on dal svojmu synovi, ktor�ho porodila Agar, meno Izmael. ' where spis = 'Gn' and vers = 1 and k = 16 and v = 15
update biblia set nvg = 'Osemdesiat�es� rokov mal Abram, ke� mu Agar porodila Izmaela.' where spis = 'Gn' and vers = 1 and k = 16 and v = 16
go

-- 539	Gn 17, 1. 4-5. 9-10. 15-22
-- 540	Gn 17, 3-9
update biblia set lc_id = 539 where spis = 'Gn' and vers = 1 and k = 17 and v = 1
update biblia set lc_id = 540 where spis = 'Gn' and vers = 1 and k = 17 and v between 3 and 9
update biblia set lc_id = 539 where spis = 'Gn' and vers = 1 and k = 17 and v = 10
update biblia set lc_id = 539 where spis = 'Gn' and vers = 1 and k = 17 and v between 15 and 22
go

update biblia set nvg = 'Ke� mal Abram dev�desiatdev� rokov, zjavil sa mu P�n a povedal mu: "Ja som Boh, v�emoh�ci, kr��aj predo mnou a bu� dokonal�. ' where spis = 'Gn' and vers = 1 and k = 17 and v = 1
update biblia set nvg = 'Abram padol na tv�r ' where spis = 'Gn' and vers = 1 and k = 17 and v = 3
update biblia set nvg = 'a Boh mu povedal: "H�a, moja zmluva s tebou. Bude� otcom mnoh�ch n�rodov ' where spis = 'Gn' and vers = 1 and k = 17 and v = 4
update biblia set nvg = 'a u� sa nebude� vola� Abram; bude� sa vola� Abrah�m, lebo �a urob�m otcom mnoh�ch n�rodov.' where spis = 'Gn' and vers = 1 and k = 17 and v = 5
update biblia set nvg = 'D�m sa ti rozr�s� pren�ramne, urob�m z teba n�rody, aj kr�li z teba vz�du.' where spis = 'Gn' and vers = 1 and k = 17 and v = 6
update biblia set nvg = 'A uzavriem zmluvu medzi mnou a tebou i medzi tvoj�m potomstvom po tebe vo v�etk�ch pokoleniach, zmluvu ve�n�, �e budem Bohom tvoj�m i tvojho potomstva po tebe.' where spis = 'Gn' and vers = 1 and k = 17 and v = 7
update biblia set nvg = 'Tebe a tvojmu potomstvu po tebe d�m krajinu, v ktorej si ako cudzinec; cel� zem Kana�n do ve�n�ho vlastn�ctva a budem ich Bohom."' where spis = 'Gn' and vers = 1 and k = 17 and v = 8
update biblia set nvg = 'Potom Boh povedal Abrah�movi: "Ale aj ty zachov� moju zmluvu, aj tvoje potomstvo po tebe vo v�etk�ch pokoleniach."' where spis = 'Gn' and vers = 1 and k = 17 and v = 9
update biblia set nvg = 'A toto je moja zmluva medzi mnou a vami i tvoj�m potomstvom po tebe, ktor� budete zachov�va�: Obrezan� bude v�etko, �o je medzi vami rodu mu�sk�ho."' where spis = 'Gn' and vers = 1 and k = 17 and v = 10
go
update biblia set nvg = 'Potom Boh povedal Abrah�movi: "Svoju man�elku Sarai u� nebude� vola� Sarai, lebo bude ma� meno S�ra. ' where spis = 'Gn' and vers = 1 and k = 17 and v = 15
update biblia set nvg = 'Ja ju po�ehn�m a d�m ti aj z nej syna. Po�ehn�m ju a bud� z nej poch�dza� n�rody; aj kr�li n�rodov z nej bud� poch�dza�."' where spis = 'Gn' and vers = 1 and k = 17 and v = 16
update biblia set nvg = 'Abrah�m padol na tv�r a smial sa; povedal si v srdci: "Vari sa m��e storo�n�mu narodi� syn? A dev�desiatro�n� S�ra porod�?" ' where spis = 'Gn' and vers = 1 and k = 17 and v = 17
update biblia set nvg = 'A povedal Bohu: "Keby aspo� Izmael �il pred tvojou tv�rou."' where spis = 'Gn' and vers = 1 and k = 17 and v = 18
update biblia set nvg = 'Ale P�n opakoval: "Tvoja �ena S�ra ti porod� syna a d� mu meno Iz�k a ja s n�m uzavriem zmluvu: ve�n� zmluvu s n�m a s jeho potomstvom. ' where spis = 'Gn' and vers = 1 and k = 17 and v = 19
update biblia set nvg = 'A vypo�ul som �a, aj �o sa t�ka Izmaela: po�ehn�m ho, d�m mu plodnos� a rozmno��m ho n�ramne. Dvan�s� knie�at sa z neho narod� a urob�m z neho ve�k� n�rod. ' where spis = 'Gn' and vers = 1 and k = 17 and v = 20
update biblia set nvg = 'Ale svoju zmluvu uzavriem s Iz�kom, ktor�ho ti porod� S�ra o takomto �ase na bud�ci rok." ' where spis = 'Gn' and vers = 1 and k = 17 and v = 21
update biblia set nvg = 'Ke� sa s n�m Boh prestal rozpr�va�, odi�iel od Abrah�ma.' where spis = 'Gn' and vers = 1 and k = 17 and v = 22
go

-- SSV preklad nem� ver� Gn 18, 33, len ver� 32, preto to d�vame spolo�ne do v. 32
-- 541	Gn 18, 1-10a
-- 542	Gn 18, 1-15
-- 543	Gn 18, 16-33
-- 544	Gn 18, 20-32
update biblia set lc_id = 542 where spis = 'Gn' and vers = 1 and k = 18 and v between 1 and 15
update biblia set lc_id = 543 where spis = 'Gn' and vers = 1 and k = 18 and v between 16 and 33
go

update biblia set nvg = 'Abrah�movi sa zjavil P�n pri duboch Mambreho, ke� sedel za najv��ej hor��avy d�a pri vchode do svojho stanu. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 1
update biblia set nvg = 'Ke� zdvihol o�i, zbadal ne�aleko st� troch mu�ov. Len �o ich zazrel, utekal im od vchodu do stanu v �strety, poklonil sa a� po zem ' where spis = 'Gn' and vers = 1 and k = 18 and v = 2
update biblia set nvg = 'a povedal: "Pane, ak som na�iel priaze� v tvojich o�iach, neob�� svojho slu�obn�ka. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 3
update biblia set nvg = 'Prines� trochu vody, umyjete si nohy a odpo�iniete si pod stromom. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 4
update biblia set nvg = 'Donesiem k�sok chleba a posiln�te sa; potom m��ete �s� �alej. Ve� preto ste zabo�ili k svojmu slu�obn�kovi." Oni odpovedali: "Urob, ako vrav�!"' where spis = 'Gn' and vers = 1 and k = 18 and v = 5
update biblia set nvg = 'Abrah�m sa popon�h�al do stanu k S�re a povedal: "R�chlo zamies tri miery m�ky a nape� podplamenn�ky!"' where spis = 'Gn' and vers = 1 and k = 18 and v = 6
update biblia set nvg = 'S�m be�al k st�du, vybral pekn� mlad� te�a, dal ho sluhovi a ten sa pon�h�al pripravi� ho. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 7
update biblia set nvg = 'Potom vzal maslo, mlieko a pripraven� te�a a predlo�il im to. S�m st�l pri nich pod stromom; a oni jedli.' where spis = 'Gn' and vers = 1 and k = 18 and v = 8
update biblia set nvg = 'Potom sa ho p�tali: "Kde je tvoja �ena S�ra?" On odpovedal: "Tu, v stane."' where spis = 'Gn' and vers = 1 and k = 18 and v = 9
update biblia set nvg = 'A P�n mu povedal: "O rok o takomto �ase sa vr�tim k tebe a tvoja man�elka S�ra bude ma� syna." Ke� to S�ra po�ula, smiala sa pri vchode do stanu, ktor� bol za n�m. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 10
update biblia set nvg = 'Ve� obaja boli starci, vo vysokom veku, a S�re u� d�vno prestalo, �o m�vaj� �eny. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 11
update biblia set nvg = 'Preto sa potajomky zasmiala a myslela si: "Teraz, ke� som u� star�, m�m myslie� na rozko�? Aj m�j p�n je u� starec."' where spis = 'Gn' and vers = 1 and k = 18 and v = 12
update biblia set nvg = 'P�n povedal Abrah�movi: "Pre�o sa S�ra smeje a mysl� si: ��i m��em naozaj porodi�, tak�to starena?� ' where spis = 'Gn' and vers = 1 and k = 18 and v = 13
update biblia set nvg = 'Vari je P�novi nie�o nemo�n�? O rok o takomto �ase sa vr�tim k tebe a S�ra bude ma� syna."' where spis = 'Gn' and vers = 1 and k = 18 and v = 14
update biblia set nvg = 'S�ra zapierala: "Nesmiala som sa," lebo sa b�la. Ale P�n povedal: "Nie. Smiala si sa."' where spis = 'Gn' and vers = 1 and k = 18 and v = 15
update biblia set nvg = 'Mu�ovia sa z �dolia Mambreho pobrali a zamierili k Sodome. Abrah�m i�iel s nimi odprevadi� ich.' where spis = 'Gn' and vers = 1 and k = 18 and v = 16
update biblia set nvg = 'A P�n povedal: "M��em pred Abrah�mom taji�, �o chcem urobi�?! ' where spis = 'Gn' and vers = 1 and k = 18 and v = 17
update biblia set nvg = 'Ve� z neho m� by� ve�k� a mocn� n�rod a v �om maj� by� po�ehnan� v�etky n�rody zeme. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 18
update biblia set nvg = 'Lebo jeho som si vyvolil, aby svojim synom a svojmu domu po sebe prik�zal zachov�va� P�novu cestu a kona� pod�a spravodlivosti a pr�va, aby P�n mohol splni� na Abrah�movi v�etko, �o mu s��bil."' where spis = 'Gn' and vers = 1 and k = 18 and v = 19
update biblia set nvg = 'Preto P�n povedal: "�aloba na Sodomu a Gomoru je ve�k� a ich hriech je ve�mi �a�k�. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 20
update biblia set nvg = 'Zost�pim a pozriem sa, �i naozaj robia tak, ako znie �aloba, �o do�la ku mne, a �i nie. Chcem to vedie�."' where spis = 'Gn' and vers = 1 and k = 18 and v = 21
update biblia set nvg = 'Mu�i sa odtia� obr�tili a i�li do Sodomy, k�m Abrah�m st�le e�te st�l pred P�nom.' where spis = 'Gn' and vers = 1 and k = 18 and v = 22
update biblia set nvg = 'Prist�pil bli��ie a povedal: "Chce� naozaj zahubi� spravodliv�ho s bezbo�n�m? ' where spis = 'Gn' and vers = 1 and k = 18 and v = 23
update biblia set nvg = 'A keby bolo v meste p�desiat spravodliv�ch, zahubil by si ich a neodpustil by si mestu kv�li p�desiatim spravodliv�m, �o s� v �om?' where spis = 'Gn' and vers = 1 and k = 18 and v = 24
update biblia set nvg = 'Nech je �aleko od teba urobi� nie�o tak�: spravodliv�ho usmrti� s bezbo�n�m. Spravodliv� by bol na tom rovnako ako bezbo�n�. To nech je �aleko od teba. Vari ten, �o s�di cel� zem, nebude kona� spravodlivo?"' where spis = 'Gn' and vers = 1 and k = 18 and v = 25
update biblia set nvg = 'P�n mu povedal: "Ak v meste Sodome n�jdem p�desiat spravodliv�ch, odpust�m kv�li nim cel�mu mestu."' where spis = 'Gn' and vers = 1 and k = 18 and v = 26
update biblia set nvg = 'Abrah�m povedal: "Opov�il som sa rozpr�va� so svoj�m P�nom, hoci som len prach a popol. ' where spis = 'Gn' and vers = 1 and k = 18 and v = 27
update biblia set nvg = '�o ak bude spravodliv�ch o p� menej ako p�desiat? Zni�� kv�li piatim cel� mesto?" // "Nezni��m," odpovedal, "ak ich tam n�jdem �tyridsa�p�."' where spis = 'Gn' and vers = 1 and k = 18 and v = 28
update biblia set nvg = 'Abrah�m mu znova povedal: "A �o ak sa ich tam n�jde len �tyridsa�?" Odpovedal: "Kv�li �tyridsiatim ich nezni��m."' where spis = 'Gn' and vers = 1 and k = 18 and v = 29
update biblia set nvg = '"Nehnevaj sa, pros�m, P�n m�j," pokra�oval �alej, "�e e�te hovor�m: A ak sa ich tam n�jde len tridsa�?" Odpovedal: "Neurob�m to, ak ich tam n�jdem tridsa�."' where spis = 'Gn' and vers = 1 and k = 18 and v = 30
update biblia set nvg = 'Abrah�m povedal: "Opov�il som sa rozpr�va� so svoj�m P�nom: �o ak sa ich tam n�jde dvadsa�?" P�n odpovedal: "Nezahub�m ich kv�li dvadsiatim."' where spis = 'Gn' and vers = 1 and k = 18 and v = 31
update biblia set nvg = '"Pros�m, nech sa nehnev� m�j P�n," pokra�oval, "�e e�te raz prehovor�m: A �o ak sa ich tam n�jde len desa�?" Odpovedal: "Kv�li desiatim ich nezahub�m." // (NVg: v. 33) Ke� sa P�n prestal rozpr�va� s Abrah�mom, odi�iel a Abrah�m sa vr�til na svoje miesto.' where spis = 'Gn' and vers = 1 and k = 18 and v = 32
go

-- 545	Gn 19, 15-29
update biblia set lc_id = 545 where spis = 'Gn' and vers = 1 and k = 19 and v between 15 and 29
go

update biblia set nvg = '[...] Anjeli naliehali na Lota: "Vsta�, vezmi svoju �enu a obe dc�ry, ktor� tu m�, aby si nezahynul v zlo�innom meste." ' where spis = 'Gn' and vers = 1 and k = 19 and v = 15
update biblia set nvg = 'A ke� v�hal, chytili ho mu�i za ruku i jeho �enu a obe dc�ry, lebo P�n ho chcel zachr�ni�, vyviedli ho von a nechali ho za mestom.' where spis = 'Gn' and vers = 1 and k = 19 and v = 16
update biblia set nvg = 'Tam anjel povedal: "Zachr�� sa, ide ti o �ivot. Neobzeraj sa a nezastavuj sa nikde v tomto okol�. H�adaj �to�i�te v hor�ch, aby si nezahynul."' where spis = 'Gn' and vers = 1 and k = 19 and v = 17
update biblia set nvg = 'Lot im povedal: "Pros�m, nie, Pane. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 18
update biblia set nvg = 'Tvoj sluha na�iel milos� pred tebou a ve�k� je tvoje milosrdenstvo, ktor� si mi preuk�zal, ke� si mi zachr�nil �ivot. Ale do h�r ujs� nevl�dzem, zachyt� ma pohroma a umriem. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 19
update biblia set nvg = 'Pozri, tu ne�aleko je mal� mesto, tam m��em ujs�, v �om sa zachr�nim. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 20
update biblia set nvg = '�i nie je mal�? A ja ostanem na�ive." // On mu povedal: "Nu� dobre, aj t�to tvoju prosbu vysly��m a mesto, za ktor� sa prihov�ra�, nezni��m. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 21
update biblia set nvg = 'Utekaj a skry sa tam, lebo nem��em ni� robi�, k�m ta ned�jde�." Preto sa to mesto vol� Segor.' where spis = 'Gn' and vers = 1 and k = 19 and v = 22
update biblia set nvg = 'Nad krajinu vy�lo slnko, ke� Lot do�iel do Segoru. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 23
update biblia set nvg = 'Vtedy P�n spustil na Sodomu a Gomoru s�ru a ohe� z neba od P�na ' where spis = 'Gn' and vers = 1 and k = 19 and v = 24
update biblia set nvg = 'a zni�il obe mest� i cel� okolit� kraj; v�etk�ch obyvate�ov miest a v�etky po�n� rastliny. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 25
update biblia set nvg = 'Jeho �ena sa obzrela za seba a premenila sa na so�n� st�p.' where spis = 'Gn' and vers = 1 and k = 19 and v = 26
update biblia set nvg = 'Ke� Abrah�m r�no vstal, i�iel na miesto, kde predt�m st�l s P�nom, ' where spis = 'Gn' and vers = 1 and k = 19 and v = 27
update biblia set nvg = 'pozrel sa na Sodomu a Gomoru a na cel� kraj okolo a videl vystupova� zo zeme �erav� popol a dym ako z pece. ' where spis = 'Gn' and vers = 1 and k = 19 and v = 28
update biblia set nvg = 'Ke� Boh ni�il mest� a okolie tohoto kraja, spomenul si na Abrah�ma a Lota zachr�nil zo skazy miest, v ktor�ch b�val.' where spis = 'Gn' and vers = 1 and k = 19 and v = 29
go

-- 550	Gn 21, 5. 8-20
update biblia set lc_id = 550 where spis = 'Gn' and vers = 1 and k = 21 and v = 1
update biblia set lc_id = 550 where spis = 'Gn' and vers = 1 and k = 21 and v between 8 and 20
go

update biblia set nvg = 'Ke� mal Abrah�m sto rokov, narodil sa mu syn Iz�k.' where spis = 'Gn' and vers = 1 and k = 21 and v = 1
update biblia set nvg = 'Chlapec vyr�stol a odstavili ho. V de� odstavenia urobil Abrah�m ve�k� hostinu.' where spis = 'Gn' and vers = 1 and k = 21 and v = 8
update biblia set nvg = 'A ke� S�ra videla, ako syn Egyp�anky Agar �ant� s jej synom Iz�kom, ' where spis = 'Gn' and vers = 1 and k = 21 and v = 9
update biblia set nvg = 'povedala Abrah�movi: "Vy�e� sl��ku i jej syna, lebo syn sl��ky nesmie dedi� s moj�m synom Iz�kom!" ' where spis = 'Gn' and vers = 1 and k = 21 and v = 10
update biblia set nvg = 'Abrah�ma sa to ve�mi dotklo, ve� to bol jeho syn.' where spis = 'Gn' and vers = 1 and k = 21 and v = 11
update biblia set nvg = 'Ale Boh mu povedal: "Netr�p sa kv�li chlapcovi a svojej sl��ke. Po��vni v�etko, �o ti povedala S�ra, lebo pod�a Iz�ka sa bude vola� tvoje potomstvo. ' where spis = 'Gn' and vers = 1 and k = 21 and v = 12
update biblia set nvg = 'Ale aj zo syna sl��ky urob�m ve�k� n�rod, preto�e je tvoj�m potomkom."' where spis = 'Gn' and vers = 1 and k = 21 and v = 13
update biblia set nvg = 'Abrah�m teda skoro r�no vstal, vzal chlieb a mech s vodou, nalo�il to Agar na chrb�t, dal jej chlapca a prepustil ju. Ona odi�la a bl�dila po p��ti Bersabe. ' where spis = 'Gn' and vers = 1 and k = 21 and v = 14
update biblia set nvg = 'A ke� sa minula voda z mecha, polo�ila chlapca pod ker, ' where spis = 'Gn' and vers = 1 and k = 21 and v = 15
update biblia set nvg = 'poodi�la a sadla si opodia�, asi akoby ��pom dostrelil, lebo si vravela: "Nem��em h�adie�, ako die�a zomiera." Tak sedela ob�ale� a nahlas plakala.' where spis = 'Gn' and vers = 1 and k = 21 and v = 16
update biblia set nvg = 'Ale Boh po�ul hlas chlapca a bo�� anjel zavolal z neba na Agar: "�o ti je, Agar? Neboj sa, Boh po�ul hlas chlapca z miesta, kde je. ' where spis = 'Gn' and vers = 1 and k = 21 and v = 17
update biblia set nvg = 'Vsta�, vezmi chlapca a staraj sa o�, lebo z neho urob�m ve�k� n�rod."' where spis = 'Gn' and vers = 1 and k = 21 and v = 18
update biblia set nvg = 'Boh jej otvoril o�i a zbadala prame� vody. I�la, naplnila si mech a napojila chlapca.' where spis = 'Gn' and vers = 1 and k = 21 and v = 19
update biblia set nvg = 'Boh bol s n�m; a ke� vyr�stol, b�val na p��ti a stal sa z neho mlad� lukostrelec.' where spis = 'Gn' and vers = 1 and k = 21 and v = 20
go

-- 551	Gn 22, 1-18
-- 552	Gn 22, 1-19
-- 553	Gn 22, 1-2. 9a. 10-13. 15-18
-- 554	Gn 22, 1-2. 9a. 10-13. 15-18
update biblia set lc_id = 552 where spis = 'Gn' and vers = 1 and k = 22 and v between 1 and 19
update biblia set lh_id = 'VTROJ_cCIT2_NE' where spis = 'Gn' and vers = 1 and k = 22 and v between 1 and 18
go

update biblia set nvg = 'Boh sk��al Abrah�ma a povedal mu: �Abrah�m!� On odpovedal: �Tu som.�' where spis = 'Gn' and vers = 1 and k = 22 and v = 1
update biblia set nvg = 'Boh hovoril: �Vezmi svojho jedin�ho syna Iz�ka, ktor�ho miluje�, cho� do krajiny Moria a obetuj ho tam ako z�paln� obetu na vrchu, ktor� ti uk�em.�' where spis = 'Gn' and vers = 1 and k = 22 and v = 2
update biblia set nvg = 'Abrah�m vstal e�te za noci, osedlal osla, vzal so sebou dvoch sluhov a svojho syna Iz�ka, na�tiepal dreva na z�paln� obetu a vybral sa na miesto, ktor� mu Boh ozna�il. ' where spis = 'Gn' and vers = 1 and k = 22 and v = 3
update biblia set nvg = 'Ke� na tret� de� Abrah�m zdvihol o�i, z�aleka uzrel to miesto ' where spis = 'Gn' and vers = 1 and k = 22 and v = 4
update biblia set nvg = 'a povedal svojim sluhom: ��akajte tu s_oslom. Ja a chlapec p�jdeme a� ta, poklon�me sa a vr�time sa k_v�m.�' where spis = 'Gn' and vers = 1 and k = 22 and v = 5
update biblia set nvg = 'Potom Abrah�m vzal drevo na z�paln� obetu a nalo�il ho na svojho syna Iz�ka. S�m niesol v_ruk�ch ohe� a n��. Ako i�li sami dvaja, ' where spis = 'Gn' and vers = 1 and k = 22 and v = 6
update biblia set nvg = 'vravel Iz�k svojmu otcovi Abrah�movi: �Ot�e!� On mu odpovedal: ��o chce�, syn m�j?� �Pozri,� hovor� Iz�k, �ohe� a drevo je tu, a bar�nok na z�paln� obetu je kde?� ' where spis = 'Gn' and vers = 1 and k = 22 and v = 7
update biblia set nvg = 'Abrah�m odvetil: �Boh si zaobstar� bar�nka na obetu, syn m�j.� A vedno �li �alej.' where spis = 'Gn' and vers = 1 and k = 22 and v = 8
update biblia set nvg = 'Ke� do�li na miesto, ktor� mu uk�zal Boh, Abrah�m postavil olt�r, poukladal na� drevo, zviazal svojho syna Iz�ka a polo�il ho na olt�r, na drevo. ' where spis = 'Gn' and vers = 1 and k = 22 and v = 9
update biblia set nvg = 'Potom Abrah�m vystrel ruku, vzal n�� a chcel obetova� svojho syna.' where spis = 'Gn' and vers = 1 and k = 22 and v = 10
update biblia set nvg = 'Ale vtom na� zavolal anjel P�na z_neba: �Abrah�m, Abrah�m!� // On odpovedal: �Tu som.�' where spis = 'Gn' and vers = 1 and k = 22 and v = 11
update biblia set nvg = 'Anjel mu povedal: �Nevz�ahuj ruku na chlapca a neubl� mu! Teraz viem, �e sa boj� Boha, ve� si mi neodoprel svojho jedin�ho syna.�' where spis = 'Gn' and vers = 1 and k = 22 and v = 12
update biblia set nvg = 'Abrah�m zdvihol o�i a uzrel barana zachyten�ho rohami v_krov�. Vzal ho a obetoval namiesto svojho syna ako z�paln� obetu.' where spis = 'Gn' and vers = 1 and k = 22 and v = 13
update biblia set nvg = 'A toto miesto nazval �P�n sa star�; a tak sa a� podnes hovor�: �Na vrchu P�n sa star�.' where spis = 'Gn' and vers = 1 and k = 22 and v = 14
update biblia set nvg = 'Anjel P�na znova zavolal z_neba na Abrah�ma: ' where spis = 'Gn' and vers = 1 and k = 22 and v = 15
update biblia set nvg = '�Na seba sam�ho prisah�m � tak� je v�rok P�na �: Preto�e si toto urobil a neodoprel si mi svojho jedin�ho syna, ' where spis = 'Gn' and vers = 1 and k = 22 and v = 16
update biblia set nvg = 'po�ehn�m �a a rozmno��m tvoje potomstvo ako hviezdy na nebi a ako piesok na brehu mora a tvoje potomstvo sa zmocn� br�n svojich nepriate�ov. ' where spis = 'Gn' and vers = 1 and k = 22 and v = 17
update biblia set nvg = 'A preto�e si posl�chol m�j hlas, v_tvojom potomstve bud� po�ehnan� v�etky n�rody zeme.�' where spis = 'Gn' and vers = 1 and k = 22 and v = 18
update biblia set nvg = 'Potom sa Abrah�m vr�til k svojim sluhom a v�etci spolu sa pobrali do Bersaby. A Abrah�m ostal b�va� v Bersabe.' where spis = 'Gn' and vers = 1 and k = 22 and v = 19
go

-- 555	Gn 23, 1-4. 19; 24, 1-8. 62-67
update biblia set lc_id = 555 where spis = 'Gn' and vers = 1 and k = 23 and v between 1 and 4
update biblia set lc_id = 555 where spis = 'Gn' and vers = 1 and k = 23 and v = 19
update biblia set lc_id = 555 where spis = 'Gn' and vers = 1 and k = 24 and v between 1 and 8
update biblia set lc_id = 555 where spis = 'Gn' and vers = 1 and k = 24 and v between 62 and 67
go

update biblia set nvg = 'S�ra sa do�ila stodvadsa�sedem rokov ' where spis = 'Gn' and vers = 1 and k = 23 and v = 1
update biblia set nvg = 'a zomrela v Kariatarb�, �o je Hebron, v krajine Kana�n. Abrah�m i�iel sm�ti� za �ou a oplak�va� ju.' where spis = 'Gn' and vers = 1 and k = 23 and v = 2
update biblia set nvg = 'Potom preru�il pohrebn� obrad a povedal Hetejcom: ' where spis = 'Gn' and vers = 1 and k = 23 and v = 3
update biblia set nvg = '"Som u v�s len cudzinec a hos�. Dajte mi u v�s miesto na dedi�n� hrobku, kde by som mohol pochova� svoju m�tvu."' where spis = 'Gn' and vers = 1 and k = 23 and v = 4
go
update biblia set nvg = 'Potom Abrah�m pochoval svoju �enu S�ru v jaskyni na pozemku Makpela oproti Mambre, �o je Hebron, v krajine Kana�n. ' where spis = 'Gn' and vers = 1 and k = 23 and v = 19
go
update biblia set nvg = 'Abrah�m bol u� starec vysok�ho veku a P�n ho vo v�etkom po�ehn�val.' where spis = 'Gn' and vers = 1 and k = 24 and v = 1
update biblia set nvg = 'Tu Abrah�m povedal najstar�iemu sluhovi svojho domu, ktor� spravoval cel� jeho majetok: "Polo� svoju ruku pod moje bedr� ' where spis = 'Gn' and vers = 1 and k = 24 and v = 2
update biblia set nvg = 'a zaprisah�m �a na P�na, Boha neba i zeme, �e m�jmu synovi nevezme� �enu z dc�r Kana�ncov, medzi ktor�mi b�vam, ' where spis = 'Gn' and vers = 1 and k = 24 and v = 3
update biblia set nvg = 'ale p�jde� do mojej vlasti, k mojim pr�buzn�m a tam vyberie� �enu pre m�jho syna Iz�ka."' where spis = 'Gn' and vers = 1 and k = 24 and v = 4
update biblia set nvg = 'Sluha odvetil: "A ak �ena nebude chcie� �s� so mnou do tejto krajiny, m�m tvojho syna zavies� nasp� do krajiny, z ktorej si vy�iel?"' where spis = 'Gn' and vers = 1 and k = 24 and v = 5
update biblia set nvg = 'Abrah�m mu povedal: "Neopov� sa; nikdy ta nesmie� zavies� m�jho syna! ' where spis = 'Gn' and vers = 1 and k = 24 and v = 6
update biblia set nvg = 'P�n, Boh nebies, ktor� ma vyviedol z domu m�jho otca a z m�jho rodn�ho kraja, ktor� so mnou hovoril a prisahal mi: �T�to zem d�m tvojmu potomstvu,� po�le pred tebou svojho anjela, aby si tam vybral �enu m�jmu synovi. ' where spis = 'Gn' and vers = 1 and k = 24 and v = 7
update biblia set nvg = 'A keby �ena nechcela �s� s tebou, t�to pr�saha �a nevia�e. Len m�jho syna ta nevo�!"' where spis = 'Gn' and vers = 1 and k = 24 and v = 8
go
update biblia set nvg = 'Iz�k pri�iel od studne Lachajroi a b�val v Negebe. ' where spis = 'Gn' and vers = 1 and k = 24 and v = 62
update biblia set nvg = 'Na sklonku d�a vy�iel Iz�k do po�a �iali�. Ke� zdvihol o�i, videl prich�dza� �avy.' where spis = 'Gn' and vers = 1 and k = 24 and v = 63
update biblia set nvg = 'Aj Rebeka zdvihla o�i a zbadala Iz�ka. Zosadla z �avy ' where spis = 'Gn' and vers = 1 and k = 24 and v = 64
update biblia set nvg = 'a op�tala sa sluhu: "Kto je tamten �lovek, �o n�m ide oproti po poli?" On jej odpovedal: "To je m�j p�n." R�chlo vzala z�voj a zahalila sa.' where spis = 'Gn' and vers = 1 and k = 24 and v = 65
update biblia set nvg = 'Sluha potom porozpr�val Iz�kovi v�etko, �o vykonal, ' where spis = 'Gn' and vers = 1 and k = 24 and v = 66
update biblia set nvg = 'a Iz�k ju voviedol do stanu svojej matky S�ry. Vzal si Rebeku za �enu a tak ju miloval, �e sa uspokojil nad smr�ou svojej matky.' where spis = 'Gn' and vers = 1 and k = 24 and v = 67
go

-- 556	Gn 27, 1-5. 15-29
update biblia set lc_id = 556 where spis = 'Gn' and vers = 1 and k = 27 and v between 1 and 5
update biblia set lc_id = 556 where spis = 'Gn' and vers = 1 and k = 27 and v between 15 and 29
go

update biblia set nvg = 'Iz�k zostarel a o�i mu tak zoslabli, �e nevidel. Zavolal si svojho star�ieho syna Ezaua a povedal mu: "Syn m�j." On odvetil: "Tu som."' where spis = 'Gn' and vers = 1 and k = 27 and v = 1
update biblia set nvg = 'Otec mu povedal: "Vid�, u� som star� a neviem, kedy zomriem. ' where spis = 'Gn' and vers = 1 and k = 27 and v = 2
update biblia set nvg = 'Vezmi si zbra�, tulec a luk, a vyjdi na pole. Ke� nie�o ulov�, ' where spis = 'Gn' and vers = 1 and k = 27 and v = 3
update biblia set nvg = 'priprav mi z toho pokrm, ve� vie�, ak� m�m r�d, a prines mi ho. Zajem si a po�ehn�m �a prv, ako zomriem."' where spis = 'Gn' and vers = 1 and k = 27 and v = 4
update biblia set nvg = 'Ale Rebeka po�ula, �o Iz�k hovoril svojmu synovi Ezauovi. Ezau odi�iel na pole, aby nie�o ulovil a priniesol, ' where spis = 'Gn' and vers = 1 and k = 27 and v = 5
go
update biblia set nvg = 'a Rebeka obliekla Jakuba do najlep��ch Ezauov�ch �iat, �o mala v dome pri ruke, ' where spis = 'Gn' and vers = 1 and k = 27 and v = 15
update biblia set nvg = 'a koz�ac�mi ko�kami mu ovinula ruky a hol� krk. ' where spis = 'Gn' and vers = 1 and k = 27 and v = 16
update biblia set nvg = 'Potom dala svojmu synovi Jakubovi do r�k chutn� jedlo a chlieb, �o pripravila.' where spis = 'Gn' and vers = 1 and k = 27 and v = 17
update biblia set nvg = 'On i�iel k otcovi a povedal: "Ot�e m�j." // Ten odvetil: "Po��vam. Kto si, syn m�j?"' where spis = 'Gn' and vers = 1 and k = 27 and v = 18
update biblia set nvg = 'A Jakub povedal svojmu otcovi: "Ja som Ezau, tvoj prvoroden�. Urobil som, ako si mi rozk�zal. Po�, sadni si, jedz, �o som ulovil, a po�ehnaj ma."' where spis = 'Gn' and vers = 1 and k = 27 and v = 19
update biblia set nvg = 'Ale Iz�k sa op�tal svojho syna: "Ako si mohol tak r�chlo nie�o n�js�, syn m�j?" On odvetil: "P�n, tvoj Boh, chcel, aby som na to natrafil."' where spis = 'Gn' and vers = 1 and k = 27 and v = 20
update biblia set nvg = 'Iz�k povedal Jakubovi: "Prist�p bli��ie, nech sa �a dotknem, syn m�j, a zist�m, �i si ty m�j syn Ezau alebo nie." ' where spis = 'Gn' and vers = 1 and k = 27 and v = 21
update biblia set nvg = 'On prist�pil k otcovi a ke� ho Iz�k ohmatal, povedal: "Hlas, hlas je s�ce Jakubov, ale ruky, ruky s� Ezauove."' where spis = 'Gn' and vers = 1 and k = 27 and v = 22
update biblia set nvg = 'Nepoznal ho, lebo mal ruky chlpat� ako jeho star�� syn. Preto ho po�ehnal. ' where spis = 'Gn' and vers = 1 and k = 27 and v = 23
update biblia set nvg = 'A znova sa ho sp�tal: "Naozaj si to ty, m�j syn Ezau?" on odpovedal: "�no, ja som to."' where spis = 'Gn' and vers = 1 and k = 27 and v = 24
update biblia set nvg = 'Iz�k povedal: "Prines mi to. Budem jes� z tvojho �lovku, syn m�j, a po�ehn�m �a." Podal mu to a on jedol. A podal mu aj v�no. Jeho otec Iz�k si upil ' where spis = 'Gn' and vers = 1 and k = 27 and v = 25
update biblia set nvg = 'a povedal mu: "Po� ku mne, syn m�j, a pobozkaj ma!"' where spis = 'Gn' and vers = 1 and k = 27 and v = 26
update biblia set nvg = 'Podi�iel k nemu a pobozkal ho. Iz�k zac�til v��u jeho �iat a �ehnal ho, hovoriac: "H�a, v��a m�jho syna je ako v��a �rodn�ho po�a, ktor� po�ehnal P�n.' where spis = 'Gn' and vers = 1 and k = 27 and v = 27
update biblia set nvg = 'Nech ti Boh d� nebesk� rosu, ��rnos� zeme a hojnos� zrna i mu�tu.' where spis = 'Gn' and vers = 1 and k = 27 and v = 28
update biblia set nvg = 'Nech ti sl��ia �udia a nech sa sklonia pred tebou n�rody. Bu� p�nom nad svojimi bratmi a nech sa pred tebou skl��aj� synovia tvojej matky. Nech je prekliaty, kto �a bude prekl�na�, a po�ehnan�, kto �a bude �ehna�."' where spis = 'Gn' and vers = 1 and k = 27 and v = 29
go

-- 557	Gn 28, 10-22a
update biblia set lc_id = 557 where spis = 'Gn' and vers = 1 and k = 28 and v between 10 and 22
go

update biblia set nvg = 'Jakub odi�iel z Bersaby a putoval do Charranu. ' where spis = 'Gn' and vers = 1 and k = 28 and v = 10
update biblia set nvg = 'Ke� do�iel na ist� miesto a rozhodol sa tam po z�pade slnka prenocova�, vzal jeden z kame�ov, �o tam le�ali, polo�il si ho pod hlavu a zaspal na tom mieste.' where spis = 'Gn' and vers = 1 and k = 28 and v = 11
update biblia set nvg = 'Vo sne videl rebr�k postaven� na zemi, ktor�ho vrchol sa dot�kal neba, videl Bo��ch anjelov, ako po �om vystupuj� a zostupuj�, ' where spis = 'Gn' and vers = 1 and k = 28 and v = 12
update biblia set nvg = 'a P�na, ako sa opiera o rebr�k a hovor� mu: "Ja som P�n, Boh tvojho otca Abrah�ma a Boh Iz�ka. Zem, na ktorej sp�, d�m tebe a tvojmu potomstvu. ' where spis = 'Gn' and vers = 1 and k = 28 and v = 13
update biblia set nvg = 'Tvojho potomstva bude ako prachu na zemi; roz��ri� sa na z�pad a na v�chod, na sever a na juh; v tebe a v tvojom potomstve bud� po�ehnan� v�etky pokolenia zeme.' where spis = 'Gn' and vers = 1 and k = 28 and v = 14
update biblia set nvg = 'Ja som s tebou a budem �a chr�ni� v�ade, kam p�jde�, a privediem �a sp� do tejto krajiny; neopust�m �a, k�m nespln�m, �o som ti s��bil."' where spis = 'Gn' and vers = 1 and k = 28 and v = 15
update biblia set nvg = 'Ke� sa Jakub prebudil zo sna, povedal: "Skuto�ne, P�n je na tomto mieste a ja som o tom nevedel." ' where spis = 'Gn' and vers = 1 and k = 28 and v = 16
update biblia set nvg = 'A s chven�m hovoril: "Ak� hrozn� je toto miesto! Tu je naozaj dom Bo�� a br�na do neba." ' where spis = 'Gn' and vers = 1 and k = 28 and v = 17
update biblia set nvg = 'Ke� Jakub r�no vstal, vzal kame�, �o mal polo�en� pod hlavou, postavil ho ako pam�tn� st�p a vylial na� olej. ' where spis = 'Gn' and vers = 1 and k = 28 and v = 18
update biblia set nvg = 'A toto miesto nazval Betel. Predt�m sa mesto volalo Luza.' where spis = 'Gn' and vers = 1 and k = 28 and v = 19
update biblia set nvg = 'A Jakub urobil s�ub: "Ak bude Boh so mnou, ak ma bude chr�ni� na ceste, po ktorej idem, ak mi d� chlieb na jedenie a �aty na zaodiatie, ' where spis = 'Gn' and vers = 1 and k = 28 and v = 20
update biblia set nvg = 'ke� sa ��astne vr�tim do domu svojho otca, P�n bude moj�m Bohom ' where spis = 'Gn' and vers = 1 and k = 28 and v = 21
update biblia set nvg = 'a tento kame�, ktor� som postavil ako pomn�k, bude Bo��m domom. [...]"' where spis = 'Gn' and vers = 1 and k = 28 and v = 22
go

-- 563	Gn 32, 22-32
-- NVg ��sluje 22-32; Vg/SSV 23-33
update biblia set lc_id = 563 where spis = 'Gn' and vers = 1 and k = 32 and v between /* 22 and 32 */ 23 and 33
go

update biblia set nvg = '(NVg 22)Jakub vstal za noci, vzal so sebou svoje dve �eny, obe sl��ky i jeden�s� svojich synov a pre�iel cez brod Jabok. ' where spis = 'Gn' and vers = 1 and k = 32 and v = 23
update biblia set nvg = '(NVg 23)Vzal ich a previedol ich i v�etko, �o mu patrilo, cez potok ' where spis = 'Gn' and vers = 1 and k = 32 and v = 24
update biblia set nvg = '(NVg 24)a ostal s�m. Tu s n�m a� do r�na z�pasil nejak� mu�. ' where spis = 'Gn' and vers = 1 and k = 32 and v = 25
update biblia set nvg = '(NVg 25)Ke� onen videl, �e ho nem��e zdola�, dotkol sa mu bedrov�ho k�bu a Jakubovi sa bedrov� k�b pri z�pase s n�m vyk�boval. ' where spis = 'Gn' and vers = 1 and k = 32 and v = 26
update biblia set nvg = '(NVg 26)Nezn�my povedal: "Pus� ma, lebo u� vychod� zora." On odvetil: "Nepust�m �a, k�m ma nepo�ehn�."' where spis = 'Gn' and vers = 1 and k = 32 and v = 27
update biblia set nvg = '(NVg 27)Ten mu povedal: "Ako sa vol�?" On odpovedal: "Jakub." ' where spis = 'Gn' and vers = 1 and k = 32 and v = 28
update biblia set nvg = '(NVg 28)A tamten povedal: "Nebude� sa u� vola� Jakub, ale Izrael, lebo si z�pasil s Bohom i s �u�mi a zv�azil si!"' where spis = 'Gn' and vers = 1 and k = 32 and v = 29
update biblia set nvg = '(NVg 29)Jakub sa ho p�tal: "Povedz mi svoje meno." Onen mu odpovedal: "Pre�o chce� vedie� moje meno?" A po�ehnal ho tam.' where spis = 'Gn' and vers = 1 and k = 32 and v = 30
update biblia set nvg = '(NVg 30)Jakub nazval to miesto Fanuel, lebo si povedal: "Videl som Boha z tv�re do tv�re a ostal som na�ive."' where spis = 'Gn' and vers = 1 and k = 32 and v = 31
update biblia set nvg = '(NVg 31)Ke� pre�iel Fanuel, vy�lo slnko a on kr�val pre svoje bedro. ' where spis = 'Gn' and vers = 1 and k = 32 and v = 32
update biblia set nvg = '(NVg 32)Preto Izraeliti a� dodnes nejedia ��achy bedrov�ho k�bu, lebo onen sa dotkol ��achy Jakubovho bedrov�ho k�bu.' where spis = 'Gn' and vers = 1 and k = 32 and v = 33
go

-- 564	Gn 37, 3-4. 12-13a. 17b-28
update biblia set lc_id = 564 where spis = 'Gn' and vers = 1 and k = 37 and v between 3 and 4
update biblia set lc_id = 564 where spis = 'Gn' and vers = 1 and k = 37 and v between 12 and 13
update biblia set lc_id = 564 where spis = 'Gn' and vers = 1 and k = 37 and v between 17 and 28
go

update biblia set nvg = 'Izrael miloval Jozefa viac ako v�etk�ch svojich synov, lebo sa mu narodil v starobe, a dal mu urobi� dlh� tuniku. ' where spis = 'Gn' and vers = 1 and k = 37 and v = 3
update biblia set nvg = 'Ke� jeho bratia videli, �e ho m� otec rad�ej ako v�etk�ch ostatn�ch synov, za�ali ho nen�vidie� a nevedeli sa s n�m pr�vetivo rozpr�va�.' where spis = 'Gn' and vers = 1 and k = 37 and v = 4
update biblia set nvg = 'Raz jeho bratia p�sli ovce svojho otca pri Sicheme. ' where spis = 'Gn' and vers = 1 and k = 37 and v = 12
update biblia set nvg = 'A Izrael povedal Jozefovi: "Tvoji bratia pas� ovce pri Sicheme, po�, po�lem �a za nimi." [...]' where spis = 'Gn' and vers = 1 and k = 37 and v = 13
update biblia set nvg = '[...] A Jozef i�iel za svojimi bratmi a na�iel ich v Dotaine.' where spis = 'Gn' and vers = 1 and k = 37 and v = 17
update biblia set nvg = 'Oni ho z�aleka zbadali a prv ne� k nim pri�iel, sa dohodli, �e ho zabij�. ' where spis = 'Gn' and vers = 1 and k = 37 and v = 18
update biblia set nvg = 'Medzi sebou hovorili: "H�a, sn�r prich�dza; ' where spis = 'Gn' and vers = 1 and k = 37 and v = 19
update biblia set nvg = 'po�te, zabijeme ho a hod�me do niektorej cisterny. A povieme, �e ho zo�rala div� zver. Potom sa uk�e, �o mu pom��u jeho sny."' where spis = 'Gn' and vers = 1 and k = 37 and v = 20
update biblia set nvg = 'Ke� to po�ul Ruben, usiloval sa vyslobodi� ho z ich r�k a vravel: "Neberme mu �ivot." ' where spis = 'Gn' and vers = 1 and k = 37 and v = 21
update biblia set nvg = 'A �alej im hovoril: "Neprelievajte krv. Ho�te ho do cisterny tu na pustatine a nepo�kvr�ujte si ruky." To povedal preto, �e ho chcel vyslobodi� z ich r�k a vr�ti� jeho otcovi.' where spis = 'Gn' and vers = 1 and k = 37 and v = 22
update biblia set nvg = 'A len �o Jozef do�iel k svojim bratom, zobliekli mu jeho dlh� tuniku ' where spis = 'Gn' and vers = 1 and k = 37 and v = 23
update biblia set nvg = 'a hodili ho do cisterny, v ktorej nebolo vody.' where spis = 'Gn' and vers = 1 and k = 37 and v = 24
update biblia set nvg = 'Potom si posadali a jedli chlieb. A ke� zdvihli o�i, videli prich�dza� karav�nu Izmaelitov z Gala�du. Ich �avy niesli balzam, mastixov� �ivicu a lad�num do Egypta. ' where spis = 'Gn' and vers = 1 and k = 37 and v = 25
update biblia set nvg = 'Tu povedal J�da svojim bratom: "�o by sme mali z toho, keby sme zabili svojho brata a zatajili jeho krv? ' where spis = 'Gn' and vers = 1 and k = 37 and v = 26
update biblia set nvg = 'Bude lep�ie preda� ho Izmaelitom a nepo�kvrni� si ruky. Ve� je to n� brat a na�e telo." A bratia s n�m s�hlasili.' where spis = 'Gn' and vers = 1 and k = 37 and v = 27
update biblia set nvg = 'A ke� madi�nski kupci prech�dzali okolo, vytiahli Jozefa z cisterny a predali ho za dvadsa� strieborn�ch Izmaelitom. A t� ho odviedli do Egypta.' where spis = 'Gn' and vers = 1 and k = 37 and v = 28
go

-- 566	Gn 41, 55-57; 42, 5-7a. 17-24a
update biblia set lc_id = 566 where spis = 'Gn' and vers = 1 and k = 41 and v between 55 and 57
go
update biblia set lc_id = 566 where spis = 'Gn' and vers = 1 and k = 42 and v between 5 and 7
update biblia set lc_id = 566 where spis = 'Gn' and vers = 1 and k = 42 and v between 17 and 24
go

update biblia set nvg = 'Egyptsk� krajina za�ala hladova� a �ud volal k fara�novi o chlieb. On im povedal: "Cho�te k Jozefovi a urobte v�etko, �o v�m povie." ' where spis = 'Gn' and vers = 1 and k = 41 and v = 55
update biblia set nvg = 'Hlad do�ahol na cel� egyptsk� krajinu; Jozef otvoril v�etky s�pky a pred�val Egyp�anom obilie, lebo ich moril hlad. ' where spis = 'Gn' and vers = 1 and k = 41 and v = 56
update biblia set nvg = 'A k Jozefovi do Egypta prich�dzali aj v�etky okolit� krajiny kupova� obilie, lebo n�dza zachv�tila cel� svet.' where spis = 'Gn' and vers = 1 and k = 41 and v = 57
go
update biblia set nvg = 'S t�mi, �o putovali do Egypta nak�pi� obilie, pri�li aj Izraelovi synovia, lebo aj v Kana�ne bol hlad. ' where spis = 'Gn' and vers = 1 and k = 42 and v = 5
update biblia set nvg = 'A Jozef bol vlad�rom v egyptskej krajine, na jeho pokyn sa pred�valo �u�om obilie. // Ke� teda k nemu pri�li jeho bratia a poklonili sa a� po zem, ' where spis = 'Gn' and vers = 1 and k = 42 and v = 6
update biblia set nvg = 'on ich poznal; ale rozpr�val sa s nimi pr�snej�ie ako s cudz�mi [...]' where spis = 'Gn' and vers = 1 and k = 42 and v = 7
go
update biblia set nvg = 'a dal ich na tri dni do v�zenia. ' where spis = 'Gn' and vers = 1 and k = 42 and v = 17
update biblia set nvg = '(Na tret� de� ich z v�zenia vyviedol) a povedal: "Ak chcete �i�, urobte, �o som povedal; lebo ja sa boj�m Boha. ' where spis = 'Gn' and vers = 1 and k = 42 and v = 18
update biblia set nvg = 'Ak ste �primn�, jeden v� brat ostane vo v�zen�. Vy cho�te, zaneste domov obilie, �o ste k�pili, ' where spis = 'Gn' and vers = 1 and k = 42 and v = 19
update biblia set nvg = 'a prive�te ku mne v�ho najmlad�ieho brata, aby sa dok�zalo, �e s� va�e re�i pravdiv�, aby ste nepri�li o �ivot." // Oni urobili, ako povedal, ' where spis = 'Gn' and vers = 1 and k = 42 and v = 20
update biblia set nvg = 'a medzi sebou si vraveli: "Pr�vom takto trp�me, lebo sme sa previnili proti n�mu bratovi: videli sme �zkos� jeho du�e, ke� n�s �penlivo prosil, a nepo��vali sme. Preto na n�s do�ahlo toto tr�penie."' where spis = 'Gn' and vers = 1 and k = 42 and v = 21
update biblia set nvg = 'A Ruben hovoril: "Nevravel som v�m: Neprehre�te sa proti chlapcovi? A nepo��vali ste ma. Teraz sa od n�s po�aduje jeho krv."' where spis = 'Gn' and vers = 1 and k = 42 and v = 22
update biblia set nvg = 'No nevedeli, �e Jozef im rozumie, lebo sa s nimi rozpr�val prostredn�ctvom tlmo�n�ka. ' where spis = 'Gn' and vers = 1 and k = 42 and v = 23
update biblia set nvg = 'Na chv�ku sa od nich odvr�til a plakal. [...]' where spis = 'Gn' and vers = 1 and k = 42 and v = 24
go

-- 567	Gn 44, 18-21. 23b-29; 45, 1-5
update biblia set lc_id = 567 where spis = 'Gn' and vers = 1 and k = 44 and v between 18 and 21
update biblia set lc_id = 567 where spis = 'Gn' and vers = 1 and k = 44 and v between 24 and 29 -- v. 23b je len nazna�en�
go
update biblia set lc_id = 567 where spis = 'Gn' and vers = 1 and k = 45 and v between 1 and 5
go

update biblia set nvg = 'J�da prist�pil bli��ie k Jozefovi a d�verne vravel: "Pros�m, pane m�j, dovo�, aby ti tvoj sluha povedal nieko�ko slov, a nehnevaj sa na svojho sluhu; ve� ty si ako fara�n!' where spis = 'Gn' and vers = 1 and k = 44 and v = 18
update biblia set nvg = 'M�j p�n sa prv� raz p�tal svojich sluhov: �M�te e�te otca alebo brata?� ' where spis = 'Gn' and vers = 1 and k = 44 and v = 19
update biblia set nvg = 'A my sme vtedy odpovedali m�jmu p�novi: �M�me staru�k�ho otca a mal�ho brata, ktor� sa mu narodil v starobe. Jeho brat po matke je u� m�tvy, a tak mu ostal len on po svojej matke; preto ho otec ne�ne miluje.�' where spis = 'Gn' and vers = 1 and k = 44 and v = 20
update biblia set nvg = 'A ty si svoj�m sluhom rozk�zal: �Prive�te ho ku mne, aby som ho videl na vlastn� o�i. Ak nepr�de s vami v� najmlad�� brat, neukazujte sa mi na o�i!�' where spis = 'Gn' and vers = 1 and k = 44 and v = 21
go
update biblia set nvg = 'Ke� sme potom do�li k tvojmu sluhovi, n�mu otcovi, rozpovedali sme mu v�etko, �o povedal m�j p�n.' where spis = 'Gn' and vers = 1 and k = 44 and v = 24
update biblia set nvg = 'A n� otec vravel: �Cho�te znova a k�pte trochu p�enice.�' where spis = 'Gn' and vers = 1 and k = 44 and v = 25
update biblia set nvg = 'My sme mu odvr�vali: �Nem��eme �s�. Ak p�jde s nami n� najmlad�� brat, p�jdeme aj my; lebo bez neho sa nesmieme uk�za� na o�i tomu mu�ovi.�' where spis = 'Gn' and vers = 1 and k = 44 and v = 26
update biblia set nvg = 'Na to n�m tvoj sluha, n� otec, povedal: �Vy viete, �e moja �ena mi porodila len dvoch. ' where spis = 'Gn' and vers = 1 and k = 44 and v = 27
update biblia set nvg = 'Jeden odo m�a odi�iel a ja som povedal: Div� zver ho zo�rala! A doteraz ho niet. ' where spis = 'Gn' and vers = 1 and k = 44 and v = 28
update biblia set nvg = 'Ak vezmete odo m�a aj tohoto a nie�o sa mu na ceste stane, privediete moje �ediny b��om do hrobu.�"' where spis = 'Gn' and vers = 1 and k = 44 and v = 29
go
update biblia set nvg = 'Jozef u� nebol �alej schopn� ovl�da� sa pred t�mi, �o st�li okolo, a zvolal: "Vyjdite von v�etci!" A tak nebol nik pri �om, ke� sa dal pozna� svojim bratom. ' where spis = 'Gn' and vers = 1 and k = 45 and v = 1
update biblia set nvg = 'Dal sa do hlasit�ho pla�u, �e ho po�uli aj Egyp�ania a cel� fara�nov dom.' where spis = 'Gn' and vers = 1 and k = 45 and v = 2
update biblia set nvg = 'Potom Jozef povedal svojim bratom: "Ja som Jozef! �ije e�te m�j otec?" Ale bratia sa tak pre�akli, �e mu nemohli odpoveda�. ' where spis = 'Gn' and vers = 1 and k = 45 and v = 3
update biblia set nvg = 'On sa im v��dne prihov�ral: "No, po�te ku mne." // A ke� prist�pili bli��ie, povedal: "Ja som Jozef, v� brat, ktor�ho ste predali do Egypta. ' where spis = 'Gn' and vers = 1 and k = 45 and v = 4
update biblia set nvg = 'No netr�pte sa a nesu�ujte, �e ste ma predali do tejto krajiny, lebo to ma Boh poslal pred vami do Egypta na va�u z�chranu."' where spis = 'Gn' and vers = 1 and k = 45 and v = 5
go

-- 568	Gn 46, 1-7. 28-30
update biblia set lc_id = 568 where spis = 'Gn' and vers = 1 and k = 46 and v between 1 and 7
update biblia set lc_id = 568 where spis = 'Gn' and vers = 1 and k = 46 and v between 28 and 30
go

update biblia set nvg = 'Izrael sa vydal na cestu so v�etk�m, �o mal. Ke� do�iel do Bersaby a priniesol Bohu svojho otca Iz�ka krvav� obetu, ' where spis = 'Gn' and vers = 1 and k = 46 and v = 1
update biblia set nvg = 'po�ul, ako ho Boh v no�nom viden� vol�: "Jakub, Jakub!" On odpovedal: "Tu som!"' where spis = 'Gn' and vers = 1 and k = 46 and v = 2
update biblia set nvg = 'Hovoril mu: "Ja som Boh, Boh tvojho otca. Neboj sa zost�pi� do Egypta, lebo tam z teba urob�m ve�k� n�rod. ' where spis = 'Gn' and vers = 1 and k = 46 and v = 3
update biblia set nvg = 'Ja ta p�jdem s tebou a ja �a odtia� privediem sp�; a Jozef ti vlastnou rukou zatla�� o�i."' where spis = 'Gn' and vers = 1 and k = 46 and v = 4
update biblia set nvg = 'Jakub sa teda pohol z Bersaby. Jeho synovia nalo�ili jeho i svoje deti a �eny na vozy, �o poslal fara�n na prevezenie starca, ' where spis = 'Gn' and vers = 1 and k = 46 and v = 5
update biblia set nvg = 'a vzali so sebou v�etko, �o mali v krajine Kana�n. Tak pri�li do Egypta Jakub a v�etci jeho potomci: ' where spis = 'Gn' and vers = 1 and k = 46 and v = 6
update biblia set nvg = 'jeho synovia a vnuci, dc�ry a cel� jeho potomstvo. ' where spis = 'Gn' and vers = 1 and k = 46 and v = 7
go
update biblia set nvg = 'Jakub poslal J�du napred k Jozefovi, aby mu ozn�mil, �e sa stretn� v Gessene. Ke� pri�li do kraja Gessen, ' where spis = 'Gn' and vers = 1 and k = 46 and v = 28
update biblia set nvg = 'Jozef dal zapriahnu� do svojho voza a i�iel do Gessenu naproti svojmu otcovi. Ke� ho uvidel, hodil sa mu okolo krku a dlho plakal v jeho objat�.' where spis = 'Gn' and vers = 1 and k = 46 and v = 29
update biblia set nvg = 'Tu Izrael povedal Jozefovi: "Teraz u� spokojne zomriem, lebo som videl tvoju tv�r a viem, �e ma pre�ije�."' where spis = 'Gn' and vers = 1 and k = 46 and v = 30
go

-- 569	Gn 49, 1-2. 8-10
update biblia set lc_id = 569 where spis = 'Gn' and vers = 1 and k = 49 and v between 1 and 2
update biblia set lc_id = 569 where spis = 'Gn' and vers = 1 and k = 49 and v between 8 and 10
go

update biblia set nvg = 'Jakub zavolal svojich synov a povedal im: "Zhroma�dite sa a ozn�mim v�m, �o v�s �ak� v �alekej bud�cnosti: ' where spis = 'Gn' and vers = 1 and k = 49 and v = 1
update biblia set nvg = 'Zhroma�dite sa a po��vajte, Jakubovi synovia, po�ujte Izraela, svojho otca!' where spis = 'Gn' and vers = 1 and k = 49 and v = 2
go
update biblia set nvg = 'J�da, teba bud� chv�li� tvoji bratia, tvoja ruka bude na �iji tvojich nepriate�ov, tebe sa bud� kla�a� synovia tvojho otca. ' where spis = 'Gn' and vers = 1 and k = 49 and v = 8
update biblia set nvg = 'Mlad�m levom si J�da, od koristi vst�va�, syn m�j; l�ha si a odpo��va ako lev a ako levica: kto sa ho odv�i vyru�i�?' where spis = 'Gn' and vers = 1 and k = 49 and v = 9
update biblia set nvg = 'Nebude od�at� �ezlo od J�du ani vlad�rska berla od jeho n�h, k�m nepr�de ten, komu patr�, ktor�ho bud� posl�cha� n�rody."' where spis = 'Gn' and vers = 1 and k = 49 and v = 10
go

-- 570	Gn 49, 29-32; 50, 15-26
-- ver� 32 nie je explicitne v texte; zato je tam v. 33
update biblia set lc_id = 570 where spis = 'Gn' and vers = 1 and k = 49 and v between 29 and 33
go
update biblia set lc_id = 570 where spis = 'Gn' and vers = 1 and k = 50 and v between 15 and 26
go

update biblia set nvg = 'Jakub prik�zal svojim synom: "Ja sa pripoj�m k svojmu �udu; pochovajte ma s mojimi otcami v jaskyni Makpela, �o je na pozemku Hetejca Efrona ' where spis = 'Gn' and vers = 1 and k = 49 and v = 29
update biblia set nvg = 'oproti Mambre v krajine Kana�n, ktor� k�pil Abrah�m aj s pozemkom od Hetejca Efrona na dedi�n� pohrebisko.' where spis = 'Gn' and vers = 1 and k = 49 and v = 30
update biblia set nvg = 'Tam pochovali jeho �enu S�ru, tam je pochovan� Iz�k so svojou man�elkou Rebekou a tam le�� pochovan� aj Lia."' where spis = 'Gn' and vers = 1 and k = 49 and v = 31
update biblia set nvg = '(NVg tento ver� vynech�va)' where spis = 'Gn' and vers = 1 and k = 49 and v = 32
update biblia set nvg = '(NVg 32)Ke� skon�il t�to re�, ktorou po��al svojich synov, vylo�il si nohy na l��ko a zomrel; a tak sa pripojil k svojmu �udu.' where spis = 'Gn' and vers = 1 and k = 49 and v = 33
go
update biblia set nvg = 'Ke� Jakub zomrel, Jozefovi bratia sa b�li a vraveli si: "Len aby si nespomenul na pr�korie, ktor� musel znies�, a aby sa n�m nepomstil za v�etko zlo, �o sme mu vykonali!"' where spis = 'Gn' and vers = 1 and k = 50 and v = 15
update biblia set nvg = 'Preto mu odk�zali: "Tvoj otec n�m prik�zal sk�r, ako zomrel, aby sme ti jeho slovami povedali: ' where spis = 'Gn' and vers = 1 and k = 50 and v = 16
update biblia set nvg = '�Pros�m �a, zabudni na zlo�in svojich bratov, na ich hriech a nehanebnos�, ktorej sa na tebe dopustili.� Aj my �a pros�me, aby si n�m odpustil tento nehanebn� �in; ve� my uctievame Boha tvojho otca." Ke� mu to hovorili, Jozef plakal.' where spis = 'Gn' and vers = 1 and k = 50 and v = 17
update biblia set nvg = 'Potom i�li za n�m sami bratia, sklonili sa pred n�m a vraveli: "Sme tvoji sluhovia."' where spis = 'Gn' and vers = 1 and k = 50 and v = 18
update biblia set nvg = 'Ale on im povedal: "Nebojte sa! M��eme sa vari vzoprie� Bo�ej v�li? ' where spis = 'Gn' and vers = 1 and k = 50 and v = 19
update biblia set nvg = 'Vy ste osnovali proti mne zlo, ale Boh to obr�til na dobr�. Pov��il ma, ako vid�te, a tak zachr�nil mnoho �udu. ' where spis = 'Gn' and vers = 1 and k = 50 and v = 20
update biblia set nvg = 'Nebojte sa u�! Ja v�s budem �ivi�, aj va�e deti." // Te�il ich a milo a v��dne sa im prihov�ral.' where spis = 'Gn' and vers = 1 and k = 50 and v = 21
update biblia set nvg = 'Tak b�val Jozef i cel� dom jeho otca v Egypte. �il stodesa� rokov ' where spis = 'Gn' and vers = 1 and k = 50 and v = 22
update biblia set nvg = 'a videl Efraimov�ch synov a� do tretieho pokolenia; aj synovia Machira, syna Manasseho, sa narodili na Jozefov�ch kolen�ch.' where spis = 'Gn' and vers = 1 and k = 50 and v = 23
update biblia set nvg = 'Po tom v�etkom povedal Jozef svojim bratom: "Po mojej smrti sa v�s Boh ujme a vyvedie v�s z tejto krajiny do krajiny, o ktorej prisahal Abrah�movi, Iz�kovi a Jakubovi."' where spis = 'Gn' and vers = 1 and k = 50 and v = 24
update biblia set nvg = 'A ke� ich zaprisahal a povedal: "Boh v�s nav�t�vi; odneste z tohto miesta moje kosti so sebou," ' where spis = 'Gn' and vers = 1 and k = 50 and v = 25
update biblia set nvg = 'zomrel stodesa� ro�n�. Zabalzamovali ho a ulo�ili do rakvy v Egypte.' where spis = 'Gn' and vers = 1 and k = 50 and v = 26
go
-- ��
