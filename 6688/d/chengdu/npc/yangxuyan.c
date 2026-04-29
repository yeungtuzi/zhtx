// yang xuyan.c
// by yeung

#include <ansi.h>

inherit NPC;

string ask_hou();
void init();

void create()
{
	set_name(HIY"杨虚彦"NOR, ({ "yang xuyan", "yang"}) );
	set("title", HIR"影子刺客"NOR);
	set("gender", "男性");
	set("age", 27);
	set("long",
		"杨虚彦是一名出色的刺客，他一击不中，立即全身而退，极少有失手之时。\n"
		"他也是〖邪王〗石之轩的弟子,他看起来阴险狡诈，你最好小心一点。\n"
	);

	set("combat_exp", 500000);
	set("score", -200000);

	set("class", "fighter");

	set("str", 60);
	set("int", 30);
	set("cor", 80);
	set("cps", 30);
	set("spi", 30);

	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 80);
	set("max_kee",4000);

	set("inquiry", ([
		"不死印心法"   : (: ask_hou :),
		"不死印卷"   : (: ask_hou :),		
		"石之轩": "他是我的恩师，江湖上鼎鼎大名的邪王，你找他有事吗？\n",
		"侯希白": "侯希白这小白脸抢走了我的半卷【不死印卷】，我一定要杀了他！\n",
		"身世"  : "我本来是昏君杨广的兄长杨永之子，可恨这昏君弑父杀兄，夺了我爹爹的皇位。\n",
		"刺杀"  : "你能找到我这里，足见高明。不过杀人对我自己有什么好处呢？\n",
	]) );

	set_skill("literate", 150);
	set_skill("force", 100);
	set_skill("strike", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("sword", 100);

	set_skill("celestial",100);
	set_skill("celestrike", 100);
	set_skill("six-chaos-sword", 150);

	map_skill("sword", "six-chaos-sword");
	map_skill("parry", "six-chaos-sword");
	map_skill("force","celestial");
	map_skill("strike","celestrike");

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);

	setup();

	carry_object(__DIR__"obj/ghostsword")->wield();
}

string ask_hou()
{
	object ob;
	ob = this_player();
	ob->set("marks/yeying",0);
	ob->set("marks/hou",0);
	ob->set("marks/yang",1);
	command("grin");      
	this_object()->kill_ob(ob);
	return("不死印心法是本门绝学，妙用无穷，我手里确实也有半份。\n但小白脸派你来抢我的印卷，那是休想！\n");
}


int accept_object(object me, object ob)
{	
	object who;
	who=this_player();
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("你没有这件东西。");
	if (ob->query("money_id") && ob->value() >= 1000000 )
	{
		tell_object(me, "\n杨虚彦干笑两声，说：好吧，我就跑一趟。\n");
		tell_object(me, "请键入：杀 目标中文名字\n");
		me->set_temp("fee_paid",1);
		return 1;
	}
	else if (ob->query("money_id") && ob->value() < 1000000) 
	{
		tell_object(me, "\n杨虚彦两眼放光，笑道：不好吧，给我这麽多钱。那我就却之不恭了，哈哈。\n");
		return 1;
	}                                            
	return 0;
}                     


int do_name(string target)
{
	object me, dest, *all;
	int i;
 
	me = this_object();
	all = users();

	if(me->query("waiting_target"))
		return notify_fail("杨虚彦：我现在正忙着哪，您呆会儿再来吧！\n");
	if( !this_player()->query_temp("fee_paid") ) 
		return notify_fail("杨虚彦道：不好吧，帮你杀了人我又有什么好处呢？\n");
	if( !target || target==" ")
		return notify_fail("杨虚彦道：请告诉我那人的名字，我可没功夫跟你闲聊。\n");
	for(i=0; i<sizeof(all); i++)
	{
		if( target == all[i]->name() || target == all[i]->id() )
			dest = all[i];
	}
	if( !dest )
		return notify_fail("杨虚彦奸笑两声道：有这个玩家吗？\n");

	if (dest->is_ghost())
		return notify_fail("杨虚彦生气地哼了一声：杀死人的事情我可不干！\n");
	me->set("waiting_target", dest->query("id"));
	me->set("target_name", target);
	me->delete("chat_chance");
	me->delete("chat_msg");
	message("vision",
	HIY "\n杨虚彦说道：静侯佳音吧。\n" NOR,
	environment(), me );
	me->set("pursuer", 1);
	me->set("vendetta/authority", 1);
	message_vision("HIM $N走了出去。\n" NOR, me);
        call_out("do_clone", 1,me,dest);
	call_out("do_chase", 1, me);
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

	if( (ob->query("combat_exp")) < 300000 ) return 1;
	
	// 太面的就直接杀了

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
                if(ob->query("combat_exp")>1000000)
                     add_skill1=30;
                else
                     add_skill1=10;

                for(i=0; i<sizeof(skill_status); i++) {
                    if(skill_status[sname[i]]>200)
                       add_skill2=10;
                     else {
                        if(skill_status[sname[i]]>300)
                          add_skill2=skill_status[sname[i]]/100;
                         else
                          add_skill2=0;
                        }
                    me->set_skill(sname[i],
                        random(skill_status[sname[i]]*2)+add_skill2+add_skill1);
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

                me->set("str", 2*hp_status["str"]);
                me->set("int", hp_status["int"]);
                me->set("con", hp_status["con"]);
                me->set("spi", hp_status["spi"]);

                me->set("max_kee",    4*hp_status["max_kee"]);
                me->set("eff_kee",    4*hp_status["max_kee"]);
                me->set("kee",        4*hp_status["max_kee"]);
                me->set("max_sen",   hp_status["max_sen"]);
                me->set("eff_sen",   hp_status["max_sen"]);
                me->set("sen",       hp_status["max_sen"]);
                me->set("max_gin",   hp_status["max_gin"]);
                me->set("eff_gin",   hp_status["max_gin"]);
                me->set("gin",       hp_status["max_gin"]);
                me->set("max_force", hp_status["max_force"]);
                me->set("force",     2*hp_status["max_force"] -1);
                me->set("force_factor",     hp_status["force_factor"]*2);
                me->set("mana",      hp_status["mana"]);
                me->set("max_mana",  hp_status["max_mana"]);
                me->set("atman",     hp_status["atman"]);
                me->set("max_atman", hp_status["max_atman"]);
                me->set("combat_exp",hp_status["combat_exp"]+10000);
        return 1;
}


int do_chase(object me)
{
	
	object dest,room;
	dest = find_player(me->query("waiting_target"));
	if( !objectp(dest) || !environment(dest) )      
	{
		call_out("waiting", 0, me);
		return 1;
	}
	me->move(environment(dest));
	message_vision("$N嘿嘿奸笑着走了过来。\n" NOR, me);
	room = environment(this_object());
	if (room->query("no_fight"))
		room->set("no_fight", 0);

	me->set_leader(dest);
	command("look " + dest->query("id"));
	if ( !environment(me)->query("no_fight"))
	{
		call_out("do_kill", 1, me, dest);
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
		message_vision(HIR "$N对$n说道：有人出重金买你的脑袋，不好意思了！\n"
			+RANK_D->query_rude(dest)+"，你就认命吧！\n" NOR, me, dest);
        	me->set_leader(dest);
		me->kill_ob(dest);
		dest->fight_ob(me);
		call_out("checking", 0,  me);   
	}
	else call_out("waiting", 1, me);     
	return 1;
}

int waiting(object me)
{
	object dest;
	dest = find_player(me->query("waiting_target"));
	if ( objectp(dest) )
	{
		if (dest->is_ghost())
		{
			me->delete("waiting_target");
			call_out("do_back", 1, me);
			return 1;
		}else if (me->is_fighting() && present(dest, environment(me)))
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
	call_out("waiting", 60, me);
    return 1;
}

int checking(object me)
{
	object ob;

	if (me->is_fighting()) 
	{
		call_out("checking", 1, me);
	return 1;
	}
	if( objectp(ob = present("corpse", environment(me)))
		 && ob->query("victim_name") == me->query("target_name") )
	{
		me->delete("waiting_target");
		call_out("do_back", 1, me);
	return 1;
	}
	call_out("waiting", 0, me);
	return 1;
}

int do_back(object me)
{

	me->move("/u/y/yeung/chengdu/mishi");
	message("vision", "杨虚彦嘿嘿奸笑着走了进来。\n", 
		environment(), me );
	me->set_leader(0);
	return 1;
}              

void init()
{
	::init();
	add_action("do_name", "杀");
}
/*                      

void die()
{
        message_vision("杨虚彦大叫一声：我好恨！壮志未酬身先死！倒地而亡。\n");
        carry_object(__DIR__"obj/ghostsword")->destruct();
        ::die();
}

*/
