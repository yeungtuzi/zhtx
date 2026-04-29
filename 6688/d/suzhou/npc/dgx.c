//NPC:/d/suzhou/npc/dgx.c
//by tlang
//98.2

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(RED"大狗熊"NOR, ({"da gouxiong", "da","gouxiong" }));
	set("title", HIW"独行大盗"NOR);
	set("long",
	"他是江湖上臭名昭著的独行盗大狗熊，功夫不弱。\n"
	);

	set("gender", "男性");
	set("attitude", "heroism");
	
	set("age", 35);
	set("shen_type", -10);
	set("str", 35);
	set("int", 30);
	set("con", 30);
	set("dex", 25);
	set("per", 27);
	set("max_kee", 500);
	set("max_gin", 300);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 30);
	set("combat_exp", 150000);
	set("score", 1000);
	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("force", 60);
	set_skill("blade", 70);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("shaolin-shenfa", 60);
	set_skill("cibei-dao", 60);
	set_skill("hunyuan-yiqi", 60);
        set_skill("strike", 60);
	set_skill("sanhua-zhang", 60);

        map_skill("strike", "sanhua-zhang");
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("blade", "cibei-dao");
	map_skill("parry", "cibei-dao");

        prepare_skill("strike", "sanhua-zhang");

	setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
//	carry_object("/d/guard/npc/obj/biaoyin");
	add_money("gold", 1);
}

void init()
{
	object ob, me;
	me=this_player();

	 ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 1, me); 
}

void greeting(object me)
{
	object ob;
	ob=this_object();

	if( !me || environment(me) != environment() || !me->query("saver") ) 
		return notify_fail("来人少管闲事！否则自找死路！\n");
       	command("say 又一个送死的人来了，嘿嘿。。。。。\n");
	ob->kill_ob(me);
}

void die()
{
	object ob,me;
	me=this_player();

	me->set("test1",1);				
	ob=new("/d/guard/npc/obj/biaoyin");
	ob->move(environment(this_object()));
	message_vision("只见$N的尸体化为黄水，只剩下镖银在地上。\n",this_object());
	destruct(this_object());
}

         