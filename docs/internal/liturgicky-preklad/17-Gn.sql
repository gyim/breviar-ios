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
update biblia set lc_id = 572 where spis = 'Gn' and vers = 1 and k = 8 and v between 6 and 13 -- je tam aj ver� 14 pod�a SSV
update biblia set lc_id = 572 where spis = 'Gn' and vers = 1 and k = 8 and v between 20 and 22
go

update biblia set nvg = 'Ke� uplynulo �tyridsa� dn�, Noe otvoril na kor�be okno, ktor� bol urobil, ' where spis = 'Gn' and vers = 1 and k = 8 and v = 6
update biblia set nvg = 'a vypustil krkavca. Ten odlietal a prilietal, k�m vody na zemi nevyschli.' where spis = 'Gn' and vers = 1 and k = 8 and v = 7
update biblia set nvg = 'Vypustil von aj holubicu, aby zvedel, �i u� vody stiekli z povrchu zeme. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 8
update biblia set nvg = 'Ale ke� nena�la miesto, kde by spo�inula jej noha, vr�tila sa k nemu do kor�ba; po celej zemi boli e�te vody. Noe vystrel ruku, chytil ju a vzal ju do kor�ba.' where spis = 'Gn' and vers = 1 and k = 8 and v = 9
update biblia set nvg = '�akal e�te sedem dn� a znova vypustil z kor�ba holubicu. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 10
update biblia set nvg = 'A ona k nemu priletela a� v podve�er a v zob�ku priniesla olivov� ratoles� so zelen�mi listami. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 11
update biblia set nvg = 'Tu Noe poznal, �e vody zo zeme zmizli. �akal e�te �al��ch sedem dn� a vypustil holubicu, ktor� sa u� k nemu nevr�tila.' where spis = 'Gn' and vers = 1 and k = 8 and v = 12
update biblia set nvg = 'V �es�stoprvom roku, v prvom mesiaci, v prv� de� mesiaca, vody na zemi vyschli. ' where spis = 'Gn' and vers = 1 and k = 8 and v = 13
update biblia set nvg = 'Noe otvoril strechu kor�ba, pozrel sa von a videl, �e povrch zeme je such�.' where spis = 'Gn' and vers = 1 and k = 8 and v = 14
go
update biblia set nvg = 'Potom postavil olt�r P�novi, vzal zo v�etk�ho �ist�ho dobytka a z �ist�ch vt�kov a priniesol z�paln� obetu na olt�ri.' where spis = 'Gn' and vers = 1 and k = 8 and v = 20
update biblia set nvg = 'P�n zavo�al pr�jemn� v��u a povedal si: "U� nikdy neprek�ajem zem pre �loveka, lebo zm���anie �udsk�ho srdca je od mladosti n�klonn� na zl�. Preto u� nikdy nevyhub�m v�etky �iv� bytosti, ako som to urobil.' where spis = 'Gn' and vers = 1 and k = 8 and v = 21
update biblia set nvg = 'K�m potrv� zem, neprestane sejba a �atva, chlad a hor��os�, leto a zima, de� a noc."' where spis = 'Gn' and vers = 1 and k = 8 and v = 22
go

-- 573	Gn 9, 1-13
-- 574	Gn 9, 8-15
update biblia set lc_id = 573 where spis = 'Gn' and vers = 1 and k = 9 and v between 1 and 13
update biblia set lc_id = 574 where spis = 'Gn' and vers = 1 and k = 9 and v between 14 and 13
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
