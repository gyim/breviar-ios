-- 123	1 Krn 15, 3-4. 15-16; 16, 1-2
update biblia set lc_id = 123 where spis = '1Krn' and vers = 1 and k = 15 and v between 3 and 4
update biblia set lc_id = 123 where spis = '1Krn' and vers = 1 and k = 15 and v between 15 and 16
update biblia set lc_id = 123 where spis = '1Krn' and vers = 1 and k = 16 and v between 1 and 2
go
update biblia set nvg = 'D�vid zhroma�dil cel� Izrael v Jeruzaleme, lebo sa pren�ala P�nova archa na miesto, ktor� pre �u pripravil.' where spis = '1Krn' and vers = 1 and k = 15 and v = 3
update biblia set nvg = 'Zhroma�dil aj �ronov�ch synov a levitov.' where spis = '1Krn' and vers = 1 and k = 15 and v = 4
update biblia set nvg = 'Synovia L�viho niesli Bo�iu archu pomocou �rd� na pleciach, ako to pod�a P�novho slova prik�zal Moj�i�.' where spis = '1Krn' and vers = 1 and k = 15 and v = 15
update biblia set nvg = 'D�vid rozk�zal predstaven�m levitov, aby zo svojich bratov ustanovili spev�kov s hudobn�mi n�strojmi, s citarami, harfami a cimbalmi tak, aby mocne znelo radostn� plesanie.' where spis = '1Krn' and vers = 1 and k = 15 and v = 16
update biblia set nvg = 'Tak preniesli Bo�iu archu a postavili ju uprostred stanu, ktor� pre �u postavil D�vid. Potom obetovali pred Bohom z�paln� a pokojn� obety.' where spis = '1Krn' and vers = 1 and k = 16 and v = 1
update biblia set nvg = 'Ke� D�vid skon�il obetovanie z�paln�ch a pokojn�ch obiet, po�ehnal �ud v mene P�novom.' where spis = '1Krn' and vers = 1 and k = 16 and v = 2
go

-- 25MAR_cCIT1
-- SCPM_ZVI_cCIT1 = SCPM_ZVII_cCIT1
update biblia set lh_id = '25MAR_cCIT1', juv = '= SCPM_ZVI_cCIT1 = SCPM_ZVII_cCIT1' where spis = '1Krn' and vers = 1 and k = 17 and v between 1 and 15
go
update biblia set nvg = 'Ke� D�vid b�val vo svojom pal�ci, povedal prorokovi N�tanovi: �Pozri, ja b�vam v_dome z_c�drov a_P�nova archa zmluvy je pod stanmi.�' where spis = '1Krn' and vers = 1 and k = 17 and v = 1
update biblia set nvg = 'N�tan odpovedal D�vidovi: �Urob v�etko, �o ti vnuk� srdce, Boh je s_tebou.�' where spis = '1Krn' and vers = 1 and k = 17 and v = 2
update biblia set nvg = 'V_t� noc zaznelo N�tanovi Bo�ie slovo:', juv = '<p> pred v. 3' where spis = '1Krn' and vers = 1 and k = 17 and v = 3
update biblia set nvg = '�Cho� a_povedz m�jmu slu�obn�kovi D�vidovi: Toto hovor� P�n: Ty mi nepostav� dom, v_ktorom m�m b�va�;' where spis = '1Krn' and vers = 1 and k = 17 and v = 4
update biblia set nvg = 've� som neb�val v_dome odvtedy, �o som vyviedol Izraela, a� po tento de�, ale som sa s�ahoval zo stanu do stanu a_z_pr�bytku do pr�bytku.' where spis = '1Krn' and vers = 1 and k = 17 and v = 5
update biblia set nvg = 'Vari som niekedy, ke� som putoval uprostred Izraela, povedal niektor�mu zo sudcov Izraela, ktor�m som prik�zal p�s� m�j �ud: Pre�o ste mi nepostavili c�drov� dom?' where spis = '1Krn' and vers = 1 and k = 17 and v = 6
update biblia set nvg = 'Preto teraz takto povie� m�jmu slu�obn�kovi D�vidovi: Toto hovor� P�n z�stupov: Ja som �a vzal z_pastv�n od oviec, aby si bol vodcom m�jho �udu, Izraela, ' where spis = '1Krn' and vers = 1 and k = 17 and v = 7
update biblia set nvg = 'a_bol som s_tebou v�ade, kade si chodil; pred tvojimi o�ami som vyhubil v�etk�ch tvojich nepriate�ov a_zaistil som ti meno, ak� maj� len najv��� na zemi.' where spis = '1Krn' and vers = 1 and k = 17 and v = 8
update biblia set nvg = 'Svojmu �udu, Izraelu, som ur�il miesto a_tam som ho zasadil; tam bude b�va�. A_u� sa nepohne a_ani zlosynovia ho u� nebud� utl��a� ako kedysi ' where spis = '1Krn' and vers = 1 and k = 17 and v = 9
update biblia set nvg = 'a_v_d�och, ke� som ustanovoval sudcov nad svoj�m �udom, Izraelom, a_pon�il v�etk�ch tvojich nepriate�ov. Oznamujem ti teda, �e P�n tebe vybuduje dom.' where spis = '1Krn' and vers = 1 and k = 17 and v = 10
update biblia set nvg = 'A_a� napln� svoje dni a_ty od�de� k_svojim otcom, pozdvihnem po tebe tvojho potomka, ktor� bude poch�dza� z_tvojich synov, a_upevn�m jeho kr�ovstvo.' where spis = '1Krn' and vers = 1 and k = 17 and v = 11
update biblia set nvg = 'On mi postav� dom a_ja upevn�m jeho tr�n naveky.' where spis = '1Krn' and vers = 1 and k = 17 and v = 12
update biblia set nvg = 'Ja mu budem otcom a_on mi bude synom a_svoju priaze� mu neodn�mem, ako som od�al tomu, �o bol pred tebou.' where spis = '1Krn' and vers = 1 and k = 17 and v = 13
update biblia set nvg = 'Ustanov�m ho v_svojom dome a_v_svojom kr�ovstve naveky a_jeho tr�n bude upevnen� nav�dy.�' where spis = '1Krn' and vers = 1 and k = 17 and v = 14
update biblia set nvg = 'N�tan povedal v�etky tieto slov� a_cel� videnie D�vidovi.', juv = '<p> pred v. 15' where spis = '1Krn' and vers = 1 and k = 17 and v = 15
go

-- OCR14STVc_CIT1 -- 1 Krn 22, 5-19
update biblia set lh_id = 'OCR14STVc_CIT1' where spis = '1Krn' and vers = 1 and k = 22 and v between 5 and 19
go
update biblia set nvg = 'D�vid povedal: �M�j syn �alam�n je e�te mlad� a_�tly chlapec a_dom, ktor� treba postavi� P�novi, mus� by� tak�, aby ho spom�nali a_oslavovali vo v�etk�ch krajin�ch. Priprav�m mu teda, �o bude potrebova�.� A_preto pred svojou smr�ou pripravil v�etky prostriedky.' where spis = '1Krn' and vers = 1 and k = 22 and v = 5
update biblia set nvg = 'Potom zavolal svojho syna �alam�na a_prik�zal mu, aby postavil dom P�novi, Bohu Izraela.', juv = '<p> pred v. 6' where spis = '1Krn' and vers = 1 and k = 22 and v = 6
update biblia set nvg = 'D�vid povedal �alam�novi: �Syn m�j, ja som zam���al postavi� dom menu P�na, m�jho Boha.' where spis = '1Krn' and vers = 1 and k = 22 and v = 7
update biblia set nvg = 'Ale P�n mi povedal: �Prelial si ve�a krvi a_viedol ve�k� vojny. Nebude� m�c� postavi� dom m�jmu menu, ke� si vylial to�ko krvi predo mnou.' where spis = '1Krn' and vers = 1 and k = 22 and v = 8
update biblia set nvg = 'Syn, ktor� sa ti narod�, bude mu�om pokoja. Zaist�m mu pokoj od v�etk�ch jeho nepriate�ov zo v�etk�ch str�n, a_preto sa bude vola� �alam�n. Pokoj a_mier darujem v_Izraeli po v�etky jeho dni.' where spis = '1Krn' and vers = 1 and k = 22 and v = 9
update biblia set nvg = 'On postav� dom m�jmu menu. On mi bude synom a_ja mu budem otcom. A_upevn�m jeho kr�ovsk� tr�n nad Izraelom naveky.�' where spis = '1Krn' and vers = 1 and k = 22 and v = 10
update biblia set nvg = 'A_teraz nech je s_tebou P�n, syn m�j. Nech sa ti dar� postavi� dom P�novi, svojmu Bohu, ako to o_tebe povedal.' where spis = '1Krn' and vers = 1 and k = 22 and v = 11
update biblia set nvg = 'Nech ti P�n d� m�dros� a_rozvahu, aby si vedel spravova� Izrael a_zachov�va� z�kon P�na, svojho Boha.' where spis = '1Krn' and vers = 1 and k = 22 and v = 12
update biblia set nvg = 'Iba vtedy bude� ma� �spech, ke� bude� zachov�va� prik�zania a_ustanovenia, ktor� dal P�n Moj�i�ovi pre Izrael. Bu� stato�n� a_vzmu� sa! Neboj sa, ani sa nechvej!' where spis = '1Krn' and vers = 1 and k = 22 and v = 13
update biblia set nvg = 'Pozri, ja som popri svojich strastiach pripravil prostriedky na P�nov dom: stotis�c talentov zlata a_mili�n talentov striebra, me� a_�elezo nemo�no ani odv�i�, lebo je ich tak ve�a. Pripravil som drevo i_kame�; a_ty k_tomu prid�.' where spis = '1Krn' and vers = 1 and k = 22 and v = 14
update biblia set nvg = 'M� aj ve�a remeseln�kov � kamen�rov, mur�rov, tes�rov a_r�znych odborn�kov schopn�ch vytvori� diela ' where spis = '1Krn' and vers = 1 and k = 22 and v = 15
update biblia set nvg = 'zo zlata a_striebra, medi a_�eleza, �oho je bez po�tu. Vsta� teda a_rob a_P�n bude s_tebou.�' where spis = '1Krn' and vers = 1 and k = 22 and v = 16
update biblia set nvg = 'D�vid prik�zal aj v�etk�m izraelsk�m knie�at�m, aby pom�hali jeho synovi �alam�novi:', juv = '<p> pred v. 17' where spis = '1Krn' and vers = 1 and k = 22 and v = 17
update biblia set nvg = '�Vid�te, �e P�n, v� Boh, je s_vami a_daroval v�m pokoj zo v�etk�ch str�n, obyvate�ov krajiny vydal do va�ej ruky a_krajina sa podrobila P�novi a_jeho �udu.' where spis = '1Krn' and vers = 1 and k = 22 and v = 18
update biblia set nvg = 'Oddajte teda svoje srdcia a_svoje du�e h�adaniu P�na, svojho Boha. Vsta�te a_stavajte sv�ty�u P�novi, Bohu, aby sa mohla zanies� archa P�novej zmluvy i_n�doby zasv�ten� Bohu do domu, ktor� sa postav� P�novmu menu.�' where spis = '1Krn' and vers = 1 and k = 22 and v = 19
go

-- CHVAL_1KRN29
-- 124	1 Krn 29, 10bc. 11. 12 // nepou�it�
-- 125	1 Krn 29, 10bc. 11a-c. 11d-12a. 12b-d // nepou�it�
update biblia set lh_id = 'CHVAL_1KRN29' where spis = '1Krn' and vers = 1 and k = 29 and v between 10 and 13
go
update biblia set lc_id = 124 where spis = '1Krn' and vers = 1 and k = 29 and v between 10 and 12
go
update biblia set nvg = '[...] Zveleben� bu�, Pane, Bo�e n�ho otca Izraela, / od vekov naveky.' where spis = '1Krn' and vers = 1 and k = 29 and v = 10
update biblia set nvg = 'Tvoja je, Pane, vzne�enos� i_moc, / sl�va, jas a_veleba, / lebo tvoje je v�etko na nebi i_na zemi. / Tvoje je, Pane, kr�ovstvo, / ty si vyv��en� ako hlava nad v�etk�m.' where spis = '1Krn' and vers = 1 and k = 29 and v = 11
update biblia set nvg = 'Od teba poch�dza bohatstvo i_sl�va; / ty panuje� nad v�etk�mi. / V_tvojej ruke je moc a_sila, / tvoja ruka rob� v�etko ve�k�m a_mocn�m.' where spis = '1Krn' and vers = 1 and k = 29 and v = 12
update biblia set nvg = 'Teraz �a teda, Bo�e n�, oslavujeme / a_veleb�me tvoje sl�vne meno.' where spis = '1Krn' and vers = 1 and k = 29 and v = 13
go

-- OCR13NEc_CIT1, k. resp.
update biblia set lh_id = 'CHVAL_1KRN29, k. resp.' where spis = '1Krn' and vers = 1 and k = 10 and v between 13 and 14
go
-- text je dos� rozk�skovan�: "Saul zomrel pre svoje nepr�vosti, preto, �e poru�il P�nov pr�kaz, ktor� mu dal. ... Aj preto, �e sa dopytoval ve�tkyne a_ned�veroval P�novi. ... Boh preniesol jeho kr�ovstvo na D�vida."
update biblia set nvg = '... Saul zomrel pre svoje nepr�vosti, preto, �e poru�il P�nov pr�kaz, ktor� mu dal, aj preto, �e sa dopytoval ve�tkyne ' where spis = '1Krn' and vers = 1 and k = 10 and v = 13
update biblia set nvg = 'a_ned�veroval P�novi. Boh preniesol jeho kr�ovstvo na D�vida [...]' where spis = '1Krn' and vers = 1 and k = 10 and v = 14
go

-- OCR15PIc_CIT1
-- 2 Krn 20, 1-9. 13-24
update biblia set lh_id = 'OCR15PIc_CIT1' where spis = '2Krn' and vers = 1 and k = 20 and v between 1 and 9
update biblia set lh_id = 'OCR15PIc_CIT1' where spis = '2Krn' and vers = 1 and k = 20 and v between 13 and 24
go
update biblia set nvg = 'Zhroma�dili sa Moab�ania a_Ammon�ania a_s_nimi niektor� Maonit�ania do boja proti Jozafatovi.' where spis = '2Krn' and vers = 1 and k = 20 and v = 1
update biblia set nvg = 'K_Jozafatovi pri�li posli a_hl�sili mu: �Ide proti tebe ve�k� mno�stvo z_miest za morom, z_Edomu. U� s� v_Asasontamare, �o je Engaddi.� ' where spis = '2Krn' and vers = 1 and k = 20 and v = 2
update biblia set nvg = 'Jozafata sa zmocnil strach. �penlivo za�al prosi� P�na a_vyhl�sil p�st v_celej Judei.', juv = '<p> pred v. 3' where spis = '2Krn' and vers = 1 and k = 20 and v = 3
update biblia set nvg = 'A_J�dovci sa zhroma�dili uprosova� P�na. Pri�li zo v�etk�ch svojich miest a_�penlivo ho prosili. ' where spis = '2Krn' and vers = 1 and k = 20 and v = 4
update biblia set nvg = 'Jozafat si stal doprostred zhroma�den�ch J�dovcov a_Jeruzalem�anov v_P�novom dome pred nov�m n�dvor�m ', juv = '<p> pred v. 5' where spis = '2Krn' and vers = 1 and k = 20 and v = 5
update biblia set nvg = 'a_hovoril: �Pane, Bo�e na�ich otcov, ty si Boh na nebi a_vl�dne� nad v�etk�mi kr�ovstvami n�rodov. V_tvojej ruke je sila a_moc a_nik sa ti nem��e postavi� na odpor.' where spis = '2Krn' and vers = 1 and k = 20 and v = 6
update biblia set nvg = 'A_nevyhnal si ty, n� Boh, obyvate�ov tejto krajiny pred svoj�m �udom, Izraelom, a_nedal si ju potomkom svojho priate�a Abrah�ma naveky?' where spis = '2Krn' and vers = 1 and k = 20 and v = 7
update biblia set nvg = 'Usadili sa v_nej a_postavili v_nej sv�ty�u tvojmu menu, hovoriac: ' where spis = '2Krn' and vers = 1 and k = 20 and v = 8
update biblia set nvg = '�Ke� na n�s pr�de ne��astie, trestaj�ci me�, mor a_hlad, postav�me sa pred tento dom pred teba, lebo v_tomto dome je tvoje meno, a_budeme vola� k_tebe vo svojom s��en� a_ty n�s vysly�� a_zachr�ni�.��' where spis = '2Krn' and vers = 1 and k = 20 and v = 9
update biblia set nvg = 'Cel� Judea st�la pred P�nom i_so svojimi mali�k�mi, man�elkami a_de�mi.' where spis = '2Krn' and vers = 1 and k = 20 and v = 13
update biblia set nvg = 'Bol tam Jahaziel, syn Zachari�a, syna Banai�a, syna Jehiela, syna Mattani�a, levitu z_Asafov�ch synov. Na neho zost�pil uprostred zhroma�denia P�nov duch ', juv = '<p> pred v. 14' where spis = '2Krn' and vers = 1 and k = 20 and v = 14
update biblia set nvg = 'a_hovoril: �Po��vajte, v�etci J�dovci a_obyvatelia Jeruzalema, aj ty, kr� Jozafat: Toto v�m hovor� P�n: Nebojte sa, ani sa nechvejte pred t�mto ve�k�m mno�stvom, lebo to nie je v� boj, ale Bo��.' where spis = '2Krn' and vers = 1 and k = 20 and v = 15
update biblia set nvg = 'Zajtra zost�pite proti nim. Bud� vystupova� po svahu Sis. Zastihnete ich na konci �dolia oproti p��ti Jeruel.' where spis = '2Krn' and vers = 1 and k = 20 and v = 16
update biblia set nvg = 'Vy nebudete bojova�. Len smelo stojte, J�da a_Jeruzalem, a_uvid�te, ako v�m P�n pom��e. Nebojte sa, ani sa nechvejte! Zajtra vyjdite proti nim a_P�n bude s_vami.�' where spis = '2Krn' and vers = 1 and k = 20 and v = 17
update biblia set nvg = 'Jozafat sa sklonil a� tv�rou po zem a_v�etci J�dovci a_obyvatelia Jeruzalema padli pred P�nom a_kla�ali sa mu.' where spis = '2Krn' and vers = 1 and k = 20 and v = 18
update biblia set nvg = 'Potom leviti z_Kaatov�ch synov a_z_Koreho synov vstali a_mohutn�m hlasom chv�lili P�na, Boha Izraela.' where spis = '2Krn' and vers = 1 and k = 20 and v = 19
update biblia set nvg = 'Ke� r�no vstali, vy�li na p��� Tekue. Pri odchode si stal Jozafat doprostred nich a_povedal: �Po��vajte ma, J�dovci a_obyvatelia Jeruzalema! Verte v_P�na, svojho Boha, a_udr��te sa. Verte jeho prorokom a_bude sa v�m dari� vo v�etkom.�', juv = '<p> pred v. 20' where spis = '2Krn' and vers = 1 and k = 20 and v = 20
update biblia set nvg = 'Poradil sa s_�udom a_postavil P�nov�ch spev�kov, aby ho chv�lili v_posv�tnom r�chu, aby kr��ali pred vojskom a_jednohlasne volali: �Oslavujte P�na, lebo jeho milosrdenstvo je ve�n�.�' where spis = '2Krn' and vers = 1 and k = 20 and v = 21
update biblia set nvg = 'Ke� za�ali spieva� chv�lospevy, P�n obr�til ich z�lohy proti Ammon�anom, Moab�anom a_vrchu Seir, ktor� vy�li bojova� proti J�dovcom, a_boli porazen�.', juv = '<p> pred v. 22' where spis = '2Krn' and vers = 1 and k = 20 and v = 22
update biblia set nvg = 'Lebo Ammon�ania a_Moab�ania sa postavili proti obyvate�om vrchu Seir, aby ich pozab�jali a_zni�ili. Ke� to urobili, obr�tili sa proti sebe a_navz�jom sa ni�ili.' where spis = '2Krn' and vers = 1 and k = 20 and v = 23
update biblia set nvg = 'Ke� potom J�dovci pri�li na vyv��en� miesto s_v�h�adom na p���, videli �iroko-�aleko cel� krajinu pln� m�tvol, tak�e nezostal nik, �o by bol unikol smrti. ', juv = '<p> pred v. 24' where spis = '2Krn' and vers = 1 and k = 20 and v = 24
go

-- VPCHR_ZVII_cCIT1, k. resp.
update biblia set lh_id = 'VPCHR_ZVII_cCIT1, k. resp.' where spis = '2Krn' and vers = 1 and k = 7 and v = 15
go
update biblia set nvg = 'Moje o�i bud� otvoren� a_moje u�i pozorn� k_modlitbe na tomto mieste.' where spis = '2Krn' and vers = 1 and k = 7 and v = 15
go

-- 251	2 Krn 5, 6-10. 13 - 6, 2
update biblia set lc_id = 251 where spis = '2Krn' and vers = 1 and k = 5 and v between 6 and 10
update biblia set lc_id = 251 where spis = '2Krn' and vers = 1 and k = 5 and v between 13 and 14
update biblia set lc_id = 251 where spis = '2Krn' and vers = 1 and k = 6 and v between 1 and 2
go
update biblia set nvg = 'Kr� �alam�n a cel� izraelsk� pospolitos�, v�etci, �o sa k nemu zhroma�dili pred archu, obetovali nespo��tate�n� mno�stvo oviec a dobytka; nesmierne bolo mno�stvo obet�.' where spis = '2Krn' and vers = 1 and k = 5 and v = 6
update biblia set nvg = 'K�azi zaniesli archu P�novej zmluvy na jej miesto v chr�me, zvan� Dabir, do ve�sv�tyne, pod kr�dla cherub�nov; ' where spis = '2Krn' and vers = 1 and k = 5 and v = 7
update biblia set nvg = 'cherub�ni mali rozprestret� kr�dla nad miestom, kde polo�ili archu, a tak zakr�vali archu a jej �rde.' where spis = '2Krn' and vers = 1 and k = 5 and v = 8
update biblia set nvg = '�rde v�ak, na ktor�ch sa nosievala archa, boli trochu dlh�ie, a preto ich konce bolo vidie� pred Dabirom; no ak bol niekto vonku, vidie� ich nemohol. Archa tam ostala a� po dne�n� de�.' where spis = '2Krn' and vers = 1 and k = 5 and v = 9
update biblia set nvg = 'V arche nebolo ni� in�, iba dve tabule, ktor� do nej vlo�il Moj�i� na Horebe, ke� P�n uzavrel so synmi Izraela zmluvu pri ich v�chode z egyptskej krajiny.' where spis = '2Krn' and vers = 1 and k = 5 and v = 10
update biblia set nvg = '[...] Ke� za�ali hlasno spieva� a vyhr�va� na tr�bach, cimbaloch, organoch a na v�elijak�ch in�ch hudobn�ch n�strojoch a jedn�m hlasom chv�li� P�na: "Oslavujte P�na, lebo je dobr�, lebo jeho milosrdenstvo trv� naveky," Bo�� dom naplnil oblak; ', juv = '<p> pred v. 13' where spis = '2Krn' and vers = 1 and k = 5 and v = 13
update biblia set nvg = 'k�azi nemohli pre oblak kona� slu�bu, lebo Bo�� dom naplnila P�nova sl�va.' where spis = '2Krn' and vers = 1 and k = 5 and v = 14
update biblia set nvg = 'Vtedy povedal �alam�n: "P�n s��bil, �e bude b�va� v mr�kave; ', juv = '<p> pred v. 1' where spis = '2Krn' and vers = 1 and k = 6 and v = 1
update biblia set nvg = 'a ja som ti postavil dom za pr�bytok, aby si v �om b�val naveky."' where spis = '2Krn' and vers = 1 and k = 6 and v = 2
go

-- 248	2 Krn 24, 17-25
-- 249	2 Krn 24, 18-22 // nepou�it�, je s��as�ou predo�l�ho
update biblia set lc_id = 248 where spis = '2Krn' and vers = 1 and k = 24 and v between 17 and 25
go
update biblia set nvg = 'Po Jojadovej smrti pri�li judsk� knie�at� a poklonili sa kr�ovi; on, o�aren� ich �slu�nos�ou, po��vol ich: ' where spis = '2Krn' and vers = 1 and k = 24 and v = 17
update biblia set nvg = 'opustili chr�m P�na, Boha svojich otcov, a sl��ili posv�tn�m kame�om a modl�m. Pre tento hriech do�ahol hnev na J�du a Jeruzalem.' where spis = '2Krn' and vers = 1 and k = 24 and v = 18
update biblia set nvg = 'Posielal k nim prorokov, aby sa vr�tili k P�novi, ale nechceli po�u� ich napom�nanie.' where spis = '2Krn' and vers = 1 and k = 24 and v = 19
update biblia set nvg = 'Vtedy duch Bo�� zahalil Zachari�a, syna k�aza Jojadu; on si stal pred �ud a povedal mu: "Toto hovor� Boh: Pre�o prestupujete P�nove pr�kazy? To v�m nem��e oso�i�. Preto�e ste opustili P�na, on opustil v�s."' where spis = '2Krn' and vers = 1 and k = 24 and v = 20
update biblia set nvg = 'Oni sa proti nemu sprisahali a pod�a kr�ovho rozkazu ho ukame�ovali na n�dvor� P�novho domu.' where spis = '2Krn' and vers = 1 and k = 24 and v = 21
update biblia set nvg = 'Kr� Joas si nespomenul na dobrodenie, ktor� mu preuk�zal Zachari�ov otec Jojada, a zavra�dil jeho syna. On umieraj�c povedal: "Nech to P�n vid� a nech sa pomst�!"' where spis = '2Krn' and vers = 1 and k = 24 and v = 22
update biblia set nvg = 'O rok proti nemu tiahlo s�rske vojsko. Pri�lo do Judska, a� do Jeruzalema, a vyhubilo v�etky knie�at� �udu a cel� koris� poslalo kr�ovi do Damasku.' where spis = '2Krn' and vers = 1 and k = 24 and v = 23
update biblia set nvg = 'Hoci pri�lo ve�mi m�lo S�r�anov, P�n im vydal do r�k ve�mi ve�k� vojsko, lebo opustili P�na, Boha svojich otcov. Aj nad Joasom vykonali potupn� s�d, ' where spis = '2Krn' and vers = 1 and k = 24 and v = 24
update biblia set nvg = 'nechali ho �a�ko chor�ho a odi�li. Potom sa proti nemu sprisahali jeho sluhovia na pomstu za krv syna k�aza Jojadu a zabili ho na jeho l��ku. Zomrel a pochovali ho v D�vidovom meste, ale nie v kr�ovsk�ch hroboch.' where spis = '2Krn' and vers = 1 and k = 24 and v = 25
go

-- 250	2 Krn 36, 14-16. 19-23
update biblia set lc_id = 250 where spis = '2Krn' and vers = 1 and k = 36 and v between 14 and 16
update biblia set lc_id = 250 where spis = '2Krn' and vers = 1 and k = 36 and v between 19 and 23
go
update biblia set nvg = 'V�etky k�azsk� knie�at� i �ud mno�ili nevernosti, napodob�ovali v�etky ohavnosti pohanov a po�kvrnili P�nov dom, ktor� si zasv�til v Jeruzaleme.' where spis = '2Krn' and vers = 1 and k = 36 and v = 14
update biblia set nvg = 'P�n, Boh ich otcov, posielal k nim poslov a vo dne v noci ich napom�nal, lebo mu bolo ��to svojho �udu a svojho pr�bytku.' where spis = '2Krn' and vers = 1 and k = 36 and v = 15
update biblia set nvg = 'Ale oni vysmiali Bo��ch poslov, poh�dali jeho slovami a tupili jeho prorokov, a� vzr�stol P�nov hnev proti jeho �udu a u� nebolo lieku.' where spis = '2Krn' and vers = 1 and k = 36 and v = 16
update biblia set nvg = '(Nepriatelia) sp�lili Bo�� dom, zr�cali jeruzalemsk� m�ry, podp�lili v�etky pal�ce a zni�ili v�etky cenn� predmety.' where spis = '2Krn' and vers = 1 and k = 36 and v = 19
update biblia set nvg = 'T�ch, �o unikli me�u, odvliekli do Babylonu a stali sa otrokmi kr�a a jeho synov, k�m sa neza�alo kr�ovstvo Per�anov.' where spis = '2Krn' and vers = 1 and k = 36 and v = 20
update biblia set nvg = 'Tak sa splnilo P�novo slovo, ktor� povedal �stami Jeremi�a: Teraz zem dostala svoje soboty, cez cel� �as spusto�enia odpo��vala, a� sa naplnilo sedemdesiat rokov.' where spis = '2Krn' and vers = 1 and k = 36 and v = 21
update biblia set nvg = 'V prvom roku K�ra, kr�a Per�anov, sa splnilo, �o P�n povedal �stami Jeremi�a. P�n vnukol K�rovi, kr�ovi Per�anov, a on po celom svojom kr�ovstve nariadil vyhl�si� aj p�somne: ' where spis = '2Krn' and vers = 1 and k = 36 and v = 22
update biblia set nvg = '"Takto hovor� K�ros, kr� Per�anov: P�n, Boh nebies, mi dal v�etky kr�ovstv� zeme. A rozk�zal mi, aby som mu postavil dom v Jeruzaleme, ktor� je v Judei. S ka�d�m, kto patr� k jeho �udu, nech je P�n, jeho Boh, a nech vyst�pi."' where spis = '2Krn' and vers = 1 and k = 36 and v = 23
go
