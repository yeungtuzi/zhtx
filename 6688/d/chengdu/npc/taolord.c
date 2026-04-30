// taolord.c

#include <ansi.h>
inherit NPC;
//inherit F_MASTER;
string ask_me();

void create()
{
	set_name(RED"张天师"NOR, ({ "zhang tianshi", "zhang", "tianshi" }) );
	set("nickname", "承天真人");
	set("gender", "男性");
	set("age", 57);
	set("long",
		"张天师是茅山现任掌门林忌的师兄，本应是现任的茅山掌门，\n但是"
		"不知何故，他在二十年前独自离开了茅山。他道行深厚，\n法力高强。"
		"你发现他的双眸金黄，这正是「谷\衣心法」修炼到最\n高境界的徵兆。\n");

	set("combat_exp", 15000000);
	set("score", 200000);
	set("shen", -1000000);
	set("class", "taoist");

	set("str", 20);
	set("int", 30);
	set("cor", 20);
	set("cps", 30);
	set("spi", 30);

	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 100);

	set("atman", 6000);
	set("max_atman", 3000);

	set("mana", 4000);
	set("max_mana", 2000);
	set("mana_factor",100);

	set("inquiry", ([
		"谷衣心法": "谷衣心法是我茅山派为对抗邪魔外道所创的内功\心法。\n",
		"茅山派": "我茅山派自开山立派至今，世世代代皆以降妖伏魔为己任。\n",
		"林忌": "他...他...他是我的师弟，这个小人...\n",
		"掌门": "二十年前，我是当时茅山派掌教弟子，掌门之位本来非我莫属...不过现在我，人人皆知那林忌才是茅山掌门，我复位的心却也渐渐淡了，只是这奸人如此卑鄙，却让人愤恨难平。\n",
		"复位" : (:ask_me:),
	]) );

	set("apprentice_available", 3);
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: cast_spell, "netherbolt" :),
		(: cast_spell, "feeblebolt" :),
		(: cast_spell, "invocation" :),
	}) );

	create_family("茅山派", 5, "天师");

        set_skill("literate", 200);
        set_skill("magic", 200);
        set_skill("force", 200);
        set_skill("spells", 200);
	set_skill("unarmed", 100);
	set_skill("sword", 150);
	set_skill("parry", 120);
	set_skill("dodge", 150);

        set_skill("gouyee", 200);
        set_skill("taosword", 200);
        set_skill("taoism", 250);
	set_skill("necromancy", 180);

	map_skill("spells", "necromancy");
	map_skill("sword", "taosword");
	map_skill("parry", "taosword");
	map_skill("force","gouyee");

	setup();

	set("max_kee",2000);
	set("eff_kee",2000);
	set("kee",2000);
        set("eff_sen",400);
        set("sen",400);
        set("max_sen",400);
        set("eff_gin",2000);
	set("max_gin",2000);
	set("gin",2000);

	carry_object(__DIR__"obj/darksword")->wield();
	carry_object(__DIR__"obj/robe")->wear();

	set_temp("manashield",1);
	set_temp("apply/defense",100);
	set_temp("apply/armor",200);
	set_temp("apply/armor_vs_force",200);	
}

string ask_me()
{
	object me,sword;
	// 2026-04-30: unused variable commented out
	// mixed mengzhu;
	
	me=this_player();
	if( this_object()->recognize_apprentice(me) )
	{
		command("hammer "+me->query("id"));
		return "小心我把你开革出门！\n";
	}
	if( time()-me->query("marks/zhangtianshi_last_ask_time") < 900 )
		return "你怎么又来了，我不是说过了嘛！\n";	
	me->set("marks/zhangtianshi_last_ask_time",time());	

	if( me->query("family/family_name") != "茅山派" )
		return "眼下茅山一派在林忌掌管之下倒也算是井井有条，我又老了，罢了...\n";
/*
	mengzhu = find_object("d/taishan/npc/meng-zhu");
	if( !mengzhu || !objectp(mengzhu) )
		mengzhu = load_object("/d/taishan/npc/meng-zhu");
	else
		mengzhu->restore();
	if( !mengzhu || !objectp(mengzhu) )
	{	
		say(query("name")+"叹了口气。\n");
		return "你位轻人微，还是不要到这里来了，免得被你师傅知道，却是罪过一桩。\n";
	}
*/
//        if( me->query("family/generation") != 6 || mengzhu->query("winner")!=me->query("id") )
//                return "你位轻人微，还是不要到这里来了，免得被你师傅知道，却是罪过一桩。\n";
		//return sprintf("告诉你程序的执行情况：mengzhu是%O winner=%s\n",mengzhu,mengzhu->query("winner"));
	if( me->query_skill("necromancy",1) < 150 || me->query("mana")<3900 )
		return "你力量低微，不足成事。\n";
	say(query("name")+"似乎有些意动...\n");
	me->add("marks/zhangtianshi_ask",1);

	if( me->query("marks/zhangtianshi_ask") < 10 )
		return "唉，算了，茅山一派大局为重，我一个人的事情算什么，\n何况江湖上人人皆知那茅山掌门乃是林忌，你虽然位高望重，却也成算不大...\n";

	if( objectp( sword=present("dark sword",this_object()) ) )
	{
		me->set("marks/zhangtianshi_givequest",1);
		me->delete("marks/zhangtianshi_ask");
		message_vision("$N将"+sword->query("name")+"交给$n。\n",this_object(),me);
		sword->move(me);
		return "你真是毅力非凡，好吧，这事情交给你我也算放心了。\n";
	}
	return "我现在心有余力不足，你改日再来吧。\n";
		
}
/* ----------

void attempt_apprentice(object ob)
{
	if( query("apprentice_available") ) {
		if( find_call_out("do_recruit") != -1 )
			command("say 慢著，一个一个来。");
		else
			call_out("do_recruit", 2, ob);
	} else {
		command("say 贫道今天已经收了三个弟子，不想再收徒了。");
	}
}

void do_recruit(object ob)
{
	if( (string)ob->query("gender") != "男性" )
		command("say 贫道是出家人，不便收女徒，得罪了。");
	else {
		command("say 嗯... 想入我茅山派？也好....");
		command("recruit " + ob->query("id") );
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "taoist");
	add("apprentice_availavble", -1);
}


 ------------ */

int chat()
{       
	// 2026-04-30: unused variable commented out
	// object *enemys,victim;
	// 2026-04-30: unused variable commented out
	// int i;
	
	if( !is_fighting() )
	{
		//没魔法盾牌了
		if( !query_temp("manashield") && ((int)query("mana"))>1000 )
			command("cast manashield");			
		//来点惊喜 :)
		if( random(100) > 90 && query("mana")<query("max_mana")*2)
		{
			if(!random(5))
				message_vision(BLU"$N的金色瞳孔之中突然闪过一道妖异的光芒.\n"NOR,this_object());
			add("mana",1000);
		}	
		//法力不够了
		if( query("mana") < 2000 )
			command("exert concentrate");	
		return ::chat();
	}	                
	return ::chat();
}

int recognize_apprentice(object ob)
{
	return ob->query("marks/zhangtianshi_apprentice");
}	

int accept_object(object who,object ob)
{
	if( ob->query("mana_for_zhangtianshi") )
	{
		command("chat 哈哈哈！林忌啊林忌，你作恶多端，终不免报应！");
		command("chat 好，如此，我便指点指点你的天师正道。");
		who->set("marks/zhangtianshi_apprentice",1);	
		return 1;
	}
	return 0;
}	

int accept_learn(object who,string skill)
{
	return 1;	
}
