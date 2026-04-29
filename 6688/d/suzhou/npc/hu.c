//NPC:/d/suzhou/npc/hu.c  
//by dwolf
//97.11.4

#include <ansi.h>
inherit NPC;
string ask_me();

void create()
{
	set_name("杨康", ({ "yang kang", "yang" }));
        set("title",CYN "苏州" NOR + YEL "知府" NOR);
	set("gender", "男性");
	set("age", 43);
	set("str", 40);
	set("dex", 30);
	set("per", 27);
	set("long", @LONG
	  他就是杨康，苏州现任知府。熟悉他的人都很鄙夷他的为人。
LONG
	);
	set("combat_exp", 500000);
	set("shen_type", -1);
	set("attitude", "heroism");

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("leadership", 50);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 75);

	set("force", 700); 
	set("max_force", 700);
	set("force_factor", 30);

	set("inquiry",([
		"完颜洪烈" : (: ask_me :),
		"wanyanhonglie" : (: ask_me :),
		"卖国贼" : (: ask_me :),
		"betrayer" : (: ask_me :),
	]));

	setup();
	carry_object(__DIR__"obj/blade")->wield();
	carry_object(__DIR__"obj/baishan")->wear();  
	carry_object(__DIR__"obj/nuerh");
}

int recognize_apprentice(object ob)
{
        if ( (string)ob->query("family/family_name")=="朝廷" && (string)ob->query("wen-wu")=="wen")
                return 1;
	else
		return 0;
}

string ask_me()
{
	object ob=this_player();
	object me=this_object();
	object obj;
	int my_exp,ob_exp;

	my_exp=me->query("combat_exp");
	ob_exp=ob->query("combat_exp");

	if(ob_exp>=my_exp )
	{
		if( objectp( obj = present("wanyan liang", environment(me) ) ) )
		obj->kill_ob(ob);	
		me->set("combat_exp",ob_exp*3/2);
		me->add("shen_type",-1);
		kill_ob(ob);
			return "这种事情你也敢问？是自己找死。我宰了你。\n";
	}
	command("slap "+ob->query("id"));
	return "你说话最好小心一点。\n";
}