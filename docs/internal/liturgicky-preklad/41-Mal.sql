-- OCR28PIc_CIT1	1, 1-14; 2, 13-16
-- OCR28PIc_CIT1 resp. Mal 2, 5ab. 6a
-- 04DEC_cCIT2/28JUN_cCIT2/18MAR_cCIT2 resp.	Mal 2, 6
-- 17SEP_cCIT2 resp.	Mal 2, 7
-- 1167	Mal 1, 14b - 2, 2b. 8-10
update biblia set lh_id = 'OCR28PIc_CIT1' where spis = 'Mal' and vers = 1 and k = 1 and v between 1 and 14
update biblia set lh_id = 'OCR28PIc_CIT1 resp.' where spis = 'Mal' and vers = 1 and k = 2 and v = 5
update biblia set lh_id = '04DEC_cCIT2 resp.' where spis = 'Mal' and vers = 1 and k = 2 and v = 6
update biblia set lh_id = '17SEP_cCIT2 resp.' where spis = 'Mal' and vers = 1 and k = 2 and v = 7
update biblia set lh_id = 'OCR28PIc_CIT1' where spis = 'Mal' and vers = 1 and k = 2 and v between 13 and 16
go
update biblia set lc_id = 1167 where spis = 'Mal' and vers = 1 and k = 1 and v = 14
update biblia set lc_id = 1167 where spis = 'Mal' and vers = 1 and k = 2 and v between 1 and 2
update biblia set lc_id = 1167 where spis = 'Mal' and vers = 1 and k = 2 and v between 8 and 10
go

update biblia set nvg = 'Pánovo slovo Izraelu prostredníctvom Malachiáša. ' where spis = 'Mal' and vers = 1 and k = 1 and v = 1
update biblia set nvg = '„Milujem vás, hovorí Pán, a vy sa pýtate: ‚Ako nás miluješ?‘ Nebol Ezau Jakubov brat?, hovorí Pán. A Jakuba som miloval, ' where spis = 'Mal' and vers = 1 and k = 1 and v = 2
update biblia set nvg = 'kým Ezaua som nenávidel. Preto som z_jeho vrchov urobil púšť a jeho dedičstvo som dal púštnym šakalom. ' where spis = 'Mal' and vers = 1 and k = 1 and v = 3
update biblia set nvg = 'Ak Edom povie: ‚Sme zničení, ale vrátime sa a postavíme, čo bolo zbúrané,‘ Pán zástupov hovorí toto: Oni budú stavať a ja budem rúcať. A budú ich volať: ‚Bezbožné územie‘ a: ‚Ľud, na ktorý sa Pán hnevá naveky.‘ ' where spis = 'Mal' and vers = 1 and k = 1 and v = 4
update biblia set nvg = 'Vaše oči to uvidia a poviete: ‚Pán je veľký aj za hranicami Izraela.‘' where spis = 'Mal' and vers = 1 and k = 1 and v = 5
update biblia set nvg = 'Syn si ctí otca a sluha svojho pána. Ak som teda ja otec, kde je úcta ku mne? A ak som ja Pán, kde je bázeň predo mnou?, hovorí Pán zástupov vám, kňazi, ktorí znevažujete moje meno a hovoríte: ‚Čím sme znevážili tvoje meno?‘ ' where spis = 'Mal' and vers = 1 and k = 1 and v = 6
update biblia set nvg = 'Obetujete na mojom oltári poškvrnený chlieb, a hovoríte: ‚Čím sme ťa potupili?‘ Tým, že hovoríte: ‚Pánovým stolom možno opovrhnúť.‘ ' where spis = 'Mal' and vers = 1 and k = 1 and v = 7
update biblia set nvg = 'Keď prinášate slepé na obetu, to nie je zlo? A keď obetujete chromé a neduživé, to nie je zlo? Prines to svojmu vodcovi, či sa mu to bude páčiť a získaš si jeho priazeň, hovorí Pán zástupov. ' where spis = 'Mal' and vers = 1 and k = 1 and v = 8
update biblia set nvg = 'Ale teraz proste Boha, aby sa zmiloval nad vami. Lebo vaše ruky toto robili. Vari si získate jeho priazeň?, hovorí Pán zástupov. ' where spis = 'Mal' and vers = 1 and k = 1 and v = 9
update biblia set nvg = 'Kto z_vás zavrie dvere, aby ste nezapaľovali oheň na mojom oltári nadarmo? Nemám vo vás zaľúbenie, hovorí Pán zástupov, a neprijmem dar z_vašich rúk. ' where spis = 'Mal' and vers = 1 and k = 1 and v = 10
update biblia set nvg = 'Lebo od východu slnka až po západ je veľké moje meno medzi národmi a na každom mieste prinášajú môjmu menu kadidlo a čistú obetu, lebo je veľké moje meno medzi národmi, hovorí Pán zástupov. ' where spis = 'Mal' and vers = 1 and k = 1 and v = 11
update biblia set nvg = 'Ale vy ho znesväcujete tým, že hovoríte: ‚Pánov stôl je poškvrnený a pokrmom na ňom možno opovrhnúť.‘ ' where spis = 'Mal' and vers = 1 and k = 1 and v = 12
update biblia set nvg = 'Hovoríte: ‚Aká námaha!‘ a znevažujete ho, hovorí Pán zástupov. A z_lúpeže prinášate chromé a neduživé a prinášate to ako dar. Azda to mám prijať z_vašej ruky?, hovorí Pán. ' where spis = 'Mal' and vers = 1 and k = 1 and v = 13
update biblia set nvg = 'Nech je prekliaty podvodník, ktorý má vo svojom stáde samca, a sľúbil ho, ale Pánovi obetuje dengľavé. Lebo ja som veľký kráľ, hovorí Pán zástupov, a moje meno je hrozné medzi národmi.' where spis = 'Mal' and vers = 1 and k = 1 and v = 14
go

update biblia set nvg = 'Vám, kňazi, toto napomenutie: ' where spis = 'Mal' and vers = 1 and k = 2 and v = 1
update biblia set nvg = 'Ak neposlúchnete a nevezmete si k srdcu, že máte vzdať úctu môjmu menu, hovorí Pán zástupov, postihnem vás kliatbou. [...]' where spis = 'Mal' and vers = 1 and k = 2 and v = 2
go
update biblia set nvg = 'Moja zmluva s_kňazom bola život a pokoj a dal som mu to spolu s_bázňou i_bál sa ma. [...]' where spis = 'Mal' and vers = 1 and k = 2 and v = 5
update biblia set nvg = 'Zákon pravdy bol v_jeho ústach a na jeho perách sa nenašla neprávosť, v_pokoji a úprimnosti chodil so mnou [...]' where spis = 'Mal' and vers = 1 and k = 2 and v = 6
update biblia set nvg = 'Pery kňaza strážia poznanie a z_jeho úst sa vyžaduje zákon, lebo je poslom Pána zástupov.' where spis = 'Mal' and vers = 1 and k = 2 and v = 7
update biblia set nvg = 'Zišli ste z cesty a svojou náukou zviedli ste mnohých. Porušili ste moju zmluvu s Lévim, hovorí Pán zástupov. ' where spis = 'Mal' and vers = 1 and k = 2 and v = 8
update biblia set nvg = 'Preto aj ja vami opovrhnem a ponížim vás pred všetkým ľudom, lebo ste nezachovávali moje príkazy a robili ste výnimky v zákone.' where spis = 'Mal' and vers = 1 and k = 2 and v = 9
update biblia set nvg = 'Nemáme azda všetci jedného otca? Vari nás nestvoril jeden Boh? Prečo sme jeden voči druhému vierolomní a znesväcujeme zmluvu svojich otcov?!' where spis = 'Mal' and vers = 1 and k = 2 and v = 10
go
update biblia set nvg = 'A robíte aj toto: pokrývate Pánov oltár slzami, plačom a nárekom, že už nezhliadnem na obetu a neprijmem nič zmierne z_vašich rúk, ' where spis = 'Mal' and vers = 1 and k = 2 and v = 13
update biblia set nvg = 'a hovoríte: ‚Prečo?‘ Preto, že Pán je svedkom medzi tebou a ženou tvojej mladosti, ktorej si sa stal neverným, a ona je tvoja spoločnica a manželka tvojej zmluvy. ' where spis = 'Mal' and vers = 1 and k = 2 and v = 14
update biblia set nvg = 'Či nevytvoril jednotu tela a ducha? A čo iné hľadá jednota ako potomstvo od Boha? Chráňte si teda ducha; a nebuď neverný manželke svojej mladosti! ' where spis = 'Mal' and vers = 1 and k = 2 and v = 15
update biblia set nvg = 'Kto prepúšťa z_nenávisti, hovorí Pán, Boh Izraela, pokrýva svoj odev neprávosťou, hovorí Pán zástupov. Chráňte si ducha a nebuďte neverní!“' where spis = 'Mal' and vers = 1 and k = 2 and v = 16
go

-- OCR28SOc_CIT1	3, 1-24
-- 1168	Mal 3, 1-4
-- 1169	Mal 3, 1-4. 23-24
-- 1170	Mal 3, 13-20a
-- 1171	Mal 3, 19-20a
update biblia set lh_id = 'OCR28SOc_CIT1' where spis = 'Mal' and vers = 1 and k = 3 and v between 1 and 24
go
update biblia set lc_id = 1168 where spis = 'Mal' and vers = 1 and k = 3 and v between 1 and 4
update biblia set lc_id = 1170 where spis = 'Mal' and vers = 1 and k = 3 and v between 13 and 20
update biblia set lc_id = 1169 where spis = 'Mal' and vers = 1 and k = 3 and v between 23 and 24
go

update biblia set nvg = '„Hľa, ja posielam svojho anjela, aby mi pripravil cestu. Hneď potom príde do svojho chrámu Pán, ktorého hľadáte, a anjel zmluvy, po ktorom túžite. Hľa, príde, hovorí Pán zástupov. ' where spis = 'Mal' and vers = 1 and k = 3 and v = 1
update biblia set nvg = 'Kto však znesie deň jeho príchodu a kto obstojí, až sa zjaví? Veď on je ako oheň, ktorý roztápa, a ako lúh práčov. ' where spis = 'Mal' and vers = 1 and k = 3 and v = 2
update biblia set nvg = 'Sadne si a bude vytápať a čistiť striebro, očistí synov Léviho a zošľachtí ich ako zlato a striebro, takže budú prinášať Pánovi obety v_spravodlivosti. ' where spis = 'Mal' and vers = 1 and k = 3 and v = 3
update biblia set nvg = 'Vtedy sa Pánovi zapáči obeta Júdu a Jeruzalema ako v_dňoch predošlých, ako v_rokoch dávnych. ' where spis = 'Mal' and vers = 1 and k = 3 and v = 4
update biblia set nvg = 'A prídem vás súdiť. Budem rýchlym svedkom proti čarodejníkom, cudzoložníkom a krivoprísažníkom, aj proti tým, čo utláčajú nádenníkov, vdovy a siroty a krivdia cudzincom a neboja sa ma, hovorí Pán zástupov.' where spis = 'Mal' and vers = 1 and k = 3 and v = 5
update biblia set nvg = 'Lebo ja, Pán, som sa nezmenil; / ale vy, Jakubovi synovia, ešte ste neprišli na koniec.' where spis = 'Mal' and vers = 1 and k = 3 and v = 6
update biblia set nvg = 'Odo dní svojich otcov / odchyľovali ste sa od mojich spravodlivých príkazov / a nezachovávali ste ich. / Vráťte sa ku mne / a ja sa vrátim k_vám, / hovorí Pán zástupov. / Vy sa pýtate: ‚Ako sa máme vrátiť?‘ ' where spis = 'Mal' and vers = 1 and k = 3 and v = 7
update biblia set nvg = 'Smie človek podvádzať Boha? / Ale vy ma podvádzate. / A pýtate sa: ‚V_čom sme ťa dostali?‘ / V_desiatkoch a v_prvotinách.' where spis = 'Mal' and vers = 1 and k = 3 and v = 8
update biblia set nvg = 'Ste zavalení kliatbou, / lebo ma podvádzate vy, celý národ.' where spis = 'Mal' and vers = 1 and k = 3 and v = 9
update biblia set nvg = 'Prineste celý desiatok do chrámovej pokladnice, / aby bolo čo jesť v_mojom dome; / a vyskúšajte ma v_tomto, / hovorí Pán zástupov, / či vám neotvorím nebeské hrádze / a nevylejem na vás požehnanie v_nadmiere,' where spis = 'Mal' and vers = 1 and k = 3 and v = 10
update biblia set nvg = 'či sa kvôli vám neoborím na škodcov, / takže nebudú ničiť plod zeme / a nebudete mať neplodný vinič na poli, / hovorí Pán zástupov.' where spis = 'Mal' and vers = 1 and k = 3 and v = 11
update biblia set nvg = 'A blahoslaviť vás budú všetky národy, / lebo budete vytúženou krajinou, / hovorí Pán zástupov.' where spis = 'Mal' and vers = 1 and k = 3 and v = 12
update biblia set nvg = 'Silné sú vaše reči proti mne, hovorí Pán, ' where spis = 'Mal' and vers = 1 and k = 3 and v = 13
update biblia set nvg = 'a pýtate sa: ‚Čože sme povedali proti tebe?‘ Hovoríte: ‚Je zbytočné slúžiť Bohu. Čo máme z_toho, že zachovávame jeho prikázania a smutní chodíme pred Pánom zástupov? ' where spis = 'Mal' and vers = 1 and k = 3 and v = 14
update biblia set nvg = 'Preto teraz vyhlasujeme za blažených ľudí spupných, lebo sa darí tým, čo páchajú zlo; pokúšajú Boha a nič sa im nestane.‘ ' where spis = 'Mal' and vers = 1 and k = 3 and v = 15
update biblia set nvg = 'Vtedy sa rozprávali tí, čo sa boja Pána, medzi sebou a Pán si ich všimol a počul. A bola pred ním napísaná pamätná kniha pre tých, čo sa boja Pána a ctia si jeho meno. ' where spis = 'Mal' and vers = 1 and k = 3 and v = 16
update biblia set nvg = 'Oni budú v_deň, keď budem konať, mojím zvláštnym vlastníctvom, hovorí Pán zástupov, a budem k_nim láskavý ako otec k_svojmu synovi, ktorý mu slúži. ' where spis = 'Mal' and vers = 1 and k = 3 and v = 17
update biblia set nvg = 'Potom budete znova vidieť rozdiel medzi spravodlivým a bezbožným, medzi tým, čo slúži Bohu, a tým, čo mu neslúži.' where spis = 'Mal' and vers = 1 and k = 3 and v = 18
update biblia set nvg = 'Lebo hľa, blíži sa deň, ktorý planie ako pec, a všetci namyslenci a tí, čo páchajú neprávosť, budú ako plevy. Deň, ktorý prichádza, ich spáli, hovorí Pán zástupov, a nenechá z_nich ani koreň, ani výhonok. ' where spis = 'Mal' and vers = 1 and k = 3 and v = 19
update biblia set nvg = 'Ale vám, čo sa bojíte môjho mena, vyjde slnko spravodlivosti a jeho lúče prinesú zdravie. Potom vybehnete a budete poskakovať ako vykŕmené teliatka ' where spis = 'Mal' and vers = 1 and k = 3 and v = 20
update biblia set nvg = 'a budete šliapať po bezbožných, lebo budú ako popol pod chodidlami vašich nôh v_deň, ktorý ja urobím, hovorí Pán zástupov.' where spis = 'Mal' and vers = 1 and k = 3 and v = 21
update biblia set nvg = 'Pamätajte na zákon môjho služobníka Mojžiša, / ktorému som dal / na Horebe prikázania a nariadenia / pre celý Izrael.' where spis = 'Mal' and vers = 1 and k = 3 and v = 22
update biblia set nvg = 'Hľa, ja vám pošlem / proroka Eliáša, / prv, ako príde deň Pána, / veľký a hrozný.' where spis = 'Mal' and vers = 1 and k = 3 and v = 23
update biblia set nvg = 'On obráti srdcia otcov k_synom / a srdcia synov k_ich otcom, / aby som nemusel prísť / a postihnúť zem kliatbou.“' where spis = 'Mal' and vers = 1 and k = 3 and v = 24
go

