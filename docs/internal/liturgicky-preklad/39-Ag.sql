-- OCR28NEc_CIT1	1, 1 – 2, 9
-- 302	Ag 1, 1-8
-- 303	Ag 1, 15b - 2, 9
-- OCR28POc_CIT1	2, 10-23
update biblia set lh_id = 'OCR28NEc_CIT1' where spis = 'Ag' and vers = 1 and k = 1 and v between 1 and 15
update biblia set lh_id = 'OCR28NEc_CIT1' where spis = 'Ag' and vers = 1 and k = 2 and v between 1 and 9
update biblia set lh_id = 'OCR28POc_CIT1' where spis = 'Ag' and vers = 1 and k = 2 and v between 10 and 23
go
update biblia set lc_id = 302 where spis = 'Ag' and vers = 1 and k = 1 and v between 1 and 8
update biblia set lc_id = 303 where spis = 'Ag' and vers = 1 and k = 1 and v = 15
update biblia set lc_id = 303 where spis = 'Ag' and vers = 1 and k = 2 and v between 1 and 9
go

update biblia set nvg = 'V_druhom roku kráľa Dária, v_šiestom mesiaci v_prvý deň mesiaca, zaznelo Pánovo slovo prostredníctvom proroka Aggea judejskému miestodržiteľovi Zorobábelovi, Salatielovmu synovi, a veľkňazovi Jozuemu, Jozedekovmu synovi: ' where spis = 'Ag' and vers = 1 and k = 1 and v = 1
update biblia set nvg = '„Toto hovorí Pán zástupov: Tento ľud vraví: ‚Ešte neprišiel čas stavať Pánov dom.‘“ ' where spis = 'Ag' and vers = 1 and k = 1 and v = 2
update biblia set nvg = 'Ale Pán prehovoril prostredníctvom proroka Aggea: ' where spis = 'Ag' and vers = 1 and k = 1 and v = 3
update biblia set nvg = '„Vám už prišiel čas bývať vo vykladaných domoch, a tento dom bude pustý? ' where spis = 'Ag' and vers = 1 and k = 1 and v = 4
update biblia set nvg = 'Preto teraz hovorí Pán zástupov: Dobre sa pozrite, až kam ste prišli! ' where spis = 'Ag' and vers = 1 and k = 1 and v = 5
update biblia set nvg = 'Veľa ste siali, zvážate málo; jedli ste, a nenasýtili ste sa; pili ste, a neopojili ste sa; obliekali ste sa, ale teplo vám nebolo; a kto pracoval za mzdu, dával ju do deravého vrecka. ' where spis = 'Ag' and vers = 1 and k = 1 and v = 6
update biblia set nvg = 'Toto hovorí Pán zástupov: Dobre sa pozrite, až kam ste prišli! ' where spis = 'Ag' and vers = 1 and k = 1 and v = 7
update biblia set nvg = 'Choďte do hory, dovezte drevo a stavajte dom, v_ktorom budem mať záľubu a slávu, hovorí Pán. ' where spis = 'Ag' and vers = 1 and k = 1 and v = 8
update biblia set nvg = 'Vyhliadli ste si veľa, a je toho málo; a keď ste to priniesli domov, ja som to rozfúkol. Prečo?, hovorí Pán zástupov. Preto, že môj dom je pustý, a vy sa náhlite každý do svojho domu. ' where spis = 'Ag' and vers = 1 and k = 1 and v = 9
update biblia set nvg = 'Preto sa nad vami zatvorilo nebo a nedáva rosu a zem sa zavrela, nevydáva svoju úrodu. ' where spis = 'Ag' and vers = 1 and k = 1 and v = 10
update biblia set nvg = 'Zvolal som sucho na zem, na vrchy, na obilie, na víno, na olej a na všetko, čo vydáva zem, i_na ľudí, na dobytok a na všetku prácu rúk.“' where spis = 'Ag' and vers = 1 and k = 1 and v = 11
update biblia set nvg = 'Zorobábel, Salatielov syn, veľkňaz Jozue, Jozedekov syn, a všetky zvyšky ľudu poslúchli hlas Pána, svojho Boha, a slová proroka Aggea, ako ho k_nim poslal Pán, ich Boh; a ľud sa bál Pána.' where spis = 'Ag' and vers = 1 and k = 1 and v = 12
update biblia set nvg = 'Tu Pánov posol Aggeus povedal z_Pánovho poverenia ľudu: „Ja som s_vami, hovorí Pán.“ ' where spis = 'Ag' and vers = 1 and k = 1 and v = 13
update biblia set nvg = 'A Pán prebudil ducha judejského miestodržiteľa Zorobábela, Salatielovo syna, a ducha veľkňaza Jozueho, Jozedekovho syna, i_ducha všetkých zvyškov ľudu a išli a dali sa do práce na dome Pána zástupov, svojho Boha, ' where spis = 'Ag' and vers = 1 and k = 1 and v = 14
update biblia set nvg = 'v_dvadsiaty štvrtý deň mesiaca v_šiestom mesiaci, v_druhom roku kráľa Dária.' where spis = 'Ag' and vers = 1 and k = 1 and v = 15
go
update biblia set nvg = 'V_siedmom mesiaci, v_dvadsiaty prvý deň mesiaca zaznelo Pánovo slovo prostredníctvom proroka Aggea: ' where spis = 'Ag' and vers = 1 and k = 2 and v = 1
update biblia set nvg = '„Povedz judejskému miestodržiteľovi Zorobábelovi, Salatielovmu synovi, veľkňazovi Jozuemu, Jozedekovmu synovi, a zvyškom ľudu toto: ' where spis = 'Ag' and vers = 1 and k = 2 and v = 2
update biblia set nvg = 'Kto ešte ostal medzi vami, čo videl tento dom v_jeho prvej sláve? A ako naň hľadíte teraz? Nezdá sa vám, akoby bol ničím? ' where spis = 'Ag' and vers = 1 and k = 2 and v = 3
update biblia set nvg = 'Ale teraz sa vzchop, Zorobábel, hovorí Pán, vzchop sa, veľkňaz Jozue, Jozedekov syn, vzchop sa, všetok ľud krajiny, hovorí Pán zástupov, a pracujte, lebo ja som s_vami, hovorí Pán zástupov. ' where spis = 'Ag' and vers = 1 and k = 2 and v = 4
update biblia set nvg = 'Slovo, ktoré som vám dal, keď ste vychádzali z_egyptskej krajiny, i môj duch ostanú medzi vami; nebojte sa! ' where spis = 'Ag' and vers = 1 and k = 2 and v = 5
update biblia set nvg = 'Lebo toto hovorí Pán zástupov: Ešte chvíľku a ja pohnem nebesia i_zem, more i_súš. ' where spis = 'Ag' and vers = 1 and k = 2 and v = 6
update biblia set nvg = 'Pohnem všetky národy; prídu skvosty všetkých národov a naplním tento dom slávou, hovorí Pán zástupov. ' where spis = 'Ag' and vers = 1 and k = 2 and v = 7
update biblia set nvg = 'Moje je striebro a moje je zlato, hovorí Pán zástupov. ' where spis = 'Ag' and vers = 1 and k = 2 and v = 8
update biblia set nvg = 'Budúca sláva tohto domu bude väčšia ako sláva toho prvého, hovorí Pán zástupov; a na tomto mieste nastolím pokoj,“ hovorí Pán zástupov.' where spis = 'Ag' and vers = 1 and k = 2 and v = 9
update biblia set nvg = 'V_dvadsiaty štvrtý deň deviateho mesiaca, v_druhom roku Dária, zaznelo Pánovo slovo prorokovi Aggeovi: ' where spis = 'Ag' and vers = 1 and k = 2 and v = 10
update biblia set nvg = '„Toto hovorí Pán zástupov: Opýtaj sa kňazov na zákon: ' where spis = 'Ag' and vers = 1 and k = 2 and v = 11
update biblia set nvg = 'Keby niekto niesol v_rožku svojho odevu posvätené mäso a dotkol by sa jeho okrajom chleba, váry, vína, oleja alebo akéhokoľvek iného pokrmu, posvätil by sa?“ Kňazi odpovedali: „Nie.“ ' where spis = 'Ag' and vers = 1 and k = 2 and v = 12
update biblia set nvg = 'Potom Aggeus povedal: „Ak sa tohto všetkého dotkneš poškvrnený mŕtvolou, poškvrní sa to?“ A kňazi odpovedali: „Poškvrní.“ ' where spis = 'Ag' and vers = 1 and k = 2 and v = 13
update biblia set nvg = 'Aggeus povedal: „Tak aj tento ľud a tak aj tento národ pred mojou tvárou, hovorí Pán, a tak aj každé dielo ich rúk a všetko, čo tam obetujú, je poškvrnené.' where spis = 'Ag' and vers = 1 and k = 2 and v = 14
update biblia set nvg = 'A teraz sa dobre pozrite od tohto dňa späť: Čím ste boli predtým, ako bol položený kameň na kameň v_Pánovom chráme? ' where spis = 'Ag' and vers = 1 and k = 2 and v = 15
update biblia set nvg = 'Keď ste prichádzali ku kope, kde malo byť dvadsať meríc, a bolo desať, a keď ste prišli k_lisu nabrať päťdesiat krčahov, a bolo len dvadsať. ' where spis = 'Ag' and vers = 1 and k = 2 and v = 16
update biblia set nvg = 'Bil som vás i_všetky diela vašich rúk suchom, sneťou a krupobitím, ale nik z_vás sa neobrátil ku mne, hovorí Pán. ' where spis = 'Ag' and vers = 1 and k = 2 and v = 17
update biblia set nvg = 'A dobre sa pozrite od toho dňa do budúcna, od dvadsiateho štvrtého dňa deviateho mesiaca, odo dňa, keď boli položené základy Pánovho chrámu, dobre sa pozrite! ' where spis = 'Ag' and vers = 1 and k = 2 and v = 18
update biblia set nvg = 'Vari je ešte semeno v_sýpke a vinica, figovník, granátovník a oliva nepriniesli ešte ovocie? Od tohto dňa požehnám.“' where spis = 'Ag' and vers = 1 and k = 2 and v = 19
update biblia set nvg = 'A Pánovo slovo zaznelo Aggeovi aj druhý raz v_dvadsiaty štvrtý deň mesiaca: ' where spis = 'Ag' and vers = 1 and k = 2 and v = 20
update biblia set nvg = '„Povedz judejskému miestodržiteľovi Zorobábelovi: Ja pohnem nebom i_zemou, ' where spis = 'Ag' and vers = 1 and k = 2 and v = 21
update biblia set nvg = 'zrútim kráľovské tróny, rozdrvím silu pohanských kráľovstiev a poprevraciam bojové vozy aj ich jazdcov; popadajú kone aj ich jazdci, každý prebodnutý mečom svojho brata. ' where spis = 'Ag' and vers = 1 and k = 2 and v = 22
update biblia set nvg = 'V_ten deň, hovorí Pán zástupov, vezmem ťa, môj služobník, Salatielov syn Zorobábel, hovorí Pán, urobím ťa pečatným prsteňom, lebo som si ťa vyvolil,“ hovorí Pán zástupov.' where spis = 'Ag' and vers = 1 and k = 2 and v = 23
go

