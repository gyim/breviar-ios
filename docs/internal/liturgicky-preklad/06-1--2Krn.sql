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

-- OCR13NEc_CIT1, k. resp.
update biblia set lh_id = 'CHVAL_1KRN29, k. resp.' where spis = '1Krn' and vers = 1 and k = 10 and v between 13 and 14
go
-- text je dos rozkúskovanı: "Saul zomrel pre svoje neprávosti, preto, e porušil Pánov príkaz, ktorı mu dal. ... Aj preto, e sa dopytoval veštkyne a_nedôveroval Pánovi. ... Boh preniesol jeho krá¾ovstvo na Dávida."
update biblia set nvg = '... Saul zomrel pre svoje neprávosti, preto, e porušil Pánov príkaz, ktorı mu dal, aj preto, e sa dopytoval veštkyne ' where spis = '1Krn' and vers = 1 and k = 10 and v = 13
update biblia set nvg = 'a_nedôveroval Pánovi. Boh preniesol jeho krá¾ovstvo na Dávida [...]' where spis = '1Krn' and vers = 1 and k = 10 and v = 14
go

-- OCR15PIc_CIT1
-- 2 Krn 20, 1-9. 13-24
update biblia set lh_id = 'OCR15PIc_CIT1' where spis = '2Krn' and vers = 1 and k = 20 and v between 1 and 9
update biblia set lh_id = 'OCR15PIc_CIT1' where spis = '2Krn' and vers = 1 and k = 20 and v between 13 and 24
go
update biblia set nvg = 'Zhromadili sa Moabèania a_Ammonèania a_s_nimi niektorí Maonitèania do boja proti Jozafatovi.' where spis = '2Krn' and vers = 1 and k = 20 and v = 1
update biblia set nvg = 'K_Jozafatovi prišli posli a_hlásili mu: „Ide proti tebe ve¾ké mnostvo z_miest za morom, z_Edomu. U sú v_Asasontamare, èo je Engaddi.“ ' where spis = '2Krn' and vers = 1 and k = 20 and v = 2
update biblia set nvg = 'Jozafata sa zmocnil strach. Úpenlivo zaèal prosi Pána a_vyhlásil pôst v_celej Judei.', juv = '<p> pred v. 3' where spis = '2Krn' and vers = 1 and k = 20 and v = 3
update biblia set nvg = 'A_Júdovci sa zhromadili uprosova Pána. Prišli zo všetkıch svojich miest a_úpenlivo ho prosili. ' where spis = '2Krn' and vers = 1 and k = 20 and v = 4
update biblia set nvg = 'Jozafat si stal doprostred zhromadenıch Júdovcov a_Jeruzalemèanov v_Pánovom dome pred novım nádvorím ', juv = '<p> pred v. 5' where spis = '2Krn' and vers = 1 and k = 20 and v = 5
update biblia set nvg = 'a_hovoril: „Pane, Boe našich otcov, ty si Boh na nebi a_vládneš nad všetkımi krá¾ovstvami národov. V_tvojej ruke je sila a_moc a_nik sa ti nemôe postavi na odpor.' where spis = '2Krn' and vers = 1 and k = 20 and v = 6
update biblia set nvg = 'A_nevyhnal si ty, náš Boh, obyvate¾ov tejto krajiny pred svojím ¾udom, Izraelom, a_nedal si ju potomkom svojho priate¾a Abraháma naveky?' where spis = '2Krn' and vers = 1 and k = 20 and v = 7
update biblia set nvg = 'Usadili sa v_nej a_postavili v_nej svätyòu tvojmu menu, hovoriac: ' where spis = '2Krn' and vers = 1 and k = 20 and v = 8
update biblia set nvg = '‚Keï na nás príde nešastie, trestajúci meè, mor a_hlad, postavíme sa pred tento dom pred teba, lebo v_tomto dome je tvoje meno, a_budeme vola k_tebe vo svojom súení a_ty nás vyslyšíš a_zachrániš.‘“' where spis = '2Krn' and vers = 1 and k = 20 and v = 9
update biblia set nvg = 'Celá Judea stála pred Pánom i_so svojimi malièkımi, manelkami a_demi.' where spis = '2Krn' and vers = 1 and k = 20 and v = 13
update biblia set nvg = 'Bol tam Jahaziel, syn Zachariáša, syna Banaiáša, syna Jehiela, syna Mattaniáša, levitu z_Asafovıch synov. Na neho zostúpil uprostred zhromadenia Pánov duch ', juv = '<p> pred v. 14' where spis = '2Krn' and vers = 1 and k = 20 and v = 14
update biblia set nvg = 'a_hovoril: „Poèúvajte, všetci Júdovci a_obyvatelia Jeruzalema, aj ty, krá¾ Jozafat: Toto vám hovorí Pán: Nebojte sa, ani sa nechvejte pred tımto ve¾kım mnostvom, lebo to nie je váš boj, ale Boí.' where spis = '2Krn' and vers = 1 and k = 20 and v = 15
update biblia set nvg = 'Zajtra zostúpite proti nim. Budú vystupova po svahu Sis. Zastihnete ich na konci údolia oproti púšti Jeruel.' where spis = '2Krn' and vers = 1 and k = 20 and v = 16
update biblia set nvg = 'Vy nebudete bojova. Len smelo stojte, Júda a_Jeruzalem, a_uvidíte, ako vám Pán pomôe. Nebojte sa, ani sa nechvejte! Zajtra vyjdite proti nim a_Pán bude s_vami.“' where spis = '2Krn' and vers = 1 and k = 20 and v = 17
update biblia set nvg = 'Jozafat sa sklonil a tvárou po zem a_všetci Júdovci a_obyvatelia Jeruzalema padli pred Pánom a_klaòali sa mu.' where spis = '2Krn' and vers = 1 and k = 20 and v = 18
update biblia set nvg = 'Potom leviti z_Kaatovıch synov a_z_Koreho synov vstali a_mohutnım hlasom chválili Pána, Boha Izraela.' where spis = '2Krn' and vers = 1 and k = 20 and v = 19
update biblia set nvg = 'Keï ráno vstali, vyšli na púš Tekue. Pri odchode si stal Jozafat doprostred nich a_povedal: „Poèúvajte ma, Júdovci a_obyvatelia Jeruzalema! Verte v_Pána, svojho Boha, a_udríte sa. Verte jeho prorokom a_bude sa vám dari vo všetkom.“', juv = '<p> pred v. 20' where spis = '2Krn' and vers = 1 and k = 20 and v = 20
update biblia set nvg = 'Poradil sa s_¾udom a_postavil Pánovıch spevákov, aby ho chválili v_posvätnom rúchu, aby kráèali pred vojskom a_jednohlasne volali: „Oslavujte Pána, lebo jeho milosrdenstvo je veèné.“' where spis = '2Krn' and vers = 1 and k = 20 and v = 21
update biblia set nvg = 'Keï zaèali spieva chválospevy, Pán obrátil ich zálohy proti Ammonèanom, Moabèanom a_vrchu Seir, ktorí vyšli bojova proti Júdovcom, a_boli porazení.', juv = '<p> pred v. 22' where spis = '2Krn' and vers = 1 and k = 20 and v = 22
update biblia set nvg = 'Lebo Ammonèania a_Moabèania sa postavili proti obyvate¾om vrchu Seir, aby ich pozabíjali a_znièili. Keï to urobili, obrátili sa proti sebe a_navzájom sa nièili.' where spis = '2Krn' and vers = 1 and k = 20 and v = 23
update biblia set nvg = 'Keï potom Júdovci prišli na vyvıšené miesto s_vıh¾adom na púš, videli široko-ïaleko celú krajinu plnú màtvol, take nezostal nik, èo by bol unikol smrti. ', juv = '<p> pred v. 24' where spis = '2Krn' and vers = 1 and k = 20 and v = 24
go

-- VPCHR_ZVII_cCIT1, k. resp.
update biblia set lh_id = 'VPCHR_ZVII_cCIT1, k. resp.' where spis = '2Krn' and vers = 1 and k = 7 and v = 15
go
update biblia set nvg = 'Moje oèi budú otvorené a_moje uši pozorné k_modlitbe na tomto mieste.' where spis = '2Krn' and vers = 1 and k = 7 and v = 15
go

-- 251	2 Krn 5, 6-10. 13 - 6, 2
update biblia set lc_id = 251 where spis = '2Krn' and vers = 1 and k = 5 and v between 6 and 10
update biblia set lc_id = 251 where spis = '2Krn' and vers = 1 and k = 5 and v between 13 and 14
update biblia set lc_id = 251 where spis = '2Krn' and vers = 1 and k = 6 and v between 1 and 2
go
update biblia set nvg = 'Krá¾ Šalamún a celá izraelská pospolitos, všetci, èo sa k nemu zhromadili pred archu, obetovali nespoèítate¾né mnostvo oviec a dobytka; nesmierne bolo mnostvo obetí.' where spis = '2Krn' and vers = 1 and k = 5 and v = 6
update biblia set nvg = 'Kòazi zaniesli archu Pánovej zmluvy na jej miesto v chráme, zvané Dabir, do ve¾svätyne, pod krídla cherubínov; ' where spis = '2Krn' and vers = 1 and k = 5 and v = 7
update biblia set nvg = 'cherubíni mali rozprestreté krídla nad miestom, kde poloili archu, a tak zakrıvali archu a jej rde.' where spis = '2Krn' and vers = 1 and k = 5 and v = 8
update biblia set nvg = 'rde však, na ktorıch sa nosievala archa, boli trochu dlhšie, a preto ich konce bolo vidie pred Dabirom; no ak bol niekto vonku, vidie ich nemohol. Archa tam ostala a po dnešnı deò.' where spis = '2Krn' and vers = 1 and k = 5 and v = 9
update biblia set nvg = 'V arche nebolo niè iné, iba dve tabule, ktoré do nej vloil Mojiš na Horebe, keï Pán uzavrel so synmi Izraela zmluvu pri ich vıchode z egyptskej krajiny.' where spis = '2Krn' and vers = 1 and k = 5 and v = 10
update biblia set nvg = '[...] Keï zaèali hlasno spieva a vyhráva na trúbach, cimbaloch, organoch a na všelijakıch inıch hudobnıch nástrojoch a jednım hlasom chváli Pána: "Oslavujte Pána, lebo je dobrı, lebo jeho milosrdenstvo trvá naveky," Boí dom naplnil oblak; ', juv = '<p> pred v. 13' where spis = '2Krn' and vers = 1 and k = 5 and v = 13
update biblia set nvg = 'kòazi nemohli pre oblak kona slubu, lebo Boí dom naplnila Pánova sláva.' where spis = '2Krn' and vers = 1 and k = 5 and v = 14
update biblia set nvg = 'Vtedy povedal Šalamún: "Pán s¾úbil, e bude bıva v mrákave; ', juv = '<p> pred v. 1' where spis = '2Krn' and vers = 1 and k = 6 and v = 1
update biblia set nvg = 'a ja som ti postavil dom za príbytok, aby si v òom bıval naveky."' where spis = '2Krn' and vers = 1 and k = 6 and v = 2
go

-- 248	2 Krn 24, 17-25
-- 249	2 Krn 24, 18-22 // nepouité, je súèasou predošlého
update biblia set lc_id = 248 where spis = '2Krn' and vers = 1 and k = 24 and v between 17 and 25
go
update biblia set nvg = 'Po Jojadovej smrti prišli judské knieatá a poklonili sa krá¾ovi; on, oèarenı ich úslunosou, poèúvol ich: ' where spis = '2Krn' and vers = 1 and k = 24 and v = 17
update biblia set nvg = 'opustili chrám Pána, Boha svojich otcov, a slúili posvätnım kameòom a modlám. Pre tento hriech do¾ahol hnev na Júdu a Jeruzalem.' where spis = '2Krn' and vers = 1 and k = 24 and v = 18
update biblia set nvg = 'Posielal k nim prorokov, aby sa vrátili k Pánovi, ale nechceli poèu ich napomínanie.' where spis = '2Krn' and vers = 1 and k = 24 and v = 19
update biblia set nvg = 'Vtedy duch Boí zahalil Zachariáša, syna kòaza Jojadu; on si stal pred ¾ud a povedal mu: "Toto hovorí Boh: Preèo prestupujete Pánove príkazy? To vám nemôe osoi. Pretoe ste opustili Pána, on opustil vás."' where spis = '2Krn' and vers = 1 and k = 24 and v = 20
update biblia set nvg = 'Oni sa proti nemu sprisahali a pod¾a krá¾ovho rozkazu ho ukameòovali na nádvorí Pánovho domu.' where spis = '2Krn' and vers = 1 and k = 24 and v = 21
update biblia set nvg = 'Krá¾ Joas si nespomenul na dobrodenie, ktoré mu preukázal Zachariášov otec Jojada, a zavradil jeho syna. On umierajúc povedal: "Nech to Pán vidí a nech sa pomstí!"' where spis = '2Krn' and vers = 1 and k = 24 and v = 22
update biblia set nvg = 'O rok proti nemu tiahlo sırske vojsko. Prišlo do Judska, a do Jeruzalema, a vyhubilo všetky knieatá ¾udu a celú koris poslalo krá¾ovi do Damasku.' where spis = '2Krn' and vers = 1 and k = 24 and v = 23
update biblia set nvg = 'Hoci prišlo ve¾mi málo Sırèanov, Pán im vydal do rúk ve¾mi ve¾ké vojsko, lebo opustili Pána, Boha svojich otcov. Aj nad Joasom vykonali potupnı súd, ' where spis = '2Krn' and vers = 1 and k = 24 and v = 24
update biblia set nvg = 'nechali ho ako chorého a odišli. Potom sa proti nemu sprisahali jeho sluhovia na pomstu za krv syna kòaza Jojadu a zabili ho na jeho lôku. Zomrel a pochovali ho v Dávidovom meste, ale nie v krá¾ovskıch hroboch.' where spis = '2Krn' and vers = 1 and k = 24 and v = 25
go

-- 250	2 Krn 36, 14-16. 19-23
update biblia set lc_id = 250 where spis = '2Krn' and vers = 1 and k = 36 and v between 14 and 16
update biblia set lc_id = 250 where spis = '2Krn' and vers = 1 and k = 36 and v between 19 and 23
go
update biblia set nvg = 'Všetky kòazské knieatá i ¾ud mnoili nevernosti, napodobòovali všetky ohavnosti pohanov a poškvrnili Pánov dom, ktorı si zasvätil v Jeruzaleme.' where spis = '2Krn' and vers = 1 and k = 36 and v = 14
update biblia set nvg = 'Pán, Boh ich otcov, posielal k nim poslov a vo dne v noci ich napomínal, lebo mu bolo ¾úto svojho ¾udu a svojho príbytku.' where spis = '2Krn' and vers = 1 and k = 36 and v = 15
update biblia set nvg = 'Ale oni vysmiali Boích poslov, pohàdali jeho slovami a tupili jeho prorokov, a vzrástol Pánov hnev proti jeho ¾udu a u nebolo lieku.' where spis = '2Krn' and vers = 1 and k = 36 and v = 16
update biblia set nvg = '(Nepriatelia) spálili Boí dom, zrúcali jeruzalemské múry, podpálili všetky paláce a znièili všetky cenné predmety.' where spis = '2Krn' and vers = 1 and k = 36 and v = 19
update biblia set nvg = 'Tıch, èo unikli meèu, odvliekli do Babylonu a stali sa otrokmi krá¾a a jeho synov, kım sa nezaèalo krá¾ovstvo Peranov.' where spis = '2Krn' and vers = 1 and k = 36 and v = 20
update biblia set nvg = 'Tak sa splnilo Pánovo slovo, ktoré povedal ústami Jeremiáša: Teraz zem dostala svoje soboty, cez celı èas spustošenia odpoèívala, a sa naplnilo sedemdesiat rokov.' where spis = '2Krn' and vers = 1 and k = 36 and v = 21
update biblia set nvg = 'V prvom roku Kıra, krá¾a Peranov, sa splnilo, èo Pán povedal ústami Jeremiáša. Pán vnukol Kırovi, krá¾ovi Peranov, a on po celom svojom krá¾ovstve nariadil vyhlási aj písomne: ' where spis = '2Krn' and vers = 1 and k = 36 and v = 22
update biblia set nvg = '"Takto hovorí Kıros, krá¾ Peranov: Pán, Boh nebies, mi dal všetky krá¾ovstvá zeme. A rozkázal mi, aby som mu postavil dom v Jeruzaleme, ktorı je v Judei. S kadım, kto patrí k jeho ¾udu, nech je Pán, jeho Boh, a nech vystúpi."' where spis = '2Krn' and vers = 1 and k = 36 and v = 23
go
