



void CreateParticles(ref Location)
{
	aref locator_group;
	aref locator;
	int n;
	int num;

	string loctrName;
	
	// DumpAttributes(Location);


	if(!CheckAttribute(Location, "locators")) return;
	int pId; string tmpId;

	if(CheckAttribute(Location, "locators.smoke"))
	{
		makearef(locator_group, location.locators.smoke);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);

		//JRH -->
			if(Location.id=="wr_port" || Location.id=="Fort_Moultrie_shore" || Location.id=="Sullivan_jungle1" || Location.id=="Legrands_backyard"
			|| Location.id=="Legrands_kitchen" || Location.id=="Fort_Moultrie_village" || Location.id=="Fort_Moultrie_exit" || Location.id=="GB_chinese_nitre"
			|| Location.id=="Bessop_plantation" || Location.id=="Oranjestad_port" || Location.id=="Oranjestad_store_02" || Location.id=="BB_graveyard"
			|| Location.id=="BB_isle" || Location.id=="Kristiania_jungle_house" || Location.id=="KR_jungle_9" || Location.id=="wr_church_outside"
			|| Location.id=="BB_QAR_deck" || Location.id=="BB_QAR_cabin" || Location.id=="BB_Eden_estate" || Location.id=="BB_Eden_maze"
			|| Location.id=="BB_careen_shore" || Location.id=="BB_burning_cave")
			{
				CreateParticleSystem("smoke",stf(locator.x),stf(locator.y),stf(locator.z),-1.57,0,0,0);
			}
			else
			{
				if(frnd() < 0.3 )
				{
					pId = CreateParticleSystem("smoke",stf(locator.x),stf(locator.y),stf(locator.z),-1.57,0,0,0);
					tmpId = "pId"+n;
					location.locators.smoke.(tmpId) = pId;
				}
			}
		//JRH <--
			
		}
	}

//JRH -->
	if(CheckAttribute(Location, "locators.smoke_on"))
	{
		makearef(locator_group, location.locators.smoke_on);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("smoke",stf(locator.x),stf(locator.y),stf(locator.z),-1.57,0,0,0);	
		}
//JRH <--
	}

	if(CheckAttribute(Location, "locators.smoke_day"))
	{
		makearef(locator_group, location.locators.smoke_day);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			if(IsDay()) CreateParticleSystem("smoke",stf(locator.x),stf(locator.y),stf(locator.z),-1.57,0,0,0);	
		}
//JRH <--
	}

    //JRH -->
 	if(CheckAttribute(Location, "locators.blacksmoke"))
	{
		makearef(locator_group, location.locators.blacksmoke);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("smoke_inv",stf(locator.x),stf(locator.y),stf(locator.z),-1.57,0,0,0);
		}
	}
    //JRH <--

	if(CheckAttribute(Location, "locators.fire"))
	{
		makearef(locator_group, location.locators.fire);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			loctrName = GetAttributeName(locator);
			if(!CheckAttribute(Location, "locators.fire."+loctrName+".tmpLocator"))//MAXIMUS
			{
				if(CheckAttribute(locator,"x") && CheckAttribute(locator,"y") && CheckAttribute(locator,"z"))
				{
					if(Location.id=="Tortuga_port" || Location.id=="GB_Chinatown")		//JRH
					{
						if (makeint(environment.time) >= 20.0 || makeint(environment.time) < 8.0)
						{
							pId = CreateParticleSystem("fire", stf(locator.x), stf(locator.y), stf(locator.z),-1.57,0,0,0);
							tmpId = "pId"+n;
							location.locators.fire.(tmpId) = pId;
						}
					}
					else
					{
						pId = CreateParticleSystem("fire", stf(locator.x), stf(locator.y), stf(locator.z),-1.57,0,0,0);
						tmpId = "pId"+n;
						location.locators.fire.(tmpId) = pId;
					}
				}
			}
		}
	}

	//JRH -->
	if(CheckAttribute(Location, "locators.wreck_fire"))
	{
		makearef(locator_group, location.locators.wreck_fire);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			loctrName = GetAttributeName(locator);
			if(!CheckAttribute(Location, "locators.wreck_fire."+loctrName+".tmpLocator"))//MAXIMUS
			{
				if(CheckAttribute(locator,"x") && CheckAttribute(locator,"y") && CheckAttribute(locator,"z"))
				{
					pId = CreateParticleSystem("fort_fire_flames", stf(locator.x), stf(locator.y), stf(locator.z),-1.57,0,0,0);
					pId = CreateParticleSystem("fort_gray_smoke", stf(locator.x), stf(locator.y), stf(locator.z),-1.57,0,0,0);
					pId = CreateParticleSystem("fort_gray_smoke", stf(locator.x), stf(locator.y) + 2.0, stf(locator.z),-1.57,0,0,0);
					tmpId = "pId"+n;
					location.locators.fire.(tmpId) = pId;
				}
			}
		}
	}
        //JRH <--

	if(CheckAttribute(Location, "locators.heaters_p"))
	{
		makearef(locator_group, location.locators.heaters_p);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("fire",stf(locator.x),stf(locator.y),stf(locator.z),-1.57,0,0,0);
		}
	}


/*	if(CheckAttribute(Location, "locators.waterfall"))
	{
		makearef(locator_group, location.locators.waterfall);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystemX("waterfall",stf(locator.x),stf(locator.y),stf(locator.z),
				stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);
		}
	}
*/

	// Swindler 2006-07-10 -->
	// Commented out below if-condition because second part is senseless. Either
	// Location has fire-locators, then first part is enough, or it has not.
	// Even if second part evaluates to true and location has no fire-locators,
	// first line in if-block would cause error.
	/*if (CheckAttribute(Location, "locators.fire") || Location.id.label == "Boarding deck"))*/
/*	if(CheckAttribute(Location, "locators.fire"))// Swindler <--
	{
		makearef(locator_group, location.locators.fire);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			loctrName = GetAttributeName(locator);
			if(!CheckAttribute(Location, "locators.fire."+loctrName+".tmpLocator"))//MAXIMUS
			{
				if(CheckAttribute(locator,"x") && CheckAttribute(locator,"y") && CheckAttribute(locator,"z"))
				{
					pId = CreateParticleSystem("fire_mix", stf(locator.x), stf(locator.y), stf(locator.z),-1.57,0,0,0);
					tmpId = "pId"+n;
					location.locators.fire.(tmpId) = pId;
				}
			}
		}
	}*/

	if(CheckAttribute(Location, "locators.candles_p"))
	{
		makearef(locator_group, location.locators.candles_p);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("candle",stf(locator.x),stf(locator.y) + 0.04,stf(locator.z),-1.57,0,0,0);
		}
	}

	if(CheckAttribute(Location, "locators.torchlightes_p"))
	{
		makearef(locator_group, location.locators.torchlightes_p);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("torch",stf(locator.x),stf(locator.y) - 0.07,stf(locator.z),-1.57,0,0,0);
		}
	}

	if(CheckAttribute(Location, "locators.torchlightes_o_p") && Whr_IsLight() != 0)
	{
		makearef(locator_group, location.locators.torchlightes_o_p);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("torch",stf(locator.x),stf(locator.y) - 0.07,stf(locator.z),-1.57,0,0,0);
		}
	}

/*
	if(CheckAttribute(Location, "locators.reload"))
	{
		makearef(locator_group, location.locators.reload);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("fire_mix",stf(locator.x),stf(locator.y),stf(locator.z),-1.57,0,0,0);
		}
	}
*/
// ccc Nov05 Greater Oxbay crypt effects
	if(Location.id=="Greenford_M_crypt" && CheckAttribute(Location, "locators.monsters")) // PB
	{
		makearef(locator_group, location.locators.monsters);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystem("fountain",stf(locator.x),stf(locator.y),stf(locator.z),-1.57,0,0,0);
			if(USE_PARTICLES>1) CreateParticleSystem("fire_mix",stf(locator.x),stf(locator.y)+1.2,stf(locator.z),-1.57,0,0,0);	// ccc Dec05 tweak added
		}
	}

	if(Location.id=="Greenford_M_crypt" && CheckAttribute(Location, "locators.goto")) // PB
	{
		makearef(locator_group, location.locators.goto);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			If(USE_PARTICLES>0) CreateParticleSystemX("stars",stf(locator.x),stf(locator.y)+2,stf(locator.z),
				stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);	// ccc Dec05 tweak added
			CreateParticleSystemX("waterfog",stf(locator.x),stf(locator.y),stf(locator.z),
				stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);
		}
	}
// ccc end

	if(CheckAttribute(Location, "locators.Waterfog"))
	{
		makearef(locator_group, location.locators.waterfog);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystemX("waterfog",stf(locator.x),stf(locator.y),stf(locator.z),
				stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);
		}
	}

	//JRH
	if(CheckAttribute(Location, "locators.Waterfog_light"))
	{
		makearef(locator_group, location.locators.waterfog_light);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystemX("waterfog_light",stf(locator.x),stf(locator.y),stf(locator.z),
				stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);
		}
	}

	if(CheckAttribute(Location, "locators.Waterfogfall"))
	{
		makearef(locator_group, location.locators.waterfogfall);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystemX("waterfog_fall",stf(locator.x),stf(locator.y),stf(locator.z),
				stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);
		}
	}

	if(CheckAttribute(Location, "locators.stars"))
	{
		makearef(locator_group, location.locators.stars);
		num = GetAttributesNum(locator_group);
		for(n = 0; n < num; n++)
		{
			locator = GetAttributeN(locator_group, n);
			CreateParticleSystemX("stars",stf(locator.x),stf(locator.y),stf(locator.z),
				stf(locator.vz.x),stf(locator.vz.y),stf(locator.vz.z),0);
		}
	}

	Particles.winddirection.y = 0;
}


