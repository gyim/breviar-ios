-- 123	1 Krn 15, 3-4. 15-16; 16, 1-2
update biblia set lc_id = 123 where spis = '1Krn' and vers = 1 and k = 15 and v between 3 and 4
update biblia set lc_id = 123 where spis = '1Krn' and vers = 1 and k = 15 and v between 15 and 16
update biblia set lc_id = 123 where spis = '1Krn' and vers = 1 and k = 16 and v between 1 and 2
go
update biblia set nvg = 'Dávid zhromadil celı Izrael v Jeruzaleme, lebo sa prenášala Pánova archa na miesto, ktoré pre òu pripravil.' where spis = '1Krn' and vers = 1 and k = 15 and v = 3
update biblia set nvg = 'Zhromadil aj Áronovıch synov a levitov.' where spis = '1Krn' and vers = 1 and k = 15 and v = 4
update biblia set nvg = 'Synovia Léviho niesli Boiu archu pomocou rdí na pleciach, ako to pod¾a Pánovho slova prikázal Mojiš.' where spis = '1Krn' and vers = 1 and k = 15 and v = 15
update biblia set nvg = 'Dávid rozkázal predstavenım levitov, aby zo svojich bratov ustanovili spevákov s hudobnımi nástrojmi, s citarami, harfami a cimbalmi tak, aby mocne znelo radostné plesanie.' where spis = '1Krn' and vers = 1 and k = 15 and v = 16
update biblia set nvg = 'Tak preniesli Boiu archu a postavili ju uprostred stanu, ktorı pre òu postavil Dávid. Potom obetovali pred Bohom zápalné a pokojné obety.' where spis = '1Krn' and vers = 1 and k = 16 and v = 1
update biblia set nvg = 'Keï Dávid skonèil obetovanie zápalnıch a pokojnıch obiet, poehnal ¾ud v mene Pánovom.' where spis = '1Krn' and vers = 1 and k = 16 and v = 2
go

-- 25MAR_cCIT1
-- SCPM_ZVI_cCIT1 = SCPM_ZVII_cCIT1
update biblia set lh_id = '25MAR_cCIT1', juv = '= SCPM_ZVI_cCIT1 = SCPM_ZVII_cCIT1' where spis = '1Krn' and vers = 1 and k = 17 and v between 1 and 15
go
update biblia set nvg = 'Keï Dávid bıval vo svojom paláci, povedal prorokovi Nátanovi: „Pozri, ja bıvam v_dome z_cédrov a_Pánova archa zmluvy je pod stanmi.“' where spis = '1Krn' and vers = 1 and k = 17 and v = 1
update biblia set nvg = 'Nátan odpovedal Dávidovi: „Urob všetko, èo ti vnuká srdce, Boh je s_tebou.“' where spis = '1Krn' and vers = 1 and k = 17 and v = 2
update biblia set nvg = 'V_tú noc zaznelo Nátanovi Boie slovo:', juv = '<p> pred v. 3' where spis = '1Krn' and vers = 1 and k = 17 and v = 3
update biblia set nvg = '„Choï a_povedz môjmu sluobníkovi Dávidovi: Toto hovorí Pán: Ty mi nepostavíš dom, v_ktorom mám bıva;' where spis = '1Krn' and vers = 1 and k = 17 and v = 4
update biblia set nvg = 'veï som nebıval v_dome odvtedy, èo som vyviedol Izraela, a po tento deò, ale som sa sahoval zo stanu do stanu a_z_príbytku do príbytku.' where spis = '1Krn' and vers = 1 and k = 17 and v = 5
update biblia set nvg = 'Vari som niekedy, keï som putoval uprostred Izraela, povedal niektorému zo sudcov Izraela, ktorım som prikázal pás môj ¾ud: Preèo ste mi nepostavili cédrovı dom?' where spis = '1Krn' and vers = 1 and k = 17 and v = 6
update biblia set nvg = 'Preto teraz takto povieš môjmu sluobníkovi Dávidovi: Toto hovorí Pán zástupov: Ja som a vzal z_pastvín od oviec, aby si bol vodcom môjho ¾udu, Izraela, ' where spis = '1Krn' and vers = 1 and k = 17 and v = 7
update biblia set nvg = 'a_bol som s_tebou všade, kade si chodil; pred tvojimi oèami som vyhubil všetkıch tvojich nepriate¾ov a_zaistil som ti meno, aké majú len najväèší na zemi.' where spis = '1Krn' and vers = 1 and k = 17 and v = 8
update biblia set nvg = 'Svojmu ¾udu, Izraelu, som urèil miesto a_tam som ho zasadil; tam bude bıva. A_u sa nepohne a_ani zlosynovia ho u nebudú utláèa ako kedysi ' where spis = '1Krn' and vers = 1 and k = 17 and v = 9
update biblia set nvg = 'a_v_dòoch, keï som ustanovoval sudcov nad svojím ¾udom, Izraelom, a_poníil všetkıch tvojich nepriate¾ov. Oznamujem ti teda, e Pán tebe vybuduje dom.' where spis = '1Krn' and vers = 1 and k = 17 and v = 10
update biblia set nvg = 'A_a naplníš svoje dni a_ty odídeš k_svojim otcom, pozdvihnem po tebe tvojho potomka, ktorı bude pochádza z_tvojich synov, a_upevním jeho krá¾ovstvo.' where spis = '1Krn' and vers = 1 and k = 17 and v = 11
update biblia set nvg = 'On mi postaví dom a_ja upevním jeho trón naveky.' where spis = '1Krn' and vers = 1 and k = 17 and v = 12
update biblia set nvg = 'Ja mu budem otcom a_on mi bude synom a_svoju priazeò mu neodnímem, ako som odòal tomu, èo bol pred tebou.' where spis = '1Krn' and vers = 1 and k = 17 and v = 13
update biblia set nvg = 'Ustanovím ho v_svojom dome a_v_svojom krá¾ovstve naveky a_jeho trón bude upevnenı navdy.“' where spis = '1Krn' and vers = 1 and k = 17 and v = 14
update biblia set nvg = 'Nátan povedal všetky tieto slová a_celé videnie Dávidovi.', juv = '<p> pred v. 15' where spis = '1Krn' and vers = 1 and k = 17 and v = 15
go

-- OCR14STVc_CIT1 -- 1 Krn 22, 5-19
update biblia set lh_id = 'OCR14STVc_CIT1' where spis = '1Krn' and vers = 1 and k = 22 and v between 5 and 19
go
update biblia set nvg = 'Dávid povedal: „Môj syn Šalamún je ešte mladı a_útly chlapec a_dom, ktorı treba postavi Pánovi, musí by takı, aby ho spomínali a_oslavovali vo všetkıch krajinách. Pripravím mu teda, èo bude potrebova.“ A_preto pred svojou smrou pripravil všetky prostriedky.' where spis = '1Krn' and vers = 1 and k = 22 and v = 5
update biblia set nvg = 'Potom zavolal svojho syna Šalamúna a_prikázal mu, aby postavil dom Pánovi, Bohu Izraela.', juv = '<p> pred v. 6' where spis = '1Krn' and vers = 1 and k = 22 and v = 6
update biblia set nvg = 'Dávid povedal Šalamúnovi: „Syn môj, ja som zamıš¾al postavi dom menu Pána, môjho Boha.' where spis = '1Krn' and vers = 1 and k = 22 and v = 7
update biblia set nvg = 'Ale Pán mi povedal: ‚Prelial si ve¾a krvi a_viedol ve¾ké vojny. Nebudeš môc postavi dom môjmu menu, keï si vylial to¾ko krvi predo mnou.' where spis = '1Krn' and vers = 1 and k = 22 and v = 8
update biblia set nvg = 'Syn, ktorı sa ti narodí, bude muom pokoja. Zaistím mu pokoj od všetkıch jeho nepriate¾ov zo všetkıch strán, a_preto sa bude vola Šalamún. Pokoj a_mier darujem v_Izraeli po všetky jeho dni.' where spis = '1Krn' and vers = 1 and k = 22 and v = 9
update biblia set nvg = 'On postaví dom môjmu menu. On mi bude synom a_ja mu budem otcom. A_upevním jeho krá¾ovskı trón nad Izraelom naveky.‘' where spis = '1Krn' and vers = 1 and k = 22 and v = 10
update biblia set nvg = 'A_teraz nech je s_tebou Pán, syn môj. Nech sa ti darí postavi dom Pánovi, svojmu Bohu, ako to o_tebe povedal.' where spis = '1Krn' and vers = 1 and k = 22 and v = 11
update biblia set nvg = 'Nech ti Pán dá múdros a_rozvahu, aby si vedel spravova Izrael a_zachováva zákon Pána, svojho Boha.' where spis = '1Krn' and vers = 1 and k = 22 and v = 12
update biblia set nvg = 'Iba vtedy budeš ma úspech, keï budeš zachováva prikázania a_ustanovenia, ktoré dal Pán Mojišovi pre Izrael. Buï statoènı a_vzmu sa! Neboj sa, ani sa nechvej!' where spis = '1Krn' and vers = 1 and k = 22 and v = 13
update biblia set nvg = 'Pozri, ja som popri svojich strastiach pripravil prostriedky na Pánov dom: stotisíc talentov zlata a_milión talentov striebra, meï a_elezo nemono ani odvái, lebo je ich tak ve¾a. Pripravil som drevo i_kameò; a_ty k_tomu pridáš.' where spis = '1Krn' and vers = 1 and k = 22 and v = 14
update biblia set nvg = 'Máš aj ve¾a remeselníkov – kamenárov, murárov, tesárov a_rôznych odborníkov schopnıch vytvori diela ' where spis = '1Krn' and vers = 1 and k = 22 and v = 15
update biblia set nvg = 'zo zlata a_striebra, medi a_eleza, èoho je bez poètu. Vstaò teda a_rob a_Pán bude s_tebou.“' where spis = '1Krn' and vers = 1 and k = 22 and v = 16
update biblia set nvg = 'Dávid prikázal aj všetkım izraelskım knieatám, aby pomáhali jeho synovi Šalamúnovi:', juv = '<p> pred v. 17' where spis = '1Krn' and vers = 1 and k = 22 and v = 17
update biblia set nvg = '„Vidíte, e Pán, váš Boh, je s_vami a_daroval vám pokoj zo všetkıch strán, obyvate¾ov krajiny vydal do vašej ruky a_krajina sa podrobila Pánovi a_jeho ¾udu.' where spis = '1Krn' and vers = 1 and k = 22 and v = 18
update biblia set nvg = 'Oddajte teda svoje srdcia a_svoje duše h¾adaniu Pána, svojho Boha. Vstaòte a_stavajte svätyòu Pánovi, Bohu, aby sa mohla zanies archa Pánovej zmluvy i_nádoby zasvätené Bohu do domu, ktorı sa postaví Pánovmu menu.“' where spis = '1Krn' and vers = 1 and k = 22 and v = 19
go

-- CHVAL_1KRN29
-- 124	1 Krn 29, 10bc. 11. 12 // nepouité
-- 125	1 Krn 29, 10bc. 11a-c. 11d-12a. 12b-d // nepouité
update biblia set lh_id = 'CHVAL_1KRN29' where spis = '1Krn' and vers = 1 and k = 29 and v between 10 and 13
go
update biblia set lc_id = 124 where spis = '1Krn' and vers = 1 and k = 29 and v between 10 and 12
go
update biblia set nvg = '[...] Zvelebenı buï, Pane, Boe nášho otca Izraela, / od vekov naveky.' where spis = '1Krn' and vers = 1 and k = 29 and v = 10
update biblia set nvg = 'Tvoja je, Pane, vznešenos i_moc, / sláva, jas a_veleba, / lebo tvoje je všetko na nebi i_na zemi. / Tvoje je, Pane, krá¾ovstvo, / ty si vyvıšenı ako hlava nad všetkım.' where spis = '1Krn' and vers = 1 and k = 29 and v = 11
update biblia set nvg = 'Od teba pochádza bohatstvo i_sláva; / ty panuješ nad všetkımi. / V_tvojej ruke je moc a_sila, / tvoja ruka robí všetko ve¾kım a_mocnım.' where spis = '1Krn' and vers = 1 and k = 29 and v = 12
update biblia set nvg = 'Teraz a teda, Boe náš, oslavujeme / a_velebíme tvoje slávne meno.' where spis = '1Krn' and vers = 1 and k = 29 and v = 13
go
