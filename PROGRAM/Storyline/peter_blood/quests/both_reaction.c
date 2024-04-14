void BothQuestComplete(string sQuestName)
{
ref sld, npchar, sld1;
aref arOldMapPos, arAll, arPass;
int iTemp, i, ShipType, Rank, iChar, SiegeShips, hcrew, iSpace1, iSpace2, n;
float locx, locy, locz, fTemp;
string attrName, Model, Blade, Gun, sTemp, Ship;
bool bOk;
int idxLoadLoc;
int iOfficer;
PChar = GetMainCharacter();
switch(sQuestName)
{
case "Blood0":
sld = characterFromID("Beyns");
ChangeCharacterAddressGroup(sld, "Estate", "goto", "goto12");
GiveItem2Character(pchar, "medical1");
GiveItem2Character(pchar, "medical1");
GiveItem2Character(pchar, "medical1");
pchar.quest.Blood0.win_condition.l1 = "location";
pchar.quest.Blood0.win_condition.l1.location = "EstateLordBedRoom";
pchar.quest.Blood0.win_condition = "Blood1";
break;
case "Blood1":
sld = characterFromID("LordEstate");
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorRunToLocator(pchar, "quest", "quest1", "Blood2", -1);
break;
case "Blood2":
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorTurnToLocator(Pchar, "reload", "reload1");
sld = characterFromID("Beyns");
ChangeCharacterAddressGroup(sld, "EstateLordBedRoom", "reload", "reload1");
sld.dialog.currentnode = "EBStep_1";
LAi_SetActorTypeNoGroup(sld);
LAi_SetStayTypeNoGroup(pchar);
LAi_ActorDialog(sld, pchar, "",  -1.0, 0);
break;
case "Blood3":
StartQuestMovie(true, true, true);
ChangeShowIntarface();
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorTurnToLocator(Pchar, "sit", "sit2");
sld = characterFromID("Beyns");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorGoToLocator(sld, "quest", "quest2", "Blood3_1", -1);
break;
case "Blood3_1":
sld = characterFromID("Beyns");
LAi_ActorAnimation(sld, "Barman_idle", "Blood3_2", -1);
break;
case "Blood3_2":
sld = characterFromID("Beyns");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorGoToLocator(sld, "reload", "reload1", "Blood3_2_1", -1);
break;
case "Blood3_2_1":
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorRunToLocator(pchar, "quest", "quest2", "Blood3_3", -1);
sld = characterFromID("Beyns");
LAi_ActorTurnToLocator(sld, "sit", "sit2");
break;
case "Blood3_3":
LAi_ActorAnimation(pchar, "Barman_idle", "Blood3_4", 5);
break;
case "Blood3_4":
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorRunToLocator(pchar, "quest", "quest3", "Blood4", -1);
break;
case "Blood4":
LAi_ActorTurnToLocator(Pchar, "sit", "sit2");
LAi_ActorAnimation(Pchar, "Barman_idle", "Blood5", 5);
break;
case "Blood5":
LAi_Fade("", "");
EndQuestMovie();
DoQuestCheckDelay("Blood6", 2.0);
break;
case "Blood6":
sld = characterFromID("Beyns");
sld.dialog.currentnode = "EBStep_2";
ChangeCharacterAddressGroup(sld, "EstateOffice", "goto", "goto6");
LAi_SetActorType(sld);
DoQuestReloadToLocation("EstateOffice", "goto", "goto3", "Blood7");
break;
case "Blood7":
LAi_SetStayTypeNoGroup(Pchar);
sld = characterFromID("Beyns");
Lai_ActorDialogNow(sld, Pchar, "",-1);
break;
case "Blood8":
sld = characterFromID("Pitt");
sld.dialog.currentnode = "PStep_5";
ChangeCharacterAddressGroup(sld, "EstateOffice", "reload", "reload1");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "",  -1.0, 0);
break;
case "Blood9":
LAi_SetPlayerType(PChar);
DoQuestReloadToLocation("Estate", "reload", "reload4", "Blood10");
n = FindLocation("Estate");
DeleteAttribute(&locations[n], "box1.items");
locations[n].box1 = Items_MakeTime(0, 0, 1, 2003);
locations[n].box1.items.blade2 = 1;
locations[n].box1.items.pistol1 = 1;
if (ENABLE_AMMOMOD)
{
locations[n].box1.items.gunpowder = 6;
locations[n].box1.items.pistolbullets = 6;
}
break;
case "Blood10":
chrDisableReloadToLocation = true;
pchar.quest.Blood10.win_condition.l1 = "item_equip";
pchar.quest.Blood10.win_condition.l1.item_equip = "blade2";
pchar.quest.Blood10.win_condition = "Blood10_weapon";
pchar.quest.Blood10B.win_condition.l1 = "item_equip";
pchar.quest.Blood10B.win_condition.l1.item_equip = "pistol1";
pchar.quest.Blood10B.win_condition = "Blood10_weapon";
break;
case "Blood10_weapon":
if(IsEquipCharacterByItem(pchar, "blade2") && IsEquipCharacterByItem(pchar,"pistol1"))
{
DoQuestCheckDelay("Blood11", 2.0);
}
break;
case "Blood11":
StartQuestMovie(true, true, true);
LAi_LocationFightDisable(loadedLocation, true);
LAi_SetFightMode(Pchar, false);
LAi_LockFightMode(pchar, true);
sld1 = characterFromID("CapGobart");
LAi_SetImmortal(sld1, true);
ChangeCharacterAddressGroup(sld1, "Estate", "goto", "goto1");
GiveItem2Character(sld1, "blade4");
EquipCharacterByItem(sld1, "blade4");
GiveItem2Character(sld1, "pistol2");
EquipCharacterByItem(sld1, "pistol2");
if (ENABLE_AMMOMOD)
{
TakeNItems(sld, "gunpowder", 6);
TakeNItems(sld, "pistolbullets", 6);
}
LAi_SetActorTypeNoGroup(sld1);
LAi_ActorRunToLocator(sld1, "goto", "goto12", "", 20);
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorRunToLocator(pchar, "goto", "goto8", "Blood12", -1);
locCameraFollow();
if (ENABLE_AMMOMOD)
{
TakeNItems(sld1, "gunpowder", 6);
TakeNItems(sld1, "pistolbullets", 6);
}
for (i=1; i<=5; i++)
{
sld = characterFromID("Dragun_"+i);
LAi_SetImmortal(sld, true);
GiveItem2Character(sld, "blade4");
EquipCharacterByItem(sld, "blade4");
GiveItem2Character(sld, "pistol2");
EquipCharacterByItem(sld, "pistol2");
if (ENABLE_AMMOMOD)
{
TakeNItems(sld, "gunpowder", 6);
TakeNItems(sld, "pistolbullets", 6);
}
ChangeCharacterAddressGroup(sld, "Estate", "goto", "goto1");
LAi_SetActorTypeNoGroup(sld);
if(i == 4 || i == 5)
{
LAi_ActorRunToLocator(sld, "reload", "reload"+i, "", 20);
}
else
{
LAi_ActorRunToLocator(sld, "goto", "goto12", "", 20);
}
}
DoQuestCheckDelay("Blood13", 1.0);
break;
case "Blood12":
LAi_SetActorTypeNoGroup(pchar);
LAi_ActorTurnToLocator(Pchar, "goto", "goto12");
LAi_SetStayTypeNoGroup(pchar);
sld = characterFromID("CapGobart");
LAi_SetActorTypeNoGroup(sld);
LAi_ActorDialog(sld, pchar, "", 7, 0);
break;
case "Blood13":
LAi_LockFightMode(pchar, false);
LAi_LocationFightDisable(loadedLocation, false);
sld = characterFromID("Pitt");
ChangeCharacterAddressGroup(sld, "Estate", "reload", "reload5");
LAi_SetActorType(sld);
LAi_ActorGoToLocator(sld, "goto", "goto7", "Blood13_P", -1);
sld1 = characterFromID("Beyns");
ChangeCharacterAddressGroup(sld1, "Estate", "reload", "reload4");
LAi_SetActorType(sld1);
LAi_ActorGoToLocator(sld1, "goto", "goto5", "Blood13_A", -1);
break;
case "Blood13_A":
sld = characterFromID("Beyns");
LAi_ActorTurnToLocator(sld, "goto", "goto12");
LAi_group_MoveCharacter(sld, "Estate");
break;
case "Blood13_P":
sld = characterFromID("Pitt");
LAi_ActorTurnToLocator(sld, "goto", "goto12");
LAi_group_MoveCharacter(sld, "Estate");
break;
case "Blood14":
EndQuestMovie();
LAi_SetPlayerType(pchar);
LAi_SetFightMode(Pchar, true);
sld = characterFromID("CapGobart");
LAi_SetCheckMinHP(sld, 1, true, "Blood15");
LAi_SetCheckMinHP(Pchar, 1, true, "Blood16");
LAi_SetImmortal(pchar, false);
LAi_SetImmortal(sld, false);
LAi_SetWarriorTypeNoGroup(sld);
LAi_group_MoveCharacter(sld, "EstateSold");
LAi_group_SetRelation("EstateSold", "Estate", LAI_GROUP_NEUTRAL);
LAi_group_FightGroups("EstateSold", LAI_GROUP_PLAYER, true);
for (i=1; i<=5; i++)
{
sld = characterFromID("Dragun_"+i);
LAi_SetImmortal(sld, false);
LAi_SetCheckMinHP(sld, LAi_GetCharacterHP(sld)-1, true, "Blood15");
LAi_ActorTurnToLocator(sld, "goto", "goto12");
}
break;
case "Blood15":
sld = characterFromID("CapGobart");
LAi_group_MoveCharacter(sld, "EstateSold2");
LAi_group_SetRelation("EstateSold2", "Estate", LAI_GROUP_NEUTRAL);
for (i=1; i<=5; i++)
{
sld = characterFromID("Dragun_"+i);
LAi_SetImmortal(sld, false);
LAi_SetWarriorTypeNoGroup(sld);
LAi_RemoveCheckMinHP(sld);
LAi_group_MoveCharacter(sld, "EstateSold2");
}
LAi_group_SetRelation("EstateSold2", LAI_GROUP_PLAYER, LAI_GROUP_ENEMY);
break;
case "Blood16":
LAi_RemoveCheckMinHP(characterFromID("CapGobart"));
LAi_group_FightGroups("EstateSold2", LAI_GROUP_PLAYER, false);
LAi_SetFightMode(Pchar, false);
LAi_LockFightMode(pchar, true);
for (i=1; i<=5; i++)
{
iChar = GetCharacterIndex("Dragun_"+i);
if(iChar != -1)
{
sld = characterFromID("Dragun_"+i);
LAi_SetFightMode(sld, false);
LAi_LockFightMode(sld, true);
}
}
sld = characterFromID("CapGobart");
LAi_SetFightMode(sld, false);
LAi_LockFightMode(sld, true);
SetCharacterTask_Dead(pchar);
break;
case "Blood17":
LAi_SetImmortal(pchar, false);
LAi_LockFightMode(pchar, false);
pchar.money = 100000000;
chrDisableReloadToLocation = false;
break;
}
}