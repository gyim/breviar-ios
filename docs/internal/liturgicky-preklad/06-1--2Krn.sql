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
