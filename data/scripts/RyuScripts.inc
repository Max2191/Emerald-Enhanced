@@Custom Scripts


@@=================================================================================================EXP BATTERY

RyuExpBattery::
	lock
	special RyuDevCheck
	compare VAR_RESULT, 69
	goto_if_eq RyuExpBatteryDevMode
	goto RyuExpBatteryContd
	
RyuExpBatteryContd::
	buffernumberstring 0, VAR_RYU_EXP_BATTERY
	msgbox RyuExpBatteryStored MSGBOX_DEFAULT
	closemessage
	msgbox RyuExpBatteryUseOnPokemon MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne RS_CancelPartySlot
	goto RS_SelectSlot

RyuExpBatteryDevModeMsg::
	.string "You have Dev Mode active.\nWould you like to max out EXP Drive?$"

RyuExpBatteryDevMode::
	msgbox RyuExpBatteryDevModeMsg MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq RyuExpBatteryContd
	setvar VAR_RYU_EXP_BATTERY, 65000
	goto RyuExpBatteryContd

RS_SelectSlot::
	multichoicedefault 0, 0, 118, 0, 0
	switch VAR_RESULT
	case 0, RS_Slot1Selected
	case 1, RS_Slot2Selected
	case 2, RS_Slot3Selected
	case 3, RS_Slot4Selected
	case 4, RS_Slot5Selected
	case 5, RS_Slot6Selected
	case 127, RS_CancelPartySlot
	releaseall
	end

RS_DoExpBatteryDrain::
	special RyuGiveExpUnloadBattery
	bufferpartymonnick 1, VAR_TEMP_F
	setvar VAR_RYU_EXP_BATTERY, 1
	msgbox RyuExpBatterySuccess MSGBOX_DEFAULT
	release
	end

RyuExpBatteryStored:
	.string "You have {STR_VAR_1} Exp. Points stored.$"

RyuExpBatteryUseOnPokemon:
	.string "Would you like to give {STR_VAR_1}\nExp Points to a Pokémon?$"

RyuExpBatterySuccess:
	.string "Success! {STR_VAR_1} Exp. Points\nwere given to {STR_VAR_2}!$"
	
RS_Slot1Selected::
	setvar VAR_TEMP_F, 0
	goto RS_DoExpBatteryDrain
	
RS_Slot2Selected::
	getpartysize
	compare VAR_RESULT, 2
	goto_if_lt RS_SlotSelectEmpty
	setvar VAR_TEMP_F, 1
	goto RS_DoExpBatteryDrain
	
RS_Slot3Selected::
	getpartysize
	compare VAR_RESULT, 3
	goto_if_lt RS_SlotSelectEmpty
	setvar VAR_TEMP_F, 2
	goto RS_DoExpBatteryDrain
	
RS_Slot4Selected::
	getpartysize
	compare VAR_RESULT, 4
	goto_if_lt RS_SlotSelectEmpty
	setvar VAR_TEMP_F, 3
	goto RS_DoExpBatteryDrain
	
RS_Slot5Selected::
	getpartysize
	compare VAR_RESULT, 5
	goto_if_lt RS_SlotSelectEmpty
	setvar VAR_TEMP_F, 4
	goto RS_DoExpBatteryDrain
	
RS_Slot6Selected::
	getpartysize
	compare VAR_RESULT, 6
	goto_if_lt RS_SlotSelectEmpty
	setvar VAR_TEMP_F, 5
	goto RS_DoExpBatteryDrain
	
RS_SlotSelectEmpty::
	msgbox RS_SelectAnotherSlot MSGBOX_DEFAULT
	goto RS_SelectSlot

RS_SelectAnotherSlot:
	.string "You must select an occupied\nparty slot!$"

RS_CancelPartySlot::
	msgbox RS_CancelledMsg MSGBOX_DEFAULT
	closemessage
	msgbox RS_DisableEarnedEXPMsg MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RS_DisableExpGaining
	msgbox RS_ExpWillStillBeEarned
	clearflag FLAG_RYU_EXP_DRIVE_DISABLE_EARNING
	releaseall
	end

RS_DisableExpGaining::
	setflag FLAG_RYU_EXP_DRIVE_DISABLE_EARNING
	msgbox RS_ExpEarningDisabled
	closemessage
	releaseall
	end

RS_CancelledMsg:
	.string "The exp in the Drive has been\npreserved.$"

RS_DisableEarnedEXPMsg:
	.string "Would you like to disable earning\nEXP in battle?$"

RS_ExpEarningDisabled:
	.string "Experience gain in battle is now\ndisabled.\pThe Drive will continue to collect\nEXP.$"

RS_ExpWillStillBeEarned:
	.string "Battle EXP will still be earned.$"




@==================================================================================================Beta Menu

RyuDebugBetaMenuScript::
	setflag FLAG_RYU_BETA_MENU_USED
	msgbox BetaMenuIntro MSGBOX_DEFAULT
	closemessage
	multichoicedefault 30, 0, 133, 7, 0
	switch VAR_RESULT
	case 0, RDBM_ResetDevon
	case 1, RDBM_Magma
	case 2, RDBM_ResetAqua
	case 3, RDBM_ResetLeaf
	case 4, RDBM_ResetRival
	case 5, RDBM_ResetBadges
	case 6, RDBM_TeleportHome
	case 7, RDBM_ExitResetMenu
	case 127, RDBM_ExitResetMenu
	release
	end

BetaMenuIntro:
	.string "You really shouldn't mess with these\noptions unless you were directed\pto do so. Save file damage can occur.\pIn some cases, these menus will\ndelete items given from the questline.\p"
	.string "{COLOR LIGHT_RED}{SHADOW TRANSPARENT}YOU HAVE BEEN WARNED!!$"

RDBM_ResetDevon::
	lockall
	msgbox RDBM_Devon_msg MSGBOX_DEFAULT
	delay 60
	closemessage
	special RyuResetDevonFlags
	playse SE_EXPMAX
	waitse
	release
	end

RDBM_Devon_msg:
	.string "Resetting Devon storyline progress\n... ... ... ...$"

RDBM_Magma::
	lockall
	msgbox RDBM_Magma_msg MSGBOX_DEFAULT
	release
	end
	
RDBM_Magma_msg:
	.string "Magma hasn't been implemented yet.\nNo changes have been made.$"

RDBM_ResetAqua::
	lockall
	msgbox RDBM_Aqua_msg MSGBOX_DEFAULT
	delay 60
	closemessage
	special RyuResetAquaFlags
	playse SE_EXPMAX
	waitse
	release
	end
	
RDBM_Aqua_msg:
	.string "Resetting Aqua storyline progress\n... ... ... ...$"

RDBM_ResetLeaf::
	lockall
	msgbox RDBM_Leaf_msg MSGBOX_DEFAULT
	delay 60
	closemessage
	cleartrainerflag TRAINER_GRUNT_AQUA_HIDEOUT_24
	special RyuResetLeafFlags
	playse SE_EXPMAX
	waitse
	release
	end
	
RDBM_Leaf_msg:
	.string "Resetting Leaf storyline progress\n... ... ... ...$"

RDBM_ResetRival::
	lockall
	msgbox RDBM_Rival_msg MSGBOX_DEFAULT
	delay 60
	closemessage
	special RyuResetRivalFlags
	playse SE_EXPMAX
	waitse
	release
	end
	
RDBM_Rival_msg:
	.string "Resetting {RIVAL} storyline progress\n... ... ... ...$"

RDBM_ResetBadges::
	lockall
	setvar VAR_RYU_GCMS_SPECIES, 0
	setvar VAR_RYU_GCMS_VALUE, 0
	msgbox RDBM_GCMSReset
	release
	end

RDBM_GCMSReset:
	.string "GCMS has been reset.$"

RDBM_WeatherFixArchie:
	clearflag FLAG_RYU_ARCHIE_SUCCESSFUL
	doweather
	release
	end

RDBM_WeatherMsg:
	.string "Resetting all weather variables...$"

RDBM_WeatherMsg2:
	.string "Weather has been reset to default state.$"

RDBM_Badges_msg::
	.string "Not Implemented yet.\nNo changes made.$"

RDBM_ExitResetMenu::
	msgbox RDBM_Exiting MSGBOX_DEFAULT
	release
	end

RDBM_TeleportHome:
	call_if_set FLAG_RYU_FRONTIER_MODE, Ryu_FrontierModeCheckLeave
	msgbox RGBM_TPHOME MSGBOX_DEFAULT
	closemessage
	goto RT_Home

RGBM_TPHOME:
	.string "Teleporting {PLAYER} home...$"

RDBM_Exiting:
	.string "Exiting menu without change...$"
@==================================================================================================Relationship scripts

RyuPartnerMultiText:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Would you like to challenge this\n"
	.string "opponent with one of your partners?$"

RyuParterBattleMultichoice::
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq RyuPartnerMultiBattleChoiceMale
	multichoice 20, 4, 130, 1
	switch VAR_RESULT
	case 0, RyuMultiBattlePartnerDawn
	case 1, RyuMultiBattlePartnerShelly
	case 2, RyuMultiBattlePartnerLana
	case 3, RyuMultiBattlePartnerLanette
	
RyuPartnerMultiBattleChoiceMale::
	multichoice 20, 4, 132, 1
	switch VAR_RESULT
	case 0, RyuMultiBattlePartnerBrendan
	case 1, RyuMultiBattlePartnerShelly
	case 2, RyuMultiBattlePartnerLana
	case 3, RyuMultiBattlePartnerLanette
	
RyuPartnerNoRelationship::
	msgbox Ryu_NOREL
	closemessage
	goto RyuParterBattleMultichoice
	
RyuMultiBattlePartnerDawn::
	goto_if_unset FLAG_RYU_DS_DAWN_PARTNERS, RyuPartnerNoRelationship
	setvar VAR_0x8006, TRAINER_REL_DAWN
	setvar VAR_0x8007, TRAINER_BACK_PIC_DAWN 
	return
	
RyuMultiBattlePartnerShelly::
	goto_if_unset FLAG_RYU_DS_SHELLY_PARTNERS, RyuPartnerNoRelationship
	setvar VAR_0x8006, TRAINER_REL_SHELLY
	setvar VAR_0x8007, TRAINER_BACK_PIC_SHELLY
	return
	
RyuMultiBattlePartnerBrendan::
	goto_if_unset FLAG_RYU_DS_BRENDAN_PARTNERS, RyuPartnerNoRelationship
	setvar VAR_0x8006, TRAINER_REL_BRENDAN
	setvar VAR_0x8007, TRAINER_BACK_PIC_BRENDAN
	return

RyuMultiBattlePartnerLana::
	goto_if_unset FLAG_RYU_DS_LEAF_PARTNERS, RyuPartnerNoRelationship
	setvar VAR_0x8006, TRAINER_REL_LANA
	setvar VAR_0x8007, TRAINER_BACK_PIC_LEAF
	return

RyuMultiBattlePartnerLanette::
	goto_if_unset FLAG_RYU_DS_LANETTE_PARTNERS, RyuPartnerNoRelationship
	setvar VAR_0x8006, TRAINER_REL_LANETTE
	setvar VAR_0x8007, TRAINER_BACK_PIC_LANETTE
	return

	
Ryu_PlayerCalledDawn:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} called Dawn...\n... ... ... ... ... ...$"
	
Ryu_PlayerCalledShelly:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} called Shelly...\n... ... ... ... ... ...$"
	
Ryu_PlayerCalledBrendan:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} called Brendan...\n... ... ... ... ... ...$"

Ryu_PlayerCalledLana:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} called Lana...\n... ... ... ... ... ...$"

Ryu_PlayerCalledLanette:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}{PLAYER} called Lanette...\n... ... ... ... ... ...$"
	
Ryu_NOREL:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}You don't have a good enough\nrelationship with this person.\pChoose a different partner.$"
	
@==================================================================================================General Purpose Scripts

RyuGivePokenav::
	msgbox RustboroCity_DevonCorp_3F_Text_ReceivedPokenav MSGBOX_DEFAULT
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	return


@==================================================================================================RYU EV USER MODE MENU

RyuUserModeEVMenu::
	msgbox RyuUserEVInfo MSGBOX_DEFAULT
	
	multichoicegrid 0, 4, 131, 2, 0
	switch VAR_RESULT
	case 0, RyuUserEVHp
	case 1, RyuUserEVAtk
	case 2, RyuUserEVDef
	case 3, RyuUserEVSpatk
	case 4, RyuUserEVSpdef
	case 5, RyuUserEVSpeed
	case 6, RyuUserEvExit
	case 7, RyuUserEvExit
	case 127, RyuUserEvExit
	release
	end
	
RyuUserEVHp::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	checkitem ITEM_WAVE_MAIL, 1
	compare VAR_RESULT, 1
	goto_if_ne RyuUserEvNoImprint
	special RyuSetEVHP
	addmonhappiness VAR_TEMP_2, 25
	removeitem ITEM_WAVE_MAIL, 1
	msgbox RyuEvSuccessMsgHP MSGBOX_DEFAULT
	release
	end

RyuUserEVAtk::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	checkitem ITEM_BEAD_MAIL, 1
	compare VAR_RESULT, 1
	goto_if_lt RyuUserEvNoImprint
	special RyuSetEVATK
	addmonhappiness VAR_TEMP_2, 25
	removeitem ITEM_BEAD_MAIL, 1
	msgbox RyuEvSuccessMsgAtk MSGBOX_DEFAULT
	release
	end
	
RyuUserEVDef::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	checkitem ITEM_SHADOW_MAIL, 1
	compare VAR_RESULT, 1
	goto_if_ne RyuUserEvNoImprint
	special RyuSetEVDEF
	addmonhappiness VAR_TEMP_2, 25
	removeitem ITEM_SHADOW_MAIL, 1
	msgbox RyuEvSuccessMsgDef MSGBOX_DEFAULT
	release
	end
	
RyuUserEVSpatk::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	checkitem ITEM_TROPIC_MAIL, 1
	compare VAR_RESULT, 1
	goto_if_ne RyuUserEvNoImprint
	special RyuSetEVSPATK
	addmonhappiness VAR_TEMP_2, 25
	removeitem ITEM_TROPIC_MAIL, 1
	msgbox RyuEvSuccessMsgSpatk MSGBOX_DEFAULT
	release
	end
	
RyuUserEVSpdef::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	checkitem ITEM_DREAM_MAIL, 1
	compare VAR_RESULT, 1
	goto_if_ne RyuUserEvNoImprint
	special RyuSetEVSPDEF
	addmonhappiness VAR_TEMP_2, 25
	removeitem ITEM_DREAM_MAIL, 1
	msgbox RyuEvSuccessMsgSpdef MSGBOX_DEFAULT
	release
	end
	
RyuUserEVSpeed::
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	checkitem ITEM_FAB_MAIL, 1
	compare VAR_RESULT, 1
	goto_if_ne RyuUserEvNoImprint
	special RyuSetEVSPE
	addmonhappiness VAR_TEMP_2, 25
	removeitem ITEM_FAB_MAIL, 1
	msgbox RyuEvSuccessMsgSpeed MSGBOX_DEFAULT
	release
	end
	
RyuUserEvExit::
	closemessage
	release
	end
	
RyuUserEvNoImprint::
	msgbox EvNoImprints MSGBOX_DEFAULT
	closemessage
	release
	end
	
RyuUserEVInfo:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Genetic Imprinter\p"
	.string "{SHADOW LIGHT_GREY}Select a stat to reduce to\n"
	.string "0 for the first Pokémon\l"
	.string "in your party.\pThis operation cannot be\n"
	.string "undone.$"

RyuEvSuccessMsgHP:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}HP EV's were reduced to 0.\nOne HP Imprint consumed.$"
	
RyuEvSuccessMsgAtk:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Atk EV's were reduced to 0.\nOne Atk Imprint consumed.$"
	
RyuEvSuccessMsgDef:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Def EV's were reduced to 0.\nOne Def Imprint consumed.$"
	
RyuEvSuccessMsgSpatk:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}SpAtk EV's were reduced to 0.\nOne SpAtk Imprint consumed.$"
	
RyuEvSuccessMsgSpdef:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}SpDef EV's were reduced to 0.\nOne SpDef Imprint consumed.$"
	
RyuEvSuccessMsgSpeed:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Speed EV's were reduced to 0.\nOne Speed Imprint consumed.$"

EvNoImprints:
	.string "{COLOR LIGHT_RED}{SHADOW LIGHT_GREY}You don't have enough imprints.\pObtain more at Lilycove\nTraining Center.$"

@@======================================================================================================================================= NUZLOCKE CHALLENGE RELATED

Ryu_CheckSetNuzlockPCUseVar::
	compare VAR_RYU_PC_USES, 0
    goto_if_eq Ryu_OutOfPcUses
    subvar VAR_RYU_PC_USES, 1
	return
	release
	end

Ryu_OutOfPcUses::
	playse SE_HAZURE
	waitse
	msgbox Ryu_SorryCantHeal
	release
	end

Ryu_NoPcUsesHardcore::
	playse SE_HAZURE
	waitse
	msgbox Ryu_SorryHardcore
	release
	end

Ryu_SorryCantHeal:
	.string "{COLOR LIGHT_RED}{SHADOW RED}I'm terribly sorry, but you have\nused up all of your heals until\lyou get a new badge.$"

Ryu_SorryHardcore:
	.string "This service is restricted by\ngame rules. Sorry!$"

RyuMartsDisabledNuzlocke::
	msgbox RyuMartsDisabledNuzlockeMsg MSGBOX_DEFAULT
	release
	end

RyuTCDisabledNuzlocke::
	msgbox RyuTCDisabledNuzlockeMsg MSGBOX_DEFAULT
	release
	end

Ryu_YouHaveNoMons::
	msgbox CantHealNoMons
	release
	end

CantHealNoMons:
	.string "You don't have any pokemon to heal.\nPlease return another time!$"

RyuMartsDisabledNuzlockeMsg:
	.string "{COLOR DARK_GREY}{SHADOW RED}Sorry, but you can't use this while\n"
	.string "playing in nuzlocke mode. Fight more\p"
	.string "Gyms!$"

RyuTCDisabledNuzlockeMsg:
	.string "{COLOR DARK_GREY}{SHADOW RED}Sorry, but the Training Center is\n"
	.string "disabled while playing in nuzlocke\p"
	.string "mode. Grind in grass!$"
	
RyuHealed:
	.string "Your team has been restored to full\n"
	.string "health. Have a nice day!$"
	
RyuUsesGone:
	.string "{COLOR DARK_GREY}{SHADOW RED}You cannot use this Pokemon Center\n"
	.string "anymore.$"

RyuHealedGym::
	special HealPlayerParty
	msgbox RyuHealedGymMsg MSGBOX_DEFAULT
	closemessage
	return
	
RyuScripts_HardcoreGymReward::
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 1
	release
	end

RyuGymItemReward1::
	giveitem ITEM_TM39
	closemessage
	setflag FLAG_RYU_GYM1HANDOUT
	goto_if_unset FLAG_RYU_NUZLOCKEMODE, ryu_return
	additem ITEM_SUPER_POTION, 1
	additem ITEM_GREAT_BALL, 1
	closemessage
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	goto_if_set FLAG_RYU_NUZLOCKEMODE, Ryu_ResetPcUses
	return

Ryu_ResetPcUses::
	setvar VAR_RYU_PC_USES, 3
	return

RyuGymItemReward2::
	giveitem ITEM_TM60
	setflag FLAG_RYU_GYM2HANDOUT
	goto_if_unset FLAG_RYU_NUZLOCKEMODE, ryu_return
	additem ITEM_SUPER_POTION, 2
	additem ITEM_GREAT_BALL, 2
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	goto_if_set FLAG_RYU_NUZLOCKEMODE, Ryu_ResetPcUses
	return

RyuGymItemReward3::
	giveitem ITEM_TM34
	setflag FLAG_RYU_GYM3HANDOUT
	goto_if_unset FLAG_RYU_NUZLOCKEMODE, ryu_return
	additem ITEM_SUPER_POTION, 3
	additem ITEM_GREAT_BALL, 3
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	goto_if_set FLAG_RYU_NUZLOCKEMODE, Ryu_ResetPcUses
	return

RyuGymItemReward4::
	giveitem ITEM_TM50
	setflag FLAG_RYU_GYM4HANDOUT
	goto_if_unset FLAG_RYU_NUZLOCKEMODE, ryu_return
	additem ITEM_SUPER_POTION, 4
	additem ITEM_GREAT_BALL, 4
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	goto_if_set FLAG_RYU_NUZLOCKEMODE, Ryu_ResetPcUses
	return

RyuGymItemReward5::
	giveitem ITEM_TM42
	setflag FLAG_RYU_GYM5HANDOUT
	goto_if_unset FLAG_RYU_NUZLOCKEMODE, ryu_return
	additem ITEM_SUPER_POTION, 5
	additem ITEM_GREAT_BALL, 5
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	goto_if_set FLAG_RYU_NUZLOCKEMODE, Ryu_ResetPcUses
	return

RyuGymItemReward6::
	giveitem ITEM_TM40
	setflag FLAG_RYU_GYM6HANDOUT
	goto_if_unset FLAG_RYU_NUZLOCKEMODE, ryu_return
	additem ITEM_SUPER_POTION, 6
	additem ITEM_GREAT_BALL, 6
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	goto_if_set FLAG_RYU_NUZLOCKEMODE, Ryu_ResetPcUses
	return

RyuGymItemReward7::
	giveitem ITEM_TM04
	setflag FLAG_RYU_GYM7HANDOUT
	goto_if_unset FLAG_RYU_NUZLOCKEMODE, ryu_return
	additem ITEM_SUPER_POTION, 7
	additem ITEM_GREAT_BALL, 7
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	goto_if_set FLAG_RYU_NUZLOCKEMODE, Ryu_ResetPcUses
	return

RyuGymItemReward8::
	giveitem ITEM_TM03
	setflag FLAG_RYU_GYM8HANDOUT
	goto_if_unset FLAG_RYU_NUZLOCKEMODE, ryu_return
	additem ITEM_SUPER_POTION, 8
	additem ITEM_GREAT_BALL, 8
	setvar VAR_RYU_NUZLOCKE_WAYSTONE_USES, 3
	goto_if_set FLAG_RYU_NUZLOCKEMODE, Ryu_ResetPcUses
	return

RyuHealedGymMsg:
	.string "I've restored your Pokémon to\n"
	.string "full health.$"

RyuGameClearedMsg:
	.string "{COLOR GREEN} {SHADOW LIGHT_GREY}Congratulations on clearing the game\n"
	.string "in nuzlocke mode! It's a momentous\p"
	.string "achievment, considering how hard\n"
	.string "the base game is. Add Ryuhouji/2180\p"
	.string "on discord and let me know you\n"
	.string "reached this point!\p"
	.string "Nuzlocke restrictions have been\p"
	.string "lifted, enjoy the battle frontier!$"
	
RyuEmptySpace:
	.string "$"
	
RyuFailedNuzlocke::
	msgbox NuzlockeFail MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_RYU_NUZLOCKEMODE
	setvar VAR_RYU_EXP_MULTIPLIER, 1000
	setvar VAR_RYU_PRICE_MULTIPLIER, 1000
	release
	end
	
NuzlockeFail:
	.string "You have failed this nuzlocke\n"
	.string "challenge. Game will now go to\l."
	.string "Normal mode.$"

@============================================================================================================================= Forecaster

Ryu_Forecaster::
	msgbox RyuForecasterIntro MSGBOX_SIGN
	closemessage
	multichoicedefault 0, 0, 134, 0, 1 
	switch VAR_RESULT
	case 0, Ryu_FCClear
	case 1, Ryu_FCLightRain
	case 2, Ryu_FCStorm
	case 3, Ryu_FCDrought
	case 4, Ryu_FCSandstorm
	case 5, Ryu_FCSnow
	case 6, Ryu_FCShade
	case 7, Ryu_FCExit

RyuForecasterIntro:
	.string "Please select desired weather.\nSelecting 'Clear' will\lrevert to default.$"

Ryu_FCClear::
	lock
	setweather WEATHER_NONE
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_NONE
	clearflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCLightRain::
	lock
	setweather WEATHER_RAIN
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_RAIN
	setflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCStorm::
	lock
	setweather WEATHER_RAIN_THUNDERSTORM
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_RAIN_THUNDERSTORM
	setflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCDrought::
	lock
	setweather WEATHER_DROUGHT
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_DROUGHT
	setflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCSandstorm::
	lock
	setweather WEATHER_SANDSTORM
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_SANDSTORM
	setflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCSnow::
	lock
	setweather WEATHER_SNOW
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_SNOW
	setflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCShade::
	lock
	setweather WEATHER_SHADE
	doweather
	setvar VAR_RYU_WEATHER, WEATHER_SHADE
	setflag FLAG_RYU_FORECASTER
	release
	end

Ryu_FCExit::
	release
	end



Ryu_CantUsePcCharging::
	msgbox RyuCantUsePCCHARGING 
	closemessage
	release
	end

RyuCantUsePCCHARGING:
	.string "The Wireless PC needs to recharge.\nPlease try again later.$"
	

@=================================================Ball changer


RyuBallChanger::
	msgbox BCIntro
	multichoicegrid 2, 0, 141, 3, 1
	switch VAR_RESULT
	case 0, BCPokeball
	case 1, BCGreatball
	case 2, BCUltraball
	case 3, BCLuxuryball
	case 4, BCPremierball
	case 5, BCRepeatball
	case 6, BCTimerball
	case 7, BCNestball
	case 8, BCNetball
	case 9, BCSafariball
	case 10, BCDiveball
	case 11, BCCancel
	end

BCPokeball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_POKE_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 4
	removeitem ITEM_POKE_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCGreatball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_GREAT_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 3
	removeitem ITEM_GREAT_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCUltraball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_ULTRA_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 2
	removeitem ITEM_ULTRA_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCLuxuryball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_LUXURY_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 11
	removeitem ITEM_LUXURY_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCPremierball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_PREMIER_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 11
	removeitem ITEM_PREMIER_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCRepeatball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_REPEAT_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 9
	removeitem ITEM_REPEAT_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCTimerball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_TIMER_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 10
	removeitem ITEM_TIMER_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCNestball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_NEST_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 8
	removeitem ITEM_NEST_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCNetball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_NET_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 6
	removeitem ITEM_NET_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCSafariball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_SAFARI_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 5
	removeitem ITEM_SAFARI_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCDiveball::
	checkmoney 10000
	compare VAR_RESULT, 1
	goto_if_ne BC_NotEnoughMoney
	checkitem ITEM_DIVE_BALL, 1
	compare VAR_RESULT, 1
	goto_if_ne BC_NoBall
	setvar VAR_TEMP_4, 7
	removeitem ITEM_DIVE_BALL, 1
	takemoney 10000
	special RyuChangeUsedPokeball
	msgbox BC_Success
	release
	end

BCIntro:
	.string "Welcome to the ball changer menu.\pOnce you make your selection,\nyou will be charged ¥10000\land the chosen ball will be consumed.$"

BCCancel::
	msgbox BC_Cancelled
	closemessage
	release
	end

BC_NoBall::
	msgbox BC_NeedBall
	release
	end

BC_NotEnoughMoney:
	msgbox BC_NeedMoney
	release
	end

BC_Cancelled:
	.string "Okay. We can try again later.$"

BC_Success:
	.string "Success!\nThe ball has been changed.\pYou were charged ¥10000, and\nthe ball you changed to was consumed.$"

BC_NeedBall:
	.string "Sorry, but you must have at least\none of the ball you want to change to.$"

BC_NeedMoney:
	.string "Sorry, but you do not have enough\nmoney to do this.\pIt costs ¥10000.$"
	
@@+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++Follower System

RyuCancelFollowerForQuest::  @call_if_set FLAG_RYU_HAS_FOLLOWER, RyuCancelFollowerForQuest
	msgbox RyuCantHaveFollower MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq RF_FollowerLeaveCall
	release
	end

RyuResetFollowerPosition::
	gfec
	setobjectxy OBJ_EVENT_ID_FOLLOWER, VAR_TEMP_E, VAR_TEMP_F
	setvar VAR_TEMP_D, 1
	end

RyuResetFollowerPositionAR::
	gfec
	setobjectxy OBJ_EVENT_ID_FOLLOWER, VAR_TEMP_E, VAR_TEMP_F
	setvar VAR_TEMP_D, 1
	return

RyuForceCancelFollowerForQuest:: @call_if_set FLAG_RYU_HAS_FOLLOWER, RyuForceCancelFollowerForQuest
	goto RF_FollowerLeaveCall
	

RyuFollowerSelectNPCScript::
	switch VAR_RYU_FOLLOWER_ID
	case OBJ_EVENT_GFX_TWIN, LRT_MinnieScript
	case OBJ_EVENT_GFX_AQUA_MEMBER_F, RyuFollower_ShellyScript
	case OBJ_EVENT_GFX_WOMAN_2, RyuFollower_LanetteScript
	end

RyuFollower_ShellyScript::
	goto_if_set FLAG_RYU_WAYSTONE_DISABLED, RyuFollower_MagmaShelly
	msgbox RyuFollower_ShellyLeaveMsg MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RF_FollowerLeave
	release
	end

RyuFollower_MagmaShelly::
	goto MH_FollowerShellyScript
	end
	
RyuFollower_LanetteScript::
	msgbox RyuFollowerLanetteLeaveMsg MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RF_FollowerLeave
	release
	end

RF_FollowerLeaveCall::
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_WOMAN_2
	goto_if_eq Ryu_RestoreLanetteAtHouse
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_TWIN
	goto_if_eq Ryu_RestoreMinnie
	clearflag FLAG_RYU_HAS_FOLLOWER
	destroyfollower
	msgbox RyuFollowerLeavesService
	clearflag FLAG_RYU_HAS_FOLLOWER
	return
	
RF_FollowerLeave:
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_WOMAN_2
	call_if_eq Ryu_RestoreLanetteAtHouse
	compare VAR_RYU_FOLLOWER_ID, OBJ_EVENT_GFX_TWIN
	call_if_eq Ryu_RestoreMinnie
	clearflag FLAG_RYU_HAS_FOLLOWER
	destroyfollower
	msgbox RyuFollowerLeavesService
	clearflag FLAG_RYU_HAS_FOLLOWER
	release
	end

Ryu_RestoreLanetteAtHouse::
	clearflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	return

Ryu_RestoreMinnie::
	clearflag FLAG_RYU_HIDE_MINNIE
	return

RyuFollowerAllySelector::
	special RyuFollowerToTrainerID
	return
	
RyuFollower_ShellyLeaveMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Shelly: Should I go?$"
	
RyuFollowerLanetteLeaveMsg:
	.string "{COLOR LIGHT_RED}{SHADOW RED}Lanette: Should I return to my lab??$"

RyuFollowerLeavesService:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN}Your follower\nleaves your service...$"

RyuCantHaveFollower:
    .string "{COLOR LIGHT_GREEN}{SHADOW GREEN}You're attempting to do a\n"
    .string "cinematic quest.\p"
    .string "You can't have a follower present\n"
    .string "for this quest. Would you like\l"
    .string "to dismiss your follower?$"


ryu_return::
	return

ryu_end::
	release
	end

@==================================================================================================Theme changer

Ryu_SwitchTheme::
	compare VAR_RYU_THEME_NUMBER, 0
	goto_if_eq Ryu_SwitchToDarkTheme
	compare VAR_RYU_THEME_NUMBER, 1
	goto_if_eq Ryu_SwitchToDefaultTheme
	end

Ryu_SwitchToDarkTheme::
	setvar VAR_RYU_THEME_NUMBER, 1
	msgbox RyuNowUsingDarkTheme
	release
	end

Ryu_SwitchToDefaultTheme::
	setvar VAR_RYU_THEME_NUMBER, 0
	msgbox RyuNowUsingDefaultTheme
	release
	end

RyuNowUsingDarkTheme:
	.string "You're now using the dark theme.$"

RyuNowUsingDefaultTheme:
	.string "Switched to default theme.$"

@========================================================================Random "Stepped On" encounter

SB_CheckMeloettaEncounter::
	goto_if_set FLAG_RYU_CAPTURED_MELOETTA, ryu_end
	readgamestat GAME_STAT_USED_SOUND_MOVE
	switch VAR_RESULT
	case 255, Ryu_DoMeloettaRoll
    case 200, Ryu_MeloettaWatchingMsg
	case 100, Ryu_BeingWatched
	release
	end

Ryu_MeloettaWatchingMsg::
	goto_if_set FLAG_RYU_SECOND_MELOETTA_MSG, ryu_end
	playmoncry SPECIES_MELOETTA, 0
	msgbox Ryu_HearAMelodyFromSomewhere
	setflag FLAG_RYU_SECOND_MELOETTA_MSG
	waitmoncry
	closemessage
	release
	end

Ryu_HearAMelodyFromSomewhere:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (You hear a delightful melody from\n"
	.string " somewhere nearby...)$"

Ryu_BeingWatched::
	goto_if_set FLAG_RYU_FIRST_MELOETTA_MSG, ryu_end
	msgbox Ryu_Feelslikebeingwatchedmsg
	setflag FLAG_RYU_FIRST_MELOETTA_MSG
	closemessage
	release
	end

Ryu_Feelslikebeingwatchedmsg:
	.string "{COLOR LIGHT_GREEN}{SHADOW GREEN} (You get the strangest feeling...\n"
	.string " as if someone or something is\l"
	.string " watching over you...)$"

Ryu_DoMeloettaRoll::
	random 10
	compare VAR_RESULT, 1
	goto_if_eq Ryu_DoMeloettaEncounter
	release
	end

Ryu_DoMeloettaEncounter::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	fadescreen FADE_TO_BLACK
	drawfullscreenimage SCENEBGMELOETTA
	msgbox Ryu_MeloettaApproaches
	closemessage
	playmoncry SPECIES_MELOETTA, 0
	msgbox Ryu_ItsSingingBeautifully
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	setwildbattle SPECIES_MELOETTA, VAR_RESULT, ITEM_STAR_PIECE
	clearfullscreenimage
	fadescreen FADE_FROM_BLACK
	special BattleSetup_StartLegendaryBattle
	waitstate
	special GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne Ryu_MeloettaNotCaught
	setflag FLAG_RYU_CAPTURED_MELOETTA
	release
	end

Ryu_MeloettaNotCaught::
	special resetSoundGameStat
	release
	end

Ryu_MeloettaApproaches:
	.string "A cute looking Pokemon approaches!$"

Ryu_ItsSingingBeautifully::
	.string "It starts singing a nice tune...\p"
	.string "It finishes its tune and attacks!$"

SB_SetupRandomSteppedOnEncounter::
	compare VAR_REPEL_STEP_COUNT, 0
	goto_if_ne ryu_end
	random 5
	switch VAR_RESULT
	case 0, SB_Random0
	case 1, SB_Random1
	case 2, SB_Random2
	case 3, SB_Random3
	case 4, SB_Random4
	goto  ryu_end

SB_SetupRandomMimikyuEncounter::
	lock
	clearflag FLAG_TEMP_A
	setwildbattle SPECIES_MIMIKYU, 33, ITEM_NONE
	playmoncry SPECIES_MIMIKYU, 0
	waitmoncry
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox StumbledOnMimikyu
	closemessage
	dowildbattle
	release
	end

StumbledOnMimikyu:
	.string "You stumbled across\na wild Mimikyu!$"


SB_Random0::
	setwildbattle SPECIES_PYUKUMUKU, 20, ITEM_NONE
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	bufferspeciesname 0, SPECIES_PYUKUMUKU
	msgbox Ryu_YouSteppedOn
	closemessage
	dowildbattle
	release
	end

SB_Random1::
	setwildbattle SPECIES_SANDYGAST, 20, ITEM_NONE
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	bufferspeciesname 0, SPECIES_SANDYGAST
	msgbox Ryu_YouSteppedOn
	closemessage
	dowildbattle
	release
	end

SB_Random2::
	setwildbattle SPECIES_SHELLDER, 20, ITEM_NONE
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	bufferspeciesname 0, SPECIES_SHELLDER
	msgbox Ryu_YouSteppedOn
	closemessage
	dowildbattle
	release
	end

SB_Random3::
	setwildbattle SPECIES_MAREANIE, 20, ITEM_NONE
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	bufferspeciesname 0, SPECIES_MAREANIE
	msgbox Ryu_YouSteppedOn
	closemessage
	dowildbattle
	release
	end

SB_Random4::
	setwildbattle SPECIES_SKRELP, 20, ITEM_NONE
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	bufferspeciesname 0, SPECIES_SKRELP
	msgbox Ryu_YouSteppedOn
	closemessage
	dowildbattle
	release
	end

Ryu_YouSteppedOn:
	.string "You stepped on a wild {STR_VAR_1}!$"

@==================================================================================================MEGA STONE REWARDS


RyuTier8GymMegaStoneReward::
	switch VAR_TEMP_8
	case 1, RoxanneMegaReward
	case 2, BrawlyMegaReward
	case 3, WattsonMegaReward
	case 4, FlanneryMegaReward
	case 5, NormanMegaReward
	case 6, WinonaMegaReward
	case 7, TateandLizaMegaReward
	case 8, JuanMegaReward
	return


RoxanneMegaReward::
	goto_if_set FLAG_RYU_ROXANNE_MEGA_REWARD, ryu_return
	msgbox RoxanneMega
	additem ITEM_AERODACTYLITE
	setflag FLAG_RYU_ROXANNE_MEGA_REWARD
	closemessage
	return

RoxanneMega:
	.string "Roxanne: Congratulations! You have\nbeaten me at my strongest.\lHere's a special gift from me!$"

BrawlyMegaReward::
	goto_if_set FLAG_RYU_BRAWLY_MEGA_REWARD, ryu_return
	msgbox BrawlyMega
	additem ITEM_MEDICHAMITE
	setflag FLAG_RYU_BRAWLY_MEGA_REWARD
	closemessage
	return

BrawlyMega:
	.string "Brawly: You've totally outclassed\nme in battle. I feel comfortable\ltrusting you with this.$"

WattsonMegaReward::
	goto_if_set FLAG_RYU_WATTSON_MEGA_REWARD, ryu_return
	msgbox WattsonMega
	additem ITEM_MANECTITE
	setflag FLAG_RYU_WATTSON_MEGA_REWARD
	closemessage
	return

WattsonMega:
	.string "Wattson: Color me shocked, you\nreally got me!\pHere's a gift from me!$"

FlanneryMegaReward::
	goto_if_set FLAG_RYU_FLANNERY_MEGA_REWARD, ryu_return
	msgbox FlanneryMega
	additem ITEM_BLAZIKENITE
	setflag FLAG_RYU_FLANNERY_MEGA_REWARD
	closemessage
	return

FlanneryMega:
	.string "Flannery: You're too hot for\nme to handle, but I bet\lyou can handle this!$"

NormanMegaReward::
	goto_if_set FLAG_RYU_NORMAN_MEGA_REWARD, ryu_return
	msgbox NormanMega
	additem ITEM_KANGASKHANITE
	setflag FLAG_RYU_NORMAN_MEGA_REWARD
	closemessage
	return

NormanMega:
	.string "Dad: I'm very proud of you!\nTake this gift from me,\lYou can put it to good use!$"

WinonaMegaReward::
	goto_if_set FLAG_RYU_WINONA_MEGA_REWARD, ryu_return
	msgbox WinonaMega
	additem ITEM_PIDGEOTITE
	setflag FLAG_RYU_WINONA_MEGA_REWARD
	closemessage
	return

WinonaMega:
	.string "Winona: Your grace exceeds my own,\nso it's only right for you to\lhave this!$"

TateandLizaMegaReward::
	goto_if_set FLAG_RYU_TAL_MEGA_REWARD, ryu_return
	msgbox TateandLizaMega
	additem ITEM_ALAKAZITE
	setflag FLAG_RYU_TAL_MEGA_REWARD
	closemessage
	return

TateandLizaMega:
	.string "Liza: You overcame our impossible\nto beat combo!\pYou can use this to it's\nfullest power!$"

JuanMegaReward::
	goto_if_set FLAG_RYU_JUAN_MEGA_REWARD, ryu_return
	msgbox JuanMega
	additem ITEM_SWAMPERTITE
	setflag FLAG_RYU_JUAN_MEGA_REWARD
	closemessage
	return

JuanMega:
	.string "Juan: You're even more fabulous\nthan I. I thought this wasn't\ppossible until now. As a token\nof your dedication to the art\lof battle, take this stone!$"

@Legendaries common scripts

RyuLegendary_LeftStoneAlone::
	msgbox RyuLegendary_LeftStoneAloneMsg
	release
	end

RyuLegendary_LeftStoneAloneMsg:
	.string "{PLAYER} left the stone alone.$"

RyuLegendary_CheckCaught::
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_ne ryu_end
	return

RyuLegendary_Stoneisdull::
	msgbox RyuLegendary_StoneIsDullMsg
	release
	end

RyuLegendary_StoneIsDullMsg:
	.string "The stone is dull and lifeless.$"

@==================================================================================================Randombattle

Ryu_StartRandomBattle::
	msgbox StartingRandomBattleMsg
	cleartrainerflag TRAINER_RANDOM_PARTY
	trainerbattle_single TRAINER_RANDOM_PARTY, BF_battleintro, BF_battledefeat, BF_RandomBattleCleanup
	end

StartingRandomBattleMsg:
	.string "Starting Random Battle...$"

BF_RandomBattleCleanup::
	msgbox BattleAgain, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Ryu_StartRandomBattle
	clearflag FLAG_RYU_RANDOMBATTLE
	special ForceSoftReset
	release
	end
	
BF_NoBattle::
	msgbox BF_NoBattleMsg
	closemessage
	release
	end

BattleAgain:
	.string "Would you like to battle again?$"
	
BF_NoBattleMsg:
    .string "Very well. Talk with me again if\n"
    .string "you change your mind!$"

BF_Starting:
    .string "Hold on... Let me put your party\n"
    .string "aside...\p"
    .string "... ... ... ...\n"
    .string "... ... ... ...\p"
    .string "There. All set... Here we go!$"

	
BF_RandomIntro:
    .string "Selene: Hi! I like to do random\n"
    .string "battles.\p"
    .string "Would you like to battle with me?$"

BF_battleintro:
	.string "I will try my very hardest to win!$"
	
BF_battledefeat:
	.string "Good fight.\nLet's do it again!$"

@==================================================================================================Meloetta Switcher

CLM_MeloettaSwitcher::
	msgbox CLM_MSIntro
	closemessage
	lockall
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 2
	faceplayer
	msgbox CLM_MS_OhHiSorry
	closemessage
	specialvar VAR_RESULT, RyuMeloettaFormSwitcher
	switch VAR_RESULT
	case 2, CLM_MeloettaFinished @ form was sucessfully switched
	case 0, CLM_NoMeloetta @Player hasn't caught meloetta
	case 1, CLM_MeloettaNotInParty @Player caught it but doesn't have it with them
	end
	
CLM_MeloettaFinished::
	playmoncry SPECIES_MELOETTA, 0
	bufferpartymonnick 0, VAR_TEMP_9
	msgbox CLM_MeloettaCriesFromBall
	waitmoncry
	closemessage
	msgbox CLM_FinishedMsg
	closemessage
	showmonpic VAR_TEMP_A, 10, 3
	msgbox CLM_MeloettaSwitcherLadyOutro
	closemessage
	hidemonpic
	applymovement 2, Common_Movement_FaceRight
	waitmovement 2
	release
	end

CLM_MeloettaNotInParty::
	msgbox CLM_NotInPartyMsg
	closemessage
	applymovement 2, Common_Movement_FaceRight
	waitmovement 2
	release
	end

CLM_NoMeloetta::
	msgbox CLM_NoMeloettaMsg
	closemessage
	applymovement 2, Common_Movement_FaceRight
	waitmovement 2
	release
	end

CLM_MSIntro:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(The woman is quietly humming to\n"
    .string " herself as she watches the tv across\l"
    .string " the room.)$"
	
CLM_MS_OhHiSorry:
    .string "Oh! Hi! Sorry! I was just thinking\n"
    .string "about this tune I heard\l"
	.string "when I was young.$"

CLM_MeloettaCriesFromBall:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}Your {STR_VAR_1} cries out from her\n"
    .string " ball, as if she knew this person a\l"
    .string " long time ago...)$"

CLM_MeloettaSwitcherLadyOutro:
    .string "Oh, wow, it was this Pokémon that I\n"
    .string "heard so many years ago! Wait... She\l"
    .string "changed colors! What could it mean?!$"

CLM_NoMeloettaMsg:
    .string "This tune has been stuck in my head\n"
    .string "for so many years. I wish I knew\l"
    .string "where I heard it.$"

CLM_FinishedMsg:
    .string " {COLOR LIGHT_GREEN}{SHADOW GREEN}(It appears that your {STR_VAR_1}\n"
    .string " took on a new form!)$"

CLM_NotInPartyMsg:
    .string "Oh!, I think you've heard it too! Do\n"
    .string "you know where it came from?\p"
    .string "{COLOR LIGHT_BLUE}{SHADOW BLUE}{PLAYER}: Yes, it's from a Pokémon.\n"
    .string "{COLOR DARK_GREY}{SHADOW LIGHT_GREY}You have to show me, Please!$"
