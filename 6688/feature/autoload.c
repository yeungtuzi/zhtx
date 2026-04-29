// autoload.c

string *autoload;

void clean_up_autoload() { autoload = 0; }

void save_autoload()
{
	object *inv;
	int i, j;
	mixed param;

	inv = all_inventory();
	autoload = allocate(sizeof(inv));
	for(i=0, j=0; i<sizeof(inv); i++) {
		if( !(param = inv[i]->query_autoload()) ) continue;
		autoload[j] = base_name(inv[i]);
		if( stringp(param) ) autoload[j] += ":" + param;
		j++;
	}
	autoload = autoload[0..j-1];
}

void restore_autoload()
{
	int i;
	object ob,me;
	string file, param, err, *equip_name;
	mapping equip;   

	if( !pointerp(autoload) ) return;
	me = this_object();

	for(i=0; i<sizeof(autoload); i++) {
		if( sscanf(autoload[i], "%s:%s", file, param)!=2 ) {
			file = autoload[i];
			param = 0;
		}
		err = catch(ob = new(file));
		if( err || !ob ) {
			write("你觉得似乎失落了什麽重要的东西，最好通知一下巫师。\n");
			log_file("AUTOLOAD", sprintf("Fail to autoload %s of %s, error %s\n",
				file, this_object()->query("name"), err));
			continue;
		}
		export_uid(ob);
		ob->move(this_object());
		ob->autoload(param);
	}
	clean_up_autoload();		// To save memory.
	//恢复玩家自定义的兵器装备。
	// by YEUNG
	if( mapp(equip = me->query("custom_weapon")) && (i=sizeof(equip_name=keys(equip))) )
	{
		while( i-- )
		{
			if( !mapp(equip[equip_name[i]]) )
				continue;
			file = USER_WEAP_DIR + "c_" + equip_name[i] + ".c";
			err = catch(ob = new(file));
			if( err || !ob ) 
			{
				write("你觉得似乎失落了什麽重要的东西，最好通知一下巫师。\n");
				log_file("AUTOLOAD", sprintf("Fail to autoload %s of %s, error %s\n",
					file, this_object()->query("name"), err));
				continue;
			}                                              
			export_uid(ob);
			ob->move(me);
			ob->init_weapon(me->query("id"),equip[equip_name[i]]["name"],equip[equip_name[i]]["id"],
					equip[equip_name[i]]["long"],equip_name[i],equip[equip_name[i]]["damage"],
					equip[equip_name[i]]["attack"],equip[equip_name[i]]["dodge"],
					equip[equip_name[i]]["parry"],equip[equip_name[i]]["defense"]
			);
			
		}
				
	}	

	//恢复玩家自定义的衣服。
	// by YEUNG
	if( mapp(equip = me->query("custom_cloth")) && (i=sizeof(equip_name=keys(equip))) )
	{
		while( i-- )
		{
			if( !mapp(equip[equip_name[i]]) )
				continue;
			file = USER_CLOTH_DIR + "cloth.c";
			err = catch(ob = new(file));
			if( err || !ob ) 
			{
				write("你觉得似乎失落了什麽重要的东西，最好通知一下巫师。\n");
				log_file("AUTOLOAD", sprintf("Fail to autoload %s of %s, error %s\n",
					file, this_object()->query("name"), err));
				continue;
			}                                              
			export_uid(ob);
			ob->move(me);
			ob->init_cloth(me->query("id"),equip[equip_name[i]]["name"],equip[equip_name[i]]["id"],
					equip[equip_name[i]]["long"],equip_name[i],equip[equip_name[i]]["armor"],
					equip[equip_name[i]]["attack"],equip[equip_name[i]]["dodge"],
					equip[equip_name[i]]["parry"],equip[equip_name[i]]["defense"]
			);
			
		}
				
	}	
	
	
}
