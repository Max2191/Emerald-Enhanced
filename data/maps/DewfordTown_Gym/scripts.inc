DewfordTown_Gym_MapScripts:: @ 81FC63C
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition: @ 81FC642
	call DewfordTown_Gym_EventScript_SetFlashRadius
	end

DewfordTown_Gym_EventScript_SetFlashRadius:: @ 81FC648
	checktrainerflag TRAINER_BRAWLY_1
	goto_if_eq DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	compare VAR_0x8000, 0
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius7
	compare VAR_0x8000, 1
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius6
	compare VAR_0x8000, 2
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius5
	compare VAR_0x8000, 3
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius4
	compare VAR_0x8000, 4
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius3
	compare VAR_0x8000, 5
	goto_if_eq DewfordTown_Gym_EventScript_SetFlashRadius2
	goto DewfordTown_Gym_EventScript_SetFlashRadius1

DewfordTown_Gym_EventScript_SetLightsOn:: @ 81FC6A2
	setflashradius 0
	return

DewfordTown_Gym_EventScript_SetFlashRadius1:: @ 81FC6A6
	setflashradius 1
	return

DewfordTown_Gym_EventScript_SetFlashRadius2:: @ 81FC6AA
	setflashradius 2
	return

DewfordTown_Gym_EventScript_SetFlashRadius3:: @ 81FC6AE
	setflashradius 3
	return

DewfordTown_Gym_EventScript_SetFlashRadius4:: @ 81FC6B2
	setflashradius 4
	return

DewfordTown_Gym_EventScript_SetFlashRadius5:: @ 81FC6B6
	setflashradius 5
	return

DewfordTown_Gym_EventScript_SetFlashRadius6:: @ 81FC6BA
	setflashradius 6
	return

DewfordTown_Gym_EventScript_SetFlashRadius7:: @ 81FC6BE
	setflashradius 7
	return

DewfordTown_Gym_EventScript_BrightenRoom:: @ 81FC6C2
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	compare VAR_0x8000, VAR_0x8001
	goto_if_eq DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	compare VAR_0x8000, 1
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	compare VAR_0x8000, 2
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	compare VAR_0x8000, 3
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	compare VAR_0x8000, 4
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	compare VAR_0x8000, 5
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	compare VAR_0x8000, 6
	goto_if_eq DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange:: @ 81FC71A
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer:: @ 81FC71B
	playse SE_MU_PACHI
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers:: @ 81FC726
	playse SE_MU_PACHI
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers:: @ 81FC731
	playse SE_MU_PACHI
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers:: @ 81FC73C
	playse SE_MU_PACHI
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers:: @ 81FC747
	playse SE_MU_PACHI
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers:: @ 81FC752
	playse SE_MU_PACHI
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness:: @ 81FC75D
	playse SE_MU_PACHI
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashRadius
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated:: @ 81FC768
	setvar VAR_0x8000, 0
	checktrainerflag TRAINER_TAKAO
	goto_if_lt DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn:: @ 81FC77B
	checktrainerflag TRAINER_JOCELYN
	goto_if_lt DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura:: @ 81FC789
	checktrainerflag TRAINER_LAURA
	goto_if_lt DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden:: @ 81FC797
	checktrainerflag TRAINER_BRENDEN
	goto_if_lt DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian:: @ 81FC7A5
	checktrainerflag TRAINER_CRISTIAN
	goto_if_lt DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith:: @ 81FC7B3
	checktrainerflag TRAINER_LILITH
	goto_if_lt DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers:: @ 81FC7C1
	return

DewfordTown_Gym_EventScript_Brawly:: @ 81FC7C2
	lock
	faceplayer
	setflag FLAG_RYU_ALTERNATE_SCALE
	special checkbadgecount
	switch VAR_RESULT
	case 0, brawly1
	case 1, brawly1
	case 2, brawly1
	case 3, brawly2
	case 4, brawly2
	case 5, brawly3
	case 6, brawly3
	case 7, brawly4
	case 8, brawly4

DFG_Reset::
	setvar VAR_TEMP_8, 2
	special checkbadgecount
	compare VAR_RESULT, 8
	call_if_eq RyuTier8GymMegaStoneReward
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle
	closemessage
	cleartrainerflag TRAINER_BRAWLY_1
	cleartrainerflag TRAINER_BRAWLY_2
	cleartrainerflag TRAINER_BRAWLY_3
	cleartrainerflag TRAINER_BRAWLY_4
	clearflag FLAG_RYU_ALTERNATE_SCALE
	goto_if_set FLAG_RYU_HARDCORE_MODE, RyuScripts_HardcoreGymReward
	call_if_set FLAG_RYU_NUZLOCKEMODE, RyuHealedGym
	call_if_unset FLAG_RYU_GYM2HANDOUT, RyuGymItemReward2
	release
	end

brawly1::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreBattle, DewfordTown_Gym_Text_BrawlyDefeat, DFG_Reset
	release
	end

brawly2::
	trainerbattle_single TRAINER_BRAWLY_2, DewfordTown_Gym_Text_BrawlyPreBattle, DewfordTown_Gym_Text_BrawlyDefeat, DFG_Reset
	release
	end

brawly3::
	trainerbattle_single TRAINER_BRAWLY_3, DewfordTown_Gym_Text_BrawlyPreBattle, DewfordTown_Gym_Text_BrawlyDefeat, DFG_Reset
	release
	end

brawly4::
	goto_if_set FLAG_RYU_DS_HAS_PARTNER, DFG_PartnerQuery
	trainerbattle_single TRAINER_BRAWLY_4, DewfordTown_Gym_Text_BrawlyPreBattle, DewfordTown_Gym_Text_BrawlyDefeat, DFG_Reset
	release
	end

DFG_PartnerQuery::
    msgbox RyuPartnerMultiText MSGBOX_YESNO
	compare VAR_RESULT 1
	goto_if_eq DFG_RelDialog
	goto DFG_NoRelGymBattle
	return
	
	
DFG_RelDialog::
	call RyuParterBattleMultichoice
	compare VAR_0x8006, TRAINER_REL_SHELLY
	goto_if_eq DFG_GymBattleIntroShelly
	compare VAR_0x8006, TRAINER_REL_DAWN
	goto_if_eq DFG_GymBattleIntroDawn
	compare VAR_0x8006, TRAINER_REL_BRENDAN
	goto_if_eq DFG_GymBattleIntroBrendan
	compare VAR_0x8006, TRAINER_REL_LANA
	goto_if_eq DFG_GymBattleIntroLana
	compare VAR_0x8006, TRAINER_REL_LANETTE
	goto_if_eq DFG_GymBattleIntroLanette
	goto DFG_NoRelGymBattle
	
DFG_NoRelGymBattle::
	trainerbattle_single TRAINER_BRAWLY_4, DewfordTown_Gym_Text_BrawlyPreBattle, DewfordTown_Gym_Text_BrawlyPreBattle, DFG_Reset
	release
	end
	
DFG_NoRelationship1::
	msgbox Ryu_NOREL MSGBOX_DEFAULT
	closemessage
	goto DFG_RelDialog
	
DFG_GymBattleIntroShelly::
	msgbox Ryu_PlayerCalledShelly MSGBOX_DEFAULT
	closemessage
	delay 30
	goto_if_unset FLAG_RYU_DS_SHELLY_PARTNERS, DFG_NoRelationship1
	addobject 11
	playse SE_DOOR
	applymovement 11, DFG_PartnerEnter
	waitmovement 0
	msgbox DFG_SHELLY_INTRO MSGBOX_DEFAULT
	goto DFG_AltGymBattle

DFG_GymBattleIntroLana::
	msgbox Ryu_PlayerCalledLana MSGBOX_DEFAULT
	closemessage
	delay 30
	goto_if_unset FLAG_RYU_DS_LEAF_PARTNERS, DFG_NoRelationship1
	addobject 12
	playse SE_DOOR
	applymovement 12, DFG_PartnerEnter
	waitmovement 12
	msgbox DFG_LANA_INTRO MSGBOX_DEFAULT
	goto DFG_AltGymBattle
	
DFG_GymBattleIntroDawn::
	goto_if_unset FLAG_RYU_DS_DAWN_PARTNERS, DFG_NoRelationship1
	msgbox Ryu_PlayerCalledDawn MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 9
	playse SE_DOOR
	applymovement 9, DFG_PartnerEnter
	waitmovement 0
	msgbox DFG_DAWN_INTRO MSGBOX_DEFAULT
	goto DFG_AltGymBattle
	
DFG_GymBattleIntroBrendan::
	goto_if_unset FLAG_RYU_DS_BRENDAN_PARTNERS, DFG_NoRelationship1
	msgbox Ryu_PlayerCalledBrendan MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 10
	playse SE_DOOR
	applymovement 10, DFG_PartnerEnter
	waitmovement 0
	msgbox DFG_BRENDAN_INTRO MSGBOX_DEFAULT
	goto DFG_AltGymBattle
	
DFG_GymBattleIntroLanette::
	goto_if_unset FLAG_RYU_DS_LANETTE_PARTNERS, DFG_NoRelationship1
	msgbox Ryu_PlayerCalledLanette MSGBOX_DEFAULT
	closemessage
	delay 30
	addobject 13
	playse SE_DOOR
	applymovement 13, DFG_PartnerEnter
	waitmovement 0
	msgbox DFG_LANETTE_INTRO MSGBOX_DEFAULT
	goto DFG_AltGymBattle
	
DFG_AltGymBattle::
	msgbox DFG_PreBattleText MSGBOX_DEFAULT
	special SavePlayerParty
	trainerbattle 10 TRAINER_BRAWLY_4, 0, NULL, DFG_DefeatText
	setvar VAR_0x8004, SPECIAL_BATTLE_MULTI
	setvar VAR_0x8005, 4|2
	special DoSpecialTrainerBattle
	waitstate
	special LoadPlayerParty
	delay 10
	goto DFG_GymBattleEnd
	
	
DFG_GymBattleEnd::
	compare VAR_0x8006, TRAINER_REL_DAWN
	goto_if_eq DFG_GymBattleEndDawn
	compare VAR_0x8006, TRAINER_REL_SHELLY
	goto_if_eq DFG_GymBattleEndShelly
	compare VAR_0x8006, TRAINER_REL_BRENDAN
	goto_if_eq DFG_GymBattleEndBrendan
	compare VAR_0x8006, TRAINER_REL_LANA
	goto_if_eq DFG_GymBattleEndLana
	compare VAR_0x8006, TRAINER_REL_LANETTE
	goto_if_eq DFG_GymBattleEndLanette
	release
	end
	
DFG_GymBattleEndShelly::
	msgbox DFG_ShellyGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 11, DFG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 11
	release
	end
	
DFG_GymBattleEndDawn::
	msgbox DFG_DawnGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 9, DFG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 9
	release
	end
	
DFG_GymBattleEndBrendan::
	msgbox DFG_BrendanGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 10, DFG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 10
	release
	end

DFG_GymBattleEndLana:
	msgbox DFG_LanaGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 12, DFG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 12
	release
	end
	
DFG_GymBattleEndLanette:
	msgbox DFG_LanetteGymBattleComplete MSGBOX_DEFAULT
	closemessage
	applymovement 13, DFG_PartnerExit
	waitmovement 0
	playse SE_DOOR
	removeobject 13
	release
	end
	
DFG_SHELLY_INTRO:
	.string "Shelly: {COLOR LIGHT_RED}{SHADOW RED}Ah, yes, a good ol'\nfashioned brawl. I used to fight\lAqua grunts for fun all the time!$"

DFG_DAWN_INTRO:
	.string "Dawn: {PLAYER}{COLOR LIGHT_RED}{SHADOW RED}! I'm glad you called, I was\n"
	.string "getting bored, anyways. I'm here to back\l"
	.string "you up, like always!$"
	
DFG_BRENDAN_INTRO:
	.string "Brendan: {COLOR LIGHT_BLUE}{SHADOW BLUE}Now this is definetly\n"
    .string "more my style. Let's have at it!$"

DFG_LANA_INTRO:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Lana: My Heracross oughta make quick\nwork of this guy...$"
	
DFG_LANETTE_INTRO:
	.string "Lanette:{COLOR LIGHT_RED}{SHADOW RED} I pride myself on my\nabilty to outsmart brawny types.$"
	
DFG_PreBattleText:
	.string "Brawly: Here at Dewford Gym, we\n"
    .string "pride ourselves on our physical\l"
    .string "prowess.\p"
    .string "Will you ride the waves like a pro,\n"
    .string "or get washed away like seaweed?$"
	
DFG_DefeatText:
	.string "You guys fit right in here!\n" 
	.string "Hit the waves with me any time!$"
	
DFG_ShellyGymBattleComplete:
	.string "Shelly:{COLOR LIGHT_RED}{SHADOW RED} That really takes me back\n"
    .string "to my grunt days. A nice workout!\l"
    .string "Call me if you want backup again!$"

DFG_DawnGymBattleComplete:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Dawn:{COLOR DARK_GREY}{SHADOW LIGHT_GREY} Thanks for the fun! Call me\n"
	.string "if you ever want help again!$"
	
DFG_BrendanGymBattleComplete:
	.string "Brendan:{COLOR LIGHT_BLUE}{SHADOW BLUE} Ah, that's better. Worked"
    .string "out all my aggression. Let's do it"
    .string "again sometime!$"

DFG_LanaGymBattleComplete:
    .string "Lana:{COLOR LIGHT_RED}{SHADOW RED} I do enjoy a nice workout\n"
    .string "once in a while...\p"
    .string "But now I'm all hot and bothered...$"
	
DFG_LanetteGymBattleComplete:
    .string "Lanette:{COLOR LIGHT_RED}{SHADOW RED} As expected, brawn can't\nbeat brains!$"
	
DFG_PartnerEnter:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_up
	walk_up
	walk_in_place_up
	step_end

DFG_PartnerExit:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

DewfordTown_Gym_EventScript_BrawlyDefeated:: @ 81FC7F7
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	compare VAR_PETALBURG_GYM_STATE, 6
	call_if_eq Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp:: @ 81FC855
	additem ITEM_TM08
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM08
	return

DewfordTown_Gym_EventScript_GiveBulkUp2: @ 81FC878
	additem ITEM_TM08
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM08
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch:: @ 81FC89C
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao:: @ 81FC8B7
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoPreBattle, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom:: @ 81FC8D2
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn:: @ 81FC8D9
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynPreBattle, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom:: @ 81FC8F4
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura:: @ 81FC8FB
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraPreBattle, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom:: @ 81FC916
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden:: @ 81FC91D
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenPreBattle, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom:: @ 81FC938
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian:: @ 81FC93F
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianPreBattle, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom:: @ 81FC95A
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith:: @ 81FC961
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithPreBattle, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom:: @ 81FC97C
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide:: @ 81FC983
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory:: @ 81FC998
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue:: @ 81FC9A2
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue:: @ 81FC9B2
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified:: @ 81FC9C2
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue:: @ 81FC9CC
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice: @ 81FC9D6
	.string "Hey, how's it going, Champion-\n"
	.string "bound {PLAYER}?\p"
	.string "DEWFORD's Gym Leader Brawly commands\n"
	.string "FIGHTING-type Pokémon.\p"
	.string "Going against him with NORMAL-type\n"
	.string "Pokémon is asking for trouble.\p"
	.string "FIGHTING Pokémon will lay a serious\n"
	.string "smack down on NORMAL Pokémon,\l"
	.string "so be careful!\p"
	.string "What's worse, the Gym is as dark as\n"
	.string "the ocean floor.\p"
	.string "But it will get brighter after defeating\n"
	.string "the Trainers in your way.\p"
	.string "Hey, okay, go for it!$"

DewfordTown_Gym_Text_GymGuidePostVictory: @ 81FCB5C
	.string "Whoah! It's turned too bright in here!\p"
	.string "Your future is bright, too!$"

DewfordTown_Gym_Text_TakaoPreBattle: @ 81FCB9F
	.string "Might is right!\n"
	.string "Come on!$"

DewfordTown_Gym_Text_TakaoDefeat: @ 81FCBB8
	.string "Not enough power…$"

DewfordTown_Gym_Text_TakaoPostBattle: @ 81FCBCA
	.string "Your skill overcame my strength!\n"
	.string "Your technique is commendable!$"

DewfordTown_Gym_Text_JocelynPreBattle: @ 81FCC0A
	.string "There's no need for Brawly to be\n"
	.string "involved!\p"
	.string "I'll crush you!$"

DewfordTown_Gym_Text_JocelynDefeat: @ 81FCC45
	.string "But… How?\n"
	.string "How could I lose so easily?$"

DewfordTown_Gym_Text_JocelynPostBattle: @ 81FCC6B
	.string "I'm not going to waste this loss.\n"
	.string "I'll use it to motivate me to train!\p"
	.string "One day I'll become a Gym Leader…\p"
	.string "No, I'll become the Pokémon League\n"
	.string "Champion!$"

DewfordTown_Gym_Text_LauraPreBattle: @ 81FCD01
	.string "Don't you dare brush me off!\n"
	.string "It's not my fault if you cry!$"

DewfordTown_Gym_Text_LauraDefeat: @ 81FCD3C
	.string "Waaaaaaah!\n"
	.string "I lost!$"

DewfordTown_Gym_Text_LauraPostBattle: @ 81FCD4F
	.string "I battle in the dark to make my heart\n"
	.string "stronger.\p"
	.string "But because it's so dark, I can never\n"
	.string "see Brawly's face…$"

DewfordTown_Gym_Text_LilithPreBattle: @ 81FCDB8
	.string "Ufufu…\n"
	.string "Are you stumbling around in the dark?$"

DewfordTown_Gym_Text_LilithDefeat: @ 81FCDE5
	.string "Oh, you…\n"
	.string "I don't want to know you!$"

DewfordTown_Gym_Text_LilithPostBattle: @ 81FCE08
	.string "You deserve to stay lost and end up\n"
	.string "back at the entrance again!$"

DewfordTown_Gym_Text_BrendenPreBattle: @ 81FCE48
	.string "I'll show you the gumption of\n"
	.string "a sailing man!$"

DewfordTown_Gym_Text_BrendenDefeat: @ 81FCE75
	.string "How'd this happen?\n"
	.string "It's not like me to lose this way!$"

DewfordTown_Gym_Text_BrendenPostBattle: @ 81FCEAB
	.string "Oh, aye! You're worthy of seeing\n"
	.string "our Gym Leader.$"

DewfordTown_Gym_Text_CristianPreBattle: @ 81FCEDC
	.string "If you mean to pass, it has to be\n"
	.string "through me!$"

DewfordTown_Gym_Text_CristianDefeat: @ 81FCF0A
	.string "Grrrrr!\n"
	.string "Vastly overpowered!$"

DewfordTown_Gym_Text_CristianPostBattle: @ 81FCF26
	.string "You win!\n"
	.string "Go after that badge!$"

DewfordTown_Gym_Text_BrawlyPreBattle: @ 81FCF44
	.string "I'm Brawly!\n"
	.string "DEWFORD's Gym Leader!\p"
	.string "I've been churned in the rough waves\n"
	.string "of these parts, and I've grown tough\l"
	.string "in the pitch-black cave!\p"
	.string "So you wanted to challenge me?\n"
	.string "Let me see what you're made of!$"

DewfordTown_Gym_Text_BrawlyDefeat: @ 81FD008
	.string "Whoah, wow! You made a much bigger\n"
	.string "splash than I expected!\p"
	.string "You swamped me!\p"
	.string "Okay, you've got me.\n"
	.string "Take this Gym Badge!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge: @ 81FD07D
	.string "{PLAYER} received the KNUCKLE badge\n"
	.string "from Brawly.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis: @ 81FD0A8
	.string "The KNUCKLE badge makes all Pokémon\n"
	.string "up to Level 30, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "And, you'll be able to use the HM move\n"
	.string "FLASH outside of battle.\p"
	.string "If you'd like, use this TECHNICAL\n"
	.string "MACHINE, too.$"

DewfordTown_Gym_Text_ExplainBulkUp: @ 81FD181
	.string "That TM08 contains BULK UP.\p"
	.string "It's a move that raises both ATTACK\n"
	.string "and DEFENSE stats.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly: @ 81FD1E0
	.string "Registered Gym Leader Brawly\n"
	.string "in the Pokénav.$"

DewfordTown_Gym_Text_BrawlyPostBattle: @ 81FD20D
	.string "I can see your talent becoming a giant\n"
	.string "wave to cause a storm of astonishment\l"
	.string "among Trainers one day!$"

DewfordTown_Gym_Text_GymStatue: @ 81FD272
	.string "DEWFORD TOWN Pokémon Gym$"

DewfordTown_Gym_Text_GymStatueCertified: @ 81FD28B
	.string "DEWFORD TOWN Pokémon Gym\p"
	.string "Brawly's Certified Trainers:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch: @ 81FD2C4
	.string "Brawly: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Show me how much higher\n"
	.string "you've gone!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat: @ 81FD367
	.string "Wow!\n"
	.string "Swamped again!$"

DewfordTown_Gym_Text_BrawlyPostRematch: @ 81FD37B
	.string "Brawly: Battling is vast and it's deep.\n"
	.string "You can't see the bottom.\l"
	.string "It's just like the sea of Hoenn!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons: @ 81FD3DE
	.string "Brawly: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Oh? You only have one Pokémon\n"
	.string "that can battle.\p"
	.string "I'm sorry, but I'd like you to come back\n"
	.string "with at least two Pokémon.$"
