// hou xibai.c
// by yeung

#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

string ask_hou();

void create()
{
	set_name(HIG"候希白"NOR, ({ "hou xibai", "hou"}) );
	set("nickname", HIC"多情公子"NOR);
	set("gender", "男性");
	set("age", 27);
	set("long",
		"候希白是花间派嫡传弟子，向以多情惜花著称，但是，却很少有人知道，\n"
		"他同时也是〖邪王〗石之轩的弟子。他看起来风流潇洒，但是此刻却似\n"
		"心有所忧。\n");

	set("combat_exp", 500000);
	set("score", 200000);

	set("class", "fighter");

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("spi", 30);

	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 80);
	set("max_kee",2000);

	set("inquiry", ([
		"不死印心法"   : (: ask_hou :),
		"不死印卷"   : (: ask_hou :),		
		"石之轩": "他是我的恩师，江湖上鼎鼎大名的邪王，你找他有事吗？\n",
		"杨虚彦": "杨虚彦这臭贼抢走了我的半卷【不死印卷】，你能帮助我吗？\n"
	]) );

	create_family(HIM"花间"HIY"派"NOR, 5, "传人");

	set_skill("literate", 150);
	set_skill("force", 100);
	set_skill("strike", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("blade", 100);

	set_skill("celestial",100);
	set_skill("celestrike", 100);
	set_skill("spring-blade", 150);

	map_skill("blade", "spring-blade");
	map_skill("parry", "spring-blade");
	map_skill("force","celestial");
	map_skill("strike","celestrike");

	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);

	setup();

	carry_object(__DIR__"obj/lovefan")->wield();
}

string ask_hou()
{
	object ob;
	ob = this_player();
	if( !ob->query("marks/yeying") )
		return("你问这个干什么呢,我又不认识你。\n");
	else
	{
		ob->set("marks/yeying",0);
		ob->set("marks/hou",1);
		return("不死印心法是本门绝学，妙用无穷，可是我手里只有半份。\n你若能帮我找回另外半份，我情愿和你分享。\n");
	}
}
