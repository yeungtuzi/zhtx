// updated.c
#include <ansi.h>

void create() { seteuid(getuid()); }

int load_adv_equips(object ob)
{
	string m, *pkey,*qkey;
	mapping my,equips,*equip;
	int i,j,amount,bug;                                       	
	object end_room,equip_obj;
	string *file1,file;
	
	if((!ob->query_temp("loaded_adv_equip"))&&(equips=ob->query("adv_equips")))
	{
		pkey=keys(equips);
		ob->set_temp("loaded_adv_equip",1);
		for(i=0;i<sizeof(pkey);i++)
		{
			equip=equips[pkey[i]];
			file1=explode(pkey[i],"#");
			file=file1[0];
			if(file_size(file+".c")>0)
			{
				equip_obj=new(file);
				bug=equip_obj->reload_props(equip);
				equip_obj->move(ob);			
				if(bug) tell_object(ob,HIY"你的装备"+equip_obj->query("name")+HIY"出了bug，现在调整到合适值！\n"NOR);
			}
			else map_delete(equips,pkey[i]);
		}
	}
	return 1;
}

void check_user(object ob)
{
        // 2026-04-30: unused variable commented out
        // mapping custom_ob;
        // 2026-04-30: unused variable commented out
        // string *custom_ob_key;
        // 2026-04-30: unused variable commented out
        // int key_size;

        // 2026-04-30: unused variable commented out
        // int v1, v2;
        string m;
        mapping my;
        //check bug-gained money
/*
        if( ob->query("marks/check_money_bug")  < 101 )
        {
               if( ob->query("deposit") > 1000000 ) ob->set("deposit",1000000);
                ob->set("marks/check_money_bug",101);
                tell_object(ob,"\nWe are sorry to clear everyone's deposit now cause a
 fatal bug of our MUD game.\n
We have no other choice and we appoligize for our mistake.\n
                        the ZHII wizard team. 2000/11/12\n");
                ob->delete("autoload");
                if( mapp(custom_ob = ob->query("custom_weapon")) && 
arrayp(custom_ob_key=keys(custom_ob)) && 
(key_size=sizeof(custom_ob_key))>0 )
                {
                        while(key_size--)
                        {
                                if(mapp(custom_ob[custom_ob_key[key_size]]) &&  
custom_ob[custom_ob_key[key_size]]["damage"] > 50 )
                                custom_ob[custom_ob_key[key_size]]["damage"] = 50;
                        }                       
                }
                ob->save(1);                       
                tell_object("\nDone, please login again now.\n");
                destruct(ob);

                ob->save(1);
        }
*/
        my = ob->query_entire_dbase();
        if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
        if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
        if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];
        if( my["eff_gin"] > my["max_gin"] ) my["eff_gin"] = my["max_gin"];
        if( my["eff_kee"] > my["max_kee"] ) my["eff_kee"] = my["max_kee"];
        if( my["eff_sen"] > my["max_sen"] ) my["eff_sen"] = my["max_sen"];
        if( my["gin"] > my["eff_gin"] ) my["gin"] = my["eff_gin"];
        if( my["kee"] > my["eff_kee"] ) my["kee"] = my["eff_kee"];
        if( my["sen"] > my["eff_sen"] ) my["sen"] = my["eff_sen"];

            if( my["potential"]<0) my["potential"]=0;
        if( my["max_age"])
        // 寿命到了
        if( my["age"] > my["max_age"] )
        {
                tell_object(ob,"你突然觉得一阵头晕目眩，眼前似乎出现了玫瑰色的光环，笼罩着一切。\n");
                tell_object(ob,"你觉得光线耀眼，气息有些不畅，不由闭上了眼睛，等睁开双眼的时候，发现...\n\n");
                ob->move("/adm/npc/room/end");
        }       
        load_adv_equips(ob);
	if( my["mana_factor"] > 41 )
		my["mana_factor"] = 41;

}
