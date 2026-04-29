// hashou.c  杀手
#include <condition.h>
#include <ansi.h>
#include <combat.h>


inherit NPC;

int waiting(object me);
int checking(object me);
int do_chase(object me);
int do_clone(object dest, object me);
int do_kill(object me, object dest);
string ask_me();
int consider();

void create()
{

    seteuid(getuid());

    set_name("吴一物", ({ "sha shou", "sha" }) );
    set("title", "血煞星");
    set("gender", "男性" );
    set("age", 40);
    set("str", 30);
    set("con", 30);
    set("int", 30);
    set("cor",40);
    set("cps",40);
    set("max_gin",300);
    set("max_sen",300);
    set("max_kee",300);
    set("no_clean_up",1);

    set("long","这是一个很不起眼的人物,很难想像竟是那闻之色变的 血煞星\n"
      "武功深不可测,最可怕的是  以其人之道,还治其人之身 .\n" );

    set("env/wimpy", 0);
    set("pills",3);

    set("chat_chance_combat", 80);
    set("chat_msg_combat", ({
	(: consider :),
	(: exert_function, "powerup" :),
	(: exert_function, "recover" :)
      }) );


    setup();

//            call_out("do_name",0);
}

string ask_me()
{
    return "我就是邪剑李四，你来找我有什麽事吗？\n";
}


int do_name()
{
    object weapon, me, dest, *all;
    string str,skill_type, parry_type;
    int i,j,k,attack_points;

    int *possible;
    possible=allocate(50);

    //        command("say in do name");
    me = this_object();
    all = users();
    j=0;

    for(i=0; i<sizeof(all); i++)
    {
	dest = all[i];
	if( (dest->query("kee")<200) ) 
	    continue;
if( wizardp(dest) || raw_wiz_level(dest) )
continue;
	//        command("say keeping for");
	if( objectp(weapon = dest->query_temp("weapon")) )
	{
	    skill_type = weapon->query("skill_type");
	    parry_type = "parry";

	}
	else
	{
	    skill_type = "unarmed";
	    parry_type = "unarmed";
	}

	attack_points = COMBAT_D->skill_power(dest, skill_type, SKILL_USAGE_ATTACK);

        if( attack_points/100 < 10000) {
	    //               command("say 李四很不高兴：就这种脚色还要我动手! \n");
	    //               str=sprintf("name= %s\n",dest->query("id"));
	    //                        tell_object(dest,str);

	}
	else {
	    //           command("say good one");
	    possible[j]=i;
	    j=j+1;
	}
    }

    //       command("say out from for");

    if(j==0){
	call_out("do_back",0,me,3);
	return 0;
    }

    //        command("chat");
    i=random(j);
    dest = all[possible[i]];

    me->set("waiting_target", dest->query("id"));
    me->set("target_name",dest->query("name"));

    tell_room(environment(me),HIY "吴一物嘿嘿嘿地干笑了几声，说道：老子就陪你们玩几招!\n"NOR, ({me}));

    me->set("pursuer", 1);
    me->set("vendetta/authority", 1);
    me->set("bellicosity", 100);
    me->set("combat_exp", 50000);

    message_vision("$N走了出去。\n" NOR, me);
    me->apply_condition("rest_time", 10);

    call_out("do_clone", 1,me,dest);
    call_out("do_chase", 2, me);

    return 1;
}


int do_clone(object me, object ob)
{
    object *inv;
    mapping hp_status, skill_status, map_status, prepare_status;
    string *sname, *mname, *pname;
    int i, temp,add_skill1,add_skill2;

    seteuid( geteuid(me) );

    /* delete and copy skills */

    if ( mapp(skill_status = me->query_skills()) ) {
	skill_status = me->query_skills();
	sname  = keys(skill_status);

	temp = sizeof(skill_status);
	for(i=0; i<temp; i++) {
	    me->delete_skill(sname[i]);
	}
    }

    if ( mapp(skill_status = ob->query_skills()) ) {

	skill_status = ob->query_skills();
	sname  = keys(skill_status);
	if(ob->query("combat_exp")>10000)
	    add_skill1=30;
	else
	    add_skill1=10;

	for(i=0; i<sizeof(skill_status); i++) {
	    if(skill_status[sname[i]]>80)
		add_skill2=10;
	    else {
		if(skill_status[sname[i]]>120)
		    add_skill2=skill_status[sname[i]]/100;
		else
		    add_skill2=0;
	    }
	    me->set_skill(sname[i],
              random(skill_status[sname[i]])+add_skill2+add_skill1);
	}
    }

    /* delete and copy skill maps */

    if ( mapp(map_status = me->query_skill_map()) ) {
	mname  = keys(map_status);

	temp = sizeof(map_status);
	for(i=0; i<temp; i++) {
	    me->map_skill(mname[i]);
	}
    }

    if ( mapp(map_status = ob->query_skill_map()) ) {
	mname  = keys(map_status);

	for(i=0; i<sizeof(map_status); i++) {

	    me->map_skill(mname[i], map_status[mname[i]]);
	}
    }

    /* delete and copy skill prepares */

    if ( mapp(prepare_status = me->query_skill_prepare()) ) {
	pname  = keys(prepare_status);

	temp = sizeof(prepare_status);
	for(i=0; i<temp; i++) {
	    me->prepare_skill(pname[i]);
	}
    }

    if ( mapp(prepare_status = ob->query_skill_prepare()) ) {
	pname  = keys(prepare_status);

	for(i=0; i<sizeof(prepare_status); i++) {
	    me->prepare_skill(pname[i], prepare_status[pname[i]]);
	}
    }


    /* unwield and remove weapon & armor */

    inv = all_inventory(me);
    for(i=0; i<sizeof(inv); i++) {
	destruct(inv[i]);
    }
    set("weapon", 0);
    set("armor", 0);

    /* wield and wear weapon & armor */

    inv = all_inventory(ob);
    for(i=0; i<sizeof(inv); i++) {
	                if( inv[i]->query("weapon_prop/damage") > 100
	                ||  inv[i]->query("armor_prop/armor") > 100 ) continue;

	if( inv[i]->query("weapon_prop") &&  inv[i]->query("equipped") )
	{
	    carry_object(base_name(inv[i]))->wield();
	    me->set("weapon", base_name(inv[i]));
	}
	else if( inv[i]->query("armor_prop") &&  inv[i]->query("equipped
") ) {

                        carry_object(base_name(inv[i]))->wear();
                        me->set("armor", base_name(inv[i]));
                }
        }

        me->add_temp("apply/astral_vision", 1);

/* copy entire dbase values */

        hp_status = ob->query_entire_dbase();

                me->set("str", hp_status["str"]);
                me->set("int", hp_status["int"]);
                me->set("con", hp_status["con"]);
                me->set("spi", hp_status["spi"]);

                me->set("max_kee",    3*hp_status["max_kee"]);
                me->set("eff_kee",    3*hp_status["max_kee"]);
                me->set("kee",        3*hp_status["max_kee"]);
                me->set("max_gin",    3*hp_status["max_gin"]);
                me->set("eff_gin",    3*hp_status["max_gin"]);
                me->set("gin",        3*hp_status["max_gin"]);
                me->set("max_sen",  hp_status["max_sen"]);
                me->set("eff_sen",  hp_status["max_sen"]);
                me->set("sen",      hp_status["max_sen"]);
                me->set("max_force", hp_status["max_force"]);
                me->set("force",     hp_status["force"]);
                me->set("force_factor",     hp_status["force_factor"]/2);
                me->set("mana",      hp_status["mana"]);
                me->set("max_mana",  hp_status["max_mana"]);
                me->set("atman",     hp_status["atman"]);
                me->set("max_atman", hp_status["max_atman"]);
                me->set("shen", hp_status["max_atman"]*(-1));
                me->set("combat_exp",hp_status["combat_exp"]+1000);

        return 1;
}

int consider()
{
        int i, flag = 0;
        object *enemy;
        object weapon_ob;
        string ob_pwd,rest;

        enemy = query_enemy() - ({ 0 });
        for(i=0; i<sizeof(enemy); i++) {
                if( !living(enemy[i]) ) continue;
                if( weapon_ob = enemy[i]->query_temp("weapon") ) {
                        flag++;
			if(weapon_ob->query("weapon_prop/damage") <79 &&  
                         !query_temp("weapon") && !query_temp("clone_weapon") ) {
                                command("say " + RANK_D->query_respect(enemy[i])
 + "既然使兵刃，在下空手接招未免不敬。");
                                sscanf(sprintf("%O",weapon_ob),"%s#%s",ob_pwd,rest); 
				ob_pwd="/"+ob_pwd;
                                carry_object(ob_pwd)->wield();
				set_temp("clone_weapon",1);
                                command("say 进招吧！");
                                break;
                        }
                }
        }
}

int do_chase(object me)
{
	
	object dest;
	dest = find_player(me->query("waiting_target"));
	
	if( !objectp(dest) || !environment(dest) )	
	{
		call_out("waiting", 0, me);
		return 1;
	}
	
	me->move(environment(dest));
	message_vision("$N走了过来。\n" NOR, me);
	me->set_leader(dest);
	command("look " + dest->query("id"));
	
	if ( !environment(me)->query("no_fight"))
	{
		call_out("do_kill", 0, me, dest);
		return 1;
	}
	else
	{
		call_out("waiting", 0, me);
		return 1;
	}

	return 1;
}

int do_kill(object me, object dest)
{

	if( objectp(dest) && present(dest, environment(me))
		 && !environment(me)->query("no_fight"))
	{
		message_vision(HIR "$N对$n说道：阴司鬼王差我来，请你去他那儿做客，"
			+RANK_D->query_rude(dest)+"，你认命吧！\n" NOR, me, dest);
		me->set_leader(dest);
		me->kill_ob(dest);
		dest->fight_ob(me);

		call_out("checking", 0,  me); 	
	}
	else  
		call_out("waiting", 1, me); 	
	
	return 1;
}

int waiting(object me)
{
	object dest;
	dest = find_player(me->query("waiting_target"));
//        command("say in waiting");

	
	if ( objectp(dest) )
	{
                if (dest->is_ghost()&& (dest->query("eff_kee")<=1))
                {
                        me->delete("waiting_target");
                        call_out("do_back", 1, me,0);
                        return 1;
	          }if (me->is_fighting() && present(dest, environment(me)))
		{
			call_out("checking", 0, me);
			return 1;
		}else if (living(me) && !environment(dest)->query("no_fight"))
		{
			call_out("do_chase", 0, me);
			return 1;
		}
	}		
	
	remove_call_out("waiting");
	call_out("waiting", 10, me);
    return 1;
}

int checking(object me)
{
	object ob;
        int my_max_qi;

        if ( (int)me->query_condition("rest_time" ) == 0 ){
                 me->delete("waiting_target");
                 call_out("do_back", 1, me,1);
                 return 1;
         }
//        command("say checking");
        my_max_qi  = me->query("max_kee");

        if (me->is_fighting()) {
                if ( (me->query("kee")*100 / my_max_qi) <= 80 && (int)query("pills"))
                    {  
// command("say exert recover");
//                        command("exert recover");
                         say( HIY "吴一物从口袋摸出一粒从孙悟空那偷来的仙豆吞了下去。\n
" NOR);
                set("eff_gin", query("max_gin"));
                set("eff_kee", query("max_kee"));
                set("eff_sen", query("max_sen"));
                set("gin", query("eff_gin"));
                set("kee", query("eff_kee"));
                set("sen", query("eff_sen"));
                add("pills", -1);

                     }
                         
               if (( (int)me->query("kee")*100 / my_max_qi) <= 40 ) {
                 me->delete("waiting_target");
                 call_out("do_back", 0, me,2);
                 return 1;
                }

                call_out("checking", 1, me);
                return 1;
        }

     
	if( objectp(ob = present("corpse", environment(me)))
		 && ob->query("victim_name") ==	me->query("target_name") )
	{
		me->delete("waiting_target");
		call_out("do_back", 1, me,0);
        return 1;
	}
	
	call_out("waiting", 0, me);
	return 1;
}

int do_back(object me,int result)
{
        mapping   prepare_status;
        int i, temp;
        object *inv;
        string *pname;

        switch( result) {
           case 3:     command("chat 难道这天底下，竟然没有人是我的对手!");
                       break;
           case 1:
                        command("chat 老子没时间陪你玩了,这次就放你一马!");
                        break;
           case 2:      command("chat 算你狠，后会有期");
                        break;
	   case 4: 
			command("chat 厉害！厉害！");
			break;
           default:     command("chat 哈哈哈");
             }
           tell_room(environment(me),HIY "吴一物消失在一团烟雾中!\n"NOR,({me}));
 
             
        destruct(me);
	return 1;
}

void die() {
	do_back(this_object(),4);
}

void unconcious() {
	do_back(this_object(),4);
}
