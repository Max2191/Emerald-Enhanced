LilycoveCity_TrainingCenter_MapScripts::
	.byte 0
	
TC_EvIvCheckerScript::
    lock
	special RyuIvCheckerDef
	msgbox TC_IvShow1 MSGBOX_DEFAULT
	special RyuIvCheckerOff
	msgbox TC_IvShow2 MSGBOX_DEFAULT
	special RyuEvCheckerDef
	msgbox TC_EvShow1 MSGBOX_DEFAULT
	special RyuEvCheckerOff
	msgbox TC_EvShow2 MSGBOX_DEFAULT
	special RyuOtherDataChecker
	msgbox TC_FSShow MSGBOX_DEFAULT
	goto_if_set FLAG_RYU_NUZLOCKEMODE, TC_IVEV_NOHEAL
	goto_if_set FLAG_RYU_HARDCORE_MODE, TC_IVEV_NOHEAL
	special HealPlayerParty
	playfanfare MUS_ME_ASA
	waitfanfare
	release
	end

TC_IVEV_NOHEAL::
	msgbox TC_HCNZ_CANTHEAL
	release
	end

TC_HCNZ_CANTHEAL:
	.string "You're in a restricted game mode.\nYou can't heal here.$"
	
TC_IvShow1:
	.string "Lead Pokemon Defensive IVS:\n"
	.string "HP: {STR_VAR_1}    Def: {STR_VAR_2}     SpDef: {STR_VAR_3}$"
	
TC_IvShow2:
	.string "Lead Pokemon Offensive IVS:\n"
	.string "Atk: {STR_VAR_1}    SpAtk: {STR_VAR_2}     Speed: {STR_VAR_3}$"
	
TC_EvShow1:
	.string "Lead Pokemon Defensive EVS:\n"
	.string "HP: {STR_VAR_1}    Def: {STR_VAR_2}     SpDef: {STR_VAR_3}$"
	
TC_EvShow2:
	.string "Lead Pokemon Offensive EVS:\n"
	.string "Atk: {STR_VAR_1}    SpAtk: {STR_VAR_2}     Speed: {STR_VAR_3}$"

TC_FSShow:
	.string "Lead Pokemon Friendship Level: {STR_VAR_1}\n"
	.string "Lead Pokemon Ribbon Count: {STR_VAR_3}$"

@================================================================================================== Training Center Entry
	
TC_Entry::
	lockall
	goto_if_set FLAG_RYU_NUZLOCKEMODE, TC_ENTRY_NUZLOCKE
	goto_if_set FLAG_RYU_HARDCORE_MODE, TC_ENTRY_NUZLOCKE
	goto_if_set FLAG_RYU_TC_ENTERED, TC_Exiting
	applymovement 2, TC_FacePlayer
	goto_if_set FLAG_RYU_DEV_MODE, TC_DevEntry
	msgbox TC_Entry_Cost MSGBOX_DEFAULT
	waitmessage
	msgbox TC_EnterQuery MSGBOX_YESNO
	compare VAR_RESULT 1
	goto_if_eq TC_Entering
	goto TC_Exiting

TC_ENTRY_NUZLOCKE::
	msgbox TC_CantEnterNuzlockeHardcore
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepDown
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_StepDown
	release
	end

TC_CantEnterNuzlockeHardcore:
	.string "You're in a restricted game mode.\nYou can't use this service.$"

TC_DevEntry::
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 2
	msgbox TC_DevModeMsg
	closemessage
	setflag FLAG_RYU_TC_ENTERED
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_StepUp
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_StepUp
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

TC_DevModeMsg:
	.string "Oh! Sorry, m'lord. I didn't\nrealize it was you at first.\pPlease forgive me and continue\nthrough as you will.$"
	

TC_Entering::
	lockall
	call TC_BallCheck
	checkitem ITEM_TOWN_MAP, 0
	compare VAR_RESULT, 1
	goto_if_eq TC_Discount_entering
	checkmoney 65000
	compare VAR_RESULT, 0
	goto_if_eq TC_Exiting_Nomoney
	msgbox TC_Welcome MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, TC_WalkIn
	applymovement OBJ_EVENT_ID_FOLLOWER, TC_WalkIn
	waitmovement 0
	takemoney VAR_TEMP_0
	setflag FLAG_RYU_TC_ENTERED
	setflag FLAG_RYU_WAYSTONE_DISABLED
	releaseall
	end
	
TC_Discount_entering::
	msgbox TC_Discount_Welcome MSGBOX_DEFAULT
	checkmoney 6500
	compare VAR_RESULT, 0
	goto_if_eq TC_Disc_Broke
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, TC_WalkIn
	applymovement OBJ_EVENT_ID_FOLLOWER, TC_WalkIn
	waitmovement 0
	takemoney 6500
	setflag FLAG_RYU_WAYSTONE_DISABLED
	setflag FLAG_RYU_TC_ENTERED
	releaseall
	end

TC_Discount_Welcome:
	.string "Oh, I see you have a VIP Pass.\n"
	.string "That reduces the cost to ¥10000.\p"
	.string "Lots of the professor's research is\n"
	.string "used here!$"
	
TC_Disc_Broke::
	msgbox TC_Leave_Disc_broke, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, TC_WalkOut
	applymovement OBJ_EVENT_ID_FOLLOWER, TC_WalkOut
	waitmovement OBJ_EVENT_ID_PLAYER
	releaseall
	end

TC_Leave_Disc_broke:
	.string "I'm sorry, but even with the guest\n"
	.string "pass, it still costs ¥10,000 to enter.\p"
	.string "We still have maintenance costs!\n"
	.string "Please come back later. Thanks!$"
	
TC_BallCheck::
	checkitem ITEM_POKE_BALL, 1
	compare VAR_RESULT, 1
	goto_if_eq TC_Exiting_pokeballs
	checkitem ITEM_GREAT_BALL, 1
	compare VAR_RESULT, 1
	goto_if_eq TC_Exiting_pokeballs
	checkitem ITEM_PREMIER_BALL, 1
	compare VAR_RESULT, 1
	goto_if_eq TC_Exiting_pokeballs
	checkitem ITEM_ULTRA_BALL, 1
	compare VAR_RESULT, 1
	goto_if_eq TC_Exiting_pokeballs
	checkitem ITEM_LUXURY_BALL, 1
	compare VAR_RESULT, 1
	goto_if_eq TC_Exiting_pokeballs
	checkitem ITEM_NET_BALL, 1
	compare VAR_RESULT, 1
	goto_if_eq TC_Exiting_pokeballs
	checkitem ITEM_DIVE_BALL, 1
	compare VAR_RESULT, 1
	goto_if_eq TC_Exiting_pokeballs
	checkitem ITEM_NEST_BALL, 1
	compare VAR_RESULT, 1
	goto_if_eq TC_Exiting_pokeballs
	checkitem ITEM_REPEAT_BALL, 1
	compare VAR_RESULT, 1
	goto_if_eq TC_Exiting_pokeballs
	checkitem ITEM_TIMER_BALL, 1
	compare VAR_RESULT, 1
	goto_if_eq TC_Exiting_pokeballs
	checkitem ITEM_SAFARI_BALL, 1
	compare VAR_RESULT, 1
	goto_if_eq TC_Exiting_pokeballs
	return
	
TC_Exiting_Nomoney::
	msgbox TC_Broke MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, TC_WalkOut
	applymovement OBJ_EVENT_ID_FOLLOWER, TC_WalkOut
	waitmovement 0
	releaseall
	end
	
TC_Broke:
	.string "I'm sorry, but you cannot afford\n"
	.string "to use the training center currently.\p"
	.string "You need ¥65000 to enter.\p"
	.string "Perhaps you can find a friend with\n"
	.string "a membership or VIP pass.\p"
	.string "Have a nice day!$"
	
TC_Exiting::
	applymovement 2, TC_FacePlayer
	msgbox TC_Leave MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, TC_WalkOut
	applymovement OBJ_EVENT_ID_FOLLOWER, TC_WalkOut
	waitmovement 0
	clearflag FLAG_RYU_TC_ENTERED
	clearflag FLAG_RYU_WAYSTONE_DISABLED
	releaseall
	end

TC_InvalidExitCheck::
	goto_if_set FLAG_RYU_TC_ENTERED, TC_WelcomeBack
	goto_if_set FLAG_RYU_NUZLOCKEMODE, RyuTCDisabledNuzlocke
	releaseall
	end

TC_WelcomeBack::
	applymovement OBJ_EVENT_ID_PLAYER, TC_Reentry
	applymovement OBJ_EVENT_ID_FOLLOWER, TC_Reentry
	waitmovement 0
	applymovement 2, TC_FacePlayer
	waitmovement 0
	msgbox TC_WB_TEXT MSGBOX_DEFAULT
	call TC_BallCheck
	applymovement OBJ_EVENT_ID_PLAYER, TC_WalkIn
	applymovement OBJ_EVENT_ID_FOLLOWER, TC_WalkIn
	waitmovement 0
	releaseall
	end
	
TC_WB_TEXT:
	.string "Hi there. It seems you passed out.\n"
	.string "You may now resume your session.$"
	
	
TC_Exiting_pokeballs::
	msgbox TC_Leave_Balls MSGBOX_DEFAULT
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, TC_WalkOut
	applymovement OBJ_EVENT_ID_FOLLOWER, TC_WalkOut
	waitmovement 0
	releaseall
	end

TC_Entry_Cost:
	.string "Hello and welcome to Lilycove\n"
	.string "Training Center.\p"
	.string "It will cost ¥65000 to use this service.\p"
	.string "You're also not permitted to have\n"
        .string "any pokeballs with you. \p"
	.string "Please deposit any you have\n"
	.string "in the pc to our left.$"

TC_EnterQuery:
	.string "Would you like to enter?$"
	
TC_Welcome:
	.string "We hope you have a fruitful training\n"
	.string "session!$"
	
TC_Leave:
	.string "Thanks for using the Lilycove\n"
	.string "Training Center!\p"
	.string "Don't forget to take your balls\n"
	.string "out of the PC! $"
	
TC_Leave_Balls:
	.string "I'm terribly sorry, but you're not\n"
	.string "permitted to have any balls with you.\p"
	.string "We can't allow our training\n"
	.string "pokémon to be captured. $"
	
TC_FacePlayer:
	face_right
	step_end

TC_WalkOut:
    walk_down
	walk_down
	step_end
	
TC_WalkIn:
	walk_up
	walk_up
	walk_up
	step_end

TC_Reentry:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


@==================================================================================================TC Tutor
	
TC_Tutorial::
	lock
	faceplayer
	msgbox TC_Tut_Query MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if 1, TC_Tut_Text
	closemessage
	release
	end

TC_Tut_Text::
	msgbox TC_TutorialText MSGBOX_DEFAULT
	release
	end

TC_Tut_Query:
	.string "Guide: Hi there, trainer.  Would you\p"
	.string "like a guide on how to use this place?$"
	
TC_TutorialText:
	.string "Inside this room you will find 6 dittos.\p"
	.string "each one will transform into a pokémon\n"
	.string "suitable for the kind of Evolution Value\p"
	.string "you're trying to get.\n"
	.string "They are ordered left to right respectively:\p"
	.string "HP, Attack, Defense, Special Attack, Special\n"
	.string "Defense, Speed.\p"
	.string "I recommend you have your pokémon to be\n"
	.string "trained holding a Macho Brace. Which you\p"
	.string "can get from the Winstrates on Route 111.\n"
	.string "Have fun training!$"
	
TC_Drugstore::
	lock
	message TC_Drugs_Txt
	waitmessage
	pokemart TC_Drugs_Mart
	msgbox TC_Drugs_Exit_Txt MSGBOX_DEFAULT
	release
	end
	
	@.align 2
TC_Drugs_Mart:
	.2byte ITEM_HP_UP
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_CARBOS
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_PP_UP
	.2byte ITEM_PP_MAX
	.2byte ITEM_NONE
	release
	end
	
TC_Drugs_Txt:
	.string "Get your drugs here to boost\n"
	.string "performance or your money back!$"

TC_Drugs_Exit_Txt:
	.string "Thanks for shopping with us!$"
	
TC_Imprint_Shop::
	checkitem ITEM_IMPRINTER, 1
	compare VAR_RESULT, 1
	goto_if_ne TC_StatShopGiveImprinter
	msgbox TC_Imprint_Txt MSGBOX_DEFAULT
	pokemart TC_Imprint_Mart
	release
	end
	
TC_StatShopGiveImprinter::
	msgbox BuyImprinter MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne TC_StatShopNoBuyImprinter
	checkmoney 65000
	compare VAR_RESULT, 0
	goto_if_eq TC_StatShopCantAffordImprinter
	takemoney 65000
	additem ITEM_IMPRINTER
	msgbox TC_BoughtImprinter MSGBOX_DEFAULT
	waitmessage
	closemessage
	goto TC_Imprint_Shop
	
BuyImprinter:
	.string "In order to use these items,\nyou must have an Imprinter.\pWould you like to buy an Imprinter\nfor ¥65000?$"
	
TC_StatShopNoBuyImprinter::
	msgbox TC_DidntBuyImprinter MSGBOX_DEFAULT
	release
	end
	
TC_DidntBuyImprinter:
	.string "Come speak with me if you change\nyour mind!$"
	
TC_StatShopCantAffordImprinter::
	msgbox TC_CantaffordImprinterMsg MSGBOX_DEFAULT
	release
	end
	
TC_CantaffordImprinterMsg:
	.string "You can't afford the Imprinter.\nYou need ¥65000 to buy it.$"
	
TC_BoughtImprinter:
	.string "Enjoy your Imprinter!$"
	
	@.align 2
TC_Imprint_Mart:
	.2byte ITEM_WAVE_MAIL
	.2byte ITEM_BEAD_MAIL
	.2byte ITEM_SHADOW_MAIL
	.2byte ITEM_TROPIC_MAIL
	.2byte ITEM_DREAM_MAIL
	.2byte ITEM_FAB_MAIL
	.2byte ITEM_NONE
	
TC_Imprint_Txt:
	.string "Hi! Welcome to the imprint shop.\p"
	.string "Customize your Pokémon's stats\n"
	.string "with these special items.$"
	
TC_Tutor::
	lockall
	faceplayer
	goto_if_set FLAG_RYU_NUZLOCKEMODE, RyuTCDisabledNuzlocke
	goto_if_set FLAG_RYU_HARDCORE_MODE, RyuTCDisabledHardcore
	msgbox TC_TutorWelcome MSGBOX_DEFAULT
	msgbox TC_TutorQuery MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne TC_Tutor_Cancel
	goto TC_SelectSlot

RyuTCDisabledHardcore::
	msgbox TC_TutDisabled
	release
	end

TC_TutDisabled:
	.string "Sorry, but you cannot use this\nservice due to gamemode restrictions.$"
	
TC_SelectSlot::
	msgbox TC_WhichSlot MSGBOX_DEFAULT
	multichoicedefault 1, 1, 118, 0, 0
	switch VAR_RESULT
	case 0, TC_Slot1Selected
	case 1, TC_Slot2Selected
	case 2, TC_Slot3Selected
	case 3, TC_Slot4Selected
	case 4, TC_Slot5Selected
	case 5, TC_Slot6Selected
	case 127, TC_CancelPartySlot
	releaseall
	end
	
TC_Slot1Selected::
	setvar VAR_TEMP_1, 0
	bufferpartymonnick 1, 0
	goto TC_MoveSlotMenu
	
TC_Slot2Selected::
	getpartysize
	compare VAR_RESULT, 2
	goto_if_lt TC_SlotSelectEmpty
	setvar VAR_TEMP_1, 1
	bufferpartymonnick 1, 1
	goto TC_MoveSlotMenu
	
TC_Slot3Selected::
	getpartysize
	compare VAR_RESULT, 3
	goto_if_lt TC_SlotSelectEmpty
	setvar VAR_TEMP_1, 2
	bufferpartymonnick 1, 2
	goto TC_MoveSlotMenu
	
TC_Slot4Selected::
	getpartysize
	compare VAR_RESULT, 4
	goto_if_lt TC_SlotSelectEmpty
	setvar VAR_TEMP_1, 3
	bufferpartymonnick 1, 3
	goto TC_MoveSlotMenu
	
TC_Slot5Selected::
	getpartysize
	compare VAR_RESULT, 5
	goto_if_lt TC_SlotSelectEmpty
	setvar VAR_TEMP_1, 4
	bufferpartymonnick 1, 4
	goto TC_MoveSlotMenu
	
TC_Slot6Selected::
	getpartysize
	compare VAR_RESULT, 6
	goto_if_lt TC_SlotSelectEmpty
	setvar VAR_TEMP_1, 5
	bufferpartymonnick 1, 5
	goto TC_MoveSlotMenu
	
TC_SlotSelectEmpty::
	msgbox TC_SelectAnotherSlot MSGBOX_DEFAULT
	goto TC_SelectSlot
	
TC_MoveSlotMenu::
	msgbox TC_MoveSlotMenuIntro MSGBOX_DEFAULT
	multichoicedefault 1, 1, 119, 4, 0
	switch VAR_RESULT
	case 0, TC_MoveSlot0 
	case 1, TC_MoveSlot1 
	case 2, TC_MoveSlot2 
	case 3, TC_MoveSlot3 
	case 4, TC_CancelMoveSlot
	case 127, TC_CancelMoveSlot
	
TC_MoveSlot0::
	setvar VAR_TEMP_2, 0
	goto TC_AttackMenu
	
TC_MoveSlot1::
	setvar VAR_TEMP_2, 1
	goto TC_AttackMenu
	
TC_MoveSlot2::
	setvar VAR_TEMP_2, 2
	goto TC_AttackMenu
	
TC_MoveSlot3::
	setvar VAR_TEMP_2, 3
	goto TC_AttackMenu
	
TC_AttackMenu::
	msgbox TC_AttacksMenuIntro MSGBOX_DEFAULT
	closemessage
	multichoicegrid 0, 0, 120, 3, 0
	switch VAR_RESULT
	case 0, TC_AM_DarkPulse
	case 1, TC_AM_Scald
	case 2, TC_AM_DragonPulse
	case 3, TC_AM_DrainPunch
	case 4, TC_AM_StoneEdge
	case 5, TC_AM_RockSlide
	case 6, TC_AM_Avalanche
	case 7, TC_AM_ThunderWave
	case 8, TC_AM_GigaImpact
	case 9, TC_AM_SilverWind
	case 10, TC_AM_Brine
	case 11, TC_AM_FlashCannon
	case 12, TC_AM_EnergyBall
	case 13, TC_AM_SignalBeam
	case 14, TC_AM_SeedBomb
	case 15, TC_AM_SuperPower
	case 16, TC_AM_EarthPower
	case 17, TC_AM_NastyPlot
	case 18, TC_AM_FocusBlast
	case 19, TC_AM_SwordsDance
	case 20, TC_AttackMenuExit 
	case 127, TC_AttackMenuExit
	
TC_AM_DarkPulse::
	setvar VAR_TEMP_3, MOVE_DARK_PULSE
	goto TC_TeachMoveQuery
	
TC_AM_Scald::
	setvar VAR_TEMP_3, MOVE_SCALD
	goto TC_TeachMoveQuery
	
TC_AM_DragonPulse::
	setvar VAR_TEMP_3, MOVE_DRAGON_PULSE
	goto TC_TeachMoveQuery
	
TC_AM_DrainPunch::
	setvar VAR_TEMP_3, MOVE_DRAIN_PUNCH
	goto TC_TeachMoveQuery
	
TC_AM_StoneEdge::
	setvar VAR_TEMP_3, MOVE_STONE_EDGE
	goto TC_TeachMoveQuery
	
TC_AM_RockSlide::
	setvar VAR_TEMP_3, MOVE_ROCK_SLIDE
	goto TC_TeachMoveQuery
	
TC_AM_Avalanche::
	setvar VAR_TEMP_3, MOVE_AVALANCHE
	goto TC_TeachMoveQuery

TC_AM_ThunderWave::
	setvar VAR_TEMP_3, MOVE_THUNDER_WAVE
	goto TC_TeachMoveQuery
	
TC_AM_GigaImpact::
	setvar VAR_TEMP_3, MOVE_GIGA_IMPACT
	goto TC_TeachMoveQuery
	
TC_AM_SilverWind::
	setvar VAR_TEMP_3, MOVE_SILVER_WIND
	goto TC_TeachMoveQuery
	
TC_AM_Brine::
	setvar VAR_TEMP_3, MOVE_BRINE
	goto TC_TeachMoveQuery
	
TC_AM_FlashCannon::
	setvar VAR_TEMP_3, MOVE_FLASH_CANNON
	goto TC_TeachMoveQuery

TC_AM_EnergyBall::
	setvar VAR_TEMP_3, MOVE_ENERGY_BALL
	goto TC_TeachMoveQuery
	
TC_AM_SignalBeam::
	setvar VAR_TEMP_3, MOVE_SIGNAL_BEAM
	goto TC_TeachMoveQuery
	
TC_AM_SeedBomb::
	setvar VAR_TEMP_3, MOVE_SEED_BOMB
	goto TC_TeachMoveQuery

TC_AM_SuperPower::
	setvar VAR_TEMP_3, MOVE_SUPERPOWER
	goto TC_TeachMoveQuery
	
TC_AM_EarthPower::
	setvar VAR_TEMP_3, MOVE_EARTH_POWER
	goto TC_TeachMoveQuery

TC_AM_NastyPlot::
	setvar VAR_TEMP_3, MOVE_NASTY_PLOT
	goto TC_TeachMoveQuery

TC_AM_FocusBlast::
	setvar VAR_TEMP_3, MOVE_FOCUS_BLAST
	goto TC_TeachMoveQuery

TC_AM_SwordsDance::
	setvar VAR_TEMP_3, MOVE_SWORDS_DANCE
	goto TC_TeachMoveQuery

TC_TeachMoveQuery::
	msgbox TC_TeachMoveConfirm MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_ne TC_ConfirmExit
	checkitem ITEM_RETRO_MAIL, 1
	compare VAR_RESULT, 1
	call_if_ge TC_VoucherUse
	setvar VAR_TEMP_5, 50000
	checkmoney VAR_TEMP_5
	compare VAR_RESULT, 0
	goto_if_eq TC_MoveCancelledBroke
	takemoney VAR_TEMP_5
	special RyuSetMonMove
	msgbox TC_PkmnLearnedMove MSGBOX_DEFAULT
	release
	end

TC_VoucherUse::
	msgbox TC_VoucherUseConfirm MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq TC_TeachMoveQueryVoucher
	return
	
TC_TeachMoveQueryVoucher::
	removeitem ITEM_RETRO_MAIL, 1
	special RyuSetMonMove
	msgbox TC_PkmnLearnedMove MSGBOX_DEFAULT
	release
	end
	
TC_MoveCancelledBroke::
	msgbox TC_TUTOR_BROKE MSGBOX_DEFAULT
	release
	end
	
TC_TUTOR_BROKE:
	.string "You can't afford tutoring, sorry!$"

TC_ConfirmExit:
	msgbox TC_ConfirmSelectionExit MSGBOX_DEFAULT
	release
	end
	
TC_AttackMenuExit::
	msgbox TC_CancelledFromAttackMenu MSGBOX_DEFAULT
	release
	end
	
TC_CancelMoveSlot::
	msgbox TC_CancelledFromMoveSlot MSGBOX_DEFAULT
	release
	end
	
TC_CancelPartySlot::
	msgbox TC_CancelledFromPartySlot MSGBOX_DEFAULT
	release
	end

TC_Tutor_Cancel::
	msgbox TC_CancelledFromTutorQuery MSGBOX_DEFAULT
	release
	end
	
TC_VoucherUseConfirm:
	.string "You appear to have a Tutor Voucher.\pWould you like to use one\ninstead of paying?$"
	
TC_PkmnLearnedMove:
	.string "Success! It learned the move!$"
	
TC_ConfirmSelectionExit:
	.string "Okay, I'll leave its moves untouched.$"
	
TC_TutorWelcome:
	.string "Hi there. I'm a special move tutor.\p"
	.string "I can teach certain moves to any\n"
	.string "pokémon for ¥50000.$"
	
TC_CancelledFromTutorQuery:
	.string "Okay, come back when you have\n"
	.string "enough money!$"
	
TC_TutorQuery:
	.string "Would you like for me to teach a pokémon\n"
	.string "a special move?$"
	
TC_WhichSlot:
	.string "Which of your party pokémon should I\n"
	.string "teach a move to?$"
	
TC_SelectAnotherSlot:
	.string "That slot is empty, Select another!$"
	
TC_MoveSlotMenuIntro:
	.string "Which battle move slot should this move\n"
	.string "replace?$"
	
TC_CancelledFromPartySlot:
	.string "Very well. You know where to find me\n"
	.string "if you change your mind.$"
	
TC_CancelledFromMoveSlot:
	.string "All right, Let me know if you change your\n"
	.string "mind!$"
	
TC_AttacksMenuIntro:
	.string "Which attack would you like to teach?$"
	
TC_CancelledFromAttackMenu:
	.string "Very well. Chat with me if you change\n"
	.string "your mind.$"
	
TC_TeachMoveConfirm:
	.string "Are you sure you want to do this?\n"
	.string "It can't be undone by me if you do!$"

@==================================================================================================Actual Training

TC_HPEV::
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	setwildbattle SPECIES_NIDOQUEEN, VAR_RESULT, ITEM_NONE
	playmoncry SPECIES_NIDOQUEEN, 0
	bufferspeciesname 0, SPECIES_NIDOQUEEN
	waitmoncry
	msgbox TCEVMsg
	closemessage
	dowildbattle
	release
	end

TCEVMsg:
	.string "It morphed into {STR_VAR_1}!$"

TC_AtkEV::
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	setwildbattle SPECIES_MACHAMP, VAR_RESULT, ITEM_NONE
	playmoncry SPECIES_MACHAMP, 0
	bufferspeciesname 0, SPECIES_MACHAMP
	waitmoncry
	msgbox TCEVMsg
	closemessage
	dowildbattle
	release
	end

TC_DefEV::
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	setwildbattle SPECIES_POLIWRATH, VAR_RESULT, ITEM_NONE
	playmoncry SPECIES_POLIWRATH, 0
	bufferspeciesname 0, SPECIES_POLIWRATH
	waitmoncry
	msgbox TCEVMsg
	closemessage
	dowildbattle
	release
	end

TC_SpcAtkEV::
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	setwildbattle SPECIES_CHARIZARD, VAR_RESULT, ITEM_NONE
	playmoncry SPECIES_CHARIZARD, 0
	bufferspeciesname 0, SPECIES_CHARIZARD
	waitmoncry
	msgbox TCEVMsg
	closemessage
	dowildbattle
	release
	end

TC_SpdefEV::
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	setwildbattle SPECIES_MEGANIUM, VAR_RESULT, ITEM_NONE
	playmoncry SPECIES_MEGANIUM, 0
	bufferspeciesname 0, SPECIES_MEGANIUM
	waitmoncry
	msgbox TCEVMsg
	closemessage
	dowildbattle
	release
	end

TC_SpeedEV::
	special checkbadgecount
	multvar VAR_RESULT, 10
	compare VAR_RESULT, 10
	call_if_lt TC_NoBadge
	setwildbattle SPECIES_RAICHU, VAR_RESULT, ITEM_NONE
	playmoncry SPECIES_RAICHU, 0
	bufferspeciesname 0, SPECIES_RAICHU
	waitmoncry
	msgbox TCEVMsg
	closemessage
	dowildbattle
	release
	end

TC_NoBadge::
	addvar VAR_RESULT, 5
	return
